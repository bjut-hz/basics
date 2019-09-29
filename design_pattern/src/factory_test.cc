#include "util/testharness.h"
#include "util/basic.h"
#include "simple_factory.h"

namespace DP {
	
class SingleFactoryTest{};

TEST(SingleFactoryTest, Add) {
	Operation* oper = OperationFactory::CreateOperation(Operation::kAdd);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 + 3, oper->GetResult());

	delete oper;
};

TEST(SingleFactoryTest, Sub) {
	Operation* oper = OperationFactory::CreateOperation(Operation::kSub);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 - 3, oper->GetResult());

	delete oper;
};

TEST(SingleFactoryTest, Multi) {
	Operation* oper = OperationFactory::CreateOperation(Operation::kMulti);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 * 3, oper->GetResult());

	delete oper;
};

TEST(SingleFactoryTest, Div) {
	Operation* oper = OperationFactory::CreateOperation(Operation::kDiv);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(static_cast<NumberType>(2) / static_cast<NumberType>(3), oper->GetResult());

	delete oper;
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}