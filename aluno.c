#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "validacao.h"
#include "funcoes.h"


// CONTROLA O CADASTRO, ATUALIZAÇÃO E EXCLUSAO DE ALUNOS
void CRUD_Alunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno){
    int menu;
    Menu_CRUD();
    printf("Escolha uma opcao: ");
    scanf("%d",&menu);
    getchar();

    switch(menu){
        case 1: ExecutarCadastroAlunos(lista_alunos, qnt_alunos_cadastrados, matriculaAluno); break;
        case 2: ExecutarAtualizarAluno(lista_alunos, *qnt_alunos_cadastrados); break;
        case 3: ExecutarExcluirAluno(lista_alunos, qnt_alunos_cadastrados); break;
        case 0: return;
    }
}

//GERENCIA O CADASTRO DE ALUNOS
void ExecutarCadastroAlunos(ALUNO lista_alunos[], int *qnt_alunos_cadastrados, int *matriculaAluno) {
    int continuar = 1;
    int sucesso;
    int indice = 0;
    char op[10];

    printf("\n///  CADASTRO DE ALUNOS  ///\n\n");
    do {
        if (*qnt_alunos_cadastrados >= QNT_ALUNOS) {
            printf("\n/// Maximo de alunos cadastrados atingido. Voltando... ///\n");
            break;
        }

        printf("\n/// Cadastrando aluno - %d. ///\n", *qnt_alunos_cadastrados + 1);

        for(int i = 0; i < QNT_ALUNOS; i++){
            if(lista_alunos[i].preenchido == 0){
                indice = i;
                break;
            }
        }

        sucesso = LerDadosAluno(&lista_alunos[indice]);

        if (sucesso) {
            printf("\n/// Cadastro Salvo! ///\n");
            (*matriculaAluno)++;
            lista_alunos[indice].matricula = *matriculaAluno;
            lista_alunos[indice].preenchido = 1;
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
                printf("\n///  Erro - Digite uma opcao valida.  ///\n");
            }
        }

    } while (continuar == 1);
}


//ATUALIZAR DADOS DO ALUNO
int ExecutarAtualizarAluno(ALUNO lista[], int qnt){
    int matricula;
    int sucesso;
    int indice_encontrado;
    int indice;

    if(qnt > 0){
        listarAlunos(lista, qnt);
        printf("\n\n///  ATUALIZAR CADASTRO  ///\n");

        printf("\nDigite a matricula do aluno: ");
        scanf(" %d",&matricula);
        getchar();

        indice_encontrado = buscar_matricula_aluno(matricula, lista, qnt);

        if(indice_encontrado != -1)
            indice = indice_encontrado;
        else{
            printf("\n/// Aluno nao encontrado. ///\n");
            return 0;
        }

        sucesso = LerDadosAluno(&lista[indice]);

        if(sucesso){ 
            printf("\n///  Dados atualizados com sucesso!  ///\n");
            return 1;
        }
        else return 0;
    }
    else {
        printf("\n\n/// Nao ha alunos cadastrados! ///\n\n");
        return 0;
    }   
}

int ExecutarExcluirAluno(ALUNO lista[], int *qnt_alunos_cadastrados){
    int matricula;
    printf("\n\n///  EXCLUIR ALUNO  ///\n\n");

    if(*qnt_alunos_cadastrados > 0)
        listarAlunos(lista, *qnt_alunos_cadastrados);
    else {
        printf("\n/// Nao ha alunos cadastrados. ///\n");
        return 0;
    }

    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&matricula);
    getchar();

    int indice_encontrado = buscar_matricula_aluno(matricula, lista, *qnt_alunos_cadastrados);

    int indice;

    if(indice_encontrado != -1)
        indice = indice_encontrado;
    else{
        printf("\n/// Aluno nao encontrado! ///\n");
        return 0;
    }

    char op[10];
    do{
        printf("\nDeseja excluir %s? (s/n) ", lista[indice].nome);
        ler_str(op,sizeof(op));

        if(op[0] == 'S' || op[0] == 's' ){
            lista[indice].preenchido = 0;
            printf("\n/// ALUNO EXCLUIDO ///\n");
            ordenar_preenchidos_alunos(lista, *qnt_alunos_cadastrados);
            (*qnt_alunos_cadastrados)--;

            break;
        }
        if(op[0] == 'N' || op[0] == 'n'){
            printf("\n/// Voltando... ///\n");
            return 0;
        }
    }while(1);
    
    return 1;
}   


