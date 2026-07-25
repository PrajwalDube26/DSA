class Solution {
public:
    string reverseWords(string s) {
        stack<string>s1;

        string str="";
        string s2="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ' && str.length()>0)
            {
                s1.push(str);
                str="";
            }
            else if(s[i] != ' ' )
            {
                str=str + s[i];
            }
        }
        if(str.length()>0)
            s1.push(str);

        str="";


        while(s1.size()>0)
        {
            s2=s2+s1.top();
            s1.pop();
            if(s1.size()>0)
            {
                s2=s2+" ";
            }
        }
        
        return s2;
    }
};