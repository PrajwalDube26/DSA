class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        stack<int>s1,s2,temp;
        int right=0,left=0;
        int n= fruits.size();
        int maxa = 0;
        bool m=0;

        for(right=0;right<n;right++)
        {
            if(s1.empty())
            {
                s1.push(fruits[right]);
            }
            else if(!s1.empty() && s1.top() == fruits[right])
            {
                s1.push(fruits[right]);
            }
            else if(!s1.empty() && s1.top() != fruits[right] && s2.empty())
            {
                s2.push(fruits[right]);
            }
            else if(!s1.empty() && s1.top() != fruits[right] && !s2.empty() && s2.top() == fruits[right])
            {
                s2.push(fruits[right]);
            }
            else if(!s1.empty() && s1.top() != fruits[right] && !s2.empty() && s2.top() != fruits[right])
            {
                m=0;
                while(!s1.empty())
                {
                    if(s1.top()==fruits[left])
                    {
                        s1.pop();
                    }
                    else if(s2.top()==fruits[left])
                    {
                        s2.pop();
                    }
                    left++;

                    if(s2.empty())
                    {
                        m=1;
                        break;
                    }
                }

                if(m==0)
                {
                    s1.push(fruits[right]);
    
                    temp = s1;
                    s1 =s2;
                    s2=temp; 
                }
                else if(m==1)
                {
                    s2.push(fruits[right]);
                }
    
            }
            maxa = max(maxa,right-left+1);
        }

        return maxa;
    }
};