/****************************************************************************
** Meta object code from reading C++ file 'devicehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../devicehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceHandler_t {
    QByteArrayData data[24];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceHandler_t qt_meta_stringdata_DeviceHandler = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DeviceHandler"
QT_MOC_LITERAL(1, 14, 12), // "aliveChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "dataReceived"
QT_MOC_LITERAL(4, 41, 17), // "disconnectService"
QT_MOC_LITERAL(5, 59, 17), // "serviceDiscovered"
QT_MOC_LITERAL(6, 77, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(7, 92, 15), // "serviceScanDone"
QT_MOC_LITERAL(8, 108, 19), // "serviceStateChanged"
QT_MOC_LITERAL(9, 128, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(10, 160, 1), // "s"
QT_MOC_LITERAL(11, 162, 11), // "receiveData"
QT_MOC_LITERAL(12, 174, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(13, 199, 1), // "c"
QT_MOC_LITERAL(14, 201, 5), // "value"
QT_MOC_LITERAL(15, 207, 24), // "confirmedDescriptorWrite"
QT_MOC_LITERAL(16, 232, 20), // "QLowEnergyDescriptor"
QT_MOC_LITERAL(17, 253, 1), // "d"
QT_MOC_LITERAL(18, 255, 5), // "alive"
QT_MOC_LITERAL(19, 261, 11), // "addressType"
QT_MOC_LITERAL(20, 273, 11), // "AddressType"
QT_MOC_LITERAL(21, 285, 4), // "data"
QT_MOC_LITERAL(22, 290, 13), // "PublicAddress"
QT_MOC_LITERAL(23, 304, 13) // "RandomAddress"

    },
    "DeviceHandler\0aliveChanged\0\0dataReceived\0"
    "disconnectService\0serviceDiscovered\0"
    "QBluetoothUuid\0serviceScanDone\0"
    "serviceStateChanged\0QLowEnergyService::ServiceState\0"
    "s\0receiveData\0QLowEnergyCharacteristic\0"
    "c\0value\0confirmedDescriptorWrite\0"
    "QLowEnergyDescriptor\0d\0alive\0addressType\0"
    "AddressType\0data\0PublicAddress\0"
    "RandomAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   76, // properties
       1,   88, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x0a /* Public */,
       5,    1,   59,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
      11,    2,   66,    2, 0x08 /* Private */,
      15,    2,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QByteArray,   13,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QByteArray,   17,   14,

 // properties: name, type, flags
      18, QMetaType::Bool, 0x00495001,
      19, 0x80000000 | 20, 0x0009510b,
      21, QMetaType::QByteArray, 0x00095000,

 // properties: notify_signal_id
       0,
       0,
       0,

 // enums: name, alias, flags, count, data
      20,   20, 0x2,    2,   93,

 // enum data: key, value
      22, uint(DeviceHandler::AddressType::PublicAddress),
      23, uint(DeviceHandler::AddressType::RandomAddress),

       0        // eod
};

void DeviceHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aliveChanged(); break;
        case 1: _t->dataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->disconnectService(); break;
        case 3: _t->serviceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 4: _t->serviceScanDone(); break;
        case 5: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 6: _t->receiveData((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 7: _t->confirmedDescriptorWrite((*reinterpret_cast< const QLowEnergyDescriptor(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyDescriptor >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceHandler::aliveChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceHandler::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceHandler::dataReceived)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->alive(); break;
        case 1: *reinterpret_cast< AddressType*>(_v) = _t->addressType(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DeviceHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setAddressType(*reinterpret_cast< AddressType*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DeviceHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DeviceHandler.data,
    qt_meta_data_DeviceHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeviceHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DeviceHandler::aliveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DeviceHandler::dataReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
