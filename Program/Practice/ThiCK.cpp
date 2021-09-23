#include<stdio.h>
#include<string.h>
#include<windows.h>

struct Olympic
{
    int ID;
    char Nation[4];
    char Name[30];
    float R[3]; //so thuc >0 <20 va =0 neu pham quy
    float FR;
};
Olympic VDV[1];

void showMenu(){
    system("cls");
    printf("\n-----------CHUONG TRINH OLYMPIC MON NHAY XA-----------");
    printf("\n 1. Nhap thong tin truoc thi dau");
    printf("\n 2. In thong tin");
    printf("\n 3. Thi dau");
    printf("\n 4. Tim kiem");
    printf("\n 5. In ket qua");
    printf("\n 6. Ket thuc");
    printf("\n>> ");
}
void nhap(Olympic &p, int n){
    p.ID = n+1;int i,j;
    printf("\n< Van dong vien thu %d >\n", p.ID);
    printf("Nhap quoc gia cua van dong vien: ");
    fflush(stdin); fgets(p.Nation,4,stdin);
    for(i=0;i<3;i++){
        if(p.Nation[i]>96){
            p.Nation[i]-=32;
        }
    }
    
    printf("Nhap ten van dong vien: ");
    fflush(stdin); gets(p.Name);
    // kiemTraTenp----------
    int X=strlen(p.Name);
    while(p.Name[0]==32){       //loai bo khoang trang dau ten
        for(i=0;i<X-1;i++){
            p.Name[i]=p.Name[i+1];
        }
        X--;
    }
    if(p.Name[0]>90){     //viet hoa dau dong
        p.Name[0]-=32;
    }
    i=0;
    while(i!=X-1){       //loai bo DoubleSpace
        if(p.Name[i]==32 && p.Name[i+1]==32){
            for(j=i;j<X-1;j++){
                p.Name[j]=p.Name[j+1];
            }
            X--;
        } else{i++;}
    }
    for(i=X-1;i>0;i--){      //loai bo khoang trang cuoi ten
        if(p.Name[i]==32){
            p.Name[i]=p.Name[i+1];
        }else{break;}
    }
    for(i=1;i<X;i++){       //viet hoa ten
        if(p.Name[i]!=32 && p.Name[i-1]==32){
            if(p.Name[i]>90){
                p.Name[i]-=32;
            }
        }
    }
    //-----------------------
    printf("----------------------------------");
}
void nhapN(Olympic p[], int N){
    system("cls");
    printf("\n-----NHAP THONG TIN VAN DONG VIEN-----\n");
    int i;
    for(i=0;i<N;i++){
        nhap(p[i],i);
    }
}

