#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define nil NULL
#define info(P)  (P)->info
#define no(P)    (P)->no
#define next(P)  (P)->next
#define first(L) (L).first

typedef int infotype;

typedef struct tElmList *address;

typedef struct tElmList{
	    infotype info;
	    int      no;
	    address next;
}ElmList;

/*
typedef struct{
	    address first;
}List;
*/

void CreateList(address *L);
address Alokasi(infotype x, int no);
void AddFirst(address *L, infotype x, int no);
void CetakList(address L);
address CariElm(address L, infotype x);

//address CariElm(List L, int x);

int main(){
    address MyList;
    address Px;
    int N;
    int No;
    
    CreateList(&MyList);
    
    printf("Masukan Bilangan :");scanf("%d", &N);
    No=0;
    while(N!=999){
    	No++;
    	AddFirst(&MyList, N, No);
    	printf("Masukan Bilangan :");scanf("%d", &N);
	}
    CetakList(MyList);
    
    printf("\nMasukan Elemen dicari :");scanf("%d", &N);
    Px = CariElm(MyList, N);
    if(Px!=nil)
    	printf("Ditemukan di : %d", no(Px));
	else
	    printf("Tidak Ada...!");
    
    return 0;
}


void CreateList(address *L){
	*L = nil;
}

address Alokasi(infotype x, int no){
	address P;
	
	P = (address) malloc(sizeof(ElmList));
	if(P!=nil){
		info(P) = x;
		no(P) = no;
		next(P) = nil;
	}
	  
	return P;
}

void AddFirst(address *L, infotype x, int no){
	address Px;
	
	Px = Alokasi(x, no);
	next(Px) = *L;
	*L = Px;
}

void CetakList(address L){
	 if(L!=nil){
	 	printf("<%d>",info(L));
	 	CetakList(next(L));
	 }
}

address CariElm(address L, infotype x){
	if(L == nil)
	   return nil;
	else{
		if(info(L) == x)
		   return L;
		else
		   return CariElm(next(L), x);   
	}   
}
