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
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();

class Solution {
public:
    Solution(){
        DPSolver; 
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = helper(head);
        if (cur && cur->val >= 10) 
            return new ListNode(cur->val/10, new ListNode(cur->val % 10, cur->next));
        
        return cur;
    }

    ListNode* helper(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = helper(head->next);
        if (!prev) {
            head->val = 2 * head->val;

        } else {
            head->val = 2 * head->val + prev->val / 10;
            prev->val = prev->val % 10;
            head->next = prev;
        }
        return head;
    }
};