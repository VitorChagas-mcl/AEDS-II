import java.util.*;
import java.io.*;

class Hora{
    private int hora;
    private int minuto;
    // construtor de hora
    public Hora(int hora, int minuto){
        this.hora = hora;
        this.minuto = minuto;
    }
    //gets e sets
    public int getHora(){
        return hora;
    }

    public int getMinuto(){
        return minuto;
    }

    public void setHora(int hora){
        this.hora = hora;
    }

    public void setMinuto(int minuto){
        this.minuto = minuto;
    }
    // parse de hora 
    public static Hora parseHora(String s){
        Scanner scan = new Scanner(s);// scanner da string
        scan.useDelimiter(":");// separa por :
        int hora = scan.nextInt();//leitura dos valores
        int minuto = scan.nextInt();
        Hora h = new Hora(hora,minuto);// criar o objeto hora
        return h;// retona a nova hora
    }

    public String formatar(){
        return String.format("%02d:%02d", this.hora, this.minuto); // retorna a hora formatada
    }
}   

class Data{
    
    private int ano;
    private int mes;
    private int dia;
    // construtor de data
    public Data(int ano, int mes, int dia){
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }
    //gets e sets
    public int getAno(){
        return ano;
    }

    public int getMes(){
        return mes;
    }

    public int getDia(){
        return dia;
    }

    public void setAno(int ano){
        this.ano = ano;
    }

    public void setMes(int mes){
        this.mes = mes;
    }

    public void setDia(int dia){
        this.dia = dia;
    }
    // parse de data 
    public static Data parseData(String s){ 
        Scanner scan = new Scanner(s);// scanner da string 
        scan.useDelimiter("-");// delimitacao pro -
        int ano = scan.nextInt();//leitura dos valores
        int mes = scan.nextInt();
        int dia = scan.nextInt();
        scan.close();
        Data data = new Data(ano, mes, dia);// cria um objeto data
        return data;// retorna a nova data
    }
   
    public String formatar(){
        return String.format("%02d/%02d/%04d", this.dia, this.mes, this.ano);// retorna a data no padrao brasileiro
    }
}
    
class Restaurante{
    private int idRestaurante;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tiposCozinha;
    private int faixa_preco;
    private Hora horarioAbertura;
    private Hora horarioFechamento;
    private Data dataAbertura;
    private boolean aberto;
    //construtor de restaurante
    public Restaurante(int idRestaurante, String nome, String cidade, int capacidade, double avaliacao,
            String[] tiposCozinha,int faixa_preco, Hora horarioAbertura, Hora horarioFechamento, Data dataAbertura, boolean aberto) {
        this.idRestaurante = idRestaurante;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixa_preco = faixa_preco;
        this.horarioAbertura = horarioAbertura;
        this.horarioFechamento = horarioFechamento;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;
    }
    //gets e sets
    public int getIdRestaurante() {
        return idRestaurante;
    }

