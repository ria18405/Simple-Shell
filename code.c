#include <stdio.h> 
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() 
{ 
	char input[100]; 
	char array[100][100];
	char history[200][200];
	int hist=0;
	char current_wd[1024];
	char  *gdir;
    char  *dir;
    char  *to;
	while(1){
		int status;


	printf("%s",">>>$$>>>");

   scanf("%[^\n]%*c", input);
   // scanf("%c", input); 


   // if(input[0] == '\0'){
   // 		exit(0);
   // }

   strcpy(history[hist],input);
   hist++;

    char* token = strtok(input, " "); 
    int i=0;
    while (token != NULL) { 
        // printf("%s\n", token); 
        strcpy(array[i],token);
        token = strtok(NULL, " "); 
        i++;
    } 
    // printf("%d",i);
    // int flag=0;
   	// for(int p=0;p<i;p++){
   	// 	if(strcmp(array[p]," ")!=0){
   	// 		flag=1;
   	// 		break;
   	// 	}
   	// }
   	// if(flag==0){
   	// 	printf("Invalid input format - did not match any internal/external command\n" );
   	// }

    //EXIT
    if(strcmp(array[0],"exit")==0){
    	printf("%s\n","EXITING THE SHELL" );
    	// return 0;
    	exit(0);

    }
    //HISTORY-c

    else if(strcmp(array[0],"history")==0 && strcmp(array[1],"-c")==0){
    	memset(history, 0, sizeof(history));
    	hist=0;

    }

    // if(strcmp(array[0],"history")==0 && (array[1][0]!='\0')){
    // 	for(int j=hist-1;j > array[1] ;j--){
    // 		printf("%s\n",history[j] );

    // 	}

    // }
    

    //HISTORY
    else if(strcmp(array[0],"history")==0){
    	for(int j=0;j<hist;j++){
    		printf("%s\n",history[j] );

    	}
    	
    }

    //PWD
    else if(strcmp(array[0],"pwd")==0){
	   	if (getcwd(current_wd, sizeof(current_wd)) != NULL) {
	       	printf("Current working dir: %s\n", current_wd);
	   		}

	}
	//CD
	else if(strcmp(array[0],"cd")==0){
			gdir = getcwd(current_wd, sizeof(current_wd));		//gdir : current dir
            dir = strcat(gdir, "/");
            to = strcat(dir, array[1]);					//to: destination path

            chdir(to);

	}
	//ECHO
	// char* token1 = strtok(input, " "); 
	/*
	if(strcmp(array[0],"echo")==0){
		if(strcmp(array[1],"-n")!=0){

			for(int k=1;k<i;k++){
				for(int kk=0;kk<sizeof(array[k]);kk++){
					if(array[k][kk]==34){			//encountering a "(ignore a ")
						// kk++;
						continue;
					}
					printf("%c",array[k][kk] );			
				}
				
			}	
			printf("\n" );			//nextline
		}
       
     	else{
     	//echo -n
     		for(int k=1;k<i;k++){
				for(int kk=0;kk<sizeof(array[k]);kk++){
					if(array[k][kk]==34){			//encountering a "(ignore a ")
						// kk++;
						continue;
					}
					if(array[k][kk]==45){		//encountering a - (ignore a -)
						kk++;
						continue;
					}
					printf("%c",array[k][kk] );			
				
				}
				
						//nextline
			}	
     	}*/

 else if(strcmp(array[0],"echo")==0 && (strcmp(array[1],"-n")==0)){
 	// for(int j=2;j<i;j++){
 	// 	printf("%s ",array[j] );
 	// }
 	for(int j=2;j<i;j++){
 		for(int k=0;k<sizeof(array[j]);k++){
 			if(array[j][k]!=34 && array[j][k]!=92){
 				printf("%c",array[j][k]);
 			}
 		}
 		printf(" ");
 	}
 }   
else if((strcmp(array[0],"echo")==0)&&(strcmp(array[1],"-E")==0)){

 	for(int j=2;j<i;j++){
 		for(int k=0;k<sizeof(array[j]);k++){
 			if(array[j][k]!=34 && array[j][k]!=92){
 				printf("%c",array[j][k]);
 			}
 		}
 		printf(" ");
 	}
 	printf("\n");
 }
 else if(strcmp(array[0],"echo")==0 && strcmp(array[1],"-n")!=0  && strcmp(array[1],"-E")!=0){

 	for(int j=1;j<i;j++){
 		for(int k=0;k<sizeof(array[j]);k++){
 			if(array[j][k]!=34 && array[j][k]!=92){
 				printf("%c",array[j][k]);

 			}
 		}
 		printf(" ");
 	}
 	printf("\n");
 }
 // else if(strcmp)
    

    /*
    if(strcmp(array[0],"ls")==0){
    	// execlp("/home/ria/Desktop/CAOS","ls",NULL);
    	execlp("/usr/bin/ls", "ls", NULL);
    }
  //   if(strcmp(array[0],"date")){
  //  	// __time_t t;   // not a primitive datatype
  //   // time(&t);
  //   time_t mytime;
		// mytime = time(NULL);
		// printf("%s",ctime(&mytime));

  //   // printf("\n This program has been writen at (date and time): %s", ctime(&t));
  //   }
    if(strcmp(array[0],"date")){
    	execlp("/usr/bin/date","date",NULL);

    }
*/


	char try[] ="/bin/";

     // char * try=getcwd(current_wd, sizeof(current_wd));
     // strcat(try,"/");
	strcat(try,array[0]);
	// printf("%s",try);		

	int pid=fork();

// char * newarray[100][100];
// for(int y=1;y<i;y++){
// 	strcpy(newarray[y-1],array[y]);
// 	printf("%s\n",newarray[y-1] );
// }

// 		execv(try,newarray[0]);
// 	}

// }
if(pid==0){
	// if(array[1][0]== '\0'){
		// if(strcmp(array[0],"ls")==0){
		//     execlp(try, "ls", NULL);
		// }
		// else if(strcmp(array[0],"date")==0){
		// 	execlp(try,"date",NULL);
		// }
		// else if(strcmp(array[0],"mkdir")==0){
		// 	execlp(try,"mkdir",array[1],NULL);
		// }
		// else if(strcmp(array[0],"rm")==0){
		// 	execlp(try,"rm",array[1],NULL);
		// }
		// else if(strcmp(array[0],"rm")==0){
		// 	execlp(try,"rm",array[1],NULL);
		// }
		// else if(strcmp(array[0],"cat")==0){
		// 	execlp(try,"cat",array[1],NULL);
		// }
	// }

			if( array[1][0]!= '\0'){
				// printf("%s\n", array[0]);
				execlp(try,array[0], array[1], NULL);
			}
			else {
				// execlp("/bin/ls","ls",NULL);
				execlp(try,array[0], NULL);

			}
			exit(0);
	
}
else{
	wait(NULL);
}
// execlp("bin/ls", "ls", NULL);}

// }
memset(array,0,sizeof(array));


} 
return 0;
}