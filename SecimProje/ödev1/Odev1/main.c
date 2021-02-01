#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float tumcalisanodenen,devletaylikgelirver,ayliktoplambrutucret=0,ayliktoplamnetucret=0,enyukbrut=0,netenyukbrut=0;
    int girilenpersonelsayisi=0,ikibindenazalanlar=0,gv15=0,gv20=0,gv27=0,gv35=0,tumcalevli=0,
    tumcalbekar=0,evlicalisesdurum=0,tumcocuksayisi=0,tumcocuklucalisan=0,ucdenfazla=0,engellicalisan=0;

    char enyukad[50],enyuksoyad[50],enyuktc[50];
    float enyukgelver=0,enyuknetucret=0;
    char netenyukad[50],netenyuksoyad[50],netenyuktc[50];
    float netenyukgelver=0,netenyuknetucret=0;


    char personeldevam;
    do{
        girilenpersonelsayisi++;
        int cocuksayisi,cocukyasi,odenek=0,engelorani,muaftutar,es_yardimi=0;
    char ad[50],soyad[50],medenidurum,esdurum,engeldurumu,tcno[50];
    float brut_ucret,aylik_net_maas,netucret,engelburutucret,gelirvergisi;

    printf("TC Kimlik Numara Giriniz: ");
    scanf("%s",tcno);

    printf("Ad Giriniz:");
   scanf("%s",ad);
    printf("Soyad Giriniz:");
    scanf("%s",soyad);




    printf("Calisan Maasi Giriniz: ");
    scanf("%f",&aylik_net_maas);
    if(aylik_net_maas<1777.50){
        aylik_net_maas=1777.50;
    }


    char medenidogrumu='y';
  do{
    printf("Medeni Durum(Evliyse E veya e,Bekar ise B veya b): ");
    scanf("%s",&medenidurum);
     if(medenidurum=='E' || medenidurum=='e'){

            tumcalevli++;
        char esdogrumu='y';
        do{
            printf("Es Calisma Durumu(Evet ise E veya e,Hayir ise H veya h): ");
         scanf("%s",&esdurum);
         if(esdurum=='E' || esdurum=='e'){
            evlicalisesdurum++;
            brut_ucret=aylik_net_maas;
            es_yardimi=0;
            esdogrumu='e';

         }

         else if(esdurum=='H' || esdurum=='h'){
            brut_ucret=aylik_net_maas+220;
            es_yardimi = 220;
            esdogrumu='e';

         }
         else printf("\n Yanlis giris yaptiniz tekrar giriniz...\n");

        }while (esdogrumu =='y');



            printf("\n");

            printf("Cocuk Sayisi Giriniz: ");
            scanf("%d",&cocuksayisi);
               if(cocuksayisi!=0){
                    tumcocuklucalisan++;
                    tumcocuksayisi+=cocuksayisi;
                int i=0;
                  for(i=0;i<cocuksayisi;)
                  {
                      printf("\nCocuk yasini giriniz: ",i++);
                      scanf("%d",&cocukyasi);

                      if(cocukyasi<=6){
                        odenek=odenek+25;
                       }


                      else if(cocukyasi>6){
                        odenek=odenek+45;


                      }
                  }
                brut_ucret= brut_ucret+odenek;

               }
               if(cocuksayisi>3)
               {
                   ucdenfazla++;
               }


           medenidogrumu='e';
         }

         else if(medenidurum=='B' || medenidurum=='b'){
            tumcalbekar++;
            brut_ucret=aylik_net_maas;
            medenidogrumu='e';

         }
         else printf("\n Yanlis giris yaptiniz tekrar giriniz...\n");

  }while (medenidogrumu == 'y');


    printf("\n");


char engeldogrumu = 'y';

do{


    printf("Engel Durumu Varmi(Evet ise E veya e, Hayir ise H veya h)? :");
    scanf(" %c",&engeldurumu);

         if(engeldurumu=='E'|| engeldurumu=='e'){
            printf("Engel Orani Giriniz(Lutfen 40'dan 100'e kadar Tamsayi Olarak Giriniz...):");
            scanf("%d",&engelorani);

                 if(engelorani>=40 && engelorani<60){
                        engellicalisan++;
                    muaftutar=210;
                   engelburutucret=brut_ucret-muaftutar;

                 }
                 else if(engelorani>=60 && engelorani<80){
                    engellicalisan++;
                    muaftutar=470;
                   engelburutucret=brut_ucret-muaftutar;

                 }
                 else if(engelorani>=80 && engelorani<=100){
                    engellicalisan++;
                    muaftutar=900;
                 engelburutucret=brut_ucret-muaftutar;

                 }
                 engeldogrumu='e';
         }
         else if (engeldurumu=='H' || engeldurumu=='h'){
            engellicalisan=0;
            muaftutar=0;
            engelburutucret=brut_ucret;
            engeldogrumu='e';

           }

        else printf("\n Yanlis giris yaptiniz tekrar giriniz...\n");

}while (engeldogrumu =='y');


        printf("\n");


        if (engelburutucret<2000){
            netucret=engelburutucret-((engelburutucret/100)*15)+muaftutar;
            gelirvergisi = ((engelburutucret/100)*15);
            gv15++;

        }
       else  if (engelburutucret>=2000 && engelburutucret<5000){
            netucret=engelburutucret-((engelburutucret/100)*20)+muaftutar;
            gelirvergisi = ((engelburutucret/100)*20);
            gv20++;

        }
        else  if (engelburutucret>=5000 && engelburutucret<10000){
            netucret=engelburutucret-((engelburutucret/100)*27)+muaftutar;
            gelirvergisi = ((engelburutucret/100)*27);
            gv27++;

        }
        else  if (engelburutucret>=10000){
            netucret=engelburutucret-((engelburutucret/100)*35)+muaftutar;
            gelirvergisi = ((engelburutucret/100)*35);
            gv35++;

        }
        if (netucret<2000)
        {
            ikibindenazalanlar++;
        }

    printf("\n");

        printf("\n ------- Calisanin Bilgileri ------- ");
        printf("\n %s Tc numarali %s %s",tcno,ad,soyad);
        printf("\n Es durumundan dolayi odenen tutar= %d",es_yardimi);
        printf("\n Cocuk icin odenen tutar= %d",odenek);
        printf("\n Aylik brut ucreti= %.2f",brut_ucret);
        printf("\n Vergi kesinti tutari= %.2f",gelirvergisi);
         if(engelorani>=40 && engelorani<60){
                  printf("\n 3.Derece engelli indirimi.");
                 }
                 else if(engelorani>=60 && engelorani<80){
                    printf("\n 2.Derece engelli indirimi.");
                 }
                 else if(engelorani>=80 && engelorani<=100){
                         printf("\n 1.Derece engelli indirimi.");
                 }
        printf("\n Aylik net ucret =%.2f",netucret);

        printf("\n ---- Banknotlar ---- \n");

    if(netucret>netenyuknetucret)
    {
        netenyukbrut=brut_ucret;
        int i=0;
        for(i=0; i<50;i++)
        {
            netenyuktc[i]=tcno[i];
        netenyukad[i]=ad[i];
        netenyuksoyad[i]=soyad[i];
        }

        netenyukgelver=gelirvergisi;
        netenyuknetucret=netucret;

    }



    if (brut_ucret>enyukbrut)
    {
        enyukbrut=brut_ucret;
        int i=0;
        for(i=0; i<50 ; i++)
        {
            enyuktc[i]=tcno[i];
        enyukad[i]=ad[i];
        enyuksoyad[i]=soyad[i];
        }

        enyukgelver=gelirvergisi;
        enyuknetucret=netucret;
    }
    tumcalisanodenen=tumcalisanodenen+netucret;
    devletaylikgelirver =devletaylikgelirver+gelirvergisi;
    ayliktoplambrutucret=ayliktoplambrutucret+brut_ucret;
    ayliktoplamnetucret=ayliktoplamnetucret+netucret;

         float TumBanknot[12] = { 200, 100, 50, 20, 10, 5, 1, 0.50, 0.25, 0.10, 0.05, 0.01};
   int gerekenbanknot[12];
   int i=0;
for (i=0; i<12; i++)
{
    gerekenbanknot[i]=netucret/TumBanknot[i];
    netucret =fmod(netucret,TumBanknot[i]);
}
     for (i=0; i<12; i++)
{
    if (gerekenbanknot[i] != 0)
    {
        printf("%.2f Banknottan  %d adet \n",TumBanknot[i],gerekenbanknot[i]);
    }
}

        printf("Baska Calisan Varmi(Evet ise E veya e, Hayir ise H veya h):");
        scanf(" %c",&personeldevam);

    }while(personeldevam=='e' || personeldevam=='E');



        printf("\n -- Tum Calisanlara Odenenlerin Bilgileri -- ");
        printf("\n Tum calisanlara odenen aylik net ucret = %.2f",tumcalisanodenen);
        printf("\n Devlete odenen aylik toplam gelir vergisi= %.2f",devletaylikgelirver);
        printf("\n Tum calisanlarin aylik toplam brut ucret ortalamasi = %.2f",ayliktoplambrutucret/girilenpersonelsayisi);
        printf("\n Tum calisanlarin aylik toplam net ucret ortalamasi = %.2f",ayliktoplamnetucret/girilenpersonelsayisi);
        printf("\n Aylik gereken para miktarlari= \n\n");

       //--------------------------------------------------------------------------------------------------------------
        float banknottumtumu[12] = { 200, 100, 50, 20, 10, 5, 1, 0.50, 0.25, 0.10, 0.05, 0.01};
   int gerekenbanknottumu[12];
   int i=0;
