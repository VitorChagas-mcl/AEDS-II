import java.util.*;
class No{
	public int elemento;
	public No dir, esq;
    public int nivel;

	public No(int x){
		this.elemento = x;
		this.dir = this.esq = null;
        this.nivel = 1;
	}

    public void setNivel(){
        this.nivel = 1 + (getNivel(dir) > getNivel(esq) ? getNivel(dir) : getNivel(esq));
    }

    private static int getNivel(No no){
        return (no == null) ? 0 : no.nivel;
    }

    public int getFatorBalanceamento(){
        return getNivel(dir) - getNivel(esq);
    }
}

class Arvore{
	public No raiz;

	public Arvore(){
		this.raiz = null;	
	}

	public void inserir(int x){
		raiz = inserir(x, raiz);
	}

	public No inserir(int x, No i){
		if(i == null){
			i = new No(x);
		}else if(x < i.elemento){
			i.esq = inserir(x, i.esq);
		}else if(x > i.elemento){
			i.dir = inserir(x, i.dir);
		}else{
			System.out.println("Erro ao inserir");
			return i;
		}
        i.setNivel();
		return balancear(i);
	}

	public boolean pesquisar(int x){
		return pesquisar(x, raiz);
	}

	public boolean pesquisar(int x, No i){
        boolean resp = false;
		if(i == null){
			resp = false;
		}else if(x == i.elemento){
			System.out.printf(i.elemento + " ");
			resp = true;
		}else if(x < i.elemento){
			System.out.printf(i.elemento + " ");
			resp = pesquisar(x, i.esq);
		}else{
			System.out.printf(i.elemento + " ");
			resp = pesquisar(x, i.dir);
		}
		return resp;
	}

	public void caminhaPre(No i){
		if(raiz == null)
			System.out.print("V");
		if(i != null){ 
            System.out.print(i.elemento +"(" + i.nivel + ")" + " ");
			caminhaPre(i.esq);
			caminhaPre(i.dir);
		}
	}

	public void caminhaPos(No i){
		if(raiz == null)
			System.out.print("V");
		if(i != null){
			caminhaPos(i.esq);
			caminhaPos(i.dir);
			System.out.print(i.elemento + "(" + i.nivel + ")" + " ");
		}
	}

	public void caminhaCentral(No i){
		if(raiz == null)
			System.out.print("V");
		if(i != null){	
			caminhaCentral(i.esq);	
			System.out.print(i.elemento + "(" + i.nivel + ")" + "fb=" + i.getFatorBalanceamento() + " ");
			caminhaCentral(i.dir);
		}
	}

    public No rotacaoSimplesEsq(No no){
        No noDir = no.dir;
        No noDirEsq = noDir.esq;

        noDir.esq = no;
        no.dir = noDirEsq;
        no.setNivel();
        noDir.setNivel();
        return noDir;  
    }

    public No rotacaoSimplesDir(No no){
        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;

        noEsq.dir = no;
        no.esq = noEsqDir;
        no.setNivel();
        noEsq.setNivel();
        return noEsq;
    }

    public No rotacaoDuplaEsqDir(No no){
        no.esq = rotacaoSimplesEsq(no.esq);
        return rotacaoSimplesDir(no);
    }

    public No rotacaoDuplaDirEsq(No no){
        no.dir = rotacaoSimplesDir(no.dir);
        return rotacaoSimplesEsq(no);
    }

    private No balancear(No i){
       int fator = i.getFatorBalanceamento();
       if(fator == 2){
            if(i.dir.getFatorBalanceamento() == 1 || i.dir.getFatorBalanceamento() == 0){
                i = rotacaoSimplesEsq(i);
            }else{
                i = rotacaoDuplaDirEsq(i);
            }
       }else if(fator == -2){
            if(i.esq.getFatorBalanceamento() == -1 || i.esq.getFatorBalanceamento() == 0){
                i = rotacaoSimplesDir(i);
            }else{
                i = rotacaoDuplaEsqDir(i);
            }
       }
       i.setNivel();
       return i;
    }
}

public class Principal{
	public static void main(String[] args){
		Arvore a = new Arvore();
		int valor;
		String leitura;
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()){
            leitura = scan.next();

            if(leitura.charAt(0) == 'I'){
                valor = scan.nextInt();
                a.inserir(valor);
            }else if(leitura.charAt(0) == 'E'){
                a.caminhaCentral(a.raiz);
                System.out.println();
            }else if(leitura.charAt(0) == 'P' && leitura.length() == 1){
                valor = scan.nextInt();
            if(a.pesquisar(valor)){
                    System.out.println("S");
                }else{
                    System.out.println("N");
                }
            }else if(leitura.charAt(1) == 'R'){   
                a.caminhaPre(a.raiz);
                System.out.println();
            }else if(leitura.charAt(1) == 'O'){   
                a.caminhaPos(a.raiz);
                System.out.println();
            }
        }
		scan.close();
	}
}
