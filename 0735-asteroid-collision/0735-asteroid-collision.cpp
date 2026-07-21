class Solution {
public:
    vector<int> reverse(vector<int> ans,int n)
    {
        for(int i=0;i<n/2;i++)
        {
            swap(ans[i],ans[n-i-1]);
        }

        return ans;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s1;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0 )
            {
                s1.push(asteroids[i]);
            }
            else if(asteroids[i]<0 )
            {
                bool m=0;
                while(!s1.empty() && s1.top() > 0 )
                {
                    if(s1.top()<abs(asteroids[i]))
                    {
                        s1.pop();
                    }
                    else if(s1.top()==abs(asteroids[i]))
                    {
                        m=1;
                        s1.pop();
                        break;
                    }
                    else if(s1.top()>abs(asteroids[i]))
                    {
                        break;
                    }
                }
                if((s1.empty() || s1.top()<0 ) && m==0)
                {
                    s1.push(asteroids[i]);
                }
            }
        }

        vector<int>ans;
        while(!s1.empty())
        {
            ans.push_back(s1.top());
            s1.pop();
        }

        return reverse(ans,ans.size());
    }
};