package SingleLinkedList;

import java.util.Scanner;

public class SingleLinkedListDemo {
    public static void main(String[] args) {
        int choice,index,value;
        SingleLinkedList list = null;
        do {
            Utils.show();
            choice = new Scanner(System.in).nextInt();
            switch (choice){
                case 1:{
                    list = new SingleLinkedList();
                    if (list == null){
                        System.out.println("内存分配失败！");
                        System.out.println("空链表创建失败！");
                    }
                    System.out.println("空链表创建成功");
                    break;
                }
                case 2:{
                    list.DestroyList();
                    System.out.println("链表销毁完成！");
                    break;
                }
                case 3:{
                    if (list == null){
                        System.out.println("链表为空，请先创建链表");
                    }else{
                        System.out.print("你想在第几个节点后插入新节点：");
                        index = new Scanner(System.in).nextInt();
                        System.out.print("请输入整数：");
                        value = Utils.judge_scanf();
                        if (list.InsertList(index,value)){
                            System.out.println("插入成功！");
                        }else {
                            System.out.println("插入失败！");
                        }
                    }
                    break;
                }
                case 4:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表不存在或者只存在一个空的头结点");
                    }
                    System.out.print("你想删除第几个节点之后的节点：");
                    index = new Scanner(System.in).nextInt();
                    if (list.DeleteList(index) == false){
                        System.out.println("删除失败！");
                    }
                    break;
                }
                case 5:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表不存在或者只存在一个空的头结点");
                    }else {
                        list.TravelList();
                    }
                    break;
                }
                case 6:{
                    System.out.println("请输入你要查询的数据：");
                    value = Utils.judge_scanf();
                    assert list != null;
                    if (list.SearchList(value)){
                        System.out.println("该数存在！");
                    }else {
                        System.out.println("该数不存在！");
                    }
                    break;
                }
                case 7: {
                    if (list == null || list.head.next == null){
                        System.out.println("链表为空或者链表只含有一个空结点");
                        System.out.println("链表反转失败");
                    }else {
                        if (list.ReverseList()){
                            System.out.println("链表反转成功！");
                        }else {
                            System.out.println("链表反转失败！");
                        }
                    }
                    break;
                }
                case 8:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表为空或者链表只含有一个空结点");
                    }else {
                        if (list.isLoopList()){
                            System.out.println("链表成环");
                        }else {
                            System.out.println("链表不成环");
                        }
                    }
                    break;
                }
                case 9:{
                    list.head = list.ReverseEvenList();
                    System.out.println("操作成功！");
                    break;
                }
                case 10:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表为空或者链表只含有一个空结点");
                    }else {
                        list.FindMidNode();
                    }
                    break;
                }
                case 11:{
                    list.DestroyList();
                    break;
                }
                default:{
                    System.out.println("请重新输入数字！(1-11)");
                    break;
                }
            }
        }while (choice != 11);
    }
}

class Utils{
    public static void show(){
        System.out.print("单链表ADT\n\n");
        System.out.println("1.创建空链表");
        System.out.println("2.销毁链表");
        System.out.println("3.插入结点");
        System.out.println("4.删除结点");
        System.out.println("5.遍历链表");
        System.out.println("6.查询数据");
        System.out.println("7.反转链表");
        System.out.println("8.判断链表是否成环");
        System.out.println("9.反转链表中的偶数结点与奇数节点");
        System.out.println("10.查找中间节点");
        System.out.println("11.退出");
        System.out.print("\n请输入对应的数字(1-11)：");
    }

    public static int judge_scanf(){
        int len = 0, num = 0, arg = 1;
        char[] word = new char[10];
        int m,j,k;
        boolean flag = true;
        while(flag)
        {
            word = new Scanner(System.in).next().toCharArray();
            len = word.length;
            for(m = 0;m<len;m++)
            {
                //检验是否乱输入其他字符
                if(word[m]<'0' || word[m]>'9')
                {
                    break;
                }
                else
                {
                    if(m == len-1){
                        flag = false;
                    }
                }
            }
        }
        j = len - 1;
        // 将字符重新转换为数字
        for(m=0;m<len;m++)
        {
            for(k=0;k<j;k++) {
                arg *= 10;
            }
            num += (word[m]-'0')*arg;
            arg = 1;
            j--;
        }
        return num;
    }
}
