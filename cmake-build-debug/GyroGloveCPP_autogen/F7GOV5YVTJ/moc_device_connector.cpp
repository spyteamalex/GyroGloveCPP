/****************************************************************************
** Meta object code from reading C++ file 'device_connector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../BLE/device_connector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device_connector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceConnector_t {
    QByteArrayData data[26];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceConnector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceConnector_t qt_meta_stringdata_DeviceConnector = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DeviceConnector"
QT_MOC_LITERAL(1, 16, 12), // "stateChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "State"
QT_MOC_LITERAL(4, 36, 12), // "dataReceived"
QT_MOC_LITERAL(5, 49, 17), // "serviceDiscovered"
QT_MOC_LITERAL(6, 67, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(7, 82, 15), // "serviceScanDone"
QT_MOC_LITERAL(8, 98, 19), // "serviceStateChanged"
QT_MOC_LITERAL(9, 118, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(10, 150, 1), // "s"
QT_MOC_LITERAL(11, 152, 11), // "receiveData"
QT_MOC_LITERAL(12, 164, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(13, 189, 1), // "c"
QT_MOC_LITERAL(14, 191, 5), // "value"
QT_MOC_LITERAL(15, 197, 24), // "confirmedDescriptorWrite"
QT_MOC_LITERAL(16, 222, 20), // "QLowEnergyDescriptor"
QT_MOC_LITERAL(17, 243, 1), // "d"
QT_MOC_LITERAL(18, 245, 11), // "AddressType"
QT_MOC_LITERAL(19, 257, 13), // "PublicAddress"
QT_MOC_LITERAL(20, 271, 13), // "RandomAddress"
QT_MOC_LITERAL(21, 285, 9), // "Connected"
QT_MOC_LITERAL(22, 295, 12), // "Disconnected"
QT_MOC_LITERAL(23, 308, 9), // "BadDevice"
QT_MOC_LITERAL(24, 318, 16), // "ServiceConnected"
QT_MOC_LITERAL(25, 335, 5) // "Error"

    },
    "DeviceConnector\0stateChanged\0\0State\0"
    "dataReceived\0serviceDiscovered\0"
    "QBluetoothUuid\0serviceScanDone\0"
    "serviceStateChanged\0QLowEnergyService::ServiceState\0"
    "s\0receiveData\0QLowEnergyCharacteristic\0"
    "c\0value\0confirmedDescriptorWrite\0"
    "QLowEnergyDescriptor\0d\0AddressType\0"
    "PublicAddress\0RandomAddress\0Connected\0"
    "Disconnected\0BadDevice\0ServiceConnected\0"
    "Error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceConnector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       2,   72, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   55,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,
      11,    2,   62,    2, 0x08 /* Private */,
      15,    2,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QByteArray,   13,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QByteArray,   17,   14,

 // enums: name, alias, flags, count, data
      18,   18, 0x2,    2,   82,
       3,    3, 0x2,    5,   86,

 // enum data: key, value
      19, uint(DeviceConnector::AddressType::PublicAddress),
      20, uint(DeviceConnector::AddressType::RandomAddress),
      21, uint(DeviceConnector::State::Connected),
      22, uint(DeviceConnector::State::Disconnected),
      23, uint(DeviceConnector::State::BadDevice),
      24, uint(DeviceConnector::State::ServiceConnected),
      25, uint(DeviceConnector::State::Error),

       0        // eod
};

void DeviceConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceConnector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< State(*)>(_a[1]))); break;
        case 1: _t->dataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->serviceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 3: _t->serviceScanDone(); break;
        case 4: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 5: _t->receiveData((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 6: _t->confirmedDescriptorWrite((*reinterpret_cast< const QLowEnergyDescriptor(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 6:
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
            using _t = void (DeviceConnector::*)(State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceConnector::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceConnector::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceConnector::dataReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceConnector::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DeviceConnector.data,
    qt_meta_data_DeviceConnector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceConnector.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeviceConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DeviceConnector::stateChanged(State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceConnector::dataReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
