/*
	Program	 adtqueue.c
	Author	: <3411191151>/<Moch Rizki Kurniawan>
	Date	: 5 Mei 2020
	Desc	: ADT Queue
*/
//preprosesor
#include <windows.h> 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define nil NULL
#define info(p) (p)->info
#define next(p) (p)->next

#define head(s) (s).head
#define tail(s) (s).tail

//pembentukan type
typedef struct {
	int abs,ord;
}point;

typedef struct {
	point awal,akhir;
}garis;

typedef struct telmqueue *address;

typedef struct telmqueue{
	garis info;
	address next;
}elmqueue;

typedef struct{
	address head;
	address tail;
}queue;

//prototype
void createqueue(queue *q);
address alokasi(garis x);
void dealokasi(address p);
void addqueue(queue *q, garis x);
void delqueue(queue *q, garis *x);
void cetakqueue(queue q);

int main(){
	
	//Kamus Data
	int pil;
	garis input, out;
	queue q;
		
	//Algoritma
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
				printf("Masukkan Titik Awal (x y): ");scanf("%d%d", &input.awal.abs,&input.awal.ord);
				printf("Masukkan Titik Akhir (x y): ");scanf("%d%d", &input.akhir.abs,&input.akhir.ord);
				addqueue(&q, input);
				system("cls");
			break;
		
			case 2:
				delqueue(&q, &out);
				system("cls");
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
						
	return 0;
}

//realisasi prototype
void createqueue(queue *q){
	head(*q) = nil;
	tail(*q) = nil;
}


address alokasi(garis x){
	//Kamus
	elmqueue *p;
	
	//Algoritma
	p = (elmqueue*)malloc(sizeof(elmqueue));
	if(p != nil){
		info(p) = x;
		next(p) = nil;
		return p;
	} else {
		return nil;
	}
}

void dealokasi(address p){
	free(p);
}


void addqueue(queue *q, garis x){
	//Kamus
	address p;
	elmqueue *t;
	
	//Algoritma
	p = alokasi(x);
	t = tail(*q);
	if (head(*q)==nil) {
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

void delqueue(queue *q, garis *g){
	address awal;
	awal=head(*q);
	*g=info(awal);
	if(next(awal)==nil){
		head(*q) = nil;
		tail(*q) = nil;
	}else
		head(*q)=next(awal);
	dealokasi(awal);
}

void cetakqueue(queue q){
	//Kamus
	elmqueue *p;
	
	//Algoritma
	if(head(q)!=nil){
		p = head(q);
		while (p != nil){
			printf(" [P1(%d,%d) , P2(%d,%d)]", info(p).awal.abs, info(p).awal.ord,info(p).akhir.abs,info(p).akhir.ord);
			p = next(p);
		}
	} else {
		printf("[ Empty ]");
	}
}



