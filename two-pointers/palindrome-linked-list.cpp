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
    ListNode* reverselist(ListNode* head){
        if(head == NULL || head -> next == NULL)return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL && head -> next != NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* newhead = reverselist(slow -> next);
        ListNode* first = head;
        ListNode* second = newhead;
        while(second != NULL){
            if(first -> val != second -> val){
                reverselist(newhead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverselist(newhead);
        return true;
    }
};