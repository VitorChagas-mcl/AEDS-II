class Is{

	public static boolean Letra(char c){
		//Função que verifica se é uma lestra
   		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}

	
	public static boolean SoVogais(String s){
		int tam = s.length();//pegar o tamanho da string

		for(int i = 0; i < tam; i++){
			char c = s.charAt(i);// C = 'a' por exemplo pega carcter por caracter
			
			if(!Letra(c)){// se entrar e nao for uma letra ja retorna false
				return false;
			}
			//verifica se é so vogal
       			if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
       			    c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
        		    return false;
       			}
    		}
		 // Caso nao entre no if retorna verdadeiro
		return true;
	}


	public static boolean SoCons(String s){
		int tam = s.length();// pega o tamanho da string

		for(int i = 0; i < tam; i++){
        		char c = s.charAt(i);//C = 'a' pega uma caracter

       			 if(!Letra(c)){// verifica se é letra
       			 	return false;
        		 }
			 // Diferente das Vogais se tiver uma vogal ele ja retorna false
       			 if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              	  	    c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
       		    	 	return false;
        		 }
	    	}	
		//caso caso nao entre no if retorna verdadeiro
	    return true;
	}	


	public static boolean SoNumInteiro(String s){
		int tam = s.length();//mesma função ja explicada	

		for(int i = 0; i < tam; i++){
			char c = s.charAt(i);//mesma função ja explicada
			
			//verifica se C é diferente de um numero
			//se for retorna false
			if(!(c >= '0' && c <= '9')){
				return false;	
			}
		}
		//caso nao seja retorna true
		return true;
	}


	public static boolean SoNumReal(String s){
		int tam = s.length();//mesma função ja explicada	
		int sep = 0;//Um contador pra verifica se tem mais de um . ou virgula

		for(int i = 0; i < tam; i++){
			char c = s.charAt(i);//Mesma função ja explicada
			//verifica se o C é um numero ou um . ou uma ,
			if(c >= '0' && c <= '9' || c == '.' || c == ','){
				if(c == '.' || c == ',') //se for . ou , o contador recebe +1
					sep++;	
			}else{//Se nao for retorna false
				return false;
			}
		}
		if(sep > 1)//Verifica se existe mais de um . ou , se existir retorna false
			return false; 
		//Se bater Retorna true
		return true;
	}

	public static boolean equal(String str1, String str2){
		int tam = str1.length();
		if(tam != str2.length())// verifica se as string tem tamanho iguais
			return false;

		for(int i = 0; i < tam; i++){
			if(str1.charAt(i) != str2.charAt(i))// verifica letra por letra
				return false;
		}
		// caso nao caia no if retorna verdadeiro	
		return true;
	}

	public static void main(String[] args){
		String linha;
		boolean x1, x2, x3, x4;
	
		linha = MyIO.readLine();//le a primeira
		while(!equal(linha,"FIM ")){// verifica se a palavra é igual a FIM
				//variaveis Xi pegando true ou false do retorno da função
			x1 = SoVogais(linha);
			x2 = SoCons(linha);
			x3 = SoNumInteiro(linha);
			x4 = SoNumReal(linha);
			//Usando operador ternario se o Xi for verdadeiro
			//atribui ao resp(i) SIM, caso nao seja atribui com nao
			String resp1 = x1 ? "SIM" : "NAO";
			String resp2 = x2 ? "SIM" : "NAO";
			String resp3 = x3 ? "SIM" : "NAO";
			String resp4 = x4 ? "SIM" : "NAO";
			//print das respostas
			MyIO.println(resp1 + " " + resp2 + " " + resp3 + " " + resp4);
			linha = MyIO.readLine();//ler proxima linha
		}	
	}
}
