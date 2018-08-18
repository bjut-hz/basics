package list

import (
	"log"
	"bytes"
	"strconv"
)

// array implementation
// use dummy node
type Position int
type ArrayList struct {
	size int
	elements []int
}

func NewArrayList() *ArrayList {
	l := &ArrayList{size:0, elements:make([]int, 1)}
	l.elements[0] = 0
	return l
}

func (l *ArrayList) MakeEmpty() *ArrayList {
	l.size = 0
	return l
}

func (l *ArrayList) IsEmpty() bool {
	return 0 == l.size
}

func (l *ArrayList) IsLast(p Position) bool {
	return p == Position(l.size)
}

func (l *ArrayList) GetSize() int {
	return l.size
}

func (l *ArrayList) Find(x int) Position {
	for i := 1; i <= l.size; i++ {
		if x == l.elements[i] {
			return Position(i)
		}
	}
	return 0
}

func (l *ArrayList) Delete(x int) {
	idx := l.Find(x)
	if 0 == idx {
		log.Fatal("invalid x", x)
		return
	}

	for i := int(idx); i+1 <= l.size; i++ {
		l.elements[i] = l.elements[i+1]
	}
	l.size--
}

func (l *ArrayList) FindPrevious(x int) Position {
	for i := 0; i+1 <= l.size; i++ {
		if x == l.elements[i+1] {
			return Position(i)
		}
	}
	return 0
}

func (l *ArrayList) Insert(x int, p Position) {
	if l.size + 1 == len(l.elements) {
		// array is full. make space
		arr := make([]int, 2 * len(l.elements))
		copy(arr, l.elements)
		l.elements = arr
	}

	for i := l.size + 1; i-1 > int(p); i-- {
		l.elements[i] = l.elements[i-1]
	}
	l.elements[p+1] = x
	l.size++
}

func (l *ArrayList) Retrieve(p Position) int {
	return l.elements[p]
}

func (l *ArrayList) DumpList() string  {
	var b bytes.Buffer
	for i := 1; i <= l.size; i++ {
		b.WriteString(strconv.Itoa(l.elements[i]) + " ")
	}
	return b.String()
}

func DeleteList(l *ArrayList) {
	l.size = 0
	l.elements = nil
	l = nil
}

/*
 link list way
*/

type Element struct {
	next *Element
	Value interface{}
}

type LinkList struct {
	len int
	root Element
}

func NewLinkList() *LinkList {
	return new(LinkList).Init()
}

func (l *LinkList) Init() *LinkList {
	l.len = 0
	l.root.next = nil
	return l
}

func (l *LinkList) InsertFront(value interface{}) *Element {
}

func (l *LinkList) InsertAfter(value interface{}, at *Element) *Element {
}

func (l *LinkList) InsertBefore(value interface{}, at *Element) *Element {

}

func (l *LinkList) Find(value interface{}) *Element {

}

func (l *LinkList) Delete(at *Element) {

}