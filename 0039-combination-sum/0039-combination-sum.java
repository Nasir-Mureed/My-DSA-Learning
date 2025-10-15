class Solution {
    static List<List<Integer>> res;
    static void help(int[] src,List<Integer> ans,int ind,int sum)
    {
        // if(ind>=src.length) return;
        if(ind==src.length)
        {
            if(sum==0)
                res.add(new ArrayList<Integer> (ans));
            return;
        }
        if(sum<0) return;
        if(sum>=src[ind])
        {
            ans.add(src[ind]);
            help(src,ans,ind,sum-src[ind]);
            ans.remove(ans.size()-1);
        }
        help(src,ans,ind+1,sum);

    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        res=new ArrayList<>();
        help(candidates,new ArrayList<>(),0,target);
        return res;
        
    }
}