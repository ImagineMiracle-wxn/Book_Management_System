#include "Menu.h"

Administrator * ADMINI = NULL;
Reader * USER = NULL;

int Login_or_Logon(void)
{
	int choose = 0;
	while (choose != 1 && choose != 2 && choose != 3)
	{
		cout << "--------------------图书馆管理系统--------------------" << endl;
		cout << " " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "温馨提示: " << endl;
		cout << "———————————————————————————" << endl;
		cout << "|--------------管理员请使用默认账号登陆--------------|" << endl;
		cout << "|-----如果您是一次使用本系统的用户，请先注册账号-----|" << endl;
		cout << "———————————————————————————" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "------------------1.已有账号直接登陆  " << endl;
		cout << "------------------2.注册账号(只可注册读者账号)        " << endl;
		cout << "------------------3.退出系统" << endl;


		cout << " " << endl << endl;
		cout << "     请选择 : ";
		cin >> choose;
		if (choose != 1 && choose != 2 && choose != 3)
		{
			cout << "            请输入正确的选项!!!(1 or 2 or 3)            " << endl;
			_getch();
		}
		system("cls");
	}
	return choose;
}

string Login(int * judge)
{
	string account, passwd, str_choose;
	bool flag = true;
	int choose = 0;

	while (choose != 1 && choose != 2)
	{
		system("cls");
		cout << std::right << setw(60) << "Current user  : " << "Not Login" << endl;
		cout << std::right << setw(60) << "System Admini : " << Get_Admini()->Get_Admini_ID() << endl;
		cout << std::right << setw(1) << "Account  : " << "Please input your account!" << endl;
		cout << std::right << setw(1) << "Password : " << "Please input your password!" << endl;

		cout << endl << endl << endl << std::right << setw(40) << " 1.Input  2.Quit (Choose one) :";
		cin >> str_choose;

		istringstream is(str_choose);

		is >> choose;

		if (choose != 1 && choose != 2)
		{
			cout << "------------请输入正确的选项!!!  请按任意键继续!!!" << endl;
			_getch();
		}

	}

	if (choose == 2)
	{
		*judge = -1;
		return "quit";
	}

	while (flag)
	{

		system("cls");

		cout << std::right << setw(60) << "Current user  : " << "Not Login" << endl;
		cout << std::right << setw(60) << "System Admini : " << Get_Admini()->Get_Admini_ID() << endl;
		cout << std::right << setw(1) << "Account  : " << "Please input your account!" << endl;
		cout << std::right << setw(1) << "Password : " << "Please input your password!" << endl;

		cout << endl << endl << endl << std::right << setw(40) << "Input : ";
		cin >> account;

		system("cls");

		cout << std::right << setw(60) << "Current user  : " << "Not Login" << endl;
		cout << std::right << setw(60) << "System Admini : " << Get_Admini()->Get_Admini_ID() << endl;
		cout << std::right << setw(1) << "Account  : " << account << endl;
		cout << std::right << setw(1) << "Password : " << "Please input your password!" << endl;

		cout << endl << endl << endl << std::right << setw(40) << "Input : ";
		cin >> passwd;

		system("cls");

		cout << std::right << setw(60) << "Current user  : " << "Not Login" << endl;
		cout << std::right << setw(60) << "System Admini : " << Get_Admini()->Get_Admini_ID() << endl;
		cout << std::right << setw(30) << "Account  : " << account << endl;
		cout << std::right << setw(30) << "Password : ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		for (int i = 0; i < (int)passwd.length(); i++)
		{
			cout << "*";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << endl;


		cout << endl << std::right << setw(37) << "请按任意键确认……" << endl;
		_getch();
		if (account == Get_Admini()->Get_Admini_ID())
		{
			if (passwd == Get_Admini()->Get_Admini_PW())
			{
				flag = false;
				system("cls");
				cout << ' ' << endl << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << std::right << setw(32) << "      Landed successfully!Welcome to the system my Administrator!!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << endl << std::right << setw(37) << "请按任意键确认……" << endl;
				_getch();
				*judge = 0;
				ADMINI = Get_Admini();
				return Get_Admini()->Get_Admini_ID();
			}
		}

		Reader *p = Get_Readers_Index();
		while (p->Next())
		{
			if (account == p->Next()->Get_Reader_ID())
			{
				if (p->Next()->Authentication(passwd))
				{
					flag = false;
					system("cls");
					cout << ' ' << endl << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					cout << std::right << setw(32) << "      Landed successfully!Welcome to the system user ID:" << account << "!!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << std::right << setw(37) << "请按任意键确认……" << endl;
					_getch();
					*judge = 1;
					USER = p->Next();
					return p->Next()->Get_Reader_ID();
				}
			}
			p = p->Next();
		}
		if (flag)
		{
			system("cls");
			cout << ' ' << endl << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			cout << std::right << setw(35) << "login failed!!!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << endl << std::right << setw(37) << "请按任意键确认……" << endl;
			_getch();
		}
		system("cls");
	}
	return account;
}

int Admini_Menu(Administrator * &admini)
{
	int choose = 13;

	while (choose > 11 || choose < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << std::right << setw(96) << "Current user  ID   : " << admini->Get_Admini_ID() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "--------------------------------图书馆管理系统-----------------------------";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
		cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

		cout << "-----------1.按书名查找图书信息----------2.按编号查找书的信息--------------" << endl;
		cout << "-----------3.按书名模糊查找图书----------4.查看所有读者信息----------------" << endl;
		cout << "-----------5.添加读者账户----------------6.根据读者ID注销读者账户----------" << endl;
		cout << "-----------7.录入书本信息----------------8.修改图书信息--------------------" << endl;
		cout << "-----------9.根据书本ID删除图书---------10.打印图书馆所有图书--------------" << endl;
		cout << "--------------------------0.退出当前系统-----------------------------------" << endl;

		cout << " " << endl;
		cout << "-----------请输入您的选择 : ";
		cin >> choose;

		if (choose > 11 || choose < 0)
		{
			cout << "--------------请输入正确的选项，请按任意键继续!!!" << endl;
			_getch();
			system("cls");
		}
	}

	return choose;
}

void Admini_Login(Administrator * &admini)
{
	int choose = -1;

	while (choose != 0)
	{
		choose = Admini_Menu(admini);

		switch (choose)
		{
		case 1:
		{
			string book_name;
			cout << "请输入要查找的书名（完整名字） : ";
			cin >> book_name;
			if (admini->Seach_in_Library_By_Name_Admini(book_name))
			{
				(admini->Seach_in_Library_By_Name_Admini(book_name))->Show_Oneself_Detail();
			}
			else
			{
				cout << "未找到相关信息!!!" << endl;
			}

			break;
		}
		case 2:
		{
			string book_id;
			cout << "请输入要查找书的编号 : ";
			cin >> book_id;
			if (admini->Seach_in_Library_By_ID_Admini(book_id))
			{
				(admini->Seach_in_Library_By_ID_Admini(book_id))->Show_Oneself_Detail();
			}
			else
			{
				cout << "未找到相关信息!!!" << endl;
			}

			break;
		}
		case 3:
		{
			string book_name;
			cout << "请输入您想要查找的大概书名 : ";
			cin >> book_name;
			admini->Seach_in_Library_By_Name_Admini(book_name, 1);
			break;
		}
		case 4:
		{
			admini->Show_Current_Readers_Detail();
			break;
		}
		case 5:
		{
			string pw, name;
			char sex = 0;
			cout << endl << "-------读者账号注册:" << endl << endl;
			cout << "-------自动为您分配的账号为 : " << Auto_Allot_ReaderID() << endl;
			cout << "-------请输入您想要的密码   : ";
			cin >> pw;
			cout << "-------请输入您的姓名       : ";
			cin >> name;

			while (sex != 'F' && sex != 'M')
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << std::right << setw(96) << "Current user  ID   : " << admini->Get_Admini_ID() << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "--------------------------------图书馆管理系统-----------------------------";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
				cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

				cout << endl << "-------读者账号注册:" << endl << endl;
				cout << "-------自动为您分配的账号为 : " << Auto_Allot_ReaderID() << endl;
				cout << "-------请输入您想要的密码   : " << pw << endl;
				cout << "-------请输入您的姓名       : " << name << endl;
				cout << "-------请选择您的性别 F(男)  M(女)  : ";
				cin >> sex;
				if (sex != 'F' && sex != 'M')
				{
					cout << "-------请输入正确的选项(F or M)，请按任意键重新选择!!!" << endl;
					_getch();
				}
			}

			admini->Add_Reader_to_Reader_List(pw, name, sex);
			cout << "--------恭喜您！Administrator成功注册了一个读者账户!!!-----" << endl << endl;
			cout << "-------------------请按任意键继续!!!-------------------" << endl;
			_getch();
			system("cls");
			break;
		}
		case 6:
		{

			string reader_id;
			cout << "---------请输入您想要注销的读者ID : ";
			cin >> reader_id;

			admini->Del_Reader_from_Reader_List(reader_id);

			break;
		}
		case 7:
		{
			string book_name, book_press, book_author;
			int book_nums = 0, choose = 0;

			cout << " " << endl;

			cout << "---------请输入您要录入的书名 : ";
			cin >> book_name;
			cout << "---------请输入该书的出版社   : ";
			cin >> book_press;
			cout << "---------请输入该书的作者     : ";
			cin >> book_author;
			cout << "---------请输入该书的入库的数量: ";
			cin >> book_nums;

			while (choose != 1 && choose != 2)
			{
				system("cls");

				cout << "--------------------------------图书馆管理系统-----------------------------";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
				cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

				cout << "-----------1.按书名查找图书信息----------2.按编号查找书的信息--------------" << endl;
				cout << "-----------3.按书名模糊查找图书----------4.查看所有读者信息----------------" << endl;
				cout << "-----------5.添加读者账户----------------6.根据读者ID注销读者账户----------" << endl;
				cout << "-----------7.录入书本信息----------------8.修改图书信息--------------------" << endl;
				cout << "-----------9.根据书本ID删除图书---------11.打印图书馆所有图书--------------" << endl;
				cout << "--------------------------0.退出当前系统-----------------------------------" << endl;

				cout << " " << endl;

				cout << "---------请输入您要录入的书名 : " << book_name << endl;
				cout << "---------请输入该书的出版社   : " << book_press << endl;
				cout << "---------请输入该书的作者     : " << book_author << endl;
				cout << "---------请输入该书的入库的数量: " << book_nums << endl;

				cout << endl << "---------请确认您录入的信息( 1.没错就这样录入  2.我可能得再改改再重新录入)" << endl;
				cout << "----------请输入您的选择 : ";
				cin >> choose;
				if (choose != 1 && choose != 2)
				{
					cout << "-----------请输入正确的选项!!!" << endl;
				}
			}
			admini->Add_Book_to_Library_Admini(book_name, book_press, book_author, book_nums);

			cout << "-----------恭喜您录入信息成功!!!  感谢您对本系统的支持!!!" << endl;

			break;
		}
		case 8:
		{
			//-------------------------------------
			//-------------------------------------
			break;
		}
		case 9:
		{
			string book_id;

			cout << "----------请输入您想删除书本的ID : ";
			cin >> book_id;
			
			Book * p = admini->Seach_in_Library_By_ID_Admini(book_id);

			int ch = 0;
			if (p)
			{
				

				while (ch != 1 && ch != 2)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
					cout << std::right << setw(96) << "Current user  ID   : " << admini->Get_Admini_ID() << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "--------------------------------图书馆管理系统-----------------------------";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
					cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
					cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

					cout << "-----------1.按书名查找图书信息----------2.按编号查找书的信息--------------" << endl;
					cout << "-----------3.按书名模糊查找图书----------4.查看所有读者信息----------------" << endl;
					cout << "-----------5.添加读者账户----------------6.根据读者ID注销读者账户----------" << endl;
					cout << "-----------7.录入书本信息----------------8.修改图书信息--------------------" << endl;
					cout << "-----------9.根据书本ID删除图书---------10.打印图书馆所有图书--------------" << endl;
					cout << "--------------------------0.退出当前系统-----------------------------------" << endl;


					cout << " " << endl;

					cout << "----------ID 为 : " << book_id << "详细信息如下 : " << endl;

					p->Show_Oneself_Detail();
					cout << "----------请确认书的信息是否是您想要删除的!!!  (1.是，就是它   2.我再想想)" << endl;
					cin >> ch;

					if (ch != 1 && ch != 2)
					{
						cout << "---------请输入正确的选项!!! 请按任意键继续!!!" << endl;
						_getch();
					}

				}
				if (ch == 2)
				{
					break;
				}
				else
				{
					admini->Del_Book_from_Library_By_ID_Admini(book_id);

					cout << "--------删除成功!!!" << endl;

				}
			}
			else
			{
				cout << "---------该书本ID不存在，请您确认您输入的ID！！！" << endl;
				cout << "---------请按任意键返回上一级!!!" << endl;
				_getch();
			}

			break;
		}
		case 10:
		{
			admini->Show_Current_Books_Detail();
			break;
		}
		case 0:
		{
			system("cls");
			return ;
		}
		default:
			break;
		}

		cout << "---------请按任意键继续!!!" << endl;
		_getch();
		system("cls");
	}

}


