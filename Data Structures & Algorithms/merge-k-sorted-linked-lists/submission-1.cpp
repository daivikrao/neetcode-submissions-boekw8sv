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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        for(int i=0;i<n;i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        while(!pq.empty()){
            pair<int,ListNode*> f = pq.top();
            pq.pop();

            dummy->next = f.second;
            dummy = dummy->next;

            if(f.second->next){
                pq.push({f.second->next->val,f.second->next});
            }
        }

        return temp->next;
    }
};
