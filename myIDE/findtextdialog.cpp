#include "findtextdialog.h"
#include "ui_findtextdialog.h"

FindTextDialog::FindTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindTextDialog)
{
    ui->setupUi(this);
}

FindTextDialog::~FindTextDialog()
{
    delete ui;
}

