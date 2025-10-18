class Solution {
    
    static boolean isBalance(int n)
    {
        int x=n,i=0;
        int[] arr=new int[(int) Math.log10(n) + 1];
        while(x!=0)
        {
            arr[i]=x%10;
            x/=10;
            i++;
        }
        for(i=0;i<arr.length;i++)
        {
            int count=0;
            for(int j=0;j<arr.length;j++)
            {
                if(arr[j]==arr[i])
                    count++;
            }
            if(arr[i]!=count)
                return false;
        }
        return true;
    }
    public int nextBeautifulNumber(int n) 
    {
        while(true)
        {
            n++;
            if(isBalance(n))
                return n;
        }
    }
}