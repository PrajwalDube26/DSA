class Solution {
public:

    bool isvowel(char c)
    {
        if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u')
        {
            return 1;
        }
        return 0;
    }

    string sortVowels(string s) 
    {
        vector<int>vowels;
        unordered_map<char,int>freq;
        unordered_map<char,int>first;

        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(isvowel(ch))
            {
                vowels.push_back(ch);
                freq[ch]++;

                if(first.find(ch)==first.end())
                {
                    first[ch]=i;
                }
            }
        }

        sort(vowels.begin(),vowels.end(),
            [&](char a,char b)
            {
                if(freq[a]==freq[b])
                {
                    return first[a]<first[b];
                }
                return freq[a]>freq[b];
            });

        int j=0;

        for(int i=0;i<s.length();i++)
        {
            if(isvowel(s[i]))
            {
                s[i]=vowels[j];
                j++;
            }
        }

        return s;
    }
};