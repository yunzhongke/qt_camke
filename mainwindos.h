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

    private:
       QGroupBox *mtitle_box; 

    public slots:
        void open();
};

#endif //MAINWINDOS_H
