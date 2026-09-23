#include "disciplina.h"

#include <stdio.h>
#include <string.h>

#include "professor.h"

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