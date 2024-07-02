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
#include <cmath>
using namespace std;

int divisorSubstrings(int num, int k) {
    int num_of_digits = num == 0 ? 1 : (int) log10(abs(num)) + 1;
    long window_power = pow(10, k);
    int counts = num_of_digits - k + 1;
    int current_window = num % window_power;
    int remain = num / window_power;
    int beautyCount = 0;
    while (counts) {
        --counts;
        if (current_window!= 0 && num % current_window == 0)
            ++beautyCount;
        current_window = (remain % 10) * (window_power/10) + current_window / 10;
        remain = remain / 10;
    }
    return beautyCount;
}

int main() {
    // Example test cases
    int num1 = 120;
    int k1 = 2;
    cout << "Number of divisor substrings: " << divisorSubstrings(num1, k1) << endl; // Expected output: 2

    int num2 = 430043;
    int k2 = 2;
    cout << "Number of divisor substrings: " << divisorSubstrings(num2, k2) << endl; // Expected output: 2

    // Additional test cases
    int num3 = 555;
    int k3 = 1;
    cout << "Number of divisor substrings: " << divisorSubstrings(num3, k3) << endl; // Expected output: 3

    int num4 = 111;
    int k4 = 3;
    cout << "Number of divisor substrings: " << divisorSubstrings(num4, k4) << endl; // Expected output: 1

    return 0;
}