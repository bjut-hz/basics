#include "chan.h"
#include <iostream>
void TestChanSendBuffered() {
	chan<int, 1> ch;
	assert(ch.size() == 0);

	ch.Send(1);
	assert(ch.size() == 1);
}

void TestChanRecvBuffered() {
	chan<int, 1> ch;
	std::thread sender([&]() {
		ch.Send(99);
		std::cout << "send 99" << std::endl;
		ch.Send(100);
		std::cout << "send 100" << std::endl;
	});

	auto x = ch.Recv();
	assert(x == 99);
	sender.join();
}

int main() {
	//TestChanSendBuffered();
	TestChanRecvBuffered();
}