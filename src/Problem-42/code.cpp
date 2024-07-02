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

int minCostClimbingStairs(vector<int>& cost) {
    int N = cost.size();
    for (int i = 2; i < N; ++i) {
        cost[i] += min(cost[i-1], cost[i-2]);
    }
    return min(cost[N-1], cost[N-2]);
}

int main() {
    // Example test cases
    vector<int> cost1 = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost2) << endl;

    // Additional test cases
    vector<int> cost3 = {0, 0, 0, 0};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost3) << endl;

    vector<int> cost4 = {1, 2, 3, 4, 5};
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost4) << endl;

    return 0;
}