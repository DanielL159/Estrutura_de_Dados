
#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};


float calcularDistancia(struct Ponto p1, struct Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

float calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    if (p2.x - p1.x != 0) {
        return (p2.y - p1.y) / (p2.x - p1.x);
    } else {
      
        return INFINITY;
    }
}

int main() {
    struct Ponto ponto1 = {1.0, 2.0};
    struct Ponto ponto2 = {4.0, 6.0};

    printf("Coordenadas do Ponto 1: (%.2f, %.2f)\n", ponto1.x, ponto1.y);
    printf("Coordenadas do Ponto 2: (%.2f, %.2f)\n", ponto2.x, ponto2.y);

    float distancia = calcularDistancia(ponto1, ponto2);
    printf("Distância entre os pontos: %.2f\n", distancia);

    float inclinacao = calcularInclinacao(ponto1, ponto2);
    if (isfinite(inclinacao)) {
        printf("Inclinação da reta entre os pontos: %.2f\n", inclinacao);
    } else {
        printf("Reta entre os pontos é vertical (inclinacao infinita).\n");
    }

    return 0;
}
