package CodeChef;

public class FFL {
    static void ffl(int[] arrP, int[] arrS, int n, int s){
        String state = "no";
        if(s <= 98){

            for(int i=0; i<n; i++){
                if(arrS[i] == 0){
                    arrS[i]=arrP[i];
                    arrP[i]=0;
                }
            }
            for(int i=0; i<n; i++){
                if(arrP[i] == 0){continue;} 
                for(int j=0; j<n; j++){
                    int temp = arrS[j];
                    if(temp == -1){continue;}
                    else if(temp + arrP[i] <= 100){ state = "yes";}
                }
            }
            
        }
         System.out.println(state);
    }
}