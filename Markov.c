#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int compare(char a[], char b[])
{
   int c = 0;

   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }

   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else
      return -1;
}

long getMicrotime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(int argc, char *argv[]){
	int i=1;
	int index;
	char cur[200];
	FILE* fPointer = fopen("d.txt", "r");
	char output[256000];
	srand((int) time(NULL));
	index = rand() % 335 +1;
	while(!feof(fPointer)){
		fgets(output, sizeof(output), fPointer);
		if(i==index){
			for(int j=0;output[j]!=' ';j++){
				cur[j]=output[j];
			}
		}
		i++;
	}
	printf("%s ", cur);
	char temp[200];
	char next[900][20];
	for(int u=0;u<56;u++){
		int count=0;
		for(int i=0;i<900;i++){
			next[i][0]='\0';
		}
		fPointer = fopen("d.txt", "r");
		while(!feof(fPointer)){
			fgets(output, sizeof(output), fPointer);
			for(int j=0;output[j]!='\n';j++){
				if(output[j]!=' '){
					snprintf(temp, sizeof temp, "%s%c", temp, output[j]);
				}
				else{
					if(compare(cur,temp)==0){
						count++;
						for(int k=j;output[k+1]!=' ' && output[k+1]!='\n';k++){
							snprintf(next[count], sizeof next[count], "%s%c", next[count], output[k+1]);
						}
					}

					temp[0]='\0';
				}
			}temp[0]='\0';
		}
		int position = getMicrotime() % count + 1;

		strcpy(cur, next[position]);
		printf("%s ", cur);
	}
	return 0;
}
