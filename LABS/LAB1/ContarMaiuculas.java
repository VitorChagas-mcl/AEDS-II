package LABS.LAB1;

import java.util.Scanner;

public class ContarMaiuculas{

    public static int contarM(String str){
        int cont = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                cont++;
            }
        }
        return cont;
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
            String str = scan.nextLine();
            
            while(!str.equals("FIM")){
                
                System.out.println(contarM(str));
                str = scan.nextLine();
            }
        }
    }
}