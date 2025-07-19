class Solution(object):
    def isAnagram(self,s, t):
        if len(t)!=len(s):
            return False
        frequency=[0]*26
        for i in range(len(s)):
            frequency[ord(s[i])-97]+=1
            frequency[ord(t[i])-97]-=1
        for i in range(0,26):
            if frequency[i]!=0:
                return False
        return True
def main():
    sol =Solution()
    print(sol.isAnagram("ab", "a"))
if __name__=="__main__":
    main()
        