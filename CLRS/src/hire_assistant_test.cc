#include "util/testharness.h"
#include "util/basic.h"
#include "util/dump_vetor.h"
#include "hire_assistant.h"


#include<iostream>
namespace CLRS {
	
class HireAssistantTest{};

TEST(HireAssistantTest, All) {
	std::vector<int> nums = {1, 2, 3, 4};
	std::cout << "Before: " << Dump(nums);
	PermuteBySorting(nums);
	std::cout << "PermuteBySorting: " << Dump(nums) << std::endl;


	std::vector<int> A = {1, 2, 3, 4, 5};
	std::cout << "Before: " << Dump(A);
	RandomizeInPlace(A);
	std::cout << "RandomizeInPlace: " << Dump(A) << std::endl;

	std::vector<int> scores = {2, 4, 1, 33, 4, 3, 6, 77};
	std::cout<< "OnlineMaximum: " << OnlineMaximum(4, scores) << std::endl;
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}