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
#include <climits>

int maxProfit(std::vector<int>& prices) {
    int last_sell_price = INT_MAX;
    int max_profit = 0;
    int profit_today = 0;

    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < last_sell_price) {
            last_sell_price = prices[i];
        }
        profit_today = prices[i] - last_sell_price;
        if(max_profit < profit_today) {
            max_profit = profit_today;
        }
    }
    return max_profit;
}

int main() {
    // Test case 1
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int max_profit1 = maxProfit(prices1);
    std::cout << "Max Profit Test Case 1: " << max_profit1 << std::endl;

    // Test case 2
    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    int max_profit2 = maxProfit(prices2);
    std::cout << "Max Profit Test Case 2: " << max_profit2 << std::endl;

    // Test case 3
    std::vector<int> prices3 = {3, 3, 11, 3, 3};
    int max_profit3 = maxProfit(prices3);
    std::cout << "Max Profit Test Case 3: " << max_profit3 << std::endl;

    return 0;
}
