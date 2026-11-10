#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int DNA_validation(char dna[]);
int Dna_len(char dna[]);
int gcCounter(char dna[]);
int atCounter(char dna[]);
void protien_translation(char dna[]);
void lowercase(char dna[]);
void main_menu();
void options();


int main(int argc, char *argv[]) {
	int choice,validation;
	char dna[1000],rna_trans[1000],ans[5];
	int len=0;
	int gc_len=0;
	int at_len=0;
	main_menu();
	
	do{
		options();
		scanf("%d",&choice);
		
		if (choice == 6){
			break;
		}
		
		
		
		validation =0;
		do{
			printf("\nEnter Valid Dna Sequence:\n");
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
		
		
	    
		
	
		switch(choice){
			case 1:
				len = Dna_len(dna);
				printf("The length of DNA string is %d\n", len);
				break;
				
				
			case 2:
				gc_len = gcCounter(dna);
				printf("The GC count is %d\n",gc_len);
				break;
				
			case 3:
				at_len = atCounter(dna);
				printf("The AT count is %d\n",at_len);
				break;
				
			case 4:
				printf("The RNA translation is ");
				protien_translation(dna);
				printf("\n");
				break;
				
			case 5:
				len = Dna_len(dna);
				printf("The length of DNA string is %d\n", len);
				gc_len = gcCounter(dna);
				printf("The GC count is %d\n",gc_len);
				at_len = atCounter(dna);
				printf("The AT count is %d\n",at_len);
				printf("The RNA translation is ");
				protien_translation(dna);
				printf("\n");
				break;
		}
		
		printf("Do you wish to continue?\n");
		scanf("%s", &ans);
		lowercase(ans);
		
		
		
		    	
	}while(choice != 6 && ans == "yes");
		
    printf("Thankyou for using our DNA sequence analyzer!!!");

	
	return 0;
}
