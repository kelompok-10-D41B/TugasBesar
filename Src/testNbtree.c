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
#include"queue.h"
#include "kombin.h"


int main() {
	list test;
	test[1]->namaBarang="susu";
	test[2]->namaBarang="coklat";
	test[3]->namaBarang="keju";
	test[4]->namaBarang="roti";
	nbtType pohon= kombin_levelorder(test);
	PrintNbt(pohon);
	return 0;
}
