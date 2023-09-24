#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_NAME_LENGTH 50 // 
typedef struct {
    char name[MAX_NAME_LENGTH];
} Person;

int main() {
    int ilk_oyuncunun_skoru = 0, ikinci_oyuncunun_skoru = 0, secilen_oyuncu, rastgele_sayi,ilk_oyuncu_tur_sonu,ikinci_oyuncu_tur_sonu;
    int ilk_oyuncu_tur_basi,ikinci_oyuncu_tur_basi;
    char secim='d';
    char temp[MAX_NAME_LENGTH];

    Person person1, person2;

    printf("Birinci kisinin adini giriniz: ");
    scanf("%s", temp);
    strcpy(person1.name, temp);

    printf("Ikinci kisinin adini giriniz: ");
    scanf("%s", temp);
    strcpy(person2.name, temp);

    printf("Girilen isimler:\n");
    printf("%s\n", person1.name);
    printf("%s\n", person2.name);

    printf("Hangi oyuncunun baslayacagini secin (1 veya 2): ");
    scanf("%d", &secilen_oyuncu);
    
    srand(time(NULL));

    while (ilk_oyuncunun_skoru < 50 && ikinci_oyuncunun_skoru < 50) {
    	secim='d';
	    switch (secilen_oyuncu) {
        case 1:
            while (secim == 'd') {
                rastgele_sayi = rand() %6 + 1;
                if (rastgele_sayi == 1) {
                	secilen_oyuncu=2;
                	printf("1 geldi\n");
                	ilk_oyuncunun_skoru=ilk_oyuncu_tur_basi;
                	break;
                } 
		     
			    else {
                    ilk_oyuncunun_skoru += rastgele_sayi;
                    printf("gelen sayi %d\n ilk oyuncunun anlik skoru : %d\n",rastgele_sayi,ilk_oyuncunun_skoru);
                    printf("\n tamam mi devam mi(t veya d)\n");
                    scanf(" %c", &secim);
                    if (secim == 't') {
                    	ilk_oyuncu_tur_basi=ilk_oyuncunun_skoru;
                        printf("Ýlk oyuncunun son skoru = %d\n", ilk_oyuncunun_skoru);
                        secilen_oyuncu=2;
                        break;
                       }
                    else{
                    	secilen_oyuncu=1;
                    	secim='d';
                    	break;
					}
                }
            }
            break;

        case 2:
            while (secim == 'd') {
                rastgele_sayi = rand() %6 + 1;
                if (rastgele_sayi == 1) {
                	secilen_oyuncu=1;
                	printf("1 geldi\n");
                	ikinci_oyuncunun_skoru=ikinci_oyuncu_tur_basi;
                	break;
                } 
		     
			    else {
                    ikinci_oyuncunun_skoru += rastgele_sayi;
                    printf("gelen sayi %d\n ikinci oyuncunun anlik skoru : %d\n",rastgele_sayi,ikinci_oyuncunun_skoru);
                    printf("\n tamam mi devam mi(t veya d)\n");
                    scanf(" %c", &secim);
                    if (secim == 't') {
                    	ikinci_oyuncu_tur_basi=ikinci_oyuncunun_skoru;
                        printf("Ýkinci oyuncunun son skoru = %d\n", ikinci_oyuncunun_skoru);
                        secilen_oyuncu=1;
                        break;
                        
                       }
                    else{
                    	secilen_oyuncu=2;
                    	secim='d';
                    	break;
					}
                }
            }
        break;

        default:
            printf("Geçersiz oyuncu secimi.\n");
        }
    }

    printf("%s: %d\n%s: %d\n", person1.name, ilk_oyuncunun_skoru, person2.name, ikinci_oyuncunun_skoru);

    return 0;
}

