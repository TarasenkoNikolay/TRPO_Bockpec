#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string.h>
using namespace std;

int sizeWord(char word[]){
	int N=0;
	while(word[N]!=0) N++;
	return N;
}

bool letterCheck(char word[], char c){  
	int N=sizeWord(word);
	for (int i=0;i<N;i++){
		if (word[i]==c) return true;
	}
	return false;
}

int countLetter(char word[]){
	int N=sizeWord(word);
	char newword[N+1];
	bool check;
	int m=0; int w=0;
	
	for (int i=0;i<N;i++){
		check=false;
		for(int j=0;j<N;j++){ 
			if (word[i]==newword[j]) check=true;  
		}
		if (check==false) {
			newword[m]=word[i];
			m++;
		}
	}
	
	while(newword[w]!=0){
		w++;
	}
	
	return w;
}

void errorLetter(int N, int error, char word[], char falseword[],char trueword[]) {
	string errorGr[6]={ ("--"),("--O"),("--O-"),("--O-<"),("--O-<-"),("--O-<-<") };
   	
	char result[50];
	
    
}















