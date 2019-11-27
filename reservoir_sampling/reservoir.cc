#include<vector>
#include<map>
#include<ctime>
#include<iostream>

std::vector<int> Reservoir(std::vector<int>& stream, int K) {
	std::vector<int> reservoir(K);

	for (int i = 0; i < K; ++i) {
		reservoir[i] = stream[i];
	}

	for (int i = K; i < stream.size(); ++i) {
		int idx = std::rand() % (i + 1);
		if (idx < K) {
			reservoir[idx] = stream[i];
		}
	}
	return reservoir;
}


// for test

int main() {
	const int kTimes = 100000;
	const int kStreamLen = 10;
	std::vector<int> stream(kStreamLen);
	for (int i = 0; i < kStreamLen; ++i) {
		stream[i] = i + 1;
	}

	std::srand(std::time(nullptr));
	std::map<int, int> m;

	int K = 1;
	const int diff = 500;

	auto generator = [&]() {
		for (int i = 0; i < kTimes; ++i) {
			auto ret = Reservoir(stream, K);
			for (auto& num : ret) {
				m[num]++;
			}
		}
	};

	auto checker = [&]() {
		int times = kTimes * ((double)K / kStreamLen);
		for (auto& ele : m) {
			if (abs(ele.second - times) > diff) {
				std::cout << ele.first << ": " << ele.second << std::endl;
			}
		}
	};

	generator();
	checker();


	m.clear();
	K = 9;
	generator();
	checker();
}