/****************************************************************************
** Meta object code from reading C++ file 'update_record.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../update_record.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'update_record.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSupdate_recordENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSupdate_recordENDCLASS = QtMocHelpers::stringData(
    "update_record",
    "loadData",
    "",
    "on_comboBox_currentIndexChanged",
    "index",
    "initializeDateTimePickers",
    "row",
    "showDateTimePicker",
    "col",
    "on_updateButtonClicked",
    "exitButtonClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSupdate_recordENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[14];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[6];
    char stringdata5[26];
    char stringdata6[4];
    char stringdata7[19];
    char stringdata8[4];
    char stringdata9[23];
    char stringdata10[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSupdate_recordENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSupdate_recordENDCLASS_t qt_meta_stringdata_CLASSupdate_recordENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "update_record"
        QT_MOC_LITERAL(14, 8),  // "loadData"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 31),  // "on_comboBox_currentIndexChanged"
        QT_MOC_LITERAL(56, 5),  // "index"
        QT_MOC_LITERAL(62, 25),  // "initializeDateTimePickers"
        QT_MOC_LITERAL(88, 3),  // "row"
        QT_MOC_LITERAL(92, 18),  // "showDateTimePicker"
        QT_MOC_LITERAL(111, 3),  // "col"
        QT_MOC_LITERAL(115, 22),  // "on_updateButtonClicked"
        QT_MOC_LITERAL(138, 17)   // "exitButtonClicked"
    },
    "update_record",
    "loadData",
    "",
    "on_comboBox_currentIndexChanged",
    "index",
    "initializeDateTimePickers",
    "row",
    "showDateTimePicker",
    "col",
    "on_updateButtonClicked",
    "exitButtonClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSupdate_recordENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    1,   51,    2, 0x08,    2 /* Private */,
       5,    1,   54,    2, 0x08,    4 /* Private */,
       7,    2,   57,    2, 0x08,    6 /* Private */,
       9,    0,   62,    2, 0x08,    9 /* Private */,
      10,    0,   63,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject update_record::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSupdate_recordENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSupdate_recordENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSupdate_recordENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<update_record, std::true_type>,
        // method 'loadData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'initializeDateTimePickers'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showDateTimePicker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_updateButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exitButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void update_record::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<update_record *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadData(); break;
        case 1: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->initializeDateTimePickers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->showDateTimePicker((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->on_updateButtonClicked(); break;
        case 5: _t->exitButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject *update_record::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *update_record::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSupdate_recordENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int update_record::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
