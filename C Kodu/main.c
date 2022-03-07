#include <stdio.h>// giri� ��k�� fonsiyonlar�n� kapsar.
#include <conio.h>// getch fonksiyonu kullan�ld��� i�in eklenmi�tir.
#include <string.h>// strcmp fonksiyonu i�in eklenmi�tir.
#include <stdlib.h>// system fonksiyonu i�in eklenmi�tir.

struct urunler // urunler ad�nda bir yap� olu�turuyoruz b�yece s�n�fland�rmak daha kolay oluyor.
{
    char kategori[20];
    char marka[20];
    char model[20];
    char fiyat[20];
};

struct uye // uye ad�nda bir yap� olu�turuyoruz b�ylece s�n�fland�rmak kolayla��yor.
{
    char adi[20];
    char sifre[20];
};

void tercih();
void kayit();
void listele();
void bul();
void sil();
void guncelle();
void uye();
void panel();
void giris();
void menuyedon();

int main()
{
    panel();// panel �a��r�l�yor.

    getch();
    return 0;
}

void panel() // amac� kay�t olmak giris yapmak ve c�k�s yapmak seceneklerini kulan�c�ya g�stermektir.
{
    char secim; // karakter dizisi
    printf("Elektronik Urun Otomasyonu\n");
    printf("1:Kayit olmak icin\n");
    printf("2:Giris yapmak icin\n");
    printf("3:Cikis\n");
    printf("Bir islem secin.\n");
    secim = getch(); // getch fonksiyonu karakter almaya yarar ama karakteri ekranda g�stermez.bir karakterlik verial�yoruz.

    switch (secim)// ald���m�z bir karakterlik verileri k�yaslayarak istenen fonksiyonlar� �a��r�yoruz.
    {
    case '1':
    {
        system("cls");// cmd ekran�n� temizlemeye yarar.
        uye();
        break;
    }
    case '2':
    {
        system("cls");
        giris();
        break;
    }
    case '3':
    {
        system("cls");
        printf("Cikis Yapiliyor.");
        exit(1);
        break;
    }
    default:
    {
        system("cls");
        printf("Yanlis islem sectiniz.\n");
        panel();
        break;
    }
    }
}

void uye()
{
    struct uye giris[50];// �nceden girilen verileri  almak i�i uye yap�s�ndan giris degiskeni olu�turuyoruz.
    struct uye kayit;// kulan�c�n�n girdi�i verileri kaydetmek i�in �ye yap�s�ndan kay�t degiskeni olu�turuyoruz.
    int i; // index de�i�keni
    printf("Kullanici adinizi girin:");//kullan�c�dan bilgilerini girmesini isteriz.
    scanf("%s", kayit.adi);
    printf("Sifrenizi girin:");
    scanf("%s", kayit.sifre);
    printf("\n");
    FILE *veritabani;// dosya de�i�keni olu�turuldu.
    veritabani = fopen("uyeler.txt", "r");// r modu a�ar ve okur.
    for (i = 0; !feof(veritabani); i++)
    {
        fscanf(veritabani, "%s%s", giris[i].adi, giris[i].sifre);// 2 adet %s oldu�undan dolay� her d�ng�de 
        // 2 adet string ifadeyi al�p giri� de�i�keninin i. indeksine adi ve sifresine at�yoruz.
    }
    for (i = 0; i < 20; i++)// dosyan�n sonuna kadar i birer birer artar
    {
        if (strcmp(kayit.adi, giris[i].adi) == 0)// strcmp fonksiyonu kar��la�t�rma i�lemi yapar.
// kay�t yap�lacak kayit adi ile �nceden kay�t edilen kay�t adlar�n� kr��la�trma yapar.
        {
            printf("Bu kullanici adi onceden alinmistir.\n");// kullan�c� bilgilendirir.
            fclose(veritabani);// dosya kapat�lm��t�r.
            uye(); // tekrar uye fonksiyonu �al��t�r�l�r ki tekrar deneyebilsin.
        }
    }
    veritabani = fopen("uyeler.txt", "a");//eger herhangi bir sorun ile kar��la��lmaz ise uye ekleme i�in �nceki 
    // verileri kaybetmeden dosya yazmak �zere a��l�r.
    fprintf(veritabani, "\n%s %s", kayit.adi, kayit.sifre);// dosyaya yazma i�lemi yap�lm��t�r.
    fclose(veritabani);// dosya kapat�lm��t�r. 
    printf("\n Kaydiniz Gerceklesti.\n");// kullan�c� bilgilendirilir.
    panel();// panele geri d�neriz.
}

