class Solution {
public:
    string longestPalindrome(string s) {
        int longest_so_far = 0;
        string i_of_center = "";
        for(int i = 0; i < (2 * s.size() - 1); i++){
            if(i % 2 == 0){
                int index = i / 2;
                for(int j = 0; true; j++){
                    int plus_index  = index + j;
                    int minus_index = index - j;
                    if (plus_index > s.size() || minus_index < 0){
                        break;
                    }
                    if(s[plus_index] != s[minus_index])
                        break;
                    
                    int pal_length = 2*j +1;
                    if(pal_length > longest_so_far){
                        longest_so_far = pal_length;
                        i_of_center = s.substr(minus_index, pal_length);
                    }
                }

            }else{
                int reduced_index = i / 2;
                for(int j = 0; true; j++){
                    int plus_index  = reduced_index + j + 1;
                    int minus_index = reduced_index - j;
                    if (plus_index > s.size() || minus_index < 0){
                        break;
                    }
                    if(s[plus_index] != s[minus_index])
                        break;
                    
                    int pal_length = 2*j + 2;
                    if(pal_length > longest_so_far){
                        longest_so_far = pal_length;
                        i_of_center = s.substr(minus_index, pal_length);
                    }
                }

            }
        }

        return i_of_center;
    }
};
