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
#include <cstdint>
#include <bitset>

uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0b11111111000000001111111100000000) >> 8) | ((n & 0b00000000111111110000000011111111) << 8);
    n = ((n & 0b11110000111100001111000011110000) >> 4) | ((n & 0b00001111000011110000111100001111) << 4);
    n = ((n & 0b11001100110011001100110011001100) >> 2) | ((n & 0b00110011001100110011001100110011) << 2);
    n = ((n & 0b10101010101010101010101010101010) >> 1) | ((n & 0b01010101010101010101010101010101) << 1);
    return n;
}

int main() {
    uint32_t num = 43261596; // Example input (binary: 00000010100101000001111010011100)
    uint32_t reversed = reverseBits(num);
    std::cout << "Original: " << num << " (" << std::bitset<32>(num) << ")" << std::endl;
    std::cout << "Reversed: " << reversed << " (" << std::bitset<32>(reversed) << ")" << std::endl;

    return 0;
}