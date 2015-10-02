/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        int table[10] = {1};
        for(int i =1;i<=9;i++){
            table[i]=i*table[i-1];
        }
        vector<char> numset;
        for(int i =1;i<=9;i++){
            numset.push_back(i+'0');
        }
        
        while(n>0){
            int temp = (k-1)/table[n-1];
            result+=numset[temp];
            numset.erase(numset.begin()+temp);
            k = k - temp*table[n-1];
            n--;
        }
        return result;
    }
};