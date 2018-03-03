/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：dialog1.h
*   创 建 者：yunzhongke
*   创建日期：2018年02月27日20时
*   描    述：
*
================================================================*/


#ifndef _DIALOG1_H
#define _DIALOG1_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "passwd_line_edit.h"

class MyDialog : public QDialog
{
    Q_OBJECT
    public:
        explicit MyDialog(QWidget *parent = 0);
        ~MyDialog();

    private:
        QLabel *user_image; ///< 图片
        QLineEdit *user_account; ///< 账号
        PasswdLineEdit *passwd;
        QPushButton *log_btn; ///< 登录
        QPushButton *cal_btn; ///< 取消
};

#endif //DIALOG1_H
