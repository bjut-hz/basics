#include "shared_ptr.h"

struct Test {
	int a = 1;

	Test(int a) {
		this->a = a;
	}
};

shared_ptr<Test> func() {
	return make_shared<Test>(3);
}

int main() {
	{
		shared_ptr<Test> a = make_shared<Test>(1);

		shared_ptr<Test> b = a;
		b = func();
	}


	_CrtDumpMemoryLeaks();
}