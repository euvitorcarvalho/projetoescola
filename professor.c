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
        case 2: ExecutarAtualizarProfessor(lista_professores, *qnt_professores_cadastrados); break;
        case 3: ExecutarExcluirProfessor(lista_professores, qnt_professores_cadastrados); break;
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

        sucesso = LerDadosProfessor(&lista_professores[*qnt_professores_cadastrados]);

        if(sucesso){
            printf("\n/// Cadastro concluido com sucesso! ///\n");
            (*matriculaProfessor)++;
            lista_professores[*qnt_professores_cadastrados].matricula = *matriculaProfessor;
            (*qnt_professores_cadastrados)++;
        }
        if(*qnt_professores_cadastrados < QNT_PROFESSORES){
            do{
                printf("\nDeseja cadastrar mais um professor? (s/n): ");
                ler_str(op, sizeof(op));
                
                int opcao = validar_opcao(op);
                
                switch(opcao){
                    case 1: continuar = 1; break;
                    case 2: continuar = 0; break;
                    default: continuar = -1; printf("\n///  Erro - Digite uma opção valida.  ///\n"); break;
                }
            }while(continuar == -1);
        }
    }while(continuar == 1);
}

//ATUALIZAR DADOS DO PROFESSOR
void ExecutarAtualizarProfessor(PROFESSOR lista[], int qnt){
    int matricula;
    int sucesso;
    int indice_encontrado;
    int indice;

    if(qnt > 0){
        listarProfessores(lista, qnt);
        printf("\n\n///  ATUALIZAR CADASTRO  ///\n");

        printf("\nDigite a matricula do professor: ");
        scanf(" %d",&matricula);
        getchar();

        indice_encontrado = buscar_matricula_professor(matricula, lista, qnt);

        if(indice_encontrado != -1)
            indice = indice_encontrado;
        else{
            printf("\n/// Professor nao encontrado. ///\n");
            return;
        }

        sucesso = LerDadosProfessor(&lista[indice]);

        if(sucesso){ 
            printf("\n///  Dados atualizados com sucesso!  ///\n");
            return;
        }
        else return;
    }
    else {
        printf("\n\n/// Nao ha professores cadastrados! ///\n\n");
        return;
    }   
}

//EXCLUI PROFESSOR
void ExecutarExcluirProfessor(PROFESSOR lista[], int *qnt_professores_cadastrados){
    int matricula;
    printf("\n\n///  EXCLUIR PROFESSOR  ///\n\n");

    if(*qnt_professores_cadastrados > 0)
        listarProfessores(lista, *qnt_professores_cadastrados);
    else {
        printf("\n/// Nao ha professores cadastrados. ///\n");
        return;
    }

    printf("\nDigite a matricula do professor: ");
    scanf("%d",&matricula);
    getchar();

    int indice_encontrado = buscar_matricula_professor(matricula, lista, *qnt_professores_cadastrados);

    int indice;

    if(indice_encontrado != -1)
        indice = indice_encontrado;
    else{
        printf("\n/// Professor nao encontrado! ///\n");
        return;
    }

    char op[10];
    do{
        printf("\nDeseja excluir %s? (s/n) ", lista[indice].nome);
        ler_str(op, sizeof(op));

        int opcao = validar_opcao(op);

        switch (opcao){
            case 1:
                printf("\n/// PROFESSOR EXCLUIDO ///\n");

                lista[indice].preenchido = 0;

                ordenar_preenchidos_professores(lista, *qnt_professores_cadastrados);

                (*qnt_professores_cadastrados)--;
                return;

            case 2:
                printf("\n/// Voltando... ///\n");
                return;

            default:
                printf("\n///  Erro - Digite uma opção valida.  ///\n"); 
                break;
        }
    }while(1);
    
} 

//CADASTRA UM PROFESSOR
int LerDadosProfessor(PROFESSOR *professor){
    char nome[100];
    char sexo[10];
    char CPF[15];
    DATA dataNascimento;
    int invalido = 0;

    printf("Digite seu nome: ");
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

        int opcao = validar_opcao(salvar);

        switch(opcao){
            case 1: 
                //ATRIBUIÇÃO
                strcpy(professor->nome,nome);
                strcpy(professor->CPF,CPF);//  0    1    2
                professor->sexo = sexo[0];// |'M'|'\n'|'\0'|
                professor->dataNascimento = dataNascimento;
                return 1; // sucesso

            case 2:
                printf("\n/// Cadastro cancelado. ///\n");
                return 0; // cadastro cancelado; 

            default:
                printf("\n///  Erro - Digite uma opção valida.  ///\n"); 
                break;
        }
    }while(1);
}   

