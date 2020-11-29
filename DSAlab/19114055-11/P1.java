/*
Masthead - 
Owner - Mayank Meena 
Enroll no. 19114055
Code Editor - VSCode 2020(1.40.1)
Terminal - Ubuntu Terminal 20.04
Shell - git bash

Contact - 
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/
import java.util.Scanner;

class P1 {
    public static void main(String[] args) {
        Scanner inputsP1 = new Scanner(System.in);
        int vertices = inputsP1.nextInt();
        int edges = inputsP1.nextInt();
        int tempEdgeCount = 0;
        String answer;
        boolean isTwoEdgeGraph = edges<vertices?false:true;

        for (int i = 0; i < vertices; i++) {
            tempEdgeCount = 0;
            if (!isTwoEdgeGraph)
                break;
            for (int j = 0; j < vertices; j++) {
                if (inputsP1.nextInt() == 1 && i !=j)
                    tempEdgeCount++;
            }
            isTwoEdgeGraph = tempEdgeCount > 1 ? true : false;
        }
        answer = isTwoEdgeGraph ? "Yes" : "No";
        System.out.println(answer);
        inputsP1.close();
    }
}
