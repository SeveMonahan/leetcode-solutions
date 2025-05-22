class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start_index = 0
        end_index = 0
        longest_substring_so_far = ""
        string_index_by_char_ord = [-1] * 256

        
        for i in range(0, len(s)):
            char = s[i]
            duplicate_index = None
            if string_index_by_char_ord[ord(char)] != -1:
                duplicate_index = string_index_by_char_ord[ord(char)]
            end_index += 1
            if duplicate_index != None:
                for index in range(start_index, duplicate_index + 1):
                    string_index_by_char_ord[ord(s[index])] = -1
                start_index = duplicate_index + 1
            string_index_by_char_ord[ord(char)] = i
            
            candidate_new_longest_substr = s[start_index:end_index]
            if len(candidate_new_longest_substr) > len(longest_substring_so_far):
                longest_substring_so_far = candidate_new_longest_substr
        
        return len(longest_substring_so_far)
