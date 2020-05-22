import java.util.*;

class Searching{
int[] searcher(String str[], String[] query,int n,int q){
 
  int arr[] = new int[q]; 
  Arrays.sort(str);
    for(int j=0; j<q; j++){
        for(int i=0; i<n; i++){
            if(str[i].equals(query[j])){
                // System.out.println(str[i]+" "+query[j]+" "+i+" "+j+" "+arr[j]);
                ++arr[j];
                // System.out.println(arr[j]);
            }
        }
    }
    return arr;
    }
}

public class BinarySearcher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
           int n = sc.nextInt();
        //    String gama =  sc.nextLine();
           String str[] = new String[n];
           for(int i=0; i<n; i++){
            //    str[i] =  sc.nextLine();
           }
           int q = sc.nextInt();
        //    String alfa =  sc.nextLine();
           String query[] = new String[q];
           for(int i=0; i<q; i++){
            // query[i] =  sc.nextLine();
        }
        Searching o = new Searching();

        for(int i=0; i<q; i++)
            System.out.println(o.searcher(str, query,n, q)[i]);
    }
}