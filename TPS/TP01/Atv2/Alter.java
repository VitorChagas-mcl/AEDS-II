import java.util.*;

class Alter{

	public static boolean equal(String str1, String str2){
		// Verifica se as strings tem tamanhos diferentes, se tiver retorna falso
		if(str1.length() != str2.length())
			return false;
		// Verifica caracter por caracter pra ver se a String 1  e igual a FIM
		// Se achar diferença ele retorna false
		for(int i = 0; i < str1.length(); i++){
			if(str1.charAt(i) != str2.charAt(i))
				return false;
		}
		// Se não cair em  nenhum caso ele retorna verdadeiro 
		return true;
	}

	public static String random(String str, Random gerador){
		char letra1 = ((char) ('a' + (Math.abs(gerador.nextInt()) % 26)));
		char letra2 = ((char) ('a' + (Math.abs(gerador.nextInt()) % 26)));
		//pega as letras aleatorias
		String resp = "";
		for(int i = 0; i < str.length(); i++){
			//Anda caracter por caracter se achar a letra sorteada
			//ele troca, se não continua escrevendo
			if(str.charAt(i) == letra1){
				resp += letra2;
			}else{
				resp += str.charAt(i);
			}
		}
		// Retorna a string nova
		return resp;
	}

	public static void main(String[] args){
	
		Random gerador = new Random();
		gerador.setSeed(4);
	
		String str = MyIO.readLine();
		String resp = "";
		while(!equal(str,"FIM")){ // Chamada da função mandando str e FIM
			resp = random(str, gerador);
			MyIO.println(resp);
			str = MyIO.readLine();
		}
	}
}
