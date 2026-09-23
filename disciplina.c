#include "disciplina.h"

#include <stdio.h>
#include <string.h>

#include "professor.h"

void RelatorioDisciplinas(DISCIPLINA lista_disciplinas[],
                          int qnt_disciplinas_cadastradas) {
  int contador = 0;

  printf("\n///       LISTAR DISCIPLINAS       ///\n");

  for (int i = 0; i < QTD_DISCIPLINAS; i++) {
    if (lista_disciplinas[i].preenchido == 1) {
      printf("\n-----------------------------------\n");
      printf("Codigo: %d\n", lista_disciplinas[i].codigo);
      printf("Nome: %s\n", lista_disciplinas[i].nome);
      printf("Semestre: %d\n", lista_disciplinas[i].semestre);
      printf("Matricula do professor responsavel: %d\n",
             lista_disciplinas[i].matriculaProfessor);

      contador++;
    }
  }

  if (contador == 0) {
    printf("\nNenhuma disciplina cadastrada.\n");
  }

  printf("\n-----------------------------------\n");
}

void RelatorioUmaDisciplina(DISCIPLINA lista_disciplinas[],
                            ALUNO lista_alunos[],
                            int qnt_disciplinas_cadastradas,
                            int qnt_alunos_cadastrados) {
  int codigo;
  int indice_disciplina = -1;

  printf("\n///   CONSULTAR UMA DISCIPLINA   ///\n");
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);

  for (int i = 0; i < QTD_DISCIPLINAS; i++) {
    if (lista_disciplinas[i].preenchido == 1 &&
        lista_disciplinas[i].codigo == codigo) {
      indice_disciplina = i;
      break;
    }
  }

  if (indice_disciplina == -1) {
    printf("\nDisciplina nao encontrada.\n");
    return;
  }

  DISCIPLINA disciplina = lista_disciplinas[indice_disciplina];

  printf("\n-----------------------------------\n");
  printf("Codigo: %d\n", disciplina.codigo);
  printf("Nome: %s\n", disciplina.nome);
  printf("Semestre: %d\n", disciplina.semestre);
  printf("Matricula do professor responsavel: %d\n",
         disciplina.matriculaProfessor);

  printf("\nAlunos matriculados:\n");

  if (disciplina.qtd_alunos_matriculados == 0) {
    printf("Nenhum aluno matriculado.\n");
  } else {
    for (int i = 0; i < disciplina.qtd_alunos_matriculados; i++) {
      int matricula = disciplina.matriculasAlunos[i];

      for (int j = 0; j < QNT_ALUNOS; j++) {
        if (lista_alunos[j].preenchido == 1 &&
            lista_alunos[j].matricula == matricula) {
          printf("- Matricula: %d | Nome: %s\n", lista_alunos[j].matricula,
                 lista_alunos[j].nome);

          break;
        }
      }
    }
  }

  printf("-----------------------------------\n");
}

void RelatorioAlunosMenosTresDisciplinas(ALUNO lista_alunos[],
                                         int qnt_alunos_cadastrados) {
  int contador = 0;

  printf("\n/// ALUNOS EM MENOS DE 3 DISCIPLINAS ///\n");

  for (int i = 0; i < QNT_ALUNOS; i++) {
    if (lista_alunos[i].preenchido == 1 &&
        lista_alunos[i].contDisciplinas < 3) {
      printf("\n-----------------------------------\n");
      printf("Matricula: %d\n", lista_alunos[i].matricula);
      printf("Nome: %s\n", lista_alunos[i].nome);
      printf("Disciplinas matriculadas: %d\n", lista_alunos[i].contDisciplinas);

      contador++;
    }
  }

  if (contador == 0) {
    printf("\nNenhum aluno encontrado.\n");
  }

  printf("\n-----------------------------------\n");
}

