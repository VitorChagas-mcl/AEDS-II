import java.util.Scanner;

class Hash{
    public String[] tabela;
    public int m;
    public int r;
    public int nr;

    public Hash(int m, int r){
        this.tabela = new String[m + r];
        this.m = m;
        this.r = r;
        this.nr = 0;
    }

    private int somaDosCaracteres(String chave){
        int soma = 0;
        for(int i = 0; i < chave.length(); i++){
            char letra = chave.charAt(i);   
            soma += (int)letra;
        }

        return soma;
    }

    private int hash(String chave){
        return somaDosCaracteres(chave) % m;
    }

    private boolean isPosicaoLivre(int pos){
        return tabela[pos] == null;
    }

    public void inserir(String chave) throws Exception{
        if(pesquisar(chave) == true){
            System.out.println("Erro");    
        }
        
        int pos = hash(chave);
        if(isPosicaoLivre(pos) == true){
            tabela[pos] = chave;
        }else if(nr < r){
            tabela[m + nr] = chave;
            nr++;
        }else{
            System.out.println("Erro");
        }
    }

    public boolean pesquisar(String chave){
        int pos = hash(chave);
        boolean resp = false;
        if(isPosicaoLivre(pos) == true){
            resp = false;
        }else if (tabela[pos].compareTo(chave) == 0){
            resp = true;
        }else{ 
            for(int i = m; i < m + nr; i++){
                if(tabela[i].compareTo(chave) == 0){
                    resp = true;
                    i = m + nr;
                }
            }
        }
        return resp;
    }

    public boolean remover(String chave){
        int pos = hash(chave);
        boolean resp = false;
        if(isPosicaoLivre(pos) == true){
            resp = false;
        }else if (tabela[pos].compareTo(chave) == 0){
            resp = true;
        }else{ 
            for(int i = m; i < m + nr; i++){
                if(tabela[i].compareTo(chave) == 0){
                    resp = true;
                    tabela[i] = null;
                    i = m + nr;
                }
            }
            
        }
        return resp;
    }

    public void imprimir(){
        for(int i = 0; i < m + r; i++){
            System.out.println(i + " " + ((i < m) ? "Principal " : "Reserva ")+  (tabela[i] != null ? tabela[i] : "-"));
        }
    }
}

public class Principal{
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        Hash tabelaHash = new Hash(11, 3);
        String leitura;
        String inicial;
        while(scan.hasNext()){
            inicial = scan.next();
            if(inicial.charAt(0) == 'I'){
                leitura = scan.next();
                tabelaHash.inserir(leitura);
            }else if(inicial.charAt(0) == 'P'){
                leitura = scan.next();
                boolean resp = tabelaHash.pesquisar(leitura);
                System.out.println((resp) ? "Sim" : "Nao");
            }else if(inicial.charAt(0) == 'M'){
                tabelaHash.imprimir();
            }else if(inicial.charAt(0) == 'R'){
                leitura = scan.next();
                tabelaHash.remover(leitura);
            }
        }
    }
}
