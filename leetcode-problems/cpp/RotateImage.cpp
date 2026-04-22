
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; i < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int x = 0; x < n; x++){
            reverse(matrix.begin(), matrix.end());
        }
    }
};