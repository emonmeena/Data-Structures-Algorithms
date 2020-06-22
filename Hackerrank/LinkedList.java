package Hackerrank;

public class LinkedList {

   static class  Node {
    int data;
    Node next;

    //Constructor
     Node(int data){
         this.data = data;
         next = null;
     }
  }

public static void insertNode(Node head, int data) {
  Node temp = new Node(data);
  temp.next = null;
  head.next = temp;
}
    
}