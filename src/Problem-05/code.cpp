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

bool isPalindrome(std::string s) {
    int start = 0, end = s.size()-1;
    while(start <= end) {
        if(!isalnum(s[start])) {
            ++start;
        }
        else if(!isalnum(s[end])) {
            --end;
        }
        else if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        else {
            ++start;
            --end;
        }
    }
    return true;
}

int main() {
    std::string input1 = "A man, a plan, a canal: Panama";
    std::string input2 = "opengenus is opensource";

    if(isPalindrome(input1)) {
        std::cout << "\"" << input1 << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input1 << "\" is not a palindrome." << std::endl;
    }

    if(isPalindrome(input2)) {
        std::cout << "\"" << input2 << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input2 << "\" is not a palindrome." << std::endl;
    }

    return 0;
}