int Reader_Menu(Reader * &reader)
{
	int choose = 11;

	while (choose > 10 || choose < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << std::right << setw(95) << "Current user  ID   : " << reader->Get_Reader_ID() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "-------------------------------读者借阅系统-------------------------------";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Current user Name  : " << reader->Get_Reader_Name() << endl;
		cout << std::right << setw(95) << "Current Permission : " << "Reader Permission" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << std::right << setw(95) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

		cout << "-----------1.按书名查找图书信息----------2.按编号查找书的信息-------------" << endl;
		cout << "-----------3.按书名模糊查找图书----------4.按照书名借书-------------------" << endl;
		cout << "-----------5.按编号借书------------------6.按编号还书---------------------" << endl;
		cout << "-----------7.按书名还书------------------8.打印图书馆所有图书-------------" << endl;
		cout << "-----------9.查看自己当前已借图书--------10.注销此账户--------------------" << endl;
		cout << "------------------------------0.退出当前系统------------------------------" << endl;

		cout << " " << endl;
		cout << "-----------请输入您的选择 : ";
		cin >> choose;

		if (choose > 10 || choose < 0)
		{
			cout << "--------------请输入正确的选项，请按任意键继续!!!" << endl;
			_getch();
			system("cls");
		}
	}

	return choose;
}

