class Solution {
    static void generate(List<String> res, StringBuilder current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            res.add(current.toString());
            return;
        }
        
        if (open < n) {
            current.append('(');
            generate(res, current, open + 1, close, n);
            current.deleteCharAt(current.length() - 1);
        }
        
        if (close < open) {
            current.append(')');
            generate(res, current, open, close + 1, n);
            current.deleteCharAt(current.length() - 1);
        }
    }
    
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        generate(res, new StringBuilder(), 0, 0, n);
        return res;
    }
}

//brute force

// class Solution {
//     static boolean isValid(char[] str)
//     {
//         Stack<Character> st=new Stack<>();
//         for(int i=0;i<str.length;i++)
//         {

//             if(str[i]=='(')
//                 st.push(str[i]);
//             else if(!st.isEmpty())
//                 st.pop();
//             else
//                 return false;

//         }
//         if(st.isEmpty())
//             return true;
//         return false;
//     }
//     static void swap(char[]arr,int i,int j)
//     {
//         char ch=arr[i];
//         arr[i]=arr[j];
//         arr[j]=ch;
//     }
//  static void permutations(char[] arr, int ind, Set<String> res) {
//     if (ind >= arr.length) {
//         if (isValid(arr)) {
//             res.add(new String(arr));
//         }
//         return;
//     }
    
//     // Handle duplicates - skip swapping identical characters
//     Set<Character> used = new HashSet<>();
//     for (int i = ind; i < arr.length; i++) {
//         if (used.contains(arr[i])) continue;
//         used.add(arr[i]);
        
//         swap(arr, ind, i);
//         permutations(arr, ind + 1, res);
//         swap(arr, ind, i);
//     }
// }

// public List<String> generateParenthesis(int n) {
//     Set<String> res = new HashSet<>();
//     char[] arr = new char[2 * n];
//     // ... fill array
//     for(int i=0;i<2*n;i++)
//         {
//             if(i<n)
//                 arr[i]='(';
//             else
//                 arr[i]=')';
//         }
//     permutations(arr, 0, res);
//     return new ArrayList<>(res);
// }
// }