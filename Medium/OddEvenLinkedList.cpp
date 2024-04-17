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
    ListNode* oddEvenList(ListNode* head) {
        // 0, 1 or 2 elements do not need to change
        if (!head || !head->next || !head->next->next) return head;
        // declare odd head which is fixed
        // declare odd tail which adds the next element
        // declare even which is the next next element
        ListNode *odd_head = head->next, *odd_tail = head->next,
            *even = head->next->next;
        // next element of head must be fixed to even
        head->next = even;

        // ensure that next element of even is present to add to odd tail
        while (even && even->next) {
            // add to next element of odd tail
            odd_tail->next = even->next;
            // move odd tail to next odd tail
            odd_tail = odd_tail->next;
            // add the even to the correct element
            even->next = even->next->next;
            // if next even is null, do the processing
            if (!even->next) {
                even->next = odd_head;
                odd_tail->next == nullptr;
                return head;
            }
            even = even->next;
        }     
        even->next = odd_head;
        odd_tail->next = nullptr;
        return head;
    }
    // ListNode* helper(ListNode* even, ListNode* odd_head, ListNode* odd_tail) {
    //     if (!even) return odd_head;
    //     if (!even->next) {
    //         even->next = odd_head;
    //         return even;
    //     }
    //     ListNode* nxt = even->next->next;
    //     if (!odd_head) {
    //         odd_head = even->next;
    //         odd_tail = even->next;
    //         odd_tail->next = nullptr;
    //     } else {
    //         odd_tail->next = even->next;
    //         odd_tail = odd_tail->next;
    //         odd_tail->next = nullptr;
    //     }
    //     even->next = helper(nxt, odd_head, odd_tail);
    //     return even;
    // }
};