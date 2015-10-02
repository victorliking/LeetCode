/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.s
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int j =-1;
        int sum=0,total=0;
        for(int i =0;i<gas.size();i++){
            sum+= gas[i]-cost[i];
            total += gas[i]-cost[i];
            if(sum<0){
                j =i;
                sum = 0;
            }
        }
        return total>=0?j+1:-1;
    }
};