class Solution(object):
    def subsets(self, nums):
        result=[]
        output=[]
        def backtracking(i):
            if i==len(nums):
                result.append(output[:])
                return
            backtracking(i+1)
            output.append(nums[i])
            backtracking(i+1)
            output.pop()
            return
        backtracking(0)
        return result
if __name__== "__main__":
    solution=Solution()
    nums = [1, 2, 3]
    res=solution.subsets(nums)
    for subset in res:
        print(subset)
