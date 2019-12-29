#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QLineEdit>
#include<QDialog>
#include<editorwidget.h>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QComboBox>
#include<findtextdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void actionActive(bool act);//按钮激活函数

    void assembly(QString type);//汇编,参数为类型(New or Append)   TODO:为啥public

private slots:

    //File
    void on_actionNew_triggered();//创建新文件
    void on_actionOpen_triggered();//打开文件
    void on_actionSave_triggered();//保存文件
    void on_actionSave_As_triggered();//另存为
    void on_actionExit_triggered();//退出程序

    //Edit
    void on_actionCut_triggered();//剪切
    void on_actionCopy_triggered();//复制
    void on_actionPaste_triggered();//粘贴
    void on_actionSelect_All_triggered();//全选
    void on_actionUndo_triggered();//撤销
    void on_actionRedo_triggered();//重做
    void on_actionFind_triggered();//查找

    //View
    void on_actionCompileOutPut_triggered();//打开程序输出视图 FIXME:????
    void on_actionAssemblyOutPut_triggered();//打开程序错误视图 FIXME:????

    //Build
    void on_actionAssemblyNew_triggered();//汇编-产生新文件写入内容
    void on_actionAssemblyAppend_triggered();//汇编-在旧文件中追加内容

    void closeEvent(QCloseEvent *event);//窗口关闭事件响应

    void set_find_cs();     //设置查找大小写敏感
    void set_find_hw();     //设置查找全词匹配
    void show_find_str();   //高亮查找结果

    void select_lex();//词法选择

    void on_actionCompile_triggered();

    void on_actionAbout_seu_IDE_triggered();

private:
    Ui::MainWindow *ui;

    editorWidget *editor;//代码编辑框

    bool isOpen=false;//标记当前文件是否为打开的
    bool isNew=false;//标记当前文件是否为新建的
    QString lastFileName;//最后一次保存的文件的名字
    QString lastFileContent;//最后一次保存文件的内容

    QLabel *statusLabel;//状态栏显示当前打开的文件名

    bool isCs=false;//标记当前查找并非大小写敏感
    bool isHw=false;//标记当前查找并非全词匹配
    QWidget* searchWidget;//查找组件
    QLineEdit *findEdit;//查找输入框
    QPushButton *findBtn;//查找按钮
    QPushButton *csBtn;//大小写敏感按钮
    QPushButton *hwBtn;//全词匹配按钮

    QComboBox *lex;//词法选择
    QString selectedlanguage;//当前被选中的语言

    FindTextDialog *about;


};

#endif // MAINWINDOW_H
