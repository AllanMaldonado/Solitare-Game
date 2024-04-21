#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>

#include "TAD.h"
#include "INTERFACE.h"
void PilhaPraPilha(tpPilhaMult &PM, coordenada Colunas[], coordenada Fileiras[]); // NP

void controle(TpPilha &P, tpMonte &M, tpPilhaMult &D,coordenada Colunas[], coordenada Fileiras[]);
void Jogar(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[]);
void menuM(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[]);
void MonteMexer(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[] /*, int op*/);
void InserirCartasPilhas(tpPilhaMult &PM, TpPilha &Pilha); // PA é a pilha auxiliar
void PilhaPraDescarte(tpPilhaMult &PM,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[]); // NP


void criarCarta(TpPilha &P)
{
    tpCarta carta;
    int TL = 0, i, j;

    for (i = 3; i <= 6; i++)
        for (j = 1; j <= 13; j++)
        {
            carta.naipe = i;
            carta.valor = j;
            carta.virada = true;
            if (carta.naipe == 3 || carta.naipe == 4)
                carta.cor = 12;
            else
                carta.cor = 0;

            PushP(P, carta);
        }
}

void embaralhar(TpPilha &P)
{
    TpPilha P1, P2, P3, P4;
    InicializarP(P1);
    InicializarP(P2);
    InicializarP(P3);
    InicializarP(P4);
    int x;
    while (!VaziaP(P.Topo))
    {
        x = rand() % 4;
        switch (x)
        {
        case 0:
            PushP(P1, PopP(P));
            break;
        case 1:
            PushP(P2, PopP(P));
            break;
        case 2:
            PushP(P3, PopP(P));
            break;
        case 3:
            PushP(P4, PopP(P));
            break;
        }
    }

    while (!VaziaP(P1.Topo))
        PushP(P, PopP(P1));
    while (!VaziaP(P2.Topo))
        PushP(P, PopP(P2));
    while (!VaziaP(P3.Topo))
        PushP(P, PopP(P3));
    while (!VaziaP(P4.Topo))
        PushP(P, PopP(P4));
}

void controle(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
    gotoxy(75, 4);
    textcolor(15);
    printf("| PACIENCIA |");
    for (int i = 64; i < 99; i++)
    {
        gotoxy(i, 5);
        textcolor(7);
        printf("%c", 205);
    }
    gotoxy(65, 8);
    textcolor(2);
    printf("[M] Monte ");
    textcolor(15);
    printf("[P]Pilhas ");
    textcolor(10);
    printf("[D]Descartes ");
    textcolor(7);
    gotoxy(65, 9);
    printf("--------------------------------");

    gotoxy(65, 11);
    textcolor(0);
    textbackground(2);
    printf("Movimento:");
    textbackground(0);
    gotoxy(65, 12);
    textcolor(7);
    printf("----------");
    gotoxy(76, 11);

    Jogar(P, PM, M,D, Colunas, Fileiras);
}
void menuP(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
    gotoxy(76, 11);
    printf("                      ");
    gotoxy(76, 11);
    printf("Mover entre pilhas? ");
    gotoxy(65, 13);
    printf("[S]Sim | [N]Nao(Volta)");
    gotoxy(93, 11);
    char op;
    do
    {
        gotoxy(95, 11);
        scanf(" %c", &op);
        switch (toupper(op))
        {
        case 'N':
            Fundo_Design(63, 3, 99, 29, 7, 0);
            controle(P, PM, M,D, Colunas, Fileiras);
            break;
        case 'S':
            gotoxy(65, 13);
            printf("                       ");

        PilhaPraPilha(PM,Colunas, Fileiras);
        Fundo_Design(63, 3, 99, 29, 7, 0);
        controle(P, PM, M,D, Colunas, Fileiras);

            break;
        }

    } while (op != 0);
}
void menuD(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
    gotoxy(76, 11);
    printf("                      ");
    gotoxy(76, 11);
    printf("Mover pro descarte? ");
    gotoxy(65, 13);
    printf("[S]Sim | [N]Nao(Volta)");
    gotoxy(93, 11);
    char op;
    do
    {
        gotoxy(95, 11);
        scanf(" %c", &op);
        switch (toupper(op))
        {
        case 'N':
            Fundo_Design(63, 3, 99, 29, 7, 0);
            controle(P, PM, M,D, Colunas, Fileiras);
            break;
        case 'S':
            gotoxy(65, 13);
            printf("                       ");
			
        	PilhaPraDescarte(PM,D,Colunas, Fileiras);
        	Fundo_Design(63, 3, 99, 29, 7, 0);
        	controle(P, PM, M,D, Colunas, Fileiras);

            break;
        }

    } while (op != 0);
}
void Jogar(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
	tpCarta C;
	
    char op;
    do
    {
        gotoxy(76, 11);
        scanf(" %c", &op);

        switch (toupper(op))
        {
        case 'M':
            menuM(P, PM, M,D, Colunas, Fileiras);
            break;
        case 'P':
            menuP(P, PM, M,D, Colunas, Fileiras);
            break;
        case 'D':
            menuD(P, PM, M,D, Colunas, Fileiras);
            break;
        default:
            //printf("Selecione entre> M/P/D");
            break;
        }
    } while (op != 27);
}

