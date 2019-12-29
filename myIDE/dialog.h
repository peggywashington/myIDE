#ifndef DIALOG_H
#define DIALOG_H

#include "childdlg.h"
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    QLineEdit *editshow;
private:
    QPushButton *btn;
    childDlg *cd;
    QVBoxLayout *mainlayout;

private slots:
    void receiveData(QString data);   //接收传递过来的数据的槽
    void OnClickBtn();                //主窗口中的点击弹窗按钮的槽
};

#endif // DIALOG_H
