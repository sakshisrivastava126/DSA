class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mp = {}
        mp2 = {}

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            mp[s[i]] = mp.get(s[i], 0) + 1

        for i in range(len(t)):
            mp2[t[i]] = mp2.get(t[i], 0) + 1

        return mp == mp2
        
       
        