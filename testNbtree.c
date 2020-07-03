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
	nbtType pohon;
	
	pohon= CreateNbt('A');
	
	InsertNbt(&pohon, 'A', 'B'); 
	InsertNbt(&pohon, 'A', 'C');
	InsertNbt(&pohon, 'A', 'Z');
	InsertNbt(&pohon, 'C', 'D');
	InsertNbt(&pohon, 'B', 'E');
	InsertNbt(&pohon, 'B', 'F');
	InsertNbt(&pohon, 'B', 'H');
	InsertNbt(&pohon, 'F', 'G');

	printf("postorder\n");
	Postorder(pohon);
	printf("preorder\n");
	Preorder(pohon);
	printf("inorder\n");
	Inorder(pohon); 
	
	PrintNbt(pohon);
	return 0;
}
