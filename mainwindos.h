<<<<<<< HEAD
/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：mainwindos.h
*   创 建 者：yunzhongke
*   创建日期：2018年02月19日06时
*   描    述：qt主窗口初探
*
================================================================*/


#ifndef _MAINWINDOS_H
#define _MAINWINDOS_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGroupBox>
#include <QtGui/QPaintEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        //修改绘图事件，绘制背景图片
        void paintEvent(QPaintEvent *);
        //鼠标按下事件
        void mousePressEvent(QMouseEvent *);
        //鼠标移动事件
        void mouseMoveEvent(QMouseEvent *);
        //鼠标释放事件
        void mouseReleaseEvent(QMouseEvent *);

    private:
       QGroupBox *mtitle_box; 
       QPushButton *mTitle_icon;

       bool press;///< 鼠标是否按下
       QPoint mouse_pos_start; ///< 鼠标左键开始移动的初始位置
       QPoint frame_pos_start; ///< 鼠标移动前整个框架相对桌面位置
       
       

    public slots:
        void open();
};

#endif //MAINWINDOS_H
||||||| merged common ancestors
