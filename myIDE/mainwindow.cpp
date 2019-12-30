#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QTextEdit>
#include<QMdiSubWindow>
#include<QColor>
#include<QTextOption>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QtEvents>
#include<QDockWidget>
#include<QInputDialog>
#include<QPushButton>
#include<QProcess>
#include<QTextCodec>
#include<windows.h>
#include<QPushButton>
#include<QIcon>
#include<findtextdialog.h>
#include<qDebug>
#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);

    // 设置文本编辑器为中心组件
    editor=new editorWidget(this);
    this->setCentralWidget(editor);
    isOpen=false;   // 当前文件是通过打开得到的
    isNew=false;    // 当前文件是通过新建得到的

    // IDE刚打开时设置 某些按钮 和 文本编辑框 不可用
    actionActive(false);
    editor->geteditor()->setVisible(false);
    // new查找框以及相关按钮
    searchWidget = new QWidget(this);
    ui->mainToolBar->addWidget(searchWidget);
    QHBoxLayout* searchLayout = new QHBoxLayout(searchWidget);
    QSpacerItem* spacer = new QSpacerItem(40,24,QSizePolicy::Expanding,QSizePolicy::Minimum);
    searchLayout->addItem(spacer);
    findBtn = new QPushButton(tr(""),searchWidget); // 查找按钮
    findBtn->setIcon(QIcon(":/img/img/find.png"));
    findBtn->setMaximumHeight(35);
    findBtn->setMaximumWidth(35);
    findBtn->setToolTip(tr("Search"));
    findBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    findEdit = new QLineEdit(searchWidget);     // 查找框
    findEdit->setFont(QFont("Consolas", 11));
    findEdit->setMaximumWidth(200);
    findEdit->setMaximumHeight(35);
    findEdit->setStyleSheet("QLineEdit{""border-radius:5px}");
    csBtn = new QPushButton(tr(""),searchWidget);   // 大小写敏感按钮
    csBtn->setIcon(QIcon(":/img/img/cs.png"));
    csBtn->setMaximumHeight(35);
    csBtn->setMaximumWidth(35);
    csBtn->setToolTip(tr("Match case"));
    csBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    hwBtn = new QPushButton(tr(""),searchWidget);   // 全词匹配按钮
    hwBtn->setIcon(QIcon(":/img/img/hw.png"));
    hwBtn->setMaximumHeight(35);
    hwBtn->setMaximumWidth(35);
    hwBtn->setToolTip(tr("Match whole word"));
    hwBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    findEdit->setEnabled(false);
    findBtn->setEnabled(false);
    csBtn->setEnabled(false);
    hwBtn->setEnabled(false);
    // 词法选择 TODO:可以改成lexCbBox
    lex=new QComboBox(this);
    lex->setMinimumHeight(25);
    lex->addItem(tr(" Text    "));
    lex->addItem(tr(" C++    "));
    lex->addItem(tr(" MiniC    "));
    lex->addItem(tr(" ASM    "));
    lex->setStyleSheet("QComboBox {combobox-popup: 1;font-family: Arial;margin-right:30px;border-radius:3px}"
                       "QComboBox::drop-down {border-top-right-radius: 3px;border-bottom-right-radius: 3px;}"
                       "QComboBox::down-arrow {image: url(:/img/img/pull_down.png);padding-right: 10px}");
    // 组件放进布局
    searchLayout->addWidget(lex);
    searchLayout->addWidget(hwBtn);
    searchLayout->addWidget(csBtn);
    searchLayout->addWidget(findEdit);
    searchLayout->addWidget(findBtn);
    // 通信机制
    connect(findBtn,SIGNAL(clicked(bool)),this,SLOT(show_find_str()));
    connect(csBtn,SIGNAL(clicked(bool)),this,SLOT(set_find_cs()));
    connect(hwBtn,SIGNAL(clicked(bool)),this,SLOT(set_find_hw()));
    connect(findEdit, SIGNAL(returnPressed()), findBtn, SIGNAL(clicked()), Qt::UniqueConnection);   //光标在查找框时查找按钮和回车等效
    connect(lex, SIGNAL(currentIndexChanged(int)),this,SLOT(select_lex()));

    // 编译和汇编结果显示在tab形式的窗体
    this->splitDockWidget(ui->dockWidget_compile,ui->dockWidget_assembly,Qt::Horizontal);     //TODO:应该改成compileDockWidget
    ui->dockWidget_compile->setVisible(false);
    ui->dockWidget_assembly->setVisible(false);

    // 底部状态栏显示当前打开文件路径
    statusLabel=new QLabel;
    ui->statusBar->addWidget(statusLabel);
}

