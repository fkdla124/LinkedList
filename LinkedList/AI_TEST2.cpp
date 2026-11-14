#include <iostream>
#include <cassert>
#include <utility>
#include "List.h"

// AI가 짜준 테스트코드 

void TestEmptyMoveConstructor()
{
    std::cout << "[TestEmptyMoveConstructor]\n";

    List<int> src;

    List<int> dst(std::move(src));

    assert(dst.empty());
    assert(dst.size() == 0);

    assert(src.empty());
    assert(src.size() == 0);

    // move 후 source 재사용
    src.push_back(10);

    assert(src.size() == 1);
    assert(src.front() == 10);
    assert(src.back() == 10);

    // destination도 재사용
    dst.push_back(20);

    assert(dst.size() == 1);
    assert(dst.front() == 20);

    std::cout << "PASS\n\n";
}


void TestEmptyMoveAssignment()
{
    std::cout << "[TestEmptyMoveAssignment]\n";

    List<int> src;

    List<int> dst;

    dst.push_back(10);
    dst.push_back(20);
    dst.push_back(30);

    dst = std::move(src);

    assert(dst.empty());
    assert(dst.size() == 0);

    assert(src.empty());

    // 둘 다 다시 사용
    src.push_back(100);
    dst.push_back(200);

    assert(src.front() == 100);
    assert(dst.front() == 200);

    std::cout << "PASS\n\n";
}


void TestMoveIntoEmpty()
{
    std::cout << "[TestMoveIntoEmpty]\n";

    List<int> src;

    src.push_back(1);
    src.push_back(2);
    src.push_back(3);

    List<int> dst;

    dst = std::move(src);

    assert(dst.size() == 3);
    assert(dst.front() == 1);
    assert(dst.back() == 3);

    assert(src.empty());

    std::cout << "PASS\n\n";
}


void TestSelfMoveAssignment()
{
    std::cout << "[TestSelfMoveAssignment]\n";

    List<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list = std::move(list);

    // 정상적인 구현이라면 그대로 유지
    assert(list.size() == 3);
    assert(list.front() == 10);
    assert(list.back() == 30);

    int expected[] = { 10, 20, 30 };
    int index = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        assert(*it == expected[index]);
        index++;
    }

    std::cout << "PASS\n\n";
}


void TestRepeatedPushPop()
{
    std::cout << "[TestRepeatedPushPop]\n";

    List<int> list;

    for (int i = 0; i < 10000; ++i)
    {
        list.push_back(i);
    }

    assert(list.size() == 10000);

    for (int i = 0; i < 5000; ++i)
    {
        assert(list.front() == i);
        list.pop_front();
    }

    assert(list.size() == 5000);
    assert(list.front() == 5000);
    assert(list.back() == 9999);

    for (int i = 9999; i >= 5000; --i)
    {
        assert(list.back() == i);
        list.pop_back();
    }

    assert(list.empty());

    std::cout << "PASS\n\n";
}


void TestAlternatingPush()
{
    std::cout << "[TestAlternatingPush]\n";

    List<int> list;

    for (int i = 0; i < 1000; ++i)
    {
        if (i % 2 == 0)
            list.push_front(i);
        else
            list.push_back(i);
    }

    assert(list.size() == 1000);

    // size만 보는 게 아니라 실제 traversal도 확인
    int count = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        count++;
    }

    assert(count == 1000);

    std::cout << "PASS\n\n";
}


void TestEraseEverything()
{
    std::cout << "[TestEraseEverything]\n";

    List<int> list;

    for (int i = 0; i < 1000; ++i)
        list.push_back(i);

    while (!list.empty())
    {
        list.erase(list.begin());
    }

    assert(list.empty());
    assert(list.size() == 0);

    // 완전히 비운 후 다시 사용
    list.push_back(123);

    assert(list.size() == 1);
    assert(list.front() == 123);
    assert(list.back() == 123);

    std::cout << "PASS\n\n";
}


void TestEraseBackwards()
{
    std::cout << "[TestEraseBackwards]\n";

    List<int> list;

    for (int i = 0; i < 100; ++i)
        list.push_back(i);

    while (!list.empty())
    {
        auto it = list.end();
        --it;

        assert(*it == static_cast<int>(list.size() - 1));

        list.erase(it);
    }

    assert(list.empty());

    std::cout << "PASS\n\n";
}


