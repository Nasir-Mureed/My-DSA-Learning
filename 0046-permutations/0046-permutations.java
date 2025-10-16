class Solution {
    static List<List<Integer>> res;
    static void help(int[]src,int[] mark,List<Integer> arr,int ind)
    {
        if(ind>=src.length)
        {
            if(arr.size()==src.length)
                res.add(new ArrayList<>(arr));
            return;
        }
        for(int i=0;i<mark.length;i++)
        {
            if(mark[i]==0)
            {
                arr.add(src[i]);
                mark[i]=1;
                help(src,mark,arr,ind+1);
                arr.remove(arr.size()-1);
                mark[i]=0;
               // help(src,mark,arr,ind+1);

            }
        }
    }
    
    public List<List<Integer>> permute(int[] nums) 
    {
        res=new ArrayList<>();
        int[]mark=new int[nums.length];
        for(int i=0;i<mark.length;i++)
        {
            mark[i]=0;
        }
        help(nums,mark,new ArrayList<>(),0);
        return res;
    }
}