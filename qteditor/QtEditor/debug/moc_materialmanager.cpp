/****************************************************************************
** Meta object code from reading C++ file 'materialmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../materialmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialManager_t {
    QByteArrayData data[12];
    char stringdata[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialManager_t qt_meta_stringdata_MaterialManager = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 29),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 5),
QT_MOC_LITERAL(4, 53, 35),
QT_MOC_LITERAL(5, 89, 29),
QT_MOC_LITERAL(6, 119, 26),
QT_MOC_LITERAL(7, 146, 5),
QT_MOC_LITERAL(8, 152, 15),
QT_MOC_LITERAL(9, 168, 16),
QT_MOC_LITERAL(10, 185, 16),
QT_MOC_LITERAL(11, 202, 14)
    },
    "MaterialManager\0on_fileListView_doubleClicked\0"
    "\0index\0on_objectMaterialList_doubleClicked\0"
    "on_saveMaterialButton_clicked\0"
    "onBoolPropertyStateChanged\0state\0"
    "onShaderChanged\0onTextureChanged\0"
    "onTextureRemoved\0onTextureAdded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaterialManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialManager *_t = static_cast<MaterialManager *>(_o);
        switch (_id) {
        case 0: _t->on_fileListView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_objectMaterialList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_saveMaterialButton_clicked(); break;
        case 3: _t->onBoolPropertyStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onShaderChanged(); break;
        case 5: _t->onTextureChanged(); break;
        case 6: _t->onTextureRemoved(); break;
        case 7: _t->onTextureAdded(); break;
        default: ;
        }
    }
}

const QMetaObject MaterialManager::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_MaterialManager.data,
      qt_meta_data_MaterialManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *MaterialManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialManager.stringdata))
        return static_cast<void*>(const_cast< MaterialManager*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int MaterialManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
