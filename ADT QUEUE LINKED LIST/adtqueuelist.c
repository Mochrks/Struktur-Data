/* 	Program adtqueue.c
	Nama`	:Moch.Rizki Kurniawan
	NIM		:3411191151
	Date	: 4/3/2020
	Desc	: Adt queue linked list
*/

//prepocessor
#include <windows.h> 
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define nil NULL
#define info(p) (p)->info
#define next(p) (p)->next

#define head(s) (s).head
#define tail(s) (s).tail


//pembentukan type
typedef struct{
	int abs;
	int ord;
}point;
typedef struct{
	point a;
	point b;
}garis;
typedef struct telmqueue *address;

typedef struct telmqueue{
	int info;
	address next;
}tabqueue;

typedef struct{
	address head;
	address tail;
}queue;

//prototype
void createqueue(queue *q);
address alokasi(int x);
void dealokasi(address p);
void addqueue(queue *q, int x);
void delqueue(queue *q, int *x);
void cetakqueue(queue q);
boolean isqueueempty(queue q);

//main driver
int main(){

	//kamus
	int pil;
	int input, out;
	queue q;
	int i,x1,y1,x2,y2;
	
	
	//algoritma	
	
	
	createqueue(&q);
	while(pil != 4){		
	
		printf("===========================\n");
		printf("| ADT Queue [Linked List] |\n");
		printf("===========================\n");
		printf("\n");
		printf("Daftar Pilihan : \n");
		printf("1. Add Queue\n");
		printf("2. Delete Queue\n");
		printf("3. Reset\n");
		printf("4. Exit\n");
		
		printf("\n");

		cetakqueue(q);
		printf("\n");
		printf("\n");
	
		printf("Masukan pilihan : ");scanf("%d", &pil);
		printf("\n");
		
		switch(pil){	
			
			case 1:
				printf("Masukan Angka : ");scanf("%d", &input);
				addqueue(&q, input);
				system("cls");
			break;
		
			case 2:
				if(isqueueempty(q)){
					printf("\n");
					printf("Stack Kosong !!\n\n");
					getch();
					createqueue(&q);
					system("cls");
				} else {
					delqueue(&q, &out);
					system("cls");
				}
			break;
			
			case 3:
				createqueue(&q);
				system("cls");
			break;
			
			case 4:
				
			break;
			
			default:
				printf("Pilihan tidak valid !!\n\n");
				getch();
				system("cls");
			break;	
		}		
	}
	
	printf("Terima Kasih %c \n",1);						
	return 0;
}


//realisasi prototype
void createqueue(queue *q){
	
	//Kamus
	
	//Algoritma
	head(*q) = nil;
	tail(*q) = nil;
}

address alokasi(int x){

	//Kamus
	tabqueue *p;
	
	//Algoritma
	p = (tabqueue*)malloc(sizeof(tabqueue));
	if(p != nil){
		info(p) = x;
		next(p) = nil;
		return p;
	} else {
		return nil;
	}
}

void dealokasi(address p){

	//Kamus
	
	//Algoritma
	free(p);
}

void addqueue(queue *q, int x){
	//Kamus
	address p;
	tabqueue *t;
	
	//Algoritma
	p = alokasi(x);
	t = tail(*q);
	if (isqueueempty(*q)) {
		next(p) = head(*q);
		next(p) = tail(*q);
		head(*q) = p;
		tail(*q) = p;
	} else {
		while (next(t) != nil){
			t = next(t);
		}
		next(t) = p;
		(*q).tail = p;
	}
}

void delqueue(queue *q, int *x){

	//Kamus
	
	//Algoritma	
	if(head(*q)->next != nil){		
		*x = head(*q)->info;
		head(*q) = head(*q)->next;
		dealokasi(head(*q));
	} else {
		createqueue(&(*q));
	}
}

void cetakqueue(queue q){

	//Kamus
	tabqueue *p, *s;
	
	//Algoritma
	if(!isqueueempty(q)){
		p = head(q);
		while (p != nil){
			printf(" [ %d ]", info(p));
			p = next(p);
		}
	} else {
		printf("[ Empty ]");
	}
}

boolean isqueueempty(queue q){
	//Kamus
	
	//ALgoritma
	if(head(q) == nil || tail(q) == nil){
		return 1;
	} else {
		return 0;
	}	
}
