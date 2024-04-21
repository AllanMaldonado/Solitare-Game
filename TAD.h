#define MAXPILHA 52
#define MAXMONTE 48
#define MAXPILHAS 100

//-----------------CARTAS--------------------------

struct tpCarta
{
	int valor, cor, naipe;
	bool virada;
};

//-----------------MONTES--------------------------

struct tpMonte
{
	int topo1, topo2;
	tpCarta Monte[MAXMONTE];
	// M1 (principal) e M4 (usado pra quando precisar preecher o monte principal denovo)//M2 (Exibir na tela) e M3 (usado quando M2 atingir 3 e precisar jogar no M4)
};

void IniciarMonte(tpMonte &MON)
{
	MON.topo1 = -1;
	MON.topo2 = MAXMONTE;
}

void PushMonte(tpMonte &MON, tpCarta Elem, int NP)
{
	if (NP == 1)
		MON.Monte[++MON.topo1] = Elem;
	else
		MON.Monte[--MON.topo2] = Elem;
}

int CheiaMonte(tpMonte MON)
{
	return MON.topo1 == MON.topo2 - 1;
}

int VaziaMonte(tpMonte MON, int NP)
{
	if (NP == 1)
		return MON.topo1 == -1;
	else
		return MON.topo2 == MAXMONTE;
}

tpCarta PopMonte(tpMonte &MON, int NP)
{
	if (NP == 1)
		return MON.Monte[MON.topo1--];
	else
		return MON.Monte[MON.topo2++];
}
void ExibirMonte(tpMonte MON, int NP)
{
	tpCarta Elem;
	char booleano;
	while (!VaziaMonte(MON,NP))
	{
		Elem = PopMonte(MON,NP);
		if(Elem.virada==true)
			booleano='V';
		else if(Elem.virada==false)
				booleano='D';
		if(Elem.cor == 12)
			textcolor(12);
		else
			textcolor(15);

		printf("[%c / %d / %c]\n", Elem.naipe, Elem.valor,booleano);
 	}
	textcolor(15);
}
tpCarta TopoMonte (tpMonte MON, int NP)
{
	if(NP == 1 )
		return MON.Monte[MON.topo1];
	else
		return MON.Monte[MON.topo2];
}
//-------------------
struct TpPilha
{
	int Topo;
	tpCarta Pilha[MAXPILHA];
};

void InicializarP(TpPilha &P)
{
	P.Topo = -1;
}

void PushP(TpPilha &P, tpCarta Elem)
{
	P.Pilha[++P.Topo] = Elem;
}

tpCarta PopP(TpPilha &P)
{
	return P.Pilha[P.Topo--];
}

int CheiaP(int Topo)
{
	return Topo == MAXPILHA - 1;
}

int VaziaP(int Topo)
{
	return Topo == -1;
}

void ExibirP(TpPilha P)
{
	tpCarta Elem;
	while (!VaziaP(P.Topo))
	{
		Elem = PopP(P);
		textcolor(Elem.cor);
		printf("  [%c / %d]\n  ", Elem.naipe, Elem.valor);
	}
	textcolor(15);
}
//-------------------------------------------------
struct tpPilhaMult
{
	int Topo[MAXPILHAS], Base[MAXPILHAS];
	tpCarta Pilha[MAXPILHAS];	
};

void Inicializar(tpPilhaMult &P, int Qtde)
{
	int QtdeElem, i;
	
	QtdeElem = MAXPILHAS/Qtde;
	
	for(i=0;i<=Qtde;i++)
	{
		P.Base[i]=i*QtdeElem;
		P.Topo[i]=P.Base[i]-1;
	}
}

void Push(tpPilhaMult &P, tpCarta C, int NP)
{
	P.Pilha[++P.Topo[NP]]=C;
}

tpCarta Pop(tpPilhaMult &P, int NP)
{
	return P.Pilha[P.Topo[NP]--];
}

tpCarta CartaPilha(tpPilhaMult P, int NP)
{
	return P.Pilha[P.Topo[NP]];
}

int PVazia(tpPilhaMult P, int NP)
{
	return P.Topo[NP]+1==P.Base[NP];
}

int PCheia(tpPilhaMult P, int NP)
{
	return P.Topo[NP]+1==P.Base[NP+1];
}

void ExibirPM(tpPilhaMult P, tpCarta C, int NP)
{
	printf("\nNaipe \tCor \tNumero");
	while(!PVazia(P,NP))
	{	
		C = Pop(P,NP);
		printf("\n%c \t%d \t%d", C.naipe, C.cor, C.valor);
	}
}
