class Solution {
    public List<Pair> mergeSort(List<Pair> pairs) {
        mergeSort(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    private List<Pair> mergeSort(List<Pair> pairs, int s, int e) {
        if (s < e) {
            int m = ((s + e) / 2);
            mergeSort(pairs, s, m);
            mergeSort(pairs, m + 1, e);
            merge(pairs, s, m, e);
        }
        return pairs;
    }

    private void merge(List<Pair> pairs, int s, int m, int e) {
        int lenL = m - s + 1;
        int lenR = e - m;

        Pair[] tmpL = new Pair[lenL];
        Pair[] tmpR = new Pair[lenR];

        for (int i = 0; i < lenL; i++) {
            tmpL[i] = pairs.get(s + i);
        }

        for (int i = 0; i < lenR; i++) {
            tmpR[i] = pairs.get(m + 1 + i);
        }

        int l = 0;
        int r = 0;
        int i = s;
        while (l < lenL && r < lenR) {
            if (tmpL[l].key <= tmpR[r].key) {
                pairs.set(i++, tmpL[l++]);
            } else {
                pairs.set(i++, tmpR[r++]);
            }
        }

        while (l < lenL) {
            pairs.set(i++, tmpL[l++]);
        }
        while (r < lenR) {
            pairs.set(i++, tmpR[r++]);
        }
    }
}