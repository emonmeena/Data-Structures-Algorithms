package Hackerrank;

import Hackerrank.LinkedList.*;


public class Main {
    public static void main(String[] args) {

        //Initializing LinkedList with head
        Node head = new Node(0);
        // Inserting / Making LL
        for(int i = 0; i<11; i++){
        LinkedList.insertNodeAtLast(head, i*10);
        }
        // Printing all elements
        LinkedList.printAll(head);

        int key = 106;
        // Search Method returns true or false
        System.out.println( 
        LinkedList.search(head, key)
        );
        // Insertion at the beginning
        head = LinkedList.insertAtStart(head, key); //returns new head at new Node. coz head node changes

        //inserting at Specific pos.
        int pos = 3; // 1 < pos < last position
        LinkedList.insert(head, pos, key);

    }
}