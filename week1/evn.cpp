#include<stdio.h>

int tiencu(int n){
	int bac1=1728, bac2=1786, bac3=2074, bac4=2612, bac5=2919, bac6=3015;
	if(n<=50){
		return n*bac1;
	} else if(n>50 && n<=100) {
		return 50*bac1+(n-50)*bac2;
	} else if(n>100 && n<=200) {
		return 50*bac1+50*bac2+(n-100)*bac3;
	} else if(n>200 && n<=300) {
		return 50*bac1+50*bac2+100*bac3+(n-200)*bac4;
	} else if(n>300 && n<=400) {
		return 50*bac1+50*bac2+100*bac3+100*bac4+(n-300)*bac5;
	} else {
		return 50*bac1+50*bac2+100*bac3+100*bac4+100*bac5+(n-400)*bac6;
	}
}

int tienmoi(int n){
	int bac1=1728, bac2=2074, bac3=2612, bac4=3111, bac5=3457;
	if(n<=100){
		return n*bac1;
	} else if(n>100 && n<=200){
		return 100*bac1+(n-100)*bac2;
	} else if(n>200 && n<=400){
		return 100*bac1+100*bac2+(n-200)*bac3;
	} else if(n>400 && n<=700){
		return 100*bac1+100*bac2+200*bac3+(n-400)*bac4;
	} else {
		return 100*bac1+100*bac2+200*bac3+300*bac4+(n-700)*bac5;
	}
}
int main(){
	int n;
	double chenhlech;
	scanf("%d", &n);
	chenhlech=1.1*(tienmoi(n)-tiencu(n));
	printf("%.2f", chenhlech);
}
