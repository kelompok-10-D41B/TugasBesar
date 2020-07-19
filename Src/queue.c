/*
Program		: queue.c
Deskripsi	: Implemetasi dari header queue.h
Nama		: Azzam Badruz zaman
Tanggal		: 06/07/2020
Revisi		: 2
Compiler	: Dev C++
*/
#ifndef QUEUE_C
#define QUEUE_C

#include "queue.h"

/*	============================= KONSTRUKTOR =============================  */
qType InitQ() {
/*	initialisasi awal queue
	IS: queue tidak terdefinisi
	Fs: terdefinisi, Q = NULL  */
	    
	qType Q;
	
	Q= NULL;
	return Q;
}


addrQ AlokasiQ(infotypeQ info) {
/*  return addrQ hasil alokasi, jika alokasi gagal
    maka akan return NULL  */
    
	addrQ newNode= (addrQ)malloc(sizeof(nodeQ));
	
	if(newNode != NULL) {
		newNode->info= info;
		newNode->next= NULL;
		return newNode;
	} else {
		printf("memori penuh\n");
	}
}

void DealokasiQ(addrQ deNode) {
/*  melepas addrQ dari de_node  */

	deNode->next= NULL;
	free(deNode);
}


void EnQueue(qType *Q, infotypeQ info) {
/*	membuat node berisi info lalu di masukkan kedalam
	queue Q, Q mungkin kosong, jika tidak kosong node baru
	masuk diurutan terakhir (konsep queue)  */
	addrQ newNode;
	newNode= AlokasiQ(info);
	
	if(IsEmptyQ(*Q)) {		//end of queue
		*Q= newNode;
	} else {
		qType temp= GetEndofQ(*Q);
		temp->next= newNode;
	}
//	PrintQ(*Q);
}

infotypeQ DeQueue(qType *Q) {
/*	return info dari node paling awal dalam queue 
	lalu node tersebut di dealokasi (konsep queue)
	jika queue kosong maka terjadi underflow  */
	
	if(IsEmptyQ(*Q)) {
		printf("\n--- underflow ---\n");
		return;
	}
	
	addrQ temp;
	infotypeQ X;
	
	temp= *Q;
	X= temp->info;
	*Q= (*Q)->next;
	DealokasiQ(&(*temp));
	return X;
}

/*	================================= GET ================================== */
qType GetEndofQ(qType Q) {
/*	return end of queue  */
	if(!IsEmptyQ(Q->next)) {
		return GetEndofQ(Q->next);
	}
	
	return Q;
}

/*	=============================== PENGECEKAN ============================  */
boolean IsEmptyQ(qType Q) {
/*  cek queue empty atau tidak, return boolean  */ 

	return (Q == NULL); 
}

/*  =============================== LAIN-LAIN ============================== */
void PrintQ(qType Q) {
/*	menampilkan isi queue  */
	while(!IsEmptyQ(Q)) {
		printf("%d ", Q->info);
		Q= Q->next;
	}
}

void sortQ(qType *Q){
/*	mengurutkan isi queue secara ascending  */

	if(!IsEmptyQ(*Q)) {
		addrQ temp, current;
		infotypeQ swap;
		current= *Q;
		temp= NULL;
		
		while(current->next!=temp) {
			while(current->next!=temp) {
				if(current->info>current->next->info) {
					swap= current->info;
					current->info= current->next->info;
					current->next->info= swap;
				}
				current= current->next;
			}
			temp= current;
			current= *Q;
		}
		
	} else{
		printf("\nerror");
	}
}

#endif
