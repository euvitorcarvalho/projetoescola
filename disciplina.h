#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"

#define QTD_DISCIPLINAS 50
#define MAX_VAGAS 50

typedef struct {
  int codigo;
  char nome[50];
  int semestre;
  int matriculaProfessor;
  int preenchido;
  int matriculasAlunos[MAX_VAGAS];
  int qtd_alunos_matriculados;
} DISCIPLINA;

void CRUD_Disciplinas(DISCIPLINA lista_disciplinas[],
                      PROFESSOR lista_professores[],
                      int* qnt_disciplinas_cadastradas, int* codigoDisciplina);

#endif