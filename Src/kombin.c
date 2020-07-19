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
#include <stdarg.h>
#include "kombin.h"
#include "list.h"



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

void levelordertraversal (nbtType *T,LIST asd,int b);
void check_string(nbtType *T,LIST asd,int b);

void check_string(nbtType *T,LIST asd,int b){
	int i=0;
	while((*T)->info[i] != '\0'){
	if((*T)->info[i] == '0'){
		strcat(asd[b].itemset,"susu");
	}else if((*T)->info[i] =='1'){
		strcat(asd[b].itemset,"roti");
	}else if((*T)->info[i] =='2'){
		strcat(asd[b].itemset,"keju");
	}else if((*T)->info[i] =='3'){
		strcat(asd[b].itemset,"coklat");
	}
		i++;
	}	
	printf("asd");

}
//LIST KOMBINASI
void levelordertraversal (nbtType *T,LIST asd,int b) {
	check_string(T,asd,b);
	while((*T)->nb !=NULL){
	levelordertraversal (&(*T)->nb,asd,b+1);
	}
	if((*T)->fs != NULL){
	levelordertraversal (&(*T)->fs,asd,b+1);
	}

	
}


#endif
