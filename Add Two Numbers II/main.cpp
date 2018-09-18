/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *cur=dummy;
        
        ListNode *p1=l1;
        ListNode *p2=l2;
        stack<int>stk1,stk2;
        while(p1)
        {
            stk1.push(p1->val);
            p1=p1->next;
        }
        while(p2)
        {
            stk2.push(p2->val);
            p2=p2->next;
        }
        int sum=0;
        int carry=0;
        while(stk1.size()||stk2.size()||sum)
        {
            if(stk1.size())
            {
                sum+=stk1.top();
                stk1.pop();
            }
            if(stk2.size())
            {
                sum+=stk2.top();
                stk2.pop();
            }
            ListNode *temp=new ListNode(sum%10);
            sum/=10;
            carry=sum;
            temp->next=cur->next;
            cur->next=temp;
        }
        return dummy->next;

    }
    
};