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
    QDockWidget *dockWidget_compile;
    QWidget *dockWidgetContents_compile;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_compile_output;
    QDockWidget *dockWidget_assembly;
    QWidget *dockWidgetContents_assembly;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_assembly_output;

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
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QStringLiteral("actionCompile"));
        actionAssemblyOutPut = new QAction(MainWindow);
        actionAssemblyOutPut->setObjectName(QStringLiteral("actionAssemblyOutPut"));
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
        dockWidget_compile = new QDockWidget(MainWindow);
        dockWidget_compile->setObjectName(QStringLiteral("dockWidget_compile"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        dockWidget_compile->setFont(font1);
        dockWidget_compile->setStyleSheet(QStringLiteral("font: 10pt \"Consolas\";"));
        dockWidget_compile->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_compile = new QWidget();
        dockWidgetContents_compile->setObjectName(QStringLiteral("dockWidgetContents_compile"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_compile);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textEdit_compile_output = new QTextEdit(dockWidgetContents_compile);
        textEdit_compile_output->setObjectName(QStringLiteral("textEdit_compile_output"));
        textEdit_compile_output->setFont(font1);
        textEdit_compile_output->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_4->addWidget(textEdit_compile_output, 0, 0, 1, 1);

        dockWidget_compile->setWidget(dockWidgetContents_compile);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_compile);
        dockWidget_assembly = new QDockWidget(MainWindow);
        dockWidget_assembly->setObjectName(QStringLiteral("dockWidget_assembly"));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(10);
        dockWidget_assembly->setFont(font2);
        dockWidget_assembly->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_assembly = new QWidget();
        dockWidgetContents_assembly->setObjectName(QStringLiteral("dockWidgetContents_assembly"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_assembly);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit_assembly_output = new QTextEdit(dockWidgetContents_assembly);
        textEdit_assembly_output->setObjectName(QStringLiteral("textEdit_assembly_output"));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        textEdit_assembly_output->setFont(font3);
        textEdit_assembly_output->setUndoRedoEnabled(false);
        textEdit_assembly_output->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(textEdit_assembly_output, 0, 0, 1, 1);

        dockWidget_assembly->setWidget(dockWidgetContents_assembly);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_assembly);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addSeparator();
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SEU IDE", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSelect_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "Find", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("MainWindow", "Replace", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout_seu_IDE->setText(QApplication::translate("MainWindow", "About SEU IDE", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
        actionCompileOutPut->setText(QApplication::translate("MainWindow", "AssemblyOutput", Q_NULLPTR));
        actionCompile->setText(QApplication::translate("MainWindow", "Compile", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCompile->setShortcut(QApplication::translate("MainWindow", "Ctrl+F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAssemblyOutPut->setText(QApplication::translate("MainWindow", "CompileOutput", Q_NULLPTR));
        actionAssemblyNew->setText(QApplication::translate("MainWindow", "new", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAssemblyNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+F9", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAssemblyAppend->setText(QApplication::translate("MainWindow", "Append", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionAssemblyAppend->setShortcut(QApplication::translate("MainWindow", "Ctrl+F10", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        menu->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "Build", Q_NULLPTR));
        menuAssembly->setTitle(QApplication::translate("MainWindow", "Assembly", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        dockWidget_compile->setWindowTitle(QApplication::translate("MainWindow", "Compile", Q_NULLPTR));
        dockWidget_assembly->setWindowTitle(QApplication::translate("MainWindow", "Assembly", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
