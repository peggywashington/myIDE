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
        label->setText(QApplication::translate("FindTextDialog", "\346\254\242\350\277\216\344\275\277\347\224\250SEU_IDE\357\274\201\n"
"\346\224\257\346\214\201MiniC\347\274\226\350\257\221\345\217\212\346\261\207\347\274\226\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindTextDialog: public Ui_FindTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDTEXTDIALOG_H
