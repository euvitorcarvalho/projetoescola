#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"

#define QTD_DISCIPLINAS 50
#define MAX_VAGAS 50

typedef struct DISCIPLINA {
  int codigo;
  char nome[50];
  int semestre;
  int matriculaProfessor;
  int preenchido;
  int matriculasAlunos[MAX_VAGAS];
  int qtd_alunos_matriculados;
} DISCIPLINA;

void RelatorioDisciplinas(DISCIPLINA lista_disciplinas[],
                          int qnt_disciplinas_cadastradas);

void CRUD_Disciplinas(DISCIPLINA lista_disciplinas[], ALUNO lista_alunos[],
                      PROFESSOR lista_professores[],
                      int* qnt_disciplinas_cadastradas, int* codigoDisciplina);

void RelatorioUmaDisciplina(DISCIPLINA lista_disciplinas[],
                            ALUNO lista_alunos[],
                            int qnt_disciplinas_cadastradas,
                            int qnt_alunos_cadastrados);

void RelatorioAlunosMenosTresDisciplinas(ALUNO lista_alunos[],
                                         int qnt_alunos_cadastrados);

void MatricularAlunoDisciplina(DISCIPLINA lista_disciplinas[],
                               ALUNO lista_alunos[],
                               int qnt_disciplinas_cadastradas,
                               int qnt_alunos_cadastrados);

void ExcluirAlunoDisciplina(DISCIPLINA lista_disciplinas[],
                            ALUNO lista_alunos[],
                            int qnt_disciplinas_cadastradas,
                            int qnt_alunos_cadastrados);

#endif