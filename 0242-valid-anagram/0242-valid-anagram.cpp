class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;

        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }

        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }

        for(int i=97;i<=122;i++)
        {
            char ch=(char) i;
            if(m1[ch]!=m2[ch])
            {
                return false;
            }
        }

        return true;
    }
};