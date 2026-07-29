/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        {
            return NULL;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<ListNode*>v1(lists.size());

        for(int i=0;i<lists.size();i++)
        {
            v1[i] = lists[i];
        }

        for(int i=0;i<lists.size();i++)
        {
            if(v1[i]!=NULL)
            {
                pq.push({lists[i]->val,i});
                v1[i] = lists[i]->next;
            }
        }

        if(pq.empty())
        {
            return NULL;
        }

        ListNode* ans, *travel;
        pair<int,int> a =pq.top();

        pq.pop();
        ans= new ListNode(a.first);
        travel=ans;

        if(v1[a.second]!=NULL)
        {
            pq.push({v1[a.second]->val,a.second});
            v1[a.second] = v1[a.second] ->next;
        }

        while(!pq.empty())
        {
            a =pq.top();
            ListNode* temp= new ListNode(a.first);
            travel->next=temp;
            travel = temp;

            if(v1[a.second]!=NULL)
            {
                pq.push({v1[a.second]->val,a.second});
                v1[a.second] = v1[a.second] ->next;
            }
            pq.pop();
        }

        return ans;
    }
};