void menuM(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
    gotoxy(76, 11);
    printf("                      ");
    gotoxy(76, 11);
    printf("Puxar uma carta? ");
    gotoxy(65, 13);
    printf("[S]Sim | [N]Nao(Volta)");
    gotoxy(93, 11);
    char op;
    do
    {
        scanf(" %c", &op);
        switch (toupper(op))
        {
        case 'N':
            Fundo_Design(63, 3, 99, 29, 7, 0);
            controle(P, PM, M,D, Colunas, Fileiras);
            break;
        case 'S':
            gotoxy(65, 13);
            printf("                       ");
            MonteMexer(P, PM, M,D, Colunas, Fileiras);
            // controle();
            break;
        }

    } while (op != 0);
}

void MonteDescarte(int &irPilha, tpMonte &M, tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[])
{
    tpCarta aux2, AUX;
    int irFileira;
    bool valida;

    if (D.Topo[irPilha - 1] != 13)
    {
        // FAZER AS VERIFICA��ES DE HIERARQUIAA DE ACORDO COM A PILHA
        aux2 = PopMonte(M, 2);

        if (aux2.valor == (D.Pilha[D.Topo[irPilha - 1]].valor) + 1 || aux2.valor==1 && PVazia(D, irPilha-1) )
            if (aux2.naipe == D.Pilha[D.Topo[irPilha - 1]].naipe || aux2.valor==1 && PVazia(D, irPilha-1))
                valida = true;
            else
                valida = false;
        else
            valida = false;

        if (valida == true)
        {
            gotoxy(65, 15);

           
            switch(irPilha)
            {
            	case 1:  Carta_Design(33, 5, 38, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 2:  Carta_Design(40, 5, 45, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 3:  Carta_Design(47, 5, 52, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 4:  Carta_Design(54, 5, 59, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            
            		break;
            }
			Push(D, aux2, irPilha - 1);
        }
        else
        {
            gotoxy(65, 15);
            printf("                       ");
          }
        gotoxy(65, 15);
            printf("                       ");
            gotoxy(65, 15);
    }
    gotoxy(90, 30);
     
}
void PilhaPraDescarte(tpPilhaMult &PM,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[]) // NP
{
    tpCarta aux2,aux,aux3,C;
    bool valida;
    int C1,C2,irFileira,irFileira2;
    //--------------------------------------------------------------------------
    gotoxy(3, 30);	ExibirPM(PM,C,1);
    gotoxy(65, 13);
    printf("Quer tirar de qual pilha?"); scanf("%d",&C1);
    aux=CartaPilha(PM,C1-1);

    gotoxy(65, 14);
    printf("Qual Descarte recebe?"); scanf("%d",&C2);
    aux3=CartaPilha(D,C2-1);
	//--------------------------------------------------------------------------
	
    if (PM.Pilha[PM.Topo[C1-1]].valor == (D.Pilha[D.Topo[C2-1]].valor) + 1 || PM.Pilha[PM.Topo[C1-1]].valor==1 && PVazia(D, C2-1))
        if (PM.Pilha[PM.Topo[C1-1]].naipe == D.Pilha[D.Topo[C2-1]].naipe ||  PM.Pilha[PM.Topo[C1-1]].valor==1 &&  PVazia(D, C2-1))
            valida = true;
        else
            valida = false;
    else  valida = false;
    //--------------------------------------------------------------------------	
    if (valida == true)
        {
            aux2 = Pop(PM,C1-1);
            gotoxy(65, 15);

            irFileira = (D.Topo[C2 - 1] - D.Base[C2 - 1]) + 2;
            // printf("Fileira: %d  ",irFileira);
            switch(C2)
            {
            	case 1:  Carta_Design(33, 5, 38, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 2:  Carta_Design(40, 5, 45, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 3:  Carta_Design(47, 5, 52, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            	case 4:  Carta_Design(54, 5, 59, 8, false, aux2.naipe, aux2.cor, aux2.valor);
            		break;
            }
 			
            
			Push(D, aux2, C2 - 1);
            
            irFileira2 = (PM.Topo[C1 - 1] - PM.Base[C1 - 1]) + 2;
            Fundo_Design(Colunas[irFileira2].CI, Fileiras[irFileira2].LI, Colunas[irFileira2].CF, Fileiras[irFileira2].LF, 2, 2);
            
            if(!PVazia(PM,C1 - 1))
            {
            	aux3 = CartaPilha(PM,C1-1);
            	/*Pop(PM,C1-1);
            	Pop(PM,C1-1);*/
            	Carta_Design(Colunas[C1].CI, Fileiras[irFileira2-1].LI, Colunas[C1].CF, Fileiras[irFileira2-1].LF, false, aux3.naipe, aux3.cor, aux3.valor);

            }else{
                Fundo_Design(Colunas[C1].CI, Fileiras[C1].LI, Colunas[C1].CF, Fileiras[C1].LF, 2, 10);
            }
        }
        else//--------------------------------------------------------------------------
        {
            gotoxy(65, 15);
            printf("                       ");
        
            
        }
        gotoxy(65, 15);
            printf("                       ");
            gotoxy(65, 15);
            
    gotoxy(3, 40);	ExibirPM(PM,C,1);
}
void PilhaPraPilha(tpPilhaMult &PM, coordenada Colunas[], coordenada Fileiras[]) // NP
{
    tpCarta aux2,aux,aux3;
    bool valida;
    int C1,C2,irFileira,irFileira2;
    gotoxy(65, 13);
    printf("Quer tirar de qual pilha?"); scanf("%d",&C1);
    aux=CartaPilha(PM,C1-1);

    gotoxy(65, 14);
    printf("Qual pilha recebe?"); scanf("%d",&C2);
    aux3=CartaPilha(PM,C2-1);

    if (PM.Pilha[PM.Topo[C1-1]].valor == (PM.Pilha[PM.Topo[C2-1]].valor) - 1 || PM.Pilha[PM.Topo[C1-1]].valor==13 && PVazia(PM, C2-1))
        if (PM.Pilha[PM.Topo[C1-1]].cor != PM.Pilha[PM.Topo[C2-1]].cor || PM.Pilha[PM.Topo[C1-1]].valor==13 && PVazia(PM, C2-1))
            valida = true;
        else
            valida = false;
    else  valida = false;
    
    if (valida == true)
        {
            aux2 = Pop(PM,C1-1);
            gotoxy(65, 15);

            irFileira = (PM.Topo[C2 - 1] - PM.Base[C2 - 1]) + 2;
            // printf("Fileira: %d  ",irFileira);
            Carta_Design(Colunas[C2].CI, Fileiras[irFileira].LI, Colunas[C2].CF, Fileiras[irFileira].LF, false, aux2.naipe, aux2.cor, aux2.valor);
            Push(PM, aux2, C2 - 1);
            
            irFileira2 = (PM.Topo[C1 - 1] - PM.Base[C1 - 1]) + 2;
            Fundo_Design(Colunas[C1].CI, Fileiras[C1].LI, Colunas[C1].CF, Fileiras[C1].LF, 2, 2);
            
            if(!PVazia(PM,C1 - 1))
            {
            	aux3 = CartaPilha(PM,C1-1);
            	Carta_Design(Colunas[C1].CI, Fileiras[irFileira2].LI, Colunas[C1].CF, Fileiras[irFileira2].LF, false, aux3.naipe, aux3.cor, aux3.valor);

            }else{
                Fundo_Design(Colunas[C1].CI, Fileiras[C1].LI, Colunas[C1].CF, Fileiras[C1].LF, 2, 10);
            }
        }
        else
        {
            gotoxy(65, 15);
            printf("                       ");
            gotoxy(65, 15);
             
        }
        gotoxy(65, 15);
            printf("                       ");
            gotoxy(65, 15);
}

void MonteIniciar(TpPilha &P, tpMonte &M, tpPilhaMult &PM)
{
    for (int i = 0; i < 24; i++)
        PushMonte(M, PopP(P), 1);

    InserirCartasPilhas(PM, P);
    // ExibirMonte(M, 1);
    //printf("\n");
}

void InserirCartasPilhas(tpPilhaMult &PM, TpPilha &Pilha) // PA é a pilha auxiliar
{
    tpCarta aux, c;
    int i, j, cont;

    while (!VaziaP(Pilha.Topo))
    {
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < i + 1; j++)
            {
                Push(PM, PopP(Pilha), i);
            }
        }
    }
    InicialCartasFront(PM);
    //ExibirPM( PM, c, 2);
}

void MontePilha(int &irPilha, tpMonte &M, tpPilhaMult &PM, coordenada Colunas[], coordenada Fileiras[])
{
    tpCarta aux2, AUX;
    int irFileira;
    bool valida;

    if (PM.Topo[irPilha - 1] != 13)
    {
        // FAZER AS VERIFICA��ES DE HIERARQUIAA DE ACORDO COM A PILHA
        aux2 = PopMonte(M, 2);

        if (aux2.valor == (PM.Pilha[PM.Topo[irPilha - 1]].valor) - 1 || aux2.valor==13 &&  PVazia[PM,irPilha - 1])
            if (PM.Pilha[PM.Topo[irPilha - 1]].cor != aux2.cor || aux2.valor==13 && PVazia[PM,irPilha - 1])
                valida = true;
            else
                valida = false;
        else
            valida = false;

        if (valida == true)
        {
            gotoxy(65, 15);


            irFileira = (PM.Topo[irPilha - 1] - PM.Base[irPilha - 1]) + 2;
            // printf("Fileira: %d  ",irFileira);
            Carta_Design(Colunas[irPilha].CI, Fileiras[irFileira].LI, Colunas[irPilha].CF, Fileiras[irFileira].LF, false, aux2.naipe, aux2.cor, aux2.valor);
            Push(PM, aux2, irPilha - 1);
        }
        else
        {
            gotoxy(65, 15);
            printf("                       ");
          }
        gotoxy(65, 15);
            printf("                       ");
            gotoxy(65, 15);
    }
    gotoxy(90, 30);
     
}

void MonteMexer(TpPilha &P, tpPilhaMult &PM, tpMonte &M,tpPilhaMult &D, coordenada Colunas[], coordenada Fileiras[] /*, int op*/)
{
    tpCarta aux, aux2, AUX;
    TpPilha P2;
    InicializarP(P2);
    tpMonte M2;
    IniciarMonte(M2);

    int cont = 0, irFileira = 0, irPilha = 0;
    char quer, puxa,op;

    gotoxy(76, 11);
    printf("[ESP-puxa | ESC-sair]");
    puxa = getch();
    if (puxa == 27)
        menuM(P, PM, M,D, Colunas, Fileiras);

    do
    {
        /*AUX=CartaPilha(PM,1);
        printf("oooooo: %d/%c",AUX.valor,AUX.naipe);*/

        if (puxa == 32 && !VaziaMonte(M, 1))
        {
            aux = PopMonte(M, 1);
            PushMonte(M, aux, 2);

            MonteFront(aux.valor, aux.cor, aux.naipe);
            gotoxy(65, 13);
            printf("                       ");
            gotoxy(65, 13);

            printf("Quer a carta [S/N]?");
            gotoxy(84, 13);
            scanf(" %c", &quer);
            textcolor(15);
            gotoxy(65, 13);
            printf("                       ");

            if (toupper(quer) == 'S')
            {
            	gotoxy(65, 13);
            	printf("Enviar pra [P]ilha ou [D]escarte? ");
            	gotoxy(98, 13);
            	scanf(" %c", &op);
                MonteFront(0, 0, 0);
				
				switch(toupper(op))
				{
					case 'P':
						gotoxy(65, 13);
		                printf("                                  ");
						gotoxy(65, 13);
		                printf("Qual pilha?[1 a 7]");
		                gotoxy(83, 13);
		                scanf("%d", &irPilha);
		                gotoxy(65, 13);
		                printf("                                  ");
		
		                MontePilha(irPilha, M, PM, Colunas, Fileiras);
						break;
					case 'D':
						gotoxy(65, 13);
		                printf("                                  ");
												gotoxy(65, 13);

		                printf("Qual Descarte?[1 a 4]");
		                gotoxy(92, 13);
		                scanf("%d", &irPilha);
		                gotoxy(65, 13);
		                printf("                                  ");
						
		                MonteDescarte(irPilha, M, D, Colunas, Fileiras);
		                
						break;
					default:
						break;
				}
				gotoxy(65, 13);
		        printf("                                  ");
                
            }
        }
        if (VaziaMonte(M, 1))
        {
            while (!VaziaMonte(M, 2))
                PushMonte(M, PopMonte(M, 2), 1);
            // ExibirMonte(M, 1);
        }

        gotoxy(76, 11);
        printf("[ESP-puxa | ESC-sair]");
        puxa = getch();

        if (puxa == 27)
        {
            PushMonte(M, PopMonte(M, 2), 1);
            menuM(P, PM, M,D, Colunas, Fileiras);
        }

    } while (quer != '0');

    // break;
    // }
}

void IniciarTela(coordenada Colunas[], coordenada Fileiras[])
{

    CriarFundo();
    MonteFront(0, 0, 0);
    InicializarColunas(Colunas);
    InicializarFileiras(Fileiras);
    // InicialCartasFront();

    // Descarte

    Carta_Design(33, 5, 38, 8, false, 178, 2, 0); // D1
    Carta_Design(40, 5, 45, 8, false, 178, 2, 0); // D2
    Carta_Design(47, 5, 52, 8, false, 178, 2, 0); // D3
    Carta_Design(54, 5, 59, 8, false, 178, 2, 0); // D4
   
    
    textbackground(0);
    
    int j=1;
    for(int i=7; i<56 ; i+=7)
    {
    	gotoxy(i,11);
    	 printf("[%d]",j);
    	 j++;
    }
    
    int i=34;
    for(int j=1; j<5 ;j++)
    {
    	gotoxy(i,4);
    	 printf("[%d]",j);
    	 i+=7;
    }
    
   
    textcolor(15);
    textbackground(2);
}

void Executar()
{
    tpCarta C, AUX;
    TpPilha P;
    InicializarP(P);
    
    tpMonte M;
    IniciarMonte(M);
    
    tpPilhaMult PM;
    Inicializar(PM, 7);
    
    tpPilhaMult D;
    Inicializar(D, 4);

    coordenada Colunas[7], Fileiras[13];

    criarCarta(P);
    for (int i = 0; i < 6; i++)
        embaralhar(P);

    IniciarTela(Colunas, Fileiras);
    MonteIniciar(P, M, PM);

    //---------
    /*MontePraPilha(PM,1,3);
    AUX=CartaPilha(PM,3);
    printf("%d/%c",AUX.valor,AUX.naipe);*/

    controle(P, PM, M,D, Colunas, Fileiras);
}

int main()
{
    Executar();
    return 0;
}
