/****************************************************************************
** Meta object code from reading C++ file 'Sink.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/pushpull/Sink.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sink.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nzmqt__samples__pushpull__Sink_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nzmqt__samples__pushpull__Sink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nzmqt__samples__pushpull__Sink_t qt_meta_stringdata_nzmqt__samples__pushpull__Sink = {
    {
QT_MOC_LITERAL(0, 0, 30), // "nzmqt::samples::pushpull::Sink"
QT_MOC_LITERAL(1, 31, 12), // "batchStarted"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 17), // "numberOfWorkItems"
QT_MOC_LITERAL(4, 63, 22), // "workItemResultReceived"
QT_MOC_LITERAL(5, 86, 14), // "batchCompleted"
QT_MOC_LITERAL(6, 101, 10), // "batchEvent"
QT_MOC_LITERAL(7, 112, 7) // "message"

    },
    "nzmqt::samples::pushpull::Sink\0"
    "batchStarted\0\0numberOfWorkItems\0"
    "workItemResultReceived\0batchCompleted\0"
    "batchEvent\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nzmqt__samples__pushpull__Sink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   39,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    7,

       0        // eod
};

void nzmqt::samples::pushpull::Sink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->batchStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->workItemResultReceived(); break;
        case 2: _t->batchCompleted(); break;
        case 3: _t->batchEvent((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sink::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sink::batchStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Sink::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sink::workItemResultReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Sink::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Sink::batchCompleted)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject nzmqt::samples::pushpull::Sink::staticMetaObject = { {
    QMetaObject::SuperData::link<SampleBase::staticMetaObject>(),
    qt_meta_stringdata_nzmqt__samples__pushpull__Sink.data,
    qt_meta_data_nzmqt__samples__pushpull__Sink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *nzmqt::samples::pushpull::Sink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nzmqt::samples::pushpull::Sink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nzmqt__samples__pushpull__Sink.stringdata0))
        return static_cast<void*>(this);
    return SampleBase::qt_metacast(_clname);
}

int nzmqt::samples::pushpull::Sink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SampleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void nzmqt::samples::pushpull::Sink::batchStarted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nzmqt::samples::pushpull::Sink::workItemResultReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void nzmqt::samples::pushpull::Sink::batchCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
