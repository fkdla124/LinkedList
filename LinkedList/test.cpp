// #include "LinkedList.h"

#include <iostream>
#include "LinkedList.h"
#include <list>

template <typename T>
void PrintList(const std::list<T>& list)
{
	if (list.empty())
	{
		std::cout << "list empty : " << std::boolalpha << list.empty() << "\n";
		std::cout << "list size : " << list.size() << "\n";
		std::cout << "\n\n";
		return;
	}

	std::cout << "list empty : " << std::boolalpha << list.empty() << "\n";
	std::cout << "list size : " << list.size() << "\n";
	std::cout << "list front : " << list.front() << "\n";
	std::cout << "list back : " << list.back() << "\n";
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n\n";
}


int main()
{
	List<int> list;

	List<int> list2(std::move(list));

	srand(time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		list.push_back(rand() % 100 + 1);
	}
}