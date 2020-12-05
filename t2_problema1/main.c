#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Autoria: Lucas Nathan Henrique da Silva
struct Candidato {
    char respostas[50];
    int matricula;
    int acertos;
} cand[10];


int comparador(const void*, const void*);
int comparador(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int qtd_candidatos;
    char abcde[5] = "abcde";
    char gabarito[51] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba'/0'";
    for(int i = 0; i < 10; i++){
        cand[i].acertos = 0;
    }
    printf("Quantos candidatos vao ser classificados? : ");
    scanf("%d", &qtd_candidatos);
    for(int i = 0; i < qtd_candidatos; i++){
        printf("Digite a matricula de 5 digitos do candidato numero %d: ",i+1);
        fflush(stdin);
        scanf("%d", &cand[i].matricula);
        if(cand[i].matricula <10000 || cand[i].matricula > 99999 ){
            printf("Tem que ser 5 digitos.\n");
            i--;
            continue;
        }
    }

    //Recebe os dados das notas
    for(int i = 0; i < qtd_candidatos; i++){
        printf("Digite as 50 respostas de 'A' a 'E' do candidato de matricula %d: ",cand[i].matricula);
        fflush(stdin);
        gets(cand[i].respostas);
        if(strlen(cand[i].respostas) != 50) {
            printf("Tem que ser 50 respostas, foram digitadas %d\n",strlen(cand[i].respostas));
            i--;
            break;
        } else {
            }
    }
    //Começa a classificar os candidatos
    printf("Classificacao: \n");
    for(int i = 0; i < qtd_candidatos; i++){
        for(int j = 0; j < 50; j++){
            if(cand[i].respostas[j] == gabarito[j]){
                cand[i].acertos++;
            }
        }
    }
    //Ordenador
    int ord_qtd_acertos[qtd_candidatos];
    for(int i = 0; i < qtd_candidatos; i++){
        ord_qtd_acertos[i] = cand[i].acertos;
    }
    int *ptr_ord_qtd_acertos;
    ptr_ord_qtd_acertos = ord_qtd_acertos;
    int pos[qtd_candidatos];
    qsort(ord_qtd_acertos, qtd_candidatos, sizeof(int), comparador);

    for(int i = 0; i < qtd_candidatos; i++){
        if(cand[i].acertos = *ptr_ord_qtd_acertos){
            pos[i] = cand[i].matricula;
            ptr_ord_qtd_acertos++;
        } else {
            continue;
        }
    }

    //Exibe resultados
    for(int i = qtd_candidatos-1; i >= 0; i--) {
        printf("%d |\t%d\n", pos[i], ord_qtd_acertos[i]);
    }

}
