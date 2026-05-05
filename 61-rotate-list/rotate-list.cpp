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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp != NULL && temp->next != NULL) {
            temp = temp->next;
            n++;
        }
        if(n == 1) return head;
        ListNode* last = temp;
        k = k % n;
        if(k == 0) return head;
        int p = n - k;
        temp = head;
        while(p != 1) {
            temp = temp->next;
            p--;
        }
        ListNode* ans = temp->next;
        temp->next = NULL;
        last->next = head;
        return ans;
    }
};