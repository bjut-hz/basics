#include "util/testharness.h"
#include "util/basic.h"
#include "suqare_matrix_multiply.h"

#include<iostream>
#include<sstream>
#include<string>

namespace CLRS {
	
class SquateMatrixMulitplyTest{
	public:
	std::string DumpMatrix(std::vector<std::vector<int>>& in){
		std::ostringstream os;
		for(int i = 0; i < in.size(); ++i) {
			for(int j = 0; j < in[0].size(); ++j) {
				os << in[i][j] << " ";
			}
			os << "\n";
		}

		return os.str();
	}
};

TEST(SquateMatrixMulitplyTest, All) {
	std::vector<std::vector<int>> A = {
		//{1, 1, 1, 1},
		//{1, 1, 1, 1},
		//{1, 1, 1, 1},
		//{1, 1, 1, 1},
		{1, 1},
		{1, 1},

	};
	std::vector<std::vector<int>> B = {
		{1, 1},
		{1, 1},
	};

	auto result = SquareMatrixMultiply(A, B);
	std::cout << DumpMatrix(*result) << std::endl;

	int A_idx[4] = {0, 0, A.size()-1, A.size() - 1};
	int B_idx[4] = {0, 0, B.size()-1, B.size() - 1};
	std::cout << DumpMatrix(SquareMatrixMultiplyRecursive(A, B, A_idx, B_idx)) << std::endl;


	delete result;
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}