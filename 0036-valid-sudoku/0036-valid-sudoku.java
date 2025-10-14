class Solution {
    
    static boolean canPlace(char[][] board,int i,int j,char val)
    {
        for(int r=0;r<9;r++) //check in given row
        {
            if(board[i][r]==val && r!=j) //if present can not place val
                return false;
        }
        for(int c=0;c<9;c++) //check in given column
        {
            if(board[c][j]==val && c!=i)
                return false;
        }
        int r,c;  //represent the starting cell of 3 X 3 sub grid
        if(i<=2)
        {
            r=0;
            if(j<=2)     //1st Sub Grid
                c=0;
            else if(j<=5) //2nd Sub Grid
                c=3;
            else          //3rd Sub Grid
                c=6;

        }
        else if(i<=5)
        {
            r=3;
            if(j<=2)        //4th Sub Grid
                c=0;
            else if(j<=5)   //5th Sub Grid
                c=3;
            else            //6th Sub Grid
                c=6;

        }
        else
        {
            r=6;
            if(j<=2)  //7th Sub Grid
                c=0;
            else if(j<=5) //8th Sub Grid
                c=3;
            else        //9th Sub Grid
                c=6;

        }
        for(int x=0;x<3;x++)    // check in given sub Grid
        {
            for(int y=0;y<3;y++)
            { 
                if(board[r+x][c+y]==val && r+x!=i && c+y!=j)
                    return false;
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
         for(int i=0;i<9;i++)// board is of 9 X 9 
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!canPlace(board,i,j,board[i][j]))
                        return false;
                    
                }
            }
        } 
        return true;       
    }
}