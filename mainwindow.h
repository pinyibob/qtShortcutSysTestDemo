#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject*obj,QEvent*e) override;
    bool event(QEvent *event) override;
private:
    Ui::MainWindow *ui;

    QWidget *m_floatWindow = nullptr;
};
#endif // MAINWINDOW_H
