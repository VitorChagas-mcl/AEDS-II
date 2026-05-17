import java.util.Scanner;

class Celula{
    public int elemento;
    public Celula sup, inf, dir, esq;

    public Celula() {
        this.elemento = 0;
        this.sup = this.inf = this.dir = this.esq = null;
    }
    
    public Celula(int x){
        this.elemento = x;
        this.sup = this.inf = this.dir = this.esq = null;
    }
}

public class Matriz{
    public Celula inicio;

    public int linha, coluna;
    public Matriz(int linha, int coluna) {
    		this.linha = linha;
    		this.coluna = coluna;
            if (linha <= 0 || coluna <= 0) {
                inicio = null;
                return;
            }

    		inicio = new Celula();

    		// Constroi a primeira linha
    		Celula atual = inicio;
    		for (int j = 1; j < coluna; j++) {
        		atual.dir = new Celula();
        		atual.dir.esq = atual;
        		atual = atual.dir;
    		}

    		// Constroi as linhas que faltam
    		Celula inicioLinhaAnterior = inicio;
    		for (int i = 1; i < linha; i++) {
        		Celula inicioLinhaAtual = new Celula(); // cria a celula nova
        		inicioLinhaAtual.sup = inicioLinhaAnterior;//conecta ela com as outras linhas
        		inicioLinhaAnterior.inf = inicioLinhaAtual;

        		Celula acima = inicioLinhaAnterior.dir;
        		atual = inicioLinhaAtual;
        		for (int j = 1; j < coluna; j++) {
            			atual.dir = new Celula();
           			    atual.dir.esq = atual;
            			atual = atual.dir;
            			atual.sup = acima;
            			acima.inf = atual;
            			acima = acima.dir;
        		}

        		inicioLinhaAnterior = inicioLinhaAtual;
    		}
    }

    public Matriz somar(Matriz m) {
        	Matriz resp = null;

        	if (this.linha == m.linha && this.coluna == m.coluna) { // confere se o tamanho das matrizes são iguais 
            		resp = new Matriz(this.linha, this.coluna); // Se sim, cria uma matriz nova do mesmo tamanho

            		Celula iA = this.inicio; // Cria celulas novas que referenciam a celula de inicio de todas as matrizes (usaremos estas para iterar a matriz)
            		Celula iB = m.inicio;
            		Celula iC = resp.inicio;

            		for (; iA != null; iA = iA.inf, iB = iB.inf, iC = iC.inf) {// for de fora: anda "pra baixo" nas matrizes até a referencia inf ser null 
                		Celula a = iA;//Cria celulas novas que apontam para as criadas anteriormente
                		Celula b = iB;
                		Celula c = iC;

                		for (; a != null; a = a.dir, b = b.dir, c = c.dir) {//for de dentro: anda para a direita até a referencia dir ser null
                    			c.elemento = a.elemento + b.elemento; //soma os elementos das celulas a e b e coloca na celula c  
                		}	
            		}	
    
    	    }

        	return resp; // retorna a matriz criada com os resultados da soma
    	}

    public Matriz multiplicar(Matriz m){
        Matriz resp = null;
        if (this.coluna == m.linha) { // ← condição correta para multiplicação matricial
            resp = new Matriz(this.linha, m.coluna);

            Celula linhaA = this.inicio;
            Celula linhaR = resp.inicio;

            for (; linhaA != null; linhaA = linhaA.inf, linhaR = linhaR.inf) {
                for (int j = 0; j < m.coluna; j++) {
    
                    // Pega início da coluna j de B
                    Celula cabecaColB = m.inicio;
                    for (int c = 0; c < j; c++) cabecaColB = cabecaColB.dir;

                 // Produto escalar: linha de A · coluna de B
                    int soma = 0;
                    Celula celA = linhaA, celB = cabecaColB;
                    while (celA != null && celB != null) {
                        soma += celA.elemento * celB.elemento;
                        celA = celA.dir;
                        celB = celB.inf;
                    }

                    Celula celR = linhaR;
                    for (int c = 0; c < j; c++) celR = celR.dir;
                    celR.elemento = soma;
                } 
            }
        }
        return resp;
    }    

    public void mostrarDiagonalPrincipal(){
        Celula i = inicio;

        while(i != null){
            System.out.print(i.elemento);
            Celula prox = (i.inf != null) ? i.inf.dir : null;
            if (prox != null) System.out.print(" ");
            i = prox;
        }
        System.out.println();
    }

    public void mostrarDiagonalSecundaria(){
        Celula i = inicio;
        if(i == null) return;
        while(i.dir != null) i = i.dir;

        while(i != null){
            System.out.print(i.elemento);
            Celula prox = (i.inf != null) ? i.inf.esq : null;
            if (prox != null) System.out.print(" ");
            i = prox;
        }
        System.out.println();
    }
    
    public void mostrar(){
        Celula linha = inicio;
        while (linha != null) {
            
            Celula cel = linha;
            while (cel != null) {
                System.out.print(cel.elemento);
                if (cel.dir != null) System.out.print(" ");
                cel = cel.dir; 
            }
            System.out.println("");
            linha = linha.inf;
        }
    }
   
    public void ler(Scanner sc) {
        Celula linha = inicio;
        while (linha != null) {
            Celula cel = linha;
            while (cel != null) {
                if (sc.hasNextInt()) {
                    cel.elemento = sc.nextInt();
                }
                cel = cel.dir;
            }
            linha = linha.inf;
        }
    }

    public static void main(String[] args){
        
        Scanner scan = new Scanner(System.in);

            
            int t = scan.nextInt();

            for(int i = 0; i < t; i++){
                int l1 = scan.nextInt(); 
                int c1 = scan.nextInt();

                Matriz mat1 = new Matriz(l1, c1); 
                mat1.ler(scan);
                
                int l2 = l1, c2 = c1;
                
                Matriz mat2 = new Matriz(l2, c2);
                mat2.ler(scan);

                mat1.mostrarDiagonalPrincipal();
                mat2.mostrarDiagonalSecundaria();

                Matriz soma = mat1.somar(mat2);
                if (soma != null) {
                    soma.mostrar();
                }
    
                Matriz produto = mat1.multiplicar(mat2);
                if (produto != null) {
                    produto.mostrar();
                }            
            }
        scan.close();
    }
}
