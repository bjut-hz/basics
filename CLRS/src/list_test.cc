#include "util/testharness.h"
#include "util/basic.h"
#include "list.h"
#include<algorithm>
#include<iostream>

namespace CLRS {
	
class ListTest{};

TEST(ListTest, InsertAndRemove) {
	List l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);

	ASSERT_EQ(true, l.Find(1));
	ASSERT_EQ(true, l.Find(2));

	l.Remove(3);
	ASSERT_EQ(false, l.Find(3));
};

TEST(ListTest, Iterator) {
	List l;
	l.Insert(1);
	l.Insert(4);
	l.Insert(3);

	std::for_each(l.begin(), l.end(), [](const auto& n) {
		std::cout << n << " ";
	});
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}