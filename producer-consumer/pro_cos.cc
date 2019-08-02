#include<iostream>
#include<vector>

#include "semaphore.h"

#define N 10

Semaphore empty(N);
Semaphore full(0);

// guard buffer
std::mutex mu;
int buffer[N];
int i = 0;


void Producer() {
	int counter = 0;
	while (true) {
		empty.P();
		{
			std::unique_lock<std::mutex> lock(mu);
			buffer[i++] = counter;

			std::cout << "Producer " << std::this_thread::get_id() << ": " << counter << std::endl;
			counter++;
		}
		full.V();

		if (counter == N) {
			break;
		}
	}

}

void Consumer() {
	while (true) {
		full.P();
		{
			std::unique_lock<std::mutex> lock(mu);
			std::cout << "Consumer " << std::this_thread::get_id() << ": " << buffer[--i] << std::endl;
		}
		empty.V();
	}


}


int main(){
	const int p_num = 3;
	const int c_num = 5;

	std::thread p_pid[p_num];
	std::thread c_pid[c_num];
	for (int i = 0; i < p_num; ++i) {
		p_pid[i] = std::thread(Producer);
	}

	for(int i = 0; i < c_num; ++i) {
		c_pid[i] = std::thread(Consumer);
	}


	for(int i = 0; i < p_num; ++i) {
		p_pid[i].join();
	}
	for (int i = 0; i < c_num; ++i) {
		c_pid[i].join();
	}
}