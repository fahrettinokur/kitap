#include<iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <cstdlib>
#include "guncelleme1.cpp"


using namespace std;


struct tanim{
  string name;
  string tur;
  string aciklama;
};

string bant_sikistirma(string name)
{
	for(int i=name.length() ; i<=30 ;i++){
		name=name+" ";
	}
	return name;
}







int main(){
	
	
	
	
guncelleme_start();
	

	
	
int x_df;
char secim_df;
tanim x;
int x_durum = 1;
while (x_durum){

cout << ".....xxxEkleme islemlerixxx.... " << endl;
cout << "Dizi icin : d \n Film icin : f"<<endl;
cout << "Gecmis durumu incelmek icin... g " << endl;
cout << "seciminizi :" ;
cin  >>secim_df;

if (secim_df=='d'){
	system("cls");
ifstream dosyaOku("C:/Users/fahrettin/Desktop/dizivefilim/dizi.txt",ios::in);

bool durum=dosyaOku.is_open();
	if(durum==0){
	ofstream dosyaYaz("dizi.txt",ios::out);
	dosyaYaz.close();
	cout << "Dosya olusturuluyor....." << endl;
	Sleep(1000);
	system("cls");
	
	}

// bu bölüm veri giriþi
cout << "Dizinin ismini giriniz :";
getline(cin >> ws,x.name);


//bu bölüm tür giriþi
cout <<"Dizinin turunu giriniz  :";
getline(cin >> ws , x.tur);



//bu bölümde açýklama girilir
cout <<"Dizi hakkinda açiklamayi giriniz :";
getline(cin >> ws,x.aciklama);


//girilecek indix belirleme 
string satir_oku;
int n =1;	
while(getline(dosyaOku,satir_oku)){
		n++;
}

//x.name in ekrana yazarken kullanýlan sýralama iþlemleri...
//ayrýca diziye atanýldý
string n_s=to_string(n);	
string gecis = n_s+"-";
x.name = gecis + x.name;

//isimleri belli dizi içinde sýkýþtýrýp almamýz kolay olsun istiyoruz
x.name=bant_sikistirma(x.name);
x.tur=bant_sikistirma(x.tur);

// dosyaya ekleme yapamýz için kullanýlan bir sistem
fstream dosyaGul("C:/Users/fahrettin/Desktop/dizivefilim/dizi.txt",ios::app);

//yazama iþlemi yapýldý
string yazmac = x.name + " " + x.tur +  x.aciklama + "\n";
dosyaGul << yazmac;


//açýlan dosya kapatýldý
dosyaGul.close();
dosyaOku.close();

}







/*



þimdi sýra filimlere geldi



*/


else if (secim_df == 'f'){
	system("cls");
ifstream dosyaOku("C:/Users/fahrettin/Desktop/dizivefilim/film.txt",ios::in);

bool durum=dosyaOku.is_open();
	if(durum==0){
	ofstream dosyaYaz("film.txt",ios::out);
	dosyaYaz.close();
	cout << "dosya oluturuluyor...." << endl;
	Sleep(1000);
	system("cls");
	}

// bu bölüm veri giriþi
cout << "Film in ismini giriniz ismini giriniz :";
getline(cin >> ws,x.name);


//bu bölüm tür giriþi
cout <<"Filminizin turunu giriniz  :";
getline(cin >> ws , x.tur);


//bu bölümde açiklama verisi alýnýr
cout <<"Filim hakkinda açiklamayý giriniz :";
getline(cin >> ws , x.aciklama);


//girilecek indix belirleme 
string satir_oku;
int n =1;	
while(getline(dosyaOku,satir_oku)){
		n++;
}

//x.name in ekrana yazarken kullanýlan sýralama iþlemleri...
//ayrýca diziye atanýldý
string n_s=to_string(n);	
string gecis = n_s+"-";
x.name = gecis + x.name;

//isimleri belli dizi içinde sýkýþtýrýp almamýz kolay olsun istiyoruz
x.name=bant_sikistirma(x.name);
x.tur=bant_sikistirma(x.tur);

// dosyaya ekleme yapamýz için kullanýlan bir sistem
fstream dosyaGul("C:/Users/fahrettin/Desktop/dizivefilim/film.txt",ios::app);

//yazama iþlemi yapýldý
string yazmac = x.name + " " + x.tur + x.aciklama + "\n";
dosyaGul << yazmac;


//açýlan dosya kapatýldý
dosyaGul.close();
dosyaOku.close();
	
}


else if(secim_df=='g'){
	system("cls");
	char oku_df;
	cout << "Filim için f Dizi için d   :";
	cin >> oku_df;
	
	if (oku_df=='d'){
		ifstream dosyaOku("C:/Users/fahrettin/Desktop/dizivefilim/dizi.txt",ios::in);
		if(!dosyaOku.is_open()){
			cout<< "Dosya Bulunamadi...." <<endl;
			cout<<"Sistemden cikiliyor..." <<endl;
			Sleep(1500);
			x_durum=0;
			break;
		}
	string satir_oku;
    int n =1;	
    while(getline(dosyaOku,satir_oku)){
		cout<<to_string(n)+satir_oku<<endl;
		n++;
    }
			
	}
	
	else if (oku_df=='f'){
		ifstream dosyaOku("C:/Users/fahrettin/Desktop/dizivefilim/film.txt",ios::in);
		if(!dosyaOku.is_open()){
			cout<< "Dosya Bulunamadi...."<<endl;
			cout<<"Sistemden cikiliyor..."<<endl;
			Sleep(1500);
			x_durum=0;
			break;
		}
		string satir_oku;
        int n =1;	
        while(getline(dosyaOku,satir_oku)){
		cout<<to_string(n)+satir_oku<<endl;
		n++;
    }
		
	} 	
}

cout<<"cikma istiyorsaniz 0 a basiniz : ";
cin >> x_durum;

}
}

