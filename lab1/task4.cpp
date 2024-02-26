/*programmer:Syed Fahad Faheem Shah
 roll num: (23k-0062)
  date:2/26/2024
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int max_area(int *height, int n) {
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            max_area = max(max_area, abs(i - j) *min(height[i], height[j]));
        }
    }

    return max_area;
}

int main() {

    int heights[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << max_area(heights, 9) <<endl;

    return 0;
}
