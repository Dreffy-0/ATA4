#ifndef CALCULADORA_H
#define CALCULADORA_H

#define TAMANHO_MAX_PILHA 100

typedef struct {
    float itens[TAMANHO_MAX_PILHA];
    int topo;
} Pilha;

void empilhar(Pilha *p, float valor);
float desempilhar(Pilha *p);
float avaliar_posfixada(char *expressao);
void exibir_operacoes();

#endif // CALCULADORA_H

