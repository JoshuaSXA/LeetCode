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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        ListNode *resPtr = new ListNode(0);
        resPtr->next = head;
        ListNode *ptr1 = resPtr, *ptr2 = head, *tmpPtr1;
        int count = 0;
        
        while(ptr2 != NULL){
            if(count == m - 1){
                tmpPtr1 = ptr1;
            }else if(count >= m && count < n){
                ListNode* ptr = ptr2;
                ptr2 = ptr2->next;
                ptr->next = ptr1;
                ptr1 = ptr;
                ++count;
                continue;
            }else if(count == n){
                break;
            }
            ++count;
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        
        tmpPtr1->next->next = ptr2;
        tmpPtr1->next = ptr1;
        return resPtr->next;
    }
};