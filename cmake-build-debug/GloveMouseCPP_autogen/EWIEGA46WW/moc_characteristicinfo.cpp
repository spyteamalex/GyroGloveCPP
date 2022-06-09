/****************************************************************************
** Meta object code from reading C++ file 'characteristicinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../characteristicinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'characteristicinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CharacteristicInfo_t {
    QByteArrayData data[8];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CharacteristicInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CharacteristicInfo_t qt_meta_stringdata_CharacteristicInfo = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CharacteristicInfo"
QT_MOC_LITERAL(1, 19, 21), // "characteristicChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 18), // "characteristicName"
QT_MOC_LITERAL(4, 61, 18), // "characteristicUuid"
QT_MOC_LITERAL(5, 80, 19), // "characteristicValue"
QT_MOC_LITERAL(6, 100, 20), // "characteristicHandle"
QT_MOC_LITERAL(7, 121, 24) // "characteristicPermission"

    },
    "CharacteristicInfo\0characteristicChanged\0"
    "\0characteristicName\0characteristicUuid\0"
    "characteristicValue\0characteristicHandle\0"
    "characteristicPermission"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CharacteristicInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       5,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495001,
       4, QMetaType::QString, 0x00495001,
       5, QMetaType::QString, 0x00495001,
       6, QMetaType::QString, 0x00495001,
       7, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void CharacteristicInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharacteristicInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->characteristicChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CharacteristicInfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CharacteristicInfo::characteristicChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CharacteristicInfo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getUuid(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getValue(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getHandle(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getPermission(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CharacteristicInfo::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CharacteristicInfo.data,
    qt_meta_data_CharacteristicInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CharacteristicInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharacteristicInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CharacteristicInfo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CharacteristicInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CharacteristicInfo::characteristicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
