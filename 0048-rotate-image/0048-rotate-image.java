class Solution {
    public void rotate(int[][] matrix) 
    {
        for(int i=0;i<matrix.length;i++)
        {
            for(int j=i+1;j<matrix[i].length;j++)
            {
                int temp=matrix[i][j];    // replace [i][j] to [j][i]
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<matrix.length;i++)
        {
            for(int s=0 ,end = matrix[i].length-1 ;s<end;s++,end--)
            {
                int temp=matrix[i][s];  //reverse each row
                matrix[i][s]=matrix[i][end];
                matrix[i][end]=temp;
            }
        }
        
    }
}