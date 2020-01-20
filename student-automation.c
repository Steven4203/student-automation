#include <stdio.h>
#include <stdlib.h>

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

void ogrenci_ara(ogr *ptr_ogrenci, int sayi);
void durum_goster(ogr *ptr_ogrenci, int say);
void listele(struct ogrenci *ptr_ogrenci, int say);

int main()
{
    int sayi, i, j, secim, secim_2;
    printf("Kac adet ogrenciniz oldugunu yaziniz:");
    scanf("%d", &sayi);

    ogr *ptr_ogrenci = (ogr *)malloc(sizeof(ogr) * sayi);

    if (ptr_ogrenci == NULL)
    {
        printf("Yetersiz bellek, programdan cikiliyor.");
        exit(1);
    }

    for (i = 0; i < sayi; i++)
    {
        printf("%d.Ogrencinin numarasini giriniz:", i + 1);
        scanf("%d", &(ptr_ogrenci + i)->numara);
        printf("%d.Ogrencinin adini giriniz:", i + 1);
        scanf("%s", &(ptr_ogrenci + i)->ad);
        printf("%d.Ogrencinin soyadini giriniz:", i + 1);
        scanf("%s", &(ptr_ogrenci + i)->soyad);
        printf("%d.Ogrencinin ders sayisini giriniz:", i + 1);
        scanf("%d", &(ptr_ogrenci + i)->ders_sayisi);

        (ptr_ogrenci + i)->dersler = (drs *)calloc((ptr_ogrenci)->ders_sayisi, sizeof(drs));

        if ((ptr_ogrenci + i)->dersler == NULL)
        {
            printf("Yetersiz bellek, programdan cikiliyor.");
            exit(1);
        }

        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
        {
            printf("%d.Dersin adini giriniz:", j + 1);
            scanf("%s", &((ptr_ogrenci + i)->dersler + j)->ders_adi);
            printf("%d.Dersin vize notunu giriniz:", j + 1);
            scanf("%d", &((ptr_ogrenci + i)->dersler + j)->vize_notu);
            printf("%d.Dersin final notunu giriniz:", j + 1);
            scanf("%d", &((ptr_ogrenci + i)->dersler + j)->final_notu);
        }
    }

    do
    {
        printf("1- Ogrenci Ara\n2- Durum Goster\n3- Listele\n4- Cikis\nLutfen secim yapiniz:");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            do
            {
                ogrenci_ara(ptr_ogrenci, sayi);
                printf("\n\n1-Tekrar ogrenci ara\t2-Ana Menuye don\nLutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("Tekrar ogrenci aratiliyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("Ana menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("Hatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            } while (secim_2 != 2);
            break;
        case 2:
            do
            {
                durum_goster(ptr_ogrenci, sayi);
                printf("\n\n1-Tekrar durum goster\t2-Ana Menuye don\nLutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("Tekrar durum gosteriliyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("Ana menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("Hatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            } while (secim_2 != 2);
            break;
        case 3:
            do
            {
                listele(ptr_ogrenci, sayi);
                printf("\n\n1-Tekrar Listele\t2-Ana Menuye don\nLutfen seciminizi yapiniz:");
                scanf("%d", &secim_2);
                if (secim_2 == 1)
                {
                    printf("Tekrar listeleniyor...\n");
                    continue;
                }
                else if (secim_2 == 2)
                {
                    printf("Ana menuye donduruluyor...\n");
                }
                else if (secim_2 > 2)
                {
                    printf("Hatali secim yaptiniz, ana menuye donuyorsunuz...\n");
                    break;
                }
            } while (secim_2 != 2);
            break;
        case 4:
            printf("Programdan cikiliyor...");
            break;
        default:
            printf("Hatali secim yaptiniz, lutfen tekrar deneyiniz.");
            break;
        }
    } while (secim != 4);

    return 0;
}

void ogrenci_ara(ogr *ptr_ogrenci, int sayi)
{
    int i, j, count = 0, str_size = 0;
    char aranan[20], *searched_word;
    printf("Aratmak istediginiz ogrencinin adini giriniz:");
    scanf("%s", &aranan);
    searched_word = aranan;

    while (*(aranan + str_size) != '\0')
    {
        str_size++;
    }

    for (i = 0; i < sayi; i++)
    {
        if (*(searched_word) == *((ptr_ogrenci + i)->ad))
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
                    break;
                }
            }
        }

        if (count == 1)
        {
            printf("%d- No:%d\tAdi:%s\tSoyadi:%s\nAldigi Dersler:", i + 1, (ptr_ogrenci + i)->numara, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
            for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
            {
                printf("%d.Dersin Adi:%s\tVize Notu:%d\tFinal Notu:%d\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
            }
            printf("\n\n");
        }
        count = 0;
    }
}

void durum_goster(ogr *ptr_ogrenci, int say)
{
    int i, j;
    float toplam;
    for (i = 0; i < say; i++)
    {
        printf("%d->%s %s:\n", i + 1, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
        {
            toplam = (double)(((ptr_ogrenci + i)->dersler + j)->final_notu) * 0.6 + (double)(((ptr_ogrenci + i)->dersler + j)->vize_notu) * 0.4;
            if (toplam >= 60)
            {
                printf("%d- %s ders durumu: GECTI\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi);
            }
            else
            {
                printf("%d- %s ders durumu: KALDI\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi);
            }
        }
        printf("\n");
    }
}

void listele(ogr *ptr_ogrenci, int say)
{
    int i, j;
    for (i = 0; i < say; i++)
    {
        printf("%d.Ogrencinin:\nNumarasi:%d\tAdi:%s     Soyadi:%s\nAldigi Dersler: \n", i + 1, (ptr_ogrenci + i)->numara, (ptr_ogrenci + i)->ad, (ptr_ogrenci + i)->soyad);
        for (j = 0; j < (ptr_ogrenci + i)->ders_sayisi; j++)
        {
            printf("%d.Dersin Adi:%s\tVize Notu:%d\tFinal Notu:%d\n", j + 1, ((ptr_ogrenci + i)->dersler + j)->ders_adi, ((ptr_ogrenci + i)->dersler + j)->vize_notu, ((ptr_ogrenci + i)->dersler + j)->final_notu);
        }
    }
}
