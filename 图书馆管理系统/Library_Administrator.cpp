#include "Library_Administrator.h"

Administrator  * Admini = NULL;

Administrator::Administrator()
{
	Admini_ID = "Admini";
	Admini_PW = "Admini";

	Reader_List_Heade = Get_Readers_Index();
	Library_Heade = Get_Library_Index();
	if (Reader_List_Heade == NULL)
	{
		cerr << "Waring : Reader_List is uninitialized!!!" << endl;
	}
	if (Library_Heade == NULL)
	{
		cerr << "Waring : Library_Heade is uninitialized!!!" << endl;
	}
}

string Administrator::Get_Admini_ID()
{
	return Admini_ID;
}

string Administrator::Get_Admini_PW()
{
	return Admini_PW;
}

Reader * Administrator::Get_Reader_List_Heade(void)
{
	return Reader_List_Heade;
}

void Administrator::Add_Reader_to_Reader_List(const string R_pw, const string Reader_name, const char Reader_sex)
{
	stringstream ss;
	ss << Auto_Allot_ReaderID();

	Reader * p = new Reader(ss.str(), R_pw, Reader_name, Reader_sex);
}

void Administrator::Del_Reader_from_Reader_List(const string Reader_ID)
{
	Reader * p = Get_Readers_Index();
	Reader * tmp = NULL;
	int choose = 0;

	if (p->Next())
	{
		while (p->Next())
		{
			if (p->Next()->Get_Reader_ID() == Reader_ID)
			{
				while (choose != 1 && choose != 2)
				{
					cout << "--------是否继续注销？(1.是	2.否)" << endl;
					cin >> choose;
				}
				if (p->Next()->Get_Borrow_Array()[0].Book_Name.empty())
				{
					if (1 == choose)
					{
						tmp = p->Next();
						p->Set_Next(p->Next()->Next());
						delete tmp;
						cout << "---------恭喜您！管理员，您注销了ID为: " << Reader_ID << "的读者账户!!!" << endl;
						return;
					}
				}
				else
				{
					cout << "----------注销失败" << endl;
					cout << "----------该读者尚存借阅图书，请通知该读者归还后再进行注销操作!!!(管理员您好！请珍惜书本资源)" << endl;
				}
				
				break;
			}
			p = p->Next();
		}
	}
	cout << "---------ID为 : " << Reader_ID << "的读者不存在!!!" << endl;
}

void Administrator::Set_Reader_List_Heade(Reader * head)
{
	Reader_List_Heade = head;
}

void Administrator::Show_Current_Readers_Detail()
{
	Reader * p = Reader_List_Heade;

	Sort_Reader_List();

	while (p->Next())
	{
		cout << " ID  : " << p->Next()->Get_Reader_ID() << "   ";
		cout << "姓名 : " << p->Next()->Get_Reader_Name() << "   ";
		cout << "性别 : " << p->Next()->Get_Reader_Sex() << "   ";
		int nums = 0, i = 0;

		while (!(p->Next()->Get_Borrow_Array()[i++].Book_Name.empty()))
		{
			if (i == READER_BORROW_MAX)
			{
				break;
			}
		}
		cout << "当前已借书本数目 : " << i << "   ";
		cout << "当前可借书本数目 : " << READER_BORROW_MAX - i << endl;

		p = p->Next();
	}
}

Book * Administrator::Get_Library_Heade(void)
{
	return Library_Heade;
}

void Administrator::Add_Book_to_Library_Admini(const string name, const string press, const string author, const unsigned int num)
{
	Add_Book_to_Library(name, press, author, num);
}

void Administrator::Del_Book_from_Library_By_Name_Admini(const string name)
{
	Del_Book_from_Library_By_Name(name);
}

void Administrator::Del_Book_from_Library_By_ID_Admini(const string ID)
{
	Del_Book_from_Library_By_ID(ID);
}

Book * Administrator::Seach_in_Library_By_Name_Admini(const string name)
{
	return Seach_in_Library_By_Name(name);
}

void Administrator::Seach_in_Library_By_Name_Admini(const string name, int)
{
	Seach_in_Library_By_Name(name, 1);
}

Book * Administrator::Seach_in_Library_By_ID_Admini(const string id)
{
	return Seach_in_Library_By_ID(id);
}

void Administrator::Show_Current_Books_Detail(void)
{
	Show_Books_Detail_in_Library();
}

void Init_Admini()
{
	Admini = new Administrator();
	if (Admini == NULL)
	{
		cerr << "Error : Memory allocation error!!!" << endl;
		exit(-1);
	}
}

Administrator * Get_Admini()
{
	return Admini;
}