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
#include "dialog.h"
//#include "dialog1.h"
#include "mainwindos.h"

int main(int argc , char *argv[])
{
    QApplication a(argc , argv);

    //设置界面风格
    // see:http://blog.csdn.net/bloong/article/details/46327701
    //QApplication::setStyle("windos");
    
    // 启动界面
    // see http://blog.csdn.net/xuancailinggan/article/details/50599510
    QPixmap pixmap("../Images/pic/logo.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.showMessage("正在加载.." , Qt::AlignBottom , Qt::red);
    a.processEvents(); //保证程序一直可以响应鼠标键盘上的事件
    Dialog lg;
    MainWindow w;

    splash.finish(&lg); //等待比较占用资源的类初始化完后会调用close()

    if (lg.exec() == QDialog::Accepted){
        //w.show(); 
        w.showMaximized();
        return a.exec();
    }else
        return 0;
}
