#include <iostream>
#include "LinkedList.h"

// AI가 짜준 테스트코드 

void TestPushPop()
{
    std::cout << "[TestPushPop]\n";

    List<int> list;

    assert(list.empty());
    assert(list.size() == 0);

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    assert(!list.empty());
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list.back() == 20);

    list.pop_front();

    assert(list.size() == 2);
    assert(list.front() == 10);

    list.pop_back();

    assert(list.size() == 1);
    assert(list.back() == 10);

    list.pop_back();

    assert(list.empty());
    assert(list.size() == 0);

    std::cout << "PASS\n\n";
}


void TestIterator()
{
    std::cout << "[TestIterator]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int expected[] = { 10, 20, 30 };
    int index = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        assert(*it == expected[index]);
        index++;
    }

    assert(index == 3);

    auto it = list.begin();

    assert(*it == 10);

    ++it;
    assert(*it == 20);

    it++;
    assert(*it == 30);

    --it;
    assert(*it == 20);

    it--;
    assert(*it == 10);

    std::cout << "PASS\n\n";
}


void TestInsert()
{
    std::cout << "[TestInsert]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(30);

    auto it = list.begin();
    ++it; // 30

    auto inserted = list.insert(it, 20);

    assert(*inserted == 20);
    assert(list.size() == 3);

    int expected[] = { 10, 20, 30 };
    int index = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
    {
        assert(*i == expected[index]);
        index++;
    }

    std::cout << "PASS\n\n";
}


void TestErase()
{
    std::cout << "[TestErase]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    auto it = list.begin();
    ++it; // 20

    auto next = list.erase(it);

    assert(*next == 30);
    assert(list.size() == 2);

    int expected[] = { 10, 30 };
    int index = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
    {
        assert(*i == expected[index]);
        index++;
    }

    std::cout << "PASS\n\n";
}


void TestEraseRange()
{
    std::cout << "[TestEraseRange]\n";

    List<int> list;

    for (int i = 1; i <= 5; ++i)
        list.push_back(i);

    auto first = list.begin();
    ++first; // 2

    auto last = list.end();
    --last; // 5

    list.erase(first, last);

    // 1, 5
    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 5);

    std::cout << "PASS\n\n";
}


void TestRemove()
{
    std::cout << "[TestRemove]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.remove(20);

    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 30);

    // 존재하지 않는 값
    list.remove(100);

    assert(list.size() == 2);

    std::cout << "PASS\n\n";
}


void TestCopyConstructor()
{
    std::cout << "[TestCopyConstructor]\n";

    List<int> original;

    original.push_back(10);
    original.push_back(20);
    original.push_back(30);

    List<int> copy(original);

    assert(copy.size() == original.size());

    auto it1 = original.begin();
    auto it2 = copy.begin();

    for (; it1 != original.end(); ++it1, ++it2)
    {
        assert(*it1 == *it2);
    }

    // 깊은 복사 확인
    original.front() = 999;

    assert(copy.front() == 10);

    std::cout << "PASS\n\n";
}


void TestCopyAssignment()
{
    std::cout << "[TestCopyAssignment]\n";

    List<int> a;
    a.push_back(10);
    a.push_back(20);

    List<int> b;
    b.push_back(100);
    b.push_back(200);
    b.push_back(300);

    b = a;

    assert(b.size() == 2);
    assert(b.front() == 10);
    assert(b.back() == 20);

    // 깊은 복사 확인
    a.front() = 999;

    assert(b.front() == 10);

    std::cout << "PASS\n\n";
}


void TestSelfCopyAssignment()
{
    std::cout << "[TestSelfCopyAssignment]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list = list;

    // 현재 네 코드에서는 이 테스트가 실패함.
    // copy assignment에
    //
    // if (this == &src)
    //     return *this;
    //
    // 가 필요함.

    assert(list.size() == 3);
    assert(list.front() == 10);
    assert(list.back() == 30);

    std::cout << "PASS\n\n";
}


void TestMoveConstructor()
{
    std::cout << "[TestMoveConstructor]\n";

    List<int> src;

    src.push_back(10);
    src.push_back(20);
    src.push_back(30);

    List<int> dst(std::move(src));

    assert(dst.size() == 3);
    assert(dst.front() == 10);
    assert(dst.back() == 30);

    // move 후 source는 empty
    assert(src.empty());
    assert(src.size() == 0);

    std::cout << "PASS\n\n";
}


void TestMoveAssignment()
{
    std::cout << "[TestMoveAssignment]\n";

    List<int> src;

    src.push_back(10);
    src.push_back(20);
    src.push_back(30);

    List<int> dst;

    dst.push_back(100);
    dst.push_back(200);

    dst = std::move(src);

    assert(dst.size() == 3);
    assert(dst.front() == 10);
    assert(dst.back() == 30);

    assert(src.empty());
    assert(src.size() == 0);

    std::cout << "PASS\n\n";
}


void TestInitializerList()
{
    std::cout << "[TestInitializerList]\n";

    List<int> list{ 10, 20, 30, 40 };

    assert(list.size() == 4);
    assert(list.front() == 10);
    assert(list.back() == 40);

    int expected[] = { 10, 20, 30, 40 };
    int index = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        assert(*it == expected[index]);
        index++;
    }

    std::cout << "PASS\n\n";
}


void TestCountConstructor()
{
    std::cout << "[TestCountConstructor]\n";

    List<int> list(5, 10);

    assert(list.size() == 5);

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        assert(*it == 10);
    }

    std::cout << "PASS\n\n";
}


void TestClear()
{
    std::cout << "[TestClear]\n";

    List<int> list;

    for (int i = 0; i < 100; ++i)
        list.push_back(i);

    assert(list.size() == 100);

    list.clear();

    assert(list.empty());
    assert(list.size() == 0);

    // clear 후 다시 사용 가능한지도 확인
    list.push_back(123);

    assert(list.size() == 1);
    assert(list.front() == 123);
    assert(list.back() == 123);

    std::cout << "PASS\n\n";
}


int main()
{
    TestPushPop();
    TestIterator();
    TestInsert();
    TestErase();
    TestEraseRange();
    TestRemove();

    TestCopyConstructor();
    TestCopyAssignment();

    TestSelfCopyAssignment();

    TestMoveConstructor();
    TestMoveAssignment();

    TestInitializerList();
    TestCountConstructor();
    TestClear();

    std::cout << "====================\n";
    std::cout << "ALL TESTS PASSED\n";
    std::cout << "====================\n";
}