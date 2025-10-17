class Solution {

   static boolean canPlace(List<StringBuilder> board,int i,int j)
    {
        // if(i>=board.length || j>=board[0].length())
        // {
        //     return false; //out of bound check
        // }
        for(int y=j-1;y>=0 ;y--) //check left
        {
            if(board.get(i).charAt(y)=='Q')
                return false;
        }
        for(int x=i-1 ,y=j-1; x>=0&&y>=0 ;x--,y--) //check up diagonal
        {
            if(board.get(x).charAt(y)=='Q')
                return false;
        }
        for(int x=i+1, y=j-1; x<board.size() && y>=0 ;x++,y--) //check down diagonal
        {
            if(board.get(x).charAt(y)=='Q')
                return false;
        }
        return true;
    }
    static void placeQueen(List<StringBuilder> board,int j,int n,List<List<String>> res)
    {
        if(j>=board.get(0).length())// is it base case
        {
            List<String> ans=new ArrayList<>();
            for(int i=0;i<board.size();i++)
            {
                ans.add(board.get(i).toString());
            }
            res.add(ans);//should use copy not ref
            return ;
        }

        for(int k=0;k<board.size();k++)
        {
            if(canPlace(board,k,j))
            {
                board.get(k).setCharAt(j,'Q');
                placeQueen(board,j+1,n,res);
                board.get(k).setCharAt(j,'.');
            }

        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        List<StringBuilder> board=new ArrayList<>();
        StringBuilder str=new StringBuilder();
        for(int i=0;i<n;i++)
        {
            str.append('.');
        }
        for(int i=0;i<n;i++)
        {
            board.add(new StringBuilder(str.toString()));
        }
        placeQueen(board,0,n,res);
        return res;
    }
}