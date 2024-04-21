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
        ListNode* temp = head;
        // preprocessing
        for (int i = 0 ; i < n; i++) {
            // if processing failed means there is no valid node to remove, just return the head
            // increase inefficiency, but apparently testcase assumes input is valid
            // if (temp == nullptr) return head;
            temp = temp->next;
        }
        // edge case whereby we remove the first element
        if (temp == nullptr) return head->next;
        temp = temp->next;
        ListNode* tempTwo = head;
        // temp is now n + 1th node ahead, if it reach the end, tempTwo will be the n + 1th node from the back
        while (temp != nullptr) {
            temp = temp->next;
            tempTwo = tempTwo->next;
        }
        // remove the nth node by joining n+1th to n-1th if valid node
        if (tempTwo != nullptr && tempTwo->next !=nullptr) {
            tempTwo->next = tempTwo->next->next;
        }
        // return head
        return head;
    }
};