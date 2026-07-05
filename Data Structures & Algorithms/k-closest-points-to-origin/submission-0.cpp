class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k);
};


namespace {

double distanceZ(const std::vector<int>& p) {
  if (p.size() < 2) {
    throw std::invalid_argument("Point must have at least 2 dimensions");
  }

  const int x = p[0];
  const int y = p[1];
  return (x * x) + (y * y);
}

bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
  return distanceZ(a) > distanceZ(b);
}

}  // namespace

std::vector<std::vector<int>> Solution::kClosest(
    std::vector<std::vector<int>>& points, int k) {
  std::priority_queue minHeap(points.begin(), points.end(), cmp);

  std::vector<std::vector<int>> result;
  result.reserve(static_cast<std::size_t>(k));
  for (int i = 0; i < k && !minHeap.empty(); ++i) {
    result.push_back(minHeap.top());
    minHeap.pop();
  }

  return result;
}
