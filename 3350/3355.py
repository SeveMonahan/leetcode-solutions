class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        reduction_array = [0] * (len(nums) + 1)
        for q in queries:
            fst = q[0]; lst = q[1]
            reduction_array[fst] += 1; reduction_array[lst + 1] -= 1

        reduction = 0
        for i in range(0, len(nums)):
            reduction = reduction + reduction_array[i]
            num = nums[i]
            difference = num - reduction
            if difference > 0:
                return False
        return True 
