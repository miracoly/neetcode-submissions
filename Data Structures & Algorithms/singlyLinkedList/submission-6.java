
class LinkedList {
    private ListNode head;
    private ListNode tail;

    public LinkedList() {
    }

    public int get(int index) {
        if (head == null || index < 0) return -1;

        var curr = head;
        int i = 0;
        while (curr != null) {
            if (i == index) return curr.value;
            curr = curr.next;
            i++;
        }
        return -1;
    }

    public void insertHead(int val) {
        final var newHead = new ListNode(val);
        newHead.next = head;
        if (tail == null) {
            tail = newHead;
        }
        head = newHead;
    }

    public void insertTail(int val) {
        final var newTail = new ListNode(val);
        if (head == null) {
            head = newTail;
        }
        if (tail != null) {
            tail.next = newTail;
        }
        tail = newTail;
    }

    public boolean remove(int index) {
        if (index < 0) return false;
        if (index == 0) {
            if (head == null) return false;
            head = head.next;
            if (head == null) {
                tail = null;
            }
            return true;
        }

        int i = 0;
        var curr = head;
        while (i < index - 1 && curr != null) {
            i++;
            curr = curr.next;
        }

        if (curr == null || curr.next == null) return false;
        if (curr.next == tail) {
            tail = curr;
        }

        curr.next = curr.next.next;
        return true;
    }

    public ArrayList<Integer> getValues() {
        final var result = new ArrayList<Integer>();
        var current = head;
        while (current != null) {
            result.add(current.value);
            current = current.next;
        }
        return result;
    }
}

class ListNode {
    final int value;
    ListNode next;

    public ListNode(final int value) {
        this(value, null);
    }

    public ListNode(final int value, final ListNode next) {
        this.value = value;
        this.next = next;
    }
}