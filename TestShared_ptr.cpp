#include "Shared_ptr.h"
#include "TestShared_ptr.h"
#include "Swap.h"
#include "Move.h"

#include <cassert>
#include <string>

void TestShared_ptr::allTests()
{
	testConstructors();
	testDestructor();
	testAssignmentOperator();
	testMoveAssignmentOperator();
	testMakeShared();
	testOperators();
	testCompareOperators();
	testReset();
	testSwap();
	testMove();
}
void TestShared_ptr::testConstructors()
{
	shared_ptr<int> testShared_ptr1 = shared_ptr<int>(new int(20));
	assert(*testShared_ptr1 == 20);
	assert(testShared_ptr1.shareCount() == 1);

	shared_ptr<int> testShared_ptr2 = testShared_ptr1;
	assert(*testShared_ptr2 == 20);
	assert(testShared_ptr1 == testShared_ptr2);
	assert(testShared_ptr2.shareCount() == 2);

	shared_ptr<int> testShared_ptr3 = shared_ptr<int>(new int(10));
	shared_ptr<int> testShared_ptr4 = shared_ptr<int>(move(testShared_ptr3));
	assert(*testShared_ptr4 == 10);
	assert(testShared_ptr4.shareCount() == 1);
	assert(testShared_ptr3.isFree() == true);
}
void TestShared_ptr::testDestructor()
{
	int* testInt = new int(10);
	{
		shared_ptr<int> testShared_ptr1 = shared_ptr<int>(testInt);
		assert(*testShared_ptr1 == 10);
		assert(testShared_ptr1.shareCount() == 1);
		{
			shared_ptr<int> testShared_ptr2 = testShared_ptr1;
			assert(*testShared_ptr2 == 10);
			assert(testShared_ptr2.shareCount() == 2);
		}
		assert(testShared_ptr1.shareCount() == 1);
	}
}
void TestShared_ptr::testAssignmentOperator()
{
	shared_ptr<int> testShared_ptr1 = shared_ptr<int>(new int(10));
	assert(*testShared_ptr1 == 10);
	assert(testShared_ptr1.shareCount() == 1);
	shared_ptr<int> testShared_ptr2 = shared_ptr<int>(new int(20));
	assert(*testShared_ptr2 == 20);
	assert(testShared_ptr2.shareCount() == 1);
	testShared_ptr1 = testShared_ptr2;
	assert(*testShared_ptr1 == 20);
	assert(*testShared_ptr1 == *testShared_ptr2);
	assert(testShared_ptr1.shareCount() == testShared_ptr2.shareCount());
	assert(testShared_ptr1.shareCount() == 2);
}
void TestShared_ptr::testMoveAssignmentOperator()
{
	shared_ptr<int> testShared_ptr1 = shared_ptr<int>(new int(10));
	assert(*testShared_ptr1 == 10);
	assert(testShared_ptr1.shareCount() == 1);
	shared_ptr<int> testShared_ptr2 = shared_ptr<int>(new int(20));
	assert(*testShared_ptr2 == 20);
	assert(testShared_ptr2.shareCount() == 1);
	testShared_ptr1 = shared_ptr<int>(move(testShared_ptr2));
	assert(*testShared_ptr1 == 20);
	assert(testShared_ptr1.shareCount() == 1);
	assert(testShared_ptr2.isFree() == true);
}
void TestShared_ptr::testMakeShared()
{
	shared_ptr<int> testShared_ptr1 = make_shared<int>(10);
	assert(*testShared_ptr1 == 10);
	assert(testShared_ptr1.shareCount() == 1);
}
void TestShared_ptr::testOperators()
{
	int* testInt = new int(10);
	shared_ptr<int> testShared_ptr1 = shared_ptr<int>(testInt);
	assert(*testShared_ptr1 == 10);

	auto testShared_ptr2 = make_shared<std::string>(3, 'b');
	assert(testShared_ptr2->length() == 3);
}
void TestShared_ptr::testCompareOperators()
{
	shared_ptr<int> testShared_ptr = shared_ptr<int>();
	assert(testShared_ptr == nullptr);
}
void TestShared_ptr::testReset()
{
	int* testInt = new int(10);
	shared_ptr<int> testShared_ptr = shared_ptr<int>(testInt);
	assert(*testShared_ptr == 10);
	assert(testShared_ptr.shareCount() == 1);
	testShared_ptr.reset();
	assert(testShared_ptr.isFree() == true);
}
void TestShared_ptr::testSwap()
{
	int a = 5;
	int b = 10;
	my_swap(a, b);
	assert(b == 5);
	assert(a == 10);
}
void TestShared_ptr::testMove()
{
	int a = 5;
	int b = 10;
	a = move(b);
	assert(a == 10);
	assert(b == 10);
}