MainWindow::~MainWindow(){
    delete ui;
}

bool MainWindow::new_or_open_without_saving_event(QString mode){
    QMessageBox msgBox;
    QPushButton *okbtn=new QPushButton(mode+" anyway");
    QPushButton *cancelbtn=new QPushButton(QObject::tr("Cancel"));
    msgBox.setWindowTitle("Warning");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText(mode+" another without saving the current file?");
    msgBox.addButton(okbtn,QMessageBox::AcceptRole);
    msgBox.addButton(cancelbtn,QMessageBox::RejectRole);
    msgBox.exec();
    if (msgBox.clickedButton() == okbtn) return true;
    else return false;
}

// 关闭窗口事件，重写closeEvent
void MainWindow::closeEvent(QCloseEvent *event){
    // 若未修改则，则接收关闭指示
    if(!editor->geteditor()->isModified()) event->accept();
    // 否则弹出警告
    else{
        if(QMessageBox::warning(this,tr("Warning"),tr("Exit without being saved?"),QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            event->accept();
        else
            event->ignore();
    }
}

void MainWindow::on_actionNew_triggered(){        // TODO:名字改了之后就不对了。。。

    if(editor->geteditor()->isModified())
        if(!new_or_open_without_saving_event("New")) return;

    editor->geteditor()->clear();
    editor->geteditor()->setVisible(true);

    actionActive(true);

    statusLabel->setText(tr("Untitled.*"));

    isNew=true;
    isOpen=false;
    editor->geteditor()->setModified(false);
}

void MainWindow::on_actionOpen_triggered(){

    if(editor->geteditor()->isModified())
        if(!new_or_open_without_saving_event("Open")) return;

    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Open file"));

    // 并未打开
    if(fileName == "")
        return;
    // 打开了文件
    else{
        // 设置文件类型对应的语法高亮
        if(fileName.endsWith(".txt")) {editor->setLexer(0);lex->setCurrentIndex(0);}
        else if(fileName.endsWith(".cpp")||fileName.endsWith(".h")) {editor->setLexer(1);lex->setCurrentIndex(1);}
        else if(fileName.endsWith(".asm")) {editor->setLexer(3);lex->setCurrentIndex(3);}

        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this,tr("Warning"),tr("Open failed!"));
            return;
        }
        else{
            if(!file.isReadable()){
                QMessageBox::warning(this,tr("Warning"),tr("Unreadable!"));
            }
            else{
                editor->geteditor()->clear();
                editor->geteditor()->setVisible(true);
                ui->textEdit_compile_output->clear();
                ui->textEdit_assembly_output->clear();

                actionActive(true);

                // 文件显示在编辑框
                QTextStream in(&file);
                editor->geteditor()->setText(in.readAll());     // 当前文件内容将覆盖所有原内容，redo和undo初始化
                file.close();

                statusLabel->setText(fileName);

                isOpen = true;
                isNew = false;
                lastFileName = fileName;    // 记录最近一次打开的文件名
                editor->geteditor()->setModified(false);    // 置位为false 表示并未修改
            }
        }
    }
}

void MainWindow::on_actionSave_triggered(){

    // 若为本次新建的文件
    if(isNew){
        // 文件为空不可保存
        if(editor->geteditor()->text() == "")
            QMessageBox::warning(this,tr("Warning"),tr("Empty file!"),QMessageBox::Ok);
        else{
            QFileDialog fileDialog;
            QString str = fileDialog.getSaveFileName(this,tr("Save"),"/Untitled",
            tr("Text File(*.txt);;Cpp(*.cpp);;Cpp(*.h);;MiniC(*.cpp);;ASM(*.asm);;All (*.*)"),
            &selectedlanguage);

            if(str == "") return;
            QFile file(str);

            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QMessageBox::warning(this,tr("Warning"),tr("Open failed!"),QMessageBox::Ok);
                return;
            }
            else{
                QTextStream textStream(&file);
                QString text = editor->geteditor()->text();
                textStream<<text;
                file.close();

                statusLabel->setText(str);

                isNew = false;      // 重置为false
                isOpen = true;      // 重置为true
                lastFileName = str;
                editor->geteditor()->setModified(false);    // 保存后置为未修改

                QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
            }

        }
    }
    // 若为旧文件，默认直接保存（覆盖源文件
    else{
        if(isOpen){
            QFile file(lastFileName);
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QMessageBox::warning(this,tr("Warning"),tr("Write failed!"));
                return;
            }
            else{
                QTextStream textStream(&file);
                QString str = editor->geteditor()->text();
                textStream<<str;
                file.close();

                editor->geteditor()->setModified(false);    // 保存后置为未修改

                QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
            }
        }
        else{
            QMessageBox::warning(this,tr("Warning"),tr("Please new or open a file!"));
            return;
        }
    }
}

