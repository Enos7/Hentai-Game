#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
/*
    para compilar esse exemplo voce precisa baixar o compilador gcc
    com o comando "sudo apt install build-essential"

    com o compilador instalado basta rodar "gcc eliezer.c"
    entao o programa compilado vai aparecer na pasta com o nome "a.out"
    e para rodar basta executar 
    ./a.out.
    para compilar e rodar o jogo em um comando apenas, use:
    "gcc eliezer.c && ./a.out"

*/

char pedir_tecla() {
    // ler o caracter do usuario, o primeiro character
    char ch=getchar();
    // limpar o buffer de entrada
    char c; while ((c = fgetc (stdin)) != EOF && c != '\n');
    return ch;
}

char player_nome[200];
int player_saude=100;

void limpar_tela() { system("clear");}

void printar_informacoes() {
    limpar_tela();
    printf("----------INFORMACOES--------\n");
    printf("Nome do player: %s \n",player_nome);
    printf("Saude: %i \n",player_saude);
    printf("-----------------------------\n");
}

int main() {
    limpar_tela();
    printf("Bem vindo ao meu mundo!\n");
    sleep(1); 
    printf("Para começar digite um nome para o seu player:");
    scanf("%s",player_nome);
    setlocale(LC_ALL, "");
    char tecla_pressionada;
    while (1) {
        printf("digite 'i' para suas mostrar seus dados, 'x' para sair.");
        tecla_pressionada=pedir_tecla();
        if(tecla_pressionada=='x') break;
        if(tecla_pressionada=='i') {
            printar_informacoes();
        } 
    }
    
  
    return 0;
}