class Solution {

    public int climbStairs(int n) {
        final var cache = mkCache(n);
        return climbStairs(n, 0, cache);
    }

    private int climbStairs(int n, int i, int[] cache) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (cache[i] != -1) return cache[i];
        final var result = climbStairs(n, i + 1, cache) + climbStairs(n, i + 2, cache);
        cache[i] = result;
        return result;
    }

    private int[] mkCache(int n) {
        final var cache = new int[n];
        Arrays.fill(cache, -1);
        return cache;
    }

}
