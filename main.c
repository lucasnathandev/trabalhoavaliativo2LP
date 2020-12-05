#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
typedef struct Cliente {
    char nome[256];
    int cpf;
    }conta;

typedef struct Conta {
    int numero_da_conta;
    struct Cliente cliente;
    float saldo;
    };

int main()
{
    struct Conta conta;
    struct Conta *ptrConta = &conta;
    setlocale(LC_ALL, "");
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    scanf("%s", conta.cliente.nome);
    printf("Digite o cpf do cliente: ");
    fflush(stdin);
    scanf("%d", &conta.cliente.cpf);
    printf("Digite o numero da conta do cliente: ");
    fflush(stdin);
    scanf("%d", &ptrConta->numero_da_conta);
    ptrConta->saldo = 0;

    int opcao = 0;
    float valorSaque;
    float valorDeposito;
    do {
        system("cls");
        printf("Operações financeiras\n====================\n");
        printf("1 - Saque.\n2 - Depósito.\n3 - Exibir saldo.\n4 - Sair.\n");
        printf("Digite a opção desejada: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            printf("Tela de saque.\nDigite a quantidade a ser sacada usando virgula para separar os centavos dos reais.\nR$ ");
            fflush(stdin);
            scanf("%f", &valorSaque);
            if(ptrConta->saldo < valorSaque){
                printf("Sinto muito saldo insuficiente, seu saldo é de %9.2f, o valor desejado foi de %9.2f, faltam %9.2f para poder sacar esse valor.\n",ptrConta->saldo, valorSaque, valorSaque - ptrConta->saldo);
                system("pause");
                break;
            } else if(ptrConta->saldo < 1 || valorSaque < 1){
                printf("Tem que ter saldo na conta e o valor do saque tem que ser positivo.\n");
                system("pause");
                break;
                }   else{
                    ptrConta->saldo -= valorSaque;
                    printf("Espere o dinheiro sair pelo caixa.");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".\n");
                    printf("Retire seu dinheiro.\n");
                    system("pause");
                    break;
            }
        case 2:
            system("cls");
            printf("Tela de depósito.\nDigite a quantidade a ser depositada usando virgula para separar os centavos dos reais.\nR$ ");
            fflush(stdin);
            scanf("%f", &valorDeposito);
            ptrConta->saldo += valorDeposito;
            printf("Valor depositado R$%9.2f\n",valorDeposito);
            system("pause");
            break;
        case 3:
            system("cls");
            printf("Tela de saldo da sua conta.\nSaldo: R$%9.2f\n",ptrConta->saldo);
            system("pause");
            break;

        case 4:
            system("cls");
            puts("Obrigado pela preferência. :D");
            break;
        default:
            system("cls");
            printf("Opção inválida.");
            break;
        }

    } while(opcao != 4);

    return 0;
}
