#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Converte qualquer moeda para d�lar
float paraDolar(int moeda, float valor) {
    switch (moeda) {
        case 1: return valor / 4.95f;  // Real -> D�lar
        case 2: return valor;         // D�lar -> D�lar
        case 3: return valor / 1.35f;  // D�lar Canadense -> D�lar
        case 4: return valor / 0.92f;  // Euro -> D�lar
        case 5: return valor / 150.25f; // Iene -> D�lar
        default: return -1; // Erro
    }
}

// Converte d�lar para a moeda final
float deDolarPara(int moeda, float valorDolar) {
    switch (moeda) {
        case 1: return valorDolar * 4.95f;  // D�lar -> Real
        case 2: return valorDolar;         // D�lar -> D�lar
        case 3: return valorDolar * 1.35f;  // D�lar -> D�lar Canadense
        case 4: return valorDolar * 0.92f;  // D�lar -> Euro
        case 5: return valorDolar * 150.25f; // D�lar -> Iene
        default: return -1; // Erro
    }
}

int main() {
    int moedaOriginal, moedaDestino;
    float valorIni, valorDolar, valorFinal;

    while (1) {
        // Exibir menu
        printf("\n |===============================================|\n");
        printf(" | Bem vindo ao programa de conversao de Moedas! |\n");
        printf(" |===============================================|\n");
        printf("     Data de atualizacao de cambio: 05/02/2024\n\n");

        printf("   Moedas disponiveis\n");
        printf("------------------------\n");
        printf("| 1: Real              |\n");
        printf("| 2: Dolar Americano   |\n");
        printf("| 3: Dolar Canadense   |\n");
        printf("| 4: Euro              |\n");
        printf("| 5: Iene              |\n");
        printf("| 6: Sair do programa  |\n");
        printf("------------------------\n\n");

        printf("Por favor, selecione a moeda inicial (1-6): ");
        if (scanf("%d", &moedaOriginal) != 1) {
            printf("Entrada inv�lida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (moedaOriginal == 6) {
            printf("\nSaindo do programa...\n");
            break;
        }

        printf("Informe o valor que deseja converter (ex: 300.00): ");
        if (scanf("%f", &valorIni) != 1) {
            printf("Entrada inv�lida! Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }

        valorDolar = paraDolar(moedaOriginal, valorIni);

        if (valorDolar == -1) {
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        printf("Selecione a moeda para conversao (1-5): ");
        if (scanf("%d", &moedaDestino) != 1) {
            printf("Entrada inv�lida! Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }

        valorFinal = deDolarPara(moedaDestino, valorDolar);

        if (valorFinal == -1) {
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        printf("\nValor Convertido: %.2f\n", valorFinal);
    }

    return 0;
}
