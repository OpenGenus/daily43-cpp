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
#include <cstring>
using namespace std;

bool divisorGame(int N) {
    bool dp[N + 1];
    memset(dp, false, sizeof(dp));
    
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0 && !dp[i - j]) {
                dp[i] = true;
            }
        }
    }
    
    return dp[N];
}

int main() {
    // Example test cases
    int N1 = 2;
    cout << "Does Alice win with N = " << N1 << "? " << (divisorGame(N1) ? "Yes" : "No") << endl;

    int N2 = 3;
    cout << "Does Alice win with N = " << N2 << "? " << (divisorGame(N2) ? "Yes" : "No") << endl;

    // Additional test cases
    int N3 = 4;
    cout << "Does Alice win with N = " << N3 << "? " << (divisorGame(N3) ? "Yes" : "No") << endl;

    int N4 = 5;
    cout << "Does Alice win with N = " << N4 << "? " << (divisorGame(N4) ? "Yes" : "No") << endl;

    int N5 = 6;
    cout << "Does Alice win with N = " << N5 << "? " << (divisorGame(N5) ? "Yes" : "No") << endl;

    return 0;
}