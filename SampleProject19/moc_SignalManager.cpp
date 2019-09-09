/****************************************************************************
** Meta object code from reading C++ file 'SignalManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "app/Core/SignalManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignalManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SignalManager_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignalManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignalManager_t qt_meta_stringdata_SignalManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SignalManager"
QT_MOC_LITERAL(1, 14, 15), // "setTextFieldCpp"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "text"
QT_MOC_LITERAL(4, 36, 15), // "setProperrtyCpp"
QT_MOC_LITERAL(5, 52, 14), // "onclickCppSlot"
QT_MOC_LITERAL(6, 67, 6), // "sendTo"
QT_MOC_LITERAL(7, 74, 3) // "msg"

    },
    "SignalManager\0setTextFieldCpp\0\0text\0"
    "setProperrtyCpp\0onclickCppSlot\0sendTo\0"
    "msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignalManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,

       0        // eod
};

void SignalManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignalManager *_t = static_cast<SignalManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTextFieldCpp((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->setProperrtyCpp((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: _t->onclickCppSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SignalManager::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalManager::setTextFieldCpp)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SignalManager::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalManager::setProperrtyCpp)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SignalManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SignalManager.data,
      qt_meta_data_SignalManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignalManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignalManager.stringdata0))
        return static_cast<void*>(const_cast< SignalManager*>(this));
    return QObject::qt_metacast(_clname);
}

int SignalManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SignalManager::setTextFieldCpp(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SignalManager::setProperrtyCpp(QVariant _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
