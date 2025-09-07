#include <stdio.h>
#include <locale.h>
int decimal_binario(int numero){
    //Conta quantos dígitos o número binário terá após a conversão
    int contador = 0, registro = numero;
    while(numero != 0){
        numero /= 2;
        contador++;
    }

    //Salva o número binário em um array
    int binario[contador-1];
    numero = registro;
    for(int i=contador-1; i>=0; i--){
        binario[i] = numero % 2;
        numero /= 2;
    }

    //Converte de array para inteiro para poder retornar
    int base = 1, resultado = 0;
    for(int i=contador-1; i>=0; i--){
        resultado += binario[i]*base;
        base *= 10;
    }

    return resultado;
}

int binario_decimal(int numero){
    //Conta quantos dígitos o binário tem antes da conversão
    int contador = 0, registro = numero;
    do{
        //Verifica se todos os dígitos do binário são 0 ou 1
        if(numero%10 != 0 && numero%10 != 1) return 2;
        numero /= 10;
        contador++;
    }while(numero != 0);
    
    //Passa cada caractere do número em binário para um índice do array
    int binario[contador-1];
    numero = registro;
    for(int i=contador-1; i>=0; i--){
        binario[i] = numero % 10;
        numero /= 10;
    }

    //Converte o binário para decimal
    int base = 1, resultado = 0;
    for(int i=contador-1; i>=0; i--){
        resultado += binario[i]*base;
        base *= 2;
    }

    return resultado;
    
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, numero;
    printf("Conversor binário decimal: \n");
    printf("\n1 - Binário para decimal");
    printf("\n2 - Decimal para binário");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("\nDigite o número em binário para conversão: ");
        scanf("%d", &numero);
        if(binario_decimal(numero) == 2) {
            printf("\nO número digitado não é um número binário");
        } else {
            printf("\nO número binário %d em decimal é %d.", numero, binario_decimal(numero));
        }
    } else if(opcao == 2){
        printf("Digite o número em decimal para conversão: ");
        scanf("%d", &numero);
        printf("\nO número decimal %d em binário é %d.", numero, decimal_binario(numero));
    } else {
        printf("\nOpçaõ inválida, finalizando programa.");
    }

    return 0;
}