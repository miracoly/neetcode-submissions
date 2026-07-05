class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        return Arrays.stream(lists)
                .reduce(this::merge)
                .orElse(null);
    }

    ListNode merge(ListNode ls1, ListNode ls2) {
        if (ls1 == null) return ls2;
        if (ls2 == null) return ls1;

        ListNode preHead = new ListNode();
        ListNode cur = preHead;

        while (ls1 != null && ls2 != null) {
            if (ls1.val <= ls2.val) {
                cur.next = ls1;
                ls1 = ls1.next;
            } else {
                cur.next = ls2;
                ls2 = ls2.next;
            }
            cur = cur.next;
        }

        while (ls1 != null) {
            cur.next = ls1;
            ls1 = ls1.next;
            cur = cur.next;
        }

        while (ls2 != null) {
            cur.next = ls2;
            ls2 = ls2.next;
            cur = cur.next;
        }

        return preHead.next;
    }
}
