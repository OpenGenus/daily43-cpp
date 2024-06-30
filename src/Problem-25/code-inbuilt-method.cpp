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

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> answer(n + 1);
        answer[0] = 0;
        for (int i = 1; i <= n; ++i)
            answer[i] = __builtin_popcount(i);
        return answer;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::vector<int> result = sol.countBits(n);

    std::cout << "Number of set bits from 0 to " << n << " are:" << std::endl;
    for (int i = 0; i <= n; ++i) {
        std::cout << "Number " << i << " has " << result[i] << " set bits." << std::endl;
    }

    return 0;
}