#pragma once
#include <fstream>
typedef int(*func)();

string CLI = "client.bin", EMP = "employee.bin", ACC = "account.bin",

MENU_AUTH = "menu_auth.txt",
MENU_CLI = "menu_client.txt",
MENU_EMP = "menu_employee.txt",
MENU_LIST = "menu_list.txt";
ifstream FIN_TXT;

char* buff = new char[1024]{};

size_t id_us = 1000;
size_t id_acc = 1001001;

User* CUR_USER{};
int cur_list = -1;