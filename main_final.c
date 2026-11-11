#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int DNA_validation(char dna[]);
int Dna_len(char dna[]);
int gcCounter(char dna[]);
int atCounter(char dna[]);
char* protien_translation(const char dna[], char rna[]);
void lowercase(char dna[]);
void main_menu();
void options();

struct patient{
	int patient_ID;
	char patient_name[50];
	int age;
	char dna[100];
	int dna_len;
	int at_count;
	int gc_count;
	char rna_trans[100];
};

int main(int argc, char *argv[]) {
	int choice=0,validation,i,j;
	char dna[100],rna[100],ans[5];
	int ID=0;
	struct patient s[10];
	i=0;
	
	
	main_menu();
	
	do{
		options();
		scanf("%d",&choice);
		
		if (choice == 3){
			break;
		}
		
		switch(choice){
			case 1:
				if (i==0){
					printf("There are no past analysations\n");
					break;
				}
				printf("Enter the ID you want to see data of:\n");
				scanf("%d", &ID);
		
				int found = 0;
				for (j = 0; j < i; j++) {
				    if (s[j].patient_ID == ID) {
				        printf("Info for patient %d::\n", s[j].patient_ID);
				        printf("Name: %s | Age: %d\n", s[j].patient_name, s[j].age);
				        printf("The DNA strand entered was: %s\n", s[j].dna);
				        printf("The length of DNA string is %d\n", s[j].dna_len);
				        printf("The GC count is %d:\n", s[j].gc_count);
				        printf("The AT count is %d:\n", s[j].at_count); 
				        printf("The RNA translation is %s\n", s[j].rna_trans);
				        found = 1;
				        break;
				    }
				}
				if (!found) {
				    printf("The ID that you have entered does not exist!\n");
				}

				break;
				
				
			case 2:
				s[i].patient_ID = i+1;
				
				printf("Enter name:\n");
				scanf("%s", s[i].patient_name); //we don't use '&' bcs it causes compiler error
				
				printf("Enter patient age:\n");
				scanf("%d", &s[i].age);
				
				
				validation =0;
				do{
					printf("\nEnter Valid Dna Sequence (In the format A,G,T,C):\n");
					scanf("%s",dna);
					lowercase(dna);
					validation = DNA_validation(dna);
					if (validation == 0){
						printf("Invalid sequence\n");
					}
					else{
						printf("Sequence is valid!\n\n");
					}
				}
				while(validation==0);
				
				strcpy(s[i].dna, dna);
				s[i].dna_len = Dna_len(dna);
				printf("The length of DNA string is %d\n", s[i].dna_len);
				s[i].gc_count = gcCounter(dna);
				printf("The GC count is %d\n",s[i].gc_count);
				s[i].at_count = atCounter(dna);
				printf("The AT count is %d\n",s[i].at_count);
				strcpy(s[i].rna_trans,protien_translation(dna,rna));
				printf("The RNA translation is %s\n",s[i].rna_trans);
				printf("\n");
				i=i+1;
				break;
				
			
		}
		
		printf("Do you wish to continue?\n");
		scanf("%s", &ans);
		lowercase(ans);
		
		
		
		    	
	}while(choice != 3 && strcmp(ans, "yes") == 0);
		
    printf("Thankyou for using our DNA sequence analyzer!!!");

	
	return 0;
}
