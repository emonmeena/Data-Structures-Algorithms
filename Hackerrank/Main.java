package Hackerrank;

import Hackerrank.LinkedList.*;


public class Main {
    public static void main(String[] args) {

        // LinkedList
        Node head = new Node(0);

        LinkedList.insertNode(head, 100);

        System.out.println(head.next.next);


    }
}