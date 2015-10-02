/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        dfs(ret,path,s,0);
        return ret;
    }
    
    void dfs(vector<vector<string>>&ret, vector<string>& path, string s, int start){
        if(start==s.size()){
            ret.push_back(path);
            return;
        }
        for(int i =start;i<s.size();i++){
            if(isP(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                dfs(ret,path,s,i+1);
                path.pop_back();
            }
        }
    }
    
    bool isP(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};