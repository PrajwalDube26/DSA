class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int n = seq.length();
        int bal=0,maxa=0;
        vector<int>v1(n,0);

        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                bal++;
            }
            else if(seq[i]==')')
            {
                bal--;
            }

            maxa = max(maxa,bal);
        }
        int z = ceil((double)maxa/2);

        bal=0;

        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                bal++;
                if(bal>z)
                {
                    v1[i]=1;
                }
            }
            else if(seq[i]==')')
            {
                if(bal>z)
                {
                    v1[i]=1;
                }
                bal--;
            }
        }
        return v1;
    }
};