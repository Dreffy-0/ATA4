#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void empilhar(Pilha *p, float valor) {
    if (p->topo == TAMANHO_MAX_PILHA - 1) {
        printf("Estouro da pilha\n");
        exit(1);
    }
    p->itens[++p->topo] = valor;
}

float desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("Substitui��o da pilha\n");
        exit(1);
    }
    return p->itens[p->topo--];
}

float avaliar_posfixada(char *expressao) {
    Pilha p;
    p.topo = -1;

    char *token = strtok(expressao, " ");
    while (token != NULL) {
        if (isdigit(*token)) {
            empilhar(&p, atof(token));
        } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
                   strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
                   strcmp(token, "^") == 0 || strcmp(token, "sen") == 0 ||
                   strcmp(token, "cos") == 0 || strcmp(token, "tg") == 0 ||
                   strcmp(token, "log") == 0 || strcmp(token, "raiz") == 0) {
            float operando2 = desempilhar(&p);
            float operando1;
            float resultado;

            if (strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 ||
                strcmp(token, "tg") == 0 || strcmp(token, "log") == 0 ||
                strcmp(token, "raiz") == 0) {
                operando1 = 0; 
            } else {
                operando1 = desempilhar(&p);
            }

            switch (*token) {
                case '+':
                    resultado = operando1 + operando2;
                    break;
                case '-':
                    resultado = operando1 - operando2;
                    break;
                case '*':
                    resultado = operando1 * operando2;
                    break;
                case '/':
                    resultado = operando1 / operando2;
                    break;
                case '^':
                    resultado = pow(operando1, operando2);
                    break;
                case 's': // sen
                    resultado = sin(operando2);
                    break;
                case 'c': // cos
                    resultado = cos(operando2);
                    break;
                case 't': // tg
                    resultado = tan(operando2);
                    break;
                case 'l': // log
                    resultado = log10(operando2);
                    break;
                case 'r': // raiz
                    resultado = sqrt(operando2);
                    break;
                default:
                    printf("Expressao invalida\n");
                    exit(1);
            }
            empilhar(&p, resultado);
        } else {
            printf("Token invalido: %s\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    return desempilhar(&p);
}

void exibir_operacoes() {
    printf("Operacoes disponiveis:\n");
    printf("+ : Soma\n");
    printf("- : Subtracao\n");
    printf("* : Multiplicacao\n");
    printf("/ : Divisao\n");
    printf("^ : Potenciacao\n");
    printf("sen : Seno\n");
    printf("cos : Cosseno\n");
    printf("tg : Tangente\n");
    printf("log : Logaritmo de base 10\n");
    printf("raiz : Raiz quadrada\n");
}

