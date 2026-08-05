class Solution {
public:
    pair<int,int> minmax(vector<int>& freq)
    {
        int mini=INT_MAX,maxa=INT_MIN;
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                mini=min(mini,freq[i]);
            }
            
            maxa=max(maxa,freq[i]);
        }

        return {mini,maxa};
    }

    int beautySum(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int k=0;k<26;k++)
            {
                freq[k]=0;
            }

            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;

                pair<int,int> min_max = minmax(freq);
                if(min_max.second - min_max.first >0)
                {
                    ans+=min_max.second - min_max.first;
                }
            }
        }

        return ans;
    }
};