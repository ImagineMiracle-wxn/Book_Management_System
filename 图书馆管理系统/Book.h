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

	//出版社
	string Press;

	string Author;
	//数量
	unsigned int Nums;

	Book * next;
};

void Init_Book_List(void);

Book * Get_Library_Index(void);

//按照图书ID升序排序
void Sort_Book_List(void);

//自动分配图书ID函数
int Auto_Allot_BookID(void);

void Add_Book_to_Library(const string name, const string press, const string author, const unsigned int num);

void Del_Book_from_Library_By_Name(const string name);

void Del_Book_from_Library_By_ID(const string ID);

//按书名查找，成功返回书本类指针，失败返回NULL
Book * Seach_in_Library_By_Name(const string name);

//按书名进行模糊查找，成功返回书本类指针，失败返回NULL
void Seach_in_Library_By_Name(const string name, int );

//同上
Book * Seach_in_Library_By_ID(const string id);

void Show_Books_Detail_in_Library(void);

#endif
