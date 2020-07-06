/*
Program		: kombin.c
Deskripsi	: imlementasi header kombin.h
Nama		: Azzam Badruz zaman
			  Wafi Khaerun Nashirin
Referensi	: 
Tanggal		: 5 juli 2020
Revisi		: 1
Compiler	: Dev C++
*/

#ifndef KOMBIN_C
#define KOMBIN_C

#include "kombin.h"


//ini jadi modu internal nbtree.c, gabisa di akses di main, buat rekursif tree
void kombin(char item[], int position, int idx,  nbtType *T, char kombi[]);

/*
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

*/

//kombinasi item menggunakan list dengan cara levelorder dan juga mengganti char menggunakan queue
nbtType Generate_levelorder(*list) {
	puts("test levelorder");
	int i=0;
	while(list[i]->namaBarang != NULL){
		char penampung [i]=i+1;
		i++;
	}
	nbtType cektree= CreateNbt("NULL");	//root = NULL
	queue antri;
	kombin_levelorder(penampung, 0, 0, &cektree->fs, antri);
	
	return cektree;
}

void kombin_levelorder(char penampung[], int position, int idx, nbtType *T, queue test);
void kombin_levelorder(char penampung[], int position, int idx, nbtType *T, queue test) {
	if(idx < strlen(penampung)) {		//konsepnya preorder
	/*
		char temp[strlen(penampung)];
		strcpy(temp, test->data);
		temp[position]= item[idx];
		*/
		int i=0;
		while(i<idx+1){
			Insert(&test,penampung[i]);
			i++;
		}
		*T= CreateNbt(test);
		first_son(item, position+1, idx+1, &(*T)->fs, test);
		next_brother(item, position, idx+1, &(*T)->nb, test);
	} 
}
void first_son(char penampung[], int position, int idx, nbtType *T, queue test);
void first_son(char penampung[], int position, int idx, nbtType *T, queue test) {
	if(idx < strlen(penampung)) {		//konsepnya preorder
	
		int i=0;
		while(i<idx+1){
			Insert(&test,penampung[i]);
		}
		*T= CreateNbt(test);
		first_son(item, position+1, idx+1, &(*T)->fs, temp);
	} 
}
void next_brother(char penampung[], int position, int idx, nbtType *T, queue test);
void next_brother(char penampung[], int position, int idx, nbtType *T, queue test) {
	if(idx < strlen(penampung)) {		//konsepnya preorder

		int i=0;
		while(i<idx+1){
			Insert(&test,penampung[position]);
			Insert(&test,penampung[i]);
			i++;
		}
		*T= CreateNbt(test);
		next_brother(item, position, idx+1, &(*T)->nb, temp);
	} 
}



#endif
