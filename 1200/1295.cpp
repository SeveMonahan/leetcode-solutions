class Solution {
public:
    int findNumbers(vector<int>& nums) {
        unsigned int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(doesNumberContainEvenNumberDigits(nums[i]))
                j++;
        }

        return j;
        
    }
    
    bool doesNumberContainEvenNumberDigits(int number){
        unsigned int total_digits = 1;
        unsigned int reduced_number = number;
        while(true){
            reduced_number = reduced_number / 10;
            if(reduced_number == 0){
                break;
            }else{
                total_digits++;
            }
        }

        return (total_digits % 2 == 0);

    }
};
