/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/

class Solution {
    struct node{
        int parent = 0;
        vector<int> nbs;
    };
    
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,node> nodes;
        if(edges.size()!=n-1) return false;
        for(auto edge:edges){
            nodes[edge.first].nbs.push_back(edge.second);
            nodes[edge.second].nbs.push_back(edge.first);
        }
        vector<bool> v(n,false);
        queue<int> q;
        q.push(0);
        v[0] = true;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto n:nodes[p].nbs){
                if(n!=nodes[p].parent){
                    if(v[n]) return false;
                    v[n] = true;
                    nodes[n].parent = p;
                    q.push(n);
                }
            }
        }
        return true;
    }
};