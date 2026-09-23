#include <stdio.h>
#include <string.h>

#include "aluno.h"
#include "disciplina.h"
#include "funcoes.h"
#include "professor.h"
#include "validacao.h"

int main() {
  // Lista de alunos
  ALUNO lista_alunos[QNT_ALUNOS];

  // Aluno 1
  strcpy(lista_alunos[0].nome, "Guilherme Almeida");
  strcpy(lista_alunos[0].CPF, "01234567890");
  lista_alunos[0].sexo = 'M';
  lista_alunos[0].dataNascimento = DiaMesAno(4072006);
  lista_alunos[0].preenchido = 1;
  lista_alunos[0].matricula = 1;

  // Aluno 2
  strcpy(lista_alunos[1].nome, "Luiza Almeida");
  strcpy(lista_alunos[1].CPF, "01234567890");
  lista_alunos[1].sexo = 'F';
  lista_alunos[1].dataNascimento = DiaMesAno(3082006);
  lista_alunos[1].preenchido = 1;
  lista_alunos[1].matricula = 2;

  // Aluno 3
  strcpy(lista_alunos[2].nome, "Vitor Carvalho");
  strcpy(lista_alunos[2].CPF, "01234567890");
  lista_alunos[2].sexo = 'M';
  lista_alunos[2].dataNascimento = DiaMesAno(24032006);
  lista_alunos[2].preenchido = 1;
  lista_alunos[2].matricula = 3;

  // Aluno 4
  strcpy(lista_alunos[3].nome, "Joaozinho");
  strcpy(lista_alunos[3].CPF, "01234567890");
  lista_alunos[3].sexo = 'M';
  lista_alunos[3].dataNascimento = DiaMesAno(17092020);
  lista_alunos[3].preenchido = 1;
  lista_alunos[3].matricula = 4;

  int qnt_alunos_cadastrados = 4;
  int matriculaAluno = 4;

  // Atribuição inicial a todos os alunos
  for (int i = qnt_alunos_cadastrados; i < QNT_ALUNOS; i++) {
    strcpy(lista_alunos[i].nome, "Sem nome");
    strcpy(lista_alunos[i].CPF, "00000000000");

    lista_alunos[i].sexo = 'O';
    lista_alunos[i].dataNascimento = DiaMesAno(0);
    lista_alunos[i].preenchido = 0;
    lista_alunos[i].matricula = 0;
  }

  // Lista de professores
  PROFESSOR lista_professores[QNT_PROFESSORES];

  // Professor 1
  strcpy(lista_professores[0].nome, "Daiane");
  strcpy(lista_professores[0].CPF, "01234567890");
  lista_professores[0].sexo = 'F';
  lista_professores[0].dataNascimento = DiaMesAno(2051989);
  ;
  lista_professores[0].preenchido = 1;
  lista_professores[0].matricula = 1;

  // Professor 2
  strcpy(lista_professores[1].nome, "Yulo");
  strcpy(lista_professores[1].CPF, "01234567890");
  lista_professores[1].sexo = 'M';
  lista_professores[1].dataNascimento = DiaMesAno(6071987);
  lista_professores[1].preenchido = 1;
  lista_professores[1].matricula = 2;

  // Professor 3
  strcpy(lista_professores[2].nome, "Leo");
  strcpy(lista_professores[2].CPF, "01234567890");
  lista_professores[2].sexo = 'M';
  lista_professores[2].dataNascimento = DiaMesAno(14041998);
  lista_professores[2].preenchido = 1;
  lista_professores[2].matricula = 3;

  int qnt_professores_cadastrados = 3;
  int matriculaProfessor = 3;

  // Atribuição inicial a todos os professores
  for (int i = qnt_professores_cadastrados; i < QNT_PROFESSORES; i++) {
    strcpy(lista_professores[i].nome, "Sem nome");
    strcpy(lista_professores[i].CPF, "00000000000");

    lista_professores[i].sexo = 'O';
    lista_professores[i].dataNascimento = DiaMesAno(0);
    lista_professores[i].preenchido = 0;
    lista_professores[i].matricula = 0;
  }

  // Lista de disciplinas
  DISCIPLINA lista_disciplinas[QTD_DISCIPLINAS];
  int qnt_disciplinas_cadastradas = 0;
  int codigoDisciplina = 1;  // Vai gerar o código autoincremento

  // Atribuição inicial a todas as disciplinas
  for (int i = 0; i < QTD_DISCIPLINAS; i++) {
    strcpy(lista_disciplinas[i].nome, "Sem nome");
    lista_disciplinas[i].semestre = 0;
    lista_disciplinas[i].matriculaProfessor = 0;
    lista_disciplinas[i].qtd_alunos_matriculados = 0;

    lista_disciplinas[i].preenchido = 0;
    lista_disciplinas[i].codigo = 0;
  }

  int menu = -1;

  do {
    MenuInicio();

    printf("\nEscolha uma opcao: ");
    scanf("%d", &menu);
    getchar();

    switch (menu) {
      case 1:
        CRUD_Alunos(lista_alunos, &qnt_alunos_cadastrados, &matriculaAluno);
        break;
      case 2:
        CRUD_Professores(lista_professores, &qnt_professores_cadastrados,
                         &matriculaProfessor);
        break;
      case 3:
        CRUD_Disciplinas(lista_disciplinas, lista_professores,
                         &qnt_disciplinas_cadastradas, &codigoDisciplina);
        break;
      case 4:
        ExecutarVerRelatorios(lista_alunos, lista_professores,
                              qnt_alunos_cadastrados,
                              qnt_professores_cadastrados);
        break;
      case 0:
        printf("\n\n/////   PROGRAMA ENCERRADO   //////\n\n");
        break;
      default:
        printf("\nDigite uma opção valida.\n");
        break;
    }
  } while (menu != 0);
}
