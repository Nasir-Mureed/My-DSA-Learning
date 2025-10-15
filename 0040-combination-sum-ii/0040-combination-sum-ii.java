class Solution {
    static void help(int[] src, List<Integer> temp, List<List<Integer>> res, int ind, int sum) {
        if (sum == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        if (sum < 0 || ind == src.length) {
            return;
        }
        
        // Include current element
        temp.add(src[ind]);
        help(src, temp, res, ind + 1, sum - src[ind]);
        temp.remove(temp.size() - 1);
        
        // Skip all duplicates of current element
        int next = ind + 1;
        while (next < src.length && src[next] == src[ind]) {
            next++;
        }
        help(src, temp, res, next, sum);
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);  // Sort to group duplicates together
        List<List<Integer>> res = new ArrayList<>();
        help(candidates, new ArrayList<>(), res, 0, target);
        return res;
    }
}