void xuatN(int N){
    system("cls");
    printf("\n-----THONG TIN VAN DONG VIEN-----");      
    printf("\n ID Nation  Name                          R1    R2    R3    FR");
    int i;
    for(i=0;i<N;i++){
        printf("\n %-3d%-8s%-30s%-6.2f%-6.2f%-6.2f%-6.2f",VDV[i].ID,VDV[i].Nation,VDV[i].Name,VDV[i].R[0],VDV[i].R[1],VDV[i].R[2],VDV[i].FR);
    }
}
void sapXep(int N){
    int i,j;
    float fr[N];
    for(i=0;i<N;i++){
        for(j=0;j<3;j++){
            if(fr[i]<VDV[i].R[j]){
                fr[i]=VDV[i].R[j];
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(fr[i]<fr[j]){
                float t=fr[i]; fr[i]=fr[j]; fr[j]=t;
                Olympic T=VDV[i]; VDV[i]=VDV[j]; VDV[j]=T;
            }
        }
    }
}
void search_name(int N){
    printf("\nNhap ten can tim:");
    char name_input[3];
    fflush(stdin); gets(name_input);
    for (int i = 0; i < N; i++)
    {
        if (strstr(VDV[i].Name, name_input) != NULL)
        {
            printf("\n-----THONG TIN VAN DONG VIEN-----");
            printf("\n ID Nation  Name                          R1    R2    R3    FR");
            printf("\n %-3d%-8s%-30s%-6.2f%-6.2f%-6.2f%-6.2f",VDV[i].ID,VDV[i].Nation,VDV[i].Name,VDV[i].R[0],VDV[i].R[1],VDV[i].R[2],VDV[i].FR);
        }
    }
}
void tinhfr(int N){
    int i,j;
    for(i=0;i<N;i++){
        VDV[i].FR=0;
        for(j=0;j<3;j++){
            if(VDV[i].FR<VDV[i].R[j]){
                VDV[i].FR=VDV[i].R[j];
            }
        }
    }
}

int main(){
    bool cn1=false,cn3=false,cn4=true;
    int N,i,choice;
    while(choice!=6){
    begin: showMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            if(cn1==true){
                printf("Vui long nhap lai");
                break;}
            sl: printf("Nhap so luong van dong vien (1~20): ");
            scanf("%d",&N);
            if(N<1||N>20){
                printf("Vui long nhap lai!\n");
                fflush(stdin); goto sl;
            }
            (Olympic*)malloc(N*sizeof(Olympic));
            nhapN(VDV,N);
            cn1=true;
            printf("\nNhan Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 2:{
            xuatN(N);
            printf("\nNhan Enter de tiep tuc...");
            fflush(stdin); getchar();
            break;
        }
        case 3:{
            if(cn3==true){
                printf("Vui long nhap lai");
                break;}
            int i,j;
            for(i=0;i<3;i++){
                system("cls");
                printf("---KET QUA THI DAU LAN %d---\n", i+1);
                for(j=0;j<N;j++){
                    kq: printf("Ket qua thi cua van dong vien thu %d: ",j+1);
                    scanf("%f",&VDV[j].R[i]);
                    if(VDV[j].R[i]<0||VDV[j].R[i]>20){
                        printf("Vui long nhap lai!\n");
                        fflush(stdin); goto kq;
                    }
                    
                }
                xuatN(N);
                printf("\nNhan Enter de tiep tuc...");
                fflush(stdin); getchar();
                
            }
            tinhfr(N);
            cn3=true;
            cn4=false;
            
            break;
        }
        case 4:{
            if(cn4==true){
                printf("Vui long nhap lai");
                break;}
            system("cls");
            int x;
            printf("----TIM KIEM VAN DONG VIEN----");
            while(x!=1 && x!=2){
                printf("\n 1. Tim kiem theo ten quoc gia");
                printf("\n 2. Tim kiem theo ten");
                printf("\n>> "); scanf("%d",&x);
            }
            switch (x)
            {
            case 1:{
                x=0;
                char arr[4];
                printf("Nhap ten quoc gia: ");
                fflush(stdin); fgets(arr,4,stdin);
                printf("\nDanh sach:");
                int i;
                printf("\n ID Nation  Name                          R1    R2    R3    FR");
                for(i=0;i<N;i++){
                    if(strcmp(arr,VDV[i].Nation)==0){
                        printf("\n %-3d%-8s%-30s%-6.2f%-6.2f%-6.2f%-6.2f",VDV[i].ID,VDV[i].Nation,VDV[i].Name,VDV[i].R[0],VDV[i].R[1],VDV[i].R[2],VDV[i].FR);
                    }
                }
                printf("\nNhan Enter de tiep tuc...");
                fflush(stdin); getchar();
                break;
            }
            case 2:{
                x=0;
                search_name(N);
                printf("\nNhan Enter de tiep tuc...");
                fflush(stdin); getchar();
                break;
            }  
            }
        }
        case 5:{
            if(cn4==true){
                printf("Vui long nhap lai");
                break;}
            sapXep(N);
            xuatN(N);
            printf("\nNhan Enter de tiep tuc...");
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