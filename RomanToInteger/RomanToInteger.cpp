#include<iostream>
using namespace std;

int static RtoI(char c){
	switch(c){
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;
	}
}

int romanToInt(string s) {
	int result = 0;
	char last = s.at(0);
	int temp = RtoI(s.at(0));
	int size = s.length();
	for(int i = 1; i<size ; i++){
		if(RtoI(last) >= RtoI(s.at(i))){
			result += temp;
			last = s.at(i);
			temp = RtoI(s.at(i));
		}
		else if(RtoI(last) < RtoI(s.at(i))){
			result -= temp;
			last = s.at(i);
			temp = RtoI(s.at(i));
		}
	}
	return result+temp;
}


void main(){
	cout<<romanToInt("MMCDVI")<<endl;
	getchar();
}
