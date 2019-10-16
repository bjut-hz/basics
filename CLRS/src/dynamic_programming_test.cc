#include "util/testharness.h"
#include "util/basic.h"
#include "dynamic_programming.h"

namespace CLRS {
	
class CutRodTest{
public:
	std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
};

TEST(CutRodTest, CutRod) {
	ASSERT_EQ(1, CutRod(price, 1));
	ASSERT_EQ(5, CutRod(price, 2));
	ASSERT_EQ(8, CutRod(price, 3));
	ASSERT_EQ(10, CutRod(price, 4));
	ASSERT_EQ(13, CutRod(price, 5));
	ASSERT_EQ(17, CutRod(price, 6));
	ASSERT_EQ(18, CutRod(price, 7));
	ASSERT_EQ(22, CutRod(price, 8));
	ASSERT_EQ(25, CutRod(price, 9));
	ASSERT_EQ(30, CutRod(price, 10));
};

TEST(CutRodTest, MemoizedCutRod) {
	ASSERT_EQ(1, MemoizedCutRod(price, 1));
	ASSERT_EQ(5, MemoizedCutRod(price, 2));
	ASSERT_EQ(8, MemoizedCutRod(price, 3));
	ASSERT_EQ(10, MemoizedCutRod(price, 4));
	ASSERT_EQ(13, MemoizedCutRod(price, 5));
	ASSERT_EQ(17, MemoizedCutRod(price, 6));
	ASSERT_EQ(18, MemoizedCutRod(price, 7));
	ASSERT_EQ(22, MemoizedCutRod(price, 8));
	ASSERT_EQ(25, MemoizedCutRod(price, 9));
	ASSERT_EQ(30, MemoizedCutRod(price, 10));
};

TEST(CutRodTest, BottomUpCutRod) {
	ASSERT_EQ(1, BottomUpCutRod(price, 1));
	ASSERT_EQ(5, BottomUpCutRod(price, 2));
	ASSERT_EQ(8, BottomUpCutRod(price, 3));
	ASSERT_EQ(10, BottomUpCutRod(price, 4));
	ASSERT_EQ(13, BottomUpCutRod(price, 5));
	ASSERT_EQ(17, BottomUpCutRod(price, 6));
	ASSERT_EQ(18, BottomUpCutRod(price, 7));
	ASSERT_EQ(22, BottomUpCutRod(price, 8));
	ASSERT_EQ(25, BottomUpCutRod(price, 9));
	ASSERT_EQ(30, BottomUpCutRod(price, 10));
};

TEST(CutRodTest, PrintCutRodSolution) {
	ASSERT_EQ(1, PrintCutRodSolution(price, 1));
	ASSERT_EQ(5, PrintCutRodSolution(price, 2));
	ASSERT_EQ(8, PrintCutRodSolution(price, 3));
	ASSERT_EQ(10, PrintCutRodSolution(price, 4));
	ASSERT_EQ(13, PrintCutRodSolution(price, 5));
	ASSERT_EQ(17, PrintCutRodSolution(price, 6));
	ASSERT_EQ(18, PrintCutRodSolution(price, 7));
	ASSERT_EQ(22, PrintCutRodSolution(price, 8));
	ASSERT_EQ(25, PrintCutRodSolution(price, 9));
	ASSERT_EQ(30, PrintCutRodSolution(price, 10));
};

class OrderTest{
public:
	std::vector<int> p = {30, 35, 15, 5, 10, 20, 25}; // matrix size
};

TEST(OrderTest, All) {
	auto n = p.size() - 1;
	std::vector<std::vector<int>> m(n, std::vector<int>(n, INT_MAX));
	std::vector<std::vector<int>> s(n, std::vector<int>(n, INT_MAX));
	MatrixChainOrder(p, m, s);
	int matrix_a = 1;
	int matrix_b = 3;
	std::cout << "multiply times: " << m[matrix_a][matrix_b] << std::endl << "order: ";
	PrintOptimalParens(s, matrix_a, matrix_b);
	std::cout << std::endl;
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}