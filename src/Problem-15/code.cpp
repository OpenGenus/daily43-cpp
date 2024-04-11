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
#include <string>

int longestPalindrome(std::string s) {
    int frequency[128] = {}, odd_frequency = 0;
    for(auto c:s)
        ++frequency[c];
    for(auto i:frequency)
        odd_frequency += i & 1;
    return s.size() - odd_frequency + (odd_frequency > 0);
}

int main() {
    std::string input = "abccccdd"; // Example input
    int length = longestPalindrome(input);
    std::cout << "Length of the longest palindrome: " << length << std::endl;

    return 0;
}
