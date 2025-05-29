class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result = {};
        vector<int> num_each_digit = vector<int>(11, 0);
        for(int i = 0; i < digits.size(); i++){
            num_each_digit[digits[i]]++;
        }

        for(int i = 1; i < 10; i++){ // Note we skip 0, for the leading digit only
            if(num_each_digit[i] != 0){
                num_each_digit[i]--;
                for(int j = 0; j < 10; j++){
                    if(num_each_digit[j] != 0){
                        num_each_digit[j]--;
                        for(int k = 0; k < 10; k +=2){
                            if(num_each_digit[k] != 0)
                                result.push_back(i*100 + j*10 + k);
                        }
                        num_each_digit[j]++;
                    }
                }
                num_each_digit[i]++;
            }

        }

        std::sort(result.begin(), result.end());
        vector<int> unique_result = {};
        int previous_result = 0;
        for(int i = 0; i < result.size(); i++){
            int single_result = result[i];
            if(single_result == previous_result)
                continue;
            unique_result.push_back(single_result);
            previous_result = single_result;
        }

        return unique_result;
    }
};
