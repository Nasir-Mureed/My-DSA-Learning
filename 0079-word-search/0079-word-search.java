class Solution 
{
    static boolean exploreWord(char[][] board,int i,int j,String word,int wordChar )
    {
        if(wordChar+1==word.length())// word found
        {
            return true;
        }
        char currChar=board[i][j];
        board[i][j]='#'; //mark visited
        if(i+1<board.length &&board[i+1][j]==word.charAt(wordChar+1))
        {
            if(exploreWord(board,i+1,j,word,wordChar+1)) return true;
        }
        if(i-1>=0 && board[i-1][j]==word.charAt(wordChar+1))
        {
            if(exploreWord(board,i-1,j,word,wordChar+1))return true;
        }
        if(j+1<board[0].length && board[i][j+1]==word.charAt(wordChar+1))
        {
            if(exploreWord(board,i,j+1,word,wordChar+1)) return true;
        }
        if(j-1>=0 && board[i][j-1]==word.charAt(wordChar+1))
        {
            if(exploreWord(board,i,j-1,word,wordChar+1))return true;
        }
        board[i][j]=currChar;// remove visited Mark
        return false;
    }
    public boolean exist(char[][] board, String word) 
    {
        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board[i].length;j++)
            {
                if(board[i][j]==word.charAt(0))
                {
                    if(exploreWord(board,i,j,word,0)) 
                        return true;
                }
            }
        }
        return false;
    }
}