class Solution {
    public int climbStairs(int n) {
        int one = 1;
        int two = 0;

        for (int i = 0; i < n; i++) {
            int tmp = one;
            one = one + two;
            two = tmp;
        }
        return one;
    }
}