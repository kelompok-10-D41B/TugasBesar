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

#define jml_barang 5
typedef struct {
	char * kombinasi;
	int support;
} kombinType;

typedef qType qKombin;

//percobaan bikin tree kombin
nbtType Generate();

//deklarasi
list barang[jml_barang];

nbtType Generate_levelorder(list *barang);

#endif
