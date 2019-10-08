#include "util/testharness.h"
#include "util/basic.h"
#include "simple_factory.h"
#include "factory_method.h"

namespace DP {
	
class FactoryTest{};

TEST(FactoryTest, SimpleFacrtoryAdd) {
	IOperation* oper = OperationFactory::CreateOperation(IOperation::kAdd);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 + 3, oper->GetResult());

	delete oper;
};

TEST(FactoryTest, SimpleFacrtorySub) {
	IOperation* oper = OperationFactory::CreateOperation(IOperation::kSub);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 - 3, oper->GetResult());

	delete oper;
};

TEST(FactoryTest, SimpleFacrtoryMulti) {
	IOperation* oper = OperationFactory::CreateOperation(IOperation::kMulti);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 * 3, oper->GetResult());

	delete oper;
};

TEST(FactoryTest, SimpleFacrtoryDiv) {
	IOperation* oper = OperationFactory::CreateOperation(IOperation::kDiv);
	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(static_cast<NumberType>(2) / static_cast<NumberType>(3), oper->GetResult());

	delete oper;
};


TEST(FactoryTest, FactoryMethodAdd) {
	IFactory* factory = new AddFactory();
	IOperation* oper = factory->CreateOperation();

	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 + 3, oper->GetResult());

	delete oper;
	delete factory;
};

TEST(FactoryTest, FactoryMethodSub) {
	IFactory* factory = new SubFactory();
	IOperation* oper = factory->CreateOperation();

	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 - 3, oper->GetResult());

	delete oper;
	delete factory;
};

TEST(FactoryTest, FactoryMethodMulti) {
	IFactory* factory = new MultiFactory();
	IOperation* oper = factory->CreateOperation();

	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(2 * 3, oper->GetResult());

	delete oper;
	delete factory;
};

TEST(FactoryTest, FactoryMethodDiv) {
	IFactory* factory = new DivFactory();
	IOperation* oper = factory->CreateOperation();

	oper->lhs_ = 2;
	oper->rhs_ = 3;

	ASSERT_EQ(static_cast<NumberType>(2) / static_cast<NumberType>(3), oper->GetResult());

	delete oper;
	delete factory;
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}