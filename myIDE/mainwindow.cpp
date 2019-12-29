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
#include<QDebug>
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
    QSpacerItem* spacer = new QSpacerItem(50,24,QSizePolicy::Expanding,QSizePolicy::Minimum);
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
    // 词法选择 TODO:可以改成lexCbBox   TODO!!:再加个miniC的
    lex=new QComboBox(this);
    lex->addItem(tr("Text  "));     // TODO:可以删掉几个看着不像抄的
    lex->addItem(tr("C++  "));
    lex->addItem(tr("ASM  "));      // TODO:ASM真的要吗 都没对应的高亮能调
    lex->addItem(tr("Python  "));
    lex->addItem(tr("Java "));
    lex->addItem(tr("Verilog  "));
    lex->setStyleSheet("QComboBox {combobox-popup: 1;font-family: Arial;margin-right:30px}");   // TODO:太丑了 给我搞出来！！
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
//    ui->statusBar->addPermanentWidget(lex);
    connect(lex, SIGNAL(currentIndexChanged(int)),this,SLOT(select_lex()));

    // 编译和汇编结果显示在tab形式的窗体
    this->tabifyDockWidget(ui->dockWidget_compile,ui->dockWidget_assembly);     //TODO:应该改成compileDockWidget
    ui->dockWidget_compile->setVisible(false);
    ui->dockWidget_assembly->setVisible(false);

    // 底部状态栏显示当前打开文件路径
    statusLabel=new QLabel;
    ui->statusBar->addWidget(statusLabel);

    //绑定菜单中File-Open按钮 使之能判断文件是否更改之后未保存 TODO:无法使之生效 考虑是否删掉
    ui->actionOpen->installEventFilter(this);
}

MainWindow::~MainWindow(){
    delete ui;
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
    ui->actionCompileOutPut->setEnabled(act);   // TODO:这又是啥？？
    ui->actionAssemblyOutPut->setEnabled(act);
}

void MainWindow::on_actionNew_triggered(){        // TODO:名字改了之后就不对了。。。

    // TODO:没有判断上一个文件无论是通过打开得到的还是新建得到的是否被修改过 如果被修改过应当触发提示
    // TODO:实践了两个方法暂时还没成功

    editor->geteditor()->clear();
    editor->geteditor()->setVisible(true);

    actionActive(true);

    statusLabel->setText(tr("Untitled.*"));

    isNew=true;
    isOpen=false;    // FIXME:true的话含义上是不是有问题
}

void MainWindow::on_actionOpen_triggered(){
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Open file"));

    // 并未打开
    if(fileName == "")
        return;
    // 打开了文件
    else{
        // 设置文件类型对应的语法高亮    TODO:类型减少的话这里也要改一下 还有012345在editorWidget.cpp里改
        if(fileName.endsWith(".txt")) {editor->setLexer(0);lex->setCurrentIndex(0);}
        else if(fileName.endsWith(".cpp")||fileName.endsWith(".h")) {editor->setLexer(1);lex->setCurrentIndex(1);}
        else if(fileName.endsWith(".asm")) {editor->setLexer(2);lex->setCurrentIndex(2);}
        else if(fileName.endsWith(".py")) {editor->setLexer(3);lex->setCurrentIndex(3);}
        else if(fileName.endsWith(".java")) {editor->setLexer(4);lex->setCurrentIndex(4);}
        else if(fileName.endsWith(".v")) {editor->setLexer(5);lex->setCurrentIndex(5);}

        QFile file(fileName);       // TODO:如果我要设置默认路径为上次打开的路径？至少是本次程序运行中上次打开的路径
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this,tr("Warning"),tr("Open failed!"));    // look:用这个弹窗可以
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
                lastFileContent=editor->geteditor()->text();    // 记录最近一次打开的文件内容 TODO:不觉得很傻逼吗 真的要这样搞？
            }
        }
    }
}

void MainWindow::on_actionSave_triggered(){
//    actionActive(true);//需要保存文件时激活相关按钮 TODO:鸡肋叭
    // 若为本次新建的文件
    if(isNew){
        // 文件为空不可保存
        if(editor->geteditor()->text() == "")
            QMessageBox::warning(this,tr("Warning"),tr("Empty file!"),QMessageBox::Ok);
        else{
            QFileDialog fileDialog;
            QString str = fileDialog.getSaveFileName(this,tr("Save"),"/Untitled",
            tr("Text File(*.txt);;Cpp(*.cpp);;Cpp(*.h);;ASM(*.asm);;Python(*.py);;Java(*.java);;Verilog(*.v);;All (*.*)"),
            &selectedlanguage);

            if(str == "") return;
            QFile file(str);
            qDebug()<<str;
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
                lastFileContent = text;

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

                lastFileContent = str;

                QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
            }
        }
        else{
            QMessageBox::warning(this,tr("Warning"),tr("Please new or open a file!"));  // TODO:应该没有这种情况吧。。
            return;
        }
    }
}

