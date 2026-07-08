class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        t = ''.join(ch.lower() for ch in s if ch.isalnum())
        r = t[::-1]
        return r == t

        