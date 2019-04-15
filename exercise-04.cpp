/*
Nama Program        :exercise-04
Nama                :Daniel Rama H.
NPM                 :140810180045
Kelas               :A
Tanggal buat        :15-04-2019
Deskripsi Program   :phone book data in a multi linked list
*/
#include<iostream>
#include<string.h>
using namespace std;
struct kontak{
	char nama[10];
	char nomor[12];
	kontak* nextkontak;
};
struct index{
	char info[5];
	kontak* FirstKontak;
	index* next;
};
typedef index* pointerIndex;
typedef kontak* pointerKontak;
typedef pointerIndex List;

void createList(List& First){
	First=NULL;
}
void createElmtIndex(pointerIndex& pBaru){
	pBaru = new index;
	cout<<"Masukan index :"; cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->FirstKontak=NULL;

}
void createElmtKontak(pointerKontak& pBaru){
	pBaru= new kontak;
	cout<<"Masukan nama kontak:"; cin>>pBaru->nama;
	cout<<"Masukan nomor kontak:"; cin>>pBaru->nomor;
	pBaru->nextkontak=NULL;
}
void insertFirstIndex(List& First,pointerIndex pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversalIndex(List First){
	pointerIndex pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout<<"Index :"<<pBantu->info<<",";
		pBantu=pBantu->next;
	}
}
void linearSearch(List First,char key[5],int& status,pointerIndex& pCari){
	status=0;
	pCari=First;
	while(status==0 && pCari!=NULL){
		if(strcmp(pCari->info,key)==0){
			status=1;
		}
		else{
			pCari=pCari->next;
		}
	}
}
void insertFirstKontak(List& First,char key[5],pointerKontak pBaru){
	pointerIndex pB;
	int ada;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ada,pB);
	if(ada){
		cout<<"Ditemukan dengan Index :"<<pB->info<<endl;
		if(pB->FirstKontak==NULL){
			pB->FirstKontak=pBaru;
		}
		else{
			pBaru->nextkontak=pB->FirstKontak;
			pB->FirstKontak=pBaru;
		}
	}
	else{
		cout<<"Index  tidak di temukan"<<endl;
	}
}
void deleteFirstKontak(List& First,char key[5],pointerKontak& pHapus ){
	int ketemu;
	pointerIndex pB;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pB);
		if(ketemu){
		cout<<"Ditemukan dengan INdex :"<<pB->info;
		if(pB->FirstKontak==NULL){
			cout<<"Tidak ada yang di hapus"<<endl;
		}
		else if(pB->FirstKontak->nextkontak==NULL){
			pHapus=pB->FirstKontak;
			pB->FirstKontak=NULL;
		}
		else{
			pHapus=pB->FirstKontak;
			pB->FirstKontak=pB->FirstKontak->nextkontak;
			pHapus->nextkontak=NULL;
		}
	}
	else{
		cout<<"Index tidak di temukan"<<endl;
	}
}
void traversalIndexKontak(List First){
	pointerIndex pBantuIndex;
	pointerKontak pBantuKontak;
	cout<<"Traversal Divisi"<<endl;
	pBantuIndex=First;
	while (pBantuIndex!=NULL){
	cout<<"Index :"<<pBantuIndex->info <<endl;
	pBantuKontak=pBantuIndex->FirstKontak;
	while (pBantuKontak!=NULL) {
	cout<<pBantuKontak->nama<<" / "<<pBantuKontak->nomor<<endl;
	pBantuKontak=pBantuKontak->nextkontak;
	}
	pBantuIndex=pBantuIndex->next;
	}
}
void updateKontak(List First,char key[10],int& status,pointerIndex& pIndex){
	status=0;
	pointerKontak pK,pb;
	pIndex=First;
	pK=pIndex->FirstKontak;
	cout<<"Masukan nama kontak :"; cin>>key;
	while(pIndex!=NULL){
		while(status== 0 && pK!=NULL){
			if(strcmp(pK->nama,key)==0){
				cout<<"Masukan Nama Kontak:"; cin>>pK->nama;
				cout<<"Masukan Nomor Kontak:"; cin>>pK->nomor;
			status=1;
			}
			else if(pK->nextkontak==NULL){
				status=1;
			}
			else {
				pK=pK->nextkontak;
			}
		}
			pIndex=pIndex->next;
		}
	}

main(){
	pointerIndex pI;
	pointerKontak pK,phk;
	List q;
	char key[5],nama[10];
	int ni,nk,ketemu;
	createList(q);
	cout<<"Masukan Banyaknya index :"; cin>>ni;
	for(int i=0;i<ni;i++){
		createElmtIndex(pI);
		insertFirstIndex(q,pI);
	}
	cout<<"Masukan banyaknya kontak :"; cin>>nk;
	for(int i=0;i<nk;i++){
		createElmtKontak(pK);
		insertFirstKontak(q,key,pK);
	}
    traversalIndexKontak(q);
	updateKontak(q,nama,ketemu,pI);
	traversalIndexKontak(q);
}


