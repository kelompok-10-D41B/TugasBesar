/*
Program		: queue.h
Deskripsi	: Header ADT queue dinamis
Nama		: Azzam Badruz zaman
Tanggal		: 06/07/2020
Revisi		: 2
Compiler	: Dev C++
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "boolean.h"
#include "nbtree.h"

typedef nbtType infotypeQ;
typedef struct nodeQ *addrQ;
typedef struct nodeQ{
	infotypeQ info;
	addrQ next;
}nodeQ;

typedef addrQ qType;

/*	============================= KONSTRUKTOR =============================  */
qType InitQ();
/*	initialisasi awal queue
	IS: queue tidak terdefinisi
	Fs: terdefinisi, Q = NULL  */
	
addrQ AlokasiQ(infotypeQ info);
/*  return addrQ hasil alokasi, jika alokasi gagal
    maka akan return NULL  */

void DealokasiQ(addrQ deNode);
/*  melepas addrQ dari de_node  */

void EnQueue(qType *Q, infotypeQ info);
/*	membuat node berisi info lalu di masukkan kedalam
	queue Q, Q mungkin kosong, jika tidak kosong node baru
	masuk diurutan terakhir (konsep queue)  */

infotypeQ DeQueue(qType *Q);
/*	return info dari node paling awal dalam queue 
	lalu node tersebut di dealokasi (konsep queue)
	jika queue kosong maka terjadi underflow  */

/*	================================= GET ================================== */
qType GetEndofQ(qType Q);
/*	return end of queue  */

/*	=============================== PENGECEKAN ============================  */
boolean IsEmptyQ(qType Q);
/*  cek queue empty atau tidak, return boolean  */ 

/*  =============================== LAIN-LAIN ============================== */
void PrintQ(qType Q);
/*	menampilkan isi queue  */

void SortQ(qType *Q);
/*	mengurutkan isi queue secara ascending  */

#endif


