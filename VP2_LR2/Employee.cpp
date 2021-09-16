#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

Employee::Employee()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
	m_lvl = true;
}

void Employee::In() // &&& узнать, как заставить эту функцию вызывать .In класса-родителя User
{
	cout << "Введите логин: ";
	cin >> m_login;
	cout << "Введите пароль: ";
	cin >> m_pass;
	cout << "Введите имя: ";
	cin >> m_name;
}

void Employee::Print() const
{
	cout << "\t\t" << "Текущие данные пользователя" << endl;
	cout << "Тип пользователя - Сотрудник" << endl;
	cout << "ID пользователя - " << m_id << endl;
	cout << "Имя пользователя - " << m_name << endl;
}

/*Employee Employee:: operator=(Employee a)
{
	m_id = a.m_id;
	m_login = a.m_login;
	m_pass = a.m_pass;
	m_date = a.m_date;
	m_name = a.m_name;
	m_lvl = a.m_lvl;
	m_salary = a.m_salary;
	//m_salary_card = a.m_salary_card;
}*/

bool operator> (const Employee& a, const Employee& b)
{
	return a.m_name > b.m_name;
}

bool operator== (const Employee& a, const Employee& b)
{
	bool r{};
	r = (a.m_login == b.m_login && a.m_pass == b.m_pass);
	return r;
}
