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

int setBits(uint32_t N) {
    int count = 0;
    while (N) {
        N &= (N - 1);
        ++count;
    }
    return count;
}

int main() {
    uint32_t N = 29; // Example input (binary representation: 11101)
    std::cout << "Number of set bits in " << N << " is " << setBits(N) << std::endl;
    return 0;
}