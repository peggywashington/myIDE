#include "dialog.h"
#include "childDlg.h"

Dialog::Dialog(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(tr("main frame"));
    resize(300,300);
    setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::Window|Qt::WindowCloseButtonHint);

    mainlayout = new QVBoxLayout(this);
    editshow = new QLineEdit();
    editshow->setFixedHeight(80);
    btn = new QPushButton();
    btn->setText(tr("点击弹窗"));
    mainlayout->addWidget(editshow);
    mainlayout->addWidget(btn);

    connect(btn, SIGNAL(clicked()), this, SLOT(OnClickBtn()));  //点击弹窗后的事件触发
}

void Dialog::OnClickBtn()
{
    cd = new childDlg();  //创建子对话框对象
    connect(cd, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    cd->show();  //弹窗会一直show出来，当有sendData信号时，对主对话框进行receive操作
}
void Dialog::receiveData(QString data)
{
    editshow->setText(data);     //获取传递过来的数据
}
