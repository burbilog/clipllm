/****************************************************************************
** Meta object code from reading C++ file 'trayicon.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/trayicon.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trayicon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN6ClipAI2UI8TrayIconE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN6ClipAI2UI8TrayIconE = QtMocHelpers::stringData(
    "ClipAI::UI::TrayIcon",
    "activated",
    "",
    "QSystemTrayIcon::ActivationReason",
    "reason",
    "showSettingsRequested",
    "showHistoryRequested",
    "quitRequested",
    "hotkeyTriggered",
    "promptSelected",
    "promptId",
    "showTrayMessage",
    "title",
    "message",
    "QSystemTrayIcon::MessageIcon",
    "icon",
    "millisecondsTimeoutHint",
    "onActivated",
    "onPromptTriggered",
    "onSettingsTriggered",
    "onHistoryTriggered",
    "onAboutTriggered",
    "onQuitTriggered",
    "onPromptsUpdated"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN6ClipAI2UI8TrayIconE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x06,    1 /* Public */,
       5,    0,  113,    2, 0x06,    3 /* Public */,
       6,    0,  114,    2, 0x06,    4 /* Public */,
       7,    0,  115,    2, 0x06,    5 /* Public */,
       8,    0,  116,    2, 0x06,    6 /* Public */,
       9,    1,  117,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    4,  120,    2, 0x0a,    9 /* Public */,
      11,    3,  129,    2, 0x2a,   14 /* Public | MethodCloned */,
      11,    2,  136,    2, 0x2a,   18 /* Public | MethodCloned */,
      17,    1,  141,    2, 0x08,   21 /* Private */,
      18,    0,  144,    2, 0x08,   23 /* Private */,
      19,    0,  145,    2, 0x08,   24 /* Private */,
      20,    0,  146,    2, 0x08,   25 /* Private */,
      21,    0,  147,    2, 0x08,   26 /* Private */,
      22,    0,  148,    2, 0x08,   27 /* Private */,
      23,    0,  149,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 14, QMetaType::Int,   12,   13,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 14,   12,   13,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClipAI::UI::TrayIcon::staticMetaObject = { {
    QMetaObject::SuperData::link<QSystemTrayIcon::staticMetaObject>(),
    qt_meta_stringdata_ZN6ClipAI2UI8TrayIconE.offsetsAndSizes,
    qt_meta_data_ZN6ClipAI2UI8TrayIconE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN6ClipAI2UI8TrayIconE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TrayIcon, std::true_type>,
        // method 'activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::ActivationReason, std::false_type>,
        // method 'showSettingsRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showHistoryRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quitRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hotkeyTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'promptSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showTrayMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::MessageIcon, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showTrayMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::MessageIcon, std::false_type>,
        // method 'showTrayMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::ActivationReason, std::false_type>,
        // method 'onPromptTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSettingsTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHistoryTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAboutTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQuitTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPromptsUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ClipAI::UI::TrayIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TrayIcon *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::ActivationReason>>(_a[1]))); break;
        case 1: _t->showSettingsRequested(); break;
        case 2: _t->showHistoryRequested(); break;
        case 3: _t->quitRequested(); break;
        case 4: _t->hotkeyTriggered(); break;
        case 5: _t->promptSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->showTrayMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::MessageIcon>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 7: _t->showTrayMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::MessageIcon>>(_a[3]))); break;
        case 8: _t->showTrayMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->onActivated((*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::ActivationReason>>(_a[1]))); break;
        case 10: _t->onPromptTriggered(); break;
        case 11: _t->onSettingsTriggered(); break;
        case 12: _t->onHistoryTriggered(); break;
        case 13: _t->onAboutTriggered(); break;
        case 14: _t->onQuitTriggered(); break;
        case 15: _t->onPromptsUpdated(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (TrayIcon::*)(QSystemTrayIcon::ActivationReason );
            if (_q_method_type _q_method = &TrayIcon::activated; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (TrayIcon::*)();
            if (_q_method_type _q_method = &TrayIcon::showSettingsRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (TrayIcon::*)();
            if (_q_method_type _q_method = &TrayIcon::showHistoryRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (TrayIcon::*)();
            if (_q_method_type _q_method = &TrayIcon::quitRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (TrayIcon::*)();
            if (_q_method_type _q_method = &TrayIcon::hotkeyTriggered; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (TrayIcon::*)(const QString & );
            if (_q_method_type _q_method = &TrayIcon::promptSelected; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *ClipAI::UI::TrayIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClipAI::UI::TrayIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN6ClipAI2UI8TrayIconE.stringdata0))
        return static_cast<void*>(this);
    return QSystemTrayIcon::qt_metacast(_clname);
}

int ClipAI::UI::TrayIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ClipAI::UI::TrayIcon::activated(QSystemTrayIcon::ActivationReason _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClipAI::UI::TrayIcon::showSettingsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClipAI::UI::TrayIcon::showHistoryRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ClipAI::UI::TrayIcon::quitRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClipAI::UI::TrayIcon::hotkeyTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ClipAI::UI::TrayIcon::promptSelected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
