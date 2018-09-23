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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        return MergeSort(head);
    }
    
    ListNode* MergeSort(ListNode*head) {
        if(head->next==NULL)
            return head;
        ListNode* pHead,*qHead,*pre;
        pHead=head;
        qHead=head;
        pre=NULL;
        while(qHead!=NULL&&qHead->next!=NULL)
        {
           qHead=qHead->next->next;
           pre=pHead;
           pHead=pHead->next;
        }
        pre->next=NULL;
        ListNode *l,*r;
        l=MergeSort(head);
        r=MergeSort(pHead);
        return merge(l,r);
    }
    
    ListNode* merge(ListNode *l,ListNode*r) {
        ListNode *pRes=new ListNode(0);
        ListNode *temp=pRes;
        while(l!=NULL&&r!=NULL)
        {
            if(l->val<=r->val)
            {
                temp->next=l;
                temp=temp->next;
                l=l->next;
            }
            else
            {
                temp->next=r;
                temp=temp->next;
                r=r->next;
            }
        }
        if(l!=NULL)
            temp->next=l;
        if(r!=NULL)
            temp->next=r;
        temp=pRes->next;
        delete pRes;
        return temp;   
    }
    
};