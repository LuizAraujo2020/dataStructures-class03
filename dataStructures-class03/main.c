//
//  main.c
//  dataStructures-class03
//
//  Created by Luiz Carlos da Silva Araujo on 20/08/21.
//

// Sintese
//   objetivo "Lista Encadeada"
//   autor "Edson F. da Fonseca & Turma de Estrutura de Dados 2021/2"
//   data "14/08/2021"
#include<stdio.h>
#include<stdlib.h>


// *** Declaracao de tipos *********************************************************
struct tProduto {
    int codigo; // chave
    char descricao[20];
    float valor;
};

struct tNo {
    struct tProduto dado;
    struct tNo *prox;
};

// *** Prototipos ******************************************************************
int menu(void);
void inicializar(struct tNo**);
void incluir(struct tNo**, struct tNo*);
void listar(struct tNo*);
void consultar(struct tNo*, int);
void destruir(struct tNo**);

int main(int argc, const char * argv[]) {
    struct tNo *lista;
    struct tNo *p;
    struct tProduto produto;
    int opcao, codigo;
    
    inicializar(&lista);
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                printf("\n\n*** Inclusao ***\n\n");
                printf("Digite o codigo...: ");
                scanf("%d", &produto.codigo);
                printf("Digite a descricao: ");
                fflush(stdin);
                gets(produto.descricao);
                printf("Digite o valor....: R$ ");
                scanf("%f", &produto.valor);
                p = malloc(sizeof(struct tNo));
                p->dado = produto; // (*p).dado = produto;
                incluir(&lista, p);
                break;
            case 2:
                printf("\n\n*** Listagem ***\n\n");
                listar(lista);
                break;
            case 4:
                printf("\n\n*** Consulta ***\n\n");
                printf("Digite o codigo...: ");
                scanf("%d", &codigo);
                consultar(lista, codigo);
                
                break;
                
        }
    } while (opcao != 0);
    destruir(&lista);
    return 0;
}

// *** menu ************************************************************************
int menu(void) {
    int op;
    printf("\n\n*** Menu ***\n\n");
    printf("1. Incluir\n");
    printf("2. Excluir\n");
    printf("3. Alterar\n");
    printf("4. Consultar\n");
    printf("5. Listar\n");
    printf("0. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    return op;
}

// *** inicializar *****************************************************************
void inicializar(struct tNo **lst) {
    (*lst) = NULL;
}

// *** incluir *********************************************************************
void incluir(struct tNo **lst, struct tNo *novo) { // ponteiro por referencia, ponteiro por valor
    struct tNo *p = (*lst);
    
    if ((*lst) == NULL) { // vazia/unico
        (*lst) = novo;
        novo->prox = NULL;
    }
    else { // inicio, fim e meio
        if (novo->dado.codigo < (*lst)->dado.codigo) { // inicio
            novo->prox = (*lst);
            (*lst) = novo;
        }
        else { // fim e meio
               // coloca o p no ultimo noh da lista
            while (p->prox != NULL)
                p = p->prox;
            if (novo->dado.codigo > p->dado.codigo) { // fim
                novo->prox = NULL;
                p->prox = novo;
            }
            else { // meio
                   // coloca o p no noh anterior ao noh que entrara
                p = (*lst);
                while (p->prox->dado.codigo < novo->dado.codigo)
                    p = p->prox;
                novo->prox = p->prox;
                p->prox = novo;
            }
        }
    }
}

// *** Listar **********************************************************************
void listar(struct tNo *lst) {
    struct tNo *p = lst;
    printf("Cod-- Descricao----------- Valor\n");
    while (p != NULL) {
        printf("%5d %-20s R$ %.2f\n", p->dado.codigo, p->dado.descricao, p->dado.valor);
        p = p->prox;
    }
}

// *** Consultar ********************************************************************
void consultar(struct tNo *lst, int cod){
    struct tNo *p = lst;
    int counter = 0;
    
    printf("Cod-- Descricao----------- Valor\n");
    while (p != NULL) {//listar todos, com repeticao de cod
        if (p->dado.codigo == cod) {
            counter++;
            printf("%5d %-20s R$ %.2f\n", p->dado.codigo, p->dado.descricao, p->dado.valor);
        }
        p = p->prox;
    }
    printf("\n\nENCONTRADOS: %d", counter);
    
    
    
    while (p->dado.codigo != cod) // sem repeticao de cod
        p = p->prox;
    printf("%5d %-20s R$ %.2f\n", p->dado.codigo, p->dado.descricao, p->dado.valor);

    
}

// *** Destruir ********************************************************************
void destruir(struct tNo **lst) {
    struct tNo *p = (*lst);
    struct tNo *q;
    
    while (p->prox != NULL) {
        q = p;
        p = p->prox;
        q = NULL;
    }
}

