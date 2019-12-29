#ifndef CHILDDLG_H
#define CHILDDLG_H

#include <QString>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class childDlg : public QDialog
{
    Q_OBJECT
public:
    childDlg(QWidget *parent = 0);
    QLineEdit *editinput;
    QPushButton *okbtn;
    QVBoxLayout *layout1;
    QString str;
signals:
    void sendData(QString); //传递数据的信号
private slots:
    void OnClickOkBtn(); //子对话框的确定按钮的槽
};

#endif // CHILDDLG_H
