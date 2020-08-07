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
/* AQUI VAI AS FUNCOES DE UTILIDADES DO SISTEMA */

void limpar_buffer_de_entrada() {
    char c; while ((c = fgetc (stdin)) != EOF && c != '\n');
}
char pedir_tecla() {
    char ch=getchar();
    limpar_buffer_de_entrada();
    return ch;
}
int pedir_inteiro() {
    int valor;
    scanf("%d",&valor);
    limpar_buffer_de_entrada();
    return valor;
}

void limpar_tela() { system("clear");}

/*   AQUI COMEÇA REALMENTE A LOGICA DO JOGO */

typedef struct {
    char *nome;
    int saude;
    int sorte;
    int dano;
    int magia;
} Raca;

Raca racas[]={
    //nome       saude      sorte       dano        magia       
    {"Elfo"     ,50         ,110        ,40          ,130   },
    {"Nordico"  ,100        ,60         ,120         ,40    },
    {"Orc"      ,150        ,50         ,110         ,20    }
};

char personagem_nome[200];
Raca personagem_raca;

void menu_criacao_personagem() {
    limpar_tela();
    printf("Bem vindo ao meu mundo!\n");
    sleep(1); 
    printf("Para começar digite um nome para o seu personagem:");
    scanf("%s",personagem_nome);
    printf("-------RAÇAS----\n");
    int numero_de_racas=sizeof(racas)/sizeof(Raca);
    for (int i = 0; i < numero_de_racas; i++){
        printf("%d) %s \n",i,racas[i].nome);
    }
    printf("Escolha a raça: ");

    int raca_escolhida=-1;
    while (!(raca_escolhida>=0 && raca_escolhida<numero_de_racas)){
        raca_escolhida=pedir_inteiro();
    }
    personagem_raca=racas[raca_escolhida];
    limpar_tela();
}

void menu_informacoes() {
    limpar_tela();
    printf("----------INFORMACOES--------\n");
    printf("Nome do personagem: %s \n",personagem_nome);
    printf("Raça: %s \n",personagem_raca.nome);
    printf("Saude: %d \n",personagem_raca.saude);
    printf("Sorte: %d \n",personagem_raca.sorte);
    printf("Dano: %d \n",personagem_raca.dano);
    printf("Magia: %d \n",personagem_raca.magia);
    printf("-----------------------------\n");
}

int main() {
    setlocale(LC_ALL, "");
    menu_criacao_personagem();

    char tecla_pressionada;
    while (1) {
        printf("digite 'i' para as informações do personagem, 'x' para sair.");
        tecla_pressionada=pedir_tecla();
        if(tecla_pressionada=='x') break;
        if(tecla_pressionada=='i') {
            printar_informacoes();
        } 
    }
    
  
    return 0;
}