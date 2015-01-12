/****************************************************************************
** Meta object code from reading C++ file 'fullscreenwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../fullscreenwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fullscreenwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FullScreenWindow_t {
    QByteArrayData data[13];
    char stringdata[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FullScreenWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FullScreenWindow_t qt_meta_stringdata_FullScreenWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FullScreenWindow"
QT_MOC_LITERAL(1, 17, 45), // "on_listView_WindowSelection_c..."
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 7), // "current"
QT_MOC_LITERAL(4, 72, 8), // "previous"
QT_MOC_LITERAL(5, 81, 35), // "on_listView_WindowSelection_E..."
QT_MOC_LITERAL(6, 117, 8), // "QWidget*"
QT_MOC_LITERAL(7, 126, 6), // "editor"
QT_MOC_LITERAL(8, 133, 34), // "QAbstractItemDelegate::EndEdi..."
QT_MOC_LITERAL(9, 168, 4), // "hint"
QT_MOC_LITERAL(10, 173, 44), // "on_pushButton_toggleProfilesS..."
QT_MOC_LITERAL(11, 218, 39), // "on_comboBox_Monitor_currentIn..."
QT_MOC_LITERAL(12, 258, 5) // "index"

    },
    "FullScreenWindow\0"
    "on_listView_WindowSelection_currentRowChanged\0"
    "\0current\0previous\0on_listView_WindowSelection_EditEnd\0"
    "QWidget*\0editor\0QAbstractItemDelegate::EndEditHint\0"
    "hint\0on_pushButton_toggleProfilesSettings_clicked\0"
    "on_comboBox_Monitor_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FullScreenWindow[] = {

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
       1,    2,   34,    2, 0x08 /* Private */,
       5,    2,   39,    2, 0x08 /* Private */,
      10,    0,   44,    2, 0x08 /* Private */,
      11,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void FullScreenWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FullScreenWindow *_t = static_cast<FullScreenWindow *>(_o);
        switch (_id) {
        case 0: _t->on_listView_WindowSelection_currentRowChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->on_listView_WindowSelection_EditEnd((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QAbstractItemDelegate::EndEditHint(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_toggleProfilesSettings_clicked(); break;
        case 3: _t->on_comboBox_Monitor_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject FullScreenWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FullScreenWindow.data,
      qt_meta_data_FullScreenWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FullScreenWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FullScreenWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FullScreenWindow.stringdata))
        return static_cast<void*>(const_cast< FullScreenWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FullScreenWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
