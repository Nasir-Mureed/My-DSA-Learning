class Solution {
    static boolean isValid(StringBuilder str)
    {
        int len=str.length();
        for(int i=1;i<len;i++)
        {
            if(str.charAt(i)=='0' && str.charAt(i-1)=='0')
                return false;
        }
        if(len>=2 &&str.charAt(len-1)=='0' && str.charAt(len-2)=='0')
            return false;
        return true;
    }
    static void generate(StringBuilder temp,int n,List<String> res)
    {
        if(temp.length()>=n)
        {
            //if(isValid(temp))
                res.add(temp.toString());
            return;
        }
        if(!temp.isEmpty() && temp.charAt(temp.length()-1)=='0')
        {
            temp.append('1');
            generate(temp,n,res);
            temp.deleteCharAt(temp.length()-1);
        }
        else
        {
            temp.append('0');
        generate(temp,n,res);
        temp.deleteCharAt(temp.length()-1);

        temp.append('1');
        generate(temp,n,res);
        temp.deleteCharAt(temp.length()-1);
        }
        
        
    }
    public List<String> validStrings(int n) {
        List<String> res=new ArrayList<>();
        generate(new StringBuilder(),n,res);
        return res;
    }
}