/****************************************************************************
**SAKARYA ÜNİVERSİTESİ
**BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**PROGRAMLAMAYA GİRİŞİ DERSİ
**
**ÖDEV NUMARASI: Proje1
**ÖĞRENCİ ADI: Merve Günay
**ÖĞRENCİ NUMARASI: B201210017
**DERS GRUBU: C Gurubu
****************************************************************************/

#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	// urun.txt dosyasında yer alancak alanlar
	string Urun_Kodu;
	string Ureticisi;
	string Temin_Suresi;
	string Uretim_Tarihi;
	string Fiyat_Genele;
	string Fiyat_Ozele;
	string Kdv_Orani;
	string Stok_Adedi;

	//cari.txt dosyasında yer alacak alanlar
	string Firma_no;
	string Firma_Adi;
	string Firma_Telefon;
	string Firma_Sorumlusu;
	string Musteri_Katagorisi;
	string Adres;

	//siparis.txt dosyasında yer alacak alanlar
	string Firma_No;      //cari.txt ve siparis.txt dosyaları arasındaki ilişkiyi sağlamak için
	string Siparis_Tarihi;
	string Siparis_Tutari;
	string Siparis_Listesi;
	string Siparisi_Alan;

	//siparisListesi.txt dosyasında yer alacak alanlar
	string Urun_kodu;    //urun.txt ve siparis.txt dosyaları arasında ilişkiyi sağlamak için
	string Urun_Adedi;

	int secim;
	cout << "   Ne yapmak istiyorsunuz ? " << endl;
	cout << "   1) Urun Icin Islemler " << endl;
	cout << "   2) Musteri Dosyasi Islemleri  " << endl;
	cout << "   3) Siparis Islemleri " << endl;

	cin >> secim;       //Kullanıcıya işlem seçimi yaptırıldı

	switch (secim) {
	case 1:
		cout << "Urun dosyasi icin islemler asagidaki gibidir. Lutfen, yapmak istediginiz islemi seciniz." << endl;
		int urun_islem_secimi1;
		cout << "1) Urun Ekleme" << endl;
		cout << "2) Urun Arama" << endl;
		cout << "3) Urun Listeleme" << endl;
		cout << "4) Urun Duzeltme" << endl;
		cout << "5) Urun Silme" << endl;

		cin >> urun_islem_secimi1;      //Kullanıcıya ürün dosyası işlemleri seçimi yaptırıldı

		if (urun_islem_secimi1 == 1) {

			ofstream UrunEkle;          //Urun ekleyebileceğim bir dosya oluşturdum.
			UrunEkle.open("urun.txt", ios::app);   // Oluşturduğum dosyayı açtım
			int cevap;  //Ürün ekleme işlemi devam edicek mi etmeyecek mi, cevap, cevabı integer olarak tanımlandı.
			
			do
			{
				cout << " Urun Kodu                :"; cin >> Urun_Kodu;        //Urun bilgilerini kullanıcıya girdirdim.
				cout << " Ureticisi                :"; cin >> Ureticisi;
				cout << " Temin Suresi             :"; cin >> Temin_Suresi;
				cout << " Uretim Tarihi            :"; cin >> Uretim_Tarihi;
				cout << " Genel Musteriye Fiyat    :"; cin >> Fiyat_Genele;
				cout << " Ozel Musteriye Fiyat     :"; cin >> Fiyat_Ozele;
				cout << " KDV Orani                :"; cin >> Kdv_Orani;
				cout << " Stok Adedi               :"; cin >> Stok_Adedi;

				UrunEkle << " " << Urun_Kodu << " " <<  Ureticisi << " " << Temin_Suresi << " " << Uretim_Tarihi << " " << Fiyat_Genele << " " << Fiyat_Ozele << " " << Kdv_Orani << " " << Stok_Adedi << " " << endl;   //Girilen bilgileri yazdırdım.
				cout << "Dosyaya baska urun ekleyecekmisiniz? (1=Evet / 2=Hayir)" << endl;
				cin >> cevap;

			} while (!(cevap == 2));
			UrunEkle.close(); //dosyayı kapattım.
			cout << "Dosyaya urun ekleme islemi tamamlandi. " << endl;
			
			system("PAUSE");
			return 0;
		}

		else if (urun_islem_secimi1 == 2) {
			//Urunleri eklediğim dosyayı okumak için açtım.
			ifstream UrunArama("urun.txt", ios::in);    
			string aranankod;
			cout << "Aranacak kod :" << endl;
			cin >> aranankod;
			
			if (UrunArama.is_open())
			{
				int x = 0;
				
				do
				{
					UrunArama >> Urun_Kodu >> Ureticisi >> Temin_Suresi >> Uretim_Tarihi >> Fiyat_Genele >> Fiyat_Ozele >> Kdv_Orani >> Stok_Adedi;

					if (Urun_Kodu == aranankod)  //aranan kod ile eşleşen ürün kodu bilgilerinin çıktısını aldım.
					{
						cout << "Ureticisi                  :" << Ureticisi << endl;
						cout << "Temin Suresi               :" << Temin_Suresi << endl;
						cout << "Uretim Tarihi              :" << Uretim_Tarihi << endl;
						cout << "Genel Musteriye Fiyat      :" << Fiyat_Genele << endl;
						cout << "Ozel Musteriye Fiyat       :" << Fiyat_Ozele << endl;
						cout << "KDV Orani                  :" << Kdv_Orani << endl;
						cout << "Stok Adedi                 :" << Stok_Adedi << endl;
						x = 1;
						return 0;
					}

				} while (!UrunArama.eof());
				UrunArama.close();  //dosyayı kapattım.
				if (x == 0) {
					cout << "Dosyada kayitli urun kodu yok!" << endl;
				}
					
			}
			else
				cout << "Dosya acilamadi!";
			
			system("PAUSE");
			return 0;

		}

		else if (urun_islem_secimi1 == 3) {
			ifstream UrunListele("urun.txt");     //Urun dosyasını satır satır okuttum.
			string satir = "";

			if (UrunListele.is_open()) {

				while (getline(UrunListele, satir)) {
					cout << satir << endl;
				}

				UrunListele.close();
			}

			return 0;
		}




		else if (urun_islem_secimi1 == 4) {    //urun düzeltme
			int geccici = 0;
			string düzeltme_kod;
			cout << "Guncellenecek Urun Bilgisi Icin Urun Kodu  Giriniz..."; 
			cin >> düzeltme_kod;
			
			ifstream UrunDosyaOku("urun.txt"); //dosyayı okuma amaçlı açtık.
			ofstream GeciciDosyaYaz("Urun.tmp");  //değiştirilen urun bilgilerini tutan tmp dosyası yazdım.

			while (UrunDosyaOku >> Urun_Kodu >> Ureticisi >> Temin_Suresi >> Uretim_Tarihi >> Fiyat_Genele >> Fiyat_Ozele >> Kdv_Orani >> Stok_Adedi)
			{
				if (düzeltme_kod == Urun_Kodu){
					cout << "\n Yeni Urun Bilgilerini Giriniz \n";
					cout << " Urun Kodu                :"; cin >> Urun_Kodu;
					cout << " Ureticisi                :"; cin >> Ureticisi;
					cout << " Temin Suresi             :"; cin >> Temin_Suresi;
					cout << " Uretim Tarihi            :"; cin >> Uretim_Tarihi;
					cout << " Genel Musteriye Fiyat    :"; cin >> Fiyat_Genele;
					cout << " Ozel Musteriye Fiyat     :"; cin >> Fiyat_Ozele;
					cout << " KDV Orani                :"; cin >> Kdv_Orani;
					cout << " Stok Adedi               :"; cin >> Stok_Adedi;

					GeciciDosyaYaz << " " << Urun_Kodu << " " << Ureticisi << " " << Temin_Suresi << " " << Uretim_Tarihi << " " << Fiyat_Genele << " " << Fiyat_Ozele << " " << Kdv_Orani << " " << Stok_Adedi << " " << endl;  //girilen urun bilgilerini dosyaya yazdırdım.
					geccici = 1;
				}
			}
			GeciciDosyaYaz.close();  //açtığım dosyaları kapattım.
			UrunDosyaOku.close();
			
			remove("urun.txt");                 //urun.txt dosyasını sildim.
			rename("Urun.tmp", "urun.txt");     //Urun.tmp dosyasını urun.txt dosyasına kopyaladım.

			if (geccici == 0)
				cout << "Boyle Bir Urun Kodu Bulunmamaktadir..." << endl;
			if (geccici == 1)
				cout << "Urun Bilgileri Guncellendi..." << endl;
        
        }

	





		else if (urun_islem_secimi1 == 5) {   //urun silme
			int gecici = 0, karar = 0;
			string sil_kod;
			cout << "Silinecek urun icin kod numarasini giriniz: "; cin >> sil_kod; //silinecek urunun urun kodu numarası bilgisini girdirdim.

			ifstream UrunSil("urun.txt");
			while (!UrunSil.eof()) //urunSil de belirttiğim urun.txt dosyasını sonuna kadar okuttum.
			{
				UrunSil >> Urun_Kodu >> Ureticisi >> Temin_Suresi >> Uretim_Tarihi >> Fiyat_Genele >> Fiyat_Ozele >> Kdv_Orani >> Stok_Adedi;

				if (Urun_Kodu == sil_kod)
				{
					cout << "=========== Urun Bilgileri ==========" << endl;
					cout << "Urun kodu                :" << sil_kod << endl;
					cout << "Ureticisi                :" << Ureticisi << endl;
					cout << "Temin Suresi             :" << Temin_Suresi << endl;
					cout << "Uretim Tarihi            :" << Uretim_Tarihi << endl;
					cout << "Genel Musteriye Fiyat    :" << Fiyat_Genele << endl;
					cout << "Ozel Musteriye Fiyat     :" << Fiyat_Ozele << endl;
					cout << "KDV Orani                :" << Kdv_Orani << endl;
					cout << "Stok Adedi               :" << Stok_Adedi << endl;

				}
				cout << "Urun kaydini silmek istiyor musunuz? ( 1=evet / 2=hayir )";
				int karar;
				cin >> karar;


				if (karar == 1)
				{
					ifstream urunDosyaOku("urun.txt"); //dosyayı okuma amaçlı aç
					ofstream GeciciDosyaYaz("Urun.tmp");  //silinecek ürünü tutacak tmp dosyası yazdım.

					while (urunDosyaOku >> Urun_Kodu >> Ureticisi >> Temin_Suresi >> Uretim_Tarihi >> Fiyat_Genele >> Fiyat_Ozele >> Kdv_Orani >> Stok_Adedi)
					{

						if (sil_kod != Urun_Kodu) {
							GeciciDosyaYaz << " " << Urun_Kodu << " " << Ureticisi << " " << Temin_Suresi << " " << Uretim_Tarihi << " " << Fiyat_Genele << " " << Fiyat_Ozele << " " << Kdv_Orani << " " << Stok_Adedi << " " << endl;
						}
						
						if (sil_kod == Urun_Kodu) {
							gecici = 1;
						}
					}

					GeciciDosyaYaz.close();
					UrunSil.close();
					urunDosyaOku.close();

					remove("urun.txt");                //urun.txt dosyasını sildim.
					rename("Urun.tmp", "urun.txt");    //Urun.tmp dosyasını urun.txt dosyasına kopyaladım.

					if (gecici == 0) {
						cout << "Boyle Bir Urun Bulunmamaktadir..." << endl;
					}
					
					if (gecici == 1) {
						cout << "Urun Silindi..." << endl;
						
					}
				}
				system("PAUSE");
				return 0;
			}
		}
	    
		break;
	case 2:
		cout << "Musteri dosyasi icin islemler asagidaki gibidir. Lutfen, yapmak istediginiz islemi seciniz." << endl;
		int musteri_islem_secimi;
		cout << "1) Musteri Ekle" << endl;
		cout << "2) Musteri Arama" << endl;
		cout << "3) Musteri Duzeltme" << endl;
		cout << "4) Musteri Silme" << endl;

		cin >> musteri_islem_secimi;    //Kullanıcıya müşteri dosyası işlemleri seçimi yaptırıldı.

		if (musteri_islem_secimi == 1) {
			ofstream MusteriEkle;
			MusteriEkle.open("cari.txt", ios::app);        //müsteri eklemek için dosya yazdım.
			int cevap;
			
			do
			{
				cout << " Firma No                :"; cin >> Firma_No;   //kullanıcıdan bilgileri aldım.
				cout << " Firma Adi               :"; cin >> Firma_Adi;
				cout << " Firma Telefon           :"; cin >> Firma_Telefon;
				cout << " Firma Sorumlusu         :"; cin >> Firma_Sorumlusu;
				cout << " Musteri Katagorisi      :"; cin >> Musteri_Katagorisi;
				cout << " Adres                   :"; cin >> Adres;
				

				MusteriEkle << " " << Firma_No << " " << Firma_Adi << " " << Firma_Telefon << " " << Firma_Sorumlusu << " " << Musteri_Katagorisi << " " << Adres << " " << endl;   // dosyaya bilgileri yazdırdım.

				cout << "Dosyaya baska musteri ekleyecekmisiniz? (1=Evet / 2=Hayir)" << endl;
				cin >> cevap;

			} while (!(cevap == 2));
			MusteriEkle.close();
			cout << "Dosyaya musteri ekleme islemi tamamlandi. " << endl;
			
			system("PAUSE");
			return 0;
		}


		else if (musteri_islem_secimi == 2) {
			ifstream MusteriArama("cari.txt", ios::in);      //müşteri aramak için dosyayı okuttum.
			string arananFirmaNo;                            //aranacak firma noyu tanımlaım.
			cout << "Aranacak firma no :" << endl;         
			cin >> arananFirmaNo;                      
			if (MusteriArama.is_open())
			{
				int x = 0;
				
				do
				{
					MusteriArama >> Firma_No >> Firma_Adi >> Firma_Telefon >> Firma_Sorumlusu >> Musteri_Katagorisi >> Adres;

					if (Firma_No == arananFirmaNo)                      //aranan firma no dosyada herhangi bir firma no ile eşleşirse tüm bilgileri ekrana getirdim.
					{
						cout << " Firma No                :" << Firma_No << endl;
						cout << " Firma Adi               :" << Firma_Adi << endl;
						cout << " Firma Telefon           :" << Firma_Telefon << endl;
						cout << " Firma Sorumlusu         :" << Firma_Sorumlusu << endl;
						cout << " Musteri Katagorisi      :" << Musteri_Katagorisi << endl;
						cout << " Adres                   :" << Adres << endl;
						x = 1;
						return 0;
					}

				} while (!MusteriArama.eof());
				MusteriArama.close();
				if (x == 0) {
					cout << "Dosyada kayitli firma no yok!" << endl;
                }
					
			}
			else
				cout << "Dosya acilamadi!";
			system("PAUSE");
			return 0;
		}



		else if (musteri_islem_secimi == 3) {
			int geccici = 0;
			string düzeltme_firma_no;
			cout << "Guncellenecek Firma Bilgisi Icin Firma No Giriniz..."; 
			cin >> düzeltme_firma_no;

			ifstream MusteriDosyaOku("cari.txt"); //dosyayı okuma amaçlı açtık.
			ofstream GeciciDosyaYaz("Cari.tmp");    //yeni bilgileri tutacağım geçici tmp dosyası oluşturdum.

			while (MusteriDosyaOku >> Firma_No >> Firma_Adi >> Firma_Telefon >> Firma_Sorumlusu >> Musteri_Katagorisi >> Adres)
			{
				if (düzeltme_firma_no == Firma_No) {
					cout << " Firma No                :"; cin >> Firma_No;
					cout << " Firma Adi               :"; cin >> Firma_Adi;
					cout << " Firma Telefon           :"; cin >> Firma_Telefon;
					cout << " Firma Sorumlusu         :"; cin >> Firma_Sorumlusu;
					cout << " Musteri Katagorisi      :"; cin >> Musteri_Katagorisi;
					cout << " Adres                   :"; cin >> Adres;

					GeciciDosyaYaz << " " << Firma_No << " " << Firma_Adi << " " << Firma_Telefon << " " << Firma_Sorumlusu << " " << Musteri_Katagorisi << " " << Adres << " " << endl;  //girilen firma bilgilerini dosyaya yazdırdım.
					geccici = 1;
				}
			}
			GeciciDosyaYaz.close();       //dosyaları kapadım.
			MusteriDosyaOku.close();

			remove("cari.txt");                    //musteri.txt dosyasını sildim.
			rename("Cari.tmp", "cari.txt");     //Musteri.tmp dosyasını musteri.txt dosyasına kopyaladım.

			if (geccici == 0)
				cout << "Boyle Bir Firma Bulunmamaktadir..." << endl;
		
				
			if (geccici == 1) 
				cout << "Firma Bilgileri Guncellendi..." << endl;
			
				
		}


		else if (musteri_islem_secimi == 4) {
		    int gecici = 0, karar = 0;
		    string sil_firma_no;              //silinecek firma no yu tanımladım.
		    cout << "Silinecek Firmanin numarasini giriniz: "; 
		    cin >> sil_firma_no; //silinecek firmanın numara bilgisini girdirdim.

		    ifstream FirmaSil("cari.txt");         
		    while (!FirmaSil.eof()) //firmasil de belirttiğim cari.txt dosyasını sonuna kadar okuttum.
		    {
			    FirmaSil >> Firma_No >> Firma_Adi >> Firma_Telefon >> Firma_Sorumlusu >> Musteri_Katagorisi >> Adres;

			    if (Firma_No == sil_firma_no)         //firma bilgilerin ikerana getirdim.
			    {
				    cout << "=========== Firma Bilgileri ==========" << endl;
				    cout << " Firma No                :" << Firma_No << endl;
				    cout << " Firma Adi               :" << Firma_Adi << endl;
				    cout << " Firma Telefon           :" << Firma_Telefon << endl;
				    cout << " Firma Sorumlusu         :" << Firma_Sorumlusu << endl;
				    cout << " Musteri Katagorisi      :" << Musteri_Katagorisi << endl;
				    cout << " Adres                   :" << Adres << endl;

			    }
			    cout << "Firma kaydini silmek istiyor musunuz? ( 1=evet / 2=hayir )";
			    int karar;
			    cin >> karar;


			    if (karar == 1)
			    {
				    ifstream FirmaDosyaOku("cari.txt"); //dosyayı okuma amaçlı aç
				    ofstream GeciciDosyaYaz("Cari.tmp");
				 
				    while (FirmaDosyaOku >> Firma_No >> Firma_Adi >> Firma_Telefon >> Firma_Sorumlusu >> Musteri_Katagorisi >> Adres)
				    {

					    if (sil_firma_no != Firma_No) {
						    GeciciDosyaYaz << " " << Urun_Kodu << " " << Ureticisi << " " << Temin_Suresi << " " << Uretim_Tarihi << " " << Fiyat_Genele << " " << Fiyat_Ozele << " " << Kdv_Orani << " " << Stok_Adedi << " " << endl;
					    }

					    if (sil_firma_no == Firma_No) {
						    gecici = 1;
					    }
				    }

				    GeciciDosyaYaz.close();   //dosyaları kapattım.
				    FirmaSil.close();
				    FirmaDosyaOku.close();

				    remove("cari.txt");                //randevu.txt dosyasını sildim.
				    rename("Cari.tmp", "cari.txt");    //randevu.tmp dosyasını randevu.txt dosyasına kopyaladım.

				    if (gecici == 0) {
					cout << "Boyle Bir Firma Bulunmamaktadir..." << endl;
				    }

				    if (gecici == 1) {
					cout << "Firma Bilgileri Silindi..." << endl;

				    }
			    }
			    system("PAUSE");
			    return 0;
		    }
		}


        break;
	case 3:
		cout << "Siparis dosyasi icin islemler asagidaki gibidir. Lutfen, yapmak istediginiz islemi seciniz." << endl;
		int siparis_islem_secimi;
		cout << "1) Siparis Olustur" << endl;
		cout << "2) Siparis Arama" << endl;
		cout << "3) Siparis Silme" << endl;
		cout << "4) Siparis Raporlama" << endl;

		cin >> siparis_islem_secimi;        //Kullanıcıya siparis dosyası işlemleri seçimi yaptırıldı.

		if (siparis_islem_secimi == 1) {
			ofstream SiparisOlustur;
			SiparisOlustur.open("siparis.txt", ios::app);         //siparişleri yazacağım siparis.txt dosyasını oluşturdum.
			int cevap1;
			
			do
			{
				cout << " Firma No                :"; cin >> Firma_No;          //kullanıcıdan bilgileri aldım
				cout << " Siparis Tarihi          :"; cin >> Siparis_Tarihi;
				cout << " Siparis Tutari          :"; cin >> Siparis_Tutari;
				cout << " Siparisi Alan           :"; cin >> Siparisi_Alan;
				cout << " Siparis Listesi         :" << endl;
				
				ofstream SiparisListesi;                                       //siparişteki ürünleri tutacak sipariş listesi dosyası oluşturdum.
				SiparisListesi.open("siparislistesi.txt", ios::app); 
				int cevap2;
				
				do
				{
					cout << " Urun Kodu                :"; cin >> Urun_Kodu;
					cout << " Urun Adedi               :"; cin >> Urun_Adedi;
					

					SiparisListesi << " " << Urun_Kodu << " " << Urun_Adedi << " " << endl;            

					cout << "Dosyaya baska urun ekleyecekmisiniz? (1=Evet / 2=Hayir)" << endl;
					cin >> cevap2;

				} while (!(cevap2 == 2));
				SiparisListesi.close();
				cout << "Siparis Listesi Dosyasina urun ekleme islemi tamamlandi. " << endl;
				

				
			    SiparisOlustur << " " << Firma_No << " " << Siparis_Tarihi << " " << Siparis_Tutari << " " << Siparisi_Alan << " " << endl;      //girilen bilgileri dosyaya yazdırdım.

				cout << "Dosyaya baska Siparis ekleyecekmisiniz? (1=Evet / 2=Hayir)" << endl;
				cin >> cevap1;

			} while (!(cevap1 == 2));
			SiparisOlustur.close();
			cout << "Dosyaya Siparis ekleme islemi tamamlandi. " << endl;
			
			system("PAUSE");
			return 0;

		}


		else if (siparis_islem_secimi == 2) {
			ifstream SiparisArama("siparis.txt", ios::in);        //muşterileri ekldiğim dosyayı okumak için açtım.
			string arananFirmaNo;                                 //aranacak firma no yu tanımaldım.
			cout << "Siparisi Aranacak Firma No :" << endl;
			cin >> arananFirmaNo;
			
			if (SiparisArama.is_open())
			{
				int x = 0;
				
				do
				{
					SiparisArama >> Firma_No >> Siparis_Tarihi >> Siparis_Tutari >> Siparisi_Alan;

					if (Firma_No == arananFirmaNo)              //aranan firma no dosyada eşleşen firma no varsa onun bilgilerini ekrana getirdim.
					{
						cout << " Firma No                :" << Firma_No << endl;
						cout << " Siparis Tarihi          :" << Siparis_Tarihi << endl;
						cout << " Siparis Tutari          :" << Siparis_Tutari << endl;
						cout << " Siparisi Alan           :" << Siparisi_Alan << endl;
						x = 1;
						return 0;
					}

				} while (!SiparisArama.eof());
				SiparisArama.close();         //dosyayı kapattım.
				
				if (x == 0) {
					cout << "Dosyada siparisi kayıtlı firma no yok!" << endl;
				}

			}
			else
				cout << "Dosya acilamadi!";
			system("PAUSE");
			return 0;
		}


        
		else if (siparis_islem_secimi == 3) {
			int gecici = 0, karar = 0;
			string sil_firma_no;
			cout << "Silinecek Siparis Firma numarasini giriniz: ";
			cin >> sil_firma_no; //silinecek siparisin firma numarası bilgisini girdirdim.

			ifstream FirmaSil("siparis.txt");
			while (!FirmaSil.eof()) //firmasil de belirttiğim siparis.txt dosyasını sonuna kadar okuttum.
			{
				FirmaSil >> Firma_No >> Siparis_Tarihi >> Siparis_Tutari >> Siparisi_Alan;

				if (Firma_No == sil_firma_no)          //eşleşen firma bilgilerini ekrana getirdim.
				{
					cout << "=========== Firma Bilgileri ==========" << endl;
					cout << " Firma No                :" << Firma_No << endl;
					cout << " Siparis Tarihi          :" << Siparis_Tarihi << endl;
					cout << " Siparis Tutarı          :" << Siparis_Tutari << endl;
					cout << " Siparis Alan            :" << Siparisi_Alan << endl;
					
                }
				
				cout << "Firmanın siparis kaydini silmek istiyor musunuz? ( 1=evet / 2=hayir )";
				int karar;
				cin >> karar;


				if (karar == 1)
				{
					ifstream SiparisDosyaOku("siparis.txt"); //dosyayı okuma amaçlı açtım
					ofstream GeciciDosyaYaz("Siparis.tmp");  //yeni bilgilerin tutualacağı tmp dosyası oluşturdum.

					while (SiparisDosyaOku >> Firma_No >> Siparis_Tarihi >> Siparis_Tutari >> Siparisi_Alan)
					{

						if (sil_firma_no != Firma_No) {
							GeciciDosyaYaz << " " << Firma_No << " " << Siparis_Tarihi << " " << Siparis_Tutari << " " << Siparisi_Alan << endl;
						}

						if (sil_firma_no == Firma_No) {
							gecici = 1;
						}
					}

					GeciciDosyaYaz.close(); //dosyaalrı kapattım.
					FirmaSil.close();
					SiparisDosyaOku.close();

					remove("siparis.txt");                   //siparis.txt dosyasını sildim.
					rename("Siparis.tmp", "siparis.txt");    //siparis.tmp dosyasını siparis.txt dosyasına kopyaladım.

					if (gecici == 0) {
						cout << "Boyle Bir Siparis Bulunmamaktadir..." << endl;
					}

					if (gecici == 1) {
						cout << "Siparis Bilgileri Silindi..." << endl;

					}
				}
				system("PAUSE");
				return 0;
			}

		}


        else if (siparis_islem_secimi == 4) {            //siparis bilgilerini satır satır okuttum.
		ifstream SiparisListele("siparis.txt");
		ifstream SiparisListesiListele("siparislistesi.txt");
		string satir = " ";

		if (SiparisListele.is_open()) {

			while (getline(SiparisListele, satir)) {
				cout << "Siparis:" << endl;
				cout << satir << endl;
				ifstream SiparisListesiListele("siparislistesi.txt");
				string satir = " ";
			}
			
			SiparisListele.close();             //dosyaları kapattım.
			SiparisListesiListele.close();
		}

		return 0;
		}






    }
}


