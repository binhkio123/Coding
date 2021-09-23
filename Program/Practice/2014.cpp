#include<stdio.h>
#include<string.h>
#include<windows.h>

int n=0;

struct SinhVien
{
    int MSSV;
    char Name[30];
    float huongDan, phanBien, hoiDong[3];
    float GK,CK;
};
SinhVien sv[1];

void showMenu(){
    system("cls");
    printf("\n------CHUONG TRINH TINH DIEM TOT NGHIEP------");
    printf("\n 1. Bo sung sinh vien\n 2. Danh sach sinh vien bao ve thanh cong\n 3. Sap xep theo ten sinh vien\n 4. Thoat chuong trinh");
    printf("\n>> ");
}

bool ktDiem(float a){
    if(a<5.5||a>10){
        return false;
    } else{
        return true;
    }
}
void nhap(SinhVien &SV, int S){
    system("cls");
    printf("\n-----KHAI BAO THONG TIN-----\n");
mssv: printf("\n1. Nhap MSSV: "); scanf("%d",&SV.MSSV);
    if(SV.MSSV<1||SV.MSSV>99999){
        printf("Vui long nhap lai MSSV !");
        goto mssv;
    }
    int i,j;
    for(i=0;i<S;i++){
        if(SV.MSSV==sv[i].MSSV){
            printf("* MSSV da ton tai! *\n");
            goto mssv;
        }
    }
    printf("2. Nhap ho va ten: ");
    fflush(stdin); gets(SV.Name);
    // kiemTraTenSV----------
    int i,j;
    int X=strlen(SV.Name);
    while(SV.Name[0]==32){       //loai bo khoang trang dau ten
        for(i=0;i<X-1;i++){
            SV.Name[i]=SV.Name[i+1];
        }
        X--;
    }
    if(SV.Name[0]>90){     //viet hoa dau dong
        SV.Name[0]-=32;
    }
    i=0;
    while(i!=X-1){       //loai bo DoubleSpace
        if(SV.Name[i]==32 && SV.Name[i+1]==32){
            for(j=i;j<X-1;j++){
                SV.Name[j]=SV.Name[j+1];
            }
            X--;
        } else{i++;}
    }
    for(i=X-1;i>0;i--){      //loai bo khoang trang cuoi ten
        if(SV.Name[i]==32){
            SV.Name[i]=SV.Name[i+1];
        }else{break;}
    }
    for(i=1;i<X;i++){       //viet hoa ten
        if(SV.Name[i]!=32 && SV.Name[i-1]==32){
            if(SV.Name[i]>90){
                SV.Name[i]-=32;
            }
        }
    }
    //-----------------------
    printf("3. Diem cua SV:\n");
    printf("+ Diem huong dan: "); scanf("%f",&SV.huongDan);
    while(SV.huongDan<=0 || SV.huongDan>10){
        printf("+ Diem huong dan: "); scanf("%f",&SV.huongDan);
    }
    printf("+ Diem phan bien: "); scanf("%f",&SV.phanBien);
    while(SV.phanBien<=0 || SV.phanBien>10){
        printf("+ Diem phan bien: "); scanf("%f",&SV.phanBien);
    }
    while( (SV.hoiDong[0]<=0 || SV.hoiDong[0]>10) || (SV.hoiDong[1]<=0 || SV.hoiDong[1]>10) || (SV.hoiDong[2]<=0 || SV.hoiDong[2]>10) ){
        printf("+ Diem hoi dong (3 diem): "); scanf("%f%f%f", &SV.hoiDong[0], &SV.hoiDong[1], &SV.hoiDong[2]);
    }
    
    //Kiem tra diem
    if( ktDiem(SV.huongDan)==true && ktDiem(SV.phanBien)==true && ktDiem(SV.hoiDong[0])==true && ktDiem(SV.hoiDong[1])==true && ktDiem(SV.hoiDong[2])==true ){
        SV.GK= (SV.huongDan+SV.phanBien)/2;
        SV.CK= (SV.hoiDong[0]+SV.hoiDong[1]+SV.hoiDong[2])/3;
    }else{
        SV.CK=0; SV.GK=0;
    }
}
void nhapN(int N, SinhVien SV[]){
    int i;
    for(i=n;i<n+N;i++){
        nhap(SV[i],i);
    }
    n+=N;
}
void xuat(SinhVien &SV){
    printf("\n %-5d  %-30s%-4.1f %-4.1f %-4.1f %-4.1f %-5.1f %-4.1f %-4.1f", SV.MSSV, SV.Name, SV.huongDan, SV.phanBien, SV.hoiDong[0], SV.hoiDong[1], SV.hoiDong[2], SV.GK, SV.CK);
}
void xuatN(SinhVien SV[]){
    system("cls");
    printf("\n-----------------DANH SACH SINH VIEN-------------------\n");
    printf("\n MSSV   Ho va Ten                     HD   PB   HD1  HD2  HD3   GK   CK");
    int i,j;
    for(i=0;i<n;i++){
        xuat(SV[i]);
    }
}
void sapXep(SinhVien SV[]){
    system("cls");
    printf("\n-----------------DANH SACH SINH VIEN-------------------\n");
    printf("\n MSSV   Ho va Ten                     HD   PB   HD1  HD2  HD3   GK   CK"); 
    int sum=n;
    while(sum!=0){
        int i,j,k;
        for(i=65;i<90;i++){
            for(j=0;j<n;j++){
                for(k=strlen(SV[j].Name);;k--){     //chu cai trong ten
                    if(SV[j].Name[k-1]==32 && SV[j].Name[k]==i){
                        xuat(SV[j]);
                        sum--;
                        break;
                    } else{
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    int choice,i,j,N;
    while (choice!=4)
    {
    begin: showMenu();
        fflush(stdin); scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
        soSV: printf(" So sinh vien muon them: "); scanf("%d",&N);
            if(N<=0){
                printf("Vui long nhap chinh xac so sinh vien !");
                goto soSV;
            }
            (SinhVien*)malloc((N)*sizeof(SinhVien));
            nhapN(N,sv);
            xuatN(sv);
            printf("\n >> Nhan Enter de tiep tuc!.....");
            fflush(stdin); getchar();
            break;
        }
        case 2:{    //Danh sach sv bao ve thanh cong
            system("cls");
            printf("\n-----------------DANH SACH SINH VIEN-------------------\n");
            printf("\n MSSV   Ho va Ten                     HD   PB   HD1  HD2  HD3   GK   CK");
            int i,j;
            for(i=0;i<n;i++){
                if(sv[i].GK!=0 && sv[i].CK!=0){
                    xuat(sv[i]);
                }
            }
            printf("\n >> Nhan Enter de tiep tuc!.....");
            fflush(stdin); getchar();
            break;
        }
        case 3:{    //Sap xep theo ten
            sapXep(sv);
            printf("\n >> Nhan Enter de tiep tuc!.....");
            fflush(stdin); getchar();
            break;
        }
        case 4:{
            break;
        }
        default:{
            printf("Vui long chon lai!..."); Sleep(1000);
            goto begin;
        }   
        }
    }
    
    return 0;
}