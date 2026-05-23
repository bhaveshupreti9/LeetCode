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
        if(head == NULL || head -> next == NULL)return head;
        ListNode* temp = head;
        int i = 1;
        while(temp -> next != NULL){
            i++;
            temp = temp -> next;
        }
        k = k%i;
        if(k == 0)return head;
        temp -> next = head;
        ListNode* tail = head;
        int x = 1;
        while(x < i - k){
            tail = tail -> next;
            x++;
        }
        
        head = tail -> next;
        tail -> next = NULL;
        return head;
    }
};