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