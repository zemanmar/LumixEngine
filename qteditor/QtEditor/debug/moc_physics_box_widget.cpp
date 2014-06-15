/****************************************************************************
** Meta object code from reading C++ file 'physics_box_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../propertywidgets/physics_box_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'physics_box_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PhysicsBoxWidget_t {
    QByteArrayData data[8];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PhysicsBoxWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PhysicsBoxWidget_t qt_meta_stringdata_PhysicsBoxWidget = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 28),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 7),
QT_MOC_LITERAL(4, 55, 26),
QT_MOC_LITERAL(5, 82, 4),
QT_MOC_LITERAL(6, 87, 26),
QT_MOC_LITERAL(7, 114, 26)
    },
    "PhysicsBoxWidget\0on_isDynamicCheckBox_toggled\0"
    "\0checked\0on_xSizeInput_valueChanged\0"
    "arg1\0on_ySizeInput_valueChanged\0"
    "on_zSizeInput_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PhysicsBoxWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void PhysicsBoxWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PhysicsBoxWidget *_t = static_cast<PhysicsBoxWidget *>(_o);
        switch (_id) {
        case 0: _t->on_isDynamicCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_xSizeInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_ySizeInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_zSizeInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PhysicsBoxWidget::staticMetaObject = {
    { &PropertyWidgetBase::staticMetaObject, qt_meta_stringdata_PhysicsBoxWidget.data,
      qt_meta_data_PhysicsBoxWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *PhysicsBoxWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PhysicsBoxWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhysicsBoxWidget.stringdata))
        return static_cast<void*>(const_cast< PhysicsBoxWidget*>(this));
    return PropertyWidgetBase::qt_metacast(_clname);
}

int PhysicsBoxWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertyWidgetBase::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
