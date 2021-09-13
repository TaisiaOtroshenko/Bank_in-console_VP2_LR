#include "ItemMenuAbstract.h"

namespace otv
{
	ItemMenuForm::ItemMenuForm()
	{
		m_item_name;
		m_func;
	}
	ItemMenuForm::ItemMenuForm(string name, func F)
	{
		m_item_name = name;
		m_func = F;
	}
}
