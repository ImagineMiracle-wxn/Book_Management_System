#include "Menu.h"

Administrator * ADMINI = NULL;
Reader * USER = NULL;

int Login_or_Logon(void)
{
	int choose = 0;
	while (choose != 1 && choose != 2 && choose != 3)
	{
		cout << "--------------------ͼ��ݹ���ϵͳ--------------------" << endl;
		cout << " " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << "��ܰ��ʾ: " << endl;
		cout << "������������������������������������������������������" << endl;
		cout << "|--------------����Ա��ʹ��Ĭ���˺ŵ�½--------------|" << endl;
		cout << "|-----�������һ��ʹ�ñ�ϵͳ���û�������ע���˺�-----|" << endl;
		cout << "������������������������������������������������������" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "------------------1.�����˺�ֱ�ӵ�½  " << endl;
		cout << "------------------2.ע���˺�(ֻ��ע������˺�)        " << endl;
		cout << "------------------3.�˳�ϵͳ" << endl;


		cout << " " << endl << endl;
		cout << "     ��ѡ�� : ";
		cin >> choose;
		if (choose != 1 && choose != 2 && choose != 3)
		{
			cout << "            ��������ȷ��ѡ��!!!(1 or 2 or 3)            " << endl;
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
			cout << "------------��������ȷ��ѡ��!!!  �밴���������!!!" << endl;
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


		cout << endl << std::right << setw(37) << "�밴�����ȷ�ϡ���" << endl;
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
				cout << endl << std::right << setw(37) << "�밴�����ȷ�ϡ���" << endl;
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
					cout << endl << std::right << setw(37) << "�밴�����ȷ�ϡ���" << endl;
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
			cout << endl << std::right << setw(37) << "�밴�����ȷ�ϡ���" << endl;
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
		cout << "--------------------------------ͼ��ݹ���ϵͳ-----------------------------";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
		cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

		cout << "-----------1.����������ͼ����Ϣ----------2.����Ų��������Ϣ--------------" << endl;
		cout << "-----------3.������ģ������ͼ��----------4.�鿴���ж�����Ϣ----------------" << endl;
		cout << "-----------5.��Ӷ����˻�----------------6.���ݶ���IDע�������˻�----------" << endl;
		cout << "-----------7.¼���鱾��Ϣ----------------8.�޸�ͼ����Ϣ--------------------" << endl;
		cout << "-----------9.�����鱾IDɾ��ͼ��---------10.��ӡͼ�������ͼ��--------------" << endl;
		cout << "--------------------------0.�˳���ǰϵͳ-----------------------------------" << endl;

		cout << " " << endl;
		cout << "-----------����������ѡ�� : ";
		cin >> choose;

		if (choose > 11 || choose < 0)
		{
			cout << "--------------��������ȷ��ѡ��밴���������!!!" << endl;
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
			cout << "������Ҫ���ҵ��������������֣� : ";
			cin >> book_name;
			if (admini->Seach_in_Library_By_Name_Admini(book_name))
			{
				(admini->Seach_in_Library_By_Name_Admini(book_name))->Show_Oneself_Detail();
			}
			else
			{
				cout << "δ�ҵ������Ϣ!!!" << endl;
			}

			break;
		}
		case 2:
		{
			string book_id;
			cout << "������Ҫ������ı�� : ";
			cin >> book_id;
			if (admini->Seach_in_Library_By_ID_Admini(book_id))
			{
				(admini->Seach_in_Library_By_ID_Admini(book_id))->Show_Oneself_Detail();
			}
			else
			{
				cout << "δ�ҵ������Ϣ!!!" << endl;
			}

			break;
		}
		case 3:
		{
			string book_name;
			cout << "����������Ҫ���ҵĴ������ : ";
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
			cout << endl << "-------�����˺�ע��:" << endl << endl;
			cout << "-------�Զ�Ϊ��������˺�Ϊ : " << Auto_Allot_ReaderID() << endl;
			cout << "-------����������Ҫ������   : ";
			cin >> pw;
			cout << "-------��������������       : ";
			cin >> name;

			while (sex != 'F' && sex != 'M')
			{
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << std::right << setw(96) << "Current user  ID   : " << admini->Get_Admini_ID() << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "--------------------------------ͼ��ݹ���ϵͳ-----------------------------";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
				cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

				cout << endl << "-------�����˺�ע��:" << endl << endl;
				cout << "-------�Զ�Ϊ��������˺�Ϊ : " << Auto_Allot_ReaderID() << endl;
				cout << "-------����������Ҫ������   : " << pw << endl;
				cout << "-------��������������       : " << name << endl;
				cout << "-------��ѡ�������Ա� F(��)  M(Ů)  : ";
				cin >> sex;
				if (sex != 'F' && sex != 'M')
				{
					cout << "-------��������ȷ��ѡ��(F or M)���밴���������ѡ��!!!" << endl;
					_getch();
				}
			}

			admini->Add_Reader_to_Reader_List(pw, name, sex);
			cout << "--------��ϲ����Administrator�ɹ�ע����һ�������˻�!!!-----" << endl << endl;
			cout << "-------------------�밴���������!!!-------------------" << endl;
			_getch();
			system("cls");
			break;
		}
		case 6:
		{

			string reader_id;
			cout << "---------����������Ҫע���Ķ���ID : ";
			cin >> reader_id;

			admini->Del_Reader_from_Reader_List(reader_id);

			break;
		}
		case 7:
		{
			string book_name, book_press, book_author;
			int book_nums = 0, choose = 0;

			cout << " " << endl;

			cout << "---------��������Ҫ¼������� : ";
			cin >> book_name;
			cout << "---------���������ĳ�����   : ";
			cin >> book_press;
			cout << "---------��������������     : ";
			cin >> book_author;
			cout << "---------������������������: ";
			cin >> book_nums;

			while (choose != 1 && choose != 2)
			{
				system("cls");

				cout << "--------------------------------ͼ��ݹ���ϵͳ-----------------------------";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
				cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
				cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

				cout << "-----------1.����������ͼ����Ϣ----------2.����Ų��������Ϣ--------------" << endl;
				cout << "-----------3.������ģ������ͼ��----------4.�鿴���ж�����Ϣ----------------" << endl;
				cout << "-----------5.��Ӷ����˻�----------------6.���ݶ���IDע�������˻�----------" << endl;
				cout << "-----------7.¼���鱾��Ϣ----------------8.�޸�ͼ����Ϣ--------------------" << endl;
				cout << "-----------9.�����鱾IDɾ��ͼ��---------11.��ӡͼ�������ͼ��--------------" << endl;
				cout << "--------------------------0.�˳���ǰϵͳ-----------------------------------" << endl;

				cout << " " << endl;

				cout << "---------��������Ҫ¼������� : " << book_name << endl;
				cout << "---------���������ĳ�����   : " << book_press << endl;
				cout << "---------��������������     : " << book_author << endl;
				cout << "---------������������������: " << book_nums << endl;

				cout << endl << "---------��ȷ����¼�����Ϣ( 1.û�������¼��  2.�ҿ��ܵ��ٸĸ�������¼��)" << endl;
				cout << "----------����������ѡ�� : ";
				cin >> choose;
				if (choose != 1 && choose != 2)
				{
					cout << "-----------��������ȷ��ѡ��!!!" << endl;
				}
			}
			admini->Add_Book_to_Library_Admini(book_name, book_press, book_author, book_nums);

			cout << "-----------��ϲ��¼����Ϣ�ɹ�!!!  ��л���Ա�ϵͳ��֧��!!!" << endl;

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

			cout << "----------����������ɾ���鱾��ID : ";
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
					cout << "--------------------------------ͼ��ݹ���ϵͳ-----------------------------";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
					cout << "Current user Name  : " << admini->Get_Admini_ID() << endl;
					cout << std::right << setw(96) << "Current Permission : " << "Administrator" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << std::right << setw(96) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

					cout << "-----------1.����������ͼ����Ϣ----------2.����Ų��������Ϣ--------------" << endl;
					cout << "-----------3.������ģ������ͼ��----------4.�鿴���ж�����Ϣ----------------" << endl;
					cout << "-----------5.��Ӷ����˻�----------------6.���ݶ���IDע�������˻�----------" << endl;
					cout << "-----------7.¼���鱾��Ϣ----------------8.�޸�ͼ����Ϣ--------------------" << endl;
					cout << "-----------9.�����鱾IDɾ��ͼ��---------10.��ӡͼ�������ͼ��--------------" << endl;
					cout << "--------------------------0.�˳���ǰϵͳ-----------------------------------" << endl;


					cout << " " << endl;

					cout << "----------ID Ϊ : " << book_id << "��ϸ��Ϣ���� : " << endl;

					p->Show_Oneself_Detail();
					cout << "----------��ȷ�������Ϣ�Ƿ�������Ҫɾ����!!!  (1.�ǣ�������   2.��������)" << endl;
					cin >> ch;

					if (ch != 1 && ch != 2)
					{
						cout << "---------��������ȷ��ѡ��!!! �밴���������!!!" << endl;
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

					cout << "--------ɾ���ɹ�!!!" << endl;

				}
			}
			else
			{
				cout << "---------���鱾ID�����ڣ�����ȷ���������ID������" << endl;
				cout << "---------�밴�����������һ��!!!" << endl;
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

		cout << "---------�밴���������!!!" << endl;
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
		cout << "-------------------------------���߽���ϵͳ-------------------------------";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Current user Name  : " << reader->Get_Reader_Name() << endl;
		cout << std::right << setw(95) << "Current Permission : " << "Reader Permission" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << std::right << setw(95) << "System   Admini    : " << Get_Admini()->Get_Admini_ID() << endl;

		cout << "-----------1.����������ͼ����Ϣ----------2.����Ų��������Ϣ-------------" << endl;
		cout << "-----------3.������ģ������ͼ��----------4.������������-------------------" << endl;
		cout << "-----------5.����Ž���------------------6.����Ż���---------------------" << endl;
		cout << "-----------7.����������------------------8.��ӡͼ�������ͼ��-------------" << endl;
		cout << "-----------9.�鿴�Լ���ǰ�ѽ�ͼ��--------10.ע�����˻�--------------------" << endl;
		cout << "------------------------------0.�˳���ǰϵͳ------------------------------" << endl;

		cout << " " << endl;
		cout << "-----------����������ѡ�� : ";
		cin >> choose;

		if (choose > 10 || choose < 0)
		{
			cout << "--------------��������ȷ��ѡ��밴���������!!!" << endl;
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
			cout << "������Ҫ���ҵ��������������֣� : ";
			cin >> book_name;
			if (reader->Seach_in_Library_By_Name_Reader(book_name))
			{
				(reader->Seach_in_Library_By_Name_Reader(book_name))->Show_Oneself_Detail();
			}
			else
			{
				cout << "δ�ҵ������Ϣ!!!" << endl;
			}
			break;
		}
		case 2:
		{
			string id;
			cout << "������Ҫ���ҵı�� : ";
			cin >> id;
			if (reader->Seach_in_Library_By_ID_Reader(id))
			{
				(reader->Seach_in_Library_By_ID_Reader(id))->Show_Oneself_Detail();
			}
			else
			{
				cout << "δ�ҵ������Ϣ!!!" << endl;
			}
			break;
		}
		case 3:
		{
			string book_name;
			cout << "������Ҫ���ҵĴ������ : ";
			cin >> book_name;
			reader->Seach_in_Library_By_Name_Reader(book_name, 1);
			break;
		}
		case 4:
		{
			string book_name;
			cout << "������Ҫ������������������� : ";
			cin >> book_name;
			if (reader->Borrow_Book(book_name))
			{
				cout << "------����ɹ�!!!" << endl;
			}
			else
			{
				cout << "------����ʧ��!!!" << endl;
			}
			break;
		}
		case 5:
		{
			int book_id = 0;
			cout << "������Ҫ����ı�� : ";
			cin >> book_id;
			if (reader->Borrow_Book(book_id))
			{
				cout << "------����ɹ�!!!" << endl;
			}
			else
			{
				cout << "------����ʧ��!!!" << endl;
			}
			break;
		}
		case 6:
		{
			int book_id = 0;

			cout << "---------����������Ҫ����ı��: ";
			cin >> book_id;

			if (reader->Return_the_Book(book_id))
			{
				cout << "-----------����ɹ�!!!" << endl;
			}
			else
			{
				cout << "-----------����ʧ��!!!" << endl;
			}

			break;
		}
		case 7:
		{
			string Book_Name;

			cout << "---------����������Ҫ���������������������: ";
			cin >> Book_Name;

			if (reader->Return_the_Book(Book_Name))
			{
				cout << "-----------����ɹ�!!!" << endl;
			}
			else
			{
				cout << "-----------����ʧ��!!!" << endl;
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

			cout << "------------------�밴���������!!!" << endl;
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
		cout << "---------�밴���������!!!" << endl;
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
		//ѡ���½����ע��
		while (Lgi_or_Lgo != 1)
		{
			Lgi_or_Lgo = Login_or_Logon();

			if (Lgi_or_Lgo == 3)
			{
				cout << "  " << endl << endl << endl;
				cout << "--------------��ӭ�����´�ʹ��!!!" << endl;
				return 0;
			}

			if (Lgi_or_Lgo == 2)
			{
				string pw, name;
				char sex = 0;
				cout << "--------------------ͼ��ݹ���ϵͳ--------------------" << endl;
				cout << "-------�����˺�ע��:" << endl << endl;
				cout << "-------�Զ�Ϊ��������˺�Ϊ : " << Auto_Allot_ReaderID() << endl;
				cout << "-------����������Ҫ������   : ";
				cin >> pw;
				cout << "-------��������������       : ";
				cin >> name;

				while (sex != 'F' && sex != 'M')
				{
					system("cls");
					cout << "--------------------ͼ��ݹ���ϵͳ--------------------" << endl;
					cout << "-------�����˺�ע��:" << endl << endl;
					cout << "-------�Զ�Ϊ��������˺�Ϊ : " << Auto_Allot_ReaderID() << endl;
					cout << "-------����������Ҫ������   : " << pw << endl;
					cout << "-------��������������       : " << name << endl;
					cout << "-------��ѡ�������Ա� F(��)  M(Ů)  : ";
					cin >> sex;
					if (sex != 'F' && sex != 'M')
					{
						cout << "-------��������ȷ��ѡ��(F or M)���밴���������ѡ��!!!" << endl;
						_getch();
					}
				}

				R_Add_Reader_to_Reader_List(pw, name, sex);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "---------��ϲ�����ɹ�ע���˻�����ӭʹ�ñ�ϵͳ!!!-------" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "-------------------�밴���������!!!-------------------" << endl;
				_getch();
				system("cls");
			}
		}

		//����Ա���û���½
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