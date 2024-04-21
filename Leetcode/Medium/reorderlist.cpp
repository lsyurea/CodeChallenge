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
    void FastIO() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    void reorderList(ListNode* head) {
        map(head);
    }

    ListNode* map(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr) return head;
        // cout << "This is the value: " << head->val << "\n";
        // reorder by taking L0 -> Ln -> L1 -> Ln-1
        // always reverse the next (n^2 algo)
        ListNode* curNode = getTail(head);
        ListNode* nextNode = curNode->next;
        curNode->next = nullptr;
        ListNode* temp = head->next;
        nextNode->next = map(temp);
        head->next = nextNode;
        return head;
    }

    // Do not need to use reverse
    // ListNode* reverse(ListNode* curNode) {
    //     if (curNode == nullptr || curNode->next == nullptr) return curNode;
    //     ListNode* nextNode = reverse(curNode->next);
    //     nextNode->next = curNode;
    //     curNode->next = nullptr;
    //     return curNode;
    // }

    ListNode* getTail(ListNode* curNode) {
        if (curNode == nullptr || curNode->next == nullptr || curNode->next->next == nullptr) return curNode;
        return getTail(curNode->next);
    }
};