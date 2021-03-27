package SingleLinkedList;

public class SingleLinkedList {
    public LNode head;
    public int size;

    public SingleLinkedList() {
        this.head = null;
        this.size = 0;
    }

    public void DestroyList() {
        head = null;
        size = 0;
    }

    public boolean InsertList(int index, int data) {
        if (index > size){
            return false;
        }
        if (index == 0) {
            head = new LNode(data,head);
        } else {
            LNode prev = getNode(index);
            prev.next = new LNode(data,prev.next);
        }
        size++;
        return true;
    }

    public boolean DeleteList(int index) {
        if (index > size){
            return false;
        }
        LNode node = head;
        if (index == 0){
            head = head.next;
        }else {
            LNode prev = getNode(index);
            node = prev.next;
            prev.next = node.next;
        }
        System.out.println("删除成功！被删除的元素为" + node.data);
        size--;
        return true;
    }

    public void TravelList() {
        LNode p = head;
        while (p != null) {
            System.out.print(p.data + "->");
            p = p.next;
        }
        System.out.print("\n");
    }

    public boolean SearchList(int data) {
        while (head != null) {
            if (head.data == data) {
                return true;
            }
            head = head.next;
        }
        return false;
    }

    public boolean ReverseList() {
        if (head == null) {
            return false;
        }
        LNode p1 = head, p2, p3;
        p2 = p3 = p1.next;
        while (p3 != null) {
            p3 = p3.next;
            p2.next = p1;
            p1 = p2;
            p2 = p3;
        }
        head = p1;
        return true;
    }

    public boolean isLoopList() {
        if (head == null) {
            return false;
        }
        LNode p1 = head.next;
        LNode p2 = head.next.next;
        while ((p1 != null) && (p2 != null)) {
            if (p1 == p2) {
                return true;
            }
            p1 = p1.next;
            p2 = p2.next.next;
        }
        return false;
    }

    public LNode ReverseEvenList() {
        LNode p1, p2, h, t = null;
        int n = 0;
        h = p1 = head;
        while (p1.next != null) {
            p2 = p1.next;
            p1.next = p2.next;
            p2.next = p1;
            if (++n == 1) {
                h = p2;
            } else {
                t.next = p2;
            }
            t = p1;
            p1 = p1.next;
            if (p1 == null) {
                break;
            }
        }
        return h;
    }

    public LNode FindMidNode() {
        LNode p1, p2;
        p1 = p2 = head;
        while (p2 != null) {
            p2 = p2.next.next;
            p1 = p1.next;
            if (p2.next == null) {
                System.out.print("中间节点的数据为" + p1.data);
                break;
            }
            if (p2.next.next == null) {
                System.out.print("中间节点的数据为" + p1.data + "-" + p1.next.next);
            }
        }
        return p1;
    }

    public LNode getNode(int index) {
        if (index > size) {
            return null;
        }
        LNode node = head;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        return node;
    }
}
