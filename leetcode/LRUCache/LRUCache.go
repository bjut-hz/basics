package LRUCache

import (
	"bytes"
	"fmt"
)

// use two-way linked list and map
type node struct {
	key int
	value int
	prev *node
	next *node
}

type lru struct {
	hashMap map[int]*node // accelerate searching
	root node //sentinel node
	capacity int
}

type LRUCache struct {
	lru *lru
}


func Constructor(capacity int) LRUCache {
	cache := LRUCache{lru:&lru{}}
	cache.lru.hashMap = make(map[int]*node, capacity)

	cache.lru.root.prev = &cache.lru.root
	cache.lru.root.next = &cache.lru.root
	cache.lru.capacity = capacity

	//fmt.Printf("\n### %p\n", &cache.root)
	return cache
}


func (this *LRUCache) Get(key int) int {
	if v, ok := this.lru.hashMap[key]; ok {
		// move at the front
		e := this.lru.hashMap[key]
		this.remove(e)
		this.insert(e, &this.lru.root)

		return v.value
	}
	return -1
}

func (this *LRUCache) insert(e, at *node) {
	n := at.next
	e.prev = at
	at.next = e

	e.next = n
	n.prev = e
}

func (this *LRUCache) remove(e *node) {
	e.prev.next = e.next
	e.next.prev = e.prev

	e.prev = nil
	e.next = nil
}

func (this *LRUCache) Put(key int, value int)  {
	if e, ok := this.lru.hashMap[key]; ok {
		// node exist
		e.value = value
		this.Get(key)
		return
	}

	if len(this.lru.hashMap) == this.lru.capacity {
		// delete least recent used node
		tail := this.lru.root.prev
		this.remove(tail)
		delete(this.lru.hashMap, tail.key)
	}

	e := &node{key:key, value:value}
	this.insert(e, &this.lru.root)
	this.lru.hashMap[key] = e
}



func (this *LRUCache) DumpList() string {

	var b bytes.Buffer

	for e, i := &this.lru.root, 0; i <= len(this.lru.hashMap); e, i = e.next, i + 1 {
		b.WriteString(fmt.Sprintf("(%v: %v) ", e.key, e.value))
	}
	return b.String()
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */