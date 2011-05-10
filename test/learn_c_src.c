#include <stdio.h> 			// přidání hlavičkového souboru standardní knihovny
int main () 				// funkce main
{
	puts("Ahoj světe !");		// jeden ze způsobů výstupu
	return 0;			// hodnota navrácená funkcí
}


/******************************************************
 * kompilace pomocí příkazu:
 * $ cc priklad.c -o priklad
 *
 * volání překladače s přepínačem pro výstupní soubor
 ******************************************************/


/****************************************************************
 * DATOVÉ TYPY
 *
 * celá znaménková	celá bez znaménka	reálná
 * --------------------------------------------------------------
 * signed char		unsigned char		float
 * short			unsigned short		double
 * int				unsigned int		long double
 * long				unsigned long		-
 ****************************************************************/


/*************************************************************************
 * VYBRANÉ FUNKCE:
 *
 * int atoi(const char *s) - stdlib.h - konverze na int -
 * long atol(const char *s) - stdlib.h - konverze na long -
 * double atof(const char *s) - stdlib.h - konverze na double -
 * int main(void)
 * int main()
 * int main(int argc, char *argv[])
 * int printf(const char *format, ...) - stdio.h - výstup - printf("Minus sto dvacet pět je %i\n", i);
 * puts(string) - (stdio.h) - výstup - puts("neco")
 * int scanf(const char *format, ...) - stdio.h -
 * sizeof(data_type) - (stdio.h) - velikost datového typu - sizeof(int)
 * long strtol(const char *nptr, char **endptr, int base) - stdlib.h -
 * double strtod(const char *nptr, char **endptr) - stdlib.h -
 *************************************************************************/


/*******************************************************
 * PROMěNNÉ (variables)
 *******************************************************/

#include <stdio.h>

double d1, d2;	// globální proměnné

int main(void)
{
	int j;	// lokální proměnná
	int i = 0;

	d1 = 1.5;
	j = i;
	return j;
}


/*******************************************************
 * POLE
 *******************************************************/

int a[5] = {1, 2, 3, 4, 5};	// naplnění pole

int a[10]; 		// definování pole o 10 prvcích
a[0] = 5;		// přiřazení hodnoty 5 k indexu 0 pole a
a[7] = a[1] + 15;

/*--------------------------------------------------------------------*/

int i;
int a[10];
for (i = 0; i < 10; i++)	// naplnění pole pomocí cyklu
  a[i] = 2 * i;

/*--------------------------------------------------------------------*/

int matice[6][3];		// vícerozměrové pole a jeho naplnění
int i, j;

for (i = 0; i < 6; i++)
  for (j = 0; j < 3; j++)
    matice[i][j] = i + j;


/*******************************************************
 * UKAZATELÉ (pointery)
 *******************************************************/

int *p_i;       /* proměnná p_i je ukazatel na int */
void *p_v;      /* proměnná p_v je ukazatel na void */

/*-----------------------------------------------------*/

int i, j;	// dvě proměnné typu int
int *p_i;	// ukazatel na int */

i = 1;
p_i = &i;	// do p_i dáme adresu i
j = *p_i;	// j přiřadíme obsah paměti (chápaný jako int), na niž ukazuje p_i, tedy obsah i (1)

/*--------------------------------------------------------------------*/

void nula_spatne(int promenna) {
  promenna = 0;
}

void nula_dobre(int *p_promenna) {
  *p_promenna = 0;
}

int main(void) {
  int i = 1;
  nula_spatne(i);	// v i je pořád jedna
  nula_dobre(&i);	// teprve teď je v i nula
  return i;
}

/*******************************************************
 * PODMÍNKY A VěTVENÍ
 *******************************************************/

int i;

switch (i) {
  case 1:
   /* Blok 1 */
    break;
  case 2:
    /* Blok 2 */
    break;
  case 3:
    /* Blok 3 */
    break;
  default:
    /* Blok default */
    break;
}

/*******************************************************
 * CYKLY
 *******************************************************/

int i = 1;

