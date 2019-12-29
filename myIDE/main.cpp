#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <iostream>
#include <QDebug>
using namespace std;
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    //qDebug()<<"wtf"<<endl;
    return a.exec();
}
