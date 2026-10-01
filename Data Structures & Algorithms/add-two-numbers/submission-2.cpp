/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if(l1 == NULL){
            return l2;
        }

        if(l2 == NULL){
            return l1;
        }

        ListNode* head = NULL;

        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            ListNode* node = new ListNode(sum%10);
            node->next = head;
            head = node;
            carry = sum/10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1!=NULL){
            int sum = l1->val + carry;
            ListNode* node = new ListNode(sum%10);
            node->next = head;
            head = node;
            carry = sum/10;

            l1 = l1->next;
        }

        while(l2!=NULL){
            int sum = l2->val + carry;
            ListNode* node = new ListNode(sum%10);
            node->next = head;
            head = node;
            carry = sum/10;

            l2 = l2->next;
        }

        if(carry > 0){
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }

        ListNode* prev = NULL;
        ListNode* current = head;

        while(current!=NULL){
            ListNode* n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }

        return prev;
    }
};
