#include "util/testharness.h"
#include "util/basic.h"
#include "redblack.h"
#include<iostream>


namespace CLRS {
	
class RedBlackTest{};

TEST(RedBlackTest, All) {
	auto redblack = New();

	const int N = 14;
	int ele[N] = {7, 4, 11, 3, 6, 9, 18, 2, 14, 19, 12, 17, 22, 20};
	RedBlackNode* nodes[N];
	for (int i = 0; i < N; ++i) {
		nodes[i] = new RedBlackNode();
		nodes[i]->key = ele[i];

		Insert(redblack, nodes[i]);
	}

	ASSERT_EQ(redblack.root->key, 7);
	
	ASSERT_EQ(Minimum(redblack, redblack.root)->key, 2);

	Delete(redblack, nodes[7]);
	ASSERT_EQ(Minimum(redblack, redblack.root)->key, 3);


	Delete(redblack, nodes[0]);
	Delete(redblack, nodes[1]);
	Delete(redblack, nodes[2]);
	Delete(redblack, nodes[13]);

	std::cout << InorderTraverse(redblack) << std::endl;

	Destroy(redblack);
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}