#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<editorwidget.h>
#include<aboutdialog.h>

#include<QMainWindow>
#include<QLineEdit>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QComboBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // event
    bool newOrOpenWithoutSavingEvent(QString mode);
    void closeEvent(QCloseEvent *event);                    // 窗口关闭事件

    void actionActive(bool act);                // 按钮激活函数

    void assembly(QString type);    // 汇编,参数为类型(New or Append)

private slots:  // 槽函数

    // menu-file
    void on_actionNew_triggered();      // 新建文件
    void on_actionOpen_triggered();     // 打开文件
    void on_actionSave_triggered();     // 保存文件
    void on_actionSave_As_triggered();  // 另存为
    void on_actionExit_triggered();     // 退出程序

    // menu-edit
    void on_actionCut_triggered();          // 剪切
    void on_actionCopy_triggered();         // 复制
    void on_actionPaste_triggered();        // 粘贴
    void on_actionSelect_All_triggered();   // 全选
    void on_actionUndo_triggered();         // undo
    void on_actionRedo_triggered();         // redo
    void on_actionFind_triggered();         // 查找
    void on_actionReplace_triggered();      // 替换

    // menu-view
    void on_actionCompileOutPut_triggered();    // 开关编译结果框
    void on_actionAssemblyOutPut_triggered();   // 开关汇编结果框

    // menu-build
    void on_actionCompile_triggered();          // 编译
    void on_actionAssemblyNew_triggered();      // 汇编-产生新文件写入内容
    void on_actionAssemblyAppend_triggered();   // 汇编-在旧文件中追加内容  TODO:估计这个不用了

    // menu-help
    void on_actionAbout_seu_IDE_triggered();

    // toolbar
    void select_lex();          // 词法选择
    void find_text_changed();   // 若查找框内容改变 清除上一波高亮
    void set_find_cs();         // 设置查找大小写敏感
    void set_find_hw();         // 设置查找全词匹配
    void show_find_str();       // 高亮查找结果
    void replace_find_str();    // 替换查找结果

private:
    Ui::MainWindow *ui;
    // 组件
    editorWidget *editor;       // 代码编辑框
    QComboBox *lexCbBox;        // 词法选择框
    QWidget *searchWidget;      // 搜索（查找+替换）组件
    QWidget *findWidget;        // 查找组件
        QLineEdit *findEdit;    // 查找输入框
        QPushButton *findBtn;   // 查找按钮
        QPushButton *csBtn;     // 大小写敏感按钮
        QPushButton *hwBtn;     // 全词匹配按钮
    QWidget *replaceWidget;     // 替换组件
        QLineEdit *replaceEdit;    // 查找输入框
        QPushButton *replaceBtn;   // 查找按钮
    QLabel *statusLabel;        // 底部状态栏显示当前打开的文件名
    AboutDialog *about;         // about对话框

    // 相关标记
    bool isOpen=false;      // 当前文件是否为通过打开得到的
    bool isNew=false;       // 当前文件是否为通过新建得到的
    bool isCs=false;        // 当前查找是否大小写敏感
    bool isHw=false;        // 当前查找是否全词匹配

    QString lastFileName;       // 最后一次保存的文件的名字
    QString selectedlanguage;   // 当前被选中的语言
};

#endif // MAINWINDOW_H
