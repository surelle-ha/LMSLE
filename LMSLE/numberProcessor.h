void decHex(int decnum, char *salt, char *textfile, int mode){
	 int rem, i=0;
    char hexnum[50];
    while(decnum!=0)
    {
        rem = decnum%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
        hexnum[i] = rem;
        i++;
        decnum = decnum/16;
    }
    if(mode == 1){
		for(i=i-1; i>=0; i--){
			printf("%c", hexnum[i]);
		}
		printf("%s", salt);
    }else if(mode == 2){
		char buffer[256];
		if(snprintf(buffer, sizeof(buffer), "document/%s.txt", textfile)>=sizeof(buffer)){
			/* the buffer isn't big enough */
		}else{
			FILE *fptr;
			fptr = fopen(buffer, "a");
			if (fptr == NULL) {
				printf("Error!");
				exit(1);
			}
			for(i=i-1; i>=0; i--){
				fprintf(fptr, "%c", hexnum[i]);
			}
			fprintf(fptr, "%s", salt);
			fclose(fptr);
		}
	}else if(mode == 3){
		char buffer[256];
		if(snprintf(buffer, sizeof(buffer), "document/%s", textfile)>=sizeof(buffer)){
			/* the buffer isn't big enough */
		}else{
			FILE *fptr;
			fptr = fopen(buffer, "a");
			if (fptr == NULL) {
				printf("Error!");
				exit(1);
			}
			for(i=i-1; i>=0; i--){
				fprintf(fptr, "%c", hexnum[i]);
			}
			fprintf(fptr, "%s", salt);
			fclose(fptr);
		}
	}
}

int hexDec(char *hex, int root, char *textfile, int mode){
    long long decimal = 0, base = 1;
    int i = 0, value, length;
    length = strlen(hex);
    for(i = length--; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    if(mode == 1){
		printf("%c", decimal-root);
		
    }else if(mode == 2){
		char buffer[256];
		if(snprintf(buffer, sizeof(buffer), "document/%s.txt", textfile)>=sizeof(buffer)){
			/* the buffer isn't big enough */
		}else{
			FILE *fptr;
			fptr = fopen(buffer, "a");
			if (fptr == NULL) {
				printf("Error!");
				exit(1);
			}
			fprintf(fptr, "%c", decimal-root);
			fclose(fptr);
		}
	}else if(mode == 3){
		char buffer[256];
		if(snprintf(buffer, sizeof(buffer), "document/%s", textfile)>=sizeof(buffer)){
			/* the buffer isn't big enough */
		}else{
			FILE *fptr;
			fptr = fopen(buffer, "a");
			if (fptr == NULL) {
				printf("Error!");
				exit(1);
			}
			fprintf(fptr, "%c", decimal-root);
			fclose(fptr);
		}
	}
}
