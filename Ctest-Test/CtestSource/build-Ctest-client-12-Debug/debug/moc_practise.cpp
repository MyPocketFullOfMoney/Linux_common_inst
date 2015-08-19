/****************************************************************************
** Meta object code from reading C++ file 'practise.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ctest-client/practise.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'practise.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_practise[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x08,
      26,    9,    9,    9, 0x08,
      59,    9,    9,    9, 0x08,
      88,    9,    9,    9, 0x08,
     119,    9,    9,    9, 0x08,
     150,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_practise[] = {
    "practise\0\0row\0change(int)\0"
    "on_pushButton_Practise_clicked()\0"
    "on_pushButton_Exit_clicked()\0"
    "on_pushButton_ProAdd_clicked()\0"
    "on_pushButton_ProDel_clicked()\0"
    "on_pushButton_ProEdit_clicked()\0"
};

void practise::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        practise *_t = static_cast<practise *>(_o);
        switch (_id) {
        case 0: _t->change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Practise_clicked(); break;
        case 2: _t->on_pushButton_Exit_clicked(); break;
        case 3: _t->on_pushButton_ProAdd_clicked(); break;
        case 4: _t->on_pushButton_ProDel_clicked(); break;
        case 5: _t->on_pushButton_ProEdit_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData practise::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject practise::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_practise,
      qt_meta_data_practise, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &practise::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *practise::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *practise::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_practise))
        return static_cast<void*>(const_cast< practise*>(this));
    return QDialog::qt_metacast(_clname);
}

int practise::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
