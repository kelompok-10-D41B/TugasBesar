/*
Program		: kombin.h
Deskripsi	: header ADT untuk membuat kombinasi menggunaakn nbtree
Nama		: Azzam Badruz zaman
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
#define jml_barang 5
//percobaan bikin tree kombin
nbtType Generate();
nbtType Generate_levelorder(*list);

typedef struct {
	char * namaBarang;
} list;

//deklarasi
list barang[jml_barang];

#endif
