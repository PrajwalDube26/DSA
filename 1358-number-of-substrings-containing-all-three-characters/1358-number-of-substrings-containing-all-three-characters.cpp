class Solution {
public:
    bool isalltaken(int counta,int countb,int countc)
    {
        if(counta>0 && countb>0 && countc>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int numberOfSubstrings(string s)
    {
        int counta=0,countb=0,countc=0;
        int right=-1,left=0;
        int n=s.length();
        int ans=0;

        while(right < n)
        {
            bool is_all_taken = isalltaken(counta,countb,countc);

            if(is_all_taken)
            {
                ans+=n-right;

                if(s[left]=='a')counta--;
                else if(s[left]=='b')countb--;
                else if(s[left]=='c')countc--;

                left++;
            }
            else
            {
                right++;

                if(right==n)break;

                if(s[right]=='a')counta++;
                else if(s[right]=='b')countb++;
                else if(s[right]=='c')countc++;

            }
        }

        return ans;
    }
};