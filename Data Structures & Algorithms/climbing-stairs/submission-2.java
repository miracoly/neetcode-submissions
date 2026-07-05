class Solution {
    public int climbStairs(int n) {
        final Map<Integer, Integer> cache = new HashMap<>();
        return climbStairs(n, 0, cache);
    }

    public int climbStairs(int n, int i, Map<Integer, Integer> cache) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (cache.containsKey(i)) return cache.get(i);
        final var result = climbStairs(n, i + 1, cache) + climbStairs(n, i + 2, cache);
        cache.put(i, result);
        return result;
    }

}
