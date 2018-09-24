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
    void reorderList(ListNode* head) {
        if(head == NULL){
            return;
        }
        vector<ListNode*> nodeMap;
        ListNode* ptr = head;
        while(ptr != NULL){
            nodeMap.push_back(ptr);
            ptr = ptr->next;
        }
        int len = nodeMap.size();
        ListNode* resPtr = new ListNode(0);
        ptr = resPtr;
        
        for(int i = 0; i < len && ptr != NULL; ++i){
            if(i < len - 1 - i){
                ptr->next = nodeMap[i];
                ptr = ptr->next;
                ptr->next = nodeMap[len - 1 - i];
            }else if(i == len - 1 - i){
                ptr->next = nodeMap[i];
            }else if(i > len - 1 - i){
                break;
            }
            
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return;
    }
    
};