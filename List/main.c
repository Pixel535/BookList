#include <stdio.h>
#include <stdlib.h>


typedef struct ksiazka
{
    char nazwa[50];
    char imie[50];
    char nazwisko[50];
    struct ksiazka *next;

}ksiazka;


//Do Funkcji 1

void dodajksiazke(ksiazka** lista, ksiazka* nowy)
{
     nowy->next=NULL;
     if((*lista)==NULL)
     {
        *lista = nowy;
     }
     else
     {
        ksiazka* wsk = *lista;
         while((wsk)->next != NULL)
         {
            wsk = wsk->next;
         }
        wsk->next = nowy;
     }

}

void nowaKsiazka(ksiazka** lista)
{
    char j[5];
    gets(j);
    ksiazka* nowy = (ksiazka*)malloc(sizeof(ksiazka));
    printf("Podaj [tytul]: ");
    gets(nowy->nazwa);
	printf("Podaj [imie] autora: ");
	gets(nowy->imie);
	printf("Podaj [nazwisko] autora: ");
	gets(nowy->nazwisko);
    dodajksiazke(lista, nowy);
}

//Do Funkcji 2

void pokazListe (ksiazka* lista)
{
    ksiazka* wsk = lista;
    int x = 1;
    printf("Lista ksiazek:\n");
    while (wsk != NULL)
    {
        printf("%d) \"%s\" %s %s\n", x, wsk->nazwa, wsk->imie, wsk->nazwisko);
        wsk = wsk->next;
        ++x;
    }

	if(lista == NULL)
    {
        printf("Lista jest pusta\n");
    }


}

//Do Funkcji 3

int dlugosclisty(ksiazka* lista)
{
    int d = 0;
    ksiazka* wsk = lista;
    while(wsk != NULL)
    {
        d++;
        wsk = wsk->next;
    }
    return d;
}

void pokazksiazke(ksiazka* lista)
{
    int numer;
    printf("Podaj numer z listy: ");
    scanf("%d", &numer);


    if ((numer < 1) || (numer > dlugosclisty(lista)))
    {
        printf("Blad danych");
    }
    else
    {
        int i;
        ksiazka* wsk = lista;
        for(i = 1; i<numer; i++)
        {
            wsk = wsk->next;
        }
        printf("\"%s\" %s %s\n", wsk->nazwa, wsk->imie, wsk->nazwisko);
    }

}


//Do Funkcji 4

int usun(char* nazwa, ksiazka** lista)
{
        ksiazka* poprzedni=NULL;
        ksiazka* wsk= *lista;

        while((wsk != NULL) && ( (strcmp(wsk->nazwa, nazwa) != 0) ))
        {
                poprzedni = wsk;
                wsk = wsk->next;
        }

        if(wsk == NULL)
        {
            return 0;
        }
        else
        {
            if(poprzedni == NULL)
            {
                (*lista)=(*lista)->next;
                free(wsk);
            }
            else
            {
             poprzedni->next=wsk->next;
             free(wsk);
            }
            return 1;
        }
}

void usunksiazkepot(ksiazka** lista)
{
    char tytul[50];
    char j[5];
    gets(j);
    printf("Podaj tytul ksiazki ktory chcesz usunac: ");
    gets(tytul);
    if(usun(tytul, lista))
    {
        printf("ksiazka zostala pomyslnie usunieta");
    }
    else
    {
        printf("Nie ma takiej ksiazki");
    }

}

//Do Funkcji 5

int usunPoNum(ksiazka** lista, int numer)
{
        ksiazka* poprzedni=NULL;
        ksiazka* wsk= *lista;
        int i;
        for(i=1; i<numer; i++)
        {
                poprzedni = wsk;
                wsk = wsk->next;
        }

        if(wsk == NULL)
        {
            return 0;
        }
        else
        {
            if(poprzedni == NULL)
            {
                (*lista)=(*lista)->next;
                free(wsk);
            }
            else
            {
             poprzedni->next=wsk->next;
             free(wsk);
            }
            return 1;
        }
}

void usunksiazkePoNum(ksiazka** lista)
{
    int i;
    printf("Podaj numer z listy ksiazki ktora chcesz usunac: ");
    scanf("%d", &i);


    if((i<1) || (i>dlugosclisty(*lista)))
    {
        printf("Zly numer nie ma takiej ksiazki");
    }
    else
    {
        usunPoNum(lista, i);
        printf("ksiazka zostala pomyslnie usunieta");
    }
}
//6
int szukaj(char* nazwa, ksiazka** lista)
{
    ksiazka* wsk = lista;
    for(wsk = lista; wsk!=NULL; wsk = wsk->next)
    {
        if((strcmp(wsk->nazwa)) == 0)
        {
            printf("\"%s\" %s %s\n", wsk->nazwa, wsk->imie, wsk->nazwisko);
        }
        else
        {
            printf("Nie ma takiej ksiazki");
        }
    }
}
void pokazksiazkepot(ksiazka* lista)
{
    char tytul[50];
    char j[5];
    gets(j);
    printf("Podaj tytul ksiazki ktory chcesz wyszukac: ");
    gets(tytul);
    szukaj(tytul, lista);
}

int main()
{
    int komenda;
	ksiazka* lista = NULL;
    printf("Program do zarzadzania lista ksiazek\n");
	printf("----------------------------------------------\n");
	printf("[0] Wyjscie z programu\n");
	printf("[1] Wprowadz nowa ksiazke\n");
	printf("[2] Wyswietl liste ksiazek\n");
	printf("[3] Wyswietl ksiazke ze wskazanej pozycji na liscie\n");
	printf("[4] Usun ksiazke o podanym tytule\n");
	printf("[5] Usun ksiazke ze wskazanej pozycji na liscie\n");
	printf("[6] Wyswietl ksiazke ze wskazanej pozycji na liscie\n");
	printf("----------------------------------------------\n\n");

	while(1)
    {
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1: nowaKsiazka(&lista); break;
			case 2: pokazListe(lista); break;
			case 3: pokazksiazke(lista); break;
			case 4: usunksiazkepot(&lista); break;
			case 5: usunksiazkePoNum(&lista); break;
			case 6: pokazksiazkepot(lista); break;
        }
    }

    return 0;
}
//Mateusz Gajda
