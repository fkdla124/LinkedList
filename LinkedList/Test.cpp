#include <iostream>
#include "List.h"
#include <list>

int main()
{
	List<int> list;

	for (int i = 1; i <= 100; i++)
	{
		list.push_back(i);
	}

	auto it = list.begin();

	for (int i = 0; i < 50; i++)
	{
		++it;
	}

	list.insert(it, list.begin(), list.end());

	list.print();

	return 0;
}