
struct coordenada
{
    int CI, CF, LI, LF;
};
void Fundo_Design(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
    for (int i = LI; i < LF; i++)
    {
        for (int j = CI; j < CF; j++)
        {
            textbackground(CorF);
            gotoxy(j, i);
            printf(" ");
        }
    }
    // Cores
    textcolor(CorT);
    textbackground(CorF);

    // Cantos
    gotoxy(CI, LI);
    printf("%c", 201);
    gotoxy(CI, LF);
    printf("%c", 200);
    gotoxy(CF, LI);
    printf("%c", 187);
    gotoxy(CF, LF);
    printf("%c", 188);

    // Contorno
    for (int i = CI + 1; i < CF; i++)
    {
        gotoxy(i, LI);
        printf("%c", 205);
        gotoxy(i, LF);
        printf("%c", 205);
    }
    for (int i = LI + 1; i < LF; i++)
    {
        gotoxy(CI, i);
        printf("%c", 186);
        gotoxy(CF, i);
        printf("%c", 186);
    }

    textcolor(7);
    textbackground(0);
}
void CriarFundo(void)
{
    system("cls");
    Fundo_Design(2, 2, 60, 30, 0, 2);  // CI,LI, CF,LF, Cor interna, Cor externa
    Fundo_Design(61, 2, 80, 30, 0, 0); // CI,LI, CF,LF, Cor interna, Cor externa

    Fundo_Design(62, 2, 100, 30, 0, 2); // CI,LI, CF,LF, Cor interna, Cor externa
    Fundo_Design(63, 3, 99, 29, 7, 0);  // Preto
    // controle();
}
void Carta_Design(int CI, int LI, int CF, int LF, bool virada, int naipe, int corN, int valor)
{
    int i, j, k, CorT = 15, CorF = 2;

    for (i = LI; i < LF; i++)
    {
        for (j = CI; j < CF; j++)
        {
            textbackground(2);
            gotoxy(j, i);
            printf(" ");
        }
    }
    // Cores
    // textcolor(CorT); textbackground(CorF);

    if (virada == true)
    {

        for (i = LI; i < LF + 1; i++)
        {
            for (j = CI; j < CF + 1; j++)
            {
                textbackground(15);
                textcolor(2);
                gotoxy(j, i);
                printf("%c", 176);
            }
        }
        textcolor(2);
        gotoxy(CI, LI);
        printf("%c%c%c%c%c%c", 177, 177, 177, 177, 177, 177);
    }

    if (virada == false)
    {

        for (i = LI; i < LF + 1; i++)
        {
            textcolor(15);
            for (j = CI; j < CF + 1; j++)
            {

                textbackground(15);
                gotoxy(j, i);
                printf(" ");
            }
        }

        if (valor == 1)
        {
            gotoxy(CI, LI);
            textcolor(corN);
            printf("%c", 'A');
            gotoxy(CF, LF);
            textcolor(corN);
            printf("%c", 'A');
        }
        else if (valor == 11)
        {
            gotoxy(CI, LI);
            textcolor(corN);
            printf("%c", 'J');
            gotoxy(CF, LF);
            textcolor(corN);
            printf("%c", 'J');
        }
        else if (valor == 12)
        {
            gotoxy(CI, LI);
            textcolor(corN);
            printf("%c", 'Q');
            gotoxy(CF, LF);
            textcolor(corN);
            printf("%c", 'Q');
        }
        else if (valor == 13)
        {
            gotoxy(CI, LI);
            textcolor(corN);
            printf("%c", 'K');
            gotoxy(CF, LF);
            textcolor(corN);
            printf("%c", 'K');
        }
        else
        {
            gotoxy(CI, LI);
            textcolor(corN);
            printf("%d", valor);
            if (valor == 10)
                gotoxy(CF - 1, LF);
            else
                gotoxy(CF, LF);
            textcolor(corN);
            printf("%d", valor);
        }

        for (i = LI + 1; i < LF; i++)
        {
            textcolor(15);
            for (j = CI + 1; j < CF; j++)
            {

                textcolor(corN);
                gotoxy(j, i);
                printf("%c", naipe);
                if (valor == 11 && j == CI + 1 || valor == 11 && j == CF - 1)
                {
                    textcolor(6);
                    gotoxy(j, i);
                    printf("%c", 20);
                }

                if (valor == 12 && j == CI + 1 || valor == 12 && j == CF - 1)
                {
                    textcolor(6);
                    gotoxy(j, i);
                    printf("%c", 157);
                }
                if (valor == 13 && j == CI + 1 || valor == 13 && j == CF - 1)
                {
                    textcolor(6);
                    gotoxy(j, i);
                    printf("%c", 206);
                }
                textcolor(corN);
            }
        }
    }

    // Cantos
    if (valor != 0 || naipe != 0)
    {
        gotoxy(CF, LI);
        printf("%c", naipe);
        gotoxy(CI, LF);
        printf("%c", naipe);
    }
    else
    {
        gotoxy(CI, LI);
        printf("%c", 201);
        gotoxy(CF, LI);
        printf("%c", 187);
        gotoxy(CI, LF);
        printf("%c", 200);
        gotoxy(CF, LF);
        printf("%c", 188);
    }

    // textcolor(CorT); textbackground(CorF);
    // Contorno
    if (naipe == 178)
    {
        textcolor(2);
        for (i = LI; i < LF + 1; i++)
        {
            textcolor(2);
            for (j = CI; j < CF + 1; j++)
            {

                textbackground(10);
                gotoxy(j, i);
                printf("%c", 176);
            }
        }

        /*gotoxy(CI,LI);
        textcolor(corN);
        printf("%d",valor);

        gotoxy(CF,LF);
        textcolor(corN);
        printf("%d",valor);*/

        for (i = LI + 1; i < LF; i++)
        {
            textcolor(15);
            for (j = CI + 1; j < CF; j++)
            {

                textcolor(corN);
                gotoxy(j, i);
                printf("%c", 176);
            }
        }
    }
    else
    {
        for (i = CI + 1; i < CF; i++)
        {
            gotoxy(i, LI);
            printf("%c", 205);
            gotoxy(i, LF);
            printf("%c", 205);
        }
        for (i = LI + 1; i < LF; i++)
        {
            gotoxy(CI, i);
            printf("%c", 186);
            gotoxy(CF, i);
            printf("%c", 186);
        }
    }
    if (valor == 10)
    {
        gotoxy(CI, LI);
        textcolor(corN);
        printf("%d", valor);
        gotoxy(CF - 1, LF);
        textcolor(corN);
        printf("%d", valor);
    }
    textcolor(7);
    textbackground(0);
}
void InicializarColunas(coordenada PilhasColunas[7])
{

    int x1 = 6, x2 = 11;
    for (int i = 1; i <= 7; i++)
    {
        PilhasColunas[i].CI = x1;
        PilhasColunas[i].CF = x2;
        x1 += 7;
        x2 += 7;
    }
}
void InicializarFileiras(coordenada PilhasFileiras[13])
{

    int y1 = 12, y2 = 15;
    for (int i = 1; i <= 13; i++)
    {
        PilhasFileiras[i].LI = y1;
        PilhasFileiras[i].LF = y2;
        y1 += 1;
        y2 += 1;
    }
}
void InicialCartasFront(tpPilhaMult &PM)
{
    tpCarta Carta;
    int i, j, x1, x2, y1, y2;

    x1 = 6;  // coluna inicial
    x2 = 11; // coluna final
    for (i = 0; i < 7; i++)
    {

        y1 = 12; // linha inicial
        y2 = 15; // linha final

        for (j = 0; j < i+1; j++)
        {
            if (j == i)
            {
                Carta=CartaPilha(PM,i);
                Carta_Design(x1, y1, x2, y2, false,Carta.naipe,Carta.cor,Carta.valor);
            }
                
            else
                Carta_Design(x1, y1, x2, y2, true, 0, 0, 0);
            y1 += 1;
            y2 += 1;
        }
        x1 += 7;
        x2 += 7;
    }
}


void MonteFront(int valor, int cor, int naipe)
{
    if (valor == 0)
    {
        Carta_Design(3, 5, 8, 8, true, 0, 0, 0);      // MONTE VIRADO
        Carta_Design(10, 5, 15, 8, false, 178, 2, 0); // ESPACO CARTAS
    }
    else
    {
        Carta_Design(10, 5, 15, 8, false, naipe, cor, valor); // c1
    }

    // Carta_Design(17, 5, 22, 8, false, naipe, cor, valor); // c2
    // Carta_Design(24, 5, 29, 8, false, naipe, cor, valor); // c3
}
