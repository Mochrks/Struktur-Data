/*program adtstack.c
nama: Moch. Rizki Kurniawan
Nim :3411191151
date :20/04/2020
desc :Adt Stack
*/

//preprosesor
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define TOP(S) (S).TOP
//pembentukan type
typedef struct tElmlist *address;
typedef struct tElmlist {
	int info;
	address next;
}ElmStack;
typedef struct {
	address TOP;
}Stack;
//prototype
void CreateList(Stack *S);
void Push(Stack *S, int X);
void Pop(Stack *S, int *Y);
void CetakStack(Stack S);
address Alokasi(int X);
void DeAlokasi(address *P);
//main driver
int main() {
//kamus
	Stack MyStack;
	int input,out,menu;
//algoritma
	CreateList(&MyStack);
	while(menu != 3){
		printf("Daftar Menu : \n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Keluar\n");
		printf("\n");
		CetakStack(MyStack);
		printf("\n");
		printf("\n");
		printf("Masukan Menu : ");scanf("%d", &menu);
		printf("\n");

		switch(menu){
			case 1:
				printf("Masukan Angka 999 Untuk Keluar \n");
				printf("Masukan Bil : ");scanf("%d", &input);
				while(input!=999){
					Push(&MyStack, input);
					printf("Masukan Bil : ") ; scanf("%d", &input);
				}
				system("cls");
			break;

			case 2:
				Pop(&MyStack,&out);
			break;

			case 3:
			break;

			default:
				system("cls");
				printf("\nMenu Salah !!\n\n");
			break;
		}
	}
	printf(" Sudah Keluar\n");
	return 0;

}
//realisasi prototype
void CreateList(Stack *S){
	TOP(*S)=nil;
}

void Push(Stack *S, int X){
	//kamus
	address Px,awal;
	//algoritma
	awal = TOP(*S);
	if (awal!=nil) {
		while (next(awal) != nil){
			awal = next(awal);
		}
		Px = Alokasi(X);
		next(awal) = Px;
	} else {
		Px = Alokasi(X);
		next(Px) = TOP(*S);
		TOP(*S) = Px;
	}
}

void Pop(Stack *S, int *Y){
	
	 /* Kamus Lokal */
	  address awal, Sawal;

	  /* Algoritma */
	  awal = TOP(*S);
	  Sawal = nil;
		  while (next(awal) != nil) {
		    Sawal = awal;
		    awal = next(awal);;
		  }
	  	*Y = info(awal);
	  if (Sawal == nil) {
	    TOP(*S) = nil;
	  } else {
	    next(Sawal) = nil;
	  }
}

void CetakStack(Stack S){
	//kamus
	address awal,Px;
	// algoritma
	awal = TOP(S);
	if (awal!=nil) {
		while (awal!=nil) {
			printf("<%d> ",info(awal));
			awal = next(awal);
		}
	} else {
		printf("element kosong");
	}
}

address Alokasi(int X){
	//kamus
	address P;
	// algoritma
	P = (address) malloc(sizeof(ElmStack));
	if (P!=nil) {
		info(P) = X;
		next(P) = nil;
		return P;
	} else {
		printf("Alokasi Gagal");
		return(nil);
	}
}

void DeAlokasi(address *P){
	free(*P);
}
