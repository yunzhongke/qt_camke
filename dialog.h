/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：dialog.h
*   创 建 者：yunzhongke
*   创建日期：2018年02月17日15时
*   描    述：登录对话框
*
================================================================*/


#ifndef _DIALOG_H
#define _DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QMouseEvent>
#include <QtWidgets/QSystemTrayIcon>

class QLineEdit;
class QString;

class Dialog : public QDialog
{
    Q_OBJECT
    public:
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();

        // 鼠标双击事件
        void mousePressEvent(QMouseEvent *event);

        // 鼠标移动事件
        void mouseMoveEvent(QMouseEvent *event);

        // 鼠标释放事件
        void mouseReleaseEvent(QMouseEvent *event);

        // 键盘按下事件
        void keyPressEvent(QKeyEvent *);
        
    private:
        QLabel *mImageLable;///< 图片
        QLabel *mNoCSDN; ///< 没有CSDN
        QLabel *mVerticalBar; ///< 竖线
        QLabel *mThirdPartyLogin; ///< 第三方登录

        QPushButton *mAccountLogin; ///< 账号登录
        QPushButton *mQuickLogin; ///< 手机快捷登录
        QPushButton *mRegisterButton; ///< 注册
        QPushButton *mForgotButton; ///< 忘记密码
        QPushButton *mSina; ///< 新浪
        QPushButton *mLinked; ///< 领英
        QPushButton *mBaidu; ///< 百度
        QPushButton *mTencent; ///< 腾讯
        QPushButton *mGithub; ///< Github
        QPushButton *mWechat; ///< 微信
        QPushButton *mLoginButton; ///< 登陆
        QLineEdit *mUserLineEdit; ///< 输入账号
        QLineEdit *mPasswordLineEdit; ///< 输入密码
        QCheckBox *mAutoLoginCheckBox; ///< 自动登陆

        bool press;  ///< 鼠标是否按下
        QPoint mouse_pos_start; ///< 鼠标左键点击开始移动的初始位置
        QPoint frame_pos_start; ///< 鼠标移动前整个框架相对桌面位置
        
        QSystemTrayIcon *mSystray; ///< 系统托盘图标类

        QPushButton *mTitle_icon;///< 标题图标
        QPushButton *mclose_btn; ///< 关闭按键
        QPushButton *mmin_btn; ///< 最小化

        QGroupBox *mtitle_box; ///< 标题布局
        QLabel *mTitle_text; ///< 标题内容
};

#endif //DIALOG_H
