import java.util.*;

public class Espelho{

	public static String reverse(String s){
		String resp = "";

		for(int i = s.length() - 1; i >= 0; i--){
			resp += s.charAt(i);
		}
		return resp;
	}

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);

		do{

			String num = scan.nextLine();

			String [] v = num.split(" ");

			int a = Integer.parseInt(v[0]);
			int b = Integer.parseInt(v[1]);
			
			String esp = "";

			for(int i = a; i <= b; i++){ 
				esp += Integer.toString(i);	
			}		

			String temp = reverse(esp);

			esp += temp;
			
			System.out.println(esp);	
		}while(scan.hasNext());
	}
}
