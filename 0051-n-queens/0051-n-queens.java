class Solution {

    static boolean canPlace(char[][] board,int i,int j)
    {
        for(int y=j-1;y>=0 ;y--) //check left
        {
            if(board[i][y]=='Q')
                return false;
        }
        for(int x=i-1 ,y=j-1; x>=0&&y>=0 ;x--,y--) //check up diagonal
        {
            if(board[x][y]=='Q')
                return false;
        }
        for(int x=i+1, y=j-1; x<board.length && y>=0 ;x++,y--) //check down diagonal
        {
            if(board[x][y]=='Q')
                return false;
        }
        return true;
    }
    static void placeQueen(char[][] board,int j,List<List<String>> res)
    {
        if(j>=board.length)//  base case
        {
            List<String> ans=new ArrayList<>();
            StringBuilder str=new StringBuilder();
            for(int x=0;x<board.length;x++)
            {
                for(int y=0;y<board.length;y++)
                {
                    str.append(board[x][y]);
                }
                ans.add(str.toString());
                str.delete(0,str.length());
            }
            res.add(ans);
            return ;
        }

        for(int k=0;k<board.length;k++)
        {
            if(canPlace(board,k,j))
            {
                board[k][j]='Q';
                placeQueen(board,j+1,res);
                board[k][j]='.';
            }

        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        char[][] board= new char[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]='.';
            }
        }
        placeQueen(board,0,res);
        return res;
    }
}