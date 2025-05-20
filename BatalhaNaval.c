#include <stdio.h>
 
int main() {
    
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[10][10];
    int habilidade_cone[5][5];
    int habilidade_cruz[5][5];
    int habilidade_octaedro[5][5];

    int navio_horizontal[3] = {3, 3, 3}; // navio horizontal
    int navio_vertical[3] = {3, 3, 3};   // navio vertical
    int navio_diagonal1[3] = {3, 3, 3};
    int navio_diagonal2[3] = {3, 3, 3};
    
    //definindo um valor para o 'tabuleiro'
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
            
        }
        
    }
    
    //colocando os navios
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[0][0 + i] = navio_horizontal[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[7 + i][9] = navio_vertical[i];
    }

    for (int i = 0; i < 3; i++)
    {
        tabuleiro[6 + i][4 + i] = navio_diagonal1[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[2 + i][4 - i] = navio_diagonal2[i];
    }

    //habilidades especiais
    //habilidade cone

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            habilidade_cone[i][j] = 5;
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = -i; j <= i; j++)
        {
            tabuleiro[0 + i][6 + j] = habilidade_cone[i][j];
        }
        
    }
    //cruz
    int base_i = 5; // posição central no tabuleiro (por exemplo)
    int base_j = 7;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            habilidade_cruz[i][j] = 5;
        }
        
    }
    
    for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5 ; j++){
                if (i == 2 || j == 2)
                {
                    tabuleiro[base_i + (i - 2)][base_j + (j - 2)] = habilidade_cruz[i][j];
                }
            } 
        }
    // Octaedro


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            habilidade_cone[i][j] = 9;
        }
        
    }

    for (int i = 0; i < 5; i++) {   //para as linhas
    int alcance = (i <= 2) ? i : 4 - i; //definindo um alcance para o octaedro, se i for 0, 1, 2 ele imprime o valor 9  se não ele faz 4 - i, por exemplo se for linha 3, ai vai fazer 4 - 3 = 1 e vai imprimir só um 9
    for (int j = 0; j < 5; j++) { // linha das colunas
        if (j >= 2 - alcance && j <= 2 + alcance) { // se J for 2, 3, 4 ou 5 vai fazer 2 - alcance (no caso 1, e depois não sei o que faz com o valor), e se J for menor ou = a 2 + o alcance ai imprime 9
            habilidade_octaedro[i][j] = 9;
        } else { // caso contrario imprime 0
            habilidade_octaedro[i][j] = 0;
        }
    }
}
    int baseO_i = 7;    //onde quero colocar o octaedro
    int baseO_j = 2;
    for (int i = 0; i < 5; i++) {//controla as linhas
    for (int j = 0; j < 5; j++) {//controla as colunas
        tabuleiro[baseO_i + (i - 2)][baseO_j + (j - 2)] = habilidade_octaedro[i][j];//imprimie o octaedro no terminal
    }
}
        

    // Cabeçalho com letras
printf("   ");
for (int i = 0; i < 10; i++) {
    printf("%c ", 'A' + i);
}
printf("\n");

// Tabuleiro com números alinhados
for (int i = 0; i < 10; i++) {
    printf("%2d ", i + 1);  // agora os números 1 a 10 ficam alinhados
    for (int j = 0; j < 10; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

    return 0;
}