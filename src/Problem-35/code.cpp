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

string triangleType(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums[0] + nums[1] <= nums[2])
        return "none";
    if (nums[0] == nums[1] && nums[1] == nums[2])
        return "equilateral";
    if (nums[0] == nums[1] || nums[1] == nums[2])
        return "isosceles";
    return "scalene";
}

int main() {
    vector<int> nums = {3, 4, 5};
    string type = triangleType(nums);

    cout << "Triangle type: " << type << endl;

    // Additional test cases
    vector<int> nums2 = {2, 2, 2};
    cout << "Triangle type: " << triangleType(nums2) << endl;

    vector<int> nums3 = {2, 2, 3};
    cout << "Triangle type: " << triangleType(nums3) << endl;

    vector<int> nums4 = {1, 2, 3};
    cout << "Triangle type: " << triangleType(nums4) << endl;

    return 0;
}