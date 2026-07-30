class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        // stack<string>st;
        int ans=0,count=0;

        for(int i=0;i<n;i++)
        {
            if(logs[i]=="./")
            {

            }
            else if(logs[i]=="../")
            {
                // if(!st.empty())
                // {
                //     st.pop();
                // }
                if(count!=0)
                {
                    count--;
                }
            }
            else
            {
                // st.push(logs[i]);
                count++;
            }
        }

        // while(!st.empty())
        // {
        //     st.pop();
        //     ans++;
        // }

        return count;
    }
};