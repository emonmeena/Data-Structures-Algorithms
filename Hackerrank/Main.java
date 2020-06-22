package Hackerrank;

import Hackerrank.LinkedList.*;


public class Main {
    public static void main(String[] args) {

        // LinkedList
        Node head = new Node(0);

        for(int i = 0; i<11; i++){
        LinkedList.insertNodeAtLast(head, i*10);
        }

        LinkedList.printAll(head);
    }
}