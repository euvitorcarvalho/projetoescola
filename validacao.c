#include "validacao.h"

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int validar_cpf(char cpf[]) {
  int tamanho = 0;

  for (int i = 0; cpf[i] != '\0'; i++) tamanho++;
  if (tamanho != 11) return 1;  // Erro 1: Tamanho incorreto

  for (int i = 0; cpf[i] != '\0'; i++) {
    if (cpf[i] < '0' || cpf[i] > '9') return 2;  // Erro 2: Caracteres inválidos
  }

  int todosIguais = TRUE;
  for (int i = 1; i < 11; i++) {
    if (cpf[i] != cpf[0]) {
      todosIguais = FALSE;
      break;
    }
  }
  if (todosIguais) return 3;  // Erro 3: Números repetidos

  int digitoVerificador1 = cpf[9] - '0';
  int digitoVerificador2 = cpf[10] - '0';

  int somaDigitoVerificador1 = 0;
  for (int i = 0, j = 10; i < 9; i++, j--) {
    int digito = cpf[i] - '0';
    somaDigitoVerificador1 += digito * j;
  }
  int restoDigitoVerificador1 = somaDigitoVerificador1 * 10 % 11;

  if (restoDigitoVerificador1 == 10) restoDigitoVerificador1 = 0;
  if (digitoVerificador1 != restoDigitoVerificador1)
    return 4;  // Erro 4: Falha no 1º dígito

  int somaDigitoVerificador2 = 0;
  for (int i = 0, j = 11; i < 10; i++, j--) {
    int digito = cpf[i] - '0';
    somaDigitoVerificador2 += digito * j;
  }
  int restoDigitoVerificador2 = somaDigitoVerificador2 * 10 % 11;

  if (restoDigitoVerificador2 == 10) restoDigitoVerificador2 = 0;
  if (digitoVerificador2 != restoDigitoVerificador2)
    return 5;  // Erro 5: Falha no 2º dígito

  return 0;  // Sucesso
}