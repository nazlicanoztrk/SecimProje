#include <stdio.h>
#include <stdlib.h>


int PartiSayisi=0;//Secime katilan parti sayisi
/* Fonksiyon Prototipleri*/
/* Fonksiyonlar main fonksiyonunun kronolojik olarak altinda tanimladiði icin derleyici main fonksiyonunu derledigi esnada
   bu fonksiyonlari anlamlandirabilmesi ioin kendisinden once fonksiyonlarin imzalarinin birer prototip olarak tanimlanmasini gerektirir.*/
int** MvSay(int SehirSecim[PartiSayisi][5], int PartiSayisi, int MvKontenjan,int Oylar[PartiSayisi][2]);
int** Guncelle(int GenelSecim[PartiSayisi][5],int SehirSecim[PartiSayisi][5], int PartiSayisi);
int** BubbleSort(int SehirSecim[PartiSayisi][5], int PartiSayisi);
int BirinciyiBul(int SehirSecim[PartiSayisi][5], int PartiSayisi);
void UlkeSonucuYazdir(int GenelSecim[PartiSayisi][5], int PartiSayisi, int ToplamGecerliOy, int ToplamMvSayisi );
int ikinciyiBul(int SehirSecim[PartiSayisi][5], int PartiSayisi, int BirincininAdi);

