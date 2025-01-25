#include "add_storage.h"
#include "ui_add_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTimeEdit>
#include <QTableWidgetItem>
#include <QSqlTableModel>

add_Storage::add_Storage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_Storage)
{
    ui->setupUi(this);
    if(!QSqlDatabase::contains("add_storageConnectionName")){
        db4 = QSqlDatabase::addDatabase("QODBC", "add_storageConnectionName");
        db4.setDatabaseName("MySQLDSN");
        if(!db4.open()){
            QMessageBox::information(this, "info", "连接数据库失败");
            qDebug() << "error open database because" << db4.lastError().text();
        }
    } else {
        db4 = QSqlDatabase::database("add_storageConnectionName");
    }
    QSqlQuery query("SHOW TABLES", db4);
    while(query.next()){
        QString tableName = query.value(0).toString();
        ui->comboBox->addItem(tableName);
    }
    ui->comboBox_2->addItem("      ");
    ui->comboBox_2->addItem("成品库存");
    ui->comboBox_2->addItem("退货库存");
    ui->comboBox_2->addItem("季节性库存");

    // 设置 lineEdit_3 为 QDateTimeEdit
    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
    dateTimeEdit->setCalendarPopup(true);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->verticalLayout_2->replaceWidget(ui->lineEdit_3, dateTimeEdit);
    ui->lineEdit_3->deleteLater();
    ui->lineEdit_3 = dateTimeEdit;

    connect(ui->Storage_oldok, &QPushButton::clicked, this, &add_Storage::on_Storage_oldok_clicked);
}

add_Storage::~add_Storage()
{
    delete ui;
}

bool add_Storage::validatePositiveInteger(const QString &input, int &output) {
    bool isValid;
    output = input.toInt(&isValid);
    return isValid && output > 0;
}

void add_Storage::on_Storage_oldok_clicked(bool checked)
{
    if (!db4.isOpen()) {
        QMessageBox::information(this, "Error", "数据库连接已关闭");
        return;
    }

    // 获取 QLineEdit 的文本
    QString productName = ui->lineEdit->text();  // 产品名称
    QString quantityStr = ui->lineEdit_2->text();  // 入库数量

    int number;
    if (!validatePositiveInteger(quantityStr, number)) {
        QMessageBox::information(this, "Error", "请输入有效的正整数作为入库数量");
        return;
    }

    // 查询数据库以检查是否存在该产品
    QSqlQuery query(db4);
    query.prepare("SELECT id, number FROM inv_table WHERE name = :name");
    query.bindValue(":name", productName);

    if (query.exec() && query.next()) {
        // 找到产品
        int productId = query.value(0).toInt();
        int currentNumber = query.value(1).toInt();

        // 更新库存数量
        int newNumber = currentNumber + number;

        // 更新数据库中的数量
        QSqlQuery updateQuery(db4);
        updateQuery.prepare("UPDATE inv_table SET number = :newNumber WHERE id = :id");
        updateQuery.bindValue(":newNumber", newNumber);
        updateQuery.bindValue(":id", productId);

        if (updateQuery.exec()) {
            qDebug() << "Updated inventory for product ID:" << productId;
            QMessageBox::information(this, "提示", "入库成功！");
        } else {
            qDebug() << "Error updating database:" << updateQuery.lastError().text();
            QMessageBox::critical(this, "Error", "更新库存失败，请重试");
        }
    } else {
        // 未找到产品
        if (query.lastError().isValid()) {
            qDebug() << "Error checking database:" << query.lastError().text();
        }
        QMessageBox::information(this, "Error", "未找到该产品，请检查产品名称");
    }
    query.finish();
}

void add_Storage::on_Storage_exit_clicked(bool checked)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "返回", "确定要返回管理页面?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->close();
    }
}

