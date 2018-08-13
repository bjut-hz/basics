package sort

import "math"

// arr: array to sort
// P: exponent
// R: number of bucket, radix number
func RadixSort(arr []int, P int, R int) {
	type Node struct {
		element int
		next *Node
	}

	buckets := make([]*Node, R)
	// init dummy list
	for i := 0; i < len(buckets); i++ {
		buckets[i] = &Node{element:0, next:nil}
	}

	// first pass, read arr into buckets, link list use dummy node
	for _, v := range arr {
		node := &Node{element:v, next:nil}
		node.next = buckets[v%R].next
		buckets[v%R].next = node
	}

	for i := 1; i < P; i++ {
		for j, list := range buckets {
			if list.next == nil { // empty list
				continue
			} else {
				prev, node := list, list.next
				for ; nil != node; {
					base := math.Pow(float64(R), float64(i))
					quotient := node.element / int(base)

					remainder := quotient % R
					if remainder == j {
						prev = prev.next
						node = node.next
					} else {
						tmp := node
						prev.next = node.next
						node = prev.next
						tmp.next = nil
						l2 := buckets[remainder]

						if remainder > j {
							// insert in the front
							tmp.next = l2.next
							l2.next = tmp
						} else {
							// insert in the back
							ptr := l2
							for ; nil != ptr.next; ptr = ptr.next {}

							ptr.next = tmp
							tmp.next = nil
						}
					}
				}
			}
		}
	}

	i := 0
	for _, l := range buckets {
		for node := l.next; nil != node; node = node.next {
			arr[i] = node.element
			i++
		}
	}
}