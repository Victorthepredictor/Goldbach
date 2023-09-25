// Implemente algoritmo para imprimir a decomposição um número inteiro maior do que 2 (fornecido pelo usuário) como a soma de dois números primos. 

#include <stdlib.h>
#include <stdio.h>

// Função para verificar se um número é primo
int ePrimo(int n) {
    if (n <= 1) return 0; // 0 e 1 não são primos
    if (n <= 3) return 1; // 2 e 3 são primos
    if (n % 2 == 0 || n % 3 == 0) return 0; // Múltiplos de 2 e 3 não são primos

    // Verifica números primos potenciais até a raiz quadrada de n
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }

    return 1;
}

int main() {
    int numero;

    do {
        printf("Digite um numero inteiro maior que 2: ");
        scanf("%d", &numero);
    } while (numero <= 2);

    printf("Decomposicao do numero %d em dois numeros primos:\n", numero);

    // Encontra a decomposição em dois números primos
    for (int i = 2; i <= numero / 2; i++) {
        if (ePrimo(i) && ePrimo(numero - i)) {
            printf("%d + %d\n", i, numero - i);
            break; // Encontrou a decomposição, sai do loop
        }
    }

    return 0;
}
