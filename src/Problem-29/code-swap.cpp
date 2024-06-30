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

void moveZeroesToEnd(std::vector<int>& nums) {
    // i moves through all elements
    // j moves over non-zero elements only
    int i = 0, j = 0;
    
    // Move all the nonzero elements to the front
    for (; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    
    // Set remaining elements to 0
    // No need to swap elements
    for (; j < nums.size(); ++j) {
        nums[j] = 0;
    }
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12}; // Example input
    moveZeroesToEnd(nums);
    std::cout << "Array after moving zeroes to the end: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}