#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "validacao.h"
#include "funcoes.h"


// CONTROLA O CADASTRO, ATUALIZAÇÃO E EXCLUSAO DE ALUNOS
void CRUD_Alunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno){
    int menu;
    Menu_CRUD();
    printf("Escolha uma opção: ");
    scanf("%d",&menu);
    getchar();

    switch(menu){
        case 1: ExecutarCadastroAlunos(lista_alunos, qnt_alunos_cadastrados, matriculaAluno); break;
        case 2: ExecutarAtualizarAluno(lista_alunos, *qnt_alunos_cadastrados); break;
        case 3: /*ExecutarExcluirAluno()*/; break;
        case 0: return;
    }

}

//GERENCIA O CADASTRO DE ALUNOS
void ExecutarCadastroAlunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno) {
    int continuar = 1;
    int sucesso;
    char op[10];

    printf("\n///  CADASTRO DE ALUNOS  ///\n\n");
    do {
        if (*qnt_alunos_cadastrados >= QNT_ALUNOS) {
            printf("\n/// Máximo de alunos cadastrados atingido. Voltando... ///\n");
            break;
        }

        printf("/// Cadastrando aluno - %d. ///\n\n", *qnt_alunos_cadastrados + 1);
        
        // Passamos a posição atual do vetor de structs
        sucesso = cadastrarAluno(&lista_alunos[*qnt_alunos_cadastrados]);

        if (sucesso) {
            (*matriculaAluno)++;
            lista_alunos[*qnt_alunos_cadastrados].matricula = *matriculaAluno;
            (*qnt_alunos_cadastrados)++;
        }
        
        while (*qnt_alunos_cadastrados < QNT_ALUNOS) {
            printf("\nDeseja cadastrar mais um aluno? (s/n): ");
            ler_str(op, sizeof(op));

            if (op[0] == 'S' || op[0] == 's') {
                continuar = 1;
                break;
            }
            else if (op[0] == 'N' || op[0] == 'n') {
                continuar = 0;
                break;
            }
            else {
                printf("\n///  Erro - Digite uma opção valida.  ///\n");
            }
        }

    } while (continuar == 1);
}

//ATUALIZAR DADOS DO ALUNO
int ExecutarAtualizarAluno(ALUNO lista[], int qnt){
    int matricula;
    int sucesso;
    int indice;

    if(qnt > 0){
        listarAlunosMatricula(lista, qnt);
        printf("\n\n///  ATUALIZAR CADASTRO  ///\n\n");

        printf("Digite a matricula do aluno: ");
        scanf(" %d",&matricula);
        getchar();

        indice = matricula - 1;
        sucesso = cadastrarAluno(&lista[indice]);

        if(sucesso){ 
            printf("\n\n///  Dados atualizados com sucesso!  ///\n\n");
            return 1;
        }
        else return 0;
    }
    else {
        printf("\n\n/// Não há alunos cadastrados! ///\n\n");
        return 0;
    }   
}

