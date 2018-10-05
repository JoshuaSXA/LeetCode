/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) {
            return head;
        }
        
        stack<Node*> NodeStack;
        
        Node* ptr = head, *tmpPtr = NULL;
        
        while(ptr != NULL || !NodeStack.empty()) {
            
            if(ptr->next == NULL && !NodeStack.empty()) {
                tmpPtr = NodeStack.top();
                NodeStack.pop();
                if(tmpPtr == NULL) {
                    continue;
                }
                ptr->next = tmpPtr;
                tmpPtr->prev = ptr; 
            }
            
            if(ptr->child != NULL) {
                NodeStack.push(ptr->next);
                ptr->next = ptr->child;
                ptr->child->prev = ptr;
                ptr->child = NULL;
            }
            
            ptr = ptr->next;
            
        }
        
        return head;
        
    }
};