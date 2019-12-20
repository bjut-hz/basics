#include "thread_safe_hash_map.h"
#include <chrono>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <atomic>

class TimeElapse {
public:
	explicit TimeElapse(std::string name) {
		std::cout << "=========== " << name << " begin ===========" << std::endl;
		start_ = std::chrono::system_clock::now();
		name_ = name;
	}

	~TimeElapse() {
		auto end = std::chrono::system_clock::now();

		std::cout << name_ << "  Summary: " << (end - start_).count() << " tick count. " 
			<< std::chrono::duration_cast<std::chrono::seconds>(end - start_).count() << " seconds" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::system_clock>			start_;
	std::string													name_;
};

#define THREAD_NUM 12
std::vector<std::vector<std::pair<std::shared_ptr<std::string>, std::shared_ptr<std::string>>>> fake_data(THREAD_NUM);
// for normal test
std::unordered_map<std::shared_ptr<std::string>, std::shared_ptr<std::string>> m;
HashMap<std::shared_ptr<std::string>, std::shared_ptr<std::string>> hash_map;
ConcurrentHashMap<std::shared_ptr<std::string>, std::shared_ptr<std::string>> concurrent_map;

// control the test routine flow
std::atomic_int flag = { 0 };

// cause exception occur
void TestNormalHashMap() {
	auto tmp = TimeElapse("TestNormalHashMap");
	std::thread pids[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i] = std::thread(
			[idx = i]() {
				for (auto& p : fake_data[idx]) {
					m[p.first] = p.second;
				}
			}
		);
	}

	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i].join();
	}
}

void TestThreadSafeHashMap() {
	auto tmp = TimeElapse("TestThreadSafeHashMap");
	std::thread pids[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i] = std::thread(
			[idx = i]() {
			for (auto& p : fake_data[idx]) {
				hash_map.Insert(p.first, p.second);
			}
		}
		);
	}
	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i].join();
	}

	flag.store(2);
}

void TestConcurrentHashMap() {
	auto tmp = TimeElapse("TestConcurrentHashMap");
	std::thread pids[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i] = std::thread(
			[idx = i]() {
			for (auto& p : fake_data[idx]) {
				concurrent_map.Insert(p.first, p.second);
			}
		}
		);
	}

	for (int i = 0; i < THREAD_NUM; ++i) {
		pids[i].join();
	}
}

std::string RandomString() {
	std::ostringstream os;
	int len = std::rand() % 10;
	for (int i = 0; i < len; ++i) {
		char ch = 'a' + std::rand() % 26;
		os << ch;
	}
	return os.str();
}

int main() {
	// fake data init
	std::srand(std::time(nullptr));

	{
		auto tmp = TimeElapse("fake data init");
		for (int i = 0; i < THREAD_NUM; ++i) {
			for (int j = 0; j < 500000; ++j) {
				std::pair<std::shared_ptr<std::string>, std::shared_ptr<std::string>> p;
				p.first = std::make_shared<std::string>(RandomString());
				p.second = std::make_shared<std::string>(RandomString());

				fake_data[i].emplace_back(p);
			}
		}

		flag.store(1);
	}


	//TestNormalHashMap();
	// check data


	TestThreadSafeHashMap();

	while (flag.load() == 1) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	// check data


	TestConcurrentHashMap();
	// check data

}