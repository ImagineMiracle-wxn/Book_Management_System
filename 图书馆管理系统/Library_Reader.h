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

//读者最大借阅数
#define READER_BORROW_MAX 10

#define TIME_LENTH 64

struct Borrow_Detail
{
	string Book_Name;
	string ID;

	//借书时间
	char Borrow_Time[TIME_LENTH];
	//还书时间
	char Return_Time[TIME_LENTH];

	//欠费情况
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

	//查看读者是否借阅该本书--借:返回true   未借:返回false
	bool Find_Book_in_Borrow_By_onwself(const string Book_Name, int * n);

	//打印读者当前借阅的书本
	void Show_Borrow_Book(void);

	//打印读者当前借阅的书本详情
	void Show_Borrow_Book_Detail(void);

	//身份验证函数（及密码匹配函数）
	bool Authentication(const string pw);

	bool Borrow_Book(const string Book_Name);

	bool Return_the_Book(const string Book_Name);

	bool Borrow_Book(const int Book_ID);

	bool Return_the_Book(const int Book_ID);

	void Borrow_cpy_O(struct Borrow_Detail borrow[READER_BORROW_MAX]);

	void Borrow_cpy_I(struct Borrow_Detail borrow[READER_BORROW_MAX]);

	//-----------------------book---------------------
	void Show_Books_Detail_in_Library_Reader(void);

	//按书名查找，成功返回书本类指针，失败返回NULL
	Book * Seach_in_Library_By_Name_Reader(const string name);

	//按书名进行模糊查找
	void Seach_in_Library_By_Name_Reader(const string name, int);

	//同上
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
 
//初始化读者链表
void Init_Reader_List(void);

Reader * Get_Readers_Index(void);

//按照读者ID升序排序
void Sort_Reader_List(void);

//自动分配读者ID函数
int Auto_Allot_ReaderID(void);

//用户申请借阅账号函数
void R_Add_Reader_to_Reader_List(const string pw, const string name, const char sex);

//用户自行注销借阅账号函数
void R_Del_Reader_from_Reader_List(const string Reader_ID, const string Reader_pw);

#endif