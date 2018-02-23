/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：mainwindos.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年02月19日06时
*   描    述：qt主窗口实现初探
*
================================================================*/

#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStyleOption>
#include "mainwindos.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    
    // 设置菜单栏和菜单项背景透明色
    setStyleSheet(
            "QMenuBar:item{background-color:transparent;}"
            "QMenuBar{background-color:transparent;}"
    );

    /*this->mtitle_box = new QGroupBox(this);
    this->mtitle_box->installEventFilter(this);
    this->mtitle_box->setGeometry(0 , 0 , width() , height() * 0.08);*/

    QMenuBar *menu_bar = new QMenuBar(this);
    QMenu *file = menu_bar->addMenu(tr("&文件"));
    menu_bar->setGeometry(20 , 20 , file->width() , file->height());

#if 1
    //QMenu *file = this->menuBar()->addMenu(tr("&文件"));
    QAction *openAction = new QAction(QIcon("../Images/pic/open.png") , tr("&打开") , this );
    //QToolBar *toolbal = this->addToolBar(tr("&文件"));

    // 添加快捷键
    openAction->setShortcut(QKeySequence::Open); //打开的文档 ，see:https://pyqt4doc.appspot.com/qkeysequence.html
    openAction->setStatusTip(tr("打开一个文件"));


    // 设置信号与槽关联
    connect(openAction , &QAction::triggered , this , &MainWindow::open);

    // 设置菜单
    file->addAction(openAction);

    // 设置工具栏
    //toolbal->addAction(openAction);

    setWindowFlags(Qt::FramelessWindowHint);               //设置为无边框窗口  
    //setAttribute(Qt::WA_TranslucentBackground, true);      //设置为透明背景  

    /*setStyleSheet(*/
            //"border-width: 8px;border-image:url(../Images/pic/beijing.jpg) 8 8 8 8 "
            /*);*/
#endif
}

/*
 * @brief 修改背景图片
 *
 * @param 绘图事件，在这里可以省略
 */
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap backimg("../Images/pic/beijing.jpg");
    painter.drawPixmap(0 , 0 , QPixmap("../Images/pic/beijing.jpg"));
}
void MainWindow::open()
{

}

MainWindow::~MainWindow()
{

}
