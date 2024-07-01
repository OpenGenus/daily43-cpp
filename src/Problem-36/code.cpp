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

int returnToBoundaryCount(vector<int>& nums) {
    int position = 0, boundary_count = 0;
    for (int step : nums) {
        position += step;
        if (position == 0) {
            ++boundary_count;
        }
    }
    return boundary_count;
}

int main() {
    // Example test case
    vector<int> nums = {1, -1, 2, -2, 3, -3};
    int count = returnToBoundaryCount(nums);
    cout << "Boundary return count: " << count << endl;

    // Additional test cases
    vector<int> nums2 = {1, 2, -3, 1, -1};
    cout << "Boundary return count: " << returnToBoundaryCount(nums2) << endl;

    vector<int> nums3 = {1, -1, 1, -1};
    cout << "Boundary return count: " << returnToBoundaryCount(nums3) << endl;

    vector<int> nums4 = {1, 2, 3, -6};
    cout << "Boundary return count: " << returnToBoundaryCount(nums4) << endl;

    return 0;
}