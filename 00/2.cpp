/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* current_node = nullptr;

        int carry = 0;
        while(unfinished(l1, l2) || carry != 0){
            int l1_digit = get_digit(l1);
            int l2_digit = get_digit(l2);

            int sum = l1_digit + l2_digit + carry;
            int new_digit = sum % 10;
            carry = sum/10;

            if(result == nullptr){
                result = new ListNode(new_digit);
                current_node = result;
            }else{
                current_node->next = new ListNode(new_digit);
                current_node = current_node->next;
            }
            
            l1 = backstep(l1);
            l2 = backstep(l2);
        }

        return result;
        
    }

    bool unfinished(ListNode* l1, ListNode* l2){
        return l1 != nullptr || l2 != nullptr;
    }

    int get_digit(ListNode* l){
        if(l == nullptr){
            return 0;
        }

        return l->val;
    }

    ListNode* backstep(ListNode* l){
        if (l == nullptr)
            return nullptr;
        
        return l->next;
    }
};
