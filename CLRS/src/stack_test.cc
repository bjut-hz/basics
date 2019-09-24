#include "util/testharness.h"
#include "util/basic.h"
#include "stack.h"


namespace CLRS {
	
class StackTest{};

TEST(StackTest, All) {
	Stack stk;
	ASSERT_EQ(true, stk.empty());

	stk.Push(1);
	stk.Push(2);
	ASSERT_EQ(2, stk.Pop());
	ASSERT_EQ(1, stk.Pop());
	ASSERT_EQ(true, stk.empty());

	// pop empty stack, exception test
	//stk.Pop();
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}