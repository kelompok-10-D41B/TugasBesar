/*
Program		: nbtree.h
Deskripsi	: Header ADT non binary tree
Nama		: Azzam Badruz zaman
Referensi	: ADT nbtree saiful
Tanggal		: 3 juli 2020
Revisi		: 4
Compiler	: Dev C++
*/

#ifndef NBTREE_H
#define NBTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*	============================== DEKLARASI ==============================  */
typedef char infotypeNbt;
typedef struct nodeNbt *addrsNbt;
typedef struct nodeNbt{
	infotypeNbt info;
	addrsNbt pr;  //parent
	addrsNbt fs;  //firstson
	addrsNbt nb;  //nextbrother
}nodeNbt;

typedef addrsNbt nbtType;

/*	============================= KONSTRUKTOR =============================  */
addrsNbt AlokasiNbt(infotypeNbt X);
/*	return address hasil alokasi yang bernilai X, jika alokasi gagal artinya 
	memori pernuh maka return NULL  */

void DealokasiNbt(addrsNbt X);
/*	melepass address pada node*/

nbtType CreateNbt(infotypeNbt X);
/*	inisialisasi, return non binary tree yang berisi 1 node X (sebagai root)  */

void InsertNbt(nbtType *T, infotypeNbt pr, infotypeNbt X);
/*	add newnode yang bernilai X pada Nbtree T, T tidak mungkin kosong karena 
	T sudah terisi minimal 1 node saat CreatNbt, newnode bernilai X di add 
	sebagai anak dari node yang bernilai pr  */

/*	=============================== SEARCH ================================= */
addrsNbt SearchNodeNbt(nbtType T, infotypeNbt X);
/*	jika ditemukan return address node yang bernilai X, jika tidak ditemukan
	return NULL  */

/*	=============================== PENGECEKAN ============================  */
boolean IsEmptyNbt(nbtType T);
/*	return true jika T NULL, return false jika T tidak NULL*/

/*	============================ TRAVERSAL ================================  */
void Postorder(nbtType T);
void Preorder(nbtType T);
void Inorder(nbtType T);

/*  ================================= PRINT ================================ */
void PrintNbt(nbtType T);
/*	menampilkan visuali dari nbt T*/

#endif