while (i <= 10) {	// vyhodnocení podmínky a vykonání příkazů
  printf("%i\n", i);
  i++;
}

/*-------------------------------------------------*/

int i = 1;
do {
  i++;
  printf("%i\n", i);
} while (i <= 10);	// vykonání prvního cyklu, vyhodnocení podmínky a následovné opakování cyklu

/*-------------------------------------------------*/

int i;

for (i = 1; i <= 10; i++)
  printf("%i\n", i);

/*-------------------------------------------------*/

int i = 0;

while (1) {
  i++;
  if (i % 2 == 0) continue;	// nové započetí cyklu
  if (i >= 20) break;		// ukončení cyklu
  printf("%i ", i);
}

/*-------------------------------------------------*/

int i = 1;

zacatek_cyklu:
printf("%i\n", i);
i++;
if (i <= 10) goto zacatek_cyklu;

/*****************************************************************************************************************************
 * OPERÁTORY
 *****************************************************************************************************************************
 *
 * Operace	AND						OR						XOR						NOT
 * Operátor	Logický		Bitový		Logický		Bitový		Logický		Bitový		Logický	Bitový
 * 			&&			&			||			|			C nemá		^			!		~
 * Příklad dec	6 && 3	6 & 3		6 || 3		6 | 3		6 XOR 3		6 ^ 3		!6 	~6
 * Příklad bin	110 && 011	110 & 011	110 || 011	110 | 011	110 XOR 011	110 ^ 011	!110 	~110
 * Výsledek dec	1			2			1			7			0			5			0		4294967289
 * Výsledek bin	1			10			1			111			0			101			0		129001
 *
 ******************************************************************************************************************************/


/*********************************************************
 * FUNKCE printf()
 *********************************************************
 * %i, d	int, znaménkové číslo v desítkové soustavě
 * %o, u, x, X	unsigned, nezáporné celé číslo v osmičkové, desítkové, šestnáctkové (s ciframi abcd nebo ABCD) soustavě
 * %e	double, v exponenciální formě
 * %f	double, ve formě s desetinou tečkou
 * %c	int, zkonvertuje se na unsigned char reprezentující jeden znak
 * %s	const char *, nulou ukončený řetězec
 * %p	void *, adresa paměti, číslo v šestnáctkové soustavě
 * %lu	unsigned long
 *********************************************************
 * Příznak	Význam
 * #		Vypíše typ více explicitně.
 * 0		Zleva zarovnat nulami
 * -		Zprava zarovnat mezerami
 * mezera	Zleva zarovnat mezerami
 * +		Před číslem vždy znaménko
 *******************************************************/

int i = -125;
const char *s = "Nějaký text";
double d = 31.4159;

/* 1. Nejjednodušší příklad bez nepovinných parametrů, */
printf("Ahoj světe\n");

/* 2. který zvládne i funkce puts, ta navíc odřádkuje. */
puts("Ahoj světe");

/* 3. Výpis čísla typu int */
printf("Minus sto dvacet pět je %i\n", i);

/* 4. Zdvojení vypisovaného procenta */
printf("Jedeme na %i%%\n", 100);

/* 5. Výpis znaku, jeho ASCII kódu ve dvou soustavách */
printf("Znak '%c' má ASCII kód %i, šestnáctkově %x\n", 'm', 'm', (unsigned) 'm');

/* 6. Výpis řetězce, ukazatele a znaku */
printf("Řetězec s obsahuje \"%s\", je na adrese %p"
" a začíná písmenem '%c'\n", s, (const void *) s, (int) *s);

/* 7. Výpis reálných čísel */
printf("10 pi je asi %f, což se dá napsat i jako %e\n", d, d);

/* 8. Funkce printf vrací, kolik toho vytiskla. */
printf("Vnořená printf vypsala %i znaků\n", printf("12345\n"));

