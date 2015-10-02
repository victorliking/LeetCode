/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_map<string,int> cache;
        cache[beginWord] =1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            string word = q.front();
            q.pop();
            for(int i =0;i<word.size();i++){
                for(int j=0;j<26;j++){
                    string newWord = word;
                    newWord[i] = 'a'+j;
                    
                    if(wordDict.count(newWord)>0&&cache.count(newWord)==0){
                        cache[newWord] = cache[word] +1;
                        q.push(newWord);
                    }
                }
                
            }
        }
        if(cache.count(endWord)==0) return 0;
        return cache[endWord];
    }
};