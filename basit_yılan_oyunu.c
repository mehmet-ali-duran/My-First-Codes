#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
	
	int satir,sutun,tahta[300][300],yilan[2][200],hamle_sayisi=0,yemek_konum[2][200],yemek_s,oyun_bitti=0,yilan_u=1,yenilen_yemek=0,i,j,k,uzadi_mi = 0;
	char yon;
	printf("          Yilan Oyununa Hosgeldiniz\n\nOyun Alaninin Boyutlarini Giriniz\n\n");
	printf("Satir sayisi: ");
	scanf("%d",&satir);
	printf("\nSutun sayisi: ");
	scanf("%d",&sutun);
	printf("\nYemek sayisi: \n\n\n");
	do{
	scanf("%d",&yemek_s);
	}while((yemek_s<1) || (yemek_s>(satir*sutun-1)));
	satir=5;sutun=15;yemek_s=7;
	srand(time(0));
	for(i=0;i<yemek_s;i++){
		yemek_konum[1][i] = (rand()%satir)+1;
		yemek_konum[0][i] = (rand()%sutun)+1;
	}
	int cakisiyor_mu = 1;
	do{
		yilan[1][0]=(rand()%satir)+1;
		yilan[0][0]=(rand()%sutun)+1;
		cakisiyor_mu = 0;
		for(i=0;i<yemek_s;i++){
			if((yemek_konum[1][i] == yilan[1][0]) && (yemek_konum[0][i] == yilan[0][0])){
				cakisiyor_mu = 1;
			}
		}
		
	}while(cakisiyor_mu==1);
	
	for(i=0;i<satir+2;i++){
		for(j=0;j<sutun+2;j++){
			if(i==0){
				tahta[i][j] = '¯';
			}
			if(i==satir+1){
				tahta[i][j] = '¯';
			}
			if(((j==0) || (j==sutun+1)) && ((i!=0) || (i!=satir+1))){
				tahta[i][j] = '|';
			}
		}
	}
	while(oyun_bitti == 0){
		
	 	for(i=1;i<satir+1;i++){
			for(j=1;j<sutun+1;j++){
				tahta[i][j]=' ';
			}
		}
		 for(i=0;i<yemek_s;i++){
	 		tahta[yemek_konum[1][i]][yemek_konum[0][i]] = '0';
		}
		for(i=0;i<yilan_u;i++){
			tahta[yilan[1][i]][yilan[0][i]] = '1' +i;
		}
			
		for(i=0;i<satir+2;i++){
			for(j=0;j<sutun+2;j++){
				printf("%c",tahta[i][j]);
			}
			printf("\n");
		}
		if(uzadi_mi==1){
			yilan_u += 1;
			uzadi_mi = 0;
		}
		hamle_sayisi = hamle_sayisi+1;
		
		printf("Yonu gir\n");
		scanf(" %c",&yon);
		
		system("cls");
		printf("Hamle sayisi = %d\n\n\n\n",hamle_sayisi);
		
		if(yon == 'u'){
			
			yilan[1][0] -=1;
			
			if(((tahta[yilan[1][0]][yilan[0][0]])=='|') || ((tahta[yilan[1][0]][yilan[0][0]])=='¯')){
				oyun_bitti = 1;
				printf("\nDuvara carptigin icin oyun bitti\nYapýlan Hamle Sayisi:%d\nYilanin uzunlugu:%d\nYemek sayisi:%d\n",hamle_sayisi,yilan_u,yemek_s);
			}
			
			if(tahta[yilan[1][0]][yilan[0][0]] != '0'){
				yilan[1][0] +=1;
				for(i=yilan_u-1;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}	
				yilan[1][0] -=1;
			}else{
				uzadi_mi=1;
				for(i=0;i<yemek_s-1;i++){
					if((yilan[1][0] == yemek_konum[1][i]) && (yilan[0][0] == yemek_konum[0][i])){
						
						yemek_konum[1][i] = yemek_konum[1][yemek_s-1];
						yemek_konum[0][i] = yemek_konum[0][yemek_s-1];
					}
				}
				yemek_s -=1;
				yilan[1][0] +=1;
				for(i=yilan_u;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}
				yilan[1][0] -=1;
			}
			
			
		}else if(yon == 'd'){
			
			yilan[1][0] +=1;
			
			if(((tahta[yilan[1][0]][yilan[0][0]])=='|') || ((tahta[yilan[1][0]][yilan[0][0]])=='¯')){
				oyun_bitti = 1;
				printf("\nDuvara carptigin icin oyun bitti\nYapýlan Hamle Sayisi:%d\nYilanin uzunlugu:%d\nYemek sayisi:%d\n",hamle_sayisi,yilan_u,yemek_s);
			}
			
			if(tahta[yilan[1][0]][yilan[0][0]] != '0'){
				yilan[1][0] -=1;
				for(i=yilan_u-1;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}	
				yilan[1][0] +=1;
			}else{
				uzadi_mi=1;
				for(i=0;i<yemek_s-1;i++){
					if((yilan[1][0] == yemek_konum[1][i]) && (yilan[0][0] == yemek_konum[0][i])){
						
						yemek_konum[1][i] = yemek_konum[1][yemek_s-1];
						yemek_konum[0][i] = yemek_konum[0][yemek_s-1];
					}
				}
				yemek_s -=1;
				yilan[1][0] -=1;
				for(i=yilan_u;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}
				yilan[1][0] +=1;
			}
		
		}else if(yon == 'l'){
			
			yilan[0][0] -=1;
			
			if(((tahta[yilan[1][0]][yilan[0][0]])=='|') || ((tahta[yilan[1][0]][yilan[0][0]])=='¯')){
				oyun_bitti = 1;
				printf("\nDuvara carptigin icin oyun bitti\nYapýlan Hamle Sayisi:%d\nYilanin uzunlugu:%d\nYemek sayisi:%d\n",hamle_sayisi,yilan_u,yemek_s);
			}
			
			if(tahta[yilan[1][0]][yilan[0][0]] != '0'){
				yilan[0][0] +=1;
				for(i=yilan_u-1;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}	
				yilan[0][0] -=1;
			}else{
				uzadi_mi=1;				
				for(i=0;i<yemek_s-1;i++){
					if((yilan[1][0] == yemek_konum[1][i]) && (yilan[0][0] == yemek_konum[0][i])){
						
						yemek_konum[1][i] = yemek_konum[1][yemek_s-1];
						yemek_konum[0][i] = yemek_konum[0][yemek_s-1];
					}
				}
				yemek_s -=1;
				yilan[0][0] +=1;
				for(i=yilan_u;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}
				yilan[0][0] -=1;
			}
		}else if(yon == 'r'){
			
			yilan[0][0] +=1;
			
			if(((tahta[yilan[1][0]][yilan[0][0]])=='|') || ((tahta[yilan[1][0]][yilan[0][0]])=='¯')){
				oyun_bitti = 1;
				printf("\nDuvara carptigin icin oyun bitti\nYapýlan Hamle Sayisi:%d\nYilanin uzunlugu:%d\nYemek sayisi:%d\n",hamle_sayisi,yilan_u,yemek_s);
			}
			
			if(tahta[yilan[1][0]][yilan[0][0]] != '0'){
				yilan[0][0] -=1;
				for(i=yilan_u-1;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}	
				yilan[0][0] +=1;
			}else{
				uzadi_mi=1;
				for(i=0;i<yemek_s-1;i++){
					if((yilan[1][0] == yemek_konum[1][i]) && (yilan[0][0] == yemek_konum[0][i])){
						
						yemek_konum[1][i] = yemek_konum[1][yemek_s-1];
						yemek_konum[0][i] = yemek_konum[0][yemek_s-1];
					}
				}
				yemek_s -=1;
				yilan[0][0] -=1;
				for(i=yilan_u;i>0;i--){
					yilan[1][i] = yilan[1][i-1];
					yilan[0][i] = yilan[0][i-1];
				}
				yilan[0][0] +=1;
			}
		}
		
		if(yemek_s==0){
			oyun_bitti=1;
			printf("Yemek bittigi icin oyun bitti\nHamle Sayiniz: %d",hamle_sayisi);
			
		}
		
	}
	
	return 0;
}
