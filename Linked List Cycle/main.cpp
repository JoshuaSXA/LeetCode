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
    /*
    //This is a trick.
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        
        while(ptr != NULL){
            if(ptr->val == 0){
                return true;
            }else{
                ptr->val = 0;
            }
            ptr = ptr->next;
        }
        return false;
    }
    */
    
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head, *_ptr = head;
    
        while(ptr != NULL && ptr->next != NULL){
            if(ptr->next == _ptr){
                return true;
            }else{
                ptr = ptr->next->next;
                _ptr = _ptr->next;
            }
        }
        
        return false;
    }
};