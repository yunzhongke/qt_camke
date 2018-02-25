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
#include "dialog.h"
#include "mainwindos.h"

int main(int argc , char *argv[])
{
    QApplication a(argc , argv);
    MainWindow w;
    Dialog lg;
    if (lg.exec() == QDialog::Accepted){
        w.show(); 
        return a.exec();
    }else
        return 0;
}
