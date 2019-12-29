#include "childdlg.h"
#include "dialog.h"

childDlg::childDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("弹窗"));
    layout1 = new QVBoxLayout(this);
    editinput = new QLineEdit();
    okbtn = new QPushButton(tr("输入"));
    editinput->setFixedHeight(80);

    layout1->addWidget(editinput);
    layout1->addWidget(okbtn);
 //这个代码在之前的链接中没有，这个表示当点击确定按钮后，触发事件，即将输入数据存入str中
    connect(okbtn, SIGNAL(clicked()), this, SLOT(OnClickOkBtn()));
}


void childDlg::OnClickOkBtn()
{
    str = editinput->text();
    emit sendData(str);
}