void MainWindow::on_actionSave_As_triggered(){

    // 文件为空不可另存为
    if(editor->geteditor()->text() == ""){
        QMessageBox::warning(this,tr("Warning"),tr("Empty file!"),QMessageBox::Ok);
        return;
    }

    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Save as"),"/Untitled",
                       tr("Text File(*.txt);;Cpp(*.cpp);;Cpp(*.h);;MiniC(*.cpp);;ASM(*.asm);;All (*.*)"),
                       &selectedlanguage);
    if(fileName == "")
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this,tr("Warning"),tr("Write failed!"));
        return;
    }
    else{
        QTextStream textStream(&file);
        QString str = editor->geteditor()->text();
        textStream<<str;
        file.close();

        statusLabel->setText(fileName);

        lastFileName = fileName;
        isNew = false;
        isOpen = true;
        editor->geteditor()->setModified(false);    // 保存后置为未修改

        QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
    }
}

void MainWindow::on_actionExit_triggered(){
    this->close();
}

void MainWindow::on_actionCut_triggered(){
    editor->geteditor()->cut();
}

void MainWindow::on_actionCopy_triggered(){
    editor->geteditor()->copy();
}

void MainWindow::on_actionPaste_triggered(){
    editor->geteditor()->paste();
}

void MainWindow::on_actionSelect_All_triggered(){
    editor->geteditor()->selectAll();
}

void MainWindow::on_actionUndo_triggered(){
    editor->geteditor()->undo();
}

void MainWindow::on_actionRedo_triggered(){
    editor->geteditor()->redo();
}

// 仅当 菜单选择搜索 or ctrl+F之后
void MainWindow::on_actionFind_triggered(){
    findEdit->setEnabled(true);
    findBtn->setEnabled(true);
    csBtn->setEnabled(true);
    hwBtn->setEnabled(true);

    findBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    csBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    hwBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    findEdit->setFocus();
}

void MainWindow::on_actionCompileOutPut_triggered(){
    if(ui->dockWidget_compile->isVisible())
        ui->dockWidget_compile->setVisible(false);
    else ui->dockWidget_compile->setVisible(true);
}

void MainWindow::on_actionAssemblyOutPut_triggered(){
    if(ui->dockWidget_assembly->isVisible())
        ui->dockWidget_assembly->setVisible(false);
    else ui->dockWidget_assembly->setVisible(true);
}

