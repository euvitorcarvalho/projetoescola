#include "funcoes.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "aluno.h"
#include "disciplina.h"
#include "professor.h"

// MENU INICIAL
void MenuInicio() {
  printf("\n///           PROJETO ESCOLA           ///\n");

  printf("__________________ MENU __________________\n\n");
  printf("| 1 - Alunos                             |\n");
  printf("| 2 - Professores                        |\n");
  printf("| 3 - Disciplinas                        |\n");
  printf("| 4 - Ver Relatorios                     |\n");
  printf("| 0 - Sair                               |\n");
  printf("|________________________________________|\n");
}
// MENU DO CRUD (CADASTRAR, ATUALIZAR, EXCLUIR)
void Menu_CRUD() {
  printf("__________________ MENU __________________\n\n");
  printf("| 1 - Cadastrar                          |\n");
  printf("| 2 - Atualizar Dados                    |\n");
  printf("| 3 - Excluir                            |\n");
  printf("| 0 - Voltar                             |\n");
  printf("|________________________________________|\n");
}

// MENU DAS LISTAS
void MenuListas() {
  printf("\n///           VER RELATORIOS           ///\n");

  printf("__________________ LISTAS ________________\n\n");
  printf("| 1 - Listar Alunos                      |\n");
  printf("| 2 - Listar Professores                 |\n");
  printf("| 3 - Listar Disciplinas                 |\n");
  printf("| 4 - Consultar uma disciplina           ||\n");
  printf("| 5 - Alunos em menos de 3 disciplinas   |\n");
  printf("| 6 - Lista de pessoas (professor/aluno) |\n");
  printf("| 7 - Aniversariantes do mes             |\n");
  printf("| 8 - Matricular aluno em disciplina     |\n");
  printf("| 9 - Excluir aluno de disciplina        |\n");
  printf("| 10 - Disciplinas com mais de 40 alunos |\n");
  printf("| 0 - Voltar                             |\n");
  printf("|________________________________________|\n");
}

// MENU DE ORDENAÇÃO DAS LISTAGENS
void MenuListasFiltros() {
  printf("\n________________ FILTROS _______________\n\n");
  printf("| 1 - Ordenar por matricula              |\n");
  printf("| 2 - Ordenar por nome                   |\n");
  printf("| 3 - Ordenar por data de nascimento     |\n");
  printf("| 4 - Filtrar por sexo                   |\n");
  printf("| 0 - Voltar                             |\n");
  printf("|________________________________________|\n");
}

void ler_str(char str[], int tamanho) {  // recebe uma string e o tamanho dela

  // ler a string com o fgets
  fgets(str, tamanho, stdin);

  // remove o \n que o fgets considera ao apertar enter
  str[strcspn(str, "\n")] = '\0';
}

void lerData(DATA* pData) {  // recebe o endereço da variavel do tipo Data
  int num;

  // lê um numero no formato ddmmaaaa
  scanf("%d", &num);
  getchar();  // limpar buffer 😭

  // chama função para separar em dia, mes e ano
  *pData = DiaMesAno(num);
}

DATA DiaMesAno(int num) {  // recebe um numero inteiro no formato ddmmaaaa e
                           // retorna uma data separada em dia, mes e ano
  DATA data;

  data.dia = num / 1000000;
  data.mes = (num % 1000000) / 10000;
  data.ano = num % 10000;

  return data;
}

