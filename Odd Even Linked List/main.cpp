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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *ptr1 = head, *ptr2 = head->next;
        ListNode *tmpPtr1, *tmpPtr2;
        ListNode *evenPtr = new ListNode(0);
        evenPtr->next = ptr2;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->next == ptr2){
                ptr1->next = ptr2->next;
                tmpPtr1 = ptr1;
                ptr1 = ptr1->next;
            }else if(ptr1 == ptr2->next){
                ptr2->next = ptr1->next;
                tmpPtr2 = ptr2;
                ptr2 = ptr2->next;
            }else{
                break;
            }
        }
        
        if(ptr1 == NULL){
            tmpPtr1->next = evenPtr->next;
            ptr2->next = NULL;
        }else if(ptr2 == NULL){
            ptr1->next = evenPtr->next;
        }
        
        return head;
    }
};