/****************************************************************************
** Meta object code from reading C++ file 'delete_table.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../delete_table.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'delete_table.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSdelete_tableENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSdelete_tableENDCLASS = QtMocHelpers::stringData(
    "delete_table",
    "on_comboBox_currentIndexChanged",
    "",
    "index",
    "on_deleta_table_ButtonClicke"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSdelete_tableENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[13];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSdelete_tableENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSdelete_tableENDCLASS_t qt_meta_stringdata_CLASSdelete_tableENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "delete_table"
        QT_MOC_LITERAL(13, 31),  // "on_comboBox_currentIndexChanged"
        QT_MOC_LITERAL(45, 0),  // ""
        QT_MOC_LITERAL(46, 5),  // "index"
        QT_MOC_LITERAL(52, 28)   // "on_deleta_table_ButtonClicke"
    },
    "delete_table",
    "on_comboBox_currentIndexChanged",
    "",
    "index",
    "on_deleta_table_ButtonClicke"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSdelete_tableENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x08,    1 /* Private */,
       4,    0,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject delete_table::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSdelete_tableENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSdelete_tableENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSdelete_tableENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<delete_table, std::true_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_deleta_table_ButtonClicke'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void delete_table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<delete_table *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_deleta_table_ButtonClicke(); break;
        default: ;
        }
    }
}

const QMetaObject *delete_table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *delete_table::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSdelete_tableENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int delete_table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
