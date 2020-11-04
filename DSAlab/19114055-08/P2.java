import java.util.*;

class P2{
    
    public static void topoSort(int n, int adMatrix[][], int arr[], Queue<Integer> q){
       
       while(!q.isEmpty()){
           int v = q.peek();
           System.out.print(v+" ");
           for(int i=0;i<n;i++){
                if(adMatrix[v][i] == 1){
                    arr[i]--;
                    if(arr[i] == 0)
                        q.add(i);
                }
           }
           q.remove();

       } 
    }
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int adMatrix[][] = new int[n][n];
        
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adMatrix[i][j] = sc.nextInt();
                if(adMatrix[i][j] !=0)
                    arr[j]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();

        for(int i =0;i<n;i++){
            if(arr[i] == 0)
                q.add(i);
        }
        topoSort(n, adMatrix, arr, q);
        
    }
}