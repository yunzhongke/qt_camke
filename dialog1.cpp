/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：dialog1.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年02月27日20时
*   描    述：
*
================================================================*/

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QGridLayout>
#include <QtCore/QtDebug>
#include <QtWidgets/QVBoxLayout>
#include "dialog1.h"

MyDialog::MyDialog(QWidget *parent):QDialog(parent)
{
    user_image = new QLabel(this);
    user_account = new QLineEdit(this);
    passwd = new PasswdLineEdit(this);
    log_btn = new QPushButton(this);
    cal_btn = new QPushButton(this);

    QHBoxLayout *h1 = new QHBoxLayout();
    QVBoxLayout *v1 = new QVBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    QGroupBox *q = new QGroupBox();

    QPixmap pixmap = QPixmap("../Images/pic/logo.png").scaled(80 , 80 , Qt::KeepAspectRatio);
    user_image->setPixmap(pixmap);
    user_image->setGeometry(1 , 1 , 100 , 100);
    user_image->setScaledContents(true);


    user_account->setPlaceholderText(QStringLiteral("输入用户名")); 
    passwd->setPlaceholderText(QStringLiteral("输入密码"));
    //passwd->setEchoMode(QLineEdit::Password);
    log_btn->setText(QStringLiteral("登录"));
    cal_btn->setText(QStringLiteral("取消"));

    v1->addWidget(user_account , Qt::AlignHCenter);
    v1->addWidget(passwd , Qt::AlignHCenter);
    v1->setSpacing(20);
    h2->addWidget(log_btn , Qt::AlignHCenter);
    h2->addWidget(cal_btn , Qt::AlignHCenter); 
    h2->setSpacing(50);
    v1->addLayout(h2);
    q->setLayout(v1);
    h1->addWidget(user_image);
    h1->addWidget(q);
    h1->setSpacing(20);
    h1->setMargin(50);
    setLayout(h1);
}

MyDialog::~MyDialog()
{

}
