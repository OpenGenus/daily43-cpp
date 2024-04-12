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

class Solution {
public:
    bool containsDuplicate(std::vector<int>& data) {
        // Use in-built sort method
        std::sort(data.begin(), data.end());
        int size = data.size() - 1, index = 0;
        for (; index < size; ++index) {
            if (data[index] == data[index + 1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Sample vector data
    std::vector<int> nums = {1, 2, 3, 1, 4, 5};

    // Create an instance of the Solution class
    Solution sol;

    // Check if the vector contains duplicates
    bool hasDuplicate = sol.containsDuplicate(nums);

    // Print the result
    if (hasDuplicate) {
        std::cout << "The vector contains duplicates." << std::endl;
    } else {
        std::cout << "The vector does not contain duplicates." << std::endl;
    }

    return 0;
}
