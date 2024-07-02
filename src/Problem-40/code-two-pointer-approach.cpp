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
using namespace std;

// Two pointer approach
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    // i is for first string S (subsequence)
    // j is for second string T
    while(i < s.length() && j < t.length()){
        if(s[i] == t[j])
            ++i;
        ++j;
    }
    return i == s.length();
}

int main() {
    // Example test cases
    string s1 = "abc", t1 = "ahbgdc";
    cout << "Is '" << s1 << "' a subsequence of '" << t1 << "'? " 
         << (isSubsequence(s1, t1) ? "Yes" : "No") << endl;

    string s2 = "axc", t2 = "ahbgdc";
    cout << "Is '" << s2 << "' a subsequence of '" << t2 << "'? " 
         << (isSubsequence(s2, t2) ? "Yes" : "No") << endl;

    // Additional test cases
    string s3 = "abc", t3 = "abcd";
    cout << "Is '" << s3 << "' a subsequence of '" << t3 << "'? " 
         << (isSubsequence(s3, t3) ? "Yes" : "No") << endl;

    string s4 = "ace", t4 = "abcde";
    cout << "Is '" << s4 << "' a subsequence of '" << t4 << "'? " 
         << (isSubsequence(s4, t4) ? "Yes" : "No") << endl;

    string s5 = "xyz", t5 = "xaybz";
    cout << "Is '" << s5 << "' a subsequence of '" << t5 << "'? " 
         << (isSubsequence(s5, t5) ? "Yes" : "No") << endl;

    return 0;
}