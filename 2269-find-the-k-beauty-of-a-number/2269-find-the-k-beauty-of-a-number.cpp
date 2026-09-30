class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n= s.length();
        string s1="";
        int ans=0;

        for(int i=0;i<k;i++)
        {
            s1+=s[i];
        }

        int a=stoi(s1);
        if(num%a==0)ans++;

        int left=0,right=k;

        for(right=k;right<n;right++)
        {
            left++;
            s1+=s[right];
            a=stoi(s1.substr(left,right));

            if(a!=0 && num%a==0)ans++;
        }

        return ans;
    }
};