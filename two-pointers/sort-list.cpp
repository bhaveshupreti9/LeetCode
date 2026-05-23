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
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                temp-> next = l1;
                temp = l1;
                l1 = l1 -> next;
            }
            else{
                temp-> next = l2;
                temp = l2;
                l2 = l2 -> next;
            }
            if(l1)temp -> next = l1;
            else temp -> next = l2;
        }
        return dummy -> next;
    }
    ListNode* mergesort(ListNode* head){
        if(head == nullptr || head -> next == NULL)return head;
        ListNode* middle = findmid(head);
        ListNode* left = head;
        ListNode* right = middle -> next;
        middle -> next = NULL;
        
        left = mergesort(left);
        right = mergesort(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};