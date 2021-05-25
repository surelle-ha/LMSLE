void installDependency(){
	system("sudo apt-get install whiptail figlet lolcat cowsay");
	screenClean(osDetect());
}

void installLMSLE(){
	system("gcc -Wall -o \"LMSLE\" \"main.c\" ");
	system("mv LMSLE /bin");
	screenClean(osDetect());
	system("zenity --info --text=\"SUCCESSFULLY INSTALLED\" --title=\"INSTALLED\"");
}
