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
    void print(ListNode* head){
        auto current = head;
        while(current){
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyNode;
        ListNode* current = &dummyNode;
        int carry = 0;

        while(l1 || l2 || carry){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            ListNode* newNode = new ListNode(val1 + val2 + carry);
            carry = newNode->val / 10;
            newNode->val = newNode->val % 10;
            current->next = newNode;
            current = current->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummyNode.next;
    }
};
