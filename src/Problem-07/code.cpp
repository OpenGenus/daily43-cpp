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

bool isAnagram(std::string A, std::string B) {
    int count[26] = {0};
    // Count the frequency of characters in string A
    for (char x : A) {
        ++count[x - 'a'];
    }
    // Decrement the frequency of characters in string B
    for (char x : B) {
        --count[x - 'a'];
    }
    // Check if any character has non-zero frequency
    for (int val : count) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input1 = "anagram";
    std::string input2 = "nagaram";

    if(isAnagram(input1, input2)) {
        std::cout << "\"" << input1 << "\" and \"" << input2 << "\" are anagrams." << std::endl;
    } else {
        std::cout << "\"" << input1 << "\" and \"" << input2 << "\" are not anagrams." << std::endl;
    }

    return 0;
}
