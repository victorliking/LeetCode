/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if(height==0) return ;
        int width = board[0].size();
        int num = width*height;
        bool visited[num];
        for(int i =0;i<num;i++) visited[i] =false;
        queue<int> q;
        
        for(int i =0;i<height;i++){
            for(int j =0;j<width;j++){
                if(((i==0)||(j==0)||(i==height-1)||(j==width-1))&&board[i][j]=='O'){
                    int idx = width*i+j;
                    q.push(idx);
                    visited[idx] = true;
                }
            }
        }
        
        
        while(!q.empty()){
            int current = q.front();
            q.pop();
            int row = current/width;
            int col = current%width;
            
            int idx = 0;
            //check left
            idx = width*row+col-1;
            if(col-1>=0&&board[row][col-1]=='O'&&!visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //check right
            idx = width*row+col+1;
            if(col+1<=width-1&&board[row][col+1]=='O'&&!visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //check up
            idx = width*(row-1)+col;
            if(row-1>=0&&board[row-1][col]=='O'&&!visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //check down
            idx = width*(row+1)+col;
            if(row+1<=height-1&&board[row+1][col]=='O'&&!visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
                
        }
        
        for(int i =0;i<height;i++){
            for(int j =0;j<width;j++){
                int idx = width*i+j;
                if(board[i][j]=='O'&&!visited[idx]){
                    board[i][j]='X';
                }
            }
        }
    }
};