void add_Storage::on_Storage_newok_clicked(bool checked)
{
    if (!db4.isOpen()) {
        QMessageBox::information(this, "Error", "数据库连接已关闭");
        return;
    }

    // 获取 QLineEdit 和 QComboBox 的文本
    QString productName = ui->lineEdit->text().trimmed();  // 产品名称
    QString quantityStr = ui->lineEdit_2->text().trimmed();  // 入库数量
    QString priceStr = ui->lineEdit_4->text().trimmed();  // 价格
    QString storagePerson = ui->lineEdit_5->text().trimmed();  // 入库员
    QDateTime storageTime1 = ui->lineEdit_3->dateTime();  // 入库时间
    QString storageType = ui->comboBox_2->currentText();  // 入库类型

    // 创建第二个 QDateTimeEdit 用于出库时间
   // QDateTime storageTime2 = QDateTime::fromString("0001-01-01 00:00:00"); // 出库时间

    QString tableName = ui->comboBox->currentText();  // 表名

    // 验证必填字段是否为空
    if (productName.isEmpty() || quantityStr.isEmpty() || priceStr.isEmpty() || storagePerson.isEmpty()) {
        QMessageBox::information(this, "Error", "请填写所有必填字段");
        return;
    }

    // 验证入库数量是否为正整数
    bool isQuantityValid;
    int quantity = quantityStr.toInt(&isQuantityValid);
    if (!isQuantityValid || quantity <= 0) {
        QMessageBox::information(this, "Error", "请输入有效的正整数作为入库数量");
        return;
    }

    // 验证价格是否为有效的数字
    bool isPriceValid;
    double price = priceStr.toDouble(&isPriceValid);
    if (!isPriceValid || price <= 0) {
        QMessageBox::information(this, "Error", "请输入有效的正数作为价格");
        return;
    }

    // 检查产品是否已存在
    QSqlQuery checkProductQuery(db4);
    checkProductQuery.prepare(QString("SELECT id FROM %1 WHERE name = :name").arg(tableName));
    checkProductQuery.bindValue(":name", productName);

    if (!checkProductQuery.exec() || checkProductQuery.next()) {
        checkProductQuery.finish();
        if (checkProductQuery.next()) {
            QMessageBox::information(this, "Error", "该产品已存在，请检查产品名称");
            return;
        }
    } else {



    // 获取最大ID并加1
    QSqlQuery getMaxIdQuery(db4);
    getMaxIdQuery.prepare(QString("SELECT MAX(id) FROM %1").arg(tableName));

    if (!getMaxIdQuery.exec() || !getMaxIdQuery.next()) {
        getMaxIdQuery.finish();
        QMessageBox::critical(this, "错误", "无法获取最大ID: " + getMaxIdQuery.lastError().text());
        qDebug() << "Failed to get max ID:" << getMaxIdQuery.lastQuery();
        qDebug() << "Error details:" << getMaxIdQuery.lastError().text();
        return;
    }

    int maxid = getMaxIdQuery.value(0).toInt() + 1;

    // 准备插入语句
    QSqlQuery insertQuery(db4);
    insertQuery.prepare(QString("INSERT INTO %1 (id, name, number, price, type, in_time, out_time, inop) "
                                "VALUES (:id, :name, :number, :price, :type, :in_time, :inop)")
                            .arg(tableName));

    insertQuery.bindValue(":id", maxid);
    insertQuery.bindValue(":name", productName);
    insertQuery.bindValue(":number", quantity);
    insertQuery.bindValue(":price", price);
    insertQuery.bindValue(":type", storageType);
    insertQuery.bindValue(":in_time", storageTime1.toString("yyyy-MM-dd hh:mm:ss"));  // 确保时间格式正确
   // insertQuery.bindValue(":out_time", storageTime2.toString("yyyy-MM-dd hh:mm:ss"));
    insertQuery.bindValue(":inop", storagePerson);

    // 执行插入操作
    if (!insertQuery.exec()) {
        insertQuery.finish();
        QMessageBox::critical(this, "错误", "入库失败: " + insertQuery.lastError().text());
        qDebug() << "Failed to execute insert query:" << insertQuery.lastQuery();
        qDebug() << "Error details:" << insertQuery.lastError().text();
        return;
    }

    QMessageBox::information(this, "成功", "新产品已成功入库");

    // 确保在退出时正确释放资源
    checkProductQuery.finish();
    getMaxIdQuery.finish();
    insertQuery.finish();
}
}
