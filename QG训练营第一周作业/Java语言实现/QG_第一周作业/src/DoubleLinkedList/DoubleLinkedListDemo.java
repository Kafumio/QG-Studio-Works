package DoubleLinkedList;

import SingleLinkedList.SingleLinkedList;

import java.util.Scanner;

public class DoubleLinkedListDemo {
    public static void main(String[] args) {
        int choice,index,value;
        DoubleLinkedList list = null;
        do {
            Utils.show();
            choice = new Scanner(System.in).nextInt();
            switch (choice){
                case 1:{
                    list = new DoubleLinkedList();
                    if (list == null){
                        System.out.println("内存分配失败！");
                        System.out.println("空链表创建失败！");
                    }
                    System.out.println("空链表创建成功");
                    break;
                }
                case 2:{
                    list.DestroyList_Dul();
                    System.out.println("链表销毁完成！");
                    break;
                }
                case 3:{
                    if (list == null){
                        System.out.println("链表为空，请先创建链表");
                    }else{
                        System.out.print("你想在第几个节点前插入新节点：");
                        index = new Scanner(System.in).nextInt();
                        System.out.print("请输入整数：");
                        value = Utils.judge_scanf();
                        if (list.InsertBeforeList_Dul(index,value)){
                            System.out.println("插入成功！");
                        }else {
                            System.out.println("插入失败！");
                        }
                    }
                    break;
                }
                case 4:{
                    if (list == null){
                        System.out.println("链表为空，请先创建链表");
                    }else{
                        System.out.print("你想在第几个节点后插入新节点：");
                        index = new Scanner(System.in).nextInt();
                        System.out.print("请输入整数：");
                        value = Utils.judge_scanf();
                        if (list.InsertAfterList_Dul(index,value)){
                            System.out.println("插入成功！");
                        }else {
                            System.out.println("插入失败！");
                        }
                    }
                    break;
                }
                case 5:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表不存在或者只存在一个空的头结点");
                    }
                    System.out.print("你想删除第几个节点之后的节点：");
                    index = new Scanner(System.in).nextInt();
                    if (list.DeleteList_Dul(index) == false){
                        System.out.println("删除失败！");
                    }
                    break;
                }
                case 6:{
                    if (list == null || list.head.next == null){
                        System.out.println("链表不存在或者只存在一个空的头结点");
                        break;
                    }else {
                        list.TravelList();
                    }
                    break;
                }
                case 7:{
                    list.DestroyList_Dul();
                    break;
                }
                default:{
                    System.out.println("请重新输入数字！(1-11)");
                    break;
                }
            }
        }while (choice != 7);
    }
}

class Utils{
    //展示链表操作
    public static void show(){
        System.out.print("双链表ADT\n\n");
        System.out.println("1.创建空链表");
        System.out.println("2.销毁链表");
        System.out.println("3.在某个节点前插入新节点");
        System.out.println("4.在某个节点后插入新节点");
        System.out.println("5.删除节点");
        System.out.println("6.遍历链表");
        System.out.println("7.退出");
        System.out.print("\n请输入对应的数字(1-7)：");
    }

    //保证合法输入数据
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
