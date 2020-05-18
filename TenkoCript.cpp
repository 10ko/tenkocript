#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define versione "1.2.1"			//versione di tekoCript


void                                //prototipi  
	menu(),							//menu' principale
	menu2(),						//secondo menu' del programma *
	cript(),						//critta un messaggio    *
	decript(),						//decritta un messaggio   *
	help(),							//menu help   *
	credits(),						//credits    *
	exit(),							//messaggio di uscita
	input(char *mes,char *pass),	//aquisisce l'imput del messaggio e della pass
	output(char mess[]);			//ritorna un output del messaggio alaborato sia su file che su schermo
					
char
      tab[94][94] = 
      {                                          //tabella massiccia!!
" aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()",
"aaAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()",
"AAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()a",
"bbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aA",
"BB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAb",
"!!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB",
"$$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!",
"ccC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$",
"CC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$c",
"11dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC",
"ddD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1",
"DD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1d",
";;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD",
"eeE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;",
"EE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;e",
"22fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRìsS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE",
"ffF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2",
"FF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2f",
"&&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRìsS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF",
"ggG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&",
"GG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&g",
"::hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG",
"hhH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:",
"HH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:h",
"++3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH",
"33iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+",
"iiI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3",
"II*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3i",
"**jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI",
"jjJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*",
"JJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*j",
"44kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ",
"kkKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4",
"KKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4k",
"llL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kK",
"LL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKl",
"££<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL",
"<<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£",
"55 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<",
"  _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5",
"__-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 ",
"--mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _",
"mmM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-",
"MM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-m",
"66/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM",
"//nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6",
"nnN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/",
"NN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/n",
"||7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN",
"77.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|",
"..oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7",
"ooO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.",
"OO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.o",
"==p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO",
"pp8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=",
"88PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p",
"PPqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8",
"qqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8P",
"QQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8Pq",
">>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ",
"^^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>",
"##9rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^",
"99rRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#",
"rrRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9",
"RRì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9r",
"ìì?sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rR",
"??sS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì",
"ssS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?",
"SS0,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?s",
"00,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS",
",,tTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0",
"ttTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,",
"TTuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,t",
"uuU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tT",
"UU@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTu",
"@@vVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU",
"vvVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@",
"VVòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@v",
"òòùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vV",
"ùùwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVò",
"wwWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòù",
"WWàxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùw",
"ààxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwW",
"xxXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWà",
"XXyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàx",
"yyYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxX",
"YYzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXy",
"zzZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyY",
"ZZèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYz",
"èèé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZ",
"éé()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZè",
"(()aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé",
"))aAbB!$cC1dD;eE2fF&gG:hH+3iI*jJ4kKlL£<5 _-mM6/nN|7.oO=p8PqQ>^#9rRì?sS0,tTuU@vVòùwWàxXyYzZèé(",

	};
	char risp=0;
int main()
{     

      system("cls");
      cout << "\t\t\tBenvenuto in TeNkOcript ver. "versione;
      cout << "\n\n\n";
      menu();
      return 0;
}

void input(char *mes,char *pass)
{

	system("cls");
	cout<<"\nPrego, inserisci la tua parola chiave (max 10 caratteri): ";
	while(cin.get()!='\n');
    cin.getline(pass,10);

	cout<<"\nPremi: \n-1 se vuoi inserire il messaggio da tastiera;\n-2 se e' contenuto su un file\n";
	cin>>risp;
	switch(risp)
	{
	case'1':
		cout<<"\nOra inserisci il messaggio da elaborare: (max 200 caratteri): ";
		while(cin.get()!='\n');
		cin.getline(mes,200);

	break;
	case'2':
		char indirizzo[100];
		FILE *instream;
		while(1)
		{		
			for(int i=0;i<100;i++)
				indirizzo[i]=NULL;
			cout<<"\nInserisci l'indirizzo del file:\n";
			while(cin.get()!='\n');
			cin.getline(indirizzo,100);
			if(instream=fopen(indirizzo,"r"))
				break;
			printf("\nl'indirizzo non e' corretto!!\n");

		}
		fread(mes,sizeof(char),200,instream);

		fclose(instream);
	}
}
void output(char mess[])
{	
	cout<<"\nIl messaggio elaborato e':";
	cout<<mess;
	cout<<"\nPremere\n-1 se vuoi salvare il messaggio\n-2 per andare avanti\n";
	cin>>risp;
	if(risp=='1')
	{
		FILE *outstream;
		char indirizzo[100];
		
		while(1)
		{
			for(int i=0;i<100;i++)
				indirizzo[i]=NULL;
			printf("\nInserisci l'indirizzo del file:\n");
			while(cin.get()!='\n');
			cin.getline(indirizzo,100);			
			if(outstream=fopen(indirizzo,"w"))
				break;
			printf("\nIndirizzo errato!\n");

		}

		fprintf(outstream,"%s",mess);
        fclose(outstream);
	}
}




