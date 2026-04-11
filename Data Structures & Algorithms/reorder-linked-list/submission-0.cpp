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
    ListNode* reverse(ListNode* head){
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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        if(head == NULL || head->next == NULL){
            return;
        }

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* A = head;
        ListNode* B = slow->next;

        B = reverse(B);

        slow->next = NULL;
        ListNode* dummy = new ListNode(-1);

        while(A!=NULL && B!=NULL){
            dummy->next = A;
            A = A->next;
            dummy = dummy->next;

            dummy->next = B;
            B = B->next;
            dummy = dummy->next;
        }

        if(A!=NULL){
            dummy->next = A;
        }

        if(B!=NULL){
            dummy->next = B;
        }
    }
};
