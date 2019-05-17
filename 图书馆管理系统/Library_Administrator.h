#pragma once
#ifndef _IMAGINE_LIBRARY_ADMINISTRATOR_H_
#define _IMAGINE_LIBRARY_ADMINISTRATOR_H_

#include <iostream>
#include <string>
#include "Library_Reader.h"
#include "Book.h"

using namespace std;

class Administrator
{
public:
	Administrator();
	string Get_Admini_ID();
	string Get_Admini_PW();

	//-----------------Reader------------------------------
	Reader * Get_Reader_List_Heade(void);

	void Add_Reader_to_Reader_List(const string R_pw, const string Reader_name, const char Reader_sex);

	void Del_Reader_from_Reader_List(const string Reader_ID);

	//Ϊ�˷�ֹ���캯���Զ���ָ���ʼ��ʱ�����쳣
	void Set_Reader_List_Heade(Reader * head);

	/*��������󣬴�ӡ���ж�����Ϣ*/
	void Show_Current_Readers_Detail();


	//-------------------------Book--------------------------
	Book * Get_Library_Heade(void);

	void Add_Book_to_Library_Admini(const string name, const string press, const string author, const unsigned int num);
	
	void Del_Book_from_Library_By_Name_Admini(const string name);

	void Del_Book_from_Library_By_ID_Admini(const string ID);

	//���������ң��ɹ������鱾��ָ�룬ʧ�ܷ���NULL
	Book * Seach_in_Library_By_Name_Admini(const string name);

	//����������ģ�����ң��ɹ������鱾��ָ�룬ʧ�ܷ���NULL
	void Seach_in_Library_By_Name_Admini(const string name, int);

	//ͬ��
	Book * Seach_in_Library_By_ID_Admini(const string id);

	/*��������󣬴�ӡ����ͼ����Ϣ*/
	void Show_Current_Books_Detail();

private:
	string Admini_ID;
	string Admini_PW;
	
	Book * Library_Heade;
	Reader * Reader_List_Heade;
};

void Init_Admini();

Administrator * Get_Admini();

#endif
