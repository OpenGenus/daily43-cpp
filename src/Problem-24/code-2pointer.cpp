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

class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || countA > 0))
                S[i--] == '#' ? ++countA : --countA;
            while (j >= 0 && (T[j] == '#' || countB > 0))
                T[j--] == '#' ? ++countB : --countB;
            if (i < 0 || j < 0)
                return i == j;
            if (S[i--] != T[j--])
                return false;
        }
        return i == j;
    }
};

int main() {
    Solution sol;
    std::string S1 = "ab#c", T1 = "ad#c"; // true
    std::string S2 = "ab##", T2 = "c#d#"; // true
    std::string S3 = "a##c", T3 = "#a#c"; // true
    std::string S4 = "a#c", T4 = "b";     // false

    std::cout << "S: " << S1 << ", T: " << T1 << " -> " << (sol.backspaceCompare(S1, T1) ? "true" : "false") << std::endl;
    std::cout << "S: " << S2 << ", T: " << T2 << " -> " << (sol.backspaceCompare(S2, T2) ? "true" : "false") << std::endl;
    std::cout << "S: " << S3 << ", T: " << T3 << " -> " << (sol.backspaceCompare(S3, T3) ? "true" : "false") << std::endl;
    std::cout << "S: " << S4 << ", T: " << T4 << " -> " << (sol.backspaceCompare(S4, T4) ? "true" : "false") << std::endl;

    return 0;
}