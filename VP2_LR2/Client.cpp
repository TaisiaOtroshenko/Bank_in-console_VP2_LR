#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"

Client::Client()
{
	m_lvl = false;
}
void Client::In()
{
	cout << "Введите логин: ";
	cin >> m_login;
	cout << "Введите пароль: ";
	cin >> m_pass;
	cout << "Введите имя: ";
	cin >> m_name;
}
void Client::Print() const
{
	PrintParent();

	cout << "Имя - " << m_name << endl;
	cout << "Пароль - " << m_pass << endl;

	cout << "Дата создания -  " << m_date << endl;
}

Client Client::operator=(Client a)
{
	m_id = a.m_id;
	m_lvl = a.m_lvl;
	m_date = a.m_date;
	m_name = a.m_name;
	m_login = a.m_login;
	m_pass = a.m_pass;
	return *this;
}
bool operator> (const Client& a, const Client& b)
{
	return a.m_name > b.m_name;
}
bool operator== (const Client& a, const Client& b)
{
	bool r{};
	r = (a.m_login == b.m_login && a.m_pass == b.m_pass);
	return r;
}
