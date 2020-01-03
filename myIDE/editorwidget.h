#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include<QWidget>
#include<Qsci/qsciscintilla.h>

class editorWidget : public QWidget{
    Q_OBJECT

private:
    QsciScintilla *editor=new QsciScintilla(this);
    QsciLexer *lexer;

public:
    explicit editorWidget(QWidget *parent = nullptr);

    // 返回当前editor指针
    QsciScintilla *geteditor(){
           return editor;
    }

    // 设置词法高亮
    QString setHl(const int type);

signals:

public slots:
};

#endif // EDITORWIDGET_H
