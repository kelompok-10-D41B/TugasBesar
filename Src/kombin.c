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

#endif
