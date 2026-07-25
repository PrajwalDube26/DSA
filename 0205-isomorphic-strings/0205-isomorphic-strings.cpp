class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int>m1;
        map<char,char>m2;
        map<char,int>m3;
        map<char,char>m4;

        if(s.length()!=t.length())
        {
            return 0;
        }

        for(int i=0;i<s.length();i++)
        {
            if(m1[s[i]]>0)
            {
                if(m2[s[i]]!=t[i])
                {
                    return 0;
                }
                m1[s[i]]++;

            }
            else
            {
                m1[s[i]]++;
                m2[s[i]]=t[i];
            }
        }

        for(int i=0;i<s.length();i++)
        {
            if(m3[t[i]]>0)
            {
                if(m4[t[i]]!=s[i])
                {
                    return 0;
                }
                m3[t[i]]++;

            }
            else
            {
                m3[t[i]]++;
                m4[t[i]]=s[i];
            }
        }

        return 1;
    }
};