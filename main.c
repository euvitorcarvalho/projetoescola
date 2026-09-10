#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "validacoes.h"

#define QNT_ALUNOS 3
#define QNT_PROFESSORES 3
#define QNT_DISCIPLINAS 3

int main(){
    Aluno listaAlunos[QNT_ALUNOS];
    int qnt_alunos_cadastrados = 0;

    //PROFESSOR listaProfessores[QNT_PROFESSORES];
    int qnt_professores_cadastrados = 0;

    // Disciplina listaDisciplinas[QTD_DISCIPLINAS];
    int qnt_disciplinas_cadastradas = 0;

    int menu = -1;
    do{
        printf("\n       PROJETO ESCOLA\n");

        printf("\n___________ MENU ___________\n\n");
        printf("| 1 - Cadastrar Aluno       |\n");
        printf("| 2 - Cadastrar Professor   |\n");
        printf("| 3 - Cadastrar Disciplina  |\n");
        printf("| 4 - Ver Listas            |\n");
        printf("| 0 - Sair                  |\n");
        printf("_____________________________\n");

        printf("\nEscolha uma opção: ");
        scanf("%d",&menu);
        getchar(); // limpar buffer 😭

        switch(menu){
            case 1 :
                printf("\n-----CADASTRO DE ALUNOS------\n\n");
                char op[10];
                int continuar = 1;
                int sucesso;
                do{
                    if(qnt_alunos_cadastrados >= QNT_ALUNOS){
                        printf("\n/// Erro - Máximo de alunos cadastrados atingido. Voltando... ///\n");
                        break;
                    }

                    printf("/// Cadastrando aluno - %d. ///\n\n",qnt_alunos_cadastrados+1);
                    sucesso = cadastrarAluno(&listaAlunos[qnt_alunos_cadastrados]);

                    if(sucesso)
                        qnt_alunos_cadastrados++;

                    while(1){
                        printf("\nDeseja cadastrar mais um aluno? (s/n): ");
                        ler_str(op, sizeof(op));

                        if(op[0] == 'S' || op[0] == 's'){
                            continuar = 1;
                            break;
                        }
                        else if(op[0] == 'N' || op[0] == 'n'){
                            continuar = 0;
                            break;
                        }
                        else
                            printf("\nErro - Digite uma opção valida.\n");
                    }

                }while(continuar == 1);
                break;
            case 2:
                printf("\n---CADASTRO DE PROFESSORES---\n");
                break;
            case 3:
                printf("\n---CADASTRO DE DISCIPLINAS---\n");
                break;
            case 4:
                printf("\n---------VER LISTAS----------\n");
                break;
            case 0:
                printf("\n\n/////   PROGRAMA ENCERRADO   //////\n\n");
                break;
            default:
                printf("\nDigite uma opção valida.\n");
                break;
        }
    }while(menu != 0);
}