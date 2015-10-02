/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = costs.size(), m = costs[0].size(), m1=0,m2=0;
        vector<int> dp(m,0);
        for(int i =0;i<n;i++){
            int t1= m1,t2=m2;
            m1=m2=INT_MAX;
            for(int j =0;j<m;j++){
                dp[j]=(dp[j]!=t1?t1:t2)+costs[i][j];
                if(m1<=dp[j]) m2= min(m2,dp[j]);
                else m2=m1,m1=dp[j];
            }
        }
        return m1;
    }
};