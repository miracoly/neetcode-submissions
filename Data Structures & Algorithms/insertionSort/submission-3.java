public class Solution {
    public List<List<Pair>> insertionSort(List<Pair> pairs) {
        List<List<Pair>> result = new ArrayList<>(pairs.size());

        for (int i = 0; i < pairs.size(); i++) {
            int j = i - 1;

            while (j >= 0 && pairs.get(j).key > pairs.get(j + 1).key) {
                var tmp = pairs.get(j + 1);
                pairs.set(j + 1, pairs.get(j));
                pairs.set(j, tmp);
                j--;
            }
            result.add(new ArrayList<>(pairs));
        }

        return result;
    }
}