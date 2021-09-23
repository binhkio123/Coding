#include<stdio.h>
#include<string.h>
#include<windows.h>

struct SinhVien
{
    char Name[30];
    char MSSV[12];
    char QueQuan[30];
    float GPA;
};
SinhVien sv[1];

int stt=0;
float tongDiem;
void showMenu(){
    system("cls");
    printf("\n--------CHUONG TRINH QUAN LY THONG TIN SINH VIEN--------");
    printf("\n 1. Nhap thong tin sinh vien");
    printf("\n 2. In thong tin sinh vien");
    printf("\n 3. Tim kiem sinh vien theo MSSV");
    printf("\n 4. Tim kiem sinh vien theo que quan va GPA");
    printf("\n 5. Sap xep theo thu tu GPA giam dan");
    printf("\n 6. Thoat");
    printf("\n>> ");
}
void nhap(SinhVien &SV, int stt){
    int i;
    printf("1. Ho va ten: "); fflush(stdin); fgets(SV.Name,30,stdin);
nhapmssv: printf("2. MSSV: "); fflush(stdin); fgets(SV.MSSV,12,stdin);
    for(i=0;i<stt;i++){
        if(strcmp(sv[i].MSSV,SV.MSSV)==0){
            printf("**Sinh vien da ton tai trong he thong! Vui long nhap sinh vien khac...");
            goto nhapmssv;
        }
    }
    printf("3. Que quan: "); fflush(stdin); fgets(SV.QueQuan,30,stdin);
    gpa: printf("4. GPA: "); scanf("%f",&SV.GPA);
    if(SV.GPA<=0||SV.GPA>4){
        printf("**Vui long nhap GPA trong khoang [0,4]\n");
        goto gpa;
    }
    printf("----------------------------------\n");
}
void nhapN(int N, SinhVien SV[]){
    system("cls");
    int i;
    printf("-----NHAP THONG TIN SINH VIEN-----\n");
    for(i=stt;i<stt+N;i++){
        nhap(SV[i],i);
    }
    stt+=N;
}
void xuatN(){
    system("cls");
    int i;
    printf("------------DANH SACH SINH VIEN------------");
    printf("\n STT    Ho va ten                MSSV      Que quan           GPA   ");
    for(i=0;i<=stt;i++){
        printf("\n%-5d%-30s%-12s%-30s%-5.1f",i+1,sv[i].Name,sv[i].MSSV,sv[i].QueQuan,sv[i].GPA);
        tongDiem+=sv[i].GPA;
    }
    
    printf("\nDiem GPA trung binh: %.1f", tongDiem/(stt+1));
}
void xuat(int i){
    printf("\n%-5d%-30s%-12s%-30s%-5.1f",i+1,sv[i].Name,sv[i].MSSV,sv[i].QueQuan,sv[i].GPA);
}
void sapXep(){
    int i,j;
    for(i=0;i<=stt;i++){
        for(j=i;j<=stt;j++){
            if(sv[i].GPA<sv[j].GPA){
                SinhVien tmp=sv[i];
                sv[i]=sv[j];
                sv[j]=tmp;
            }
        }
    }
    xuatN();
}

int main(){
    int N,i,choice;
    while (choice!=6)
    {
    begin: showMenu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
        slsv: printf("So luong sinh vien: "); scanf("%d",&N);
            if(N<=0){
                printf("**Vui long nhap chinh xac so luong sinh vien!\n");
                fflush(stdin);
                goto slsv;
            }
            (SinhVien*)malloc((N)*sizeof(SinhVien));
            nhapN(N,sv);
            printf("\n>> Nhan phim Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 2:{
            xuatN();
            printf("\n>> Nhan phim Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 3:{
            system("cls");
            char fMSSV[12];
            printf("\n\tNhap MSSV can tim: ");
            fflush(stdin); fgets(fMSSV,12,stdin);
            int i;
            for(i=0;i<=stt;i++){
                if(strcmp(fMSSV,sv[i].MSSV)==0){
                    printf("------------THONG TIN SINH VIEN------------");
                    printf("\n STT    Ho va ten                MSSV      Que quan           GPA   ");
                    xuat(i);
                } else{
                    printf("\nKhong the tim thay sinh vien!");
                }
            }
            printf("\n>> Nhan phim Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 4:{
            char fQueQuan[30];
            printf("Nhap que quan sinh vien: ");
            fflush(stdin); fgets(fQueQuan,30,stdin);
            int i;
            printf("\n STT    Ho va ten                MSSV      Que quan           GPA   ");
            for(i=0;i<=stt;i++){
                if(strcmp(fQueQuan,sv[i].QueQuan)==0 && sv[i].GPA>(tongDiem/(stt+1))){
                    xuat(i);
                }
            }
            printf("\n>> Nhan phim Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 5:{
            sapXep();
            printf("\n>> Nhan phim Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 6:
            break;
        default:
            goto begin;
        }
    }
    return 0;
}