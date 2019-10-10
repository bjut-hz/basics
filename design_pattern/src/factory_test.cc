#include "util/testharness.h"
#include "util/basic.h"
#include "simple_factory.h"
#include "factory_method.h"
#include "abstract_factory.h"

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

TEST(FactoryTest, AbstractFactory) {
	std::shared_ptr<AbstractFacroty> factory = std::make_shared<ConcreteFactory1>();
	std::shared_ptr<AbstractProductA> p_a = factory->CreateProductA();
	std::shared_ptr<AbstractProductB> p_b = factory->CreateProductB();
	p_a->Display();
	p_b->Output();

	//直接更换工厂
	factory = std::make_shared<ConcreteFactory2>();
	p_a = factory->CreateProductA();
	p_b = factory->CreateProductB();
	p_a->Display();
	p_b->Output();
};

TEST(FactoryTest, AbstractFactoryOptimized) {
	std::shared_ptr<AbstractProductA> p_a = DataAccess::CreateProductA();
	std::shared_ptr<AbstractProductB> p_b = DataAccess::CreateProductB();
	p_a->Display();
	p_b->Output();

	DataAccess::type_ = Type::kB;
	p_a = DataAccess::CreateProductA();
	p_b = DataAccess::CreateProductB();
	p_a->Display();
	p_b->Output();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}