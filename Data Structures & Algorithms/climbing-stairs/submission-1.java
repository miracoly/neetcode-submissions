class Solution {
    public int climbStairs(int n) {
        return climbStairs(n, 0);
    }

    public int climbStairs(int n, int i) {
        if (i > n) return 0;
        if (i == n) return 1;
        else return climbStairs(n, i + 1) + climbStairs(n, i + 2);
    }


}
