#include<stdio.h>

int main(){
	int N,M,k,i,j,m,n,filtre_toplam=0;

	printf("Lutfen sirayla M ve M yi girin\nM:");
	scanf("%d",&M);
	printf("\nN:");
	scanf("%d",&N);
	printf("\nLutfen k yi girin(k tek sayi olmali):");
	do{
		scanf("%d",&k);
	}while((k%2!=1) || (k>=M) || (k>=N));
	
	int goruntu[M][N],filtre[k][k];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("Goruntu Matrisi Degerleri: ");
			scanf("%d",&goruntu[i][j]);
		}
	}
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			printf("Fltre Matrisi Ddegerleri: ");
			scanf("%d",&filtre[i][j]);filtre_toplam+=filtre[i][j];
		}
	}
	
	int cikti[M-k+1][N-k+1],ara_toplam=0;
	printf("filtre_toplam: %d\n",filtre_toplam);
	for(i=0;i<M-k+1;i++){
		for(j=0;j<N-k+1;j++){
			ara_toplam=0;
			for(m=0;m<k;m++){
				for(n=0;n<k;n++){
					cikti[i][j] = (ara_toplam +=((filtre[m][n])*goruntu[m+i][n+j]));
				}
			}
		}	
	}
	printf("Cikti matrisi\n");
	for(i=0;i<M-k+1;i++){
		for(j=0;j<N-k+1;j++){
			printf("%d",(cikti[i][j])/filtre_toplam);
		}
		printf("\n");
	}
	
	return 0;
}
