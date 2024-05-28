# cpp-ile-dosya-islemleri
Bilgisayar ürünleri satış yapan bir firma düşünün,  
Firma ürünlerini (urun.txt) dosyasında tutmaktadır. Bu dosyada
Urun Kodu (tekil olacak)
Ürün adı
Üreticisi
Temin süresi
Üretim tarihi
Fiyat (genel müşteri)
Fiyat ozel( iyi müşteriler)
Kdv oranı
Stok adedi
…
Müşterilerini kaydetmek için cari.txt dosyasında tutulacak bilgiler
Firma No(tekil)
Firma adı
Firma telefon
Firma sorumlusu
Musteri katagorisi(genel/ozel)
Adres
…

şeklindedir.

Siparişleri tutmak için (sipariş.txt) bu dosyada yer alacaklar.
Firma No
Sipariş tarihi
Sipariş tutarı
Sipariş listesi dosyası (örneğin xyz)
Siparişi alan

Olsun. Sipariş listesin dosyasının adı(örneğin xyz de) yer alacaklar.
Ürün kodu
Ürün adedi
…

Yukarıda dosyalarda tutulacak bilgiler verilmiştir. İhtiyaç duymanız durumunda ilave kayıt alanı oluşturabilirsiniz(…) ilave yapabileceğiniz alanları belirtir.


Urun için işlemler

Ürün ekleme
Ürün arama
Ürün listeleme
Ürün düzeltme
Ürün silme

Müşteri dosyası işlemleri
Müşteri ekle
Müşteri arama
Müşteri düzeltme.
Müşteri silme

Sipariş için 

Sipariş oluştur
Sipariş arama
Sipariş silme
Sipariş düzeltme
Sipariş raporlama

Gerçekleştirilecektir.

Çoklu dosya yönetimi 

Uygulamada tek bir dosya kullanımı genellikle yetersiz kalmaktadır. Gerek veri tekrarını önlemek, veri organizasyonunu sağlamak üzere çok sayıda ve bir biri ile ilişkili dosyalarda verilerimizi tutarız. Örneğin hastaların kayıtlarının tutulmasında hastanın değişmeyen ad, soy ad, tel,  doğum tarihi vb. bilgileri yanında, hastanın her muayene olduğundaki bilgileri vardır. Muayene bilgileri hasta için sık değişen bir veridir. Ayrı bir dosyada tutulması zorululuk gerektirir. Bu durumda en azından iki farklı dosya ile veri manipülasyonu gerçekleştirilmelidir. Şekil de dosyalar için muhtemel alanlar verilmiştir. 
