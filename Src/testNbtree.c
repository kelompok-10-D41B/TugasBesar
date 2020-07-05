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

int main() {
	nbtType pohon= Generate();

	printf("postorder\n");
	Postorder(pohon);
	printf("preorder\n");
	Preorder(pohon);
	printf("inorder\n");
	Inorder(pohon); 
	
	PrintNbt(pohon);
	return 0;
}