void MainWindow::on_actionSave_As_triggered()
{
//    actionActive(true);//需要保存文件时激活相关按钮   TODO:鸡肋叭
    // 文件为空不可另存为
    if(editor->geteditor()->text() == ""){
        QMessageBox::warning(this,tr("Warning"),tr("Empty file!"),QMessageBox::Ok);
        return;
    }

    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Save as"),"/Untitled",
                       tr("Text File(*.txt);;Cpp(*.cpp);;Cpp(*.h);;ASM(*.asm);;Python(*.py);;Java(*.java);;Verilog(*.v);;All (*.*)"),
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

        lastFileContent = str;
        lastFileName = fileName;
        isNew = false;
        isOpen = true;

        QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
    }
}

void MainWindow::on_actionExit_triggered(){
    this->close();
}

// 关闭窗口事件，重写closeEvent
void MainWindow::closeEvent(QCloseEvent *event){
    // 若未修改则，则接收关闭指示
    if(editor->geteditor()->text() == lastFileContent){
        event->accept();
    }
    // 否则弹出警告
    else{
        if(QMessageBox::warning(this,tr("Warning"),tr("Not Saved,Exit?"),QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
            event->accept();
        else
            event->ignore();
    }
}


void MainWindow::on_actionCompileOutPut_triggered()
{
    ui->dockWidget_compile->setVisible(true);
}

void MainWindow::on_actionAssemblyOutPut_triggered()
{
    ui->dockWidget_assembly->setVisible(true);
}

void MainWindow::on_actionCut_triggered()
{
    editor->geteditor()->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    editor->geteditor()->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    editor->geteditor()->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    editor->geteditor()->selectAll();
}

void MainWindow::on_actionUndo_triggered()
{
    editor->geteditor()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    editor->geteditor()->redo();
}

// 仅当 菜单选择搜索 or ctrl+F之后
void MainWindow::on_actionFind_triggered()
{
    findEdit->setEnabled(true);
    findBtn->setEnabled(true);
    csBtn->setEnabled(true);
    hwBtn->setEnabled(true);

    findBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    csBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    hwBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
    findEdit->setFocus();
}

// TODO:1按view中的只能出来不能回去（问题不大）
// TODO:2按一个只能出来一个 按两个不一样的才能出现tab状（还是不要tab形式了吧
// 注意咱只能编译miniC 其他的情况应弹窗提醒
void MainWindow::on_actionCompile_triggered(){
    on_actionSave_triggered();  // 编译前自动保存
    ui->dockWidget_assembly->setVisible(false);     // TODO:其实不应该这样 这样的话让两个显示的过程中不会出现tab 和view的矛盾
    ui->dockWidget_compile->setVisible(true);
    ui->textEdit_compile_output->setReadOnly(true);
    ui->textEdit_compile_output->clear();
    ui->textEdit_compile_output->append("Compile file:"+lastFileName);

    QString filename=lastFileName;
    QFile file(filename);

    if (!file.open (QIODevice::ReadOnly)){
        QMessageBox::warning(this,tr("Warning"),tr("Open Failed!"));
        return;
    }

    // 获取当前执行目录
    QString path;
    QDir dir;
    path = dir.currentPath();

    // 编译前清空输出文件   TODO:这样可以清空界面中的下面那块么？
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
        // 将执行结果显示在下方complile文本框中
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

    ui->textEdit_compile_output->append("Process failed to start,please check!");
    return;
}

void MainWindow::on_actionAssemblyNew_triggered(){
    assembly("new");
}

void MainWindow::on_actionAssemblyAppend_triggered(){
    assembly("append");
}

void MainWindow::assembly(QString type)
{
    ui->dockWidget_compile->setVisible(false);
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

    // 清空         TODO:这样可以清空界面中的下面那块么？
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

    ui->textEdit_assembly_output->append("Process failed to start,please check!");
    return;
}

// 设置和取消大小写敏感
void MainWindow::set_find_cs()
{
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
void MainWindow::set_find_hw()
{
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
        QMessageBox::information(this,tr("Warning"),tr("Find None!"),QMessageBox::Ok);
}

// 由选择语法高亮触发
void MainWindow::select_lex(){
    int type=lex->currentIndex();
    selectedlanguage = editor->setLexer(type);  // 接收当前类型
}

void MainWindow::on_actionAbout_seu_IDE_triggered(){
    about=new FindTextDialog(this);
    about->setModal(true);
    about->show();
}
