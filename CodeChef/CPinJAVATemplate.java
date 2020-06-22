package CodeChef;

import java.util.*;
import java.lang.*;
import java.io.*;



class  SinglyLinkedListNode {
         int data;
       SinglyLinkedListNode next = null;
     }

public class CPinJAVATemplate {
    public static void main(String[] args) throws java.lang.Exception {

       SinglyLinkedListNode head =  insertNodeAtTail(null, 0);

        for(int i = 1; i<11; i++){
            insertNodeAtTail(head, i);
        }
        
        for(int i = 1; i<11; i++){
            System.out.println(head.data);
            head = head.next;
        } 
        
    }



    static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {


        SinglyLinkedListNode node = new SinglyLinkedListNode();
        node.data = data;
        node.next = null;

        if(head == null){
            head = node;
        return head;    
        }

        SinglyLinkedListNode ptr = head;

        while(true){
            if(ptr.next == null) {
                ptr.next = node;
                break;
            }
                ptr = ptr.next;
        }

        return head; 
    }
}