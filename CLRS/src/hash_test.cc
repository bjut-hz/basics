#include "util/testharness.h"
#include "util/basic.h"
#include "hash.h"


namespace CLRS {
	
class HashTest{};

TEST(HashTest, All) {
	HandleTable table;
	int key1 = 1;
	Handle* pos = table.Lookup(key1, Hash(key1));
	ASSERT_EQ(true, pos == nullptr);

	int key2 = 2;
	int val2 = 99;
	auto ret1 = table.Insert(key2, Hash(key2), val2);
	ASSERT_EQ(table.Lookup(key2, Hash(key2))->value, val2);

	auto ret2 = table.Insert(key2, Hash(key2), 1000);
	ASSERT_EQ(table.Lookup(key2, Hash(key2))->value, 1000);

	int key3 = 3;
	int val3 = 888;
	table.Insert(key3, Hash(key3), val3);
	table.Remove(key3, Hash(key3));

	auto h3 = table.Lookup(key3, Hash(key3));
	ASSERT_EQ(true, h3 == nullptr);
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}