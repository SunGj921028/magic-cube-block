#include<stdio.h>
#include<stdint.h>

void temp1(int32_t g[3][3],int32_t r[3][3],int32_t b[3][3],int32_t p[3][3],int32_t w[3][3],int32_t y[3][3],int32_t n){
	int32_t Temp[3][3]={0};
	int32_t Temp3[3][3]={0};
	for(int32_t k=0;k<3;k++){
		Temp[n-1][k]=r[n-1][k];
		r[n-1][k]=g[n-1][k];
		g[n-1][k]=p[n-1][k];
		p[n-1][k]=b[n-1][k];
		b[n-1][k]=Temp[n-1][k];
	}
	if(n==1){
                Temp3[0][0]=w[0][0];
                w[0][0]=w[0][2];
                Temp3[0][1]=w[0][1];
                w[0][1]=w[1][2];
                w[0][2]=w[2][2];
                Temp3[0][2]=w[1][0];
                w[1][0]=Temp3[0][1];
                w[1][2]=w[2][1];
                Temp3[0][1]=w[2][0];
                w[2][0]=Temp3[0][0];
                w[2][1]=Temp3[0][2];
                w[2][2]=Temp3[0][1];
	}
        if(n==3){
                Temp3[0][0]=y[0][0];
                y[0][0]=y[2][0];
                Temp3[0][1]=y[0][1];
                y[0][1]=y[1][0];
                Temp3[0][2]=y[0][2];
                y[0][2]=Temp3[0][0];
                y[1][0]=y[2][1];
                Temp3[0][0]=y[1][2];
                y[1][2]=Temp3[0][1];
                y[2][0]=y[2][2];
                y[2][1]=Temp3[0][0];
                y[2][2]=Temp3[0][2];
	}
}

void temp2(int32_t w[3][3],int32_t r[3][3],int32_t y[3][3],int32_t p[3][3],int32_t g[3][3],int32_t b[3][3],int32_t n){
	int32_t Temp2[3][3]={0};
	int32_t Temp5[3][3]={0};
	int32_t l=2;
	for(int32_t m=0;m<3;m++){
		Temp2[m][n-4]=r[m][n-4];
		r[m][n-4]=w[m][n-4];
		if(n==4){
			w[m][n-4]=p[l][2];
                	p[l][2]=y[m][n-4];
		}
		if(n==5){
			w[m][n-4]=p[l][1];
                	p[l][1]=y[m][n-4];
		}
		if(n==6){
			w[m][n-4]=p[l][0];
			p[l][0]=y[m][n-4];
		}
		y[m][n-4]=Temp2[m][n-4];
		l--;
	}
	if(n==4){
		Temp2[0][0]=g[0][0];
                g[0][0]=g[2][0];
		Temp2[0][1]=g[0][1];
                g[0][1]=g[1][0];
		Temp2[0][2]=g[0][2];
                g[0][2]=Temp2[0][0];
		g[1][0]=g[2][1];
		Temp2[0][0]=g[1][2];
                g[1][2]=Temp2[0][1];
                g[2][0]=g[2][2];
                g[2][1]=Temp2[0][0];
                g[2][2]=Temp2[0][2];
	}
	if(n==6){
		Temp2[0][0]=b[0][0];
                b[0][0]=b[0][2];
                Temp2[0][1]=b[0][1];
                b[0][1]=b[1][2];
                b[0][2]=b[2][2];
		Temp2[0][2]=b[1][0];
                b[1][0]=Temp2[0][1];
                b[1][2]=b[2][1];
		Temp2[0][1]=b[2][0];
                b[2][0]=Temp2[0][0];
                b[2][1]=Temp2[0][2];
                b[2][2]=Temp2[0][1];
	}
}

int main(){
	int32_t r[3][3]={0};
        int32_t g[3][3]={0};
        int32_t b[3][3]={0};
        int32_t p[3][3]={0};
        int32_t w[3][3]={0};
        int32_t y[3][3]={0};
	for(int32_t i=0;i<3;i++){
		for(int32_t j=0;j<3;j++){
			r[i][j]=1;
			g[i][j]=2;
			b[i][j]=3;
			p[i][j]=4;
			w[i][j]=5;
			y[i][j]=6;
		}
	}
	printf("Start:\n");
	for(int32_t i=0;i<3;i++){
		for(int32_t j=0;j<3;j++){
			printf("\e[31m* \e[m");
			if(j==2){
				printf("\n");
			}
		}
	}
	double n=1;
	while(n!=0){
		printf("Input [0-6]: ");
		scanf("%lf",&n);
		if(n!=0&&n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6){
                        printf("Invalid Input\n");
                        continue;
                }
		if(n==0){
			break;
		}
		if(n==1||n==2||n==3){
			temp1(g,r,b,p,w,y,n);
		}
		if(n==4||n==5||n==6){
			temp2(w,r,y,p,g,b,n);
		}
		for(int32_t i=0;i<3;i++){
                	for(int32_t j=0;j<3;j++){
                        	if(r[i][j]==1){
                                	printf("\e[31m* \e[m");
                        	}
                        	if(r[i][j]==2){
                                	printf("\e[32m* \e[m");
                        	}
                        	if(r[i][j]==3){
                                	printf("\e[34m* \e[m");
                        	}
                        	if(r[i][j]==4){
                                	printf("\e[38;5;208m* \e[m");
                        	}
                        	if(r[i][j]==5){
                                	printf("* ");
                        	}
                        	if(r[i][j]==6){
                                	printf("\e[33m* \e[m");
                        	}
				if(j==2){
					printf("\n");
				}
			}
		}
	}
}
