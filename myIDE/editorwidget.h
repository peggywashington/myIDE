#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QWidget>
#include<Qsci/qsciscintilla.h>

class editorWidget : public QWidget
{
    Q_OBJECT
public:

    explicit editorWidget(QWidget *parent = nullptr);


    QsciScintilla *geteditor()//返回当前editor指针
    {
           return editor;
    }

    QString setLexer(const int type);//设置词法分析器


private:
    QsciScintilla *editor=new QsciScintilla(this);


signals:

public slots:
};

#endif // EDITORWIDGET_H
