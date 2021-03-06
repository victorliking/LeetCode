/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool canFinish(int num, vector<pair<int, int>>& pre) {
        vector<vector<int>> adj(num,vector<int>());
        for(int i =0;i<pre.size();i++){
            adj[pre[i].first].push_back(pre[i].second);
        }
        
        vector<int> flag(num,0);
        vector<int> ret;
        for(int i =0;i<num;i++){
            if(check(adj,flag,i,ret)==false){
                return false;
            }
        }
        //reverse(ret.begin(),ret.end());
        return true;
    }
    
    bool check(vector<vector<int>>&adj, vector<int>& flag, int node, vector<int>&ret){
        if(flag[node]==-1) return false;
        if(flag[node]==1 ) return true;
        flag[node] = -1;
        for(auto r :adj[node]){
            //if(flag[r]) return false;
            if(check(adj,flag,r,ret)==false) return false;
        }
        ret.push_back(node);
        flag[node] = 1;
        return true;
    }
};

