/* **************************************************************************
 * Copyright 2024 The OpenGenus.org Authors. All Rights Reserved.
 *
 * Code for the book "DAILY 43: Algorithmic Problems for Coding Interviews: Easy level, C++ edition"
 *
 * Licensed under the GNU General Public License, Version 3.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.gnu.org/licenses/gpl-3.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For details about the book, please visit: https://www.amazon.com/dp/B0CZJNBLQS
 * *************************************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr)
        return list2;
    if(list2 == nullptr)
        return list1;
    
    // ptr = merged linked list
    // set ptr to the first smaller value of linked list
    ListNode * ptr = list1;
    if(list1->val > list2->val) {
        ptr = list2;
        list2 = list2->next;
    }
    else {
        list1 = list1->next;
    }
    
    // Traverse both linked lists
    // merged based on the values one by one
    ListNode *curr = ptr;
    while(list1 && list2) {
        if(list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        }
        else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    
    // If list1 is over, merge rest of list2
    if(!list1)
        curr->next = list2;
    // or merge rest of list1
    else
        curr->next = list1;
    
    return ptr;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // Test case 2
    ListNode* list3 = new ListNode(7);
    list3->next = new ListNode(8);
    list3->next->next = new ListNode(9);

    ListNode* list4 = new ListNode(4);
    list4->next = new ListNode(6);
    list4->next->next = new ListNode(10);

    std::cout << "\nList 3: ";
    printList(list3);

    std::cout << "List 4: ";
    printList(list4);

    ListNode* mergedList2 = mergeTwoLists(list3, list4);

    std::cout << "Merged List 2: ";
    printList(mergedList2);

    return 0;
}
