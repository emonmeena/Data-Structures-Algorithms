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
        // Search Method returns true or false
        System.out.println( 
        LinkedList.search(head, 50)
        );
        // Insertion at the beginning
        head = LinkedList.insertAtStart(head, 106); //returns new head at new Node.

    }
}