/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：dialog.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年02月17日15时
*   描    述：对话框界面实现
*
================================================================*/

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QAction>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenu>
#include <QtCore/QtDebug>
#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    


    //this->setStyleSheet("background-color:red;");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint ); // 设置无边框且该窗口位于其它窗口之上
    //this->setAttribute(Qt::WA_TranslucentBackground);// 小部件具有半透明的背景
    this->setMouseTracking(true); //打开鼠标跟踪事件
    
    mImageLable = new QLabel(this);
    mNoCSDN = new QLabel(this);
    mVerticalBar = new QLabel(this);
    mThirdPartyLogin = new QLabel(this);
    mAccountLogin = new QPushButton(this);
    mQuickLogin = new QPushButton(this);
    mRegisterButton = new QPushButton(this);
    mForgotButton = new QPushButton(this);
    mSina = new QPushButton(this);
    mLinked = new QPushButton(this);
    mBaidu = new QPushButton(this);
    mTencent = new QPushButton(this);
    mGithub = new QPushButton(this);
    mWechat = new QPushButton(this);
    mLoginButton = new QPushButton(this);
    mUserLineEdit = new QLineEdit(this);
    mPasswordLineEdit = new QLineEdit(this);
    mAutoLoginCheckBox = new QCheckBox(this);
    mSystray = new QSystemTrayIcon(this);
    mtitle_box = new QGroupBox(this);
    mclose_btn = new QPushButton(this);
    mmin_btn = new QPushButton(this);
    mTitle_icon = new QPushButton(this);
    mTitle_text = new QLabel(this);

    /*
     * @name 将所有按钮设置不显示矩形虚线框
     * @see http://blog.csdn.net/GoForwardToStep/article/details/53420529
     * @{ */ 
    mAccountLogin->setFocusPolicy(Qt::NoFocus);
    mQuickLogin->setFocusPolicy(Qt::NoFocus);
    mRegisterButton->setFocusPolicy(Qt::NoFocus);
    mForgotButton->setFocusPolicy(Qt::NoFocus);
    mSina->setFocusPolicy(Qt::NoFocus);
    mLinked->setFocusPolicy(Qt::NoFocus);
    mBaidu->setFocusPolicy(Qt::NoFocus);
    mTencent->setFocusPolicy(Qt::NoFocus);
    mGithub->setFocusPolicy(Qt::NoFocus);
    mWechat->setFocusPolicy(Qt::NoFocus);
    mLoginButton->setFocusPolicy(Qt::NoFocus);
    mclose_btn->setFocusPolicy(Qt::NoFocus);
    mmin_btn->setFocusPolicy(Qt::NoFocus);
    mTitle_icon->setFocusPolicy(Qt::NoFocus);
    /*  @} */

    // 设置头像 **图片路径要绝对路径**
    QPixmap pixmap("/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/logo.png");
    mImageLable->setPixmap(pixmap);
    mImageLable->setGeometry(1 , 1 , 400 , 400);
    mImageLable->setScaledContents(true);
    /*QAction *mImageAction = new QAction(this);*/
    /*mImageAction->setIcon(QIcon(pixmap));*/

    //设置文本
    mUserLineEdit->setPlaceholderText(QStringLiteral("输入用户名/邮箱手机号"));
    mPasswordLineEdit->setPlaceholderText(QStringLiteral("输入密码"));
    mPasswordLineEdit->setEchoMode(QLineEdit::Password);
    mAutoLoginCheckBox->setText(QStringLiteral("下次自动登录"));
    mLoginButton->setText(QStringLiteral("登录"));
    mRegisterButton->setText(QStringLiteral("立即注册"));
    mForgotButton->setText(QStringLiteral("忘记密码"));
    mAccountLogin->setText(QStringLiteral("账号登录"));
    mQuickLogin->setText("手机快捷登录");
    mNoCSDN->setText(QStringLiteral("没有CSDN帐号?"));
    mVerticalBar->setText(QStringLiteral("|"));
    mTitle_text->setText(QStringLiteral("CSDN"));

    //隐藏边框线
    mAccountLogin->setStyleSheet("border:none");
    mQuickLogin->setStyleSheet("border:none");
    mForgotButton->setStyleSheet("border:none");
    mRegisterButton->setStyleSheet("border:none");
    mclose_btn->setStyleSheet("border:none");
    mmin_btn->setStyleSheet("border:none");
    mTitle_icon->setStyleSheet("border:none");

    //mUserLineEdit->setFixedSize(250 , 35);
    mLoginButton->setStyleSheet("QPushButton{color: white; font: 15pt 微软雅黑 bold; background-color:orange;}");
    mSina->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/sina.png) 35px 0px no-repeat;}");
    mLinked->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/linked.png) 35px 0px no-repeat;}");
    mBaidu->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/baidu.png) 35px 0px no-repeat;}");
    mTencent->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/tengcent.png) 35px 0px no-repeat;}");
    mGithub->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/github.png) 35px 0px no-repeat;}");
    mWechat->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/wechat.png) 35px 0px no-repeat;}");
    //mTitle_icon->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/csdn.png);}");
    mTitle_icon->setIcon(QIcon("../Images/pic/csdn.png"));// 在pushbutton上设置可缩放的图片

    mSina->setFixedSize(35 , 35);
    mLinked->setFixedSize(35 , 35);
    mBaidu->setFixedSize(35 , 35);
    mTencent->setFixedSize(35 , 35);
    mGithub->setFixedSize(35 , 35);
    mWechat->setFixedSize(35 , 35);
    //mTitle_icon->setFixedSize(35 , 35);

    //布局
    QGroupBox *mgroupBox1 = new QGroupBox(this);
    QGroupBox *mgroupBox2 = new QGroupBox(this);

    QHBoxLayout *mHLayout1 = new QHBoxLayout();
    QHBoxLayout *mHLayout2 = new QHBoxLayout();
    QHBoxLayout *mHLayout3 = new QHBoxLayout();
    QHBoxLayout *mHLayout4 = new QHBoxLayout();
    QHBoxLayout *mHLayout5 = new QHBoxLayout();

    QVBoxLayout *mVLayout1 = new QVBoxLayout();
    QVBoxLayout *mVLayout2 = new QVBoxLayout();
    QVBoxLayout *mVLayout3 = new QVBoxLayout();

    mHLayout1->addWidget(mAccountLogin , Qt::AlignRight);
    mHLayout1->addWidget(mVerticalBar);
    mHLayout1->setSpacing(1);
    mHLayout1->addWidget(mQuickLogin , Qt::AlignRight);
    mHLayout2->addWidget(mAutoLoginCheckBox , Qt::AlignHCenter);
    mHLayout2->addWidget(mForgotButton , Qt::AlignHCenter);

    mVLayout1->addLayout(mHLayout1);
    mVLayout1->addWidget(mUserLineEdit , Qt::AlignHCenter);
    mVLayout1->addWidget(mPasswordLineEdit , Qt::AlignHCenter);
    mVLayout1->addLayout(mHLayout2);
    mVLayout1->setSpacing(20);
    mVLayout1->addWidget(mLoginButton , Qt::AlignHCenter);
    //mVLayout1->addStretch();
    mgroupBox1->setLayout(mVLayout1);

    mHLayout3->addWidget(mSina);
    mHLayout3->addWidget(mLinked);
    mHLayout3->addWidget(mBaidu);
    mHLayout3->addWidget(mTencent);
    mHLayout3->addWidget(mGithub);
    mHLayout3->addWidget(mWechat);
    mHLayout4->addWidget(mNoCSDN);
    mHLayout4->addWidget(mRegisterButton);
    mVLayout2->addWidget(mThirdPartyLogin);
    mVLayout2->addLayout(mHLayout3);
    mVLayout2->addLayout(mHLayout4);
    mVLayout2->setSpacing(20);
    mgroupBox2->setLayout(mVLayout2);

    mVLayout3->addWidget(mgroupBox1);
    mVLayout3->addWidget(mgroupBox2);

    //mHLayout5->addStretch(10); ///< 加入弹簧，根据填写的参数按比例分配多余的空间
    mHLayout5->addWidget(mImageLable);
    mHLayout5->setSpacing(20); ///< 表示各个控件之间的上下间距
    mHLayout5->addLayout(mVLayout3);
    //mHLayout5->addStretch(10);
    mHLayout5->setMargin(50); ///< 表示控件与窗体的左右边距
    this->setLayout(mHLayout5);

    this->press = false;

    //固定对话框的大小
    this->setFixedSize(900 , 600);

    // 设置运行时程序的ICON
    QPixmap wicon("/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/csdn.png");
    this->setWindowIcon(wicon);

    //设置窗口标题
    this->setWindowTitle(QStringLiteral("CSDN"));

    //设置系统托盘图标
    this->mSystray->setIcon(QIcon("/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/csdn.png"));
    //光标移动到托盘程序图标上是显示文字
    this->mSystray->setToolTip(QStringLiteral("CSDN"));

    /*
     * @name 创建菜单对象，加入action
     * @{ */ 
    QMenu *menu = new QMenu();
    menu->addAction(QStringLiteral("&open"));
    menu->addAction(QStringLiteral("&setting"));
    menu->addAction(QStringLiteral("&exit"));
    /*  @} */

    // 为系统托盘图标设置右键菜单
    this->mSystray->setContextMenu(menu);
     
    //显示系统托盘图标
    mSystray->show();

    /*
     * @name 设置标题栏
     * @{ */ 
    this->mtitle_box->installEventFilter(this);
    this->mtitle_box->setGeometry(0 , 0 , width() , height() * 0.08);
    mclose_btn->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/close.png);}");
    mmin_btn->setStyleSheet("QPushButton{ background:url(/home/yunzhongke/project/test/qt_cmake_test/login_intrface/Images/pic/min.png);}");
    this->mclose_btn->setGeometry(width() - mtitle_box->height() , 0 , 
            mtitle_box->height() , mtitle_box->height());
    this->mmin_btn->setGeometry(mclose_btn->x() - mclose_btn->width() - 1 , 
            0 , mclose_btn->width() , mclose_btn->height());
    this->mTitle_icon->setGeometry(0 , 0 , mclose_btn->width() , mclose_btn->height());
    this->mTitle_text->setGeometry(width() / 2 - 5 , 0 , mTitle_text->width() , mTitle_text->height());

    // 设置标签字号
    QFont ft;
    ft.setPointSize(16);
    this->mTitle_text->setFont(ft);

    // 设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText , Qt::red);
    this->mTitle_text->setPalette(pa);
    /*  @} */

    // 禁止点击该图标按钮
    this->mTitle_icon->setEnabled(false);

    // 信号与槽关联 reject()槽--》退出应用程序
    connect(mclose_btn , &QPushButton::clicked , this , &Dialog::reject);
}

Dialog::~Dialog()
{

}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        // 设置鼠标形状
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        this->mouse_pos_start = event->globalPos();
        this->frame_pos_start = this->frameGeometry().topLeft(); // 获取整个框架左上角的位置
        this->press = true;
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if (this->press){
        this->move(this->frame_pos_start + event->globalPos() - this->mouse_pos_start);
    }
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor(); ///< 恢复鼠标形状 
    this->press = false;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    // Esc键
    if (event->key() == Qt::Key_Escape)
        this->reject(); //该槽函数会返回QDialog::Rejected值，则主窗口关闭
    // 回车键
    else if (event->key() == Qt::Key_Return){
        //先获取文本框的账号和密码
        this->accept(); //该槽函数会返回QDialog::Accept值，则可以继续往下操作
    }
}

