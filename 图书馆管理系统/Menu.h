#pragma once
#ifndef _IMAGINE_MENU_H_
#define _IMAGINE_MENU_H_

#include "Library_Administrator.h"
#include <windows.h>
#include <conio.h>

int Login_or_Logon(void);

//��½���溯��---������� juage(0 : ����Ա  1 : ����)
string Login(int * judge);

int Admini_Menu(Administrator * &admini);

void Admini_Login(Administrator * &admini);

int Reader_Menu(Reader * &reader);

//���ߵ�½��Ľ���
void Reader_Login(Reader * &reader);

//�˵�����
int menu(void);



void Library_Management_System(void);

#endif
