import java.util.Scanner;
class No{
	public char elemento;
	public No dir, esq;
	
	public No(){
		this.elemento = '\0';
		this.dir = this.esq = null;
	}
	public No(char elemento){
		this.elemento = elemento;
		this.dir = this.esq = null;
	}
}

class Arvore{
	public No raiz;

	public Arvore(){
		this.raiz = null;
	}

	public void inserir(char elemento){
		raiz = inserir(elemento, raiz);
	}

	public No inserir(char elemento, No i){
		if(i == null){
			i = new No(elemento);
		}else if(elemento < i.elemento){
			i.esq = inserir(elemento, i.esq);
		}else{
			i.dir = inserir(elemento, i.dir);
		}

		return i;
	}

	public boolean pesquisar(char elemento, No i){
		boolean resp = false;
		if(i == null){
			resp = false;
		}else if(elemento == i.elemento){
			resp = true;
		}else if(elemento < i.elemento){
			resp = pesquisar(elemento, i.esq);
		}else if(elemento > i.elemento){
			resp = pesquisar(elemento, i.dir);
		}

		return resp;
	}

	public boolean pesquisar(char elemento){
		return pesquisar(elemento, raiz);
	}

	public void caminharCentral(){
		caminharCentral(raiz);
	}
	public void caminharPre(){
		caminharPre(raiz);
	}
	public void caminharPos(){
		caminharPos(raiz);
	}



	public void caminharCentral(No i){
		if(i != null){
			caminharCentral(i.esq);
			System.out.print(i.elemento + " ");
			caminharCentral(i.dir);
		}
	}

	public void caminharPos(No i){
		if(i != null){
			caminharPos(i.esq);
			caminharPos(i.dir);
			System.out.print(i.elemento + " ");
		}
	}
	
	public void caminharPre(No i){
		if(i != null){
			System.out.print(i.elemento + " ");
			caminharPre(i.esq);
			caminharPre(i.dir);
		}
	}
}
public class Principal{

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		Arvore a = new Arvore();
		while(scan.hasNextLine()){
			String entrada = scan.nextLine();
			//System.out.println(entrada);
			if(entrada.charAt(1) == 'N'){
                                a.caminharCentral();
                                System.out.println();

			}else if(entrada.charAt(0) == 'I'){
                                a.inserir(entrada.charAt(2));
			}else if(entrada.charAt(1) == 'R'){
				a.caminharPre();
				System.out.println();
			}else if(entrada.charAt(1) == 'O'){
				a.caminharPos();
				System.out.println();
			}else if(entrada.charAt(0) == 'P'){
                               	if(a.pesquisar(entrada.charAt(2)) == false){
                                        System.out.println(entrada.charAt(2) + " nao existe");
                                }else{
                                        System.out.println(entrada.charAt(2) + " existe");
                                }
			}
		}	
	}
}
