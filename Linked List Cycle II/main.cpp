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
    /**********************************
     * 设置两个指针，一个指针的速度是另一个指针速度的两倍
     * https://blog.csdn.net/Eartha1995/article/details/80990636
     **********************************/
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        bool cycleFormed = false;
        ListNode* ptr1, *ptr2;
        ptr1 = head; ptr2 = head;
        
        while(ptr1->next != NULL && ptr1->next->next != NULL){
            ptr2 = ptr2->next;
            ptr1 = ptr1->next->next;
            
            if(ptr1 == ptr2){
                cycleFormed = true;
                ptr1 = head;
                while(ptr1 != ptr2){
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                break;
            }
        }
        
        return cycleFormed ? ptr1 : NULL;
    }
};