/****************************************************************************
** Meta object code from reading C++ file 'device_finder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../BLE/device_finder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device_finder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceFinder_t {
    QByteArrayData data[17];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceFinder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceFinder_t qt_meta_stringdata_DeviceFinder = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DeviceFinder"
QT_MOC_LITERAL(1, 13, 12), // "stateChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "DeviceFinder::STATE"
QT_MOC_LITERAL(4, 47, 14), // "devicesChanged"
QT_MOC_LITERAL(5, 62, 11), // "startSearch"
QT_MOC_LITERAL(6, 74, 9), // "addDevice"
QT_MOC_LITERAL(7, 84, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(8, 105, 9), // "scanError"
QT_MOC_LITERAL(9, 115, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(10, 153, 5), // "error"
QT_MOC_LITERAL(11, 159, 12), // "scanFinished"
QT_MOC_LITERAL(12, 172, 5), // "state"
QT_MOC_LITERAL(13, 178, 5), // "STATE"
QT_MOC_LITERAL(14, 184, 8), // "FINISHED"
QT_MOC_LITERAL(15, 193, 5), // "ERROR"
QT_MOC_LITERAL(16, 199, 9) // "SEARCHING"

    },
    "DeviceFinder\0stateChanged\0\0"
    "DeviceFinder::STATE\0devicesChanged\0"
    "startSearch\0addDevice\0QBluetoothDeviceInfo\0"
    "scanError\0QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0scanFinished\0state\0STATE\0FINISHED\0"
    "ERROR\0SEARCHING"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceFinder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   56, // properties
       1,   60, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x08 /* Private */,
       8,    1,   52,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

 // properties: name, type, flags
      12, 0x80000000 | 13, 0x00495009,

 // properties: notify_signal_id
       0,

 // enums: name, alias, flags, count, data
      13,   13, 0x2,    3,   65,

 // enum data: key, value
      14, uint(DeviceFinder::STATE::FINISHED),
      15, uint(DeviceFinder::STATE::ERROR),
      16, uint(DeviceFinder::STATE::SEARCHING),

       0        // eod
};

void DeviceFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceFinder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< DeviceFinder::STATE(*)>(_a[1]))); break;
        case 1: _t->devicesChanged(); break;
        case 2: _t->startSearch(); break;
        case 3: _t->addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 4: _t->scanError((*reinterpret_cast< const QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 5: _t->scanFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceFinder::*)(DeviceFinder::STATE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceFinder::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceFinder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceFinder::devicesChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DeviceFinder *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< STATE*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DeviceFinder::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DeviceFinder.data,
    qt_meta_data_DeviceFinder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceFinder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeviceFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DeviceFinder::stateChanged(DeviceFinder::STATE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceFinder::devicesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
