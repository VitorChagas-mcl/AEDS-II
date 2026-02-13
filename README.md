# 📚 Atividades de AEDS II  
**Algoritmos e Estruturas de Dados II**

Olá! 👋  
Meu nome é **Vitor Hugo Chagas Maciel**, sou estudante de **Ciência da Computação na PUC Minas**.  
Este repositório reúne atividades, exercícios e implementações desenvolvidas ao longo da disciplina **AEDS II**.

---

## 🎯 Objetivo

Centralizar os códigos produzidos durante a disciplina, servindo como:

- Material de estudo 📖  
- Apoio para revisões e provas 🧠  
- Portfólio acadêmico no GitHub 💼  

---

## 📂 Estrutura do Repositório
-`LABS/` → Atividades práticas de laboratório.
-`PROVAS/` → Questões e resoluções de provas.
-`TPS/` → Trabalhos Práticos.
-`VERDE/` → Atividades avaliativas do semestre.



Cada pasta contém códigos-fonte em **C e JAVA**, organizados de acordo com o tipo de atividade.

---

## ⚙️ Compiladores e Ferramentas

- **C / C++**
  - Compilador: **GCC / G++**
  - Compilação:
    ```bash
    gcc arquivo.c -o programa
    ./programa
    ```

- **Java**
  - Compilador: **javac (OpenJDK / Oracle JDK)**
  - Execução:
    ```bash
    javac Main.java
    java Main
    ```

- **IDEs e Editores**
  - VS Code
  - IntelliJ IDEA
  - Eclipse

---


## 🚀 Exemplos de Conteúdo

### 🔹 Exemplo: Inserção em Árvore Binária de Busca (BST)

```c
typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}
