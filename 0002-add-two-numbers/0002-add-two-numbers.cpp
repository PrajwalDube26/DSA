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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dumy=new ListNode(-1);
        ListNode * tempa=l1,*tempb=l2,*temp=dumy;
        int carry=0;
        while(tempa!=NULL || tempb!=NULL || carry>0)
        {
            int sum=carry;
            if(tempa!=nullptr)
            {
                sum+=tempa->val;
                tempa=tempa->next;
            }
            if(tempb!=NULL)
            {
                sum+=tempb->val;
                tempb=tempb->next;
            }

            temp->next=new ListNode(sum%10);
            temp=temp->next;

            carry=sum/10;
        }

        return dumy->next;
    }
};