#include"editorwidget.h"
#include<QLayout>
#include<Qsci/qsciapis.h>
#include<Qsci/qscilexercpp.h>

#include<QDebug>

editorWidget::editorWidget(QWidget *parent): QWidget(parent){
    // 设置编码方式为UTF-8
    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);

    // 行号提示
    editor->setMarginType(0,QsciScintilla::NumberMargin);   // 设置页边
    editor->setMarginLineNumbers(0,true);                   // 对该页边启用行号
    editor->setMarginWidth(0,40);                           // 页边宽度
    editor->setFont(QFont("Arial", 12));                    // 默认字体

    // 显示选中行号
    editor->setCaretLineVisible(true);
    editor->setCaretLineBackgroundColor(Qt::lightGray);

    // 界面
    QVBoxLayout *pLayout = new QVBoxLayout(this);
    pLayout->addWidget(editor);
    pLayout->setContentsMargins(0,0,0,0);

    // 设置自动补全
    editor->setAutoCompletionSource(QsciScintilla::AcsAll);     // 对所有地方都自动补全
    editor->setAutoCompletionCaseSensitivity(true);             // 大小写敏感
    editor->setAutoCompletionThreshold(2);                      // 每输入2个字符自动补全提示

    // 设置自动缩进
    editor->setAutoIndent(true);

    // 显示缩进
    editor->setIndentationGuides(true);

    // 括号匹配
    editor->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    // 显示括号不匹配
    editor->setUnmatchedBraceForegroundColor(Qt::blue);

}

QString editorWidget::setHl(const int type){
    QsciAPIs *apis;
    QString selectedLanguage;

    switch (type){
    case 0:
        lexer = nullptr;                                //0=text
//        editor->setPaper(QColor(0,0,0));
        selectedLanguage = "Text File(*.txt)";
        break;
    case 1:
        lexer=new QsciLexerCPP;                         //1=c++
//        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "Cpp(*.cpp)";
        break;
    case 2:
        lexer=new QsciLexerCPP;                         //2=MiniC
//        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "MiniC(*.cpp)";
        break;
    case 3:
        lexer = new QsciLexerCPP;                       //3=asm
//        lexer->setDefaultPaper(QColor(0,0,0));
        selectedLanguage = "ASM(*.asm)";
        break;
    default:
        lexer = nullptr;                                //defaul=text
        selectedLanguage = "Text File(*.txt)";
        break;
    }

    if(lexer!=nullptr){
        editor->setLexer(lexer);        // 设置词法分析器
        apis= new QsciAPIs(lexer);      // 提示
        apis->prepare();
    }
    else{
        editor->setLexer(0);                    // 设置词法分析器
        editor->setFont(QFont("Arial", 12));    // 默认字体
    }
    return selectedLanguage;
}

