class Solution 
{
    void swap(int i,int j,vector<int>& height,vector<string>& name)
    {
        int temp=height[i];
        height[i]=height[j];
        height[j]=temp;

        string t=name[i];
        name[i]=name[j];
        name[j]=t;
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {

        // bubble sort

        int n=names.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(heights[i]<heights[j])
                {
                    swap(i,j,heights,names);
                }
            }
        }
        return names;
    }
};