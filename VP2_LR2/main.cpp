#include <iostream>
#include <fstream>
#include <vector>

#include "CMenu.h"
#include "Client.h"
#include "Employee.h"
#include "Account.h"

using namespace std;
using namespace otv;

typedef int(*func)();

string CLI = "client.bin", EMP = "employee.bin", ACC = "accounts.bin",

MENU_AUTH = "menu_auth.txt",
MENU_CLI = "menu_client.txt",
MENU_EMP = "menu_employee.txt";

ifstream FIN;
char* buff = new char[1024]{};

vector<Client> CLIENT{};
vector <Employee> EMPLOYEE{};
vector <Account> ACCOUNT{};

int VERIFY;
User* CUR_USER{};


int AddIt();
int DelIt();
int EditIt();
int SortIt();
int FilterIt();
int VerifyOut();
int AddClient();
int AddEmployee();
int Verify();
int Screen_2();

void Screen_0();





int main()
{
	setlocale(0, "");

#pragma region �������� ����� ��������
	
	FIN.open(CLI, ios_base::in);

	size_t item_count{};
	FIN >> item_count;
	FIN.ignore();


	Client tmp_client{};
	for (int i = 0; i < item_count && FIN.is_open(); i++)
	{
		FIN.read((char*)&tmp_client, sizeof(Client));
		CLIENT.push_back(tmp_client);
	}
	FIN.close();
#pragma endregion

#pragma region Загрузка файла сотрудников

	FIN.open(EMP, ios_base::in);

	item_count = 0;
	FIN >> item_count;
	FIN.ignore();


	Employee tmp_employee{};
	for (int i = 0; i < item_count && FIN.is_open(); i++)
	{
		FIN.read((char*)&tmp_client, sizeof(Employee));
		EMPLOYEE.push_back(tmp_employee);
	}
	FIN.close();
#pragma endregion


#pragma region Загрузка файла карточек

	fin.open(ACC, ios_base::in);

	item_count = 0;
	fin >> item_count;
	fin.ignore();


	Account tmp_card{};
	for (int i = 0; i < item_count && fin.is_open(); i++)
	{
		fin.read((char*)&tmp_card, sizeof(Account));
		ACCOUNT.push_back(tmp_card);
	}
	fin.close();
#pragma endregion

#pragma region заполнение массива пунктов первого меню

	FIN.open(MENU_AUTH);

	size_t item_count_1{};
	FIN >> item_count_1;
	FIN.ignore();

	ItemMenu* items_1 = new ItemMenu[item_count_1]{};
	for (int i = 0; i < item_count_1 && FIN.is_open(); i++)
	{
		FIN.getline(buff, 1023);
		items_1[i].SetItemName(buff);
	}
	FIN.close();


	items_1[0].SetFunc(AddClient);
	items_1[1].SetFunc(AddEmployee);
	items_1[2].SetFunc(Verify);
#pragma endregion
#pragma region ����� ������� ����

	CMenu menu_auth = CMenu("���� �����", items_1, item_count_1);

	while (CUR_USER == nullptr)
	{
		cout << menu_auth;
		menu_auth.RunCommand();
	}

	Screen_2();


	system("pause");
	return 0;
}
#pragma endregion
}





int AddClient()
{
	Client tmp_cli{};
	tmp_cli.In();
	CLIENT.push_back(tmp_cli);

	return 0;
}
int AddEmployee()
{
	Employee tmp_emp{};
	tmp_emp.In();
	EMPLOYEE.push_back(tmp_emp);
	return 0;
}
int Verify()
//пройти по векторам пользователей, сверить логины и пароли
{
	User tmp_user{};
	tmp_user.In();
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (tmp_user.getLogin() == CLIENT[i].getLogin())
		{
			cout << "Пользователь найден!" << endl;
			if (tmp_user.getPassword() == CLIENT[i].getPassword()) {
				CUR_USER = &CLIENT[i];
				cout << "Пароль верный" << endl;
			}
		}
	}
	for (int i = 0; i < EMPLOYEE.size(); i++)
	{
		if (true)
		{
			CUR_USER = &EMPLOYEE[i];
		}
	}
	if (CUR_USER == nullptr)
	{
		cout << "Неверно введены данные" << endl;
	}
	return 0;
}



int Screen_2()
{
#pragma region заполнение массива пунктов второго меню
	ifstream fin;
	fin.open(MENU_CLI);
	size_t item_count_2{};
	fin >> item_count_2;

	ItemMenu* items_2 = new ItemMenu[item_count_2]{};
	for (int i = 0; i < item_count_2 && fin.is_open(); i++)
	{
		fin >> buff;
		items_2[i].SetItemName(buff);
	}
	fin.close();

	items_2[0].SetFunc(AddIt);
	items_2[1].SetFunc(DelIt);
	items_2[2].SetFunc(EditIt);
	items_2[3].SetFunc(SortIt);
	items_2[4].SetFunc(FilterIt);
	items_2[5].SetFunc(VerifyOut);
#pragma endregion

	CMenu menu_func = CMenu("Меню пользователя", items_2, item_count_2);
	do
	{
		cout << menu_func;
		cin >> menu_func;
	} while (VERIFY);
	return 0;
}





int AddIt() {
	return 0;
};
int DelIt() {
	return 0;
};
int EditIt() {
	return 0;
};
int SortIt() {
	return 0;
};
int FilterIt() {
	return 0;
};

int VerifyOut()
{
	VERIFY = 0;
	return 0;
};