void CRUD_Disciplinas(DISCIPLINA lista_disciplinas[], ALUNO lista_alunos[],
                      PROFESSOR lista_professores[],
                      int* qnt_disciplinas_cadastradas, int* codigoDisciplina) {
  int opcao = -1;

  do {
    Menu_CRUD();  // Certifique-se de que este menu não tem mais a opção
                  // "Listar" escrita, senão vai confundir o usuário
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
      case 1: {
        if (*qnt_disciplinas_cadastradas >= QTD_DISCIPLINAS) {
          printf("Erro: Limite de disciplinas atingido.\n");
          break;
        }

        int indice = -1;
        for (int i = 0; i < QTD_DISCIPLINAS; i++) {
          if (lista_disciplinas[i].preenchido == 0) {
            indice = i;
            break;
          }
        }

        printf("Nome da disciplina: ");
        fgets(lista_disciplinas[indice].nome, 50, stdin);
        lista_disciplinas[indice]
            .nome[strcspn(lista_disciplinas[indice].nome, "\n")] = 0;

        printf("Semestre: ");
        scanf("%d", &lista_disciplinas[indice].semestre);

        int matProfDigitada, profValido = 0;
        printf("Matricula do professor responsavel: ");
        scanf("%d", &matProfDigitada);

        for (int i = 0; i < QNT_PROFESSORES; i++) {
          if (lista_professores[i].preenchido == 1 &&
              lista_professores[i].matricula == matProfDigitada) {
            profValido = 1;
            break;
          }
        }

        if (profValido) {
          lista_disciplinas[indice].matriculaProfessor = matProfDigitada;
          lista_disciplinas[indice].codigo = *codigoDisciplina;
          lista_disciplinas[indice].preenchido = 1;

          (*codigoDisciplina)++;
          (*qnt_disciplinas_cadastradas)++;
          printf("Disciplina cadastrada com sucesso!\n");
        } else {
          printf(
              "Erro: Professor com matricula %d nao encontrado. Cadastro "
              "cancelado.\n",
              matProfDigitada);

          lista_disciplinas[indice] = (DISCIPLINA){0};
        }
        break;
      }

      case 2: {  // ATUALIZAR
        int codigoBusca, encontrou = 0;
        printf("Digite o codigo da disciplina a atualizar: ");
        scanf("%d", &codigoBusca);
        getchar();

        for (int i = 0; i < QTD_DISCIPLINAS; i++) {
          if (lista_disciplinas[i].preenchido == 1 &&
              lista_disciplinas[i].codigo == codigoBusca) {
            encontrou = 1;
            printf("Novo nome (atual: %s): ", lista_disciplinas[i].nome);
            fgets(lista_disciplinas[i].nome, 50, stdin);
            lista_disciplinas[i]
                .nome[strcspn(lista_disciplinas[i].nome, "\n")] = 0;

            printf("Novo semestre (atual: %d): ",
                   lista_disciplinas[i].semestre);
            scanf("%d", &lista_disciplinas[i].semestre);

            int matProfDigitada, profValido = 0;
            printf("Nova matricula do professor (atual: %d): ",
                   lista_disciplinas[i].matriculaProfessor);
            scanf("%d", &matProfDigitada);

            for (int j = 0; j < QNT_PROFESSORES; j++) {
              if (lista_professores[j].preenchido == 1 &&
                  lista_professores[j].matricula == matProfDigitada) {
                profValido = 1;
                break;
              }
            }

            if (profValido) {
              lista_disciplinas[i].matriculaProfessor = matProfDigitada;
              printf("Disciplina atualizada com sucesso!\n");
            } else {
              printf(
                  "Erro: Professor invalido. A disciplina manteve o professor "
                  "antigo.\n");
            }
            break;
          }
        }
        if (!encontrou) printf("Disciplina nao encontrada.\n");
        break;
      }

      case 3: {  // EXCLUIR
        int codigoBusca, encontrou = 0;
        printf("Digite o codigo da disciplina a excluir: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < QTD_DISCIPLINAS; i++) {
          if (lista_disciplinas[i].preenchido == 1 &&
              lista_disciplinas[i].codigo == codigoBusca) {
            lista_disciplinas[i] = (DISCIPLINA){0};
            (*qnt_disciplinas_cadastradas)--;

            printf("Disciplina excluida com sucesso!\n");
            encontrou = 1;
            break;
          }
        }
        if (!encontrou) printf("Disciplina nao encontrada.\n");
        break;
      }

      case 0:
        printf("Voltando ao menu principal...\n");
        break;

      default:
        printf("Opcao invalida!\n");
    }
  } while (opcao != 0);
}