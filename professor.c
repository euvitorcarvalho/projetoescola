//int main pra rodar e testar.
// definições de funções.
#include <stdio.h>
#include <string.h>
#include "professor.h"
#include "funcoes.h"
#include "validacao.h"


// CONTROLA O CADASTRO, ATUALIZAÇÃO E EXCLUSAO DE PROFESSORES
void CRUD_Professores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor){
    int menu;
    Menu_CRUD();
    printf("Escolha uma opção: ");
    scanf("%d",&menu);
    getchar();

    switch(menu){
        case 1: ExecutarCadastroProfessores(lista_professores, qnt_professores_cadastrados, matriculaProfessor);break;
        case 2: /*ExecutarAtualizarProfessor(parametros)*/; break;
        case 3: /*ExecutarExcluirProfessor(parametros)*/ ;break;
        case 0: return;
    }

}

// GERENCIA O CADASTRO DE PROFESSORES
void ExecutarCadastroProfessores(PROFESSOR lista_professores[], int *qnt_professores_cadastrados, int *matriculaProfessor){
    printf("\n///  CADASTRO DE PROFESSORES  ///\n\n");
    int continuar = 1;
    int sucesso;
    char op[10];

    do{
        if(*qnt_professores_cadastrados >= QNT_PROFESSORES){
            printf("\n/// Máximo de professores cadastrados atingido. Voltando... ///\n");
            break;
        }

        printf("/// Cadastrando Professor - %d. ///\n\n",*qnt_professores_cadastrados+1);

        sucesso = cadastrarProfessor(&lista_professores[*qnt_professores_cadastrados]);

        if(sucesso){
            (*matriculaProfessor)++;
            lista_professores[*qnt_professores_cadastrados].matricula = *matriculaProfessor;
            (*qnt_professores_cadastrados)++;
        }
        while(*qnt_professores_cadastrados < QNT_PROFESSORES){
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
}

//CADASTRA UM PROFESSOR
int cadastrarProfessor(PROFESSOR *professor){
    char nome[100];
    char sexo[10];
    char CPF[15];
    DATA dataNascimento;
    int invalido = 0;

    printf("digite seu nome: ");
    ler_str(nome,sizeof(nome));// recebe o nome.
    do{
         printf("\n----- Sexo -----\n");
        printf("F - Feminino\n");
        printf("M - Masculino\n");
        printf("O - Outro\n");
        printf("Informe seu sexo:\n");
        ler_str(sexo, sizeof(sexo)); //recebe o sexo
        invalido = validar_sexo(sexo);
        if(invalido){
            printf("\nSexo inválido, digite novamente.\n");
        }
    }while(invalido);

    do{
        printf("Digite seu cpf: ");
        ler_str(CPF,sizeof(CPF));// recebe cpf.
        invalido = validar_cpf(CPF);
        switch(invalido){
            case 0 : break;
            case 1 : printf("\n/// Erro 1 - Cpf digitado não contem 11 dígitos. ///\n\n"); break;
            case 2 : printf("\n/// Erro 2 - Digite apenas numeros, sem pontos ou traços. ///\n\n"); break;
            case 3 : printf("\n/// Erro 3 - Cpf digitado possui todos os caracteres iguais. ///\n\n"); break;
            case 4 : printf("\n/// Erro 4 - Erro no 1º dígito verificador. ///\n\n"); break;
            case 5 : printf("\n/// Erro 5 - Erro no 2º dígito verificador. ///\n\n"); break;
            default: printf("\n/// Erro desconhecido - falha na leitura. ///\n\n"); break;
        }
    }while(invalido);

    do{
        printf("Digite sua data de nascimento (ddmmaaaa):  ");
        lerData(&dataNascimento);// recebe data de nascimento.
        invalido = validar_data(dataNascimento);// função vazia
    }while(invalido);

    char salvar[10];
    do{
        printf("\nDeseja salvar o cadastro? (s/n): ");
        ler_str(salvar, sizeof(salvar));

        if(salvar[0] == 'S' || salvar[0] == 's'){
            //ATRIBUIÇÃO
            strcpy(professor->nome,nome);
            strcpy(professor->CPF,CPF);//  0    1    2
            professor->sexo = sexo[0];// |'M'|'\n'|'\0'|
            professor->dataNascimento = dataNascimento;

            printf("\n/// Cadastro concluido com sucesso! ///\n");
            return 1; // sucesso
        }
        else if( salvar[0] == 'N' || salvar[0] == 'n'){
            printf("\n/// Cadastro cancelado. Voltando... ///\n");
            return 0; // cadastro cancelado;
        }
        else{
            printf("\n/// Digite uma opção valida. ///\n");
        }
    }while(1);

}   

//LISTA OS PROFESSORES POR MATRICULA
void listarProfessoresMatricula(PROFESSOR lista[], int qnt){// função listar
    printf("\n\n///          LISTAR PROFESSORES         ///\n\n");

    for(int i = 0; i < qnt; i++){
        imprimirDadosProfessor(lista[i]);
    }
}

//EXIBE OS DADOS DO PROFESSOR
void imprimirDadosProfessor(PROFESSOR p){
     printf("\n--------Dados do Professor--------\n");

    printf("Nome: %s\n",p.nome);

    printf("Matricula: %06d\n",p.matricula);

    if (p.sexo == 'M')
        printf("Sexo: Masculino\n");
    else if(p.sexo == 'F')
        printf("Sexo: Feminino\n");
    else if(p.sexo == 'O')
        printf("Sexo: Outro\n");
    
    printf("Data de nascimento: %02d/%02d/%04d\n",
        p.dataNascimento.dia,
        p.dataNascimento.mes,
        p.dataNascimento.ano);

    printf("CPF: %s\n",p.CPF); //exibir cpf formatado em breve
}

//EXIBE OPÇÕES DE LISTAGEM DOS PROFESSORES
void RelatorioProfessores(PROFESSOR lista_professores[], int qnt_professores_cadastrados){

    int listagem_professores = -1;

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
                listarProfessoresMatricula(lista_professores, qnt_professores_cadastrados);
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
                break;

            default:
                printf("\n///  Erro - escolha uma opção valida  ///\n");
                break;
        }
    }while(listagem_professores != 0);
}

    //função atualizar

    // função excluir