    public void setIdRestaurante(int idRestaurante) {
        this.idRestaurante = idRestaurante;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public double getAvaliacao() {
        return avaliacao;
    }

    public void setAvaliacao(double avaliacao) {
        this.avaliacao = avaliacao;
    }

    public String[] getTiposCozinha() {
        return tiposCozinha;
    }

    public void setTiposCozinha(String[] tiposCozinha) {
        this.tiposCozinha = tiposCozinha;
    }

    public int getFaixa_Preco(){
        return faixa_preco;
    }

    public void setFaixa_Preco(int faixa_preco){
        this.faixa_preco = faixa_preco;
    }

    public Hora getHorarioAbertura() {
        return horarioAbertura;
    }

    public void setHorarioAbertura(Hora horarioAbertura) {
        this.horarioAbertura = horarioAbertura;
    }

    public Hora getHorarioFechamento() {
        return horarioFechamento;
    }

    public void setHorarioFechamento(Hora horarioFechamento) {
        this.horarioFechamento = horarioFechamento;
    }

    public Data getDataAbertura() {
        return dataAbertura;
    }

    public void setDataAbertura(Data dataAbertura) {
        this.dataAbertura = dataAbertura;
    }

    public boolean isAberto() {
        return aberto;
    }

    public void setAberto(boolean aberto) {
        this.aberto = aberto;
    }
    //função de pegar a quantidade do faixa preco e passar para int
    public static int pegarFaixa_Preco(String s){
        int cont = 0;    
        for(int i = 0; i < s.length(); i++)
            if(s.charAt(i) == '$') cont++;

        return cont;
    }

    public static Restaurante parseRestaurante(String s){
        Scanner scan = new Scanner(s);
        scan.useLocale(Locale.US);// usei para ler o double, pois vem na string ex:4.4 
        scan.useDelimiter(",");// delimitei para pegar ate a ,
        int id = scan.nextInt();
        String nome = scan.next();
        String cidade = scan.next();
        int capacidade = scan.nextInt();
        double avaliacao = scan.nextDouble();
        String tpCozinha = scan.next();  
        int faixa_preco = pegarFaixa_Preco(scan.next());
        String horarios = scan.next();
        Scanner scanHorarios = new Scanner(horarios); // novo scanner para ler as horas
        scanHorarios.useDelimiter("-");// delimitei para pegar ate - 
        Hora horaAbertura = Hora.parseHora(scanHorarios.next()); // chama da funcao para o parseHora
        Hora horaFechamento = Hora.parseHora(scanHorarios.next());
        scanHorarios.close(); // fechamento do scanner de horas
        Data dataAbertura = Data.parseData(scan.next()); // chamada da funcao para o parseData
        String abertoStr = scan.next(); // pega a string true ou false
        boolean aberto = (abertoStr.compareTo("true") == 0); // verifica se a palavra é true ou false e restona o seu valor

        scan.close(); // fachamento do scan principal

        String[] aux = new String[10]; // variavel auxiliar para pegar os Tipos de cozinha
        int cout = 0;// contador para pegar o tamanho exato de tipos
        Scanner scanTp = new Scanner(tpCozinha); // novo scanner de tuois
        scanTp.useDelimiter(";");// delimitei o ; pois ele separa os restaurantes
        while(scanTp.hasNext()){// verifica se exite palavra
            String palavra = scanTp.next();// le a palavra do vetor de string
            if(palavra.length() > 0){// se o tamanho da palavra for maior que 0
                aux[cout] = palavra; // auxiliar recebe a palavra adiciona a posição
                cout++;// e contador receber + 1
            }
        }
        scanTp.close();// fecho o scanner de tipos
    
        String[] tipoCozinha = new String[cout]; // crio um novo vetor de string
        for(int i = 0; i < cout; i++){// pego a quantidade exata de tipos
            tipoCozinha[i] = aux[i];// adiciono no vetor de tipoCozinha
        }
        //retorno um objeto restaurante
        return new Restaurante(id, nome, cidade, capacidade, avaliacao, tipoCozinha, 
                               faixa_preco ,horaAbertura, horaFechamento, dataAbertura, aberto);
    }

    public String formatar(){
     
        String strCozinhas = "";// criei um vetor para formatar o tipo de cozinha
        for(int i = 0; i < tiposCozinha.length; i++){// pego o tamanho exato do vetor
            strCozinhas += tiposCozinha[i];//adiciono a string o tipo de cozinha
            if(i < tiposCozinha.length - 1){// verifica se o i é menor que o tamanho do vetor se for adiciona ,
                strCozinhas += ","; 
            }
        }
        int n = this.faixa_preco;// pego o valor de faixa_preco
        String faixa_p = "";//crio uma string nova
        for(int i = 0; i < n; i++){
            faixa_p += '$';// adiciono a quantidade de n com $
        }
        
        double valor = this.avaliacao;
        String strAvaliacao = valor + ""; // pego o valor atual do double e coloco como string
                                         // se nao passar para string o formate retorna com , pois usar 
                                         // a localizacao que esta no meu pc

        String s = String.format("[%d ## %s ## %s ## %d ## %s ## [%s] ## %s ## %s-%s ## %s ## %b]", 
                idRestaurante, nome, cidade, capacidade, strAvaliacao, strCozinhas, 
                faixa_p, horarioAbertura.formatar(),horarioFechamento.formatar(), // formata o restaurante para o formato pedido
                dataAbertura.formatar(), aberto);
        return s; // retorna a string de restaurante formatado
    }
}

class ColecaoRestaurantes{
    private int tamanho;
    private Restaurante[] restaurantes;
    //contrutor sem parametros
    public ColecaoRestaurantes(){
        this.tamanho = 0;
        this.restaurantes = null;
    }
    //contrutor com parametros
    public ColecaoRestaurantes(int tamanho){
        this.tamanho = tamanho;//pega o tamanho da colecao
        this.restaurantes = new Restaurante[tamanho];// cria um vetor com o tamanho da colecao
    }

