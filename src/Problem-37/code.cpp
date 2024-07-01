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
#include <vector>
#include <algorithm>
using namespace std;

int minimumBoxes(vector<int>& balls, vector<int>& capacity) {
    sort(capacity.begin(), capacity.end(), greater<int>());
    int sum = 0, i = 0;
    for (auto quantity : balls)
        sum += quantity;
    for (; i < capacity.size() && sum > 0; ++i)
        sum -= capacity[i];
    return i;
}

int main() {
    // Example test case
    vector<int> balls = {10, 15, 20};
    vector<int> capacity = {10, 20, 30, 40};
    int result = minimumBoxes(balls, capacity);
    cout << "Minimum number of boxes needed: " << result << endl;

    // Additional test cases
    vector<int> balls2 = {5, 10, 15};
    vector<int> capacity2 = {5, 5, 10, 20};
    cout << "Minimum number of boxes needed: " << minimumBoxes(balls2, capacity2) << endl;

    vector<int> balls3 = {7, 2, 4};
    vector<int> capacity3 = {3, 4, 5, 6};
    cout << "Minimum number of boxes needed: " << minimumBoxes(balls3, capacity3) << endl;

    vector<int> balls4 = {1, 2, 3};
    vector<int> capacity4 = {10};
    cout << "Minimum number of boxes needed: " << minimumBoxes(balls4, capacity4) << endl;

    return 0;
}