package LRUCache


import (
	"testing"
	"fmt"
)

func TestReversePairs(t *testing.T) {
	lruCache := Constructor(2)

	lruCache.Put(2, 1)
	fmt.Println(lruCache.DumpList())
	lruCache.Put(1, 1)
	fmt.Println(lruCache.DumpList())

	lruCache.Put(2, 3)
	fmt.Println(lruCache.DumpList())

	lruCache.Put(4, 1)
	fmt.Println(lruCache.DumpList())

	fmt.Println(lruCache.Get(1))
	fmt.Println(lruCache.Get(2))


	//lruCache.Put(2, 6)
	//fmt.Println(lruCache.Get(1))
	//
	//lruCache.Put(1, 5)
	//lruCache.Put(1, 2)
	//fmt.Println(lruCache.Get(1))
	//
	//fmt.Println(lruCache.Get(2))
}