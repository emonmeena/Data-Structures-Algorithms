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

public static boolean search(Node head, int ele) {
  // Traversing
  boolean isPresent = false;
  while(true){ 
    if(head == null) break;
    if(head.key == ele) isPresent = true;
    head = head.next;
  }

  return isPresent;
}

public static Node insertAtStart(Node head, int key) {
  Node node = new Node(key);
  node.next = head;
  head = node;
  return head;
}

public static void insert(Node head, int pos, int key) {
 Node node = new Node(key);

  int currPos = 1;
  while(true){
    if(currPos == pos - 1) break;
    head = head.next;
    currPos++;
  }
  node.next = head.next;
  head.next = node;
}
  

}