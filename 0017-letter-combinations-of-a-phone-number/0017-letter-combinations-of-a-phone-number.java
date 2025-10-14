class Solution {
    static List<String> res;
    static String two="abc";
    static String three="def";
    static String four="ghi";
    static String five="jkl";
    static String six="mno";
    static String seven="pqrs";
    static String eight="tuv";
    static String nine="wxyz";
    static void help(String src,int srcLen,int srcInd,StringBuilder ans)
    {
        int ansLen=ans.length();
        if(ansLen>=srcLen )
        {
            res.add(ans.toString());
            return;
        }
        for(int i=srcInd;i<srcLen;i++)
        {
            char ch=src.charAt(i);
            if(ch=='2')
            {
                for(int j=0;j<3;j++)//length of two=3
                {
                    ans.append(two.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='3')
            {
                for(int j=0;j<3;j++)//length of three=3
                {
                    ans.append(three.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='4')
            {
                for(int j=0;j<3;j++)//length of four=3
                {
                    ans.append(four.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='5')
            {
                for(int j=0;j<3;j++)//length of five=3
                {
                    ans.append(five.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='6')
            {
                for(int j=0;j<3;j++)//length of six=3
                {
                    ans.append(six.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='7')
            {
                for(int j=0;j<4;j++)//length of seven=4
                {
                    ans.append(seven.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='8')
            {
                for(int j=0;j<3;j++)//length of eight=3
                {
                    ans.append(eight.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
            else if(ch=='9')
            {
                for(int j=0;j<4;j++)//length of nine=4
                {
                    ans.append(nine.charAt(j));
                    help(src,srcLen,i+1,ans);
                    ans.deleteCharAt(ans.length()-1);
                }
            }
        }


    }
    public List<String> letterCombinations(String digits) 
    {
        res=new ArrayList<>();
        if(digits.isEmpty()) return res;
        help(digits,digits.length(),0,new StringBuilder());
        return res;
        
    }
}