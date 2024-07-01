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
#include <algorithm>
using namespace std;

int missingInteger(vector<int>& nums) {
    if (nums.empty()) return 1; // If the list is empty, the smallest positive integer is 1.
    
    int countSum = nums[0];
    int i = 1, size = nums.size();
    // Calculate longest prefix sum
    for (; i < size; ++i) {
        if (nums[i - 1] + 1 == nums[i])
            countSum += nums[i];
        else
            break;
    }
    // Sort the array
    sort(nums.begin(), nums.end());
    // Find the missing integer
    for (i = 0; i < size; ++i) {
        if (countSum == nums[i]) {
            ++countSum;
        }
    }
    return countSum;
}

int main() {
    // Example test case
    vector<int> nums = {1, 2, 4, 5, 6};
    int result = missingInteger(nums);
    cout << "Missing integer: " << result << endl;

    // Additional test cases
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Missing integer: " << missingInteger(nums2) << endl;

    vector<int> nums3 = {2, 3, 4, 7, 8};
    cout << "Missing integer: " << missingInteger(nums3) << endl;

    vector<int> nums4 = {1, 3, 6, 4, 1, 2};
    cout << "Missing integer: " << missingInteger(nums4) << endl;

    return 0;
}