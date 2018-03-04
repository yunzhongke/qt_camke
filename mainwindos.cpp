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


    /*this->mtitle_box = new QGroupBox(this);*/
    //this->mtitle_box->installEventFilter(this);
    /*this->mtitle_box->setGeometry(0 , 0 , width() , height() * 0.08);*/

    /*
     * @name 设置菜单栏、菜单
     * @{ */ 
    QMenuBar *menu_bar = new QMenuBar(this);
    QMenu *file = menu_bar->addMenu(tr("&文件"));
    QMenu *edit = menu_bar->addMenu(tr("&编辑"));
    QMenu *tool = menu_bar->addMenu(tr("&工具"));
    QMenu *win = menu_bar->addMenu(tr("&窗口"));
    menu_bar->setGeometry(0 , 25 , 0 , 0);
    /*  @} */

    /*
     * @name 设置标题图标
     * @{ */ 
    this->mTitle_icon = new QPushButton(this);
    this->mTitle_icon->setFocusPolicy(Qt::NoFocus);//不显示矩形虚线框
    this->mTitle_icon->setStyleSheet("border:none");//隐藏边框线
    this->mTitle_icon->setIcon(QIcon("../Images/pic/csdn.png"));//设置可缩放的图片
    this->mTitle_icon->setGeometry(5 , 0 , 30 , 30);
    this->mTitle_icon->setEnabled(false);//禁止点击该图标按钮
    /*  @} */
    

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
    
    move(0 , 0);
#endif
}

/*
 * @brief 鼠标按下事件 
 *
 * @param event 鼠标事件 
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        // 设置鼠标形状
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        this->mouse_pos_start = event->globalPos();
        this->frame_pos_start = this->frameGeometry().topLeft();
        this->press = true;
    }
}

/*
 * @brief 鼠标移动事件
 *
 * @param event 鼠标事件
 */
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (this->press){
        this->move(this->frame_pos_start + event->globalPos() - this->mouse_pos_start);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    QApplication::restoreOverrideCursor(); // 恢复鼠标形状 
    this->press = false;
}

/*
 * @brief 修改背景图片
 *
 * @param 绘图事件，在这里可以省略
 */
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    QPixmap backimg = QPixmap("../Images/pic/beijing.jpg").scaled( 
            QApplication::desktop()->width() , // 获取整个屏幕的宽
            QApplication::desktop()->width() , 
            Qt::KeepAspectRatio);
    painter.drawPixmap(0 , 0 , backimg);
    
}
void MainWindow::open()
{

}

MainWindow::~MainWindow()
{

}
