
import java.util.Scanner;

public class Inverter
{
    public static String inverte(String s, int ind){
        String resp = ""; 
        if(ind == s.length())
            return resp;
    
        return inverte(s, ind + 1) + s.charAt(ind) + resp;
    }
    
    public static boolean equal(String str, String str2){
        if(str.length() != str2.length())
            return false;
            
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) != str2.charAt(i))
                return false;
        }
        return true;
    }       
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		
		while(!equal(str, "FIM")){
		    String resp = inverte(str, 0);
		    MyIO.println(resp);
		    str = scan.nextLine();
		}
        scan.close();
	}
}

