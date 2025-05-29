class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        unsigned short odds = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] % 2 == 1)
                odds += 1;
            else
                odds = 0;
            
            if (odds >= 3)
                return true;
        }

        return false;
        
    }
};
