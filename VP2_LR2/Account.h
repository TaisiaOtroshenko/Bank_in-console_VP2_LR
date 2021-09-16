#pragma once
#include <iostream>
using namespace std;
static size_t ID_account = 10000000000;

class Account
{
	size_t m_id_owner{};
	size_t m_id{};
	string m_name{};
	char* m_date;
	unsigned long m_balance{};
public:
	Account();
	Account(size_t id_owner);

	size_t GetIdOwner();
	//void Trans(Account scd, int summ_tr);

	void In();
	void Print() const;
	friend ostream& operator<<(ostream& out, const Account& acc);

	Account operator=(Account a);
	friend bool operator> (const Account& a, const Account& b);
};
