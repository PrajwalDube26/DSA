class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        stack<string>st;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(logs[i]=="./")
            {

            }
            else if(logs[i]=="../")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(logs[i]);
            }
        }

        while(!st.empty())
        {
            st.pop();
            ans++;
        }

        return ans;
    }
};