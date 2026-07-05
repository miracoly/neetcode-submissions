class Solution {
    private static final char[] OPEN = {'(', '[', '{'};
    private static final char[] CLOSE = {')', ']', '}'};

    public boolean isValid(String s) {
        final char[] stack = new char[s.length()];
        int p = 0;

        for (int i = 0; i < s.length(); i++) {
            final var c = s.charAt(i);
            if (open(c)) {
                stack[p++] = c;
            } else if (close(c)) {
                if (p > 0 && stack[p - 1] == OPEN[(indexClose(c))]) {
                    p--;
                } else {
                    return false;
                }
            }
        }
        return p == 0;
    }

    private int indexClose(char c) {
        for (int i = 0; i < CLOSE.length; i++) {
            if (c == CLOSE[i]) return i;
        }
        return -1;
    }

    private boolean open(char c) {
        for (final char p : OPEN) {
            if (p == c) return true;
        }
        return false;
    }

    private boolean close(char c) {
        for (final char p : CLOSE) {
            if (p == c) return true;
        }
        return false;
    }
}
