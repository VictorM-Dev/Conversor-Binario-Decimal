#include <stdio.h>
#include <locale.h>
int decimal_binario(int numero){
    //Conta quantos d�gitos o n�mero bin�rio ter� ap�s a convers�o
    int contador = 0, registro = numero;
    while(numero != 0){
        numero /= 2;
        contador++;
    }

    //Salva o n�mero bin�rio em um array
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
    //Conta quantos d�gitos o bin�rio tem antes da convers�o
    int contador = 0, registro = numero;
    do{
        //Verifica se todos os d�gitos do bin�rio s�o 0 ou 1
        if(numero%10 != 0 && numero%10 != 1) return 2;
        numero /= 10;
        contador++;
    }while(numero != 0);
    
    //Passa cada caractere do n�mero em bin�rio para um �ndice do array
    int binario[contador-1];
    numero = registro;
    for(int i=contador-1; i>=0; i--){
        binario[i] = numero % 10;
        numero /= 10;
    }

    //Converte o bin�rio para decimal
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
    printf("Conversor bin�rio decimal: \n");
    printf("\n1 - Bin�rio para decimal");
    printf("\n2 - Decimal para bin�rio");
    printf("\n\nEscolha uma op��o: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("\nDigite o n�mero em bin�rio para convers�o: ");
        scanf("%d", &numero);
        if(binario_decimal(numero) == 2) {
            printf("\nO n�mero digitado n�o � um n�mero bin�rio");
        } else {
            printf("\nO n�mero bin�rio %d em decimal � %d.", numero, binario_decimal(numero));
        }
    } else if(opcao == 2){
        printf("Digite o n�mero em decimal para convers�o: ");
        scanf("%d", &numero);
        printf("\nO n�mero decimal %d em bin�rio � %d.", numero, decimal_binario(numero));
    } else {
        printf("\nOp�a� inv�lida, finalizando programa.");
    }

    return 0;
}