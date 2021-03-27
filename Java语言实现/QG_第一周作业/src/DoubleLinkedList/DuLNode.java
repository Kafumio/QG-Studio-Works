package DoubleLinkedList;

public class DuLNode {
    public int data;
    public DuLNode prior;
    public DuLNode next;

    public DuLNode() {
    }

    public DuLNode(int data, DuLNode prior, DuLNode next) {
        this.data = data;
        this.prior = prior;
        this.next = next;
    }
}
