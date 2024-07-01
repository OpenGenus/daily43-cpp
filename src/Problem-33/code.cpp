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
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Check if two binary trees are mirror images
bool isMirror(TreeNode* left, TreeNode* right) {
    // Both are empty
    if (!left && !right)
        return true;
    // Only one is empty, so it is not mirror image
    if (!left || !right)
        return false;
    // Value of current node is same
    // Check for left and right sub-trees of each node
    return (left->val == right->val) && 
           isMirror(left->left, right->right) && 
           isMirror(left->right, right->left);
}

// Check if Binary Tree is symmetric
bool isSymmetricBinaryTree(TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

// Utility function to create a binary tree from array representation (level order)
TreeNode* createTree(vector<int>& arr, int index) {
    TreeNode* root = nullptr;
    if (index < arr.size()) {
        if (arr[index] == -1)
            return nullptr;
        root = new TreeNode(arr[index]);
        root->left = createTree(arr, 2 * index + 1);
        root->right = createTree(arr, 2 * index + 2);
    }
    return root;
}

// Utility function to delete the binary tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    vector<int> tree1 = {1, 2, 2, 3, 4, 4, 3};
    vector<int> tree2 = {1, 2, 2, -1, 3, -1, 3};

    TreeNode* root1 = createTree(tree1, 0);
    TreeNode* root2 = createTree(tree2, 0);

    cout << "Tree 1 is " << (isSymmetricBinaryTree(root1) ? "symmetric." : "not symmetric.") << endl;
    cout << "Tree 2 is " << (isSymmetricBinaryTree(root2) ? "symmetric." : "not symmetric.") << endl;

    // Clean up memory
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}