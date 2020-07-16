/*
Program		: kombin.c
Deskripsi	: imlementasi header kombin.h
Nama		: - Azzam Badruz zaman (191524037)
			  - Wafi Khaerun Nashirin (191524064)
Referensi	: 
Tanggal		: 5 juli 2020
Revisi		: 1
Compiler	: Dev C++
*/

#ifndef KOMBIN_C
#define KOMBIN_C

#include "kombin.h"
<<<<<<< HEAD


//ini jadi modu internal nbtree.c, gabisa di akses di main, buat rekursif tree
void kombin(char item[], int position, int idx,  nbtType *T, char kombi[]);
=======
//#include "nbtree.h"

//ini jadi modu internal nbtree.c, gabisa di akses di main, buat rekursif tree
void kombin(char item[], int position, int idx,  nbtType *T, char kombi[]);

>>>>>>> Origin/Azzambz

nbtType Generate() {
	puts("tst");
	char test[4]= "1234";	//misal dulu aja
    char kombinasi[4];
    memset(kombinasi, 0, sizeof(kombinasi));
	nbtType cektree= CreateNbt("NULL");	//root = NULL
	kombin(test, 0, 0, &cektree->fs, kombinasi);
	return cektree;
}

//nItem, startposition, T
void kombin(char item[], int position, int idx, nbtType *T, char kombi[]) {
	if(idx < strlen(item)) {		//konsepnya preorder
		char temp[strlen(item)];
		strcpy(temp, kombi);
		temp[position]= item[idx];
		*T= CreateNbt(temp);
		kombin(item, position+1, idx+1, &(*T)->fs, temp);
		kombin(item, position, idx+1, &(*T)->nb, temp);
	} 
}

<<<<<<< HEAD
=======



void kombin_levelorder(char penampung[], int position, int idx, nbtType *T);
void first_son(char penampung[], int position, int idx, nbtType *T);
void next_brother(char penampung[], int position, int idx, nbtType *T);
//kombinasi item menggunakan list dengan cara levelorder dan juga mengganti char menggunakan queue

nbtType Generate_levelorder(list *list) {
	puts("test levelorder");
	char penampung[10];
	int i=1,j=0;
	while(list[i].namaBarang != NULL){	//untuk menghitung jumlah item dalam list
		penampung[j]=i;
		i++;
	}
	queue asd;
	nbtType cektree= CreateNbt(asd);	//root = NULL
	kombin_levelorder(penampung, 0, 0, &cektree->fs);
	
	return cektree;
}



void kombin_levelorder(char penampung[], int position, int idx, nbtType *T) {
	if(idx < strlen(penampung)) {		//konsepnya preorder
		queue test;
		int i=0;
		while(i<idx+1){	//perulangan sebanyak index
			Insert(&test,penampung[i]); //untuk insert angka kedalam queue
			i++;
		}
		
		*T= CreateNbt(test);
		first_son(penampung, position+1, idx+1, &(*T)->fs);
		next_brother(penampung, position, idx+1, &(*T)->nb);
	} 
}


void first_son(char penampung[], int position, int idx, nbtType *T) {
	if(idx < strlen(penampung)) {		//konsepnya preorder
		queue test;
		int i=0;
		while(i<idx+1){ //perulangan sebanyak index
			Insert(&test,penampung[i]); //untuk insert angka kedalam queue
		}
		*T= CreateNbt(test);
		next_brother(penampung, position, idx+1, &(*T)->nb); //setelah first son dibuat lalu pergi ke next brother
		first_son(penampung, position+1, idx+1, &(*T)->fs); // lanjut lagi ke first son setelah next brother beres
	} 
}


void next_brother(char penampung[], int position, int idx, nbtType *T) {
	if(idx < strlen(penampung)) {		//konsepnya preorder
		queue test;
		int i=0; 
		while(i<idx+1){ //perulangan sebanyak index
			Insert(&test,penampung[position]); //untuk insert angka kedalam queue
			Insert(&test,penampung[i]); //untuk insert angka kedalam queue
			i++;
		}
		*T= CreateNbt(test);
		next_brother(penampung, position, idx+1, &(*T)->nb); //rekursif untuk next brother
	} 
}



>>>>>>> Origin/Azzambz
#endif
