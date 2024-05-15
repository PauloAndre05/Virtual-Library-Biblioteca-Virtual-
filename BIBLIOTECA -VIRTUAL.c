#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LivroS 100
#define MAX_titulo_LENGTH 100
#define MAX_autor_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_DIGITS 6

typedef struct {
    char titulo[MAX_titulo_LENGTH];
    char autor[MAX_autor_LENGTH];
    int ano__de_lancamento;
    int emprestado, encontrado;
} Livro;

Livro biblioteca[MAX_LivroS];
int numLivros = 1;

void adicionarLivro(char titulo[], char autor[], int ano__de_lancamento) {
    if (numLivros < MAX_LivroS) {
        strcpy(biblioteca[numLivros].titulo, titulo);
        strcpy(biblioteca[numLivros].autor, autor);
        biblioteca[numLivros].ano__de_lancamento = ano__de_lancamento;
        biblioteca[numLivros].emprestado = 0;
        numLivros++;
    } else {
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
    }
}

void listarTodosLivros() {
	int i;
    printf("\t\t\t\t\tTodos os livros da Biblioteca: \n\n");
    for( i = 1; i < numLivros; i++){
       printf("\t\t\t\tCodigo %d - %s, %s, %d \n", i, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano__de_lancamento); 
    }
}

void listarLivrosNaoEmprestado() {
	int i;
    printf("\t\t\t\t\tLivros disponiveis na Biblioteca: \n\n");
    for( i = 1; i < numLivros; i++){
        if(!biblioteca[i].emprestado) 
            printf("\t\t\t\tCodigo %d - %s, %s, %d \n", i, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano__de_lancamento);
    }
}

void listarLivroEmprestado() {
	int i, encontrado = 0;
	 printf("\t\t\t\t\tLivros emprestados: \n\n");
	for(i = 1; i < numLivros; i++)
	{
		if(biblioteca[i].emprestado){
			printf("\t\t\t\tCodigo %d - %s, %s, %d \n", i, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano__de_lancamento);
			encontrado = 1;
			}
		
	}
		if(!encontrado)
			printf("\n\t\t\t\tUPS, nenhum livro emprestado ate ao momento!\n");
}

void pesquisarLivroPeloAutor(char autor[]) {
    printf("\nLivros do autor %s:\n", autor);
    int encontrar = 0, i, codigo;
    for (i = 1; i < numLivros; i++) {
        if (strcmp(biblioteca[i].autor, autor) == 0) {
            printf("%i - %s (lancado em %d)\n",i, biblioteca[i].titulo, biblioteca[i].ano__de_lancamento);
            encontrar = 1;
            biblioteca[i].encontrado = 1;
        }
    }
	 
 	if(encontrar) {
		printf("Escolha um livro: ");
	 	scanf("%i", &codigo);
	 	for(i = 1; i < numLivros; i++){
		 if(codigo == i && biblioteca[i].encontrado)
 			printf("Voce escolheu o livro %s de %s", biblioteca[i].titulo, biblioteca[i].autor);
		}
	 }
	 
    if (!encontrar) {
        printf("Nenhum livro encontrado para este autor.\n\n");
        printf("Esses sao os livros que temos disponiveis na nossa Biblioteca\n");
        listarTodosLivros();
    }
}

void pesquisarLivroPeloTitulo(char titulo[]) {
    printf("\nAutor do livro %s: \n", titulo);
    int encontrar = 0, i;
    for (i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("%s (lancado em %d)\n", biblioteca[i].autor, biblioteca[i].ano__de_lancamento);
            encontrar = 1;
            break;
        }
    }
    if (!encontrar) {
        printf("Livro nao encontrado.\n\n");
        printf("Esses sao os livros que temos disponiveis na nossa Biblioteca\n");
        printf("\n Titulo / Autor / Ano de Lancamento\n\n");
    	for(i = 0; i < numLivros; i++) {
			printf("{ %s / %s / %d }\n", biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano__de_lancamento);
		}
    }
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//void limparTela() {
//	system("clear");
//}

