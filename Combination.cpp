/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret,path,0,0,n,k);
        return ret;
    }
    
    void dfs(vector<vector<int>>&ret,vector<int>&path,int start,int num, int n,int k){
        if(num==k){
            ret.push_back(path);
            return;
        }
        for(int i = start;i<n;i++){
            path.push_back(i+1);
            dfs(ret,path,i+1,num+1,n,k);
            path.pop_back();
        }
    }
};