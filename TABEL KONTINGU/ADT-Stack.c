/*program adtstack.c
nama: Moch. Rizki Kurniawan
Nim :3411191151
date :20/04/2020
desc :Adt Stack
*/

//preprosesor
#include<conio.h>
#include<stdio.h>

#define nMak 10
//pembentukan type
typedef struct {
	int info;
}ElmStack;

typedef struct{
	ElmStack Ts[nMak +1];
	int TOP;
}Stack;
//prototype
void CreateStack(Stack *S);
void Push(Stack *S, int x);
void Pop(Stack *S, int *y);
void CetakStack(Stack S);

//main driver
int main(){
//kamus
	Stack MyStack;
	
	int N;
//algoritma
	CreateStack(&MyStack);
	
	printf("Masukan Bilangan :") ; scanf("%d", &N);
	while(N!=999){
		Push(&MyStack, N);
		printf("Masukan Bilangan :") ; scanf("%d", &N);
	}
	
	CetakStack(MyStack);
	Pop(&MyStack, &N);
	CetakStack(MyStack);
	printf("Elemen di Pop : %d", N);
	
	return 0;

}
//realisasi prototype
void CreateStack(Stack *S){
	(*S).TOP = 0;
}
void Push(Stack *S, int x){
	if((*S).TOP < nMak){
		(*S).TOP--;
		(*S).Ts[(*S).TOP].info = x;
	}
}
void Pop(Stack *S, int *y){
	if((*S).TOP != 0){
		*y = (*S).Ts[(*S).TOP].info;
		(*S).TOP--;
	}
}
void CetakStack(Stack S){
	int i;
	
	i = S.TOP;
	while(i>=1){
		printf("<%d>", S.Ts[i].info);
		i--;
	}
	printf("\n");
}


