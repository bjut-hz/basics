#include "util/testharness.h"
#include "util/basic.h"
#include "queue.h"


namespace CLRS {
	
class QueueTest{};

TEST(QueueTest, LimitedQueue) {
	LimitedQueue queue;
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	// enqueue full queue test
	// queue.Enqueue(4);

	ASSERT_EQ(1, queue.Dequeue());
	ASSERT_EQ(2, queue.Dequeue());
	ASSERT_EQ(3, queue.Dequeue());

	// dequeue empty queue test
	// queue.Dequeue();
};


TEST(QueueTest, Queue) {
	Queue queue;
	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	ASSERT_EQ(1, queue.Dequeue());
	ASSERT_EQ(2, queue.Dequeue());
	ASSERT_EQ(3, queue.Dequeue());

	// dequeue empty queue test
	// queue.Dequeue();
};
} // namespace CLRS



int main() {
	auto ret = CLRS::test::RunAllTests();

	// memory leak check, put it as last one sentence 
	_CrtDumpMemoryLeaks();
	return ret;
}