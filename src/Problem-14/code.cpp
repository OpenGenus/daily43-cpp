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

int climbStairs(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int one_step_before = 2, two_steps_before = 1, all_ways = 0;

    for (int i = 2; i < n; i++) {
        all_ways = one_step_before + two_steps_before;
        two_steps_before = one_step_before;
        one_step_before = all_ways;
    }

    return all_ways;
}

int main() {
    int n = 5; // Example input
    int ways = climbStairs(n);
    std::cout << "Number of ways to climb " << n << " stairs: " << ways << std::endl;

    return 0;
}
