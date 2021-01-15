#include<iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <cstdlib>



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







void kitap(){
system("cls");
	
string dizi_adress="guncelleme/dizi.txt";
string film_afress="guncelleme/film.txt";
	


	
	
int x_df;
char secim_df;
tanim x;
int x_durum = 1;
while (x_durum){
system("cls");
cout <<"Omer ARAL HOS GELDİN"<<endl;
cout << ".....xxxEkleme islemlerixxx...." << endl;
cout << "Dizi icin : d \n Film icin : f"<<endl;
cout << "Gecmis durumu incelmek icin... g " << endl;
cout << "seciminizi :" ;
cin  >>secim_df;

if (secim_df=='d'){
	system("cls");
ifstream dosyaOku(dizi_adress,ios::in);

bool durum=dosyaOku.is_open();
	if(durum==0){
	ofstream dosyaYaz("dizi.txt",ios::out);
	dosyaYaz.close();
	cout << "Dosya olusturuluyor....." << endl;
	Sleep(1000);
	system("cls");
	
	}

// bu bölüm veri girişi
cout << "Dizinin ismini giriniz :";
getline(cin >> ws,x.name);


//bu bölüm tür girişi
cout <<"Dizinin turunu giriniz  :";
getline(cin >> ws , x.tur);



//bu bölümde açıklama girilir
cout <<"Dizi hakkinda açiklamayi giriniz :";
getline(cin >> ws,x.aciklama);


//girilecek indix belirleme 
string satir_oku;
int n =1;	
while(getline(dosyaOku,satir_oku)){
		n++;
}

//x.name in ekrana yazarken kullanılan sıralama işlemleri...
//ayrıca diziye atanıldı
string n_s=to_string(n);	
string gecis = n_s+"-";
x.name = gecis + x.name;

//isimleri belli dizi içinde sıkıştırıp almamız kolay olsun istiyoruz
x.name=bant_sikistirma(x.name);
x.tur=bant_sikistirma(x.tur);

// dosyaya ekleme yapamız için kullanılan bir sistem
fstream dosyaGul(dizi_adress,ios::app);

//yazama işlemi yapıldı
string yazmac = x.name + " " + x.tur +  x.aciklama + "\n";
dosyaGul << yazmac;


//açılan dosya kapatıldı
dosyaGul.close();
dosyaOku.close();

}







/*



şimdi sıra filimlere geldi



*/


else if (secim_df == 'f'){
	system("cls");
ifstream dosyaOku(film_afress,ios::in);

bool durum=dosyaOku.is_open();
	if(durum==0){
	ofstream dosyaYaz("film.txt",ios::out);
	dosyaYaz.close();
	cout << "dosya oluturuluyor...." << endl;
	Sleep(1000);
	system("cls");
	}

// bu bölüm veri girişi
cout << "Film in ismini giriniz ismini giriniz :";
getline(cin >> ws,x.name);


//bu bölüm tür girişi
cout <<"Filminizin turunu giriniz  :";
getline(cin >> ws , x.tur);


//bu bölümde açiklama verisi alınır
cout <<"Filim hakkinda açiklamayı giriniz :";
getline(cin >> ws , x.aciklama);


//girilecek indix belirleme 
string satir_oku;
int n =1;	
while(getline(dosyaOku,satir_oku)){
		n++;
}

//x.name in ekrana yazarken kullanılan sıralama işlemleri...
//ayrıca diziye atanıldı
string n_s=to_string(n);	
string gecis = n_s+"-";
x.name = gecis + x.name;

//isimleri belli dizi içinde sıkıştırıp almamız kolay olsun istiyoruz
x.name=bant_sikistirma(x.name);
x.tur=bant_sikistirma(x.tur);

// dosyaya ekleme yapamız için kullanılan bir sistem
fstream dosyaGul(film_afress,ios::app);

//yazama işlemi yapıldı
string yazmac = x.name + " " + x.tur + x.aciklama + "\n";
dosyaGul << yazmac;


//açılan dosya kapatıldı
dosyaGul.close();
dosyaOku.close();
	
}


else if(secim_df=='g'){
	system("cls");
	char oku_df;
	cout << "Filim icin f Dizi icin d   :";
	cin >> oku_df;
	
	if (oku_df=='d'){
		ifstream dosyaOku(dizi_adress,ios::in);
		if(!dosyaOku.is_open()){
			cout<< "Dosya Bulunamadi...." <<endl;
			cout<<"Sistemden cikiliyor..." <<endl;
			Sleep(1500);
			x_durum=0;
			break;
		}
	string satir_oku;
    int n_sira =1;	
    while(getline(dosyaOku,satir_oku)){
		cout<<to_string(n_sira/11)+satir_oku<<endl;
		n_sira++;
    }
			
	}
	
	else if (oku_df=='f'){
		ifstream dosyaOku(film_afress,ios::in);
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

