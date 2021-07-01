#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
using std::ifstream;

void match(string txt, string pat,int line,ofstream& op){ //pass text, pattern , line no, output file pointer
    int t=txt.size();
    int p=pat.size();
    int j;
    for(int i=0;i<=(t-p);i++){
        for(j=0;j<p;j++){
            if(pat[j]!='_' && pat[j]!=txt[i+j]){		//checking condition
                break;
            }    
        }
        if(j==p){
                 op<<"Pattern found at line - "<<line<<"  index - "<< i << endl;
        }
    }
}
int main(){
    string txt;
	string ptr;
	int line;			//to track line 
	
	char filepath[40];	//to store file names
	char ptrpath[40];
	char outputpath[40];
	int i;	
	
	while(1){
		cout<<"\n\nWe have 5 test cases"<<endl;
		cout<<"Which test case do you want to run?"<<endl;
		cin>>i;
		
		if(i<=5){
			line=1;
		
			sprintf(outputpath,"output/patternmatch%d.txt", i);	//save output file path in outputpath array 
			sprintf(filepath,"input/text/text%d.txt", i);		//save file path in filepath array
			sprintf(ptrpath,"input/pattern/pattern%d.txt", i);	//save patern path in ptrpath array
			
			ifstream fp(filepath);				//create file pointer as fp
			ifstream pp(ptrpath);				//create pattern pointer as pp 
			ofstream op(outputpath);			//create output pointer as op	
				
			getline (pp, ptr);					//read pattern
			op<<"***Test case "<<i<<"***"<<endl;
			if(fp.is_open()){					//read line by line and match text and pattern 
				while(getline(fp,txt)){
					if(ptr.size()>0 && txt.size()>0){
						match(txt,ptr,line,op);		//naive function
						line++;						//to change line
					}
					else{
						cout<<"Empty file"<<endl;
						break;
					}
										
				}
			}
			else{
				cout<<"faild to open this file!";
				break;
			}	
			fp.close();							//close files
			pp.close();
		}			
	}
}
