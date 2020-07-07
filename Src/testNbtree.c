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
#include "kombin.h"
//dah include di kombin.h
//#include "nbtree.h"	
//#include "queue.h"


int main() {
	queue antri;
	

	Insert(&antri,1);
	Insert(&antri,2);
	Insert(&antri,3);
	Insert(&antri,4);
	Tampil(antri);
	
	list test[4];
	test[1].namaBarang="susu";
	test[2].namaBarang="coklat";
	test[3].namaBarang="keju";
	test[4].namaBarang="roti";
	nbtType pohon= Generate_levelorder(test);
	PrintNbt(pohon);
	return 0;
}
