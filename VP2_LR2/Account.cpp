#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
using namespace std;

Account::Account()
{
	m_id = ID_account++;

	// !!! Какого-то дьявола выводится время вывода, а не время создания объекта
	time_t now = time(0);
	m_date = ctime(&now);
}
Account::Account(size_t id_owner)
{
	m_id_owner = id_owner;
	m_id = ID_account++;
	time_t now = time(0);
	m_date = ctime(&now);
}
size_t Account::GetId()
{
	return m_id;
}
size_t Account::GetIdOwner()
{
	return m_id_owner;
}

/*void Account::Trans(Account scd, int summ_tr)
{
	m_balance -= summ_tr;
	scd.m_balance += summ_tr;
}*/

void Account::In()
{
	cout << "Введите имя карты: ";
	cin >> m_name;
}

void Account::Print() const
{
	cout << "Имя карты - " << m_name << endl;
	cout << "Номер карты - " << m_id << endl;
	cout << "ID владельца карты - " << m_id_owner << endl;
	cout << "Дата создания карты - " << m_date;
	cout << "\t Баланс: " << m_balance << endl;
}
ostream& operator<< (ostream& out, const Account& acc)
{
	acc.Print();
	return out;
}

Account Account:: operator=(Account a)
{
	m_id = a.m_id;
	m_date = a.m_date;
	m_name = a.m_name;
	m_id_owner = a.m_id_owner;
	m_balance = a.m_balance;
	m_date = a.m_date;
	return a;
}
bool operator> (const Account& a, const Account& b)
{
	return a.m_name > b.m_name;
}