int main()
{
    int PlakaKod;//Sehir Plaka Kodu
    int MvKontenjan;//Sehir Milletvekili kontenjani


    //Parti sayisinin alinmasi
    printf("Parti Sayisi Giriniz: ");
    scanf("%d",&PartiSayisi);

    int GenelSecim[PartiSayisi][5];//Genel secim bilgilerinin tutulduðu dizi
    int Oylar[PartiSayisi][2];//Oylarin tutuldugu dizi
    int SehirSecim[PartiSayisi][5];//Sehir secim bilgilerinin tutuldugu dizi

    /* Dizilere baslangic degerlerinin verilmesi*/
    int i,j,a=65,b=65;
    for(i=0;i<PartiSayisi;i++){
        Oylar[i][0]=0;
        Oylar[i][1]=0;
        GenelSecim[i][0]=a++;
        SehirSecim[i][0]=b++;

        for(j=1;j<5;j++){
            GenelSecim[i][j]=0;
            SehirSecim[i][j]=0;
        }
    }

    int ToplamGecerliOyUlkeGeneli=0;//Ulke genelinde toplam oy sayisinin tutuldugu degisken
    int ToplamMvSayisi=0;//Ulke Genelinde Toplam Millet vekili sayisinin tutuldugu degisken
    /* Oy verme islemleri*/
    while(1>0){
        //Plaka Kodunun alinmasi
        printf("il plaka kodu giriniz: ");
        scanf("%d", &PlakaKod);

        int** tempGenelSecim;//Genel secimin tutuldugu pointer

        /* Plaka Kodunun sifir girilmesi halinde Ulke Secim sonucunun yazdirilmasi*/
        if(PlakaKod == 0){
            UlkeSonucuYazdir(GenelSecim, PartiSayisi,ToplamGecerliOyUlkeGeneli,ToplamMvSayisi);
            break;
        }
        int ToplamGecerliOySehirGeneli=0;//Toplam verilmis sehir oylarýnýn  toplaminin tutuldugu degisken
        /*Millet Vekili kontenjaninin alinmasi*/
        printf("Millet vekili kontenjani giriniz: ");
        scanf("%d", &MvKontenjan);
        ToplamMvSayisi += MvKontenjan;//Alinan millet vekili kontenjaninin ulke geneli icin baska bi degiskende saklanmasi
        int i;
        int PartiAdi=65;//Parti adinin a harfinden baslamasi icin gerekli olan ASCII kodu


        /*Oy verme islemi*/
        for(i=0;i<=PartiSayisi-1;i++)
        {
            Oylar[i][0]=PartiAdi;//Oylar dizisinin ilgili konumuna PartiAdi nin atanmasi

            /*Oy alip Oylar dizisinde Saklama islemi*/
            printf("%c Partisinin Aldigi Oy Sayisi: ",PartiAdi++);
            scanf("%d", &Oylar[i][1]);
            GenelSecim[i][1]+=Oylar[i][1];//Alinan oylarin ulke secim bilgilerine eklenmesi
            ToplamGecerliOySehirGeneli+=Oylar[i][1];//Oylarin sehir oy bilgilerinin ustune eklenmesi
            ToplamGecerliOyUlkeGeneli+=Oylar[i][1];//oylarin ulke oy bilgilerinin ustune eklenmesi
            SehirSecim[i][1]+=Oylar[i][1];//SehirSecim icindeki oylar indisine eklenmesi
        }

        printf("il Plaka Kodu: %d \n",PlakaKod);//Plaka kodunun cikti olarak yazdirilmasi
        printf("Millet Vekili Kontenjan: %d \n",MvKontenjan);//Millet Vekili Kontenjaninin cikti olarak yazdirilmasi
        printf("Gecerli Oy: %d \n", ToplamGecerliOySehirGeneli);//Toplam Gecerli oy bilgilerinin yazdirilmasi

        int** tempSehirSecim = MvSay(SehirSecim,PartiSayisi,MvKontenjan,Oylar);//tempsehirsecim pointerina millet vekili sayimi yapilmis halde sehir secim sonuclarinin atanmasi
        SehirSonucuYazdir(SehirSecim, PartiSayisi, ToplamGecerliOySehirGeneli);//Sehir secim sonuclarinin yazdirilmasi
        tempGenelSecim = Guncelle(GenelSecim, SehirSecim, PartiSayisi);//Genel secim sonuclarina Sehir secim sonuclarinin eklenmesi
    }


    return 0;
}
/* Genel secim sonuclarina Sehir secim sonuclarinin eklenip guncellenmesi*/
int** Guncelle(int arrayOne[PartiSayisi][5],int arrayTwo[PartiSayisi][5], int PartiSayisi){
    int i,j, swapVal=0;
    for(i=0;i<PartiSayisi;i++){
        for(j=0;j<PartiSayisi;j++){
            if(arrayOne[i][0]==arrayTwo[j][0]){
                    swapVal = arrayTwo[j][2];
                    arrayOne[i][2]+= swapVal;
                    swapVal = arrayTwo[j][3];
                    arrayOne[i][3]+=swapVal;
                    swapVal = arrayTwo[j][4];
                    arrayOne[i][4]+=swapVal;

                    arrayTwo[j][1]=0;
                    arrayTwo[j][2]=0;
                    arrayTwo[j][3]=0;
                    arrayTwo[j][4]=0;
            }
        }
    }
    return arrayOne;
}
/*Millet vekili sayisini hesaplayan ve sehir secim sonuclarini hazirlayan fonksiyon */
int** MvSay(int SehirSecim[PartiSayisi][5], int PartiSayisi, int MvKontenjan,int Oylar[PartiSayisi][2])
{
        int** sortArray=BubbleSort(SehirSecim,PartiSayisi);//siralanmis dizi bilgisinin bubblesort tan alinmasi
        int i,j;
        int BirinciPartiAdi;
        /*Millet vekili sayilarinin hesaplanmasi*/
        for(i=0;i<MvKontenjan;i++){
            SehirSecim[0][2]++;
            SehirSecim[0][1]=SehirSecim[0][1]/2;
            SehirSecim=BubbleSort(SehirSecim,PartiSayisi);
        }

        BirinciPartiAdi = BirinciyiBul(SehirSecim,PartiSayisi);//Sehirdeki iktidar partisini bulan fonksiyondan donen degerin parti adina cevrilmesi
        SehirSecim[BirinciPartiAdi][3]++;//Birincilik bilgisinin gucellenmesi
        /* Sifir Millet vekili cikaranlarin bilgilerinin guncellenmesi*/
        for(i=0;i<PartiSayisi;i++)
        {
            if(SehirSecim[i][2]==0){
               SehirSecim[i][4]++;
            }
        }
        /*Oylarin Baslangic hallerine geri getirilmesi*/
        int oyVal=0;
        for(i=0;i<PartiSayisi;i++){
            for(j=0;j<PartiSayisi;j++){
                if(SehirSecim[i][0]==Oylar[j][0]){
                    oyVal=Oylar[j][1];
                    SehirSecim[i][1]=oyVal;
                }
            }
        }

        SehirSecim = BubbleSort(SehirSecim,PartiSayisi);//Sehir secim bilgisinin siralanmasi

        return SehirSecim;
}
/* Sehir sonuclarini yazdiran fonksiyon*/
void SehirSonucuYazdir(int SehirSecim[PartiSayisi][5], int PartiSayisi, int ToplamGecerliOy){

        printf("\t\t     Oy Say \t Oy Yuzde \t MV Say\n");
        printf("\t\t     ------ \t -------- \t ------\n");
        int k;
        float OyYuzde=0.00;
        for(k=0;k<PartiSayisi;k++){
            OyYuzde = ((float)SehirSecim[k][1]/(float)ToplamGecerliOy)*100;
            printf("%c Partisi \t\t %d \t\t %.2f \t\t %d \n",SehirSecim[k][0],SehirSecim[k][1],OyYuzde,SehirSecim[k][2]);
        }

}
/* Ulke secim sonuclarini yazdiran fonksiyon*/
void UlkeSonucuYazdir(int GenelSecim[PartiSayisi][5], int PartiSayisi, int ToplamGecerliOy, int ToplamMvSayisi ){

        printf("------Turkiye Geneli------\n\n");
        printf("Milletvekili Kontenjani: %d\n",ToplamMvSayisi);
        printf("Gecerli Oy Sayisi      : %d\n\n\n",ToplamGecerliOy);
        printf("\t\t     Oy Say \t Oy Yuzde \t MV Say \t Mv Yuzde \t il 1.lik Say \t 0 Mv Say \n");
        printf("\t\t     ------ \t -------- \t ------ \t -------- \t ------------ \t -------- \n");
        int k;
        float OyYuzde=0.00;
        float MvYuzde=0.00;
        for(k=0;k<PartiSayisi;k++){
            OyYuzde = ((float)GenelSecim[k][1]/(float)ToplamGecerliOy)*100;
            MvYuzde = ((float)GenelSecim[k][2]/(float)ToplamMvSayisi)*100;
            printf("%c Partisi \t\t %d \t\t %.2f \t\t %d \t\t %.2f \t\t %d \t\t %d \n\n\n",
               GenelSecim[k][0],GenelSecim[k][1],OyYuzde,GenelSecim[k][2],MvYuzde,GenelSecim[k][3],GenelSecim[k][4]);
        }
        /* Iktidar ve muhalefet partilerinin genel secim sonuclari icerisindeki konumlarinin bulunup yazdirilmasi*/
        int iktidar=BirinciyiBul(GenelSecim,PartiSayisi);
        int muhalefet=ikinciyiBul(GenelSecim,PartiSayisi,GenelSecim[iktidar][0]);
        printf("iktidar Partisi: %c - Partisi\n",GenelSecim[iktidar][0]);
        printf("Ana Muhalefet Partisi: %c - Partisi\n",GenelSecim[muhalefet][0]);
}
    /* Gonderilen ve istenilen sehirdeki veya ulke genelindeki birinciyi bulan fonksiyon*/
