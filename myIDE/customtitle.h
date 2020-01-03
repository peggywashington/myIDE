#ifndef CUSTOMTITLE_H
#define CUSTOMTITLE_H

#include <QWidget>

namespace Ui {
class CustomTitle;
}

class CustomTitle : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTitle(QWidget *parent = 0);
    ~CustomTitle();
signals:
    void skinSignal();
    void settingSignal();
    void closeButtonSignal();

private slots:
    void on_SkinButton_clicked();
    void on_ButtonClicked();
    void on_SettingButton_clicked();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

private:
    Ui::CustomTitle *ui;
};

#endif // CUSTOMTITLE_H
