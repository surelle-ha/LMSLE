void layer1Encrypt(char *textfile, char *keyfile, char *option){
	/* Get Text File Start */ 
	char * token = strtok(textfile, ".");
	int i = 0;
	char *file[100];
	while( token != NULL ) {
		file[i++] = token;
		token = strtok(NULL, ".");
	}
	char buffer[256];
	if(snprintf(buffer, sizeof(buffer), "document/%s.txt", file[0])>=sizeof(buffer)){
		/* the buffer isn't big enough */
	}else{
		FILE *fp ;  
		char ch, text[15000];
		int pos = 0;  
		fp = fopen(buffer,"r") ;  
		while(1){
			ch = fgetc(fp);
			if(ch == EOF){
				break;
			}
			text[pos] = ch;
			pos++;
		}
		fclose(fp);
		/* Get Key File Start */
		char * token1 = strtok(keyfile, ".");
		int x = 0;
		char *kfile[100];
		while( token1 != NULL ) {
			kfile[x++] = token1;
			token1 = strtok(NULL, ".");
		}
		char buffer1[256];
		if(snprintf(buffer1, sizeof(buffer1), "key/%s.key", kfile[0])>=sizeof(buffer1)){
			/* the buffer1 isn't big enough */
		}else{
			FILE *fp ;  
			char ch, keyword[15000];
			int pos = 0;  
			fp = fopen(buffer1,"r") ;  
			while(1){
				ch = fgetc(fp);
				if(ch == EOF){
					break;
				}
				keyword[pos] = ch;
				pos++;
			}
			fclose(fp);
			/* Encryption Process Start here */
			int root = 0;
			for(i = 0; (i < 100 && keyword[i] != '\0'); i++){ /* Get root value */
				root += keyword[i];
			}
			if(strcmp(option, "-d")==0 || strcmp(option, "--display")==0){
				for(i = 0; (i < 100 && text[i] != '\0'); i++){ /* Get root value */
					decHex(text[i]+root, "Jkfk5p", textfile, 1);
				}
				system("zenity --info --text=\"Encryption Done!\" --title=\"Status\"");
			}else if(strcmp(option, "-c")==0 || strcmp(option, "--current")==0){
				char dec[10];
				printf("\nThis will overwrite the file. Are you sure? [y/any-key]: ");
				scanf(" %[^\n]", dec);
				if(strcmp(dec,"y")==0 || strcmp(dec,"Y")==0){
					char buffer[256];
					if(snprintf(buffer, sizeof(buffer), "document/%s.txt", file[0])>=sizeof(buffer)){
						/* the buffer isn't big enough */
					}else{
						FILE *fp ;  
						fp = fopen(buffer, "w+");
						fprintf(fp, "");
						fclose(fp);
					}
					for(i = 0; (i < 100 && text[i] != '\0'); i++){ /* Get root value */
						decHex(text[i]+root, "Jkfk5p", textfile, 2);
					}
				}
				system("zenity --info --text=\"Encryption Done!\" --title=\"Status\"");
				main();
			}else if(strcmp(option, "-s")==0 || strcmp(option, "--save")==0){
				char fname[10];
				printf("\nNew Text File Name[Include extension]: ");
				scanf(" %[^\n]", fname);
				for(i = 0; (i < 100 && text[i] != '\0'); i++){ /* Get root value */
					decHex(text[i]+root, "Jkfk5p", fname, 3);
				}
				system("zenity --info --text=\"Encryption Done!\" --title=\"Status\"");
				main();
			}
			/* Encryption Process End here */
		}
		/* Get Key File End */
	}
	/* Get Text File End */
}