int main() {
	
	// Livros adicionados a Bibloteca
    adicionarLivro("Mayombe", "Pepetela", 1980);
    adicionarLivro("A Gloriosa Familia", "Pepetela", 1997);
    adicionarLivro("A Montanha da Agua Lilas", "Henrique", 2002);
    adicionarLivro("As Memorias da Guerra", "Sousa", 2009);
    adicionarLivro("Dentes de Rato", "Agualusa", 2003);
    adicionarLivro("O Planalto e a Estepe", "Pepetela", 2009);
    adicionarLivro("Os Predadores", "Pepetela", 2005);
    adicionarLivro("O Vendedor de Passados", "Jose Eduardo Agualusa", 2004);
    adicionarLivro("A Rainha Ginga", "Jose Eduardo Agualusa", 2014);
    adicionarLivro("Bom Dia Camaradas", "Ondjaki", 2001);
    adicionarLivro("Os Transparentes", "Ondjaki", 2012);
    adicionarLivro("A Geracao da Utopia", "Pepetela", 1992);
    adicionarLivro("Yaka", "Pepetela", 1984);
    adicionarLivro("Os da Minha Rua", "Ondjaki", 2007);
    adicionarLivro("Teoria Geral do Esquecimento", "Jose Eduardo Agualusa", 2012);

    char nomeUsuario[MAX_NAME_LENGTH];
    char numeroEstudante[MAX_DIGITS + 2];
    
	printf("\t\t\tOla, Seja Bem-Vindo a Biblioteca\n\t\t\t\tVamos Comecar!\n\n");

    printf("Digite seu nome completo: ");
    fgets(nomeUsuario, MAX_NAME_LENGTH, stdin);
    nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0'; 

    do {
        printf("Ola %s, digite o seu numero do Estudante (6 digitos): ", nomeUsuario);
        fgets(numeroEstudante, sizeof(numeroEstudante), stdin);
        
        numeroEstudante[strcspn(numeroEstudante, "\n")] = '\0';
        
        if (strlen(numeroEstudante) == MAX_DIGITS) {
            printf("Numero de estudante valido: %s\n", numeroEstudante);
        } else {
            printf("Numero de estudante invalido. Tente novamente.\n");
			limparBufferEntrada();
        }
    } while (strlen(numeroEstudante) != MAX_DIGITS);

    char opcao, resposta = 'S';
    char titulo[MAX_titulo_LENGTH];
    char autor[MAX_autor_LENGTH];
    int codigo;

    do {
        printf("\n\n\n\n\t\t\t\t\t\tMenu da Bibioteca:\n\n");
        printf("\t\t\t\t\t1. Listar Todos os livros da Biblioteca\n");
        printf("\t\t\t\t\t2. Listar livros disponiveis na Biblioteca\n");
        printf("\t\t\t\t\t3. Listar livros emprestados na Biblioteca\n");
        printf("\t\t\t\t\t4. Pesquisar Livro pelo autor\n");
        printf("\t\t\t\t\t5. Pesquisar livro pelo titulo \n");
        printf("\t\t\t\t\t6. Empresar um livro\n");
        printf("\t\t\t\t\t7. Devolver um livro\n");
        printf("\t\t\t\t\t8. Sair\n\n");
        printf("\t\t\t\t\tEscolha uma opcao: ");
        scanf(" %c", &opcao);
        printf("\n\n\n\n");

        switch (opcao) {
        	case '1':
                listarTodosLivros();
                break;
        	case '2':
                listarLivrosNaoEmprestado();
                break;
            case '3':
			    listarLivroEmprestado();       
                break;
            case '4':
                printf("Digite o nome do autor: ");
                scanf("%s", autor);
                pesquisarLivroPeloAutor(autor);
                
                break;
            case '5':
                printf("Digite o título do livro: ");
                scanf("%s", titulo);
                pesquisarLivroPeloTitulo(titulo);
                break;
            case '6':
                 do {
			        listarLivrosNaoEmprestado();
			        
			        printf("\n\nDigite o codigo do Livro que deseja emprestar: ");
			        scanf("%d", &codigo);
			
			        if(codigo >= 1 && codigo < numLivros && !biblioteca[codigo].emprestado) {
			            printf("Voce acaba de emprestar o livro %s\n", biblioteca[codigo].titulo);
			            printf("Prazo de devolucao 24h\n\n");
			            biblioteca[codigo].emprestado = 1; 
			        } else {
			            printf("Codigo invalido ou livro ja emprestado!\n");
			        }
			        
			        printf("Deseja emprestar mais livro[S/N]: ");
			        getchar(); 
			        resposta = getchar();
			        resposta = toupper(resposta); 
			    } while(resposta == 'S');
                break;
            case '7':
            	listarTodosLivros();
                do {
			        printf("\n\nDigite o codigo do Livro que deseja devolver: ");
			        scanf("%d", &codigo);
			
			        if(codigo >= 1 && codigo < numLivros && biblioteca[codigo].emprestado) {
			            printf("Livro %s devolvido com sucesso!\n", biblioteca[codigo].titulo);
			            printf("Prazo de devolucao 24h\n\n");
			            biblioteca[codigo].emprestado = 0;
			        } else {
			            printf("Codigo invalido o livro nao emprestado!\n");
			        }
			        
			        printf("Digite S para tentar novamente ou N para sair [S/N]: ");
			        getchar(); 
			        resposta = getchar();
			        resposta = toupper(resposta); 
			    } while(resposta == 'S');
                break;
            case '8':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '8');

    return 0;
}

