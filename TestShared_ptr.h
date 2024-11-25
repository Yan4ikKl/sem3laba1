#pragma once

class TestShared_ptr
{
public:
	void allTests();
	void testConstructors();
	void testDestructor();
	void testAssignmentOperator();
	void testMoveAssignmentOperator();
	void testMakeShared();
	void testOperators();
	void testCompareOperators();
	void testReset();
	void testSwap();
	void testMove();
};