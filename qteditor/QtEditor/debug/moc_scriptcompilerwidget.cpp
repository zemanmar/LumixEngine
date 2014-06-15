/****************************************************************************
** Meta object code from reading C++ file 'scriptcompilerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scripts/scriptcompilerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scriptcompilerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScriptCompilerWidget_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptCompilerWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptCompilerWidget_t qt_meta_stringdata_ScriptCompilerWidget = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 25),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 5),
QT_MOC_LITERAL(4, 54, 10),
QT_MOC_LITERAL(5, 65, 7),
QT_MOC_LITERAL(6, 73, 27)
    },
    "ScriptCompilerWidget\0on_scriptListView_clicked\0"
    "\0index\0logMessage\0message\0"
    "on_compileAllButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptCompilerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void ScriptCompilerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptCompilerWidget *_t = static_cast<ScriptCompilerWidget *>(_o);
        switch (_id) {
        case 0: _t->on_scriptListView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_compileAllButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ScriptCompilerWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_ScriptCompilerWidget.data,
      qt_meta_data_ScriptCompilerWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptCompilerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptCompilerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptCompilerWidget.stringdata))
        return static_cast<void*>(const_cast< ScriptCompilerWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int ScriptCompilerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
