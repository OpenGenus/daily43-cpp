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

bool canSplitArray(vector<int>& nums) {
    // Count frequency
    unordered_map<int, int> map;
    for (auto n : nums) {
        if (map.find(n) == map.end())
            map.insert(make_pair(n, 1));
        else
            ++map[n];
    }

    // Solve problem based on frequency
    for (auto frequency : map)
        if (frequency.second > 2)
            return false;
    return true;
}

int main() {
    // Example test case
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    cout << "Can split array: " << (canSplitArray(nums1) ? "Yes" : "No") << endl;

    // Additional test cases
    vector<int> nums2 = {1, 2, 2, 3, 3, 3, 4};
    cout << "Can split array: " << (canSplitArray(nums2) ? "Yes" : "No") << endl;

    vector<int> nums3 = {1, 1, 1, 2, 2, 3, 3};
    cout << "Can split array: " << (canSplitArray(nums3) ? "Yes" : "No") << endl;

    vector<int> nums4 = {4, 5, 6, 7, 8, 9};
    cout << "Can split array: " << (canSplitArray(nums4) ? "Yes" : "No") << endl;

    vector<int> nums5 = {1, 1, 2, 2, 2, 3, 4, 5};
    cout << "Can split array: " << (canSplitArray(nums5) ? "Yes" : "No") << endl;

    return 0;
}