
#include <cstddef>

using namespace std;

class Solution {
public:
    vector<Pair> quickSort(vector<Pair> &pairs) {
    if (pairs.empty())
        return pairs;
    quickSort(pairs, 0, pairs.size() - 1);
    return pairs;
    }

private:
    void quickSort(std::vector<Pair> &pairs, size_t start, size_t end) {
    if (end - start + 1 <= 1)
        return;

    const Pair pivot = pairs[end];
    size_t left = start;

    for (size_t i = start; i < end; i++) {
        if (pairs[i].key < pivot.key) {
        Pair tmp = pairs[left];
        pairs[left] = pairs[i];
        pairs[i] = tmp;
        left++;
        }
    }

    pairs[end] = pairs[left];
    pairs[left] = pivot;

    quickSort(pairs, start, left - 1);
    quickSort(pairs, left + 1, end);
    }
};
