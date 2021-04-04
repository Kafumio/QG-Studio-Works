package SingleLinkedList;

//链表节点类
public class LNode {
    public int data;
    public LNode next;

    public LNode() {
    }

    public LNode(int data) {
        this.data = data;
    }

    public LNode(int data, LNode next) {
        this.data = data;
        this.next = next;
    }
}
