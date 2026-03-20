public class Inverter
{
    public static String inverte(String s, int ind){
        String resp = ""; 
        if(ind >= s.length())
            return resp;
        
        resp = inverte(s, ind + 1);
        resp += s.charAt(ind);
        return resp;
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
		String str = MyIO.readLine();
		
		while(!equal(str, "FIM")){
		    String resp = inverte(str, 0);
		    MyIO.println(resp);
		    str = MyIO.readLine();
		}
	}
}

