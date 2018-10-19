package longestSubstringWithoutRepeatingCharacters

// https://www.cnblogs.com/StrayWolf/p/6701197.html?utm_source=itdadao&utm_medium=referral

func lengthOfLongestSubstring(s string) int {
	length := len(s)
	if 0 == length {
		return 0
	}

	cache := make(map[uint8]int, length)
	result := 0
	for i, j := 0, 0; i < length; i++ {
		if v, ok := cache[s[i]]; ok {
			// 此处是必须的，由于cache没有清空，cache里有所有的字符，我们需要保证j一直往后走
			if v+1 > j {
				j = v + 1
			}
		}
		cache[s[i]] = i
		if (i - j + 1) > result {
			result = i - j + 1
		}
	}

	return result
}
