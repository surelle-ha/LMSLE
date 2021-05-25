/*  Welcome to Leviathan Multiple Security Layered Encryption
	Developer: Harold Eustaquio [BSIT1Y2-2]
	Institution: Our Lady of Fatima University
	Campus: Antipolo
	System: Encryption
	Language: C
	Note: Created on Leviathan Linux
	Note: This C program is a Linux based. It can be
	run on Windows or Unix Based Operating System.
	 
	GCC version 8.3.0 (Debian 8.3.0-6)
*/

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversions"

/* Builtin Library */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <signal.h>

/* My Libray */
#include "termsncondition.h"
#include "coreUtility.h"
#include "installation.h"
#include "fileHandling.h"
#include "numberProcessor.h"
#include "4enc_code.h"
#include "4dnc_code.h"
#include "terminal.h"

/* Define Family */
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)
#define true 1
#define false 0
#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

void option_encrypt(){
	while(true){
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		screenClean();
		system("cowsay -f eyes \" Written by Harold Eustaquio \" | lolcat");
		printf("\n\n\n");
		blue();
		printf(" %s", asctime(timeinfo));
		yellow();
		printf("|**************************************************|\n");
		printf("|                                                  |\n");
		printf("|              SELECT FILE AND KEY                 |\n");
		printf("|          Text Files are stored in the            |\n");
		printf("|             'document' directory                 |\n");
		printf("|           Key Files are stored in the            |\n");
		printf("|                'key' directory                   |\n");
		printf("|                                                  |\n");
		printf("|  Command:                                        |\n");
		printf("|    enc <text_filename> <key_filename> <attrib>   |\n");
		printf("|    dnc <text_filename> <key_filename> <attrib>   |\n");
		printf("|    dis <filename>                                |\n");
		printf("|    edt <filename>                                |\n");
		printf("|    out <systemcommand>                           |\n");
		printf("|    exit                                          |\n");
		printf("|                                                  |\n");
		printf("|   Attribute:                                     |\n");
		printf("|     -d, --display : display the output           |\n");
		printf("|     -c, --current : overwrite the text file      |\n");
		printf("|                     with the output              |\n");
		printf("|     -s, --save    : save as new text file        |\n");
		printf("|                                                  |\n");
		printf("|                                                  |\n");
		printf("|**************************************************|\n");
		printf("                                                    \n");
		purple();
		text_fileList();
		key_fileList();
		reset();
		yellow();
		printf("                                                    \n");
		printf("|**************************************************|\n");
		reset();
		terminal();
	}
}

void menuSeparator(char *choice){
	if(strcmp(choice,"S")==0 || strcmp(choice,"s")==0){
		option_encrypt();
	}else if(strcmp(choice,"A")==0 || strcmp(choice,"a")==0){
		system("./key_creation_selector.sh");
	}else if(strcmp(choice,"I")==0 || strcmp(choice,"i")==0){
		installLMSLE();
	}else if(strcmp(choice,"G")==0 || strcmp(choice,"g")==0){
		installDependency();
	}else if(strcmp(choice,"T")==0 || strcmp(choice,"t")==0){
		while(true){
			char cont;
			screenClean();
			termscondition();
			printf("\nGo Back?<y>");
			scanf("%c", &cont);
			if(cont == 'y'){
				break;
			}else{
				continue;
			}
		}
	}else if(strcmp(choice,"X")==0 || strcmp(choice,"x")==0){
		screenClean();
		printf("\n\n\nThank you for using LMSLE\n\n");
		exit(1);
	}else{
		
	}
}

int main(){
	char choice[100];
	if(osDetect() == 1){
		system("zenity --error --text=\"Windows Operating System is currently not supported!\" --title=\"ERROR\"");
		exit(1);
	}
	TRY{
		while(true){
			screenClean();
			system("cowsay -f eyes \" Written by Harold Eustaquio \" | lolcat");
			printf("\n\n\n");
			yellow();
			printf("|**************************************************|\n");
			printf("|                                                  |\n");
			printf("|  LEVIATHAN MULTIPLE SECURITY LAYERED ENCRYPTION  |\n");
			printf("|               Harold C. Eustaquio                |\n");
			printf("|                                                  |\n");
			printf("|   [S] Start                                      |\n");
			printf("|   [A] Generate Key                               |\n");
			printf("|   [I] Install LMSLE (LINUX) / run as root        |\n");
			printf("|   [G] Get Dependency (LINUX) / run as root       |\n");
			printf("|   [T] Terms & Conditions                         |\n");
			printf("|   [X] Exit                                       |\n");
			printf("|                                                  |\n");
			printf("| @ By using LMSLE you are agreeing                |\n");
			printf("| to the Terms & Conditions                        |\n");
			printf("|**************************************************|\n");
			reset();
			printf("[Select] >> ");
			scanf(" %[^\n]", choice);
			menuSeparator(choice);
		}
		return 0;
	}CATCH{
	  printf("Something Went Wrong!\n");
	}
	ETRY;
}
