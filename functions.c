void main_menu(){	
	printf("=========================================\n");
	printf("          DNA SEQUENCE ANALYZER\n");
	printf("=========================================\n");
	printf("\nWelcome To the DNA SEQUENCE ANALYZER!\n\n");
}

void options(){
	printf("\nSelect from one of the options");
	printf("\n\n1.DNA Length Calculator\n");
	printf("2. G-C content counter\n");
	printf("3. A-T content counter\n");
	printf("4. RNA Translator\n");
	printf("5. All Of The Above\n");
	printf("6.----Exit------\n");
}





int DNA_validation(char dna[]){
    int i;

	for(i=0; dna[i]!='\0';i++){
		if(dna[i] !='a' && dna[i] !='g' && dna[i] !='t'&& dna[i] !='c'){
			return 0;
		}
	}
	return 1;
 }
 
int Dna_len(char dna[]) {
    int i,count = 0;

    for(i=0; dna[i] !='\0'; i++) {
        count++;
    }

    return count;
}

int gcCounter(char dna[]) {
    int i, count = 0;

    for(i = 0; dna[i] != '\0'; i++) {
        if(dna[i] == 'g' || dna[i] == 'c') {
            count++;
        }
    }

    return count;
}

int atCounter(char dna[]) {
    int i, count = 0;

    for(i = 0; dna[i] != '\0'; i++) {
        if(dna[i] == 'a' || dna[i] == 't') {
            count++;
        }
    }

    return count;
}

void protien_translation(char dna[]){
	int i;
	for(i=0;dna[i]!='\0';i++){
		if(dna[i] == 't'){
			dna[i] = 'u';
		}
	}
	printf("%s",dna) ;
}

void lowercase(char dna[]){
	int i;
	for (i = 0; dna[i] != '\0'; i++) {
        dna[i] = tolower(dna[i]);
    }
}