//CADASTRA O ALUNO
int cadastrarAluno(ALUNO *pAluno){ // recebe o endereço do aluno para alterar

    // cópia das variaveis do aluno, para leiura e validação antes de atribuir ao aluno
    char nome[100];
    char sexo[10];
    char cpf[15];
    TipoData data;

    int invalido; // verificador de validade

    //LER NOME
    printf("Digite seu nome: ");
    ler_str(nome, sizeof(nome)); // nome precisa de validação?

    // LER SEXO
    do{
        printf("\n-----Sexo-------\n");
        printf(" M - Masculino\n");
        printf(" F - Feminino\n");
        printf(" O - Outro\n");

        printf("\nSelecione seu sexo: ");
        ler_str(sexo, sizeof(sexo));  //ler a opção selecionada + \n + \0 , uma forma de evitar problemas de buffer de teclado
        invalido = validar_sexo(sexo); // validação ainda em desenvolvimento. verificar se uma das opções foi selecionada, case insensitive

        switch(invalido){
            case 1 : printf("Selecione uma opção valida."); break;
            default : break;
        }

    }while(invalido);

    //LER CPF
    do{
        printf("Digite seu CPF:");
        ler_str(cpf, sizeof(cpf));
        invalido = validar_cpf(cpf);

        switch(invalido){
            case 0 : break;
            case 1 : printf("\n/// Erro 1 - Cpf digitado não contem 11 dígitos. ///\n\n"); break;
            case 2 : printf("\n/// Erro 2 - Digite apenas numeros, sem pontos ou traços. ///\n\n"); break;
            case 3 : printf("\n/// Erro 3 - Cpf digitado possui todos os caracteres iguais. ///\n\n"); break;
            case 4 : printf("\n/// Erro 4 - Erro no 1º dígito verificador. ///\n\n"); break;
            case 5 : printf("\n/// Erro 5 - Erro no 2º dígito verificador. ///\n\n"); break;
            default: printf("\n/// Erro desconhecido - falha na leitura. ///\n\n"); break;
        }

    }while (invalido);

    // LER DATA DE NASCIMENTO
    do{
        printf("Digite sua data de nascimento (ddmmaaaa):");
        lerData(&data);

        invalido = validar_data(data); // validação ainda em desenvolvimento. Verificar se dia está entre 1 e 31, se mês está entre 1 e 12. e caso seja mes fevereiro, verificar se dia está entre 1 e 28 ou 29 caso seja ano bissexto.

        switch (invalido){
            case 1 : printf("Digite uma data valida."); break;
            default : break;
        }
    }while(invalido); // repete a leitura enquanto for invalido

    char salvar[10];
    do{
        printf("Salvar cadastro? (s/n): ");
        ler_str(salvar, sizeof(salvar));

        if(salvar[0] == 's' || salvar[0] == 'S'){
            
            //ATRIBUIÇÃO - se os dados forem validos, atribuir ao aluno
    
            strcpy(pAluno->nome, nome);
            strcpy(pAluno->CPF, cpf);//                                                   0    1    2    
            pAluno->sexo = sexo[0]; // passa primeira letra lida da string de sexo. ex: | M | \n | \0 |
            pAluno->dataNascimento = data;
            printf("\n/// Cadastro Salvo! ///\n\n");
    
            return 1; //sucesso
        }
        else if(salvar[0] == 'n' || salvar[0] == 'N'){
            printf("\n/// Cadastro cancelado. voltando... ///\n");
            return 0;
        }
        else   
            printf("Digite uma opção valida.\n");
    }while(1);
}

//EXIBE DADOS DO ALUNO
void imprimirDadosAluno(ALUNO a){
    printf("\n--------Dados do Aluno--------\n");

    printf("Nome: %s\n",a.nome);

    printf("Matricula: %06d\n",a.matricula);

    if (a.sexo == 'M')
        printf("Sexo: Masculino\n");
    else if(a.sexo == 'F')
        printf("Sexo: Feminino\n");
    else if(a.sexo == 'O')
        printf("Sexo: Outro\n");
    
    printf("Data de nascimento: %02d/%02d/%04d\n",
        a.dataNascimento.dia,
        a.dataNascimento.mes,
        a.dataNascimento.ano);

    printf("CPF: %s\n",a.CPF); //exibir cpf formatado em breve

}

//LISTA ALUNOS POR MATRICULA
void listarAlunosMatricula(ALUNO lista[], int qnt){
    if(qnt > 0){
        printf("\n\n///          LISTAR ALUNOS         ///\n\n");

        for(int i = 0; i < qnt; i++){
            imprimirDadosAluno(lista[i]);
        }
    }
    else{
        printf("\n///  Não há alunos cadastrados   ///\n");
    }
}

//EXIBE OPÇÕES DE LISTAR ALUNOS
void RelatorioAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados){

    int listagem_alunos = -1;

    do{
        printf("\n\n///           LISTAR ALUNOS         ///\n\n");


        MenuListasFiltros();

        printf("\nEscolha uma opção: ");
        scanf("%d",&listagem_alunos);
        getchar();

        switch (listagem_alunos)
        {
            case 1:
                //Ordenar por matricula (Ordem padrão)
                listarAlunosMatricula(lista_alunos, qnt_alunos_cadastrados);
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
}