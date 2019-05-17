#include "Book.h"

Book * Library = NULL;

Book::Book(const string name, const string id, const string press, const string author, const unsigned int num)
{

	next = NULL;

	Name = name;
	ID = id;
	Press = press;
	Author = author;
	Nums = num;

	if (Library)
	{
		Book * p = Get_Library_Index();
		while (p->Next())
		{
			p = p->Next();
		}

		p->Set_Next(this);
	}
}

Book * Book::Next()
{
	return next;
}

void Book::Set_Next(Book * const p)
{
	next = p;
}

string Book::Get_Book_Name(void)
{
	return Name;
}

string Book::Get_Book_ID(void)
{
	return ID;
}

string Book::Get_Book_Press(void)
{
	return Press;
}

string Book::Get_Book_Author(void)
{
	return Author;
}

unsigned int Book::Get_Book_Nums(void)
{
	return Nums;
}

void Book::Set_Book_Name(const string name)
{
	Name = name;
}

void Book::Set_Book_ID(const string id)
{
	ID = id;
}

void Book::Set_Book_Press(const string press)
{
	Press = press;
}

void Book::Set_Book_Author(const string author)
{
	Author = author;
}

void Book::Set_Book_Nums(const unsigned int num)
{
	Nums = num;
}

void Book::Show_Oneself_Detail(void)
{
	cout << " ID  : "  << std::left << setw(5) << ID << "   ";
	cout << "Name : "  << std::left << setw(15) << Name << "   ";
	cout << "Press : " << std::left << setw(15) << Press << "   ";
	cout << "Author : "<< std::left << setw(8) << Author << "   ";
	cout << "Nums : "  << std::left << setw(5) << Nums << endl;
}

void Init_Book_List(void)
{
	Library = new Book();
}

Book * Get_Library_Index(void)
{
	return Library;
}

void Sort_Book_List(void)
{
	for (Book * i = Get_Library_Index(); i->Next() != NULL; i = i->Next())
	{
		for (Book * j = i->Next(); j->Next() != NULL; j = j->Next())
		{
			if (i->Next()->Get_Book_ID() > j->Next()->Get_Book_ID())
			{
				string book_id_tmp = i->Next()->Get_Book_ID();
				string book_name_tmp = i->Next()->Get_Book_Name();
				string book_press_tmp = i->Next()->Get_Book_Press();
				string book_author_tmp = i->Next()->Get_Book_Author();
				unsigned int book_nums_tmp = i->Next()->Get_Book_Nums();

				i->Next()->Set_Book_ID(j->Next()->Get_Book_ID());
				i->Next()->Set_Book_Name(j->Next()->Get_Book_Name());
				i->Next()->Set_Book_Press(j->Next()->Get_Book_Press());
				i->Next()->Set_Book_Author(j->Next()->Get_Book_Author());
				i->Next()->Set_Book_Nums(j->Next()->Get_Book_Nums());

				j->Next()->Set_Book_ID(book_id_tmp);
				j->Next()->Set_Book_Name(book_name_tmp);
				j->Next()->Set_Book_Press(book_press_tmp);
				j->Next()->Set_Book_Author(book_author_tmp);
				j->Next()->Set_Book_Nums(book_nums_tmp);
			}
		}
	}
}

int Auto_Allot_BookID(void)
{
	Book * p = Get_Library_Index();
	int Book_ID = 0;

	Sort_Book_List();

	if (Get_Library_Index()->Next())
	{
		while (p->Next())
		{
			if (p->Next()->Next())
			{
				if ((atoi(p->Next()->Get_Book_ID().c_str()) + 1) != atoi(p->Next()->Next()->Get_Book_ID().c_str()))
				{
					Book_ID = atoi(p->Next()->Get_Book_ID().c_str()) + 1;
					return Book_ID;
				}
			}
			p = p->Next();
		}

		istringstream iss(p->Get_Book_ID());
		iss >> Book_ID;

		Book_ID++;
		return Book_ID;
	}
	else
	{
		Book_ID = 0;
		return Book_ID;
	}
}

void Add_Book_to_Library(const string name, const string press, const string author, const unsigned int num)
{
	stringstream id;

	id << Auto_Allot_BookID();

	Book * p = new Book(name, id.str(), press, author, num);
}

void Del_Book_from_Library_By_Name(const string name)
{
	Book * p = Get_Library_Index();

	while (p->Next())
	{
		if (p->Next()->Get_Book_Name() == name)
		{

			Book * tmp = p->Next();

			p->Set_Next(p->Next()->Next());

			delete tmp;
			break;

		}
		p = p->Next();
	}
}

void Del_Book_from_Library_By_ID(const string ID)
{
	Book * p = Get_Library_Index();

	while (p->Next())
	{
		if (p->Next()->Get_Book_ID() == ID)
		{

			Book * tmp = p->Next();

			p->Set_Next(p->Next()->Next());

			delete tmp;
			break;

		}
		p = p->Next();
	}
}

Book * Seach_in_Library_By_Name(const string name)
{
	Book * p = Get_Library_Index();

	while (p->Next())
	{
		if (p->Next()->Get_Book_Name() == name)
		{
			return p->Next();
		}
		p = p->Next();
	}
	return NULL;
}

void Seach_in_Library_By_Name(const string name, const int n)
{
	Book * p = Get_Library_Index();
	int flag = 0;
	string::size_type idx = string::npos;

	while (p->Next())
	{
		idx = p->Next()->Get_Book_Name().find(name);
		if (idx != string::npos)
		{
			flag++;
			idx = string::npos;
			p->Next()->Show_Oneself_Detail();
		}
		p = p->Next();
	}

	if (flag == 0)
	{
		cout << "未找到相关信息!!!" << endl;
	}
}

Book * Seach_in_Library_By_ID(const string id)
{
	Book * p = Get_Library_Index();

	while (p->Next())
	{
		if (p->Next()->Get_Book_ID() == id)
		{
			return p->Next();
		}
		p = p->Next();
	}
	return NULL;
}

void Show_Books_Detail_in_Library(void)
{
	Book * p = Get_Library_Index();

	Sort_Book_List();

	bool flag = true;

	while (p->Next())
	{
		flag = false;
		cout << " ID  : "  << std::left << setw(5)  << p->Next()->Get_Book_ID() << "   ";
		cout << "Name : "  << std::left << setw(15) << p->Next()->Get_Book_Name() << "   ";
		cout << "Press : " << std::left << setw(15) << p->Next()->Get_Book_Press() << "   ";
		cout << "Author : "<< std::left << setw(8)  << p->Next()->Get_Book_Author() << "   ";
		cout << "Nums : "  << std::left << setw(5)  << p->Next()->Get_Book_Nums() << endl;

		p = p->Next();
	}

	if (flag)
	{
		cout << "----------当前库存没有任何图书信息!!!" << endl;
	}

}