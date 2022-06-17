#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define max 100

using namespace std;
//global variabel
int x=0,jumlah_mhs, ipk,nim;
bool ketemu = false;
string name;

//array dari matkul
string matkul[8]={"Sistem Operasi","Struktur data","Komunikasi Data","Komputer Grafis"
,"Lingkungan Bisnis","Pemrograman\t","Hardware/Software","Bahasa Inggris II"};

struct QUEUE
{
	string data[max];
	int head;
	int tail;
}antrian;

struct Mahasiswa
{
	string nama[max];
	int NIM[max];
	int IPK[max];
}Mhs,tukar;

void init()
{
	antrian.head=0;
	antrian.tail=0;
	x = 0;
}

bool kosong()
{
	if(antrian.tail==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool penuh()
{
	if(antrian.tail==max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tampilData()
{
	if(!kosong())
	{
		cout << "Daftar antrian : " << endl;
		for(int i=antrian.head;i<=antrian.tail-1;i++)
		{
			cout << antrian.data[i] << " | ";
		}
	}
	cout << "\n";
}

void tampilMhs(int jml_mhs)
{
	for(int i=0;i<jml_mhs;i++)
	{
		cout << "Mahasiswa " << i+1 << " : " << endl;
		cout << "Nama	: " << Mhs.nama[i] << endl;
		cout << "NIM	: " << Mhs.NIM[i] << endl;
		cout << "IPK	: " << Mhs.IPK[i] << endl;
		cout << endl;
	}
}

void InputDataMhs()
{
	cout << "Nama\t\t: " << Mhs.nama[x] << endl;
	cout << "NIM\t\t: "; cin >> Mhs.NIM[x];
	cout << "==================" << endl;
	cout << "Input Nilai" << endl;
	double jml_nilai = 0;
	int nilai[8];
	for(int j=0;j<8;j++)
	{
		cout << j+1 << ". " << matkul[j] << " : "; cin >> nilai[j];
		switch (nilai[j])
		{
			case 81 ... 100:
				nilai[j]=4;
			break;
			case 60 ... 80:
				nilai[j]=3;
			break;
			case 40 ... 59:
				nilai[j]=2;
			break;
			case 0 ... 39:
				nilai[j]=1;
			break; 
			default:
			break;
		}
		jml_nilai += nilai[j];
	}
	Mhs.IPK[x] = jml_nilai/8;
}

void enqueue()//Fungsi menambah antrian
{
	tampilData();
	
	if(!penuh())
	{
		string baru;
		cout << "Nama antrian yang akan dimasukan : ";
		cin >> baru;
		antrian.data[antrian.tail]=baru;
		
		antrian.tail++;
		jumlah_mhs = antrian.tail;
	}
	else
	{
		cout << "Antrian sudah penuh!!";
	}
	getchar();
}

void dequeue()//Fungsi mengurangi antrian
{
	tampilData();
	if(!kosong())
	{
		cout << "Mengisi data " << antrian.data[antrian.head] << " : " << endl;
		Mhs.nama[x] = antrian.data[antrian.head];
		for(int i=antrian.head;i<antrian.tail;i++)
		{
			antrian.data[i]=antrian.data[i+1];
		}
		InputDataMhs();
		antrian.tail--;
		x++;
	}
	else
	{
		cout << "Antrian kosong";
	}
	
	getchar();
	
}

void buble_sort(int x)//Fungsi mengurutkan dengan metode Bublesort
{
	for(int i=0;i<(x-1);i++)
	{
		for(int j=0;j<(x-1);j++)
		{
			if(Mhs.NIM[j] > Mhs.NIM[j+1])
			{
				//Proses penukaran
				name = Mhs.nama[j];
				ipk = Mhs.IPK[j];
				nim = Mhs.NIM[j];
				Mhs.nama[j]=Mhs.nama[j+1];
				Mhs.NIM[j]=Mhs.NIM[j+1];
				Mhs.IPK[j]=Mhs.IPK[j+1];
				Mhs.nama[j+1]=name;
				Mhs.NIM[j+1]=nim;
				Mhs.IPK[j+1]=ipk;
			}
		}
	}
}

void selection_sort(int x)//Fungsi mengurutkan dengan metode Selectionsort
{
	for(int i=0;i<x;i++)
	{
		int maks;
		maks =i;
		for(int j=i+1;j<x;j++)
		{
			if(Mhs.NIM[maks]>Mhs.NIM[j])
			{
				maks=j;
			}
		}
		if(Mhs.NIM[i] != Mhs.NIM[maks])
		{
			//Proses penukaran	
			name = Mhs.nama[i];
			ipk = Mhs.IPK[i];
			nim = Mhs.NIM[i];
			Mhs.nama[i]=Mhs.nama[maks];
			Mhs.NIM[i]=Mhs.NIM[maks];
			Mhs.IPK[i]=Mhs.IPK[maks];
			Mhs.nama[maks]=name;
			Mhs.NIM[maks]=nim;
			Mhs.IPK[maks]=ipk;		
		}
	}
}

void insertion_sort(int x)//Fungsi mengurutkan dengan metode Insertionsort
{
	int j;
	for(int i=0;i<x;i++)
	{
		name = Mhs.nama[i];
		nim = Mhs.NIM[i];
		ipk = Mhs.IPK[i];
		
		j = i-1;
		
		while(Mhs.NIM[j] > nim && j >= 0)
		{
			Mhs.nama[j+1] = Mhs.nama[j];
			Mhs.NIM[j+1] = Mhs.NIM[j];
			Mhs.IPK[j+1] = Mhs.IPK[j];
			j--;
		}
		Mhs.nama[j+1] = name;
		Mhs.NIM[j+1] = nim;
		Mhs.IPK[j+1] = ipk;
	}
	
}

void Searching(string target,int x)
{
	name = target;
	
	for(int i=0;i<x;i++)
	{
		if(name == Mhs.nama[i])
		{
			ketemu = true;
			name = Mhs.nama[i];
			nim = Mhs.NIM[i];
			ipk = Mhs.IPK[i];
		}
	}
	if(ketemu)
	{
		cout << "Data Ditemukan : \nNama\t: "  << name << "\nNIM\t: " << nim << "\nIPK\t: " << ipk << endl;
	}
	else
	{
		cout << "Nama tidak ditemukan" << endl;
	}
}

void Display(int x)
{
	cout << "=======================================" << endl;
	cout << "| NIM  |\tNama\t\t| IPK |" << endl; 
	cout << "=======================================" << endl;
	for(int i=0;i<x;i++)
	{
		cout << "| " << Mhs.NIM[i] << " | " << Mhs.nama[i] << "\t\t\t| " << Mhs.IPK[i] << " | " << endl; 
	}
	cout << "=======================================" << endl;
}

int main()
{
	//lokal variabel
	int pil1,pil2;
	string pil3;
	string cari; 
	
	do
	{
		tampilData();
		cout << "Menu Utama\n";
		cout << "==========\n";
		cout << "  [1] Buat Antrian Baru\n";
		cout << "  [2] Tambah Antrian\n";
		cout << "  [3] Isi Data Antrian\n";
		cout << "  [4] Data mahasiswa\n";
		cout << "  [0] Keluar\n";
		cout << "==========\n";
		cout << "Masukan Pilihan : "; cin >> pil1;
		
		switch(pil1)
		{
			case 1 :
				init();
				system("cls");
			break;
			case 2 :
				enqueue();
				system("cls");
			break;
			case 3 :
				dequeue();
				system("cls");
			break;
			case 4 :
				system("cls");
				tampilMhs(jumlah_mhs);
				cout << "Pilih metode pengurutan : " << endl;
				cout << "Menu Sorting : " << endl;
				cout << "1. Buble Sort" << endl;
				cout << "2. Selection Sort" << endl;
				cout << "3. Insertion Sort" << endl;
				cout << "Input Pilihan : "; cin >> pil2;
				
				cout << "Sebelum diurutkan : " << endl;
				Display(jumlah_mhs);//tampilan data sebelum diurutkan
				switch(pil2)
				{
					case 1 :
						buble_sort(jumlah_mhs);//Memanggil fungsi buble_sort()
					break;
					case 2 :
						selection_sort(jumlah_mhs);//Memanggil fungsi selection_sort()
					break;
					case 3 :
						insertion_sort(jumlah_mhs);//Memanggil fungsi insertion_sort()
					break;
				}
				cout << "Sesudah diurutkan : " << endl;
				CARI :
				Display(jumlah_mhs);
				cout << "Input nama yang akan di cari : "; cin >> cari;
				Searching(cari,jumlah_mhs);//Memanggil fungsi Searching() atau binary search
				cout << "Data ditemukan?[y/n] : ";
				cin >> pil3;
				if(pil3== "y")
				{
					cout << endl;
				}
				else if (pil3 == "n")
				{
					goto CARI;
				}
			break;
		}
	}
	while(pil1!=0);
	return 0;
}
