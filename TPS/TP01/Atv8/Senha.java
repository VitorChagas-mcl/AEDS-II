import java.util.Scanner;

class Senha{

	public static boolean validador(String s){
		boolean resp = false, simbolo = false, num = false, min = false, mai = false;
		int tam = s.length();
		if (tam < 8) return false; // Ja verifica se tem tamanho < 8 se nao ja retorna false
		for(int i = 0; i < tam; i++){
			char c = s.charAt(i);
			if(c >= '0' && c <= '9'){// Verifica se exite numero
				num = true;
			}
           		if(c >= 'A' && c <= 'Z'){ //Verifica se tem letra Maiuscula
				mai = true;
			}
           		if(c >= 'a' && c <= 'z'){// Verifica se tem letra Minuscula
				min = true;
			}
			if(c == '!' || c == '@' || c == '#' || c == '&' || c == '*' || c == '^'){
            			simbolo = true;// Verifica se tem simbolo
			}
		}
		if(simbolo && min && mai && num) // Caso tudo seja true resp recebe true
			resp = true;
		
	return resp;
	}	

	public static boolean equal(String str1, String str2){

		if(str1.length() != str2.length()) // verifica as strings se tem tamanho iguais
			return false;

		for(int i = 0; i < str1.length(); i++){
			if(str1.charAt(i) != str2.charAt(i)) // olha caracter por caracter
				return false;
		}

		return true; // caso nao bata em nenhum if retorna verdadeiro 
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String linha = sc.nextLine();
		
		while(!equal(linha, "FIM")){
			if(validador(linha)){
				MyIO.println("SIM");
			}else{
				MyIO.println("NAO");
			}
			linha = sc.nextLine();	
		}
	}
}
