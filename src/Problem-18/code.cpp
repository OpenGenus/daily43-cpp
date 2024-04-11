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
#include <algorithm>

std::string addBinary(std::string a, std::string b) {
    std::string res;
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        carry = sum > 1 ? 1 : 0;
        res += std::to_string(sum % 2);
    }
    if(carry) res += std::to_string(carry);
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string a = "101";
    std::string b = "1101";
    std::string result = addBinary(a, b);
    std::cout << "The sum of " << a << " and " << b << " in binary is: " << result << std::endl;
    return 0;
}