int BirinciyiBul(int SehirSecim[PartiSayisi][5], int PartiSayisi)
{
    int i,j;
    int MaxParti=0;
    int MaxMv=SehirSecim[0][2];
    int MaxOy=SehirSecim[0][1];
    for(i=1;i<PartiSayisi;i++)
    {
        if(MaxMv<SehirSecim[i][2])
        {
            MaxMv=SehirSecim[i][2];
            MaxOy=SehirSecim[i][1];
            MaxParti=i;
        }
        if(MaxMv==SehirSecim[i][2] && MaxOy<SehirSecim[i][1])
        {
            MaxMv=SehirSecim[i][2];
            MaxOy=SehirSecim[i][1];
            MaxParti=i;
        }
    }
    return MaxParti;//Maksimum oyu alan partiyi bulma
}
/* Muhalefeti bulmak icin kullanilan fonksiyon*/
int ikinciyiBul(int SehirSecim[PartiSayisi][5], int PartiSayisi, int BirincininAdi)
{
    int i,j,k;
    int MaxParti=0;
    int MaxMv=0;
    int MaxOy=0;
    for(k=0;k<PartiSayisi;k++){
        if(SehirSecim[k][0]!=BirincininAdi)
        {
        MaxMv=SehirSecim[k][2];
        MaxOy=SehirSecim[k][1];
        MaxParti=k;
        break;
        }
    }
    for(i=0;i<PartiSayisi;i++)
    {
        if(SehirSecim[i][0]!=BirincininAdi && i!=k)
        {
             if(MaxMv<SehirSecim[i][2])
        {
            MaxMv=SehirSecim[i][2];
            MaxOy=SehirSecim[i][1];
            MaxParti=i;
        }
        if(MaxMv==SehirSecim[i][2] && MaxOy<SehirSecim[i][1])
        {
            MaxMv=SehirSecim[i][2];
            MaxOy=SehirSecim[i][1];
            MaxParti=i;
        }
        }

    }
    return MaxParti;
}
/* Bubble Sort Siralama Algoritmasi : siralama icin swap yapýlma asamasi*/
int** BubbleSort(int SehirSecim[PartiSayisi][5], int PartiSayisi)
{
     int i,j,swapOy,swapMvSay,swapBir,swapSifir,swapParti;
    for(i=0;i<PartiSayisi-1;i++){
        for(j=0;j<PartiSayisi-i-1;j++)
        {
            if (SehirSecim[j][1]<SehirSecim[j+1][1])
            {
                swapParti=SehirSecim[j+1][0];
                swapOy=SehirSecim[j+1][1];
                swapMvSay=SehirSecim[j+1][2];
                swapBir=SehirSecim[j+1][3];
                swapSifir=SehirSecim[j+1][4];

                SehirSecim[j+1][0]=SehirSecim[j][0];
                SehirSecim[j+1][1]=SehirSecim[j][1];
                SehirSecim[j+1][2]=SehirSecim[j][2];
                SehirSecim[j+1][3]=SehirSecim[j][3];
                SehirSecim[j+1][4]=SehirSecim[j][4];

                SehirSecim[j][0] = swapParti;
                SehirSecim[j][1] = swapOy;
                SehirSecim[j][2] = swapMvSay;
                SehirSecim[j][3] = swapBir;
                SehirSecim[j][4] = swapSifir;


            }
        }


}
return SehirSecim;


}