void giris()
{
    struct uye giris[50];
    FILE *veritabani;
    char kullaniciadi[] = " ";// hata almamak i�in " " kullan�lm��t�r.
    char sifre[] = " ";
    veritabani = fopen("uyeler.txt", "r");// dosyadan okuma modu ger�ekle�mi�tir.
    int i = 0;
    for (i = 0; !feof(veritabani); i++)
    {
        fscanf(veritabani, "%s%s", giris[i].adi, giris[i].sifre);
    }
    printf("Lutfen kullanici adinizi giriniz:");
    scanf("%s", kullaniciadi);
    printf("Lutfen sifrenizi girin:");
    scanf("%s", sifre);
    for (i = 0; i < 20; i++)
    {
        if (strcmp(kullaniciadi, giris[i].adi) == 0)
        {
            if (strcmp(sifre, giris[i].sifre) == 0)
            {
                printf("\nGiris Basarili\n");
                fclose(veritabani);
                tercih();// tercih fonsiyonu �a��r�lm��t�r.
            }
        }
    }
    printf("Giris basarisiz.\n");
    fclose(veritabani);
    panel();
}

void menuyedon() 
{
    printf("Menuye Donmek istiyorsaniz 1 basin.\n");
    char menu = getch();
    if (menu == '1')
    {
        tercih();
    }
    else
    {
        exit(1);
    }
}
void tercih()// kay�tl� �yemizden �r�nler tercihi yapmas� istenmi�tir.
{

    char secim;
    printf("Elektronik Urun Otomasyonu\n");
    printf("1:Kayit Ekle\n");
    printf("2:Urunleri Listele\n");
    printf("3:Urun Bul\n");
    printf("4:Urun Sil\n");
    printf("5:Urun Guncelle\n");
    printf("6:Cikis\n");
    printf("Bir islem secin.");
    secim = getch();

    switch (secim)
    {
    case '1':
    {
        system("cls");
        kayit();
        menuyedon();

        break;
    }
    case '2':
    {
        system("cls");
        listele();
        menuyedon();
        break;
    }
    case '3':
    {
        system("cls");
        bul();
        menuyedon();
        break;
    }
    case '4':
    {
        system("cls");
        sil();
        menuyedon();
        break;
    }
    case '5':
    {
        system("cls");
        guncelle();
        menuyedon();
        break;
    }
    case '6':
    {
        system("cls");
        printf("Cikis yapildi");
        exit(0);
        break;
    }
    default: //  olas� terciherin girilmesi durumunda devreye girer.
    {
        system("cls");// cmd ekran�n� temizler.
        printf("Yanlis islem sectiniz.");
        menuyedon();// menuyedon fonksiyounu �a��r�r.
        break; // ��kar.
    }
    }
}

void kayit()
{

    struct urunler kayit;// urunler yap�s�ndan kayit ad�nda bir yap� olu�turulur.
    printf("lutfen bir kategori giriniz:");
    scanf("%s", kayit.kategori);
    printf("lutfen bir marka giriniz:");
    scanf("%s", kayit.marka);
    printf("lutfen bir model giriniz:");
    scanf("%s", kayit.model);
    printf("lutfen urunun fiyatini giriniz");
    scanf("%s", kayit.fiyat);
    printf("\n");

    FILE *kaydet;
    kaydet = fopen("urunler.txt", "a");// urunler.txt dosyas�na ekleme yapar.

    fprintf(kaydet, "\n%s %s %s %s", kayit.kategori, kayit.marka, kayit.model, kayit.fiyat);// dosyaya yazdr.
    fclose(kaydet);// dosyay� kapat�r.
}

void listele()
{
    struct urunler liste[20];
    FILE *listele;
    listele = fopen("urunler.txt", "r");
    int i = 0;
    for (i = 0; !feof(listele); i++)
    {
        fscanf(listele, "%s%s%s%s", liste[i].kategori, liste[i].marka, liste[i].model, liste[i].fiyat);
        printf("Kategori:%s\n", liste[i].kategori);// ekrana kategoriyi basar.
        printf("Marka:%s\n", liste[i].marka);// ekrana markay� basar.
        printf("Model:%s\n", liste[i].model);// ekrana modeli basar.
        printf("Fiyati:%s\n\n", liste[i].fiyat);// ekrana listeyi basar.
    }

    fclose(listele);// listele dosyas�n� kapat�r.
}
void bul()
{

    struct urunler bulun[20];
    FILE *bul;
    char kelime[] = " ";
    bul = fopen("urunler.txt", "r");
    int i = 0;
    for (i = 0; !feof(bul); i++)
    {
        fscanf(bul, "%s%s%s%s", bulun[i].kategori, bulun[i].marka, bulun[i].model, bulun[i].fiyat);
    }
    printf("Lutfen aranacak kategoriyi giriniz:");
    scanf("%s", kelime);
    for (i = 0; i < 20; i++)
    {
        if (strcmp(kelime, bulun[i].kategori) == 0)
        {
            printf("Kategori:%s\n", bulun[i].kategori);
            printf("Marka:%s\n", bulun[i].marka);
            printf("Model:%s\n", bulun[i].model);
            printf("Fiyati:%s\n\n", bulun[i].fiyat);
        }
    }
    fclose(bul);
}

void sil()
{

    struct urunler silinecek[20];
    FILE *sil;
    char kelime[] = " ";
    sil = fopen("urunler.txt", "r");
    int i = 0;
    int sayac = 0;
    int bulundu = 0;
    for (i = 0; !feof(sil); i++)
    {
        sayac++;
        fscanf(sil, "%s%s%s%s", silinecek[i].kategori, silinecek[i].marka, silinecek[i].model, silinecek[i].fiyat);
    }
    printf("Lutfen siliecek modeli giriniz:");
    scanf("%s", kelime);
    for (i = 0; i < 20; i++)
    {
        if (strcmp(kelime, silinecek[i].model) == 0)
        {
            bulundu = i;
        }
    }
    fclose(sil);
    FILE *yeni;
    yeni = fopen("urunler.txt", "w");

    for (i = 0; i < sayac; i++)
    {
        if (bulundu == i)
        {
            continue; // atlar.
        }
        fprintf(yeni, "\n%s %s %s %s", silinecek[i].kategori, silinecek[i].marka, silinecek[i].model, silinecek[i].fiyat);
    }

    fclose(yeni);
}

void guncelle()
{
    struct urunler bulun[20];
    FILE *bul;
    int bulundu = 0;
    int sayac = 0;
    char kelime[] = " ";
    bul = fopen("urunler.txt", "r");// okuma modunda a��lm��t�r.
    int i = 0;
    for (i = 0; !feof(bul); i++)
    {
        fscanf(bul, "%s%s%s%s", bulun[i].kategori, bulun[i].marka, bulun[i].model, bulun[i].fiyat);
        sayac += 1;
    }
    printf("Lutfen duzenlecek urunun modelini giriniz:");
    scanf("%s", kelime);
    for (i = 0; i < sayac; i++)
    {
        if (strcmp(kelime, bulun[i].model) == 0)
        {
            printf("Guncellenecek urunun yeni kategorisini girin:");
            scanf("%s", bulun[i].kategori);
            printf("Guncellenecek urunun yeni markasini girin:");
            scanf("%s", bulun[i].marka);
            printf("Guncellenecek urunun yeni modelini girin:");
            scanf("%s", bulun[i].model);
            printf("Guncellenecek urunun yeni fiyatini girin:");
            scanf("%s", bulun[i].fiyat);
            bulundu = 1;
            break;
        }
    }
    fclose(bul);
    if (bulundu == 0)
    {
        printf("\nGuncellemek istediginiz model bulunamadi.\n");
        guncelle();
    }
    else
    {
        FILE *yeni;
        yeni = fopen("urunler.txt", "w"); // yazma modunda a��lm��t�r.
        for (i = 0; i < sayac; i++)
        {
            fprintf(yeni, "\n%s %s %s %s", bulun[i].kategori, bulun[i].marka, bulun[i].model, bulun[i].fiyat);
        }
        printf("\n***Urun Basariyla guncellendi***\n");
        fclose(yeni);// yeni dosyas� kapat�lm��t�r.
    }
}
