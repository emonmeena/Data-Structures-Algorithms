package Hackerrank;

public class LinkedList {

   static class  Node {
    int key;
    Node next;

    //Constructor of Node
     Node(int key){
         this.key = key;
         next = null;
     }
}

public static Node insertNodeAtLast(Node head, int data) {
  Node node = new Node(data);
  node.next = null;

  if(head == null){
    head = node;
    return head;
  }

  Node ptr = head;
  while(true){
    if(ptr.next == null){
      ptr.next = node;
      break;
    }
    ptr = ptr.next;
  }
  return head;
}

public static void printAll(Node head) {
  while(true){ 
    if(head == null) break;
    System.out.println(head.key);
    head = head.next;
  }
}
  

}