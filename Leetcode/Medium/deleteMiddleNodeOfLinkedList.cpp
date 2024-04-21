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
    ListNode* deleteMiddle(ListNode* head) {
        vector<ListNode*> v;
        while(head) {
            v.push_back(head);
            head = head->next;
        }
        // floor division
        int i = v.size() / 2;

        if (i == 0) return v.size() > i + 1 ? v[i + 1] : nullptr;
        
        if (i + 1 <  v.size())
            v[i - 1]->next = v[i + 1];
        else 
            v[i - 1]->next = nullptr;
        return v[0];
    }
};