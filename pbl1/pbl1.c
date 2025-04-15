#include <stdio.h>
#include <string.h>
void logo()
{
    printf("\n ________________________________________________________________________________________________________________________________________________________________________ \n");
    printf("|                                       |                                                                                                                                |\n");
    printf("|     D                                 |                           MINISTRY OF EDUCATION AND TRAINING                                                                   |\n");
    printf("|                                       |               UNIVERSITY OF SCIENCE AND TECHNOLOGY-UNIVERSITY OF DA NANG                                                       |\n");
    printf("| B   A   C   H   K   H   O   A         |                                  _________________                                _____________________________                |\n");
    printf("|         ___________________________   |                                                                                  |                             |               |\n");
    printf("|     N  |          ...              |  |                   Lecturer       : Nguyễn Công Danh.                             |       ^             ^       |               |\n");
    printf("|        |            ....           |  |                                                                                  |            *   *            |               |\n");
    printf("|     A  |             ......        |  |                   Project        : PBL1- giải hệ phương trình tuyến tính         |                             |               |\n");
    printf("|        |              .......      |  |                                                                                  |              O              |               |\n");
    printf("|     N  |              .........    |  |                   Students       : Nguyễn Hữu Duy Bảo                            |_____________________________|               |\n");
    printf("|        |             ...........   |  |                                    Lương Danh Thiện.                            /   ______________________    /                |\n");
    printf("|     G  |            .............  |  |                                                                                /   /____/____/_____/_____/   /                 |\n");
    printf("|        |          ...............  |  |                   Section Class  : 23.10                                      /   /____/____/_____/_____/   /                  |\n");
    printf("|        |       ..................  |  |                                                                              /   /____/____/_____/_____/   /                   |\n");
    printf("|        |    ....................   |  |                   Activity Class : 23T_Nhat1                                /_____________________________/                    |\n");
    printf("|        |.......................    |  |                                    23T_DT2                                                                                     |\n");
    printf("|        |.....................      |  |                                                                                                                                |\n");
    printf("|        |___________________________|  |                                                                                         Da Nang, ngay 20 thang 04 nam 2024     |\n");
    printf("|_______________________________________|________________________________________________________________________________________________________________________________|\n"); 
	printf("\n\n");     
}
void hoandoi(long m, long n,double A[m][n],int h1,int h2 ){
    int i;
    double tam;
    for ( i = 0; i < n; i++)
    { 
        tam=A[h1][i];
        A[h1][i]=A[h2][i];
        A[h2][i]=tam;
    }    
}
void xuatmt(long m,long n,double A[m][n]){
	int i,j;
	for( i = 0 ; i < m ; i++ )
	{   printf("|");
		for( j = 0 ; j < n ; j++ )
		{  
            if( A[i][j] > 0 ){
                printf("%12.2lf",A[i][j]);
            }else{
                if( A[i][j] > -0.01 ){
                    printf("        0.00");
                }else{
                    printf("%12.2f",A[i][j]);
                }
            }
        }
        printf(" |");
		printf("\n");
	}
}
int  sx_matran(long m,long n,double A[m][n],int i){
    int j=i+1;
    while ( A[j][i] == 0 && j < m ) j++;
    if(j < m){    
        hoandoi(m,n,A,i,j); 
        return -1;
    }
    return 1;
}
double mt_hinhthang(long m,long n,double A[m][n]){
	int i,j,u,dau=1;
    double k;
    for( i = 0 ; i < m-1 ; i++ ){
        if( A[i][i] == 0 ) dau*=sx_matran(m,n,A,i);
        if(A[i][i]==0) continue;
        for( u = i ; u < m-1 ; u++ ){ 
            k=-A[u+1][i]/A[i][i];
            for( j = i ; j < n ; j++ ){  
                A[u+1][j]=k*A[i][j]+A[u+1][j];
            }
        }
    }  
    if(dau < 0)return -1;
    return 1;
}
double dinhthuc(long m,long n,double A[m][n]){
	int i,j,u;
    float k;
    double d=mt_hinhthang(m,n,A);
     
	for ( i = 0 ; i < m ; i++)
	{
		d=d*A[i][i];
	}
	return d;
}
//  sao chep ma tran
void copy_1(long m,long n,double A[m][n],double B[m][n])
{
	int i,j;
	for ( i = 0 ; i < m ; i++ ){
		for ( j = 0 ; j < n ; j++ ){
			A[i][j]=B[i][j];
		}
	}
}
// sao chep mang
void copy_2(long n,double A[n],double B[n]) 
{
	int i,j=0;
	for ( i = 0; i < n ; i++ ){
		A[i]=B[i];
	}
}
void doi(long n,double C[n][n],double B[n],int k)
{
	int i;
	for (i = 0; i < n; i++)
	{
		C[i][k]=B[i];
	}
}
void cramer(long n,double A[n][n],double B[n],double x[n])
{   int i;
    double c[n][n];
    printf("Ma trận hằng số ban đầu:\n\n");
	xuatmt(n,n,A);
    printf("\nVetto he so:\n");
    for ( i = 0 ; i < n ; i++)
    {
        printf("|%12.2lf |\n",B[i]);
    }
	copy_1(n,n,c,A);
	double d=dinhthuc(n,n,c);
	printf("\n\nBước 1: tính định thức của ma trận ban đầu bằng cách ta chuyển về ma trận tam giác.\n\n");
	xuatmt(n,n,c);
	printf("\nTừ đây ta được định thức d= %.2lf\n\n",d);
	if(d==0 ){
		printf("Vì định thức bằng 0 phương trình không có nghiệm duy nhất nên phương pháp Cramer không thể sử dụng để giải hệ phương trình\n\n");
	}else{
	    printf("Vì định thức ban đầu khác 0 thoả mãn điều kiện nên ta sang bước 2:\n\n");
	    for ( i = 0 ; i < n ; i++ )
	    {  
			printf("***************************************************\n ");
            printf("Ma trận d[%d] có dạng:\n\n",i+1);
            copy_1(n,n,c,A);
	        doi(n,c,B,i);
			xuatmt(n,n,c);
            x[i]=dinhthuc(n,n,c);
            printf("\nMa trận tam giác d[%d]:\n\n",i+1);
            xuatmt(n,n,c);
			printf("\nĐịnh thức của d[%d] = %.2lf \n\n",i+1,x[i]);
            x[i]=x[i]/d;
            printf("=> Ta có x[%d]= d[%d]/d = %.2lf\n\n",i+1,i+1,x[i]);
	    }
        printf("Vậy ta có nghiệm:\n\n");
	    for ( i = 0 ; i < n ; i++)
        {   if( x[i] < 0.01 && x[i] > -0.01) {
                printf("x[%d]= 0.00\n",i+1);
                continue;
            }
            printf("x[%d]= %.2lf\n",i+1,x[i]);
        }
	}
}
void gauss(long n, double A[n][n], double B[n],double x[n]) {
    int i, j, k;
    long m = n;
    n= n+1;
    double c[m][n];
    for ( i = 0 ; i < m ; i++ ){   
        for ( j = 0 ; j < n-1 ; j++ ){
            c[i][j]=A[i][j];
        }
        c[i][n-1]=B[i];
    }
    printf("Ma trận ban đầu:\n\n");
    xuatmt(m,n,c);
    printf("\n\n");
    printf("Ma trận hình thang:\n\n");
    mt_hinhthang(m,n,c);
    xuatmt(m,n,c);
    printf("\n\n");
    for ( i = m-1; i >= 0; i--){
        x[i]=c[i][n-1];
        for ( j = m-1 ; j > i ; j--){
            x[i]-=x[j]*c[i][j];
        }
        if(c[i][i]==0){
            if(x[i]==0){
                printf("Phương trình vô số nghiệm\n");
                return;
            }
            printf("Phương trình vô nghiệm\n");
             return;
        }
        x[i]=x[i]/c[i][i];
    }
    printf("Vậy ta có nghiệm: \n\n");
    for ( i = 0 ; i < m ; i++)
        {   if( x[i] < 0.01 &&x[i] > -0.01) {
                printf("x[%d]= 0.00\n",i+1);
                continue;
            }
            printf("x[%d]= %.3lf\n",i+1,x[i]);
        }
}
void xuat_file(long n,double x[n],double A[n][n],double B[n]){	
    int i=0;
    printf("Nhập tên file xuất ra (không cần điền .txt ) : ");
    char s[20];
    scanf("%s",s);
    strcat(s, ".txt");
    FILE *f=fopen((s),"w");
    fprintf(f,"Ma trận:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             fprintf(f," %.2lf  ", A[i][j]);
        }
        fprintf(f," %.2lf  \n",B[i]);
    }
    fprintf(f,"Nghiệm của hệ phương trình là:\n");
    for (i = 0; i < n; i++) {
        if( x[i] < 0.01 && x[i] > -0.01){
            fprintf(f,"x[%d] = 0.00\n", i+1 );
            continue;
        }
            fprintf(f,"x[%d] = %.2lf\n", i+1 , x[i]);
    }
    fclose(f);
}
long nhap_file(FILE **fp){
    long n;
    int k;
    do
    {
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("|   Lựa chọn:                                                  |\n");
        printf("|   1. Để tạo file ma trận mới                                 |\n");
        printf("|   2. Nhập file ma trận có sẵn trong máy                      |\n");
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf(" Nhập lựa chọn:");
        scanf("%d",&k);
        if(k!=2&&k!=1)printf("Lựa chon của bạn không thoã mãn xin chọn lại!!\n");
    } while (k!=2&&k!=1);
    char s[20];
    printf(" Nhập tên file đầu vào (không cần điền .txt ): ");
    scanf("%s",s);
    strcat(s, ".txt");
    switch (k)
    {
        case 1:
            *fp=fopen(s,"w");
            printf("Nhập số ẩn (n): ");
            scanf("%ld",&n);
            double A[100][100+1];
            fprintf(*fp," %ld \n",n);
            for (int i = 0; i < n; i++)
            {  
                for (int j = 0; j < n+1; j++)
                {   printf(" Nhập A[%d][%d]:",i+1,j+1);
                    scanf("%lf",&A[i][j]);
                    fprintf(*fp," %lf ", A[i][j]);
                }
                fprintf(*fp,"\n");
            }
            fclose(*fp);
            *fp = fopen(s, "r");
            if (*fp == NULL) {
                printf("Lỗi mở file\n");
                return 0;
            }
            fscanf(*fp, "%ld",&n);
            return n;
            break;
        case 2:
            *fp = fopen(s, "r");
            if (*fp == NULL) {
                printf("\n Lỗi mở file\n");
                return 0;
            }
            fscanf(*fp, "%ld",&n);
            return n;
        default:
        return 0;       
    }
}
void doc_file(long n,double A[n][n],double B[n],FILE *fp){
    printf("\n Ma trận có dạng:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%lf", &A[i][j]);
            printf("%12.2lf",A[i][j]); 
        }
        fscanf(fp, "%lf", &B[i]);
        printf("%12.2lf\n", B[i]);
    }
    fclose(fp);
}
int main(){
    logo();
    FILE *fp;
    long n, i, j,choice;
    n=nhap_file(&fp);
    while(fp==NULL){
        printf("\n File không tồn tại mời nhập lại:\n");
        n=nhap_file(&fp);
    }
    double A[100][100],B[100],x[100];
    printf("\n\nGiải phương trình hệ tuyến tính bằng phương pháp Gauss và phương pháp cramer\n\n");
    doc_file(n,A,B,fp);
    do {
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("|   Lua chon:                                                  |\n");
        printf("|   1. Giai bang phuong phap gauss.                            |\n");
        printf("|   2. Giai bang phuong phap cramer.                           |\n");
        printf("|   3. Xuat ra file                                            |\n");
        printf("|   4. Exit.                                                   |\n");
        printf("|   5. chon file khac                                          |\n");
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("Nhập lựa chọn : ");
        scanf("%ld", &choice);
        double a_tam[n][n];
        double b_tam[n];
        copy_1(n,n,a_tam,A);
        copy_2(n,b_tam,B);
        switch (choice) {
            case 1:
                printf("\nGauss:\n\n");
                gauss(n, a_tam,b_tam,x);
                break;
            case 2:
                printf("\nCramer:\n\n");
                cramer(n,a_tam,b_tam,x);
                break;
            case 3:
                xuat_file(n,x,A,B);
            case 4:
                printf("Exiting...\n");
                return 0;
            case 5:
                n=nhap_file(&fp);
                while(fp==NULL){
                    printf("File không tồn tại mời nhập lại!!:\n");
                    n=nhap_file(&fp);
                }
                doc_file(n,A,B,fp);
                break;
            default:
                printf("Lựa chon của bạn không thoã mãn xin chọn lại!!\n");
        }
       
    } while (choice != 4);

}