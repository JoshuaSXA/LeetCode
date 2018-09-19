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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        /*
        if(root == NULL){
            return res;
        }
        */
        ListNode* ptr = root;
        int length = 0;
        while(ptr != NULL){
            ++length;
            ptr = ptr->next;
        }
        int longerListNum = length % k;
        int shorterListLength = (int)(length / k);
        ptr = root;
        for(int i = 0; i < k; ++i){
            int len = i < longerListNum ? shorterListLength + 1 : shorterListLength;
            res.push_back(ptr);
            ptr = getSplitList(ptr, len);
        }
        return res;
    }
    
    ListNode* getSplitList(ListNode* head, int length){
        if(length == 0 || head == NULL){
            return NULL;
        }
        ListNode* ptr = head;
        ListNode* tmpPtr = NULL;
        for(int i = 0; i < length; ++i){
            if(i == length - 1){
                tmpPtr = ptr;
            }
            ptr = ptr->next;
        }
        tmpPtr ->next = NULL;
        return ptr;
    }
    
    
};