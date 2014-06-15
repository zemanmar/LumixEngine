/****************************************************************************
** Meta object code from reading C++ file 'fileserverwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fileserverwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileserverwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileServerWidget_t {
    QByteArrayData data[15];
    char stringdata[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileServerWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileServerWidget_t qt_meta_stringdata_FileServerWidget = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 9),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 5),
QT_MOC_LITERAL(4, 34, 6),
QT_MOC_LITERAL(5, 41, 4),
QT_MOC_LITERAL(6, 46, 3),
QT_MOC_LITERAL(7, 50, 5),
QT_MOC_LITERAL(8, 56, 4),
QT_MOC_LITERAL(9, 61, 11),
QT_MOC_LITERAL(10, 73, 21),
QT_MOC_LITERAL(11, 95, 19),
QT_MOC_LITERAL(12, 115, 23),
QT_MOC_LITERAL(13, 139, 24),
QT_MOC_LITERAL(14, 164, 4)
    },
    "FileServerWidget\0fileEvent\0\0event\0"
    "handle\0path\0ret\0param\0time\0onFileEvent\0"
    "on_pushButton_clicked\0on_filterCB_clicked\0"
    "on_filter_returnPressed\0"
    "on_checkBox_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileServerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    6,   57,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::LongLong, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::LongLong,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::LongLong, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::LongLong,    3,    4,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void FileServerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileServerWidget *_t = static_cast<FileServerWidget *>(_o);
        switch (_id) {
        case 0: _t->fileEvent((*reinterpret_cast< qint32(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< qint32(*)>(_a[5])),(*reinterpret_cast< qint64(*)>(_a[6]))); break;
        case 1: _t->onFileEvent((*reinterpret_cast< qint32(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< qint32(*)>(_a[5])),(*reinterpret_cast< qint64(*)>(_a[6]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_filterCB_clicked(); break;
        case 4: _t->on_filter_returnPressed(); break;
        case 5: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileServerWidget::*_t)(qint32 , qint64 , const QString & , qint32 , qint32 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileServerWidget::fileEvent)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FileServerWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_FileServerWidget.data,
      qt_meta_data_FileServerWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *FileServerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileServerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileServerWidget.stringdata))
        return static_cast<void*>(const_cast< FileServerWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int FileServerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FileServerWidget::fileEvent(qint32 _t1, qint64 _t2, const QString & _t3, qint32 _t4, qint32 _t5, qint64 _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
