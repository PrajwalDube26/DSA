class Solution {
public:
    int maxfreq(vector<int>& hash)
    {
        int  maxa=0;
        for(int i=0;i<26;i++)
        {
            maxa=max(maxa,hash[i]);
        }

        return maxa;
    }

    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int n=s.length();
        int len=0,maxlen=0;
        vector<int>hash(26,0);

        for(right=0;right<n;right++)
        {
            hash[s[right]-65]++;
            int maxifreq = maxfreq(hash);
            int other = right-left+1 - maxifreq;

            if(other>k)
            {
                while(other>k)
                {
                    hash[s[left]-65]--;
                    left++;
                    maxifreq = maxfreq(hash);
                    other = right-left+1 - maxifreq;
                }
            }
            len=right-left+1;
            maxlen = max(maxlen,len);
        }

        return maxlen;
    }
};