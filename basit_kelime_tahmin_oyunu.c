#include<stdio.h>

int main(){
	
	
	
	char D[5] = {'a','e','r','k','s'};
	char kelimeler[][6] = {"asker","serak","kars","kase","sera","akse","ark","kes","kas","ser","sek","kar"};
	char tahmin[10];
	char recap_array[100][20];
	int i,j,c=0,k,m,point = 0,total_point=0;
	printf("-----------------Hello-------------------\n-----Welcome to Word Prediction Game-----\n\n");
	printf("Here are the letters you can use to prediction them\n");
	for(i=0;i<5;i++){
		printf("'%c' ",D[i]);
	}
	printf("\nif you have prediction, please enter your prediction or press '0' to quit:\n");
	int length_of_words[12];
		for(j=0;j<12;j++){
			for(m=0;kelimeler[j][m];m++)
			length_of_words[j] = m+1;
		}
	do{
		//getting prediction
		int word_length = 0;
		printf("Prediction: ");
		scanf("%s",tahmin);
		i=0;
		//finding length of prediction
		while(tahmin[i]!='\0'){
			word_length +=1;
			i=i+1;
		}
		if(tahmin[0]!='0'){
			printf("your prediction is: %s\n",tahmin);
		}else{
			printf("your entered %s to finish predicting.\n",tahmin);
		}
		//is prediction is smaller than 2 letter getting again it 
		while((word_length<2) && (tahmin[0]!= '0')){
			printf("Please enter the least two letters!!\n");
			scanf("%s", tahmin);
			while(tahmin[i]!='\0'){
			word_length +=1;
			i=i+1;
			}
		}
		//finding if there is recap letter
		int recap = 0;
		for(i=0;i<word_length-1;i++){
			for(j=i+1;j<word_length;j++){
				if(tahmin[i]==tahmin[j]){
					recap = 1;
				}
			}
		}
		//if there is recap letter getting prediction again
		while(recap == 1){
			printf("Please don't use a letter more than once\n");
			printf("Prediction again:");
			scanf("%s",tahmin);
			word_length=0;
			i=0;
			while(tahmin[i]!='\0'){
			word_length +=1;
			i=i+1;
			}
			recap =0;
			for(i=0;i<word_length-1;i++){
				for(j=i+1;j<word_length;j++){
					if(tahmin[i]==tahmin[j]){
						recap = 1;
					}
				}
			}
		}
		
		//finding is letter of prediction in D
		i=0;
		int is_there_into = 1;
		while(i<word_length && is_there_into == 1){
			is_there_into = 0;
			for(k=0;k<5;k++){
				if(tahmin[i]==D[k]){
					is_there_into =1; 
				}
			}
			i++;
		}
		//finding if the prediction is in the list
		int is_in_list = 0;
		k=0;
		int is_word_same;
		while((k<12) && (is_in_list ==0)){
			if(length_of_words[k]==word_length){
				is_word_same = 1;
				m = 0;
				while((m<word_length) && (is_word_same == 1)){
					if(tahmin[m] != kelimeler[k][m]){
						is_word_same = 0;
					}
					m++;
				}
				if(is_word_same == 1){
					is_in_list =1;
				}
			}
			k++;
		}
		int h=0,d=0,is_in_list_ra = 0,is_word_same_ra,y,ku;
		//finding the prediction whether there is in recap_array
		while((h<c) && (is_in_list_ra ==0)){
			y=0;
			while(recap_array[h][y] != '\0'){
				y++;
			}
			ku=y;
			if(ku==word_length){
				is_word_same_ra = 1;
				d = 0;
				while((d<word_length)&&(is_word_same_ra == 1)){
					if(tahmin[d] != recap_array[h][d]){
						is_word_same_ra = 0;
					}
					d++;
				}
				if(is_word_same_ra == 1){
					is_in_list_ra =1;
				}
			}
			h++;
		}
		//adding the same prediction in recap_array
		m=0;
		if((is_there_into == 1) && (is_in_list == 1)){
			while((m<word_length)){
				recap_array[c][m] = tahmin[m];
				m++;
			}
			c++;
			m=0;
		}	
		//calculating the point when entered the wrong letter
		if(is_there_into ==0 && tahmin[0]!='0'){
			printf("You entered wrong letter\n");
			point = -(1*word_length);
			total_point +=point;
			printf("Your point is %d\n",point);
		//calculating the point when entered right prediciton and it is in the kelimeler
		}else if((is_there_into ==1) && (is_in_list == 1) && (is_in_list_ra ==0)){
			printf("Congrats!!");
			point = (1*word_length);
			total_point +=point;
			printf("Your point is %d\n",point);
		//calculating the point when entered valid word that is not in list
		}else if((is_there_into == 1) && (is_in_list == 0)){
			printf("You entered a prediction that is not in the list\n");
			point = -(1*word_length);
			total_point += point;
			printf("Your point is %d\n",point);
		//calculating the point when right word but more than once
		}else if((is_there_into ==1) && (is_in_list == 1) &&(is_in_list_ra ==1)){
	        printf("You re-entered the previously entered prediction\n");
			point = -(1*word_length);
			total_point += point;
			printf("Your point is %d\n",point);
		}
		if(tahmin[0] == '0'){
			printf("Your total point is %d",total_point);
		}
	}while(tahmin[0]!= '0');	
	return 0;
}
