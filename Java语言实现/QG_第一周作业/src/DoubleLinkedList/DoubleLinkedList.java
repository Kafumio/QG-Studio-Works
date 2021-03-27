package DoubleLinkedList;

import SingleLinkedList.LNode;

public class DoubleLinkedList {
    public DuLNode head;
    public DuLNode end;
    public int size;

    //初始化双链表
    public DoubleLinkedList(){
        this.head = this.end = null;
        this.size = 0;
    }

    //销毁链表
    public void DestroyList_Dul() {
        head = end = null;
        size = 0;
    }

    //在某个节点前插入新节点
    public boolean InsertBeforeList_Dul(int index,int data){
        if (index > size){
            return false;
        }
        if (index == 0){
            head = new DuLNode(data,null,head);
        }else {
            DuLNode prev = getNode(index);
            prev.prior = new DuLNode(data,prev.prior,prev);
        }
        size++;
        return true;
    }

    //在某个节点后插入
    public boolean InsertAfterList_Dul(int index,int data){
        if (index > size){
            return false;
        }
        if (index == 0){
            new DuLNode(data,head,null);
        }else {
            DuLNode prev = getNode(index);
            prev.next = new DuLNode(data,prev,prev.next);
        }
        size++;
        return true;
    }

    //删除节点
    public boolean DeleteList_Dul(int index) {
        if (index > size){
            return false;
        }
        DuLNode node = head;
        if (index == 0){
            head = head.next;
        }else {
            DuLNode prev = getNode(index);
            node = prev.next;
            prev.next = node.next;
            node.next.prior = prev;
        }
        System.out.println("删除成功！被删除的元素为" + node.data);
        size--;
        return true;
    }

    //遍历链表
    public void TravelList() {
        DuLNode p = head;
        while (p != null) {
            System.out.print(p.data + "->");
            p = p.next;
        }
        System.out.print("\n");
    }

    //获取index位置的节点
    public DuLNode getNode(int index) {
        if (index > size) {
            return null;
        }
        DuLNode node = null;
        //二分判断从头指针还是尾指针开始查找，提高查找效率
        if (index <= size/2) {
            node = head;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
        }else {
            node = end;
            for (int i = size - 1; i > index; i--){
                node = node.prior;
            }
        }
        return node;
    }
}
