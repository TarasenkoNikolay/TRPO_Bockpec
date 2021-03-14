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
	
    for(int i=0;i<N;i++) result[i]='_';
	
    system("cls");
	
    for(int i=0;i<N;i++){
		
		for(int j=0;j<N;j++){
			if(trueword[i]==word[j]) result[j]=trueword[i];
		}
	}

	cout<<errorGr[error]<<endl;
	cout<<endl<<"TRUE LETTER:     ";
	
    for(int i=0;i<N;i++){
		cout<< result[i]<<", ";
	}
	
    cout<<endl<<"FALSE LETTER:     ";
	
    for(int i=0;i<5;i++){
	        cout << falseword[i]<< "  ";
	}
	cout<<endl;
}

int main(){
	int tru=0,fal=0,error=0,mmm;
	char c;
	char word[50]={0};
	char falseword[50]={0};
	char trueword[50]={0};
    ifstream fin;
	fin.open("C:/Temp/Kolya/TRPO_Bockpec/words.txt");
	fin >> word;
	
	int N=sizeWord(word);

	int mod = 0 ;
	
	while(1){
	        cout << "Select game mode"<<endl<<"1 - auto play (default)"<<endl<<"2 - play in manual mode"<<endl;
          	cin >> mod;
           	if (mod == 1) break;
            if (mod == 2) break;
            system("cls");
    }
	
	int qwe=countLetter(word);
	
	errorLetter(N,error,word,falseword,trueword);
	
	while(true){
		mod == 1 ? fin >> c : cin >> c;
		if (letterCheck(word,c)==true) {
			if (letterCheck(trueword,c)==false) {
				trueword[tru]=c;
				tru++;
			}else{
				cout<<"Bukva vvodilas"<<endl;
			}
		}else{
			if(letterCheck(falseword,c)==true){
				cout<<"Bukva vvodilas"<<endl;
			}
			else{
				falseword[fal]=c;
				fal++;
				error++;
					
				
			}
		}
		
		errorLetter(N,error,word,falseword,trueword);
		if (tru==qwe){ cout<<"WIN!" <<endl; break;}
		if (error==5){ cout<<"LOSE!" <<endl; break;}
	}
	
	system("pause");
	return 0;
}













