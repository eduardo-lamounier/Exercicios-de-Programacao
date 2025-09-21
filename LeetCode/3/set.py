'''
3. Longest Substring Without Repeating Characters - Medium
|https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Topics:
|Hash Table, String, Sliding Window
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0

        curr_chars = set()
        l, r = 0, 0
        while r < len(s):
            if not s[r] in curr_chars:
                curr_chars.add(s[r])
                longest = max(longest, r - l + 1)
                r += 1
            else:
                curr_chars.remove(s[l])
                l += 1

        return longest