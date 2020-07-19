/*
Program		: kombin.h
Deskripsi	: header ADT untuk membuat kombinasi menggunaakn nbtree
Nama		: - Azzam Badruz zaman (191524037)
			  - Wafi Khaerun Nashirin (191524064)
Referensi	: 
Tanggal		: 4 juli 2020
Revisi		: 1
Compiler	: Dev C++
*/

#ifndef KOMBIN_H
#define KOMBIN_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "nbtree.h"
#include "queue.h"

typedef nbtType tries;	//untuk keperluar array of tries
typedef char ** item;	//untuk array of item /itemset
typedef char ** pembelian;	//data setiap transaksinya

void Generate();
/*	memulai proses pembuatan asociation rules  */

void kombin(char item[], int position, int idx,  nbtType *T, char kombi[]);
/*	membuat tree yang setiap node yang memiliki info yang berniali kombinasi*/

void levelordertraversal (nbtType T, tries arrayKombinasi[]);
/*	mengubah dari tree kombin, menjadi array of tries  */

int readTransactions(item *barang , int *nTransaksi, pembelian *pembelians);
/*	membaca file transaksi  */

void printItems(int numItems, char **items);
/*	menampilkan Items yang ada  */

int getStringIndex(char *string, int numItems, char **numitems)	;
/*	return index dari sebuah string  */

void MakeArrayTries(int nItem, tries arrayTries[]);
/*	proses membaut array of tries, tahap berjalan dengan memanggi fungsi lain*/

void countSupport(tries arrayTries[], pembelian pembelians, int n);
/*  menghitung support  */

void PrintKombinasi(tries arrayTries, item items, int idx);
/*	menampilkan semua kombinasi yang memungkin terjadi  */

#endif
