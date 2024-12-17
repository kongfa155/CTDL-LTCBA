#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *HoTen;
	float LT, TH;
	char *DiemChu;
} SinhVien;


SinhVien nhapSV(){
    char ten[50];
    fgets(ten,50, stdin);
    int len = strlen(ten);
    if (ten[len-1]=='\n'){
        len--;
        ten[len] = '\0';
    }
	SinhVien a;
	a.HoTen = malloc(len);
	a.DiemChu = malloc(3);
	strcpy(a.HoTen,ten);
	scanf("%f%f",&a.LT,&a.TH);
    float tong = a.LT + a.TH;
    char *grade;
    if(tong >= 9)
        grade = "A";
    else if(tong >= 8)
        grade = "B+";
    else if(tong >= 7)
        grade = "B";
    else if(tong >= 6)
        grade = "C+";
    else if(tong >= 5)
        grade = "C";
    else if(tong >= 4.5)
        grade = "D+";
    else if(tong >= 4)
        grade = "D";
    else
        grade = "F";
    strcpy(a.DiemChu,grade);
	getchar();
	return a;
}

void inSV(SinhVien a){
	printf("%s %.3f %.3f %s", a.HoTen, a.LT,a.TH,a.DiemChu);
}

void nhapDS(SinhVien **pL, int n){
    int i;
    *pL = malloc(sizeof(SinhVien)*n);
	for(i = 0; i <= n;i++){
		*pL[i]= nhapSV();
	}
}

void inDS(SinhVien *L,int n){
    int i;
	for(i = 0; i <= n - 1;i++){
		inSV(L[i]);
	}
}
int main(){
	int n;
	SinhVien *list;
	scanf("%d ", &n);
	nhapDS(&list, n);0
	inSV( n);
	free(list);
	return 0;
}

