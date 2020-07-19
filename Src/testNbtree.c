/*
Program		: main.c
Deskripsi	: test header nbtree.h
Nama		: Azzam Badruz zaman
Referensi	: ADT nbtree saiful
Tanggal		: 
Revisi		: 
Compiler	: Dev C++
*/

#include <stdio.h>
#include "nbtree.h"
#include "list.h"

int main() {
	LIST barang[100];
	nbtType pohon= Generate();
	PrintNbt(pohon);
	
	
	levelordertraversal (pohon,barang,0);
	
	return 0;
}
