/*
Program		: testqueue.c
Deskripsi	: untuk test adt queue dinamis (queue.h)
Nama		: Azzam Badruz zaman
Tanggal		: 06/07/2020
Revisi		: 2
Compiler	: Dev C++
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
	//deklarasi
	qType Q;
	addrQ temp, test;
	int input, data, posisi, keluar;
	if(test==NULL) puts("NULL GSAN");
	puts("bacot");
	//algoritma
	Q= InitQ();
	do{
		system("cls");
		printf("========== Linked List ==========");
		printf("\n1. enqueue");
		printf("\n2. dequeue ");;
		printf("\n3. Tampilkan Data");
		printf("\n4. Sort");
		printf("\n5. Exit");
		printf("\nPilihan Anda : ");
		scanf("%d", &input);
		
		switch(input){
			case 1 :
				system("cls");
				printf("========== Tambah di Akhir ==========");
				printf("\nMasukkan data yang akan ditambahkan (int) : ");
				scanf("%d", &data);
				EnQueue(&Q, data); getch();break;
			case 2 :
				system("cls");
				printf("========== Hapus Data Pertama ==========");
				printf("\nData yang anda miliki : "); PrintQ(Q);
				keluar= DeQueue(&Q);
				printf("\ndata yang keluar adalah : %d", keluar);
				if(Q == NULL){
					printf("\nData yang anda miliki sekarang : tidak ada");
				} else{
					printf("\nData yang anda miliki sekarang : "); PrintQ(Q);
				}
				getch(); break;
			case 3 :
				system("cls");
				printf("========== Henampilkan Data ==========");
				printf("\nData anda saat ini : "); PrintQ(Q);
				getch();
				break;
			case 4 :
				system("cls");
				printf("========== Sort ==========");
				printf("\nKeadaan awal : "); PrintQ(Q);
				sortQ(&Q);
				printf("\nSetelah sort : "); PrintQ(Q);
				getch();
				break;
			case 5 :
				posisi= 0;
				while(!IsEmptyQ(Q)) {
					keluar= DeQueue(&Q);
					printf("%d %d\n", posisi++, keluar);
					
				} 
				getch();
				system("cls");
				printf("yeay!!.. beres");
				return 0; break;
			default :
				printf("Plilihan anda tidak tersedia, tekan enter untuk mencoba kembali");
				break;				
		} 
	} while(1);
	return 0;
}

