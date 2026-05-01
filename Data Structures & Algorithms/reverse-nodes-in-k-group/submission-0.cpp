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
    ListNode* reverseList(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* current = temp;

        while(current!=NULL){
            ListNode* n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* temp,int k){
        k -= 1;
        while(temp!= NULL && k > 0){
            temp = temp->next;
            k -= 1;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevList = NULL;

        while(temp!=NULL){
            ListNode* kthNode = findKthNode(temp,k);
            if(kthNode == NULL){
                if(prevList){
                    prevList->next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* currNode = reverseList(temp);
            if(temp == head){
                head = currNode;
            }else{
                prevList->next = currNode;
            }
            prevList = temp;
            temp = nextNode;
        }
        return head;
    }
};
