#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<aboutdialog.h>

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
#include<QShortcut>
#include<qDebug>
#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    // 设置文本编辑器为中心组件
    editor=new editorWidget(this);
    this->setCentralWidget(editor);
    isOpen=false;   // 当前文件是通过打开得到的
    isNew=false;    // 当前文件是通过新建得到的

    // IDE刚打开时设置 某些按钮 和 文本编辑框 不可用
    actionActive(false);
    editor->geteditor()->setVisible(false);
    // 查找和替换模块
    searchWidget = new QWidget(this);
    ui->toolBar->addWidget(searchWidget);
    QVBoxLayout* searchLayout = new QVBoxLayout(searchWidget);
    searchLayout->setMargin(0);
    searchLayout->setSpacing(0);
    QSpacerItem* VSpacer = new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Minimum);
    searchLayout->addItem(VSpacer);
    QSpacerItem* HSpacer = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);

    findWidget = new QWidget(searchWidget);
    QHBoxLayout* findLayout = new QHBoxLayout(findWidget);
    findLayout->addItem(HSpacer);
    findBtn = new QPushButton(tr(""),findWidget); // 查找按钮
    findBtn->setIcon(QIcon(":/img/img/find.png"));
    findBtn->setMaximumHeight(35);
    findBtn->setMaximumWidth(35);
    findBtn->setToolTip(tr("Search"));
    findBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    findEdit = new QLineEdit(findWidget);     // 查找框
    findEdit->setFont(QFont("Ariel", 11));
    findEdit->setMaximumWidth(200);
    findEdit->setMaximumHeight(35);
    findEdit->setStyleSheet("QLineEdit{""border-radius:5px}");
    csBtn = new QPushButton(tr(""),findWidget);   // 大小写敏感按钮
    csBtn->setIcon(QIcon(":/img/img/cs.png"));
    csBtn->setMaximumHeight(35);
    csBtn->setMaximumWidth(35);
    csBtn->setToolTip(tr("Match case"));
    csBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    hwBtn = new QPushButton(tr(""),findWidget);   // 全词匹配按钮
    hwBtn->setIcon(QIcon(":/img/img/hw.png"));
    hwBtn->setMaximumHeight(35);
    hwBtn->setMaximumWidth(35);
    hwBtn->setToolTip(tr("Match whole word"));
    hwBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    findEdit->setEnabled(false);
    findBtn->setEnabled(false);
    csBtn->setEnabled(false);
    hwBtn->setEnabled(false);

    replaceWidget = new QWidget(searchWidget);
    QHBoxLayout* replaceLayout = new QHBoxLayout(replaceWidget);
    replaceLayout->addItem(HSpacer);
    replaceBtn = new QPushButton(tr(""),replaceWidget); // 查找按钮
    replaceBtn->setIcon(QIcon(":/img/img/replace.png"));
    replaceBtn->setMaximumHeight(35);
    replaceBtn->setMaximumWidth(35);
    replaceBtn->setToolTip(tr("Search"));
    replaceBtn->setStyleSheet("QPushButton{""border-radius:1px}");
    replaceEdit = new QLineEdit(replaceWidget);     // 查找框
    replaceEdit->setFont(QFont("Ariel", 11));
    replaceEdit->setMaximumWidth(200);
    replaceEdit->setMaximumHeight(35);
    replaceEdit->setStyleSheet("QLineEdit{""border-radius:5px}");
    replaceEdit->setEnabled(false);
    replaceBtn->setEnabled(false);
    replaceWidget->setVisible(false);
    // 词法选择框
    lexCbBox=new QComboBox(this);
    lexCbBox->setMinimumHeight(25);
    lexCbBox->addItem(tr(" Text    "));
    lexCbBox->addItem(tr(" C++    "));
    lexCbBox->addItem(tr(" MiniC    "));
    lexCbBox->addItem(tr(" ASM    "));
    lexCbBox->setStyleSheet("QComboBox {combobox-popup: 1;font-family: Arial;margin-right:30px;border-radius:3px}"
                       "QComboBox::drop-down {border-top-right-radius: 3px;border-bottom-right-radius: 3px;}"
                       "QComboBox::down-arrow {image: url(:/img/img/pull_down.png);padding-right: 10px}");
    // 组件放进布局
    findLayout->addWidget(lexCbBox);
    findLayout->addWidget(hwBtn);
    findLayout->addWidget(csBtn);
    findLayout->addWidget(findEdit);
    findLayout->addWidget(findBtn);
    replaceLayout->addWidget(replaceEdit);
    replaceLayout->addWidget(replaceBtn);
    searchLayout->addWidget(findWidget);
    searchLayout->addWidget(replaceWidget);
    // 通信机制
    connect(findBtn,SIGNAL(clicked(bool)),this,SLOT(show_find_str()));
    connect(csBtn,SIGNAL(clicked(bool)),this,SLOT(set_find_cs()));
    connect(hwBtn,SIGNAL(clicked(bool)),this,SLOT(set_find_hw()));
    connect(findEdit,SIGNAL(textChanged(QString)),this,SLOT(find_text_changed()));  // 如果查找框内容改变触发
    connect(findEdit, SIGNAL(returnPressed()), findBtn, SIGNAL(clicked()), Qt::UniqueConnection);   //光标在查找框时查找按钮和回车等效
    connect(replaceBtn,SIGNAL(clicked(bool)),this,SLOT(replace_find_str()));
    connect(replaceEdit, SIGNAL(returnPressed()), replaceBtn, SIGNAL(clicked()), Qt::UniqueConnection);   //光标在替换框时查找按钮和回车等效
    connect(lexCbBox, SIGNAL(currentIndexChanged(int)),this,SLOT(select_lex()));
    QShortcut *annotation= new QShortcut(QKeySequence(tr("ctrl+q")), this);
    connect(annotation, SIGNAL(activated()), this,SLOT(annotate()));

    // 编译和汇编结果显示在tab形式的窗体
    this->splitDockWidget(ui->dockWidgetCompile,ui->dockWidgetAssemble,Qt::Horizontal);
    ui->dockWidgetCompile->setVisible(false);
    ui->dockWidgetAssemble->setVisible(false);

    // 底部状态栏显示当前打开文件路径
    statusLabel=new QLabel;
    ui->statusBar->addWidget(statusLabel);
}

