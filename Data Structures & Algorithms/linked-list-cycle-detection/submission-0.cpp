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
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        std::unordered_set<ListNode*> visited{};
        ListNode* curr{head};
        while (curr->next) {
            visited.insert(curr);
            if (visited.contains(curr->next)) return true;

            curr = curr->next;
        }
        return false;
    }
};
