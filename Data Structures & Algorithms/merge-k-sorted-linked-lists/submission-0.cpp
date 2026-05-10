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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummyNode;
        ListNode* sortedList = &dummyNode;
        while(list1 && list2){
            if(list1->val <= list2->val){
                sortedList->next = list1;
                list1 = list1->next;
            } else {
                sortedList->next = list2;
                list2 = list2->next;
            }
            sortedList = sortedList->next;
        }

        sortedList->next = list1 ? list1 : list2;

        return dummyNode.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* sortedList = nullptr;
        for(const auto& currentList : lists){
            sortedList = mergeTwoLists(sortedList, currentList);
        }
        return sortedList;
    }
};
