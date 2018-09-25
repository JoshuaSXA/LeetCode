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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        
        ListNode *resPtr = new ListNode(0);
        resPtr->next = head;
        
        ListNode *ptr1 = head, *ptr2 = head, *prePtr = resPtr;
        int count = 1;
        
        while(ptr2 != NULL && count < n){
            ptr2 = ptr2->next;
            ++count;
        }
        
        while(ptr2->next != NULL){
            prePtr = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        prePtr->next = ptr1->next;
        delete ptr1;
        return resPtr->next;
    }
};