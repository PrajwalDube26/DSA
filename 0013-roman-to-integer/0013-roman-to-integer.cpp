class Solution {
public:
    int romanToInt(string s) 
    {
        int count = 0;
        char prev='Z';

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
            {
                count =count+1;
            }
            else if(s[i]=='V')
            {
                if(prev == 'I')
                {
                    count+=3;
                }
                else
                {
                    count  =count+ 5;
                }
            }
            else if(s[i]=='X') 
            {
                if(prev == 'I')
                {
                    count+=8;
                }
                else
                {
                    count  =count+ 10;
                }
            }
            else if(s[i]=='L') 
            {
                if(prev == 'X')
                {
                    count+=30;
                }
                else
                {
                    count  =count+ 50;
                }
            }
            else if(s[i]=='C')
            {
                if(prev == 'X')
                {
                    count+=80;
                }
                else
                {
                    count  =count+ 100;
                }
            }
            else if(s[i]=='D') 
            {
                if(prev == 'C')
                {
                    count+=300;
                }
                else
                {
                    count  =count+ 500;
                }
            }
            else if(s[i]=='M') 
            {
                if(prev == 'C')
                {
                    count+=800;
                }
                else
                {
                    count  =count+ 1000;
                }
            }

            prev = s[i];
            
        }
        return count;
    }
};