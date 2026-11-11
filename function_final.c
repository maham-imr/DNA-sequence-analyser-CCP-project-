void main_menu(){	
	printf("=========================================\n");
	printf("          DNA SEQUENCE ANALYZER\n");
	printf("=========================================\n");
	printf("\nWelcome to our DNA SEQUENCE ANALYZER!\nA DNA strand consists of nucleotides labelled A,G,T,C, \nOur analyser takes a string with in the format of 'A','G','T','C' and performs different calculations on it \n");
}

void options(){
	printf("\nSelect from one of the options");
	printf("\n\n1. View past Analysation\n");
	printf("2. Analyse DNA strand \n");
	printf("3.----Exit------\n");
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

char* protien_translation(const char dna[], char rna[]) {
    int i;
    for (i = 0; dna[i] != '\0'; i++) {
        if (dna[i] == 't') {
            rna[i] = 'u';
        } else {
            rna[i] = dna[i]; 
        }
    }
    rna[i] = '\0'; 
    return rna;
}

void lowercase(char dna[]){
	int i;
	for (i = 0; dna[i] != '\0'; i++) {
        dna[i] = tolower(dna[i]);
    }
}

