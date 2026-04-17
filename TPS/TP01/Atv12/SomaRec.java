import java.util.Scanner;

class SomaRec{

	public static int Soma(String s, int i, int tam){
		if(i >= tam){
			return 0;
		}
		char c = s.charAt(i);// Pega o caracter atual
		int soma = (c - '0');// faz a soma por exemplo 5 - 0 em ascii é 53 - 48 = 5
	
		return soma + Soma(s , i + 1, tam);// chamada recursiva
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
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine();

		while(!equal(s, "FIM")){
			int i = Soma(s, 0, s.length());
			MyIO.println(i);
			s = scan.nextLine();
		}
	}
}
