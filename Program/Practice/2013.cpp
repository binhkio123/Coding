#include<stdio.h>
#include<string.h>
#include<windows.h>

char S[40];

struct Gamer
{
    char Name[25];
    int Old;
    int Score[5];
    int Sum;
};
struct Gamer Person[4];

void ShowMenu(){
    system("cls");
    printf("\n---------Tro choi lat o chu---------");
    printf("\n  1. Khoi dong tro choi");
    printf("\n  2. Choi doan ky tu");
    printf("\n  3. Tong hop ket qua");
    printf("\n  4. Thoat chuong trinh");
    printf("\n  >> ");
}
void nhap(Gamer &player);
void xuat(Gamer player);
void play(int length, Gamer &player);
void score(Gamer &player);
void sapXep(Gamer player[], int M);

int main(){
    int M,i,choice;
    while (choice != 4)
    {
        begin: ShowMenu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{    //Khoi dong
            nhapS: printf("\nNhap xau ky tu S: ");
            fflush(stdin); gets(S);
            if(strlen(S)<20||strlen(S)>40){
                printf("Vui long chi nhap 20-40 ky tu !");
                goto nhapS;
            }
            nhapM: printf("\nNhap so nguoi choi: "); scanf("%d",&M);
            if(M<1||M>4){
                printf("Tro choi chi cho phep 1-4 nguoi choi !");
                goto nhapM;
            }
            for(i=0;i<M;i++){
                printf("\nNguoi choi thu %d:",i+1);
                nhap(Person[i]);
            }
            printf("\n-----Danh sach nguoi choi-----");
            printf("\n   Ho va ten              Tuoi");
            for(i=0;i<M;i++){
                xuat(Person[i]);
            }
            printf("\nNhan phim Enter de tiep tuc ! "); fflush(stdin);
            getchar();
            break;
        }
        case 2:{    //Choi game
            int lengthS=strlen(S);
            for(i=0;i<M;i++){
                system("cls");
                printf("\n----Nguoi choi thu %d----\n",i+1);
                play(lengthS, Person[i]);
            }
            system("cls");
            printf("----Diem cua nguoi choi----");
            printf("\n   Ho va ten              L1   L2   L3   L4   KQ");
            for(i=0;i<M;i++){
                score(Person[i]);
            }
            printf("\n> Nhan phim Enter de tiep tuc ! "); fflush(stdin);
            getchar();
            break;
        }
        case 3:{    //Sap xep
            system("cls");
            printf("----Diem cua nguoi choi----");
            sapXep(Person,M);
            printf("\nHang   Ho va ten              KQ");
            for(i=0;i<M;i++){
                printf("\n %-4d%-25s%-5d",i+1,Person[i].Name, Person[i].Sum);
            }
            printf("\n> Nhan phim Enter de tiep tuc ! "); fflush(stdin);
            getchar();
            break;
        }
        case 4:
            break;
        default:
            goto begin;
        }
    }
    
    return 0;
}

void nhap(Gamer &player){
    printf("\nTen nguoi choi: ");
    fflush(stdin); gets(player.Name);
    nhapTuoi: printf("Tuoi: "); scanf("%d",&player.Old);
    if(player.Old<1 || player.Old>100){
        printf("Vui long nhap chinh xac tuoi !\n"); goto nhapTuoi;
    }
}
void xuat(Gamer player){
    printf("\n%-25s %d", player.Name, player.Old);
}
void play(int length, Gamer &player){
    int i,j;
    char c[5];
    char S1[length];
    for(i=0;i<length;i++){S1[i]='*';}
    for(i=0;i<4;i++){
        player.Score[i]=0;
        printf("\nChuoi ky tu: '%s'",S1);
        chonkt: printf("\n>>Ky tu ban doan la: "); 
        fflush(stdin); c[i]=getchar();
        for(j=0;j<i;j++){
            if(c[i]==c[j]){
                printf("Vui long chon ky tu khac !");
                goto chonkt;
            }
        }
        for(j=0;j<length;j++){
            if(S[j]==c[i]){
                S1[j]=S[j];
                player.Score[i]++;
            }
        }
    }
    printf("\nChuoi ky tu: '%s'",S1);
    printf("\n>>Doan ca chuoi ky tu: "); 
    fflush(stdin); gets(S1);
    if(strcmp(S,S1)==0){
        printf("!! Chuc mung ban da doan chinh xac !!\n");
        player.Score[4]+=20;
    } else{
        printf("Ban da doan sai !\n");
        player.Score[4]=0;
    }
}
void score(Gamer &player){
    player.Sum = player.Score[0]+player.Score[1]+player.Score[2]+player.Score[3]+player.Score[4];
    printf("\n%-25s %-5d%-5d%-5d%-5d%-5d", player.Name, player.Score[0]
    , player.Score[1], player.Score[2], player.Score[3], player.Sum);
}
void sapXep(Gamer player[], int M){
    Gamer tmp;
    int i,j;
    for(i=0;i<M;i++){
        for(j=i+1;j<M;j++){
            if(player[i].Sum < player[j].Sum){
                tmp = player[i];
                player[i] = player[j];
                player[j] = tmp;
            }
        }
    }
}