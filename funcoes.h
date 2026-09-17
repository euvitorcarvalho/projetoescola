//DEFINIÇÃO DAS FUNÇÕES DE LEIURA
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct ALUNO ALUNO;
typedef struct PROFESSOR PROFESSOR;

typedef struct DATA
{
   int dia;
   int mes;
   int ano;
} DATA; // representa uma data com dia, mês e ano


void MenuInicio();
void MenuListas();
void MenuListasFiltros();
void Menu_CRUD();

void ExecutarVerRelatorios(
    ALUNO *lista_alunos, 
    PROFESSOR *lista_professores,
//  DISCIPLINA lista_disciplinas[],
    int qnt_alunos_cadastrados, 
    int qnt_professores_cadastrados
//  int qnt_disciplinas_cadastradas
);

void RelatorioPessoas(); // Em desenvolvimento

void RelatorioAniversariantes(); // Em desenvolvimento

void ler_str(char str[], int tamanho);

void lerData(DATA *pData);

DATA DiaMesAno(int num);

#endif