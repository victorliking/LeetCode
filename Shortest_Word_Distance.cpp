/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1=-1,pos2=-1,ret = INT_MAX;
        for(auto it = words.begin();it!=words.end();it++){
            if((*it).compare(word1)==0) pos1 = it- words.begin();
            else if((*it).compare(word2)==0) pos2 = it-words.begin();
            if(pos1>=0&&pos2>=0&&abs(pos1-pos2)<ret) ret = abs(pos1-pos2);
        }
        return ret;
    }
};