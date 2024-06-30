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
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInteger(std::string roman) {
        std::unordered_map<char, int> mapping;
        int answer = 0, index = 0, size = roman.length();
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
        for (; index < size; ++index) {
            if (index + 1 < size && mapping[roman[index]] < mapping[roman[index + 1]]) {
                answer -= mapping[roman[index]];
            } else {
                answer += mapping[roman[index]];
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    std::string roman1 = "III";      // 3
    std::string roman2 = "IV";       // 4
    std::string roman3 = "IX";       // 9
    std::string roman4 = "LVIII";    // 58
    std::string roman5 = "MCMXCIV";  // 1994

    std::cout << "Roman: " << roman1 << " -> Integer: " << sol.romanToInteger(roman1) << std::endl;
    std::cout << "Roman: " << roman2 << " -> Integer: " << sol.romanToInteger(roman2) << std::endl;
    std::cout << "Roman: " << roman3 << " -> Integer: " << sol.romanToInteger(roman3) << std::endl;
    std::cout << "Roman: " << roman4 << " -> Integer: " << sol.romanToInteger(roman4) << std::endl;
    std::cout << "Roman: " << roman5 << " -> Integer: " << sol.romanToInteger(roman5) << std::endl;

    return 0;
}