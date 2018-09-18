class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resPtr = new ListNode(0);
        ListNode* tempPtr = resPtr;
        int sum = 0;
        while(l1 || l2){
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            tempPtr->next = new ListNode(sum % 10);
            sum /= 10;
            tempPtr = tempPtr->next;
        }
        if(sum != 0){
            tempPtr->next = new ListNode(sum);
        }
        return resPtr->next;
    }
};