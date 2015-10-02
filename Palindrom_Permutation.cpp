
/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd = 0, counts[256] = {0};
        for(char c:s){
            odd+=++counts[c]&1?1:-1;
        }
        
        return odd<=1;
    }
};