//LISTA OS PROFESSORES POR MATRICULA
void listarProfessores(PROFESSOR lista[], int qnt){// função listar
    printf("\n\n///          LISTAR PROFESSORES         ///\n\n");

    for(int i = 0; i < qnt; i++){
        imprimirDadosProfessor(lista[i]);
    }
}

// EMPURRA OS NÃO PREENCHIDOS PARA FRENTE
void ordenar_preenchidos_professores(PROFESSOR lista[], int qnt){
    PROFESSOR temp;

    for(int i = 0; i < qnt - 1; i++){
        for( int j = 0; j < qnt - 1 - i; j++){
            if(lista[j].preenchido < lista[j+1].preenchido){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}

//PROCURA A MATRICULA DO PROFESSOR NA LISTA
int buscar_matricula_professor(int matricula, PROFESSOR lista[], int qnt){
    
    for(int i = 0; i < qnt; i++){
        
        if(lista[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

//ORDENA VETOR DE PROFESSORES POR MATRICULA
void ordenar_por_matricula_professores(PROFESSOR lista[], int qnt){
    PROFESSOR temp;

    for(int i = 0; i < qnt - 1; i++){
        for(int j = 0; j < qnt - 1 - i; j++){
            if(lista[j].matricula > lista[j+1].matricula){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
        }   }
    }
}


//ORDENA VETOR DE PROFESSORES POR NOME
void ordenar_por_nome_professores(PROFESSOR lista[], int qnt){
   PROFESSOR temp;

   for(int i = 0; i < qnt - 1; i++){
    for(int j = 0; j < qnt - 1 - i; j++){
        if(strcmp(lista[j].nome, lista[j+1].nome) > 0){
            temp = lista[j];
            lista[j] = lista[j+1];
            lista[j+1] = temp;
        }
    }
   }
}

//ORDENA VETOR DE PROFESSORES POR SEXO
void listar_por_sexo_professores(PROFESSOR lista[], int qnt){
    if(qnt > 0){
        char sexo;
        int invalido = 0;
        printf("\n ----- Filtrar por sexo -----\n");

        do{
            printf("\n----- Sexo -------\n");
            printf(" M - Masculino\n");
            printf(" F - Feminino\n");
            printf(" O - Outro\n");

            printf("\nSelecione o sexo: ");
            scanf(" %c",&sexo);
            getchar();

            invalido = validar_sexo(&sexo);

        }while(invalido);

        for(int i = 0; i < qnt; i++){
            if(lista[i].preenchido == 1 && lista[i].sexo == sexo)
                imprimirDadosProfessor(lista[i]);
        }
    }
    else{
        printf("\n///  Nao ha alunos cadastrados!  ///\n");
        return;
    }
}

//ORDENA VETOR DE PROFESSORES POR DATA
void ordenar_por_data_professores(PROFESSOR lista[], int qnt){
   PROFESSOR temp;

   for(int i = 0; i < qnt - 1; i++){
        for(int j = 0; j < qnt - 1 - i; j++){
            if(lista[j].dataNascimento.ano > lista[j+1].dataNascimento.ano){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
            else if(lista[j].dataNascimento.ano == lista[j+1].dataNascimento.ano){
                if(lista[j].dataNascimento.mes > lista[j+1].dataNascimento.mes){
                    temp = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = temp;
                }
                else if(lista[j].dataNascimento.mes == lista[j+1].dataNascimento.mes){
                    if(lista[j].dataNascimento.dia > lista[j+1].dataNascimento.dia){
                        temp = lista[j];
                        lista[j] = lista[j+1];
                        lista[j+1] = temp;
                    }
                }
            }
        }
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

    int op = -1;
    int ordenado = 0;

    do{
        printf("\n\n///   LISTAR PROFESSORES   ///\n\n");
        MenuListasFiltros();

        printf("\nEscolha uma opção: ");
        scanf("%d",&op);
        getchar();

        switch (op)
        {
            case 1:
                //Ordenar por matricula
                ordenar_por_matricula_professores(lista_professores, qnt_professores_cadastrados);
                ordenado = 1;
                break;

            case 2:
                //Ordenar por nome
                ordenar_por_nome_professores(lista_professores, qnt_professores_cadastrados);
                ordenado = 1;
                break;

            case 3:
                //Ordenar por Data de nascimento
                ordenar_por_data_professores(lista_professores, qnt_professores_cadastrados);
                ordenado = 1;
                break;

            case 4:
                //filtrar por sexo
                listar_por_sexo_professores(lista_professores, qnt_professores_cadastrados);
                return;

            case 0:
                printf("\n///  VOLTAR  ///\n");
                return;

            default:
                printf("\n///  Erro - escolha uma opção valida  ///\n");
                break;
        }
    }while(ordenado == 0);

    listarProfessores(lista_professores, qnt_professores_cadastrados);

}

    //função atualizar

    // função excluir