void Reader_Login(Reader * &reader)
{
	int choose = -1;

	while (choose != 0)
	{
		choose = Reader_Menu(reader);

		switch (choose)
		{
		case 1:
		{
			string book_name;
			cout << "请输入要查找的书名（完整名字） : ";
			cin >> book_name;
			if (reader->Seach_in_Library_By_Name_Reader(book_name))
			{
				(reader->Seach_in_Library_By_Name_Reader(book_name))->Show_Oneself_Detail();
			}
			else
			{
				cout << "未找到相关信息!!!" << endl;
			}
			break;
		}
		case 2:
		{
			string id;
			cout << "请输入要查找的编号 : ";
			cin >> id;
			if (reader->Seach_in_Library_By_ID_Reader(id))
			{
				(reader->Seach_in_Library_By_ID_Reader(id))->Show_Oneself_Detail();
			}
			else
			{
				cout << "未找到相关信息!!!" << endl;
			}
			break;
		}
		case 3:
		{
			string book_name;
			cout << "请输入要查找的大概书名 : ";
			cin >> book_name;
			reader->Seach_in_Library_By_Name_Reader(book_name, 1);
			break;
		}
		case 4:
		{
			string book_name;
			cout << "请输入要借的书名（完整书名） : ";
			cin >> book_name;
			if (reader->Borrow_Book(book_name))
			{
				cout << "------借书成功!!!" << endl;
			}
			else
			{
				cout << "------借书失败!!!" << endl;
			}
			break;
		}
		case 5:
		{
			int book_id = 0;
			cout << "请输入要借书的编号 : ";
			cin >> book_id;
			if (reader->Borrow_Book(book_id))
			{
				cout << "------借书成功!!!" << endl;
			}
			else
			{
				cout << "------借书失败!!!" << endl;
			}
			break;
		}
		case 6:
		{
			int book_id = 0;

			cout << "---------请输入您想要还书的编号: ";
			cin >> book_id;

			if (reader->Return_the_Book(book_id))
			{
				cout << "-----------还书成功!!!" << endl;
			}
			else
			{
				cout << "-----------还书失败!!!" << endl;
			}

			break;
		}
		case 7:
		{
			string Book_Name;

			cout << "---------请输入您想要还书的书名（完整书名）: ";
			cin >> Book_Name;

			if (reader->Return_the_Book(Book_Name))
			{
				cout << "-----------还书成功!!!" << endl;
			}
			else
			{
				cout << "-----------还书失败!!!" << endl;
			}
			break;
		}
		case 8:
		{
			reader->Show_Books_Detail_in_Library_Reader();
			break;
		}
		case 9:
		{
			reader->Show_Borrow_Book_Detail();
			break;
		}
		case 10:
		{
			R_Del_Reader_from_Reader_List(reader->Get_Reader_ID(), reader->Get_Reader_PW());

			cout << "------------------请按任意键继续!!!" << endl;
			_getch();
			system("cls");
			return;
		}
		case 0:
		{
			system("cls");
			return;
		}
		default:
			break;
		}
		cout << "---------请按任意键继续!!!" << endl;
		_getch();
		system("cls");
	}
}

