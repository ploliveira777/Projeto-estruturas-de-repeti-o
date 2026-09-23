#include <stdio.h>

#define TEMP_MIN -50.0
#define TEMP_MAX 100.0
#define FIM_MONITORAMENTO -999.0

int main(void) {
    double limite;
    double temperatura;
    double soma = 0.0;
    double maior = 0.0;
    double menor = 0.0;
    int quantidade = 0;
    int acimaDoLimite = 0;
    int consecutivas = 0;
    int primeiroValor = 1;

    /* Leitura e validação do limite de temperatura. */
    do {
        printf("Digite o limite de temperatura (%.0f a %.0f °C): ", TEMP_MIN, TEMP_MAX);

        if (scanf("%lf", &limite) != 1) {
            printf("Entrada invalida. Digite um valor numerico.\n");

            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                /* Limpa o restante da entrada invalida. */
            }

            limite = TEMP_MIN - 1;
            continue;
        }

        if (limite < TEMP_MIN || limite > TEMP_MAX) {
            printf("Limite invalido. Informe um valor entre %.0f e %.0f °C.\n",
                   TEMP_MIN, TEMP_MAX);
        }
    } while (limite < TEMP_MIN || limite > TEMP_MAX);

    printf("\nMonitoramento iniciado.\n");
    printf("Digite %g para encerrar manualmente.\n\n", FIM_MONITORAMENTO);

    /* O monitoramento continua até haver 3 temperaturas consecutivas
       acima do limite ou até o encerramento manual com -999. */
    while (1) {
        printf("Digite a temperatura (%.0f a %.0f °C): ", TEMP_MIN, TEMP_MAX);

        if (scanf("%lf", &temperatura) != 1) {
            printf("Entrada invalida. Digite um valor numerico.\n");

            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
                /* Limpa o restante da entrada invalida. */
            }
            continue;
        }

        if (temperatura == FIM_MONITORAMENTO) {
            printf("\nMonitoramento encerrado manualmente.\n");
            break;
        }

        if (temperatura < TEMP_MIN || temperatura > TEMP_MAX) {
            printf("Temperatura invalida. Informe um valor entre %.0f e %.0f °C.\n\n",
                   TEMP_MIN, TEMP_MAX);
            continue;
        }

        /* Atualiza os dados estatisticos das leituras validas. */
        soma += temperatura;
        quantidade++;

        if (primeiroValor) {
            maior = temperatura;
            menor = temperatura;
            primeiroValor = 0;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }

            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        /* Controla a quantidade de leituras consecutivas acima do limite. */
        if (temperatura > limite) {
            acimaDoLimite++;
            consecutivas++;
            printf("ALERTA: temperatura acima do limite!\n");

            if (consecutivas == 3) {
                printf("Tres temperaturas consecutivas acima do limite.\n");
                printf("Encerrando o monitoramento automaticamente.\n");
                break;
            }
        } else {
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }

        printf("Leituras validas: %d | Consecutivas acima do limite: %d\n\n",
               quantidade, consecutivas);
    }

    /* Relatorio final somente com as leituras validas realizadas. */
    if (quantidade > 0) {
        double media = soma / quantidade;
        double percentual = ((double)acimaDoLimite / quantidade) * 100.0;

        printf("\n===== RELATORIO FINAL =====\n");
        printf("Quantidade de leituras: %d\n", quantidade);
        printf("Media das temperaturas: %.2f °C\n", media);
        printf("Maior temperatura: %.2f °C\n", maior);
        printf("Menor temperatura: %.2f °C\n", menor);
        printf("Temperaturas acima do limite: %d\n", acimaDoLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    } else {
        printf("\nNenhuma leitura valida foi registrada.\n");
    }

    return 0;
}
