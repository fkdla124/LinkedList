# LinkedList + Iterator 구현.
Head, Tail에 각각 하나씩 dummyNode를 두어 삽입, 삭제 시에 불필요한 nullptr 체크를 없애고 구현 난이도를 낮춤.
<br>
<br>
# STL과 속도차이 간단 비교.
<img width="1296" height="143" alt="image" src="https://github.com/user-attachments/assets/2bf77ad7-c4e8-45a4-9934-90632fd402e6" /><br>
List<int> 생성 후 데이터 삽입을 한 번의 call당 10번 삽입. 총 1000000번씩 반복한 결과.<br>
약 두배의 차이를 보임<br>
<br>
테스트코드<br>
```cpp
#include "LinkedList.h"
#include <list>

#define PROFILE
#include "profile.h"

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

	ProfileDataOutText("profile.txt");
}

```
