#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "validacao.h"
#include "funcoes.h"


int main(){
    ALUNO lista_alunos[QNT_ALUNOS];
    int qnt_alunos_cadastrados = 0;
    int matriculaAluno = 0;

    PROFESSOR lista_professores[QNT_PROFESSORES];
    int qnt_professores_cadastrados = 0;
    int matriculaProfessor = 0;

    // Disciplina listaDisciplinas[QTD_DISCIPLINAS];
    int qnt_disciplinas_cadastradas = 0;

    int menu = -1;

    do{
        MenuInicio();

        printf("\nEscolha uma opção: ");
        scanf("%d",&menu);
        getchar(); // limpar buffer 😭

        switch(menu){
            case 1 :
                CRUD_Alunos(lista_alunos, &qnt_alunos_cadastrados, &matriculaAluno);
                break;
            case 2:
                CRUD_Professores(lista_professores, &qnt_professores_cadastrados, &matriculaProfessor);
                break;

            case 3:
                //ExecutarCadastroDisciplinas();
                break;
            case 4:
                ExecutarVerRelatorios(lista_alunos, lista_professores, qnt_alunos_cadastrados, qnt_professores_cadastrados);
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

