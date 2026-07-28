class Solution {
public:
    bool rotateString(string s, string goal) {
        string str="",str2="";

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==goal[0])
            {
                str2=s.substr(i,s.length()-i+1);
                str2+=str;
                if(str2==goal)
                {
                    return 1;
                }
                else
                {
                    str+=s[i];
                    str2="";
                }
                
            }
            else
            {
                str+=s[i];
            }
        }

        

        return 0;
    }
};