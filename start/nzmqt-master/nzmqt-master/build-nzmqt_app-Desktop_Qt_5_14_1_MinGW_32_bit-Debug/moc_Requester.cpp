/****************************************************************************
** Meta object code from reading C++ file 'Requester.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/reqrep/Requester.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Requester.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_nzmqt__samples__reqrep__Requester_t {
    QByteArrayData data[8];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_nzmqt__samples__reqrep__Requester_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_nzmqt__samples__reqrep__Requester_t qt_meta_stringdata_nzmqt__samples__reqrep__Requester = {
    {
QT_MOC_LITERAL(0, 0, 33), // "nzmqt::samples::reqrep::Reque..."
QT_MOC_LITERAL(1, 34, 11), // "requestSent"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 7), // "request"
QT_MOC_LITERAL(4, 55, 13), // "replyReceived"
QT_MOC_LITERAL(5, 69, 5), // "reply"
QT_MOC_LITERAL(6, 75, 11), // "sendRequest"
QT_MOC_LITERAL(7, 87, 12) // "receiveReply"

    },
    "nzmqt::samples::reqrep::Requester\0"
    "requestSent\0\0request\0replyReceived\0"
    "reply\0sendRequest\0receiveReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nzmqt__samples__reqrep__Requester[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x09 /* Protected */,
       7,    1,   41,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    3,
    QMetaType::Void, QMetaType::QByteArrayList,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArrayList,    5,

       0        // eod
};

void nzmqt::samples::reqrep::Requester::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Requester *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestSent((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 1: _t->replyReceived((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 2: _t->sendRequest(); break;
        case 3: _t->receiveReply((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Requester::*)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Requester::requestSent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Requester::*)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Requester::replyReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject nzmqt::samples::reqrep::Requester::staticMetaObject = { {
    QMetaObject::SuperData::link<SampleBase::staticMetaObject>(),
    qt_meta_stringdata_nzmqt__samples__reqrep__Requester.data,
    qt_meta_data_nzmqt__samples__reqrep__Requester,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *nzmqt::samples::reqrep::Requester::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nzmqt::samples::reqrep::Requester::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_nzmqt__samples__reqrep__Requester.stringdata0))
        return static_cast<void*>(this);
    return SampleBase::qt_metacast(_clname);
}

int nzmqt::samples::reqrep::Requester::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void nzmqt::samples::reqrep::Requester::requestSent(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nzmqt::samples::reqrep::Requester::replyReceived(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
