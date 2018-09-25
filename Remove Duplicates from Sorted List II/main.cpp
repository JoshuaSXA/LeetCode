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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *ptr1 = head, *ptr2 = head->next, *tmpPtr = preHead;
        
        while(ptr2 != NULL){
            if(ptr1->val == ptr2->val){
                while(ptr2 != NULL && ptr2->val == ptr1->val){
                    ptr2 = ptr2->next;
                }
                tmpPtr->next = ptr2;
                ptr1 = ptr2;
                if(ptr2 == NULL){
                    break;
                }
                ptr2 = ptr2->next;
            }else{
                tmpPtr = ptr1;
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
        }
        return preHead->next;
    }
};