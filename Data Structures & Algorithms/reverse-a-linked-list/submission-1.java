/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;

        var rest = head.next;
        head.next = null;
        return reverseList(head, rest);
    }

    public ListNode reverseList(ListNode revHead, ListNode rest) {
        if (rest == null) return revHead;

        var newRest = rest.next;
        rest.next = revHead;
        return reverseList(rest, newRest);
    }
}
