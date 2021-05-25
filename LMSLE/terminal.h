#define true 1

void terminal(){
	while(true){
		char command[255];
		printf( "\n[user@lmsle]$ ");
		scanf(" %[^\n]", command);
		char * token = strtok(command, " ");
		int i = 0;
		char *bit_command[100];
		while( token != NULL ) {
			bit_command[i++] = token;
			token = strtok(NULL, " ");
		}
		if(strcmp(bit_command[0],"enc")==0){ /* Encrypt */
			layer1Encrypt(bit_command[1], bit_command[2], bit_command[3]);
		}else if(strcmp(bit_command[0],"dnc")==0){
			layer1Decrypt(bit_command[1], bit_command[2], bit_command[3]);
		}else if(strcmp(bit_command[0],"dis")==0){
			char * token = strtok(bit_command[1], ".");
			int i = 0;
			char *file[100];
			while( token != NULL ) {
				file[i++] = token;
				token = strtok(NULL, ".");
			}
			if(strcmp(file[1],"txt")==0){
				char buffer[256];
				if(snprintf(buffer, sizeof(buffer), "document/%s.txt", file[0])>=sizeof(buffer)){
					/* the buffer isn't big enough */
				}else{
					FILE *fp ;  
					char ch ;  
					fp = fopen(buffer,"r") ;  
					while(1){  
						ch = fgetc(fp);
						if(ch == EOF)
							break;
						printf("%c",ch);
					}
					fclose(fp);
				}
			}else if(strcmp(file[1],"key")==0){
				char buffer[256];
				if(snprintf(buffer, sizeof(buffer), "key/%s.key", file[0])>=sizeof(buffer)){
					/* the buffer isn't big enough */
				}else{
					FILE *fp ;  
					char ch ;  
					fp = fopen(buffer,"r") ;  
					while(1){  
						ch = fgetc(fp);
						if(ch == EOF)
							break;
						printf("%c",ch);
					}
					fclose(fp);
				}
			}
		}else if(strcmp(bit_command[0],"edt")==0){
			char * token = strtok(bit_command[1], ".");
			int i = 0;
			char *file[100];
			while( token != NULL ) {
				file[i++] = token;
				token = strtok(NULL, ".");
			}
			if(strcmp(file[1],"txt")==0){
				char buffer[256];
				if(snprintf(buffer, sizeof(buffer), "nano document/%s.txt", file[0])>=sizeof(buffer)){
					/* the buffer isn't big enough */
				}else{
					system(buffer);
				}
			}else if(strcmp(file[1],"key")==0){
				char buffer[256];
				if(snprintf(buffer, sizeof(buffer), "nano key/%s.txt", file[0])>=sizeof(buffer)){
					/* the buffer isn't big enough */
				}else{
					system(buffer);
				}
			}
		}else if(strcmp(bit_command[0],"out")==0){
			system(bit_command[1]);
		}else if(strcmp(bit_command[0],"clean")==0){
			option_encrypt();
		}else if(strcmp(bit_command[0],"exit")==0){
			screenClean();
			printf("Thank you for using LMSLE!");
			exit(1);
		}else{
			red();
			printf("'%s' command not found..\n", bit_command[0]);
			reset();
		}
	}
}

