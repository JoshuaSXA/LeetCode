/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(head == NULL){
            return NULL;
        }
        
        map<RandomListNode*, int> ptrToIndex;
        map<int, vector<int>> randPtrMap;
        vector<RandomListNode*> indexToPtr;
        
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr != NULL){
            ptrToIndex[ptr] = i;
            ptr = ptr->next;
            ++i;
        }

    
        for(ptr = head, i = 0; ptr != NULL; ++i, ptr = ptr->next){
            if(ptr->random != NULL){
                randPtrMap[ptrToIndex[ptr->random]].push_back(i);
            }else{
                continue;
            }
        }
        
        RandomListNode *preHead = new RandomListNode(0);
        RandomListNode *newPtr = preHead, *tmpPtr;
        
        for(ptr = head; ptr != NULL;ptr = ptr->next, newPtr = newPtr->next){
            newPtr->next = new RandomListNode(ptr->label);
            indexToPtr.push_back(newPtr->next);
        }
        
        for(newPtr = preHead->next, i = 0; newPtr != NULL; ++i, newPtr = newPtr->next){
            for(int j = 0; j < randPtrMap[i].size(); ++j){
                tmpPtr = indexToPtr[randPtrMap[i][j]];
                tmpPtr->random = newPtr;
            }
        }
        
        return preHead->next;
        
    }
};