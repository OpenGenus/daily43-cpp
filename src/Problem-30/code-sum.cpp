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

int missingNumber(std::vector<int>& nums) {
    int index = 0, size = nums.size();
    // N will be missed in the loop
    int missing = size;
    // expected_sum = size * (size+1) / 2;
    // Not computing directly to avoid overflow
    for (; index < size; ++index) {
        // sum = sum + nums[index]
        // expected = expected + index
        // missing = expected - sum
        missing = missing + (index - nums[index]);
    }
    return missing;
}

int main() {
    std::vector<int> nums = {3, 0, 1}; // Example input
    std::cout << "Missing number: " << missingNumber(nums) << std::endl;

    std::vector<int> nums2 = {9,6,4,2,3,5,7,0,1}; // Another example input
    std::cout << "Missing number: " << missingNumber(nums2) << std::endl;

    return 0;
}