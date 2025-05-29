#include <algorithm>
using namespace std;
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int maximum = max({nums[0], nums[1], nums[2]});

        if(maximum >= (nums[0] + nums[1]) || maximum >= (nums[1] + nums[2]) || maximum >= (nums[0] + nums[2]))
            return "none";
        
        bool zero_one_match = nums[0] == nums[1];
        bool one_two_match  = nums[1] == nums[2];
        bool zero_two_match = nums[0] == nums[2];

        if(zero_one_match && one_two_match)
            return "equilateral";
        else if (zero_one_match || one_two_match || zero_two_match)
            return "isosceles";
        
        return "scalene";
    }
};
