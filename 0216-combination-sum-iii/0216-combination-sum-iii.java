class Solution {
    private void DFS(int x,int sum,ArrayList<Integer> arr,int k,int n,List<List<Integer>> res)
    {
        int size=arr.size();
        if(size==k)
        {
            if(sum==n)
                res.add(new ArrayList<>(arr));
            return;
        }
        if(x>9) return;
        arr.add(x);
        DFS(x+1,sum+x,arr,k,n,res);
        arr.remove(size);

        DFS(x+1,sum,arr,k,n,res);
    }
    public List<List<Integer>> combinationSum3(int k, int n) 
    {
        List<List<Integer>> res= new ArrayList<>();
        DFS(1,0,new ArrayList<>(),k,n,res);
        return res;
    }
}