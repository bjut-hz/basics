package list

import (
	"testing"
	"fmt"
)

func TestArrayList(t *testing.T) {
	l := NewArrayList()
	l.Insert(10, 0)
	if l.Retrieve(1) != 10 {
		t.Fail()
	}

	l.Insert(9, 0)
	l.Insert(8, 0)

	if !l.IsLast(l.Find(10)) {
		fmt.Print(l.Find(10))
		t.Fail()
	}

	if l.Retrieve(l.Find(8)) != 8 {
		t.Fatal("error")
	}

	l.Delete(9)

	DeleteList(l)
}


func TestLinkList(t *testing.T) {
	l := NewLinkList()
	pos := l.PushFront(1)
	pos = l.PushFront(2)

	// test FindPrevious
	if l.FindPrevious(1).Value != pos.Value {
		t.Fail()
	}

	l.Insert(3, pos)

	fmt.Println(l.DumpLinkList(), l.len)
	l.Delete(1)
	fmt.Println(l.DumpLinkList(), l.len)

	// error prone, pos should be nil if delete element 2.
	l.Insert("hello", pos)
	fmt.Println(l.DumpLinkList(), l.len)
}