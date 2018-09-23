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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *resPtr = new ListNode(0);
        resPtr->next = head;
        
        ListNode *ptr1 = resPtr, *ptr2 = head;
        ListNode *tmpPtr1, *tmpPtr2;
        while(ptr2 != NULL){
            while(ptr1->next != NULL && ptr1->next->val < x){
                ptr1 = ptr1->next;
            }
            ptr2 = ptr1->next;
            while(ptr2 != NULL && ptr2->val >= x){
                tmpPtr2 = ptr2;
                ptr2 = ptr2->next;
            }
            if(ptr2 != NULL){
                tmpPtr2->next = ptr2->next;
                tmpPtr1 = ptr1->next;
                ptr1->next = ptr2;
                ptr2->next = tmpPtr1;
                ptr1 = ptr2;
                ptr2 = tmpPtr2->next;
            }
        }
        
        return resPtr->next;
    }
};