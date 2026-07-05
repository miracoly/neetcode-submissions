class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l{1};
    int r{0};
    for (int p : piles) {
      r = max(p, r);
    }

    while (l < r) {
      int m = l + (r - l) / 2;
      bool valid = isValidK(piles, h, m);
      if (valid) r = m;
      else l = m + 1;
    }
    return l;
  }

 private:
  bool isValidK(const vector<int>& piles, int h, int k) {
    int actualH{0};
    for (int i = 0; i < static_cast<int>(piles.size()); i++) {
      actualH += (piles[i] / k) + (piles[i] % k > 0 ? 1 : 0);
    }
    return actualH <= h;
  }
};
