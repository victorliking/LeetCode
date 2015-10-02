/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
*/

class Vector2D {
public:
    vector<vector<int>>::iterator start,end;
    int j =0;
    Vector2D(vector<vector<int>>& vec2d) {
        start = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        hasNext();
        return (*start)[j++];
    }

    bool hasNext() {
        while(start!=end&&j==(*start).size()){
            start++,j=0;
        }
        return start!=end;
    }
};