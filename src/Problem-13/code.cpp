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

bool isBadVersion(int version) {
    // Example complex logic to determine if a version is bad
    // In this example, versions 3, 5, 7, and 9 are considered bad
    return version == 3 || version == 5 || version == 7 || version == 9;
}

int firstBadVersion(int n) {
    int start = 1, end = n, mid = 0;
    while (end - start > 1) {
        mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }
    // 'end' is the first bad version
    return end;
}

int main() {
    int n = 10; // Assuming 10 versions for testing
    int firstBad = firstBadVersion(n);
    std::cout << "The first bad version is: " << firstBad << std::endl;

    return 0;
}
