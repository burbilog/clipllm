/****************************************************************************
** Meta object code from reading C++ file 'settingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/settingsdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsdialog.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6ClipAI2UI14SettingsDialogE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN6ClipAI2UI14SettingsDialogE = QtMocHelpers::stringData(
    "ClipAI::UI::SettingsDialog",
    "settingsChanged",
    "",
    "languageChanged",
    "language",
    "hotkeyChanged",
    "QKeySequence",
    "hotkey",
    "onTabChanged",
    "index",
    "onApplyClicked",
    "onOkClicked",
    "onResetClicked",
    "onLanguageChanged",
    "onProviderChanged",
    "onModelChanged",
    "onApiKeyChanged",
    "onTestConnectionClicked",
    "onRefreshModelsClicked",
    "onModelsFetchFinished",
    "QNetworkReply*",
    "reply",
    "onHotkeyChanged",
    "sequence",
    "onAddPromptClicked",
    "onEditPromptClicked",
    "onDeletePromptClicked",
    "onImportPromptsClicked",
    "onExportPromptsClicked",
    "onResetPromptsClicked",
    "onPromptSelectionChanged",
    "onClearHistoryClicked",
    "onHistoryLimitChanged",
    "value",
    "onAutoCleanupChanged",
    "state",
    "onDaysToKeepChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN6ClipAI2UI14SettingsDialogE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x06,    1 /* Public */,
       3,    1,  171,    2, 0x06,    2 /* Public */,
       5,    1,  174,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  177,    2, 0x08,    6 /* Private */,
      10,    0,  180,    2, 0x08,    8 /* Private */,
      11,    0,  181,    2, 0x08,    9 /* Private */,
      12,    0,  182,    2, 0x08,   10 /* Private */,
      13,    1,  183,    2, 0x08,   11 /* Private */,
      14,    1,  186,    2, 0x08,   13 /* Private */,
      15,    1,  189,    2, 0x08,   15 /* Private */,
      16,    0,  192,    2, 0x08,   17 /* Private */,
      17,    0,  193,    2, 0x08,   18 /* Private */,
      18,    0,  194,    2, 0x08,   19 /* Private */,
      19,    1,  195,    2, 0x08,   20 /* Private */,
      22,    1,  198,    2, 0x08,   22 /* Private */,
      24,    0,  201,    2, 0x08,   24 /* Private */,
      25,    0,  202,    2, 0x08,   25 /* Private */,
      26,    0,  203,    2, 0x08,   26 /* Private */,
      27,    0,  204,    2, 0x08,   27 /* Private */,
      28,    0,  205,    2, 0x08,   28 /* Private */,
      29,    0,  206,    2, 0x08,   29 /* Private */,
      30,    0,  207,    2, 0x08,   30 /* Private */,
      31,    0,  208,    2, 0x08,   31 /* Private */,
      32,    1,  209,    2, 0x08,   32 /* Private */,
      34,    1,  212,    2, 0x08,   34 /* Private */,
      36,    1,  215,    2, 0x08,   36 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 6,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   33,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClipAI::UI::SettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN6ClipAI2UI14SettingsDialogE.offsetsAndSizes,
    qt_meta_data_ZN6ClipAI2UI14SettingsDialogE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN6ClipAI2UI14SettingsDialogE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingsDialog, std::true_type>,
        // method 'settingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'languageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'hotkeyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>,
        // method 'onTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onApplyClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOkClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLanguageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onProviderChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onModelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onApiKeyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTestConnectionClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRefreshModelsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModelsFetchFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'onHotkeyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>,
        // method 'onAddPromptClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEditPromptClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeletePromptClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onImportPromptsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExportPromptsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetPromptsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPromptSelectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClearHistoryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHistoryLimitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onAutoCleanupChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onDaysToKeepChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ClipAI::UI::SettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SettingsDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->settingsChanged(); break;
        case 1: _t->languageChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->hotkeyChanged((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1]))); break;
        case 3: _t->onTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onApplyClicked(); break;
        case 5: _t->onOkClicked(); break;
        case 6: _t->onResetClicked(); break;
        case 7: _t->onLanguageChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->onProviderChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->onModelChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->onApiKeyChanged(); break;
        case 11: _t->onTestConnectionClicked(); break;
        case 12: _t->onRefreshModelsClicked(); break;
        case 13: _t->onModelsFetchFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 14: _t->onHotkeyChanged((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1]))); break;
        case 15: _t->onAddPromptClicked(); break;
        case 16: _t->onEditPromptClicked(); break;
        case 17: _t->onDeletePromptClicked(); break;
        case 18: _t->onImportPromptsClicked(); break;
        case 19: _t->onExportPromptsClicked(); break;
        case 20: _t->onResetPromptsClicked(); break;
        case 21: _t->onPromptSelectionChanged(); break;
        case 22: _t->onClearHistoryClicked(); break;
        case 23: _t->onHistoryLimitChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->onAutoCleanupChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->onDaysToKeepChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (SettingsDialog::*)();
            if (_q_method_type _q_method = &SettingsDialog::settingsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (SettingsDialog::*)(const QString & );
            if (_q_method_type _q_method = &SettingsDialog::languageChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (SettingsDialog::*)(const QKeySequence & );
            if (_q_method_type _q_method = &SettingsDialog::hotkeyChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ClipAI::UI::SettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClipAI::UI::SettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN6ClipAI2UI14SettingsDialogE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ClipAI::UI::SettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void ClipAI::UI::SettingsDialog::settingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClipAI::UI::SettingsDialog::languageChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClipAI::UI::SettingsDialog::hotkeyChanged(const QKeySequence & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