// TODO:1按view中的只能出来不能回去（问题不大）
void MainWindow::on_actionCompile_triggered(){

    // 对于非miniC程序进行提醒无法编译
    if(lex->currentIndex()!=2){
        if(lex->currentIndex()==1)  // 如果是C++
            QMessageBox::warning(this,tr("Warning"),tr("Only MiniC compiler offered!\nYou can change to MiniC in the toolBar if you like."));
        else
            QMessageBox::warning(this,tr("Warning"),tr("Only MiniC compiler offered!"));
        return;
    }

    on_actionSave_triggered();  // 编译前自动保存
    ui->dockWidget_compile->setVisible(true);
    ui->textEdit_compile_output->setReadOnly(true);
    ui->textEdit_compile_output->clear();
    ui->textEdit_compile_output->append("Compile file:"+lastFileName);

    QString filename=lastFileName;
    QFile file(filename);

    if (!file.open (QIODevice::ReadOnly)){
        QMessageBox::warning(this,tr("Warning"),tr("Open failed!"));
        return;
    }

    // 获取当前执行目录
    QString path;
    QDir dir;
    path = dir.currentPath();

    // 编译前清空输出文件
    QFile output(path + "/cerror.txt");
    output.remove();

    // 编译器路径
    QString programName = path + "/exe/MinicComplier.exe";
    QString filePath = file.fileName();
    QStringList arguments;
    arguments<<filePath;

    // 调用编译器
    QProcess *dProcess = new QProcess(this);
    dProcess->start(programName, arguments);    // 使用外部编译器编译本文件
    dProcess->closeWriteChannel();

    // wait
    while(true==dProcess->waitForFinished()){
        // 将执行结果显示在下方compiler文本框中
        QString outPath = path + "/cerror.txt";

        QFile file(outPath);

        if (file.open (QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray all = file.readAll();
            QTextCodec *codec = QTextCodec::codecForName("GBK");
            QString ReadyText = codec->toUnicode(all);
            ui->textEdit_compile_output->append(ReadyText);
        }
        return;
    }

    ui->textEdit_compile_output->append("Process failed to start, please check!");
    return;
}

void MainWindow::on_actionAssemblyNew_triggered(){
    assembly("new");
}

void MainWindow::on_actionAssemblyAppend_triggered(){
    assembly("append");
}

void MainWindow::assembly(QString type){

    on_actionSave_triggered();
    ui->dockWidget_assembly->setVisible(true);
    ui->textEdit_assembly_output->setReadOnly(true);
    ui->textEdit_assembly_output->clear();
    ui->textEdit_assembly_output->append("Assembly file:"+lastFileName);

    QString filename=lastFileName;
    QFile file(filename);

    if (!file.open (QIODevice::ReadOnly)){
        QMessageBox::warning(this,tr("Warning"),tr("Open failed!"));
        return;
    }

    // 获取当前执行目录
    QString path;
    QDir dir;
    path = dir.currentPath();

    // 清空
    QFile output(path + "/error.txt");
    output.remove();

    QString programName = path + "/exe/myASM.exe";
    QString filePath = file.fileName();
    QStringList arguments;
    arguments<<type<<filePath;

    QProcess *dProcess = new QProcess(this);
    dProcess->start(programName, arguments);
    dProcess->closeWriteChannel();

    while(true==dProcess->waitForFinished()){

        QString outPath = path + "/error.txt";
        QFile file(outPath);

        if (file.open (QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray all = file.readAll();
            QTextCodec *codec = QTextCodec::codecForName("GBK");
            QString ReadyText = codec->toUnicode(all);
            ui->textEdit_assembly_output->append(ReadyText);
        }
        return;
    }

    ui->textEdit_assembly_output->append("Process failed to start, please check!");
    return;
}

void MainWindow::on_actionAbout_seu_IDE_triggered(){
    about=new FindTextDialog(this);
    about->setModal(true);
    about->show();
}

// 设置按钮可用与否
void MainWindow::actionActive(bool act){

    ui->actionSave->setEnabled(act);
    ui->actionSave_As->setEnabled(act);

    ui->actionUndo->setEnabled(act);
    ui->actionRedo->setEnabled(act);
    ui->actionCopy->setEnabled(act);
    ui->actionCut->setEnabled(act);
    ui->actionPaste->setEnabled(act);
    ui->actionSelect_All->setEnabled(act);
    ui->actionFind->setEnabled(act);
    ui->actionReplace->setEnabled(act);

    ui->actionCompile->setEnabled(act);
    ui->actionAssemblyNew->setEnabled(act);     // TODO:new和append都是啥？？
    ui->actionAssemblyAppend->setEnabled(act);
    ui->actionCompileOutPut->setEnabled(act);
    ui->actionAssemblyOutPut->setEnabled(act);
}

// 设置和取消大小写敏感
void MainWindow::set_find_cs(){
    if(isCs == false){
        isCs = true;
        csBtn->setStyleSheet("QPushButton{""background-color:rgb(204,204,204);""border-radius:1px}");
    }
    else{
        isCs = false;
        csBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    }
}

// 设置和取消全词匹配
void MainWindow::set_find_hw(){
    if(isHw == false){
        isHw = true;
        hwBtn->setStyleSheet("QPushButton{""background-color:rgb(204,204,204);""border-radius:1px}");
    }
    else{
        isHw = false;
        hwBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    }
}

// 显示查找结果
void MainWindow::show_find_str(){
    QString s=findEdit->text();
    if(editor->geteditor()->findFirst(s,0,isCs,isHw,1)){
        // 找到后高亮显示
        QPalette palette = editor->geteditor()->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        editor->geteditor()->setPalette(palette);
    }
    else
        QMessageBox::information(this,tr("Warning"),tr("Find none!"),QMessageBox::Ok);
}

// 由选择语法高亮触发
void MainWindow::select_lex(){
    int type=lex->currentIndex();
    selectedlanguage = editor->setLexer(type);  // 接收当前类型
}
