/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：passwd_line_edit.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年02月27日21时
*   描    述：
*
================================================================*/

#include <QtCore/QTimer>
#include "passwd_line_edit.h"

PasswdLineEdit::PasswdLineEdit(QWidget *parent , int timeout):
    QLineEdit(parent),m_Timeout(timeout)
{
    line_edit_text = "";
    last_char_count = 0;

    connect(this , &QLineEdit::textEdited , this , &PasswdLineEdit::get_real_text_slot);
    connect(this , &QLineEdit::cursorPositionChanged , this , &PasswdLineEdit::display_passwd_after_edit_slot);
}

PasswdLineEdit::~PasswdLineEdit()
{

}

void PasswdLineEdit::display_passwd_after_edit_slot(int oldPos , int newPos)
{
    if (oldPos >= 0 && newPos >= 0){
        if (newPos > oldPos)
            //QTimer::singleShot(m_Timeout , this , &PasswdLineEdit::display_passwd_slot);
            setText(Get_Mask_String());
        else
            setCursorPosition(oldPos);
    }
}

void PasswdLineEdit::display_passwd_slot()
{
    setText(Get_Mask_String());
}

void PasswdLineEdit::get_real_text_slot(const QString& text)
{
    if (text.count() > last_char_count)
        line_edit_text.append(text.right(1));
    else if (text.count() < last_char_count){
        line_edit_text.remove(line_edit_text.count() -1 , 1);
        last_char_count = line_edit_text.count();
    }
}

void PasswdLineEdit::Set_Timeout(int msec)
{
    m_Timeout = msec;
}

int PasswdLineEdit::Get_Timeout() const
{
    return m_Timeout;
}

QString PasswdLineEdit::Get_Mask_String()
{
    QString mask = "";
    int count = this->text().length();
    if (count > 0){
        for (int i = 0; i < count - 1; ++i)
            mask += "*";
    }
    return mask + this->text().right(1);
}
