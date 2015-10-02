/*
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> maps;
        for(auto iter:intervals){
            maps[iter.start] +=1;
            maps[iter.end] -= 1;
        }
        int maxroom = 0,rooms=0;
        for(auto room:maps){
            maxroom = max(maxroom,rooms+=room.second);
        }
        return maxroom;
    }
};
*/