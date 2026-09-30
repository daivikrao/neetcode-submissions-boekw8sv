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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int count = 0;

        while(current){
            current = current->next;
            count += 1;
        }

        if(head == NULL){
            return NULL;
        }

        if(count == 1){
            return NULL;
        }

        int front = count - n;
        if(front == 0){
            return head->next;
        }else{
            ListNode* temp = head;
            while(front!=1){
                temp = temp->next;
                front -= 1;
            }
            temp->next = temp->next->next;
            return head;
        }
        return head;
    }
};
