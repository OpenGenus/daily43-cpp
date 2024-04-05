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
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// -1 if sub-tree at root is unbalanced
// else the actual height of the sub-tree at root
int Height(const TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    // Check if left or right sub-tree is unbalanced
    // Check height difference of left and right sub-tree
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
        return -1;
    // Actual height
    return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    if (Height(root) == -1)
        return false;
    return true;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bool balanced = isBalanced(root);
    if (balanced) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
