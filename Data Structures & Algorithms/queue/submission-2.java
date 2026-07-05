class Deque {
    private Node preHead;
    private Node tail;
    private int size;

    public Deque() {
        this.preHead = new Node(0);
        this.tail = preHead;
        this.size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void append(int value) {
        final var newNode = new Node(value, tail, null);
        tail.next = newNode;
        tail = newNode;
        size++;
    }

    public void appendleft(int value) {
        final var head = preHead.next;
        final var newNode = new Node(value, preHead, head);
        preHead.next = newNode;
        if (head != null) {
            head.prev = newNode;
        } else {
            tail = newNode;
        }
        size++;
    }

    public int pop() {
        if (size <= 0) return -1;

        final var result = tail.val;
        tail.prev.next = null;
        tail = tail.prev;
        size--;

        return result;
    }

    public int popleft() {
        if (size <= 0) return -1;

        final var head = preHead.next;
        preHead.next = head.next;
        if (head.next != null) {
           head.next.prev = preHead;
        } else {
            tail = preHead;
        }
        size--;

        return head.val;
    }

    private static class Node {
        int val;
        Node prev;
        Node next;

        public Node(final int val) {
            this(val, null, null);
        }

        public Node(final int val, final Node prev, final Node next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }
}
