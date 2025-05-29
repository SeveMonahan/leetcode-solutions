class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int first_nums1 = 0; // Inclusive, unless = last
        int first_nums2 = 0;
        int last_nums1  = nums1.size(); // Exclusive
        int last_nums2  = nums2.size();

        while((last_nums2 - first_nums2 + last_nums1 - first_nums1) > 2){
            if((last_nums1 - first_nums1) < 1){
                first_nums2++;
                last_nums2--;
            }else if((last_nums2 - first_nums2 )< 1){
                first_nums1++;
                last_nums1--;
            }else{
                int val_f1 = nums1[first_nums1];
                int val_l1 = nums1[last_nums1 - 1];

                int val_f2 = nums2[first_nums2];
                int val_l2 = nums2[last_nums2 - 1];
            
                if(val_f1 <= val_f2){
                    first_nums1++;
                }else{
                    first_nums2++;
                }
                
                if(val_l1 > val_l2){
                    last_nums1--;
                }else{
                    last_nums2--;
                }
            }
        }
        vector<int> results = {};

        if(first_nums1 != last_nums1){
            results.push_back(nums1[first_nums1]);
            if(first_nums1 + 1 != last_nums1){
                results.push_back(nums1[first_nums1 + 1]);
            }
        }

        if(first_nums2 != last_nums2){
            results.push_back(nums2[first_nums2]);
            if(first_nums2 + 1 != last_nums2){
                results.push_back(nums2[first_nums2 + 1]);
            }
        }

        if(results.size() == 1){
            return double(results[0]);
        }
        //else

        return (double(results[0]) + double(results[1]))/2;
    }
};
