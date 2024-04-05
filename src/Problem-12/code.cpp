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

class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;
public:
    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        peek();
        const int val = out_stack.top();
        out_stack.pop();
        return val;
    }

    int peek() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Peek: " << q.peek() << std::endl;
    std::cout << "Pop: " << q.pop() << std::endl;
    std::cout << "Peek: " << q.peek() << std::endl;

    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
