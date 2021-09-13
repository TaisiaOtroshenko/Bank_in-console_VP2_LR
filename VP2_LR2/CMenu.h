#pragma once
#include "ItemMenu.h"

namespace otv
{
	class CMenu
		//принимает файл с названиями пунктов меню, массив функций void() 
		//запускает функцию пункта меню
		//ничего не возвращает
	{
	private:
		int m_select = -1; // последний ввод пользователя
		bool m_running = false; // индикатор выполнения меню
		string m_title{}; // ссылка на C-строку -- заголовок меню
		size_t m_count = 0; //колличество пунктов меню 
		ItemMenu* m_items{}; // указатель на массив объектов абстрактного класса ItemMenu

	public:
		CMenu(string title, ItemMenu* items, size_t item_count);

		int GetSelect() const;
		string GetTitle() const;
		size_t GetCount() const;
		bool IsRun() const;
		ItemMenu* GetItems() const;

		void Print() const;
		void RunCommand();
		friend ostream& operator<< (ostream& out, const CMenu& m);
		friend istream& operator>> (istream& in, CMenu& m);
	};
}