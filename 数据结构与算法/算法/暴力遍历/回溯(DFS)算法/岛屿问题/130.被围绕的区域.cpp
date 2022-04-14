class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0)return;
        int n=board[0].size();
        // 遍历边界上的岛屿
        for(int i=0;i<m;i++){
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for(int i=1;i<n-1;i++){
            dfs(board,0,i);
            dfs(board,m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='A'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!='O'){
            return;
        }
        // if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='O'){
            // 合法的位置
            board[x][y] = 'A';
            dfs(board,x+1,y);
            dfs(board,x-1,y);
            dfs(board,x,y-1);
            dfs(board,x,y+1);
        // }
    }
};