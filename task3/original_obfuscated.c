#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define lllllll 3
#define llllllll 5

char *iii(char *lllll)
{
if (strlen(lllll) != lllllll*llllllll + 2){return NULL;}int ll = (int)2[lllll];size_t llllll = lllllll*llllllll*sizeof(char);
char *llll = (char *)malloc(llllll);if (ll)
{
goto lll;}
l:
if (llll == NULL){
lllllllll:
return NULL;
}memset(llll, '\0', llllll);

int j = 0;for(int i = 0; i < strlen(lllll); i++)
{
if (lllll[i] != '-'){llll[j++] = lllll[i];}
}return llll;
lll:{}
if (ll == *(lllll+ 2))
goto l;
else
goto lllllllll;
return NULL;
}

int iiii(char *lllll){if (lllll == NULL){return -1;}

int l = 0;
int ll = 0;
int lll = 0;
int llll = 0;

int tmp = 0;
int tmp1 = 0;for(int i = 0; i < lllllll; i++)
{
for(int j = 0; j < llllllll; j++)
{
if (lllll[llllllll * i + j] < 91)
l += lllll[llllllll * i + j];
else
ll += lllll[llllllll * i + j];
}

tmp = ((l>>2)&0xF);
tmp1 = (ll + 1)&0x7;

if (tmp == tmp1){lll += l;}
else{llll += ll;}}

if (lll == llll && lll != 0)return 0;return -1;}

int main(int argc, char **argv){char *llll = NULL;
if (argc != 2){
printf("Необходимо ввести 2 аргумента - ключ в формате xxxxx-xxxxx-xxxxx.\n");printf("Например: `%s GwS9t-2HSx2-gxVBc`\n", argv[0]);return -1;
}
else{
llll = iii(argv[1]);}
if (iiii(llll) != 0){printf("Неверный ключ!\n");return -1;}printf("Программа активирована.\n"); return 0;
}
