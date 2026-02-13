package LABS.LAB1;

import java.util.Scanner;

public class ContarMaiuculasRec {

    public static boolean equals(String str1, String str2){
        if(str1.length() != str2.length()){
            return false;
        } 

        for(int i = 0; i < str1.length(); i++){
            if(str1.charAt(i) != str2.charAt(i))
                return false;
        }
        return true;
    }


    public static int contarMRec(String str, int index){
        int resp = 0;
        if(index < str.length()){
            if(str.charAt(index) >= 'A' && str.charAt(index) <= 'Z'){
                resp =  1 + contarMRec(str, index + 1);
            }else {
                resp = contarMRec(str, index + 1);
            }
        }
        return resp;
    }

    @SuppressWarnings("ConvertToTryWithResources")
    public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            String str = scan.nextLine();
            
            while(!equals(str,"FIM")){
                System.out.println(contarMRec(str, 0));
                str = scan.nextLine();
        }
        scan.close();
    }
}
