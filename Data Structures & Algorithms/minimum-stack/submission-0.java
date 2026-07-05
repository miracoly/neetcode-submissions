class MinStack {
    private final Stack<Integer> stack;
    private final Stack<Integer> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.peek()) {
            minStack.push(val);
        }
    }

    public void pop() {
        final var last = stack.peek();
        stack.pop();
        if (Objects.equals(minStack.peek(), last)) {
            minStack.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}
