void text_fileList(){
	DIR *d;
	struct dirent *dir;
	d = opendir("document");
	if(d){
		while ((dir = readdir(d)) != NULL){
			if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0){
				// Do nothing
			}else{
				printf("  [T] %s                                            \n",dir->d_name);
			}
		}
		closedir(d);
	}
}

void key_fileList(){
	DIR *d;
	struct dirent *dir;
	d = opendir("key");
	if(d){
		while ((dir = readdir(d)) != NULL){
			if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0){
				// Do nothing
			}else{
				printf("  [K] %s                                            \n",dir->d_name);
			}
		}
		closedir(d);
	}
}
