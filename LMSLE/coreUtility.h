void black(){
	printf("\033[0;30m");
}

void green(){
	printf("\033[0;32m");
}

void blue(){
	printf("\033[0;34m");
}

void purple(){
	printf("\033[0;35m");
}

void red() {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}

void reset() {
	printf("\033[0m");
}

void screenClean(){
	system("clear");
}

void figletter(){
	system("figlet LEVIATHAN BANK | lolcat");
}

int osDetect(){
	#ifdef OS_Windows
		return 1;
	#else
		return 2;
	#endif
}

void loading(int time){
	for(int i = 0; i < time; i++){
		if(i%2==0){
			printf("\n\n[ + ] Validating your account... \n\n");
		}else{
			printf("\n\n[ x ] Validating your account... \n\n");
		}
		sleep(1);
		screenClean(osDetect());
	}
}

void splashScreen(){
	system("whiptail --title \"LEVIATHAN BANK INTERNATIONAL\" --msgbox \"Welcome to Leviathan Bank International, $USER. .\" 8 78 --ok-button \"Proceed\"");
}
