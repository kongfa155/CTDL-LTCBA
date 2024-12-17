#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 5
#define MINE -1

int B[M][N];
int T[M][N];

void init() {
    for(int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            B[i][j] = 0;
            T[i][j] = 0;
        }
        /*
        
        B[1][2] = MINE;
        B[3][1] = MINE;
        */
    }
    B[1][2] = MINE;
    B[3][1] = MINE;
}
void count_mines() {
    for(int i = 0; i < M;i++) {
        for(int j = 0; j < N; j++) {
            if (B[i][j] == -1)
                continue;
            int cnt = 0;
           
            if(i+1 <M && j+1 < N && B[i+1][j+1] == MINE)
                cnt++;
            if(i-1 >=0 && j-1 >=0 && B[i-1][j-1]== MINE)
                cnt++;
            if(i+1 < M && j-1 >=0 && B[i+1][j-1] == MINE)
                cnt++;
            if(i-1 >=0 && j+1 < N && B[i-1][j+1] == MINE)
                cnt++;
            if(j-1 >=0 && B[i][j-1] == MINE)
                cnt++;
            if(j+1 < N && B[i][j+1] == MINE)
                cnt++;
            if(i+1 < M && B[i+1][j] == MINE)
                cnt++;
            if(i-1 >=0 && B[i-1][j] == MINE)
                cnt++;
            B[i][j] = cnt;
        }
    }
}
void printMap1() {
	//In dong dau
    printf("  ");
    for (int j = 0 ; j < N; j++) {
        printf("%d ",j%10);
    }
    printf("\n");
    for(int i = 0; i < M ;i++) {
    	//In chi so dong
        printf("%d ",i%10);
        for(int j = 0; j < N;j++) {
            if (B[i][j] == MINE)
                printf("x ");
            else if (B[i][j] == 0)
                printf(". ");
            else printf("%d ",B[i][j]);
        }
        printf("\n");
    }
}
void printMap2() {
	//In dòng dau 
     printf("  ");
    for (int j = 0 ; j < N; j++) {
        printf("%d ",j%10);
    }
    printf("\n");
   
    for(int i = 0; i < M ;i++) {
    	//In chi so dong
        printf("%d ",i%10);
        for(int j = 0; j < N;j++) {
            if (T[i][j] == 0)
                printf("# ");
            else if(T[i][j]==1) {
            	// Neu o da mo roi thi check theo quy tac
                if (B[i][j] == MINE)
                printf("x ");
                //La bom thi in X
            	else if (B[i][j] == 0)
                printf(". ");
                //Khong co j thi in cham
                //Con xung quanh co bom thi in chi so B[i][j]
            	else printf("%d ",B[i][j]);
        }
       
    }
    //Xuong dong sau khi chay xong
    printf("\n");
    }
   
}
int count_remain() {
    int cnt = 0;
        for ( int i = 0 ; i < M; i++)
            for (int j = 0; j < N ; j++ )
                if(T[i][j] == 0)
                    cnt ++;
        return cnt;
}
void open_cell_1(int r,int c ) {
    if (T[r][c]==0)
    T[r][c] =1;
}
int main() {
    int r,c;
    int k=2;
    //Khuc nay thieu ham khoi tao :>>> 
    init();
    count_mines();
    printMap2();
    while(1) {
    printf("Nhap o ban muon mo: ");
    scanf("%d%d",&r,&c);
    if(B[r][c] == MINE) {
	        printMap1();
	        printf("YOU LOSE.\n");
	        break;
    	}
    	open_cell_1(r,c);
        if(count_remain()==k ){
	        printMap2();
	        printf("YOU WIN.\n");
	        break;
        }
    //Sau khi check truong hop la thua hoac win thì phai in map sau khi mo de choi tiep. 
    	printMap2();
    }
    return 0;
}

