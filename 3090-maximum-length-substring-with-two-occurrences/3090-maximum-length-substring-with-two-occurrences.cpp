class Solution {
public:
    int is_all_lessorequal_totwo(vector<int>& v1)
    {
        for(int i=0;i<26;i++)
        {
            if(v1[i]>2)
            {
                return 0;
            }
        }

        return 1;
    }

    int maximumLengthSubstring(string s) 
    {
        vector<int>v1(26,0);
        int ans=0;
        int right=0,left=0;
        int n=s.length();

        for(right=0;right<n;right++)
        {
            v1[s[right]-97]++;

            if(!is_all_lessorequal_totwo(v1))
            {
                while(!is_all_lessorequal_totwo(v1))
                {
                    v1[s[left]-97]--;
                    left++;
                }
            }

            ans=max(ans,right-left+1);
        }
        
        return ans;
    }
};