#include <stdio.h>

int main(int option, float a, float b){
    
    printf("Painel de Opções: \n");
    printf("0) Sair\n");
    printf("1) Somar\n");
    printf("2) Subtrair\n");
    printf("3) Multiplicar\n");
    printf("4) Dividir\n");
    printf("Option: ");
    scanf("%d", &option);
    
    
    switch( option ) 
    {
        case 0:
        system("cls || clear");
        printf("Você escolheu sair");
        break;
        
        case 1:
        system("cls || clear");
        printf("Digite o Primeiro Valor: ");
        scanf("%d", &a);
        printf("Digite o Segundo Valor: ");
        scanf("%d", &b);
        printf("O Resultado é: %d\n", a + b);
        return 0;
        
        case 2:
        system("cls || clear");
        printf("Digite o Primeiro Valor: ");
        scanf("%d", &a);
        printf("Digite o Segundo Valor: ");
        scanf("%d", &b);
        printf("O resultado é: %d\n", a - b);
        return 0;
        
        case 3:
        system("cls || clear");
        printf("Digite o Primeiro Valor: ");
        scanf("%d", &a);
        printf("Digite o Segundo Valor: ");
        scanf("%d", &b);
        printf("O Resultado é: %d\n", a * b);
        return 0;
        
        case 4:
        system("cls || clear");
        printf("Digite o Primeiro Valor: ");
        scanf("%f", &a);
        printf("Digite o Segundo Valor: ");
        scanf("%f", &b);
        printf("O Resultado é: %f\n", a / b);
        return 0;
    }
}
