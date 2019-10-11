#include "util/testharness.h"
#include "util/basic.h"
#include "memento.h"

namespace DP {
	
class MementoTest{};

TEST(MementoTest, All) {
	auto origintor = std::make_shared<Originator>("state1", 99);
	origintor->SetHp(1000);
	origintor->SetState("70 years");

	auto care_taker = std::make_shared<Caretaker>();
	care_taker->memento = origintor->CreateMemento();

	std::cout << "====== old state: ======" << std::endl;
	origintor->Show();

	origintor->SetState("hello world");
	origintor->SetHp(999);

	std::cout << "====== update state: ======" << std::endl;
	origintor->Show();

	origintor->SetMemento(*(care_taker->memento));
	std::cout << "====== restore state: ======" << std::endl;
	origintor->Show();
};
} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}