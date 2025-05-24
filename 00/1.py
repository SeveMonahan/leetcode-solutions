class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        enumerated = enumerate(nums)
        sorted_enumerated = sorted(enumerated, key=compare_enum)
        early_pointer = 0
        late_pointer = len(sorted_enumerated) - 1
        while(early_pointer != late_pointer):
            early_tuple = sorted_enumerated[early_pointer]
            late_tuple  = sorted_enumerated[late_pointer]

            result = early_tuple[1] + late_tuple[1]

            if(result == target):
                return [early_tuple[0], late_tuple[0]]
            elif(result > target):
                late_pointer -= 1
            else:
                early_pointer += 1

        
        return None

def compare_enum(op1):
    return op1[1]
