/********************************************************************************
** Form generated from reading UI file 'findtextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDTEXTDIALOG_H
#define UI_FINDTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FindTextDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *FindTextDialog)
    {
        if (FindTextDialog->objectName().isEmpty())
            FindTextDialog->setObjectName(QStringLiteral("FindTextDialog"));
        FindTextDialog->resize(293, 183);
        gridLayout = new QGridLayout(FindTextDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(FindTextDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("YaHei Consolas Hybrid"));
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(FindTextDialog);

        QMetaObject::connectSlotsByName(FindTextDialog);
    } // setupUi

    void retranslateUi(QDialog *FindTextDialog)
    {
        FindTextDialog->setWindowTitle(QApplication::translate("FindTextDialog", "About", Q_NULLPTR));
        label->setText(QApplication::translate("FindTextDialog", "HYD", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindTextDialog: public Ui_FindTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDTEXTDIALOG_H
