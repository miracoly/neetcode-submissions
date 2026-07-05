class Solution {
private:
int findRow(vector<vector<int>>& matrix, int target) {
  int s{0};
  int e{static_cast<int>(matrix.size()) - 1};

  while (s < e) {
    int m = (s + e) / 2;

    if (s == m) {
      return matrix[e][0] > target ? m : e;
    } else if (matrix[m][0] <= target) {
      s = m;
    } else {
      e = m - 1;
    }
  }

  return s == e ? s : -1;
}

int search(vector<int>& nums, int target) {
  int l{0};
  int r = static_cast<int>(nums.size()) - 1;

  while (l <= r) {
    int m = (r + l) / 2;

    if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      return m;
    }
  }
  return -1;
}
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  const int row = findRow(matrix, target);
  if (row == -1) return false;
  const int i = search(matrix[row], target);
  return i >= 0;
}

};
