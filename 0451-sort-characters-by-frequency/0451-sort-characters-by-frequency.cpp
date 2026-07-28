class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>>v1(256,{0,0});

        for(int i=0;i<256;i++)
        {
            v1[i].second = i;
        }

        for(int i=0;i<s.length();i++)
        {
            v1[s[i]].first++;
        }

        sort(v1.begin(),v1.end());

        string ans="";
        int a = v1[255].first;
        int i= 255;
        while(a>0)
        {
            for(int j=0;j<a;j++)
            {
                ans.push_back( (char) v1[i].second );
            }
            i--;
            a = v1[i].first;
        }
        return ans;
    }
};