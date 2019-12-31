/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelect_All;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionAbout_seu_IDE;
    QAction *actionSave_As;
    QAction *actionCompileOutPut;
    QAction *actionCompile;
    QAction *actionAssemblyOutPut;
    QAction *actionAssemblyNew;
    QAction *actionAssemblyAppend;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menuAssembly;
    QMenu *menu_5;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetCompile;
    QWidget *widgetCompileContents;
    QGridLayout *gridLayout_4;
    QTextEdit *textEditCompileOutput;
    QDockWidget *dockWidgetAssembly;
    QWidget *widgetAssemblyContents;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditAssemblyOutput;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 850);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/img/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/img/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/img/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/img/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/img/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon9);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/img/select_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_All->setIcon(icon10);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/img/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon11);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QStringLiteral("actionReplace"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/img/replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon12);
        actionAbout_seu_IDE = new QAction(MainWindow);
        actionAbout_seu_IDE->setObjectName(QStringLiteral("actionAbout_seu_IDE"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionCompileOutPut = new QAction(MainWindow);
        actionCompileOutPut->setObjectName(QStringLiteral("actionCompileOutPut"));
        actionCompileOutPut->setCheckable(true);
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QStringLiteral("actionCompile"));
        actionAssemblyOutPut = new QAction(MainWindow);
        actionAssemblyOutPut->setObjectName(QStringLiteral("actionAssemblyOutPut"));
        actionAssemblyOutPut->setCheckable(true);
        actionAssemblyOutPut->setChecked(false);
        actionAssemblyNew = new QAction(MainWindow);
        actionAssemblyNew->setObjectName(QStringLiteral("actionAssemblyNew"));
        actionAssemblyAppend = new QAction(MainWindow);
        actionAssemblyAppend->setObjectName(QStringLiteral("actionAssemblyAppend"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menuAssembly = new QMenu(menu_4);
        menuAssembly->setObjectName(QStringLiteral("menuAssembly"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(9);
        mainToolBar->setFont(font);
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(25, 25));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetCompile = new QDockWidget(MainWindow);
        dockWidgetCompile->setObjectName(QStringLiteral("dockWidgetCompile"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        dockWidgetCompile->setFont(font1);
        dockWidgetCompile->setStyleSheet(QStringLiteral("font: 10pt \"Consolas\";"));
        dockWidgetCompile->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        widgetCompileContents = new QWidget();
        widgetCompileContents->setObjectName(QStringLiteral("widgetCompileContents"));
        gridLayout_4 = new QGridLayout(widgetCompileContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textEditCompileOutput = new QTextEdit(widgetCompileContents);
        textEditCompileOutput->setObjectName(QStringLiteral("textEditCompileOutput"));
        textEditCompileOutput->setFont(font1);
        textEditCompileOutput->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_4->addWidget(textEditCompileOutput, 0, 0, 1, 1);

        dockWidgetCompile->setWidget(widgetCompileContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetCompile);
        dockWidgetAssembly = new QDockWidget(MainWindow);
        dockWidgetAssembly->setObjectName(QStringLiteral("dockWidgetAssembly"));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(10);
        dockWidgetAssembly->setFont(font2);
        dockWidgetAssembly->setFloating(false);
        dockWidgetAssembly->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        widgetAssemblyContents = new QWidget();
        widgetAssemblyContents->setObjectName(QStringLiteral("widgetAssemblyContents"));
        gridLayout_2 = new QGridLayout(widgetAssemblyContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEditAssemblyOutput = new QTextEdit(widgetAssemblyContents);
        textEditAssemblyOutput->setObjectName(QStringLiteral("textEditAssemblyOutput"));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        textEditAssemblyOutput->setFont(font3);
        textEditAssemblyOutput->setUndoRedoEnabled(false);
        textEditAssemblyOutput->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(textEditAssemblyOutput, 0, 0, 1, 1);

        dockWidgetAssembly->setWidget(widgetAssemblyContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetAssembly);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu->addAction(actionSave_As);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionUndo);
        menu_2->addAction(actionRedo);
        menu_2->addSeparator();
        menu_2->addAction(actionCut);
        menu_2->addAction(actionCopy);
        menu_2->addAction(actionPaste);
        menu_2->addSeparator();
        menu_2->addAction(actionSelect_All);
        menu_2->addSeparator();
        menu_2->addAction(actionFind);
        menu_2->addAction(actionReplace);
        menu_4->addAction(actionCompile);
        menu_4->addAction(menuAssembly->menuAction());
        menuAssembly->addAction(actionAssemblyNew);
        menuAssembly->addAction(actionAssemblyAppend);
        menu_5->addAction(actionAbout_seu_IDE);
        menu_3->addAction(actionCompileOutPut);
        menu_3->addAction(actionAssemblyOutPut);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(dockWidgetCompile, SIGNAL(visibilityChanged(bool)), actionCompileOutPut, SLOT(setChecked(bool)));
        QObject::connect(dockWidgetAssembly, SIGNAL(visibilityChanged(bool)), actionAssemblyOutPut, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SEU IDE", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSelect_All->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSelect_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("MainWindow", "\346\233\277\346\215\242", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout_seu_IDE->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        actionCompileOutPut->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221\350\276\223\345\207\272", Q_NULLPTR));
        actionCompile->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCompile->setShortcut(QApplication::translate("MainWindow", "Ctrl+F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAssemblyOutPut->setText(QApplication::translate("MainWindow", "\346\261\207\347\274\226\350\276\223\345\207\272", Q_NULLPTR));
        actionAssemblyNew->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245\345\210\260\346\226\260\346\226\207\344\273\266  ", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAssemblyNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+F9", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAssemblyAppend->setText(QApplication::translate("MainWindow", "\350\277\275\345\212\240\345\210\260\346\227\247\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAssemblyAppend->setShortcut(QApplication::translate("MainWindow", "Ctrl+F10", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266 ", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221 ", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\236\204\345\273\272 ", Q_NULLPTR));
        menuAssembly->setTitle(QApplication::translate("MainWindow", "\346\261\207\347\274\226", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251 ", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276 ", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        dockWidgetCompile->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        dockWidgetCompile->setWindowTitle(QApplication::translate("MainWindow", "\347\274\226\350\257\221\350\276\223\345\207\272", Q_NULLPTR));
        dockWidgetAssembly->setWindowTitle(QApplication::translate("MainWindow", "\346\261\207\347\274\226\350\276\223\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