// VER RELATORIOS
void ExecutarVerRelatorios(ALUNO* lista_alunos, PROFESSOR* lista_professores,
                           DISCIPLINA* lista_disciplinas,
                           int qnt_alunos_cadastrados,
                           int qnt_professores_cadastrados,
                           int qnt_disciplinas_cadastradas) {
  int listagem = -1;

  do {
    MenuListas();

    printf("\nEscolha uma opcao: ");
    scanf("%d", &listagem);
    getchar();

    switch (listagem) {
      case 1:
        RelatorioAlunos(lista_alunos, qnt_alunos_cadastrados);
        break;
      case 2:
        RelatorioProfessores(lista_professores, qnt_professores_cadastrados);
        break;
      case 3:
        RelatorioDisciplinas(lista_disciplinas, qnt_disciplinas_cadastradas);
        break;
      case 4:
        RelatorioUmaDisciplina(lista_disciplinas, lista_alunos,
                               qnt_disciplinas_cadastradas,
                               qnt_alunos_cadastrados);
        break;

      case 5:
        RelatorioAlunosMenosTresDisciplinas(lista_alunos,
                                            qnt_alunos_cadastrados);
        break;

      case 6:
        RelatorioPessoas(lista_professores, qnt_professores_cadastrados,
                         lista_alunos, qnt_alunos_cadastrados);
        break;

      case 7:
         RelatorioAniversariantes(lista_alunos,lista_professores,qnt_alunos_cadastrados, qnt_professores_cadastrados);
        break;

      case 8:
        MatricularAlunoDisciplina(lista_disciplinas, lista_alunos,
                                  qnt_disciplinas_cadastradas,
                                  qnt_alunos_cadastrados);
        break;

      case 9:
        ExcluirAlunoDisciplina(lista_disciplinas, lista_alunos,
                               qnt_disciplinas_cadastradas,
                               qnt_alunos_cadastrados);
        break;

      case 10:
        RelatorioDisciplinasMaisDe40Vagas(lista_disciplinas, lista_professores,
                                          qnt_disciplinas_cadastradas,
                                          qnt_professores_cadastrados);
        break;

      case 0:
        printf("\n///               VOLTAR              ///\n");
        break;
      default:
        printf("\n///  Erro - escolha uma opcao valida  ///\n");
        break;
    }

  } while (listagem != 0);
}

void buscar_nome_alunos(char nome[], ALUNO* lista, int qnt) {
  int contador = 0;
  for (int i = 0; i < qnt; i++) {
    if (strstr(lista[i].nome, nome) != NULL) {
      imprimirDadosAluno(lista[i]);
      contador++;
    }
  }
  if (contador == 0) {
    printf("\n///   Nenhum aluno encontrado   ///\n");
    return;
  }
}

void buscar_nome_professores(char nome[], PROFESSOR* lista, int qnt) {
  int contador = 0;
  for (int i = 0; i < qnt; i++) {
    if (strstr(lista[i].nome, nome) != NULL) {
      imprimirDadosProfessor(lista[i]);
      contador++;
    }
  }
  if (contador == 0) {
    printf("\n/// Nenhum professor encontrado ///\n");
    return;
  }
}

void RelatorioPessoas(PROFESSOR* lista_professores,
                      int qnt_professores_cadastrados, ALUNO* lista_alunos,
                      int qnt_alunos_cadastrados) {
  char busca[100];
  printf("\n///      LISTAR PESSOAS       ///\n");
  do {
    printf("\nBUSCAR\n");

    printf("\nDigite o nome da pessoa: ");
    ler_str(busca, sizeof(busca));

    if (strlen(busca) < 3) printf("\nDigite pelo menos tres letras.\n");

  } while (strlen(busca) < 3);

  printf("\n///      RESULTADO DA BUSCA     ///\n");

  printf("\n-------------PROFESSORES-----------\n");
  buscar_nome_professores(busca, lista_professores,
                          qnt_professores_cadastrados);

  printf("\n---------------ALUNOS--------------\n");
  buscar_nome_alunos(busca, lista_alunos, qnt_alunos_cadastrados);

  printf("\n///////////////////////////////////\n");
}

void RelatorioAniversariantes(ALUNO *lista_alunos, PROFESSOR *lista_professores, int qnt_alunos_cadastrados, int qnt_professores_cadastrados){
   printf("\n///   LISTAR ANIVERSARIANTES   ///\n\n");
    time_t agora;
    struct tm *data;
    time(&agora);
    data = localtime(&agora); // pelo que eu vi isso define a data atual

    int mesAtual = data->tm_mon + 1; // janeiro = 0 ent pra ser mês 1 precisa adicionar 1
   
    int encontrou = 0;

    for(int i = 0; i < qnt_alunos_cadastrados; i++){
        if(lista_alunos[i].dataNascimento.mes == mesAtual){
            printf("%s\n",lista_alunos[i].nome);
            encontrou = 1;
        }
    }
      for(int i = 0; i < qnt_professores_cadastrados; i++){
        if(lista_professores[i].dataNascimento.mes == mesAtual){
            printf("%s\n",lista_professores[i].nome);
            encontrou = 1;
        }
    }
    if(encontrou == 0){
        printf("nenhum aniversariante este mês.\n");
    }
}