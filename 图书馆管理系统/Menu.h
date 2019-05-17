#pragma once
#ifndef _IMAGINE_MENU_H_
#define _IMAGINE_MENU_H_

#include "Library_Administrator.h"
#include <windows.h>
#include <conio.h>

int Login_or_Logon(void);

//登陆界面函数---输入参数 juage(0 : 管理员  1 : 读者)
string Login(int * judge);

int Admini_Menu(Administrator * &admini);

void Admini_Login(Administrator * &admini);

int Reader_Menu(Reader * &reader);

//读者登陆后的界面
void Reader_Login(Reader * &reader);

//菜单函数
int menu(void);



void Library_Management_System(void);

#endif
