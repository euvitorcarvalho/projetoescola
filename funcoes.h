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

//MENUS
void MenuInicio();
void MenuListas();
void MenuListasFiltros();
void Menu_CRUD();

//FUNÇOES
void ExecutarVerRelatorios(ALUNO *lista_alunos, PROFESSOR *lista_professores, int qnt_alunos_cadastrados, int qnt_professores_cadastrados);

void buscar_nome_professores(char nome[], PROFESSOR *lista_professores, int qnt_professores_cadastrados);

void buscar_nome_alunos(char nome[], ALUNO *lista_alunos, int qnt_alunos_cadastrados);

void RelatorioPessoas(PROFESSOR *lista_professores, int qnt_professores_cadastrados, ALUNO *lista_alunos, int qnt_alunos_cadastrados); 

void RelatorioAniversariantes(); // Em desenvolvimento

//LEITURA
void ler_str(char str[], int tamanho);

void lerData(DATA *pData);

DATA DiaMesAno(int num);

#endif