#include "util/testharness.h"
#include "util/basic.h"
#include "binary_search_tree.h"
#include <iostream>

namespace CLRS {
	
class BSTTest{};

TEST(BSTTest, WithParentPointer) {
	BST bst;

	bst.Insert(12);
	bst.Insert(5);
	bst.Insert(18);
	bst.Insert(2);
	bst.Insert(9);
	bst.Insert(15);
	bst.Insert(19);
	bst.Insert(17);
	bst.Insert(13);

	ASSERT_EQ(12, bst.root()->val);
	ASSERT_EQ(2, bst.min()->val);
	ASSERT_EQ(19, bst.max()->val);
	ASSERT_EQ(true, bst.Successor(bst.max()) == nullptr);
	ASSERT_EQ(15, bst.Search(15)->val);

	ASSERT_EQ(bst.Successor(bst.root()), bst.Search(13));

	bst.Delete(bst.Search(12));
	ASSERT_EQ(13, bst.root()->val);
	ASSERT_EQ(true, nullptr == bst.Search(12));


	std::cout << bst.InorderTraverse() << std::endl;
};

TEST(BSTTest, NoParentPointer) {
	DS_C::BST bst;

	bst.Insert(12);
	bst.Insert(5);
	bst.Insert(18);
	bst.Insert(2);
	bst.Insert(9);
	bst.Insert(15);
	bst.Insert(19);
	bst.Insert(17);
	bst.Insert(13);
	
	ASSERT_EQ(2, bst.FindMin()->val);
	ASSERT_EQ(19, bst.FindMax()->val);

	ASSERT_EQ(15, bst.Find(15)->val);

	bst.Delete(12);
	ASSERT_EQ(true, nullptr == bst.Find(12));
	std::cout << bst.InorderTraverse() << std::endl;
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}