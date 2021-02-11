#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QKeySequence>
#include <QDialog>
#include <QMainWindow>
#include <QWindow>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::ClickFocus);
    installEventFilter(this);

    //press window button to show floatWindow
    m_floatWindow = new QWidget(this);
    m_floatWindow->hide();

    //setwindow flag
    m_floatWindow->setWindowFlag(Qt::WindowType::Window);
    m_floatWindow->setFocusPolicy(Qt::ClickFocus);
    m_floatWindow->installEventFilter(this);

    //auto func1 = []()->char*{qDebug()<<"clipboard A pressed";};
    //application shortcut
    QShortcut *aShortcut = new QShortcut(QKeySequence("A"),this,nullptr,nullptr,Qt::ApplicationShortcut);
    connect(aShortcut,&QShortcut::activated,this,
            [&](){
        qDebug()<<"clipboard A pressed";
    });

    //init float window shortcut and show float window
    connect(ui->pushButton,&QAbstractButton::clicked,this,[&](){

        QShortcut *aShortcut = new QShortcut(QKeySequence("A"),m_floatWindow,nullptr,nullptr,Qt::WindowShortcut);
        connect(aShortcut,&QShortcut::activated,this,
                [&](){ qDebug()<<"clipboard B pressed___WindowB";
        });

        m_floatWindow->show();
    });

    //init blackWidget shortcut
    QShortcut *WidgetShortcut = new QShortcut(QKeySequence("C"),ui->widget,nullptr,nullptr,Qt::WidgetShortcut);
    connect(WidgetShortcut,&QShortcut::activated,this,
               [&](){ qDebug()<<"clipboard C pressed___widgetC"; });
    ui->widget->setFocusPolicy(Qt::FocusPolicy::ClickFocus);

    //init pushbutton in blackwidget shortcut
    QShortcut *ButtonShortcut = new QShortcut(QKeySequence("D"),ui->pushButton_3,nullptr,nullptr,Qt::WindowShortcut);
    connect(ButtonShortcut,&QShortcut::activated,this,
            [&](){ qDebug()<<"clipboard d pressed___PushButtonChild"; });

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == m_floatWindow && e->type() == QEvent::ShortcutOverride){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if(keyEvent->key() == Qt::Key_A){
            qDebug()<<"override a pressEvent occured";
            e->accept();
            return true;
        }
    }

    if(obj == this && e->type() == QEvent::ShortcutOverride){
        //qDebug()<<"event passed this";
        //e->accept();
    }
    return __super::eventFilter(obj,e);
}

bool MainWindow::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress){
        qDebug()<<"keyPressed!";
        return true;
    }
    return __super::event(e);
}

