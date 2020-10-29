import java.util.Scanner;

class P2{
    
    static int find(int inOrder[], int start, int end, int Find){
        int index = 0;
        for(index=start;index<end;index++){
            if(inOrder[index] == Find){
                return index;
            }
        }
        return index;
    }

    static int preIndex = 0;
    static void postorder(int inOrder[], int preOrder[], int start, int end){
        if(start>end){
            return;
        }
        
        int index = find(inOrder, start, end, preOrder[preIndex++]);

        postorder(inOrder, preOrder, start, index-1);

        postorder(inOrder, preOrder, index+1, end);

        System.out.print(inOrder[index] + " ");
    }

   public static void main(String args[]){
       Scanner input = new Scanner(System.in);

       int num_of_nodes = input.nextInt();
       int inOrder[] = new int[num_of_nodes];
       int preOrder[] = new int[num_of_nodes];

       for(int i=0;i<num_of_nodes;i++){
        inOrder[i] = input.nextInt();
       }

       for(int i=0;i<num_of_nodes;i++){
           preOrder[i] = input.nextInt();
       }

       System.out.println("The Postorder Traversal is: ");

       postorder(inOrder, preOrder, 0, num_of_nodes-1);
   }
}