#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
using namespace std;

//перегрузить операторы сравнения на int и char и присвоения 

User::User()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
}

void User::In()
{
	cin >> m_login;
	cin >> m_pass;
}




#pragma region  вывод
string User::OutLvl()
{
	return (m_lvl) ? ("Сотрудник") : ("Клиент");
}
void User::PrintParent() const
{
	//OutLvl();
	cout << "ID пользователя - " << m_id << endl;
	cout << "Имя пользователя - " << m_name << endl;
}
ostream& operator<<(ostream& out, const User& man)
{
	man.PrintParent();
	return out;
}
#pragma endregion

