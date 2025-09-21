'''
3. Longest Substring Without Repeating Characters - Medium
|https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Topics:
|Hash Table, String, Sliding Window
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0

        seen = [False] * 128
        l, r = 0, 0
        while r < len(s):
            rch = s[r]
            lch = s[l]

            if seen[ord(rch)]:
                seen[ord(lch)] = False
                l += 1
                continue

            res = max(res, r - l + 1)
            seen[ord(rch)] = True
            r += 1
                
        return res