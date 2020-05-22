import java.util.*;

public class Div2 {
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
        while(t > 0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            for(int i=0; i<n-1; i++){
                arr[i] = arr[i+1] - arr[i];
                if(arr[i] <= 2){
                    arr[i] = 1;
                }
                else arr[i] = 0;
            }
            int inf=1;
            // int grp[] = new int[n-1];
            ArrayList<Integer> grp  = new ArrayList<>();
            int k=0;
            for(int i=0; i<n-1; i++){
                if(arr[i] == 1){
                    inf++;
                }
                else {
                    grp.add(inf);
                    k++;
                    inf=0;
                }
            }
            Collections.sort(grp);
            System.out.println(grp.get(0)+" "+grp.get(grp.size()-1));
           t--;
       } 
    }
}