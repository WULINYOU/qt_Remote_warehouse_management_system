// 修改前
QObject::connect(Storage_newok, &QPushButton::clicked, add_Storage, qOverload<>(&QDialog::on_Storage_new_ok_clicked));

// 修改后
QObject::connect(Storage_newok, &QPushButton::clicked, add_Storage, &add_Storage::on_Storage_new_ok_clicked);