#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "funcoes.h"



//MENU INICIAL
void MenuInicio(){
    printf("\n\n///          PROJETO ESCOLA         ///\n\n");

    printf("__________________ MENU __________________\n\n");
    printf("| 1 - Cadastrar Aluno                    |\n");
    printf("| 2 - Cadastrar Professor                |\n");
    printf("| 3 - Cadastrar Disciplina               |\n");
    printf("| 4 - Ver Relatórios                     |\n");
    printf("| 0 - Sair                               |\n");
    printf("|________________________________________|\n");

}
// MENU DO CRUD (CADASTRAR, ATUALIZAR, EXCLUIR)
void Menu_CRUD(){
    printf("\n\n///          CADASTRAR        ///\n\n");

    printf("__________________ MENU __________________\n\n");
    printf("| 1 - Cadastrar                          |\n");
    printf("| 2 - Atualizar Dados                    |\n");
    printf("| 3 - Excluir Aluno                      |\n");
    printf("| 0 - Sair                               |\n");
    printf("|________________________________________|\n");

}

// MENU DAS LISTAS
void MenuListas(){
    printf("\n\n///           VER RELATÓRIOS         ///\n\n");

    printf("__________________ LISTAS ________________\n\n");
    printf("| 1 - listar Alunos                      |\n");
    printf("| 2 - Listar Professores                 |\n");
    printf("| 3 - Listar Disciplinas                 |\n");
    printf("| 4 - Lista de pessoas (professor/aluno) |\n"); //a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome.
    printf("| 5 - Aniversariantes do mês             |\n"); 
    printf("| 0 - Voltar                             |\n");
    printf("|________________________________________|\n");
}

// MENU DE ORDENAÇÃO DAS LISTAGENS
void MenuListasFiltros(){
    printf("\n________________ FILTROS _______________\n\n");
    printf("| 1 - Ordenar por matricula              |\n");
    printf("| 2 - Ordenar por nome                   |\n");
    printf("| 3 - Ordenar por data de nascimento     |\n");
    printf("| 4 - Filtrar por sexo                   |\n");
    printf("| 0 - Voltar                             |\n");
    printf("|________________________________________|\n");

}


void ler_str(char str[], int tamanho){ // recebe uma string e o tamanho dela

    // ler a string com o fgets
    fgets(str, tamanho, stdin); 

    // remove o \n que o fgets considera ao apertar enter
    str[strcspn(str, "\n")] = '\0';
}


void lerData(TipoData *pData){ // recebe o endereço da variavel do tipo Data
    int num;

    // lê um numero no formato ddmmaaaa
    scanf("%d",&num);  
    getchar(); // limpar buffer 😭
    // chama função para separar em dia, mes e ano
    *pData = DiaMesAno(num);
}

TipoData DiaMesAno(int num){ // recebe um numero inteiro no formato ddmmaaaa e retorna uma data separada em dia, mes e ano
    TipoData data;

    data.dia = num / 1000000;
    data.mes = (num % 1000000) / 10000;
    data.ano = num % 10000;

    return data;
}

//VER RELATORIOS
void ExecutarVerRelatorios(ALUNO *lista_alunos, PROFESSOR *lista_professores, int qnt_alunos_cadastrados, int qnt_professores_cadastrados){

    int listagem = -1;
   
    do{
        MenuListas();
        
        printf("\nEscolha uma opção: ");
        scanf("%d",&listagem);
        getchar();

        switch (listagem)
        {
            case 1 :
                RelatorioAlunos(lista_alunos, qnt_alunos_cadastrados);
                break;
            case 2 :
                RelatorioProfessores(lista_professores, qnt_professores_cadastrados);
                break;
            case 3 :
                //RelatorioDisciplinas();
                break;
            case 4 :
                //RelatorioPessoas();
                break;
            case 5 :
                //RelatorioAniversariantes();
                break;
            case 0 :
                printf("\n///  VOLTAR  ///\n");
                listagem = 0;
                break;
            default:
                printf("\n///  Erro - escolha uma opção valida  ///\n");
                break;
        }

    }while(listagem != 0);
}

void RelatorioPessoas(){
    printf("\n\n///   LISTAR PESSOAS   ///\n\n");

}

void RelatorioAniversariantes(){
    printf("\n\n///   LISTAR ANIVERSARIANTES   ///\n\n");

}