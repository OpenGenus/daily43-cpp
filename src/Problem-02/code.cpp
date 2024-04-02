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
#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> st;
    for(auto i : s) {
        // If a starting bracket, insert it
        if(i == '(' || i == '{' || i == '[')
            st.push(i);
        else {
            // If current character is a closing bracket and top of stack is the corresponding open bracket,
            // remove top of stack and ensure stack is not empty
            if (!st.empty() && ((st.top() == '(' && i == ')') || (st.top() == '[' && i == ']') || (st.top() == '{' && i == '}'))) {
                st.pop();
            }
            // no matching bracket detected
            else
                return false;
        }
    }
    // Check all brackets have been matched
    return st.empty();
}

int main() {
    std::string input1 = "((()))";  // valid
    std::string input2 = "{[()]()}"; // valid
    std::string input3 = "({[}])";   // invalid

    std::cout << "Input 1 is " << (isValid(input1) ? "valid" : "invalid") << std::endl;
    std::cout << "Input 2 is " << (isValid(input2) ? "valid" : "invalid") << std::endl;
    std::cout << "Input 3 is " << (isValid(input3) ? "valid" : "invalid") << std::endl;

    return 0;
}
