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
