/****************************************************************************
** Meta object code from reading C++ file 'Ventilator.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/pushpull/Ventilator.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ventilator.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator_t qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator = {
    {
QT_MOC_LITERAL(0, 0, 36), // "nzmqt::samples::pushpull::Ven..."
QT_MOC_LITERAL(1, 37, 12), // "batchStarted"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 12), // "workItemSent"
QT_MOC_LITERAL(4, 64, 8), // "workload"
QT_MOC_LITERAL(5, 73, 8) // "runBatch"

    },
    "nzmqt::samples::pushpull::Ventilator\0"
    "batchStarted\0\0workItemSent\0workload\0"
    "runBatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nzmqt__samples__pushpull__Ventilator[] = {

 // content:
       8,       // revision
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
       3,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::UInt,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void nzmqt::samples::pushpull::Ventilator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ventilator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->batchStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->workItemSent((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->runBatch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Ventilator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Ventilator::batchStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Ventilator::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Ventilator::workItemSent)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject nzmqt::samples::pushpull::Ventilator::staticMetaObject = { {
    QMetaObject::SuperData::link<SampleBase::staticMetaObject>(),
    qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator.data,
    qt_meta_data_nzmqt__samples__pushpull__Ventilator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *nzmqt::samples::pushpull::Ventilator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nzmqt::samples::pushpull::Ventilator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nzmqt__samples__pushpull__Ventilator.stringdata0))
        return static_cast<void*>(this);
    return SampleBase::qt_metacast(_clname);
}

int nzmqt::samples::pushpull::Ventilator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SampleBase::qt_metacall(_c, _id, _a);
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
void nzmqt::samples::pushpull::Ventilator::batchStarted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nzmqt::samples::pushpull::Ventilator::workItemSent(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