MainWindow::~MainWindow(){
    delete ui;
}

// call message box when new or open without saving
bool MainWindow::newOrOpenWithoutSavingEvent(QString mode){
    QMessageBox msgBox;
    QPushButton *okbtn=new QPushButton(mode+" anyway");
    QPushButton *cancelbtn=new QPushButton(QObject::tr("Cancel"));
    msgBox.setWindowTitle("Warning");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText(mode+" another without saving the current file?");
    msgBox.addButton(okbtn,QMessageBox::AcceptRole);
    msgBox.addButton(cancelbtn,QMessageBox::RejectRole);
    msgBox.exec();
    if(msgBox.clickedButton() == okbtn) return true;
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

void MainWindow::on_actionNew_triggered(){

    if(editor->geteditor()->isModified())
        if(!newOrOpenWithoutSavingEvent("New")) return;

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
        if(!newOrOpenWithoutSavingEvent("Open")) return;

    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("Open file"));

    // 并未打开
    if(fileName == "")
        return;
    // 打开了文件
    else{
        // 设置文件类型对应的语法高亮
        if(fileName.endsWith(".txt")) {editor->setHl(0);lexCbBox->setCurrentIndex(0);}
        else if(fileName.endsWith(".cpp")||fileName.endsWith(".h")) {editor->setHl(1);lexCbBox->setCurrentIndex(1);}
        else if(fileName.endsWith(".asm")) {editor->setHl(3);lexCbBox->setCurrentIndex(3);}

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
                ui->textEditCompileOutput->clear();
                ui->textEditAssembleOutput->clear();

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

bool MainWindow::on_actionSave_triggered(){

    // 若为本次新建的文件
    if(isNew){
        // 文件为空不可保存
        if(editor->geteditor()->text() == ""){
            QMessageBox::warning(this,tr("Warning"),tr("Empty file!"),QMessageBox::Ok);
            return false; // 空文件未保存情况
        }
        else{
            QFileDialog fileDialog;
            QString str = fileDialog.getSaveFileName(this,tr("Save"),"/Untitled",
            tr("Text File(*.txt);;Cpp(*.cpp);;Cpp(*.h);;MiniC(*.cpp);;ASM(*.asm);;All (*.*)"),
            &selectedlanguage);

            if(str == "") return false;
            QFile file(str);
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QMessageBox::warning(this,tr("Warning"),tr("Open failed!"),QMessageBox::Ok);
                return false;
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
                return true;
            }

        }
    }
    // 若为旧文件，默认直接保存（覆盖源文件
    else{
        if(isOpen){
            QFile file(lastFileName);
            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                QMessageBox::warning(this,tr("Warning"),tr("Write failed!"));
                return false;
            }
            else{
                QTextStream textStream(&file);
                QString str = editor->geteditor()->text();
                textStream<<str;
                file.close();

                editor->geteditor()->setModified(false);    // 保存后置为未修改

                QMessageBox::information(this,"Save","Successfully saved!",QMessageBox::Ok);
                return true;
            }
        }
        else{
            QMessageBox::warning(this,tr("Warning"),tr("Please new or open a file!"));
            return false;
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
    QString fileName = fileDialog.getSaveFileName(this,tr("Save as"),statusLabel->text(),
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
    if(!ui->toolBar->isVisible()){
        ui->toolBar->setVisible(true);
        ui->actionToolBar->setChecked(true);
    }

    if(findEdit->isEnabled()){
        findEdit->clear();
        editor->geteditor()->copy();
        findEdit->paste();
        findEdit->setFocus();
    }
    else{
        findEdit->setEnabled(true);
        findBtn->setEnabled(true);
        csBtn->setEnabled(true);
        hwBtn->setEnabled(true);

        findBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
        csBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
        hwBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
        editor->geteditor()->copy();
        findEdit->paste();
        findEdit->setFocus();
    }

}

// 仅当 菜单选择替换 or ctrl+R之后
void MainWindow::on_actionReplace_triggered(){
    if(!ui->toolBar->isVisible()){
        ui->toolBar->setVisible(true);
        ui->actionToolBar->setChecked(true);
        replaceWidget->setVisible(false);       // 当工具栏隐藏时假设替换组件为关闭
    }
    on_actionFind_triggered();
    if(replaceWidget->isVisible()){
        replaceWidget->setVisible(false);
        return;
    }
    else{
        replaceWidget->setVisible(true);
        replaceEdit->setEnabled(true);
        replaceBtn->setEnabled(true);

        replaceBtn->setStyleSheet("QPushButton{""background-color:rgb(255,255,255);""border-radius:1px}");
        replaceEdit->setFocus();
    }
}

void MainWindow::on_actionCompile_triggered(){

    // 对于非miniC程序进行提醒无法编译
    if(lexCbBox->currentIndex()!=2){
        if(lexCbBox->currentIndex()==1)  // 如果是C++
            QMessageBox::warning(this,tr("Warning"),tr("Only MiniC compiler offered!\nYou can change to MiniC in the toolBar if you like."));
        else
            QMessageBox::warning(this,tr("Warning"),tr("Only MiniC compiler offered!"));
        return;
    }

    if(on_actionSave_triggered()){

        ui->dockWidgetCompile->setVisible(true);
        ui->textEditCompileOutput->setReadOnly(true);
        ui->textEditCompileOutput->clear();
        ui->textEditCompileOutput->append("Compile file:"+lastFileName);

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
        QString programName = path + "/exe/compiler.exe";
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
                ui->textEditCompileOutput->append(ReadyText);
            }
            return;
        }

        ui->textEditCompileOutput->append("Process failed to start, please check!");
        return;
    }
    else{
        QMessageBox::warning(this,tr("Warning"),tr("The file can only be compiled after being saved!"));
        return;
    }


}

void MainWindow::on_actionAssemble_triggered(){

    // 对于非miniC程序进行提醒无法编译
    if(lexCbBox->currentIndex()!=3){
        QMessageBox::warning(this,tr("Warning"),tr("The file should be asm file!"));
        return;
    }

    if(on_actionSave_triggered()){
        ui->dockWidgetAssemble->setVisible(true);
        ui->textEditAssembleOutput->setReadOnly(true);
        ui->textEditAssembleOutput->clear();
        ui->textEditAssembleOutput->append("Assemble file:"+lastFileName);

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
        arguments<<filePath;

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
                ui->textEditAssembleOutput->append(ReadyText);
            }
            return;
        }

        ui->textEditAssembleOutput->append("Process failed to start, please check!");
        return;
    }
    else{
        QMessageBox::warning(this,tr("Warning"),tr("The file can only be assembled after being saved!"));
        return;
    }
}

