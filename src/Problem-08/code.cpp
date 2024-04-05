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

void dfs(std::vector<std::vector<int>>& image, int i, int j, int originalColor, int newColor) {
    // Make sure index is valid
    // Cell has the original color to continue flood fill
    // Make sure cell does not have the new color already
    if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != originalColor) {
        return;
    }
    // Set new color to current cell
    image[i][j] = newColor;
    // All four directions: up, down, right, left
    dfs(image, i - 1, j, originalColor, newColor);
    dfs(image, i + 1, j, originalColor, newColor);
    dfs(image, i, j - 1, originalColor, newColor);
    dfs(image, i, j + 1, originalColor, newColor);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int row, int column, int newColor) {
    int originalColor = image[row][column];
    dfs(image, row, column, originalColor, newColor);
    return image;
}

int main() {
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int row = 1, column = 1, newColor = 2;

    std::vector<std::vector<int>> filledImage = floodFill(image, row, column, newColor);

    // Print the filled image
    for (const auto& row : filledImage) {
        for (int pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
