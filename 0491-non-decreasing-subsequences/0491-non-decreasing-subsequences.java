class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, 0, new ArrayList<>(), res);
        return res;
    }

    private void dfs(int[] nums, int index, List<Integer> path, List<List<Integer>> res) {
        if (path.size() >= 2) {
            res.add(new ArrayList<>(path));
        }

        // To skip duplicates at the same recursion level
        HashSet<Integer> used = new HashSet<>();

        for (int i = index; i < nums.length; i++) {
            // skip duplicates at same level
            if (used.contains(nums[i])) continue;
            // maintain non-decreasing order
            if (!path.isEmpty() && nums[i] < path.get(path.size() - 1)) continue;

            used.add(nums[i]);
            path.add(nums[i]);
            dfs(nums, i + 1, path, res);
            path.remove(path.size() - 1);
        }
    }
}



// class Solution {
//     // static void dfs(int[] src,int ind,List<Integer> temp,List<List<Integer>> res)
//     // {
//     //     if(ind>=src.length)
//     //     {
//     //         if(temp.size()>=2)
//     //         {
//     //             boolean isPre=false;
//     //             for (int i = 0; i < res.size(); i++) 
//     //             {
//     //                 if(res.get(i).equals(temp))
//     //                     isPre=true;
//     //             }
//     //             if(!isPre)
//     //                 res.add(new ArrayList<>(temp));
//     //         }
//     //         return ;
//     //     }
//     //     if(!temp.isEmpty() && src[ind]>=temp.get(temp.size()-1))
//     //     {
//     //         temp.add(src[ind]);
//     //         dfs(src,ind+1,temp,res);
//     //         temp.remove(temp.size()-1);
//     //     }
//     //     if(temp.isEmpty())
//     //     {
//     //         temp.add(src[ind]);
//     //         dfs(src,ind+1,temp,res);
//     //         temp.remove(temp.size()-1);
//     //     }
        

//     //     dfs(src,ind+1,temp,res);
//     // }
//     // public List<List<Integer>> findSubsequences(int[] nums) {
//     //     List<List<Integer>> res=new ArrayList<>();
//     //     dfs(nums,0,new ArrayList<>(),res);
//     //     return res;
//     // }
// }