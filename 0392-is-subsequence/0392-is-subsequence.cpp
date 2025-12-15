class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.empty()) return true;
        int i=0;
        int size=t.length(),len1=s.length();
        for(int j=0;j<size;j++)
        {
            if(s[i]==t[j])
            {
                i++;
                if(i>=len1) //subsequence completed
                    return true;
            }
        }        
        return false;
    }
};