for (i=0; i<12; i++)
{
    gerekenbanknottumu[i]=ayliktoplamnetucret/banknottumtumu[i];
    ayliktoplamnetucret =fmod(ayliktoplamnetucret,banknottumtumu[i]);
}
     for (i=0; i<12; i++)
{
    if (gerekenbanknottumu[i] != 0)
    {
        printf("%.2f Banknottan  %d adet \n",banknottumtumu[i],gerekenbanknottumu[i]);
    }
}
//------------------------------------------------------------------------------------------------------------------
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Aylik net ucreti 2000'den az olan kisi sayisi= %d",ikibindenazalanlar);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        float a=((gv15*100)/girilenpersonelsayisi);
        float b=((gv20*100)/girilenpersonelsayisi);
        float c=((gv27*100)/girilenpersonelsayisi);
        float d=((gv35*100)/girilenpersonelsayisi);
        printf("\n Gelir vergisi 15'lik dilimdeki calisan sayisi= %d ve orani %.2f 'dir.",gv15,a);
        printf("\n Gelir vergisi 20'lik dilimdeki calisan sayisi= %d ve orani %.2f 'dir.",gv20,b);
        printf("\n Gelir vergisi 27'lik dilimdeki calisan sayisi= %d ve orani %.2f 'dir.",gv27,c);
        printf("\n Gelir vergisi 35'lik dilimdeki calisan sayisi= %d ve orani %.2f 'dir.",gv35,d);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Ucreti en yuksek calisanin Tc'si %s",enyuktc);
        printf("\n Ucreti en yuksek calisanin Ad ve Soyadi = %s %s",enyukad,enyuksoyad);
        printf("\n Ucreti en yuksek calisanin brut ucreti %.2f",enyukbrut);
        printf("\n Ucreti en yuksek calisanin Gelir vergisi kesintisi  %.2f",enyukgelver);
        printf("\n Ucreti en yuksek calisanin Aylik net ucreti %.2f",enyuknetucret);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Net ucreti en yuksek calisanin Tc'si %s",netenyuktc);
        printf("\n Net ucreti en yuksek calisanin Ad ve Soyadi = %s %s",netenyukad,netenyuksoyad);
        printf("\n Net ucreti en yuksek calisanin brut ucreti %.2f",netenyukbrut);
        printf("\n Net ucreti en yuksek calisanin Gelir vergisi kesintisi  %.2f",netenyukgelver);
        printf("\n Net ucreti en yuksek calisanin Aylik net ucreti %.2f",netenyuknetucret);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Tum calisanlarin yuzde %d kadari evli yuzde %d kadari bekardir.",((tumcalevli*100)/(tumcalbekar+tumcalevli)),((tumcalbekar*100)/(tumcalbekar+tumcalevli)));
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Evli calisanlarin eslerinin yuzde %d 'si calismaktadir.",100*evlicalisesdurum/tumcalevli);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Calisanlarin bakmakla yukumlu oldugu cocuk sayisi ortalamasi= %d ",tumcocuksayisi/girilenpersonelsayisi);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        printf("\n Ucten fazla cocugu olan calisan sayisi = %d",ucdenfazla);
        printf("\n---------------------------------------------------------------------------");
        printf("\n---------------------------------------------------------------------------");
        int engellicalisanyuzde=0;
        engellicalisanyuzde=engellicalisan/girilenpersonelsayisi;
        printf("\n Engelli calisan sayisi %d 'dir. Calisanlarin yuzde %.2f kadari engellidir.",engellicalisan,engellicalisanyuzde);


    return 0;
}
