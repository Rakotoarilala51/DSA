class Solution(object):
    def isAnagram(self, s, t):
        count = {}
        for c in s:
            if c not in count:
                count[c]=0
            count[c]+=1
        for c in t:
            if c not in count:
                return False
            count[c]-=1
            if count[c]==0:
                count.pop(c)
        return not len(count)
def main():
    sol = Solution()
    print(sol.isAnagram("an", "nan"))
if __name__=="__main__":
    main()