void menu()
{
      
      cout<<"\nPrego, ora effettua una scelta..";
      cout<<"\n(1) -Critta messaggio";
      cout<<"\n(2) -Decritta messaggio";
      cout<<"\n(3) -Help";
      cout<<"\n(4) -Credits";
      cout<<"\n(5) -Exit\n\t";
      cin>>risp;
      
      switch(risp){
            case '1':
            cript();
            break;
            case '2':
            decript();
            break;
            case'3':
            help();
            break;
            case '4':
            credits();
            break;
            case '5':
            exit();
            break;
            default:
 
			main();

      }
}

void help()
{
      system("cls");
      cout<<"\t\tBenvenuto nell'help menu' di TeNkOcript ver. "versione;
      cout<<"\n";
      cout<<"\nCosa si puo fare con questo programma?";
      cout<<"\nQuesto e' un programma che ci permette di scrivere una parola chiave e con questa cifrare un messaggio, che potremo ritradurre solamente conoscendo la parola chiave";
      cout<<"\n\nQuesto programma e' case-sensitive?";
      cout<<"\nPer il momento si, a breve uscira' la versione successiva, e' gia' in lavorazione... =)";
      cout<<"\n\nCosa posso fare se mi si impalla?";
      cout<<"\nSe sei su una shell linux premi ctrl+c altrimenti in windows chiudi la finestra del prompt";
      cout<<"\n\n\nNon mi vengono in mente altre domande a cui rispondere, percio' credo sia tutto..";
      menu2();
}





void credits()
{
      system("cls");
      cout<<"\t\t\t\tTeNkOcript ver. "versione;
      cout<<"\n\t\t\t\t\t2006";
      cout<<"\n\n\n\n\t\t\tSource by Emanuele Libralato";
      cout<<"\n\t\t\tDa un idea di Davide Spagnuolo";
      menu2();
}

void menu2()
{
      char risp=0;
      cout<<"\n\n\n\n\n\n\nDesideri: (1)-Tornare al menu' principale o (2)-Uscire dal programma?   ";
      cin>>risp;
      switch(risp){
            case '1':
            main();
            break;
            case '2':
            exit();
            break;
            default:
            cout<<"\nHai inserito un carattere errato, riprova..";
            menu2();
            break;
      }
}

void exit()
{
      cout<<"\n\n\n\t\t\tGrazie per aver usato TeNkOcript ver. "versione;
      cout<<"\n\n\t\t\t\t\t\t\t\tArrivederci!";
}

void cript()
{
      int i,a=0,b=0,c=0,j=0,control=0;      //contatori vari... -_-''
      char chiave[10],mess[200],chiave_[200],mess_cript[200];

			for(i=0;i<10;i++)				//azzeramento stringhe
   				chiave[i]='\0';    
			
            for(i=0;i<200;i++)
            {

                  mess[i]='\0';                
                  chiave_[i]='\0';
                  mess_cript[i]='\0';		//fine azzeramento stringhe
            }

	  input(mess,chiave); 
      
      c=0;
      for(i=0;mess[i]!='\0';i++)            
                  c++;            
      
      control=0;                               
      for(i=0;i<10;i++){
            if(chiave[i]!='\0')
                  control++;
      }                                   //creazione chiave ripetuta
      b=0;
      for(i=0;mess[i]!='\0';i++)
            {
                  if(b==control)
                        b=0;
                  chiave_[i]=chiave[b];
                  b++;
            }

      for(i=0;mess[i]!=0;i++){
            a=0;
            for(j=0;j<94;j++){
                  if(mess[i]==tab[0][j])
                        a=j;
            }
            b=0;                                //crittaggio
            for(j=0;j<94;j++){                        
                  if(chiave_[i]==tab[j][0])
                        b=j;
            }
            mess_cript[i]=tab[b][a];
      }            
      
	  output(mess_cript);
      menu2();
}

void decript()
{
      int i=0,a=0,b=0,y=0,j=0,control=0;      //contatori vari... -_-''
      char chiave2[10],mess2[200],chiave_2[200],mess_decript2[200];
      

			for(i=0;i<10;i++)				//azzeramento stringhe
                  chiave2[i]='\0';
			
            for(i=0;i<200;i++)
            {
                  mess2[i]='\0';                
                  chiave_2[i]='\0';
                  mess_decript2[i]='\0';		//fine azzeramento stringhe
            }

	  input(mess2,chiave2);
	  
      control=0;
      for(i=0;i<10;i++){
            if(chiave2[i]!='\0')
                  control++;
      }
      b=0;                                //creazione chiave ripetuta...
      for(i=0;mess2[i]!='\0';i++){
            
                  if(b==control)
                        b=0;
                  chiave_2[i]=chiave2[b];
                  b++;
            
      }      
      
      for(i=0;mess2[i]!=0;i++){
		for(j=0;j<94;j++){
		if(chiave_2[i]==tab[j][0])
			b=j;
		}
                                                 //decrittaggio
		for(a=1;a<94;a++){
        if(tab[b][a]==mess2[i])
		mess_decript2[i]=tab[0][a];
		}            
      }          

	output(mess_decript2);
    menu2();

}