//LER E VALIDA OS DADOS DO ALUNO
int LerDadosAluno(ALUNO *pAluno){ // recebe o endereço do aluno para alterar

    // cópia das variaveis do aluno, para leiura e validação antes de atribuir ao aluno
    char nome[100];
    char sexo[10];
    char cpf[15];
    DATA data;

    int invalido; // verificador de validade

    //LER NOME
    printf("\nDigite seu nome: ");
    ler_str(nome, sizeof(nome));

    // LER SEXO
    do{
        printf("\n-----Sexo-------\n");
        printf(" M - Masculino\n");
        printf(" F - Feminino\n");
        printf(" O - Outro\n");

        printf("\nSelecione seu sexo: ");
        ler_str(sexo, sizeof(sexo));  //ler a opção selecionada + \n + \0 , uma forma de evitar problemas de buffer de teclado
        invalido = validar_sexo(sexo); 

        switch(invalido){
            case 1 : printf("\nSelecione uma opção valida."); break;
            default : break;
        }

    }while(invalido);

    //LER CPF
    do{
        printf("\nDigite seu CPF:");
        ler_str(cpf, sizeof(cpf));
        invalido = validar_cpf(cpf);

        switch(invalido){
            case 0 : break;
            case 1 : printf("\n/// Erro 1 - Cpf digitado nao contem 11 digitos. ///\n\n"); break;
            case 2 : printf("\n/// Erro 2 - Digite apenas numeros, sem pontos ou tracos. ///\n\n"); break;
            case 3 : printf("\n/// Erro 3 - Cpf digitado possui todos os caracteres iguais. ///\n\n"); break;
            case 4 : printf("\n/// Erro 4 - Erro no 1º digito verificador. ///\n\n"); break;
            case 5 : printf("\n/// Erro 5 - Erro no 2º digito verificador. ///\n\n"); break;
            default: printf("\n/// Erro desconhecido - falha na leitura. ///\n\n"); break;
        }

    }while (invalido);

    // LER DATA DE NASCIMENTO
    do{
        printf("\nDigite sua data de nascimento (ddmmaaaa):");
        lerData(&data);

        invalido = validar_data(data); // validação ainda em desenvolvimento. Verificar se dia está entre 1 e 31, se mês está entre 1 e 12. e caso seja mes fevereiro, verificar se dia está entre 1 e 28 ou 29 caso seja ano bissexto.

        switch (invalido){
            case 1 : printf("\nDigite uma data valida!"); break;
            default : break;
        }
    }while(invalido); // repete a leitura enquanto for invalido

    //ATRIBUIÇÃO - se os dados forem validos, atribuir ao aluno
    char salvar[10];
    do{
        printf("\nSalvar cadastro? (s/n): ");
        ler_str(salvar, sizeof(salvar));

        if(salvar[0] == 's' || salvar[0] == 'S'){
            strcpy(pAluno->nome, nome);
            strcpy(pAluno->CPF, cpf);//                                                   0    1    2    
            pAluno->sexo = sexo[0]; // passa primeira letra lida da string de sexo. ex: | M | \n | \0 |
            pAluno->dataNascimento = data;    
            return 1; //sucesso
        }
        else if(salvar[0] == 'n' || salvar[0] == 'N'){
            printf("\n/// Cadastro cancelado. voltando... ///\n");
            return 0;
        }
        else   
            printf("\nDigite uma opção valida.\n");
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

//LISTA ALUNOS
void listarAlunos(ALUNO lista[], int qnt){
    if(qnt > 0){
        printf("\n\n///          LISTAR ALUNOS         ///\n\n");

        for(int i = 0; i < qnt; i++){
            if(lista[i].preenchido == 1)
                imprimirDadosAluno(lista[i]);
        }
    }
    else{
        printf("\n///  Nao ha alunos cadastrados!  ///\n");
        return;
    }
}

// EMPURRA OS NÃO PREENCHIDOS PARA FRENTE
void ordenar_preenchidos_alunos(ALUNO lista[], int qnt){
    ALUNO temp;

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

//PROCURA A MATRICULA DO ALUNO NA LISTA
int buscar_matricula_aluno(int matricula, ALUNO lista[], int qnt){
    
    for(int i = 0; i < qnt; i++){
        
        if(lista[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

//ORDENA VETOR DE ALUNOS POR MATRICULA
void ordenar_por_matricula_alunos(ALUNO lista[], int qnt){
    ALUNO temp;

    for(int i = 0; i < qnt - 1; i++){
        for(int j = 0; j < qnt - 1 - i; j++){
            if(lista[j].matricula > lista[j+1].matricula){
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
        }   }
    }
}

//ORDENA VETOR DE ALUNOS POR NOME
void ordenar_por_nome_alunos(ALUNO lista[], int qnt){
   ALUNO temp;

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

//ORDENA VETOR DE ALUNOS POR SEXO
void listar_por_sexo_alunos(ALUNO lista[], int qnt){
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
                imprimirDadosAluno(lista[i]);
        }
    }
    else{
        printf("\n///  Nao ha alunos cadastrados!  ///\n");
        return;
    }
}

//ORDENA VETOR DE ALUNOS POR DATA
void ordenar_por_data_alunos(ALUNO lista[], int qnt){
   ALUNO temp;

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


//EXIBE OPÇÕES DE LISTAR ALUNOS
void RelatorioAlunos(ALUNO lista_alunos[], int qnt_alunos_cadastrados){

    int op = -1;
    printf("\n\n///           LISTAR ALUNOS         ///\n\n");

    MenuListasFiltros();
    int ordenado = 0;

    ordenar_preenchidos_alunos(lista_alunos, qnt_alunos_cadastrados);
    do{
        printf("\nEscolha uma opcao: ");
        scanf("%d",&op);
        getchar();


        switch (op)
        {
            case 1:
                ordenar_por_matricula_alunos(lista_alunos, qnt_alunos_cadastrados);
                ordenado = 1;
                break;

            case 2:
                ordenar_por_nome_alunos(lista_alunos, qnt_alunos_cadastrados);
                ordenado = 1;
                break;

            case 3:
                ordenar_por_data_alunos(lista_alunos, qnt_alunos_cadastrados);
                ordenado = 1;
                break;

            case 4:{
                listar_por_sexo_alunos(lista_alunos, qnt_alunos_cadastrados);
                return;
            }
            case 0:
                printf("\n///  VOLTAR  ///\n");
                return;

            default:
                printf("\n///  Erro - escolha uma opcao valida  ///\n");
                break;
        }
    }while(ordenado == 0);

    listarAlunos(lista_alunos, qnt_alunos_cadastrados);
}