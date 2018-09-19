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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* prePtr = preHead;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while(ptr1 != NULL && ptr2 != NULL){
            ListNode* postPtr = ptr2->next;
            prePtr->next = ptr2;
            ptr2->next = ptr1;
            ptr1->next = postPtr;
            prePtr = ptr1;
            if(postPtr != NULL){
                ptr1 = postPtr;
                ptr2 = postPtr->next;
            }else{
                break;
            }
        }
        return preHead->next;
    }
};