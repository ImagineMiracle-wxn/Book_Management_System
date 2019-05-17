#include "Library_Reader.h"

Reader * Readers = NULL;

Reader::Reader()
{
	next = NULL;

	if (Readers)
	{
		Reader * p = Get_Readers_Index();
		while (p->Next())
		{
			p = p->Next();
		}

		p->Set_Next(this);
	}
}

Reader::Reader(string Id, string Pw, const string name, const char sex)
{
	this->next = NULL;
	this->Reader_ID = Id;
	this->Reader_PW = Pw;
	this->Reader_Name = name;
	this->Reader_Sex = sex;

	if (Readers)
	{
		Reader * p = Get_Readers_Index();
		while (p->Next())
		{
			p = p->Next();
		}

		p->Set_Next(this);
	}
}

string Reader::Get_Reader_ID()
{
	return Reader_ID;
}

string Reader::Get_Reader_PW()
{
	return Reader_PW;
}

string Reader::Get_Reader_Name()
{
	return Reader_Name;
}

char Reader::Get_Reader_Sex()
{
	return Reader_Sex;
}

struct Borrow_Detail * Reader::Get_Borrow_Array()
{
	return Borrow;
}

void Reader::Set_Reader_ID(const string id)
{
	Reader_ID = id;
}

void Reader::Set_Reader_PW(const string pw)
{
	Reader_PW = pw;
}

void Reader::Set_Reader_Name(const string name)
{
	Reader_Name = name;
}

void Reader::Set_Reader_Sex(const char sex)
{
	Reader_Sex = sex;
}

bool Reader::Find_Book_in_Borrow_By_onwself(const string Book_Name, int * n)
{
	for (int i = 0; i < READER_BORROW_MAX; i++)
	{
		if (!Borrow[i].Book_Name.empty())
		{
			if (Book_Name == Borrow[i].Book_Name)
			{
				*n = i;
				return true;
			}
		}
	}
	*n = -1;
	return false;
}

