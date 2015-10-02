/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto str:strs){
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        
        vector<vector<string>> ret;
        for(auto iter:mp){
            vector<string> temp;
            auto cache = iter.second;
            for(auto store:cache){
                temp.push_back(store);
            }
            sort(temp.begin(),temp.end());
            ret.push_back(temp);
        }
        return ret;
    }
};