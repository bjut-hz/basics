#include "chan.h"
#include <iostream>
#include <string>


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
		ch.Send(100);
	});

	auto x = ch.Recv();
	assert(x == 99);
	sender.join();
}

void TestSendClosedBuffered() {
	chan<int, 1> ch;
	ch.Send(1);
	ch.Close();
	assert(ch.closed() == true);

	try {
		ch.Send(2);
	} catch (ClosedChannelException& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void TestRecvClosedBuffered() {
	chan<int, 1> ch;
	ch.Send(1);
	assert(1 == ch.Recv());

	ch.Close();
	assert(ch.closed() == true);
	assert(0 == ch.Recv());
}

void TestChanSendUnbuffered() {
	chan<int> ch;
	std::thread receiver([&](){
		auto data = ch.Recv();
	});

	auto wait_for_reader = [&](){
		for(;;) {
			bool send = false;
			{
				std::lock_guard<std::mutex> lock(ch.mu_);
				send = ch.r_waiting_ > 0;
			}
			if(send) break;
			std::this_thread::yield();
		}
	};
	wait_for_reader();

	assert(ch.size() == 0);
	assert(ch.w_waiting_ == 0);
	ch.Send(99);
	assert(ch.w_waiting_ == 0);
	assert(ch.size() == 0);

	receiver.join();
}

void TestChanRecvUnbuffered() {
	chan<std::string> ch;
	std::thread sender([&]() {
		ch.Send("hello");
	});
	assert("hello" == ch.Recv());
	sender.join();
}

void TestSendClosedUnbuffered() {
	chan<int> ch;
	ch.Close();
	try {
		ch.Send(1);
	} catch (ClosedChannelException& ex) {
		std::cout << ex.what();
	}
}

void TestRecvClosedUnbuffered() {
	chan<int> ch;

	std::thread sender([&]() {
		ch.Send(1);
		ch.Close();
	});

	auto wait_for_sender = [&]() {
		for (;;) {
			bool recv = false;
			{
				std::lock_guard<std::mutex> lock(ch.mu_);
				recv = ch.w_waiting_ > 0;
			}
			if (recv) break;
			std::this_thread::yield();
		}
	};

	wait_for_sender();

	
	int a = ch.Recv();
	int b = ch.Recv(); // get default value
	assert(a == 1);
	assert(b == 0);
	sender.join();
}

int main() {
	TestChanSendBuffered();
	TestChanRecvBuffered();
	TestSendClosedBuffered();
	TestRecvClosedBuffered();
	TestChanSendUnbuffered();
	TestChanRecvUnbuffered();
	TestSendClosedUnbuffered();
	TestRecvClosedUnbuffered();
}