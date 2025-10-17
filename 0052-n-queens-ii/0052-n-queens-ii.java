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
    static int placeQueen(char[][] board,int j)
    {
        if(j>=board.length)// base case
        {
            return 1 ;
        }
        int count=0;
        for(int k=0;k<board.length;k++)
        {
            if(canPlace(board,k,j))
            {
                board[k][j]='Q';
                count+=placeQueen(board,j+1);
                board[k][j]='.';
            }

        }
        return count;
    }

    public int totalNQueens(int n) {
       
        char[][] board= new char[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]='.';
            }
        }
        return placeQueen(board,0);
      
    }
}