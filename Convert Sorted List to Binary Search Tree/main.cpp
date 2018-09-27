/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }else if(head->next == NULL){
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        
        ListNode *ptr = head;
        
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        
        TreeNode *root = BinaryTreePartition(head, ptr);
        
        return root;
    }
    
    TreeNode* BinaryTreePartition(ListNode* leftPtr, ListNode* rightPtr){
        
        if(leftPtr == NULL){
            return NULL;
        }else if(leftPtr == rightPtr){
            TreeNode *root = new TreeNode(leftPtr->val);
            return root;
        }
        
        
        ListNode *ptr1 = leftPtr, *ptr2 = leftPtr, *tmpPtr = leftPtr, *postPtr = NULL;
        
        while(ptr2->next != NULL && ptr2->next->next != NULL){
            tmpPtr = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        
        TreeNode *root = new TreeNode(ptr1->val);
        postPtr = ptr1->next;
        tmpPtr->next = NULL;
        root->left = ptr1 == leftPtr ? NULL : BinaryTreePartition(leftPtr, tmpPtr);
        rightPtr->next = NULL;
        root->right = BinaryTreePartition(postPtr, rightPtr);
        return root;
        
    }
    
    
};