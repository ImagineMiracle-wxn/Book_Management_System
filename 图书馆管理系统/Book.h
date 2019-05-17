#pragma once
#ifndef _IMAGINE_BOOK_H_
#define _IMAGINE_BOOK_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class Book
{
public:
	Book() { next = NULL;  }
	Book(const string name, const string id, const string press, const string author, const unsigned int num);


	string Get_Book_Name(void);
	string Get_Book_ID(void);
	string Get_Book_Press(void);
	string Get_Book_Author(void);
	unsigned int Get_Book_Nums(void);

	void Set_Book_Name(const string name);
	void Set_Book_ID(const string id);
	void Set_Book_Press(const string press);
	void Set_Book_Author(const string author);
	void Set_Book_Nums(const unsigned int num);

	void Show_Oneself_Detail(void);

	Book * Next(void);
	void Set_Next(Book * const p);

private:
	string Name;
	string ID;

	//������
	string Press;

	string Author;
	//����
	unsigned int Nums;

	Book * next;
};

void Init_Book_List(void);

Book * Get_Library_Index(void);

//����ͼ��ID��������
void Sort_Book_List(void);

//�Զ�����ͼ��ID����
int Auto_Allot_BookID(void);

void Add_Book_to_Library(const string name, const string press, const string author, const unsigned int num);

void Del_Book_from_Library_By_Name(const string name);

void Del_Book_from_Library_By_ID(const string ID);

//���������ң��ɹ������鱾��ָ�룬ʧ�ܷ���NULL
Book * Seach_in_Library_By_Name(const string name);

//����������ģ�����ң��ɹ������鱾��ָ�룬ʧ�ܷ���NULL
void Seach_in_Library_By_Name(const string name, int );

//ͬ��
Book * Seach_in_Library_By_ID(const string id);

void Show_Books_Detail_in_Library(void);

#endif
