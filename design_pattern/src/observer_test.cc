#include "util/testharness.h"
#include "util/basic.h"
#include "observer.h"

namespace DP {
	
class ObserverTest{};

TEST(ObserverTest, All) {
#ifndef USE_DELEGATE
	std::shared_ptr<ConcreteSubject> subject = std::make_shared<ConcreteSubject>();

	subject->Attatch(std::make_shared<ConcreteObserver>(subject, 1));
	subject->Attatch(std::make_shared<ConcreteObserver>(subject, 2));

	subject->SetSubject("PLC 70 anniversary!");
	subject->Notify();

#else

	std::shared_ptr<Subject> subject = std::make_shared<Subject>();

	ObserverA a(subject);
	ObserverB b(subject);
	// use different function name
	subject->Update.connect(Simple::slot(a, &ObserverA::UpdateA));
	subject->Update.connect(Simple::slot(b, &ObserverB::UpdateB));

	subject->SetSubject("PLC 70 anniversary!");
	subject->Notify();

#endif // !USE_DELEGATE

};


} // namespace DP



int main() {
	auto ret = DP::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}