void Reader::Show_Borrow_Book()
{
	for (int i = 0; i < READER_BORROW_MAX; i++)
	{
		if (Borrow[i].Book_Name.empty() != true)
		{
			cout << Borrow[i].ID << "   ";
			cout << Borrow[i].Book_Name << "   ";
		}
		
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

bool Reader::Authentication(const string pw)
{
	if (pw == Get_Reader_PW())
	{
		return true;
	}
	return false;
}

bool Reader::Borrow_Book(const string Book_Name)
{
	Book * p = NULL;
	p = Seach_in_Library_By_Name_Reader(Book_Name);

	if (p)
	{
		int i = 0;
		while (!Borrow[i++].Book_Name.empty())
		{
			if (i == 10)
			{
				break;
			}
		}
		if (i == 10)
		{
			cout << "您的账户已达借书最大数，请及时阅读!!!" << endl;
			return false;
		}
		else
		{
			this->Borrow[i - 1].Book_Name = p->Get_Book_Name();
			this->Borrow[i - 1].ID = p->Get_Book_ID();

			p->Set_Book_Nums(p->Get_Book_Nums() - 1);

			time_t t = time(0);

			memcpy((void *)this->Borrow[i - 1].Borrow_Time, (void *)ctime(&t), TIME_LENTH);
			return true;
		}
	}
	return false;
}

bool Reader::Borrow_Book(const int Book_ID)
{
	Book * p = NULL;

	stringstream ss;
	ss << Book_ID;

	p = Seach_in_Library_By_ID_Reader(ss.str());

	if (p)
	{
		int i = 0;
		while (!Borrow[i++].Book_Name.empty())
		{
			if (i == 10)
			{
				break;
			}
		}
		if (i == 10)
		{
			cout << "您的账户已达借书最大数，请及时阅读!!!" << endl;
			return false;
		}
		else
		{
			this->Borrow[i - 1].Book_Name = p->Get_Book_Name();
			this->Borrow[i - 1].ID = p->Get_Book_ID();

			p->Set_Book_Nums(p->Get_Book_Nums() - 1);

			time_t t = time(0);

			memcpy((void *)this->Borrow[i - 1].Borrow_Time, (void *)ctime(&t), TIME_LENTH);
			return true;
		}
	}
	return false;
}

bool Reader::Return_the_Book(const string Book_Name)
{
	int n = 0;
	if (Find_Book_in_Borrow_By_onwself(Book_Name, &n))
	{
		for (int i = n; i < READER_BORROW_MAX - 1; i++)
		{
			Borrow[i] = Borrow[i + 1];
		}

		memset(&Borrow[READER_BORROW_MAX - 1], 0, sizeof(struct Borrow_Detail));

		int nums = this->Seach_in_Library_By_Name_Reader(Book_Name)->Get_Book_Nums();

		this->Seach_in_Library_By_Name_Reader(Book_Name)->Set_Book_Nums(nums + 1);
		return true;
	}
	return false;
}

bool Reader::Return_the_Book(const int Book_ID)
{
	int n = 0;

	stringstream ss;
	ss << Book_ID;

	if (Find_Book_in_Borrow_By_onwself(ss.str(), &n))
	{
		for (int i = n; i < READER_BORROW_MAX - 1; i++)
		{
			Borrow[i] = Borrow[i + 1];
		}

		memset(&Borrow[READER_BORROW_MAX - 1], 0, sizeof(struct Borrow_Detail));

		int nums = this->Seach_in_Library_By_Name_Reader(ss.str())->Get_Book_Nums();

		this->Seach_in_Library_By_Name_Reader(ss.str())->Set_Book_Nums(nums + 1);
		return true;
	}
	return false;
}

void Reader::Show_Borrow_Book_Detail(void)
{
	int i = 0;
	string book_name;
	while (!this->Borrow[i++].Book_Name.empty())
	{
		if (i == 10)
		{
			break;
		}

		Book * p = Seach_in_Library_By_Name(this->Borrow[i - 1].Book_Name);

		cout << " ID  : " << std::left << setw(5) << p->Get_Book_ID() << "   ";
		cout << "Name : " << std::left << setw(15) << p->Get_Book_Name() << "   ";
		cout << "Press : " << std::left << setw(15) << p->Get_Book_Press() << "   ";
		cout << "Author : " << std::left << setw(8) << p->Get_Book_Author() << "   ";
		cout << "Remanent Nums : " << std::left << setw(5) << p->Get_Book_Nums() << "   ";
		cout << "Borrow Time : " << this->Borrow[i - 1].Borrow_Time << endl;

	}
}

void Reader::Show_Books_Detail_in_Library_Reader(void)
{
	Show_Books_Detail_in_Library();
}

Book * Reader::Seach_in_Library_By_Name_Reader(const string name)
{
	return Seach_in_Library_By_Name(name);
}

void Reader::Seach_in_Library_By_Name_Reader(const string name, int)
{
	Seach_in_Library_By_Name(name, 1);
}

Book * Reader::Seach_in_Library_By_ID_Reader(const string id)
{
	return Seach_in_Library_By_ID(id);
}

Reader * Reader::Next()
{
	return next;
}

void Reader::Borrow_cpy_O(struct Borrow_Detail borrow[READER_BORROW_MAX])
{
	if (borrow)
	{
		memcpy(borrow, Borrow, READER_BORROW_MAX * sizeof(struct Borrow_Detail));
	}
	else
	{
		cerr << "Error : Can't op the NULL!!!" << endl;
	}
}

void Reader::Borrow_cpy_I(struct Borrow_Detail borrow[READER_BORROW_MAX])
{
	if (borrow)
	{
		memcpy(Borrow, borrow, READER_BORROW_MAX * sizeof(struct Borrow_Detail));
	}
	else
	{
		cerr << "Error : Can't op the NULL!!!" << endl;
	}
}

void Reader::Set_Next(Reader * reader)
{
	this->next = reader;
}

void Init_Reader_List()
{
	Readers = new Reader();
	if (Readers == NULL)
	{
		cerr << "Error : Memory allocation error!" << endl;
		exit(-1);
	}
}

Reader * Get_Readers_Index()
{
	return Readers;
}

void Sort_Reader_List(void)
{
	for (Reader * i = Get_Readers_Index(); i->Next() != NULL; i = i->Next())
	{
		for (Reader * j = i->Next(); j->Next() != NULL; j = j->Next())
		{
			if (i->Next()->Get_Reader_ID() > j->Next()->Get_Reader_ID())
			{
				string reader_id_tmp = i->Next()->Get_Reader_ID();
				string reader_pw_tmp = i->Next()->Get_Reader_PW();
				struct Borrow_Detail borrow[READER_BORROW_MAX];
				i->Next()->Borrow_cpy_O(borrow);

				i->Next()->Set_Reader_ID(j->Next()->Get_Reader_ID());
				i->Next()->Set_Reader_PW(j->Next()->Get_Reader_PW());
				i->Next()->Borrow_cpy_I(j->Next()->Get_Borrow_Array());

				j->Next()->Set_Reader_ID(reader_id_tmp);
				j->Next()->Set_Reader_PW(reader_pw_tmp);
				j->Next()->Borrow_cpy_I(borrow);
	
			}
		}
	}
}

int Auto_Allot_ReaderID()
{
	Reader * p = Get_Readers_Index();
	int Reader_ID = 0;

	Sort_Reader_List();

	if (Get_Readers_Index()->Next())
	{
		while (p->Next())
		{
			if (p->Next()->Next())
			{
				if ((atoi(p->Next()->Get_Reader_ID().c_str()) + 1) != atoi(p->Next()->Next()->Get_Reader_ID().c_str()))
				{
					Reader_ID = atoi(p->Next()->Get_Reader_ID().c_str()) + 1;
					return Reader_ID;
				}
			}
			p = p->Next();
		}

		istringstream iss(p->Get_Reader_ID());
		iss >> Reader_ID;

		Reader_ID++;
		return Reader_ID;
	}
	else
	{
		Reader_ID = 0;
		return Reader_ID;
	}
}

void R_Add_Reader_to_Reader_List(string pw, const string name, const char sex)
{
	stringstream ss;
	ss << Auto_Allot_ReaderID();

	Reader * p = new Reader(ss.str(), pw, name, sex);
}

void R_Del_Reader_from_Reader_List(const string Reader_ID, const string Reader_pw)
{
	Reader * p = Get_Readers_Index();
	Reader * tmp = NULL;
	int choose = 0;

	while (p->Next())
	{
		if (p->Next()->Get_Reader_ID() == Reader_ID)
		{
			if (p->Next()->Authentication(Reader_pw))
			{
				if (p->Next()->Get_Borrow_Array()[0].Book_Name.empty())
				{
					while (choose != 1 && choose != 2)
					{
						cout << " " << endl << endl << endl;
						cout << "-----------是否继续注销？(1.是	2.否)" << endl;
						cin >> choose;
					}
					if (1 == choose)
					{
						tmp = p->Next();
						p->Set_Next(p->Next()->Next());
						delete tmp;
					}
					cout << " " << endl << endl << endl;
					cout << "------------------注销成功!!!欢迎您的下次使用!!!" << endl;
				}
				else
				{
					cout << " " << endl << endl << endl;
					cout << "-----------注销失败!!!" << endl;
					cout << "-----------请先将您所借的书归还，再注销账号，感谢配合!!! 请按任意键继续!" << endl;
				}
				
			}
			break;
		}
		p = p->Next();
	}
}