#include <stdio.h>

// armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

//  calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return populacao / area;
}

// calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

//  exibir os dados de uma carta
void exibir_carta(Carta c) {
    printf("Cidade: %s (%s)\n", c.nome_cidade, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
    printf("\n");
}

int main() {
    // Cadastro das cartas (pré-definidas)
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 700.0, 20};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.3, 360.0, 15};

    // Cálculo dos indicadores
    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);

    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    // Exibindo as cartas
    printf("===== CARTA 1 =====\n");
    exibir_carta(carta1);

    printf("===== CARTA 2 =====\n");
    exibir_carta(carta2);

    // Comparação de atributo escolhido

    printf("===== COMPARAÇÃO DE CARTAS (Atributo: População) =====\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
