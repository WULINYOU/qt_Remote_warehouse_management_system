/****************************************************************************
** Meta object code from reading C++ file 'confirmdeletedialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../confirmdeletedialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confirmdeletedialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS = QtMocHelpers::stringData(
    "ConfirmDeleteDialog",
    "confirmed",
    "",
    "canceled",
    "startCountdown",
    "updateCountdown",
    "remaining",
    "onCanceled",
    "onConfirmed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[20];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[16];
    char stringdata6[10];
    char stringdata7[11];
    char stringdata8[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS_t qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "ConfirmDeleteDialog"
        QT_MOC_LITERAL(20, 9),  // "confirmed"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 8),  // "canceled"
        QT_MOC_LITERAL(40, 14),  // "startCountdown"
        QT_MOC_LITERAL(55, 15),  // "updateCountdown"
        QT_MOC_LITERAL(71, 9),  // "remaining"
        QT_MOC_LITERAL(81, 10),  // "onCanceled"
        QT_MOC_LITERAL(92, 11)   // "onConfirmed"
    },
    "ConfirmDeleteDialog",
    "confirmed",
    "",
    "canceled",
    "startCountdown",
    "updateCountdown",
    "remaining",
    "onCanceled",
    "onConfirmed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConfirmDeleteDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       7,    0,   56,    2, 0x08,    6 /* Private */,
       8,    0,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConfirmDeleteDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConfirmDeleteDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConfirmDeleteDialog, std::true_type>,
        // method 'confirmed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'canceled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCanceled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onConfirmed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ConfirmDeleteDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfirmDeleteDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->confirmed(); break;
        case 1: _t->canceled(); break;
        case 2: _t->startCountdown(); break;
        case 3: _t->updateCountdown((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onCanceled(); break;
        case 5: _t->onConfirmed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConfirmDeleteDialog::*)();
            if (_t _q_method = &ConfirmDeleteDialog::confirmed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConfirmDeleteDialog::*)();
            if (_t _q_method = &ConfirmDeleteDialog::canceled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ConfirmDeleteDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfirmDeleteDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConfirmDeleteDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfirmDeleteDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ConfirmDeleteDialog::confirmed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConfirmDeleteDialog::canceled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