void MainWindow::on_actionAbout_triggered(){
    about=new AboutDialog(this);
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
    ui->actionAssemble->setEnabled(act);
    ui->actionCompileOutPut->setEnabled(act);
    ui->actionAssembleOutPut->setEnabled(act);
}

// 如果查找框内容改变就触发
void MainWindow::find_text_changed(){
    QString docText = editor->geteditor()->text();
    editor->geteditor()->SendScintilla(QsciScintilla::SCI_INDICATORCLEARRANGE, 0, docText.length());    // 清除上一波高亮
}

// 设置和取消大小写敏感
void MainWindow::set_find_cs(){
    find_text_changed();
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
    find_text_changed();
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

    QString docText = editor->geteditor()->text();
    QString findText= findEdit->text();
    if(!editor->geteditor()->findFirst(findText,0,isCs,isHw,1)){    // 1=到文档底部回转
        QMessageBox::information(this,tr("Warning"),tr("Find none!"),QMessageBox::Ok);
        find_text_changed();
        return;
    }

    // 以下标注整个文档中所有的匹配字符
//    int end;
//    if(isCs==false)
//        end = docText.lastIndexOf(findText,-1,Qt::CaseInsensitive);    // 文本中最后一个findText的位置
//    else end = docText.lastIndexOf(findText);    // 文本中最后一个findText的位置
//    int cur = -1;   // cursor从-1开始

//    // FIXME:全词匹配还不行
//    if(end != -1) {
//        while(cur != end) {
//            if(isCs==false)
//                cur = docText.indexOf(findText,cur+1,Qt::CaseInsensitive);      // cursor向下走
//            else cur = docText.indexOf(findText,cur+1);
//            editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_INDICSETSTYLE,0,QsciScintilla::INDIC_BOX);
//            editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_INDICATORFILLRANGE,cur,findText.length());     // 设置高亮
//       }
//    }
}

void MainWindow::replace_find_str(){
    QString replaceText= replaceEdit->text();
    editor->geteditor()->replace(replaceText);
}

// 选择语法
void MainWindow::select_lex(){
    int type=lexCbBox->currentIndex();
    selectedlanguage = editor->setHl(type);  // 接收当前类型
}

// 注释
void MainWindow::annotate(){
    int* linefrom = new int(0);
    int* indexfrom = new int(0);
    int* lineto = new int(0);
    int* indexto = new int(0);
    editor->geteditor()->getSelection(linefrom,indexfrom,lineto,indexto);
    if(*linefrom==-1){
        editor->geteditor()->getCursorPosition(linefrom,lineto);
        int position = editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_GETLINEINDENTPOSITION,*linefrom);
        editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_INSERTTEXT, position, "//");
    }
    else if(*linefrom==*lineto){
        int position = editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_GETLINEINDENTPOSITION,*linefrom);
        editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_INSERTTEXT, position, "//");
    }
    else{
        for(int line=*linefrom;line<=*lineto;line++){
            int position = editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_GETLINEINDENTPOSITION,line);
            editor->geteditor()->SendScintilla(QsciScintillaBase::SCI_INSERTTEXT, position, "//");
        }
    }
}