void TestInsertAtEveryPosition()
{
    std::cout << "[TestInsertAtEveryPosition]\n";

    List<int> list;

    list.push_back(0);
    list.push_back(4);

    auto it = list.begin();
    ++it;

    list.insert(it, 1);

    it = list.begin();
    ++it;
    ++it;

    list.insert(it, 2);

    it = list.begin();
    ++it;
    ++it;
    ++it;

    list.insert(it, 3);

    int expected[] = { 0, 1, 2, 3, 4 };

    int index = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
    {
        assert(*i == expected[index]);
        index++;
    }

    assert(index == 5);

    std::cout << "PASS\n\n";
}


void TestInsertCount()
{
    std::cout << "[TestInsertCount]\n";

    List<int> list;

    list.push_back(1);
    list.push_back(5);

    auto it = list.begin();
    ++it;

    list.insert(it, 3, 2);

    int expected[] = { 1, 2, 2, 2, 5 };

    int index = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
    {
        assert(*i == expected[index]);
        index++;
    }

    assert(list.size() == 5);

    std::cout << "PASS\n\n";
}


void TestInitializerInsert()
{
    std::cout << "[TestInitializerInsert]\n";

    List<int> list;

    list.push_back(1);
    list.push_back(5);

    auto it = list.begin();
    ++it;

    list.insert(it, { 2, 3, 4 });

    int expected[] = { 1, 2, 3, 4, 5 };

    int index = 0;

    for (auto i = list.begin(); i != list.end(); ++i)
    {
        assert(*i == expected[index]);
        index++;
    }

    std::cout << "PASS\n\n";
}


void TestRangeInsert()
{
    std::cout << "[TestRangeInsert]\n";

    List<int> src;

    src.push_back(1);
    src.push_back(2);
    src.push_back(3);

    List<int> dst;

    dst.push_back(10);
    dst.push_back(20);

    dst.insert(dst.end(), src.begin(), src.end());

    int expected[] = { 10, 20, 1, 2, 3 };

    int index = 0;

    for (auto it = dst.begin(); it != dst.end(); ++it)
    {
        assert(*it == expected[index]);
        index++;
    }

    assert(dst.size() == 5);

    std::cout << "PASS\n\n";
}


void TestSelfRangeInsert()
{
    std::cout << "[TestSelfRangeInsert]\n";

    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    auto first = list.begin();       // 1
    auto last = list.end();

    auto where = list.begin();
    ++where;                          // 2

    list.insert(where, first, last);

    // 이 테스트는 네 range insert 구현의 핵심 공격 포인트
    // 결과가 네가 의도한 semantics와 맞는지 확인해야 함.

    std::cout << "result: ";

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << ' ';

    std::cout << "\n";

    std::cout << "PASS (manual inspection)\n\n";
}


void TestCopyAfterMove()
{
    std::cout << "[TestCopyAfterMove]\n";

    List<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    List<int> b(std::move(a));

    List<int> c(b);

    assert(b.size() == 3);
    assert(c.size() == 3);

    assert(b.front() == 1);
    assert(c.front() == 1);

    b.front() = 999;

    assert(c.front() == 1);

    std::cout << "PASS\n\n";
}


void TestMoveAfterCopy()
{
    std::cout << "[TestMoveAfterCopy]\n";

    List<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    List<int> b(a);

    List<int> c(std::move(b));

    assert(a.size() == 3);
    assert(b.empty());
    assert(c.size() == 3);

    assert(a.front() == 1);
    assert(c.front() == 1);

    std::cout << "PASS\n\n";
}


void TestClearRepeatedly()
{
    std::cout << "[TestClearRepeatedly]\n";

    List<int> list;

    for (int round = 0; round < 100; ++round)
    {
        for (int i = 0; i < 100; ++i)
            list.push_back(i);

        assert(list.size() == 100);

        list.clear();

        assert(list.empty());
        assert(list.size() == 0);
    }

    std::cout << "PASS\n\n";
}

int main()
{
    TestEmptyMoveConstructor();
    TestEmptyMoveAssignment();
    TestMoveIntoEmpty();
    TestSelfMoveAssignment();

    TestRepeatedPushPop();
    TestAlternatingPush();

    TestEraseEverything();
    TestEraseBackwards();

    TestInsertAtEveryPosition();
    TestInsertCount();
    TestInitializerInsert();
    TestRangeInsert();

    TestSelfRangeInsert();

    TestCopyAfterMove();
    TestMoveAfterCopy();

    TestClearRepeatedly();

    std::cout << "====================\n";
    std::cout << "ALL TESTS PASSED\n";
    std::cout << "====================\n";
}