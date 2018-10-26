package minStack

import "math"

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

	push(x) -- Push element x onto stack.
	pop() -- Removes the element on top of the stack.
	top() -- Get the top element.
	getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

type minStack struct {
	min int
	arr []int
}

type MinStack struct {
	stack *minStack
}

// fuck!!! should return *MinStack

/** initialize your data structure here. */
func Constructor() MinStack {
	ret := MinStack{}
	ret.stack = &minStack{min:math.MaxInt64, arr:make([]int, 0, 10)}
	return ret
}


func (this *MinStack) Push(x int)  {
	if x < this.stack.min {
		this.stack.min = x
	}

	this.stack.arr = append(this.stack.arr, x)
}


func (this *MinStack) Pop()  {
	N := len(this.stack.arr)
	if N == 0 {
		return
	}

	top := this.Top()
	// find the min
	if top == this.stack.min {
		this.stack.min = math.MaxInt64
		for i := 0; i < (N - 1); i++ {
			if this.stack.arr[i] < this.stack.min {
				this.stack.min = this.stack.arr[i]
			}
		}
	}

	this.stack.arr = this.stack.arr[0:(N-1)]
}


func (this *MinStack) Top() int {
	N := len(this.stack.arr)
	if N == 0 {
		return -1
	}
	return this.stack.arr[N - 1]
}


func (this *MinStack) GetMin() int {
	return this.stack.min
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */