#include <stdio.h>
#include <stdlib.h>

/* Sturctlari tanimladim */
typedef struct dersler
{
    char ders_adi[100];
    int vize_notu;
    int final_notu;
} drs;

typedef struct ogrenci
{
    int numara;
    char ad[100];
    char soyad[100];
    int ders_sayisi;
    drs *dersler;
} ogr;
/* Fonksiyonlari tanimladim */
void ogrenci_ara(ogr *ptr_ogrenci, int sayi);
void durum_goster(ogr *ptr_ogrenci, int say);
void listele(struct ogrenci *ptr_ogrenci, int say);

int main()
{
    int sayi, i, j, secim, secim_2;
    printf("Kac adet ogrenciniz oldugunu yaziniz:"); /* Ogrenci bilgilerini alma */
    scanf("%d", &sayi);

    ogr *ptr_ogrenci = (ogr *)malloc(sizeof(ogr) * sayi); /* Dinamik bellek ayirma */

    if (ptr_ogrenci == NULL) /* Bellek kontrolu */
    {
        printf("Yetersiz bellek, programdan cikiliyor.\n");
        exit(1);
    }

    for (i = 0; i < sayi; i++) /* Ogrenci bilgilerini alma */
    {
        printf("**************************************************\n");
        printf("%d.Ogrencinin numarasini giriniz:", i + 1);
        scanf("%d", &(ptr_ogrenci + i)->numara);
        printf("Iki adi olan ogrenciler icin iki isim arasina '_' kullaniniz\n");
        printf("%d.Ogrencinin adini giriniz:", i + 1);
        scanf("%s", &(ptr_ogrenci + i)->ad);
        printf("%d.Ogrencinin soyadini giriniz:", i + 1);
        scanf("%s", &(ptr_ogrenci + i)->soyad);
        printf("%d.Ogrencinin ders sayisini giriniz:", i + 1);
        scanf("%d", &(ptr_ogrenci + i)->ders_sayisi);

        (ptr_ogrenci + i)->dersler = (drs *)calloc((ptr_ogrenci)->ders_sayisi, sizeof(drs)); /* Ders icin alan ayirme */

        if ((ptr_ogrenci + i)->dersler == NULL) /* Bellek kontrolu */
        {
            printf("Yetersiz bellek, programdan cikiliyor.");
            exit(1);
        }

        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++) /* Ders bilgileri alinma */
        {
            printf("\t%d.Ogrencinin %d.Dersinin adini giriniz:", i + 1, j + 1);
            scanf("%s", &((ptr_ogrenci + i)->dersler + j)->ders_adi);
            printf("\t%d.Ogrencinin %d.Dersin vize notunu giriniz:", i + 1, j + 1);
            scanf("%d", &((ptr_ogrenci + i)->dersler + j)->vize_notu);
            printf("\t%d.Ogrencinin %d.Dersin final notunu giriniz:", i + 1, j + 1);
            scanf("%d", &((ptr_ogrenci + i)->dersler + j)->final_notu);
        }
    }

    /* Her fonksiyon icin menuye donus saglayan do-while kullandim */

    do
    {
        printf("\n**************************************************\n");
        printf("\n\n1- Ogrenci Ara\n2- Durum Goster\n3- Listele\n4- Cikis\n\n***Lutfen secim yapiniz:");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1: /* Ogrenci ara */
            do
            {
                ogrenci_ara(ptr_ogrenci, sayi);
                printf("\n\n**************************************************");
                printf("\n1-Tekrar ogrenci ara\t2-Ana Menuye don\n\n***Lutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("\nTekrar ogrenci aratiliyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("\nAna menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("\nHatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            }
            while (secim_2 != 2);
            break;
        case 2: /* Durum goster */
            do
            {
                durum_goster(ptr_ogrenci, sayi);
                printf("\n\n**************************************************");
                printf("\n1-Tekrar durum goster\t2-Ana Menuye don\n\n***Lutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("\nTekrar durum gosteriliyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("\nAna menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("\nHatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            }
            while (secim_2 != 2);
            break;
        case 3: /* Listele */
            do
            {
                listele(ptr_ogrenci, sayi);
                printf("\n\n**************************************************");
                printf("\n1-Tekrar listele\t2-Ana Menuye don\n\n***Lutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("\nTekrar listeleniyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("\nAna menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("\nHatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            }
            while (secim_2 != 2);
            break;
        case 4: /* Cikis kismi */
            printf("Programdan cikiliyor...");
            break;
        default:
            printf("Hatali secim yaptiniz, lutfen tekrar deneyiniz.");
            break;
        }
    }
    while (secim != 4);

    return 0;
}

void ogrenci_ara(ogr *ptr_ogrenci, int sayi)
{
    int i, j, count = 0, str_size = 0, sec_count = 0;
    char aranan[20], *searched_word;
    printf("\nAratmak istediginiz ogrencinin adini giriniz:"); /* Ogrenci arama kismi */
    scanf("%s", &aranan);
    searched_word = aranan;

    while (*(aranan + str_size) != '\0') /* Aratilan kelimenin uzunlugunu alma */
    {
        str_size++;
    }

    for (i = 0; i < sayi; i++)
    {
        if (*(searched_word) == *((ptr_ogrenci + i)->ad)) /* Aratilan kelime ile aranan kelimenin eslestigini kontrol eden algoritma */
        {
            for (j = 1; j < str_size; j++)
            {
                if (*(searched_word + j) != *((ptr_ogrenci + i)->ad + j))
                {
                    break;
                }
                else if (*(searched_word + str_size) == *((ptr_ogrenci + i)->ad + str_size))
                {
                    count++;
                    sec_count++;
                    break;
                }
            }
        }

        if (count == 1) /* Eslesen kisilerin bilgilerini yazdirma */
        {
            printf("%d- No:%d\tAdi:%s\tSoyadi:%s\nAldigi Dersler:\n", i + 1, (ptr_ogrenci + i)->numara, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
            for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
            {
                printf("%d->%s\tVize Notu:%d\tFinal Notu:%d\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
            }
            printf("\n\n");
        }
        count = 0;
    }
    if (sec_count == 0) /* Ogrenci bulunamamasi durumunda bilgi verilmesi */
    {
        printf("Ogrenci bulunamadi...\n");
        printf("\n\n");
    }
}

void durum_goster(ogr *ptr_ogrenci, int say) /* Ogrencilerin gecme kalma durumunu gosteren kisim */
{
    int i, j;
    float toplam;
    for (i = 0; i < say; i++)
    {
        printf("%d->%d      %s %s:\n", i + 1, (ptr_ogrenci + i)->numara, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
        {
            toplam = (double)(((ptr_ogrenci + i)->dersler + j)->final_notu) * 0.6 + (double)(((ptr_ogrenci + i)->dersler + j)->vize_notu) * 0.4;
            if (toplam >= 60)
            {
                printf("%d->%s Vize Notu:%d Final Notu:%d Durumu: GECTI\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
            }
            else
            {
                printf("%d->%s Vize Notu:%d Final Notu:%d Durumu: KALDI\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
            }
        }
        printf("\n");
    }
}

void listele(ogr *ptr_ogrenci, int say) /* Ogrenci listeleme kismi */
{
    int i, j;
    for (i = 0; i < say; i++)
    {
        printf("\n%d.Ogrencinin:\nNumarasi:%d\tAdi:%s     Soyadi:%s\nAldigi Dersler: \n", i + 1, (ptr_ogrenci + i)->numara, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
        {
            printf("\t%d->%s\tVize Notu:%d\tFinal Notu:%d\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
        }
    }
}
