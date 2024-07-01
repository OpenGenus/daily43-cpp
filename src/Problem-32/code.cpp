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

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Check Palindrome Linked List
    // using slow and fast pointers
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        // Slow and fast pointers
        // Identify middle node with slow pointer
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half of Linked List
        prev = slow;
        slow = slow->next;
        prev->next = NULL;
        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // Check palindrome by comparing the two halves
        // One half: From head to middle
        // Second half: From middle to end (reversed half)
        fast = head;
        slow = prev;
        while (slow) {
            if (fast->val != slow->val)
                return false;
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    std::cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    bool palindrome = solution.isPalindrome(head);
    if (palindrome)
        std::cout << "The linked list is a palindrome." << std::endl;
    else
        std::cout << "The linked list is not a palindrome." << std::endl;

    // Clean up memory
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}