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

int majorityElement(std::vector<int>& num) {
    int major = num[0], count = 1, size = num.size();
    for(int i = 1; i < size; ++i) {
        if(count == 0) {
            ++count;
            major = num[i];
        } else if(major == num[i]) {
            ++count;
        } else {
            --count;
        }
    }
    return major;
}

int main() {
    std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4}; // Example input
    int majority = majorityElement(nums);
    std::cout << "The majority element is: " << majority << std::endl;

    return 0;
}