/*
  Výše uvedený kód nechá na výstupu:

   Ahoj světe
   Ahoj světe
   Minus sto dvacet pět je -125
   Jedeme na 100%
   Znak 'm' má ASCII kód 109, šestnáctkově 6d
   Řetězec s obsahuje "Nějaký text", je na adrese 0x8048540 a začíná písmenem 'N'
   Číslo pi je asi 31.415900, což se dá napsat i jako 3.141590e+01
   12345
   Vnořená printf vypsala 6 znaků

*/
/*-------------------------------------------------------------------------------*/
#include <stdio.h>
int main(void) {
  /* 1 */
  printf("Pro opakování: 1 = %i\n", 1);
  /* 2 */
  printf("255 = %#x = %x\n", 255, 255);
  /* 3 */
  printf("1 = %i = %10i = % 10i = %-10i = %010i\n", 1, 1, 1, 1, 1);
  /* 4 */
  printf("%+i = %i, %+i = %i\n", 1, 1, -1, -1);
  /* 5 */
  printf("%f, %.0f, %#.0f\n", 8.3, 9.7, 5.4);
  /* 6 */
  printf("Slepice dělá %-10.*s.\n", 6, "kokokodák");
  return 0;
}

/*
   Pro opakování: 1 = 1
   255 = 0xff = ff
   1 = 1 =          1 =          1 = 1          = 0000000001
   +1 = 1, -1 = -1
   8.300000, 10, 5.
   Slepice dělá kokoko
*/


/*********************************************************
 * INPUT / OUTPUT (I/O)
 *********************************************************/

char s[6] = {'k', 'r', 'á', 's', 'a', 0};

char s[6] = "krása";

/*-----------------------------------------------------------------*/

#include <stdio.h>
/* Bezpečná gets */
char * moje_gets(char *s, int size) {
  int i, c;

  /* Kvůli nule na konci řetězce */
  size--;
  /* Buffer velikosti <= 0 */
  if (size < 0) return NULL;
  for(i = 0; i < size; i++) {
    c = getchar();
    /* Konec vstupu nebo řádky */
    if (c == EOF || c == '\n') break;
    s[i] = (char) c;
  }
  /* Ukončovací 0 */
  s[i] = 0;
  /* Pokud došlo k chybě hned na začátku, vracím NULL. */
  if (!i && c == EOF) return NULL;
  /* Jinak vracím s. */
  return s;
}

int main(void) {
  char s[10];

  moje_gets(s, 10);
  puts(s);
  return 0;
}


/*-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char s[256];
  int i;

  fgets(s, 256, stdin);
  i = atoi(s);
  if (!i)
    puts("Chyba nebo nula");
  else
    printf("Korektně zadáno číslo %i\n", i);
  return 0;
}

/*-----------------------------------------------------------------*/

int i;
double f;
puts("Zadej jedno celé a jedno reálné číslo");
scanf("%i%lf", &i, &f);
printf("Zadal jsi %i a %f\n", i, f);

/*-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

 int main(void) {
  char s[256];
  long l;
  char *chyba;

  fgets(s, 256, stdin);
  l = strtol(s, &chyba, 10);
  if (chyba == s) {
    puts("Úplný nesmysl");
    return 1;
  }
  if (*chyba != '\n' && *chyba != 0) {
    puts("Za číslem byly ještě další znaky, nevadí.");
  }
  printf("Zadáno %i\n", (int) l);
  return 0;
}

/*-----------------------------------------------------------------*/

/* cc suma.c -o suma */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int suma = 0, i;
  char *chyba, *s;

  /* Pro všechny parametry kromě prvního */
  for (i = 1; i < argc; i++) {
    /* do s dej adresu i-tého řetězce */
    s = argv[i];
    /* přičti číslo do sumy */
    suma += (int) strtol(s, &chyba, 10);
    if (chyba == s) {
      /* číslo bylo úplně špatně */
      printf("Chyba: formát čísla %s\n", s);
      return 1;
    }
    if (*chyba)
      /* nebylo úplně špatně, jen nějaké znaky navíc */
      printf("Varování: divná znaky v čísle \"%s\" na pozici %i\n",
        s, chyba - s + 1);
  }
  printf("%i\n", suma);
  return 0;
}

