/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：passwd_line_edit.h
*   创 建 者：yunzhongke
*   创建日期：2018年02月27日21时
*   描    述：
*
================================================================*/


#ifndef _PASSWD_LINE_EDIT_H
#define _PASSWD_LINE_EDIT_H

#include <QtWidgets/QLineEdit>

class PasswdLineEdit : public QLineEdit
{
    Q_OBJECT
    public:
        explicit PasswdLineEdit(QWidget *parent = 0 , int timeout = 100);
        ~PasswdLineEdit();

    private slots:
        void display_passwd_after_edit_slot(int , int);
        void display_passwd_slot();
        void get_real_text_slot(const QString&);
    
    public:
        QString Get_Password() const;
        void Set_Timeout(int msec);
        int Get_Timeout() const;

    private:
        QString Get_Mask_String();

    private:
        int m_Timeout;
        QString line_edit_text;
        int last_char_count;
};

#endif //PASSWD_LINE_EDIT_H
