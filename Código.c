#include <stdio.h>
#include <string.h>
#include <stdlib.h> //printf("%d ", rand() % 100); // aleatorio //   getch(); // limpar buffer //srand(time(NULL));
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <unistd.h>

void carregamento(){
    printf("\n");
    int i = 0, j = 0, k;
    float por = 0;

    while (j != 1) {
        while (i != 11) {
            for (k = 0; k < i; k++) {
                printf("\U0001F604");}
            for (int k = i; k < 11; k++) {
                printf("\r"); 
            }
            por = i * 100.0 / 11;
            printf("[ %.0f%% ]", por);
            printf(" ");
            fflush(stdout);
            sleep(0.2); 
            i++;}j++;}
} // BARRA DE CARREGAMENTO

void menu(char *GuardaPalavra){

    srand(time(NULL));

    int dificuldade, palavraleatoria = rand() % 3, contadorparapalavra = 0;
    char frases[100], GuardaLinhas[3][50], *linha, *token;

    printf("==================================\n== \033[1;31mBEM VINDO AO DESEMBARALHANDO\033[0m ==\n==================================\n\n");
    printf("[0] - \033[38;2;120;255;120mFÁCIL\033[0m\t[\U0001F601]\n[1] - \033[38;2;0;0;139mMÉDIO\033[0m\t[\U0001F604]\n[2] - \033[38;2;128;0;128mDIFÍCIL\033[0m\t[\U0001F62C]\n\n--> ");
    scanf("%d", &dificuldade);
    FILE *arq;                                                                                  //DECLARA O ARQUIVO
    arq = fopen("../arq.txt", "r");                                                             //ABRE O ARQUIVO

    if (arq){

        while (!feof(arq)){
            for(int i = 0; i < 3; i++){
                linha = fgets(frases, sizeof(frases), arq);                                     // LE AS LINHAS DE UM ARQUIVO TXT COM SOMENTE 3 LINHAS
                strcpy(GuardaLinhas[i], linha);                                                 // ARMAZENA CADA LINHA EM UM ARRAY DE UMA MATRIX
            }
        }
    } 
    else {printf("Não foi possível ler o arquivo!");}

    token = strtok(GuardaLinhas[dificuldade], " ");                                                       // DECIDE A LINHA

    while(token != NULL){
        (contadorparapalavra == palavraleatoria) ? strcpy(GuardaPalavra, token) : 0 ;
        contadorparapalavra ++;
        token = strtok(NULL, " "); 
    }

    fclose(arq);
} // CONSIGO UMA PALAVRA ALEATORIA TIRANDO ELA DO ARQUIVO TXT
void embaralhar(char *Aux){
    int num;
    num = strlen(Aux);

    srand(time(NULL));
    for(int i = num-1; i>0; i--){

        int j = rand() % i + 1;

        char temp = Aux[i];
            Aux[i] = Aux[j];
            Aux[j] = temp;        
    }

} // EMBARALHA A PALAVRA
void jogando(char *GuardaPalavra, char *Aux){
    system("cls");
    char tentativa[50];
    printf("Decifre Está Palavra = [\033[38;2;255;255;0m%s\033[0m] \n\n\033[38;2;0;0;255m--> \033[0m", Aux);

    getchar();
    fgets(tentativa, sizeof(tentativa), stdin);
    tentativa[strcspn(tentativa, "\n")] = '\0';
    while(1){

    if (strcmp(tentativa, GuardaPalavra) == 0) {

        printf("\nParabéns, acertou!\n");
        break;
    } 
    else {
        printf("\nVamos Ver Se Acertou O Local De Alguma Letra\n\n--> ");
        for(int i = 0; i < strlen(tentativa); i++){

            if(tentativa[i] == GuardaPalavra[i]){
                printf(" \033[38;2;255;0;0m%c\033[0m", tentativa[i]);
            }
            else{printf(" %c", tentativa[i]);}
        }
        printf("\n\nErrou \U0001F62D! Vamos De Novo\U0001F645!\n\n-->");
        fgets(tentativa, sizeof(tentativa), stdin);
        tentativa[strcspn(tentativa, "\n")] = '\0'; 
    }
}
}

int main(){

system("cls");

UINT CPAGE_UTF8 = 65001;
UINT CPAGE_DEFAULT = GetConsoleOutputCP();
SetConsoleOutputCP(CPAGE_UTF8);

char GuardaPalavra[50], Aux[50];

menu(GuardaPalavra);

strcpy(Aux, GuardaPalavra);

carregamento();

embaralhar(Aux);



jogando(GuardaPalavra, Aux);

SetConsoleOutputCP(CPAGE_DEFAULT);

}
