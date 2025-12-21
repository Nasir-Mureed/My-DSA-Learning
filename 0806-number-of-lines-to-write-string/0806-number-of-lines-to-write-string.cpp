class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) 
    {
        vector<int> result(2,0);
        int i=0,pix=0,size=s.size();
        while( i<size)
        {
            pix=0;
            while(pix+widths[s[i]-'a']<=100)
            {
                pix+=widths[s[i]-'a'];
                i++;
                if(i>=size) break;
            }
            result[0]++;
            result[1]=pix;
            
        }
        return result;

        
    }
};