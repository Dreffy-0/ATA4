#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "calculadora.h"

int main() {
    exibir_operacoes();
    
    char expressao[100];
    printf("\nDigite a expressao em notacao pos-fixada: ");
    fgets(expressao, sizeof(expressao), stdin);
    
    expressao[strcspn(expressao, "\n")] = '\0';

    float resultado = avaliar_posfixada(expressao);
    printf("Resultado: %.2f\n", resultado);

    printf("\nPressione Enter para sair...");
    getchar();    

    return 0;
}