    public int getTamanho(){
        return tamanho;       
    }

    public void setTamanho(int tam){
        this.tamanho = tam;
    }
        
    public Restaurante[] getRestaurantes(){
        return restaurantes;
    }

    public void setRestaurantes(Restaurante[] restaurantes){
        this.restaurantes = restaurantes;
    }

    public void lerCsv(String path) throws Exception{// tive que usar throws porque estava dando erro
        File arquivo = new File(path);// abertura do arquivo para ler a linha de restaurante
        Scanner scan = new Scanner(arquivo);//abre o scan do csv
        
        if(scan.hasNextLine())//pula o cabecalho
            scan.nextLine();

        int i = 0;//um contador para o indece
        while(scan.hasNextLine()){//verifica se existe linha
           String linha = scan.nextLine();//le a linha de restaurante
           restaurantes[i] = Restaurante.parseRestaurante(linha);// chama a funcao do parse e guarda o restaurante 
           i++;// incremento do indece
        }
        
    }

    public static ColecaoRestaurantes lerCsv() throws Exception{
        File arquivo = new File("/tmp/restaurantes.csv"); // abertura do arquivo
        Scanner scan = new Scanner(arquivo);//leitura do arquivo

        int tam = 0;//contador para o tamanho de linha
        while(scan.hasNext()){
            scan.nextLine();//le a linha 
            tam++; // Adiciona a quantidade de linha lida no arquivo csv
        }

        scan.close();
        ColecaoRestaurantes novaCol = new ColecaoRestaurantes(tam - 1); // Cria o objeto colecao
        novaCol.lerCsv("/tmp/restaurantes.csv");// chamada da funcao de para leitura de restaurante
        
        return novaCol; // retorna a colecao de restaurante 
    }

    public Restaurante buscarPorId(int id){
         for(int i = 0; i < tamanho; i++){//pega o tamanho do vetor
            if(restaurantes[i].getIdRestaurante() == id){// e procura o restaurante na posicao atual 
                // e verifica se é igual ao id
                return restaurantes[i];// restona o restaurante na posicao 
            }
        }
        return null;// se nao achar retorna nada
     }
}

public class Principal{
        public static int comp = 0;

        public static boolean pesquisaSequencial(Restaurante[] r, String nome, int n){
            
            for(int i = 0; i < n; i++){
                comp++;
                if(r[i].getNome().compareTo(nome) == 0){
                    return true;
                }
            }
            return false;
        }

        public static void main(String[] args) throws Exception{
            Scanner scan = new Scanner(System.in);//scaner para leitura da entrada
            Restaurante[] r = new Restaurante[1000];
            int cont = 0;
            double inicio, fim, total_t = 0;
            ColecaoRestaurantes cr = ColecaoRestaurantes.lerCsv();//criar o colacao restaurante e preenche
            String linha = scan.nextLine();
            while(linha.compareTo("-1") != 0){
               
               int id = Integer.parseInt(linha);// parse int para pegar o valor de id
               Restaurante aux = cr.buscarPorId(id);//busca o restaurante
               if(aux != null){//verifica se é diferente de null
                 r[cont] = aux;
                 cont++;
               }

               linha = scan.nextLine();//leitura da proxima linha
            }

            linha = scan.nextLine();
            inicio = System.nanoTime();
            while(linha.compareTo("FIM") != 0){
                if(pesquisaSequencial(r, linha, cont) == true){
                    System.out.println("SIM");
                }else{
                    System.out.println("NAO");        
                }

                linha = scan.nextLine();
            }
            fim = System.nanoTime();
            total_t = (fim - inicio)/1_000_000.0;
            scan.close();// fechamanto do scan

            FileWriter arq = new FileWriter("880222_sequencial.txt");
            PrintWriter gravarArq = new PrintWriter(arq);

            gravarArq.printf("880222\t Comparacoes: %d\t Tempo: %.4f\n", comp, total_t);

            gravarArq.close();
        }


 }
