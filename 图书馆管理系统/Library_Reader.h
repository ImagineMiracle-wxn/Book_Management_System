#pragma once
#ifndef _IMAGINE_LIBRARY_READER_H_
#define _IMAGINE_LIBRARY_READER_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "Book.h"

using namespace std;

//������������
#define READER_BORROW_MAX 10

#define TIME_LENTH 64

struct Borrow_Detail
{
	string Book_Name;
	string ID;

	//����ʱ��
	char Borrow_Time[TIME_LENTH];
	//����ʱ��
	char Return_Time[TIME_LENTH];

	//Ƿ�����
};

class Reader
{
public:
	Reader();
	Reader(const string Id, const string Pw, const string name, const char sex);

	string Get_Reader_ID(void);
	string Get_Reader_PW(void);
	string Get_Reader_Name(void);
	char Get_Reader_Sex(void);


	struct Borrow_Detail * Get_Borrow_Array(void);

	void Set_Reader_ID(const string id);
	void Set_Reader_PW(const string pw);
	void Set_Reader_Name(const string name);
	void Set_Reader_Sex(const char sex);

	//�鿴�����Ƿ���ĸñ���--��:����true   δ��:����false
	bool Find_Book_in_Borrow_By_onwself(const string Book_Name, int * n);

	//��ӡ���ߵ�ǰ���ĵ��鱾
	void Show_Borrow_Book(void);

	//��ӡ���ߵ�ǰ���ĵ��鱾����
	void Show_Borrow_Book_Detail(void);

	//�����֤������������ƥ�亯����
	bool Authentication(const string pw);

	bool Borrow_Book(const string Book_Name);

	bool Return_the_Book(const string Book_Name);

	bool Borrow_Book(const int Book_ID);

	bool Return_the_Book(const int Book_ID);

	void Borrow_cpy_O(struct Borrow_Detail borrow[READER_BORROW_MAX]);

	void Borrow_cpy_I(struct Borrow_Detail borrow[READER_BORROW_MAX]);

	//-----------------------book---------------------
	void Show_Books_Detail_in_Library_Reader(void);

	//���������ң��ɹ������鱾��ָ�룬ʧ�ܷ���NULL
	Book * Seach_in_Library_By_Name_Reader(const string name);

	//����������ģ������
	void Seach_in_Library_By_Name_Reader(const string name, int);

	//ͬ��
	Book * Seach_in_Library_By_ID_Reader(const string id);

	Reader * Next();

	void Set_Next(Reader * reader);

private:

	string Reader_ID;
	string Reader_PW;

	string Reader_Name;

	char Reader_Sex;

	struct Borrow_Detail  Borrow[READER_BORROW_MAX];

	Reader * next;
};
 
//��ʼ����������
void Init_Reader_List(void);

Reader * Get_Readers_Index(void);

//���ն���ID��������
void Sort_Reader_List(void);

//�Զ��������ID����
int Auto_Allot_ReaderID(void);

//�û���������˺ź���
void R_Add_Reader_to_Reader_List(const string pw, const string name, const char sex);

//�û�����ע�������˺ź���
void R_Del_Reader_from_Reader_List(const string Reader_ID, const string Reader_pw);

#endif