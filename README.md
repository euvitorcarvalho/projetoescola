# Projeto Escola
 
Programa em C pra controlar o funcionamento de uma escola: cadastro de alunos, professores, disciplinas e um monte de relatório em cima disso. Atividade extra de INF029 (Laboratório de Programação), IFBA, com o professor Renato Novais.
 
Tudo roda no terminal e os dados ficam só na memória, então fechou o programa, perdeu tudo.
 
## Quem fez o quê
 
Dividimos por módulo pra não ficar um mexendo no arquivo do outro e dando conflito toda hora:
 
- **Guilherme** - `aluno.c` / `aluno.h`
- **Luiza** - `professor.c` / `professor.h`
- **Vitor** - `disciplina.c` / `disciplina.h` e `validacao.c` / `validacao.h` <br>
O `main.c` e o `funcoes.c` (menus, leitura de dados e os relatórios que misturam aluno com professor) acabaram sendo mexidos por todo mundo.
 
## Compilando e rodando
 
```
gcc -o escola main.c aluno.c professor.c disciplina.c funcoes.c validacao.c
./escola
```
 
No Windows o executável sai como `escola.exe`. Se quiser ver os avisos do compilador é só jogar um `-Wall` no meio.
 
## Os arquivos
 
```
main.c            monta os vetores de aluno e professor e roda o loop do menu
aluno.c/.h        struct ALUNO, cadastrar/atualizar/excluir, ordenações e filtros
professor.c/.h    a mesma coisa do aluno, só que pra professor
disciplina.c/.h   ainda praticamente vazio, é o que falta fazer
funcoes.c/.h      menus, struct DATA, leitura de string/data e relatórios gerais
validacao.c/.h    validação de CPF, sexo, data e confirmação de S/N
```
 
## Desenho do programa
 
```mermaid
flowchart LR
    MAIN["MENU PRINCIPAL<br/>(main.c)"]
 
    MAIN --> A_CRUD["[aluno.c]<br/>Cadastrar, Atualizar, Excluir"]
    MAIN --> P_CRUD["[professor.c]<br/>Cadastrar, Atualizar, Excluir"]
    MAIN --> D_CRUD["[disciplina.c]<br/>Cadastrar, Atualizar, Excluir<br/>Inserir/Remover aluno"]
    MAIN --> REL["Menu: RELATÓRIOS<br/>(funcoes.c)"]
 
    REL --> A_FIL["Filtros de Aluno<br/>(aluno.c)"]
    REL --> P_FIL["Filtros de Professor<br/>(professor.c)"]
    REL --> D_FIL["Filtros de Disciplina<br/>(disciplina.c)"]
    REL --> G_FIL["Relatórios gerais<br/>(funcoes.c)"]
 
    A_FIL --> A1["Listar todos"]
    A_FIL --> A2["Ordenar por matrícula, nome ou data"]
    A_FIL --> A3["Filtrar por sexo"]
    A_FIL --> A4["Alunos em menos de 3 disciplinas"]
 
    P_FIL --> P1["Listar todos"]
    P_FIL --> P2["Ordenar por matrícula, nome ou data"]
    P_FIL --> P3["Filtrar por sexo"]
 
    D_FIL --> D1["Listar disciplinas (com e sem alunos)"]
    D_FIL --> D2["Disciplinas que passam de 40 vagas"]
 
    G_FIL --> G1["Busca por nome (mín. 3 letras)"]
    G_FIL --> G2["Aniversariantes do mês"]
 
    VAL["[validacao.c]<br/>CPF, data, sexo"]
    VAL -.-> A_CRUD
    VAL -.-> P_CRUD
    VAL -.-> D_CRUD
```

## O que já funciona
 
- **Cadastro de Alunos** (Matrícula, Nome, Sexo, Data Nascimento, CPF) ✅
- **Cadastro de Professores** (Matrícula, Nome, Sexo, Data Nascimento, CPF) ✅
- **Cadastro de Disciplinas** (Nome, Código, Semestre, Professor) 🔴
  - Inserir/Excluir aluno de uma disciplina 🔴
- **Relatórios**
  - Listar Alunos ✅
  - Listar Professores ✅
  - Listar Disciplinas (sem os alunos) 🔴
  - Listar uma disciplina (com os alunos matriculados) 🔴
  - Listar Alunos por sexo ✅
  - Listar Alunos ordenados por Nome ✅
  - Listar Alunos ordenados por data de nascimento ✅
  - Listar Professores por sexo ✅
  - Listar Professores ordenados por Nome ✅
  - Listar Professores ordenados por data de nascimento ✅
  - Aniversariantes do mês 🔴
  - Busca de pessoa por pedaço do nome (mínimo 3 letras) 🟡
  - Alunos matriculados em menos de 3 disciplinas 🔴
  - Disciplinas que extrapolam 40 vagas 🔴
- **Validações**
  - CPF (tamanho, só número, dígitos repetidos e os dois dígitos verificadores) ✅
  - Sexo (aceita minúsculo e converte pra M/F/O) ✅
  - Confirmação S/N ✅
  - Data de nascimento 
  
## O que falta e o que a gente já sabe que tá errado
 
O grosso do que falta é disciplina. Ela é a única entidade que ainda não existe de verdade no código, e como vários relatórios dependem dela (listar disciplina, aluno com menos de 3 disciplinas, turma passando de 40 vagas), tudo isso caiu junto.
 
Fora isso:
 
- `validar_data()` existe mas só tem um `return 0` dentro, ou seja, aceita qualquer data. Falta checar quantidade de dias por mês, ano bissexto e um intervalo de ano que faça sentido.
- A busca por nome usa `strstr`, que diferencia maiúscula de minúscula. Procurar por "vitor" não acha "Vitor Carvalho". Já funciona, mas ainda não do jeito certo.
- `RelatorioAniversariantes()` está declarada e chamada, só que o corpo dela está vazio.
- O campo `contDisciplinas` já existe dentro do `ALUNO` esperando a parte de disciplina ficar pronta.
