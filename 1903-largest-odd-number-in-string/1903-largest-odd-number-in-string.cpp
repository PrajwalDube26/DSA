class Solution {
public:
    string largestOddNumber(string num) {
        string s1;

        int m=-1;
        for(int i=num.length()-1;i>=0;i--)
        {
            int a=num[i] - '0';

            if(a%2==1)
            {
                m=i;
                break;
            }

        }

        // for(int i=0;i<=m;i++)
        // {
        //     s1=s1+num[i];
        // }


        return num.substr(0, m + 1);;
    }
};