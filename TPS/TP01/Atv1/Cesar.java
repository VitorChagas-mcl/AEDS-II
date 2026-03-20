import java.util.*;

class Cesar{

	public static String Crip(String str){
		String aux = "";// Criar um String para salvar a mensagem 
				//que o usuario digitou
		int k = 3; // Contante para pular 3 letras

		for(int i = 0; i < str.length(); i++){
			char Carac = str.charAt(i);
		       	// Pega o caracter atual e coloca em um char
			aux += (char)(Carac + k);
			// Um Cast pra converter pra char, e soma para a string	
		}
		// Retorna a String para a main
		return aux;
	}
	
	public static boolean equal(String str1, String str2){
		if(str1.length() != str2.length())
		       	// Verifica se as string tem tamanhos diferentes 
			return false;

		for(int i = 0; i < str1.length(); i++){
			if(str1.charAt(i) != str2.charAt(i))
				//Verifica caracter por caracter 
				//Se a String 1 é diferente de FIM retorna falso
				return false;
			}
		//Caso nao caia em nenhum if retorna verdadeiro
		return true;
	}	

	public static void main(String[] args){
		
		String msg, resp = "";	
		msg = MyIO.readLine();
		while(!equal(msg, "FIM")){ // Chama a função mandado a mensagem e FIM
			resp = Crip(msg); // Resp recebe a mensagem Criptografada
			MyIO.println(resp);
			msg = MyIO.readLine();
		}
	}
}
