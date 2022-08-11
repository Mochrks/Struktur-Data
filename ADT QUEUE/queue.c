/*
	Program   : main.c
	Author    : Moch Rizki Kurniawan / <3411191151>
	Kelas     : E
	Deskripsi : ADT queue
*/
//preprosesor
//#include <windows.h> 
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include <windows.h>

#define nil 0
#define maks 10
#define undef -999

#define head(q) (q).head
#define tail(q) (q).tail
#define infohead(q) (q).t[(q).head]
#define infotail(q) (q).t[(q).tail]
//pembentukan tipe
typedef int infotype; 

typedef int address;

typedef struct{
	int abs;
	int ord;
}point;

typedef struct{
	infotype t[maks+1];
	address head;
	address tail; 
}queue;
//prototype
void createqueue(queue *q);
void addqueue(queue *q, int x, int y);
void delqueue(queue *q, infotype *x);
void cetakqueue(queue q);


//main driver
int main(){
	
	//Kamus Data
	queue q;
	point mypoint;
	int x,y ,N;
	//algoritma
	createqueue(&q);
	while (N!=999){
	
		
		printf("Masukkan x\t= "); scanf("%d", &x);
		printf("Masukkan y\t= "); scanf("%d", &y);
		
	}
	
	
	
	
	
	
	
}



















// realisaasi prototype

void createqueue(queue *q){
	//Kamus
	
	//Algoritma
	head(*q) = nil;
	tail(*q) = nil;
}

