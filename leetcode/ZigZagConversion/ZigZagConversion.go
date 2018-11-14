package ZigZagConversion

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/


//(1)第一行和最后一行下标间隔都是interval = n*2-2 = 8 ;
//(2)中间行的间隔是周期性的,第i行的间隔是: interval–2*i,  2*i,  interval–2*i, 2*i, interval–2*i, 2*i, …

func convert(s string, numRows int) string {
	if numRows <= 1 { return s }

	interval := 2 * numRows - 2
	N := len(s)
	result := ""

	//first row
	for i := 0; i < N; i += interval {
		result += s[i:i+1]
	}
	// middle rows
	for i := 1; i <(numRows - 1); i++ {
		inter := 2 * i
		for j := i; j < N; j += inter {
			result += s[j:j+1]
			inter = interval - inter
		}
	}

	// last line
	for i := numRows - 1; i < N; i += interval {
		result += s[i:i+1]
	}

	return result
}