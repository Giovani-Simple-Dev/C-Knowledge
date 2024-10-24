#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int subtrai(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b){
    return a / b;
}

int main() {
        int num1, num2, opcao, resultado;

        printf("Digite o Primeiro Número: ");
        scanf("%d", &num1);

        printf("Digite o Segundo Número: ");
        scanf("%d", &num2);

        printf("Escolha uma opção: \n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Divisão\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            resultado = soma(num1,num2);
            printf("Resultado: %d\n", resultado);
        case 2:
            resultado = subtrai(num1,num2);
            printf("Resultado: %d\n", resultado);
        case 3:
            resultado = multiplicar(num1,num2);
            printf("Resultado: %d\n", resultado);
        case 4:
            resultado = dividir(num1, num2);
            if (num2 != 0){
            printf("Resultado: %d\n", resultado);
        default:
            printf("Opção Inválida\n");
            break;
            }
            return 0;
    }
}
