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
#include <unordered_map>

using namespace std;

// Index of two sum
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> HashSet;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        // Find if the target sum is achieved
        if (HashSet.count(complement)) {
            return {HashSet[complement], i};
        }
        // Insert current element in set with index
        HashSet[nums[i]] = i;
    }
    return {};
}

int main() {
    // Input data: 2D array with each row representing a test case
    vector<vector<int>> inputs = {
        {2, 7, 11, 15, 3},    // Test Case 1
        {3, 2, 4},            // Test Case 2
        {3, 3},               // Test Case 3
        {-1, -2, -3, -4, -5}, // Test Case 4
        {0, 4, 3, 0},         // Test Case 5
    };

    // Target values corresponding to each test case
    vector<int> targets = {9, 6, 6, -8, 0};

    // Process each test case
    for (int i = 0; i < inputs.size(); ++i) {
        try {
            // Call the twoSum function
            vector<int> result = twoSum(inputs[i], targets[i]);

            // Print the input and output
            cout << "Test Case " << i + 1 << ":\n";
            cout << "Input: [";
            for (int num : inputs[i]) {
                cout << num << " ";
            }
            cout << "]\n";
            cout << "Target: " << targets[i] << "\n";
            
            // Output the result
            cout << "Output: [";
            for (int num : result) {
                cout << num << " ";
            }
            cout << "]\n\n";
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
