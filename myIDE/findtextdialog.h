#ifndef FINDTEXTDIALOG_H
#define FINDTEXTDIALOG_H

#include <QDialog>

namespace Ui {
class FindTextDialog;
}

class FindTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindTextDialog(QWidget *parent = nullptr);
    ~FindTextDialog();

private slots:

signals:


private:
    Ui::FindTextDialog *ui;
};

#endif // FINDTEXTDIALOG_H
