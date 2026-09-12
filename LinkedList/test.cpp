#include <iostream>
#include "LinkedList.h"
#include <list>

#define PROFILE
#include "profile.h"

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
	List<int> myList;

	std::list<int> stlList;

	for (int j = 0; j < 1000000; j++)
	{
		srand(time(NULL));
		{
			PROFILE_SCOPE("My List push_back");
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
		}
	}

	for (int j = 0; j < 1000000; j++)
	{
		srand(time(NULL));
		{
			PROFILE_SCOPE("STL List push_back");
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
		}
	}

	for (int j = 0; j < 1000000; j++)
	{
		srand(time(NULL));
		{
			PROFILE_SCOPE("My List push_front");
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
			myList.push_back(rand() % 100 + 1);
		}
	}

	for (int j = 0; j < 1000000; j++)
	{
		srand(time(NULL));
		{
			PROFILE_SCOPE("STL List push_front");
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
			stlList.push_back(rand() % 100 + 1);
		}
	}

	//size_t dataSize = 0;

	//for (int i = 0; i < PROFILES_SIZE; i++)
	//{
	//	if (profiles[i].name == nullptr)
	//		continue;

	//	dataSize += profiles[i].tscTrace.size();
	//}
	//std::cout << dataSize / 1000000 << "." << dataSize % 1000000 << "MB";

	ProfileDataOutText("profile.txt");
}