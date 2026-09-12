#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "validacao.h"

#define QNT_ALUNOS 3
#define QNT_PROFESSORES 3
#define QNT_DISCIPLINAS 3

void MenuInicio();
void MenuListas();
void MenuListasFiltros();

int main(){
    Aluno listaAlunos[QNT_ALUNOS];
    int qnt_alunos_cadastrados = 0;
    int matriculaAluno = 0;

    PROFESSOR listaProfessores[QNT_PROFESSORES];
    int qnt_professores_cadastrados = 0;
    int matriculaProfessor = 0;

    // Disciplina listaDisciplinas[QTD_DISCIPLINAS];
    int qnt_disciplinas_cadastradas = 0;

    char op[10];
    int continuar = 1;
    int sucesso;
    int menu = -1;

    do{
        MenuInicio();

        printf("\nEscolha uma opção: ");
        scanf("%d",&menu);
        getchar(); // limpar buffer 😭

        int listagem = -1;
        int listagem_alunos = -1;
        int listagem_professores = -1;

        switch(menu){
            case 1 :
                continuar = 1;
                printf("\n///  CADASTRO DE ALUNOS  ///\n\n");
                do{
                    if(qnt_alunos_cadastrados >= QNT_ALUNOS){
                        printf("\n/// Máximo de alunos cadastrados atingido. Voltando... ///\n");
                        break;
                    }

                    printf("/// Cadastrando aluno - %d. ///\n\n",qnt_alunos_cadastrados+1);
                    sucesso = cadastrarAluno(&listaAlunos[qnt_alunos_cadastrados]);

                    if(sucesso){
                        matriculaAluno++;
                        listaAlunos[qnt_alunos_cadastrados].matricula = matriculaAluno;
                        qnt_alunos_cadastrados++;
                    }
                    while(qnt_alunos_cadastrados < QNT_ALUNOS){
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
                            printf("\n///  Erro - Digite uma opção valida.  ///\n");
                    }

                }while(continuar == 1);
                break;
            case 2:
                printf("\n///  CADASTRO DE PROFESSORES  ///\n");
                continuar = 1;
                
                do{
                    if(qnt_professores_cadastrados >= QNT_PROFESSORES){
                        printf("\n/// Máximo de professores cadastrados atingido. Voltando... ///\n");
                        break;
                    }

                    printf("/// Cadastrando Professor - %d. ///\n\n",qnt_professores_cadastrados+1);

                    sucesso = cadastrarProfessor(&listaProfessores[qnt_professores_cadastrados]);

                    if(sucesso){
                        matriculaProfessor++;
                        listaProfessores[qnt_professores_cadastrados].matricula = matriculaProfessor;
                        qnt_professores_cadastrados++;
                    }
                    while(qnt_professores_cadastrados < QNT_PROFESSORES){
                        printf("\nDeseja cadastrar mais um professor? (s/n): ");
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
                            printf("\n///  Erro - Digite uma opção valida.  ///\n");
                    }

                }while(continuar == 1);
                break;

            case 3:
                printf("\n///  CADASTRO DE DISCIPLINAS  ///\n");
                break;
            case 4:
                
                do{
                    MenuListas();
                    
                    printf("\nEscolha uma opção: ");
                    scanf("%d",&listagem);
                    getchar();

                    switch (listagem)
                    {
                        case 1 :
                            do{
                                printf("\n\n///   LISTAR ALUNOS   ///\n\n");

                                MenuListasFiltros();

                                printf("\nEscolha uma opção: ");
                                scanf("%d",&listagem_alunos);
                                getchar();

                                switch (listagem_alunos)
                                {
                                    case 1:
                                        //Ordenar por matricula (Ordem padrão)
                                        listarAlunos(listaAlunos, qnt_alunos_cadastrados);
                                    break;

                                    case 2:
                                        //Ordenar por Nome
                                    break;

                                    case 3:
                                        //Ordenar por Data de nascimento
                                    break;

                                    case 4:
                                        //filtrar por sexo
                                    break;

                                    case 0:
                                        printf("\n///  VOLTAR  ///\n");
                                        listagem_alunos = 0;
                                    break;

                                    default:
                                        printf("\n///  Erro - escolha uma opção valida  ///\n");
                                    break;
                                }
                                
                            }while(listagem_alunos != 0);
                            break;
                        case 2 :
                            do{
                                printf("\n\n///   LISTAR PROFESSORES   ///\n\n");
                                MenuListasFiltros();

                                printf("\nEscolha uma opção: ");
                                scanf("%d",&listagem_professores);
                                getchar();

                                switch (listagem_professores)
                                {
                                    case 1:
                                        //Ordenar por matricula (Ordem padrão)
                                        listarProfessores(listaProfessores, qnt_professores_cadastrados);
                                    break;

                                    case 2:
                                        //Ordenar por Nome
                                    break;

                                    case 3:
                                        //Ordenar por Data de nascimento
                                    break;

                                    case 4:
                                        //filtrar por sexo
                                    break;

                                    case 0:
                                        printf("\n///  VOLTAR  ///\n");
                                        listagem_professores = 0;
                                    break;

                                    default:
                                        printf("\n///  Erro - escolha uma opção valida  ///\n");
                                    break;
                                }
                            }while(listagem_professores != 0);
                            break;
                        case 3 :
                            printf("\n\n///   LISTAR DISCIPLINAS   ///\n\n");
                            break;
                        case 4 :
                            printf("\n\n///   LISTAR PESSOAS   ///\n\n");
                            break;
                        case 5 :
                            printf("\n\n///   LISTAR ANIVERSARIANTES   ///\n\n");
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

void MenuInicio(){
    printf("\n\n///          PROJETO ESCOLA         ///\n\n");

    printf("__________________ MENU __________________\n\n");
    printf("| 1 - Cadastrar Aluno                    |\n");
    printf("| 2 - Cadastrar Professor                |\n");
    printf("| 3 - Cadastrar Disciplina               |\n");
    printf("| 4 - Ver Relatórios                         |\n");
    printf("| 0 - Sair                               |\n");
    printf("|________________________________________|\n");

}

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

void MenuListasFiltros(){
    printf("\n__________________ FILTROS __________________\n\n");
    printf("| 1 - Ordenar por matricula              |\n");
    printf("| 2 - Ordenar por nome                   |\n");
    printf("| 3 - Ordenar por data de nascimento     |\n");
    printf("| 4 - Filtrar por sexo                   |\n");
    printf("| 0 - Voltar                             |\n");
    printf("|________________________________________|\n");

}