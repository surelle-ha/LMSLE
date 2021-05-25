#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void){
	char key[100];
	int bit = 8;
	static const char ucase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t ucase_count = sizeof(ucase) - 1; // ucase includes terminating '\0'
    size_t i, j;
    srand(time(NULL));
	for(int i = 0; i < bit; i++){
		for(int c = 0; c < 10; c++) {
			for(j = 0; j < ucase_count; j++) {
				char random_char;
				int random_index = (double)rand() / RAND_MAX * ucase_count;
				random_char = ucase[random_index];
				key[i] = random_char;
			}
		}
	}
	char buffer[256];
	char buffer1[256];
	if(snprintf(buffer, sizeof(buffer), "../key/%d_8.key", rand()%150)>=sizeof(buffer)){
		/* the buffer isn't big enough */
	}else{
		system(snprintf(buffer1, sizeof(buffer1), "touch ../key/%d_8.key", rand()%150)>=sizeof(buffer1));
		FILE *fptr;
		fptr = fopen(buffer, "a");
		fprintf(fptr, "%s", key);
		fclose(fptr);
		system("whiptail --title \"Key File Generated\" --msgbox \"New key file has been created. Key files are stored in Key Directory. Please do not modify the content of Key Files.\" 8 78 --ok-button \"Exit\"");
	}
	return 0;
}

