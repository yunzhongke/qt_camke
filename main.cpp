/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年02月17日22时
*   描    述：界面初探
*
================================================================*/

#include <QtWidgets/QApplication>
#include <QtWidgets/QSplashScreen>
#include <QtCore/QTimer>
#include "dialog.h"
//#include "dialog1.h"
#include "mainwindos.h"

int main(int argc , char *argv[])
{
    QApplication a(argc , argv);
    MainWindow w;
    Dialog lg;

    //设置界面风格
    // see:http://blog.csdn.net/bloong/article/details/46327701
    //QApplication::setStyle("windos");
    
    // 启动界面
    QPixmap pixmap("../Images/pic/logo.png");
    QSplashScreen splash(pixmap);
    splash.show();
    QTimer::singleShot(1500 , &splash , &QSplashScreen::hide);
    QTimer::singleShot(2000 , &lg , &Dialog::exec);

    //if (lg.exec() == QDialog::Accepted){
    if (lg.result() == QDialog::Accepted){
        w.show(); 
        return a.exec();
    }else
        return 0;
    a.exec();
    return 0;
}
