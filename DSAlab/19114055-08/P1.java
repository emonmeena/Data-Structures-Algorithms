import java.util.*;

class Node{
    int height;
    Node right;
    Node left;
    int data;
    Node(int data){
        height = 0;
        right = null;
        left = null;
        this.data = data;
    }
}
class P1{
    static Node root = null;

    public static int getHeight(Node node){
        if(node == null)
            return -1;
        return node.height;
    }

    public static int getBalanceFactor(Node root){
        if(root == null)
            return -1;
        return getHeight(root.left) - getHeight(root.right);
    }
    
    public static Node leftRotation(Node node){
        Node y = node.right;
        Node z = y.left;

        y.left = node;
        node.right = z;

        node.height = Math.max(getHeight(node.left),getHeight(node.right)) + 1;
        y.height = Math.max(getHeight(y.left),getHeight(y.right)) + 1;
        
        return y;

    }

    public static Node rightRotation(Node node){
        Node y = node.left;
        Node z = y.right;

        node.left = z;
        y.right = node;

        node.height = Math.max(getHeight(node.left),getHeight(node.right)) + 1;
        y.height = Math.max(getHeight(y.left),getHeight(y.right)) + 1;

        return y;
    }

    public static Node balanceTree(Node node,int data){
        int balance_factor = getBalanceFactor(node);

        if(balance_factor < -1){
            if(node.right.data < data){
                return leftRotation(node);
            }
            else if(node.right.data > data){
                node.right = rightRotation(node.right);
                return leftRotation(node);
            }
        }
        else if(balance_factor > 1){
            if(node.left.data > data){
                return rightRotation(node);
            }
            else if(node.right.data < data){
                node.left = leftRotation(node.left);
                return rightRotation(node);
            }
        }

        return node;
    }
    public static Node insertNode(Node node,int data){
        if(node == null){
            return new Node(data);
        }
        else if(data < node.data)
            node.left = insertNode(node.left, data);
        else if(data > node.data)
            node.right = insertNode(node.right, data);
        
        node.height = Math.max(getHeight(node.left),getHeight(node.right)) + 1;

        node = balanceTree(node,data);

        return node;
        

    }
    public static void levelOrder(Node node){
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        while(!q.isEmpty()){
            Node front = q.peek();
            System.out.print(front.data+" ");
            q.remove();
            if(front.left != null)
                q.add(front.left);
            if(front.right != null)
                q.add(front.right);
        }
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int num_of_nodes;
        num_of_nodes = sc.nextInt();

        int data;
        for(int i=0;i<num_of_nodes;i++){
            data = sc.nextInt();
            root = insertNode(root,data);
        }
        
        levelOrder(root);
    }
}