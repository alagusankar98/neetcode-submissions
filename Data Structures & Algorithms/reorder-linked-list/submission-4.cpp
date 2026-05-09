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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Middle node is 'slow'
        if(prev) prev->next = nullptr; // Detach first half of list

        // print(slow);
        // print(head);

        // Reverse second half of list
        prev = nullptr;
        ListNode* current = slow;
        while(current){
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        ListNode* list1 = head;
        ListNode* list2 = prev;
        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* newList = &dummyNode;
        // print(list1);
        // print(list2);

        // Merge both lists starting from list1
        while(list1){
            // Add node from list1
            newList->next = list1;
            list1 = list1->next;
            newList = newList->next;

            // Add node from list2
            newList->next = list2;
            list2 = list2->next;
            newList = newList->next;
        }

        // print(list1);
        // print(list2);
        // print(dummyNode.next);
    }
};