int menu(void)
{
	int Lgi_or_Lgo = 0;
	int choose = 0, judge = -1;
	string name;

	ADMINI = Get_Admini();

	while (1)
	{
		Lgi_or_Lgo = 0;
		//选择登陆或是注册
		while (Lgi_or_Lgo != 1)
		{
			Lgi_or_Lgo = Login_or_Logon();

			if (Lgi_or_Lgo == 3)
			{
				cout << "  " << endl << endl << endl;
				cout << "--------------欢迎您的下次使用!!!" << endl;
				return 0;
			}

			if (Lgi_or_Lgo == 2)
			{
				string pw, name;
				char sex = 0;
				cout << "--------------------图书馆管理系统--------------------" << endl;
				cout << "-------读者账号注册:" << endl << endl;
				cout << "-------自动为您分配的账号为 : " << Auto_Allot_ReaderID() << endl;
				cout << "-------请输入您想要的密码   : ";
				cin >> pw;
				cout << "-------请输入您的姓名       : ";
				cin >> name;

				while (sex != 'F' && sex != 'M')
				{
					system("cls");
					cout << "--------------------图书馆管理系统--------------------" << endl;
					cout << "-------读者账号注册:" << endl << endl;
					cout << "-------自动为您分配的账号为 : " << Auto_Allot_ReaderID() << endl;
					cout << "-------请输入您想要的密码   : " << pw << endl;
					cout << "-------请输入您的姓名       : " << name << endl;
					cout << "-------请选择您的性别 F(男)  M(女)  : ";
					cin >> sex;
					if (sex != 'F' && sex != 'M')
					{
						cout << "-------请输入正确的选项(F or M)，请按任意键重新选择!!!" << endl;
						_getch();
					}
				}

				R_Add_Reader_to_Reader_List(pw, name, sex);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "---------恭喜您！成功注册账户，欢迎使用本系统!!!-------" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "-------------------请按任意键继续!!!-------------------" << endl;
				_getch();
				system("cls");
			}
		}

		//管理员、用户登陆
		name = Login(&judge);

		if (judge == -1)
		{
			system("cls");
			break;
		}

		if (judge == 0)
		{
			system("cls");

			Admini_Login(ADMINI);

		}
		if (judge == 1)
		{
			system("cls");
			if (USER)
			{
				Reader_Login(USER);
			}
		}
	}

	return choose;
}

void Library_Management_System()
{
	int ret = 0;
	Init_Book_List();
	Init_Reader_List();
	Init_Admini();
	ret = menu();
}