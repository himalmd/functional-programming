#include<stdio.h>
 
int main()
{
	char enText[100], deText[100];
	int option, enKey, deKey;
	
	while(1){
		
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("Choose the function\n");
		scanf("%d", &option);
		
		switch(option) {
	      case 1 :
	        printf("Enter a message to encrypt: ");
			scanf("%s", enText);
			printf("Enter key: ");
			scanf("%d", &enKey);
			encrypt(enText, enKey);
	        break;
	
	      case 2 :
	        printf("\nEnter a message to decrypt: ");
			scanf("%s", deText);
			printf("Enter key: ");
			scanf("%d", &deKey);
			decrypt(deText, deKey);
	        break;
	      default :
	        printf("Invalid option\n" );
  		 }
	}
	
	return 0;
}


void encrypt(char enMessage[100], int eKey){
	
	char ch1;
	int i;
	
	for(i = 0; enMessage[i] != '\0'; ++i){
			ch1 = enMessage[i];
			
			if(ch1 >= 'a' && ch1 <= 'z'){
				ch1 = ch1 + eKey;
				
				if(ch1 > 'z'){
					ch1 = ch1 - 'z' + 'a' - 1;
				}
				
				enMessage[i] = ch1;
			}
			else if(ch1 >= 'A' && ch1 <= 'Z'){
				ch1 = ch1 + eKey;
				
				if(ch1 > 'Z'){
					ch1 = ch1 - 'Z' + 'A' - 1;
				}
				
				enMessage[i] = ch1;
			}
		}
		
	printf("Encrypted message: %s \n", enMessage);
}


void decrypt(char deMessage[100], int dKey){
	
	char ch;
	int j;
	
	for(j = 0; deMessage[j] != '\0'; ++j){
	ch = deMessage[j];
	
	if(ch >= 'a' && ch <= 'z'){
		ch = ch - dKey;
		
		if(ch < 'a'){
			ch = ch + 'z' - 'a' + 1;
		}
		
		deMessage[j] = ch;
	}
	else if(ch >= 'A' && ch <= 'Z'){
		ch = ch - dKey;
		
		if(ch < 'A'){
			ch = ch + 'Z' - 'A' + 1;
		}
		
		deMessage[j] = ch;
	}
}

	printf("Decrypted message: %s \n", deMessage);
	

}



