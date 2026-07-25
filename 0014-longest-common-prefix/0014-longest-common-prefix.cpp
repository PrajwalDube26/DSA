class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
        {
            return strs[0];
        }
        string s="";
        bool m=1;
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<strs.size()-1;j++)
            {
                if(strs[j].length()<i+1 || strs[j+1].length()<i+1)
                {
                    m=0;
                    break;
                }
                if(strs[j][i]!=strs[j+1][i])
                {
                    m=0;
                    break;
                }
            }
            if(m==0)
            {
                break;
            }
            else if(m==1)
            {
                s+=strs[0][i];
            }
        }

        return s;
    }
};