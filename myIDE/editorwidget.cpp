#include "editorwidget.h"
#include<QLayout>
#include<Qsci/qsciapis.h>
#include<Qsci/qscilexercpp.h>
#include<Qsci/qscilexerpython.h>
#include<Qsci/qscilexerverilog.h>
#include<Qsci/qscilexerjava.h>

#include<QDebug>

editorWidget::editorWidget(QWidget *parent): QWidget(parent)
{
    // 风格


    // 行号提示
    editor->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    editor->setMarginLineNumbers(0,true);//对该页边启用行号
    editor->setMarginWidth(0,40);//设置页边宽度
    editor->setFont(QFont("Ariel", 12));//设置默认字体显示

    // 界面
    QVBoxLayout *pLayout = new QVBoxLayout(this);
    pLayout->addWidget(editor);
    pLayout->setContentsMargins(0,0,0,0);

    // 设置编码方式
    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);//设置编码为UTF-8

    // 设置自动补全
    editor->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源，自动补全所有地方出现的
    editor->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    editor->setAutoCompletionThreshold(2);    //设置每输入2个字符就会出现自动补全的提示

    // 设置自动缩进
    editor->setAutoIndent(true);

    // 显示选中行号
    editor->setCaretLineVisible(true);
    editor->setCaretLineBackgroundColor(Qt::lightGray);


    // 显示缩进
    editor->setIndentationGuides(true);

    // 括号匹配
    editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    // 显示括号不匹配
    editor->setUnmatchedBraceForegroundColor(Qt::blue);

}

QString editorWidget::setHl(const int type)
{
    QsciAPIs *apis;
    QString selectedLanguage;

    switch (type)
    {
    case 0:
        lexer = nullptr;//0-plain text
        editor->setPaper(QColor(0,0,0));
        selectedLanguage = "Text File(*.txt)";
        break;
    case 1:
        lexer=new QsciLexerCPP;//1-c++
        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "Cpp(*.cpp)";
        break;
    case 2:
        lexer=new QsciLexerCPP;//2-MiniC
        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "MiniC(*.cpp)";
        break;
    case 3:
        lexer = new QsciLexerCPP;//3-asm
        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "ASM(*.asm)";
        break;
    default:
        lexer = nullptr;//defaul-plain text
        selectedLanguage = "Text File(*.txt)";
        break;
    }

    if(lexer!=nullptr)
    {
        editor->setLexer(lexer);//给QsciScintilla设置词法分析器
        apis= new QsciAPIs(lexer);//代码提示
        apis->prepare();
    }
    else
    {
        editor->setLexer(0);//给QsciScintilla设置词法分析器
        editor->setFont(QFont("Ariel", 12));//设置默认字体显示
    }
    return selectedLanguage;
}

