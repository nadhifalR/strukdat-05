/*
 * Author : Nadhifal
 * NPM : 140810180048
 * Kelas : B
 * Deskripsi :
 * Tanggal : 27 Maret 2019
 */

 #include <iostream>
 using namespace std;

struct Pembalap {
   int nomor;
   char nama;
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};

void createNode(Pembalap* &p,  int nomor, char nama){
    p = new Pembalap;
    p->nomor=nomor;
    p->nama=nama;
    p->waktu=0;
    p->next=NULL;
    p->prev=NULL;
}

void insertFirst(Pembalap* &head, Pembalap* node){
    if (head==NULL)
        head=node;
    else {
        node->next=head;
        head->prev = node;
        head=node;
    }
}

// insert before a node
void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
    Pembalap* p=head;
    if (head->nomor==nomorKey){
        node->next=head;
        head->prev=node;
        head=node;
    }
    else{
        while(p!=NULL){
            if(p->nomor==nomorKey){
                node->next=p;
                node->prev=p->prev;
                p->prev->next=node;
                p->prev=node;
                break;
            }
            else
                p=p->next;
        }
    }
}

// delete a node that have the key
void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode){
    Pembalap* p=head;
    if (head->nomor==nomorKey){
        deletedNode=head;
        head=head->next;
        head->prev=NULL;
        deletedNode=NULL;
    }
    else{
        while(p!=NULL){
            if(p->nomor==nomorKey){
                p->prev->next=p->next;
                p->next->prev=p->prev;
                deletedNode=p;
                deletedNode=NULL;
                break;
            }
            else
                p=p->next;
        }
    }
}

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
    Pembalap* p=firstNode;
    while(p!=NULL){
        if(p->nomor==nomorKey){
            pToUpdate=p;
            break;
        }
        else
            p=p->next;
    }
}

void traversal(Pembalap* head){
    Pembalap* p=head;

	if(p==NULL){
		cout<<"List Kosong."<<endl;
	}
	else{
        while(p!=NULL){
			cout<<"nomor: "<<p->nomor<<endl;
			cout<<"nama: "<<p->nama<<endl;
			cout<<"waktu: "<<p->waktu<<endl<<endl;
			p=p->next;
		}
	}
}

// sorting ascending
void sortingByNomor(Pembalap* &head){
    //bingung ah
    }

// update Pembalap from user input
void update(Pembalap* firstNode, int nomorKey){
    Pembalap* p=firstNode;

    search(firstNode,nomorKey,p);
    p->nama='k';
    p->nomor=24;
    p->waktu=10;

    cout<<"nama: "<<p->nama<<endl;
    cout<<"nomor: "<<p->nomor<<endl;
    cout<<"waktu: "<<p->waktu<<endl<<endl;

}

int main(){
    Pembalap* head = NULL;
    Pembalap* pBaru = NULL;
    Pembalap* pToUpdate = NULL;
    char nama = 'a';

    for (int i = 0; i < 4; i++) {
        createNode(pBaru, i+1, nama++);
        insertFirst(head, pBaru);
    }

    cout << "\n>>> List" << endl;
    traversal(head);

    int keyNomor = 2;

    cout << "\n>>> Insert Before nomor " << keyNomor << endl;
    createNode(pBaru, 99, 'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);
    cout << "\n>>> SortingByNomor" << endl;
    sortingByNomor(head);
    traversal(head);

    keyNomor = 3;
    cout << "\n>>> Delete nomor " << keyNomor << endl;
    Pembalap* pHapus = NULL;
    deleteByKey(head, keyNomor, pHapus);
    traversal(head);

    keyNomor = 4;
    cout << "\n>>> Update nomor " << keyNomor << endl;
    update(head, keyNomor);

    cout << "\n>>> Updated list\n";
    traversal(head);
}
