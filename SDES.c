#include <stdio.h>
#include <stdlib.h>
void leftRotatebyOne(int arr[], int n);
int concat(int x, int y);
int convertirBinarioDecimal(long b);
void binario(int num);
void setaux2(int n);
void setaux1(int n);
void XOR2(int arrl[],int arrp4[]);
void permutacion10(int arrp10[], int key1 []);
void permutacion8(int arrp10[],int key1 [] );
int p[]={1,0,1,0,0,1,0,1},p1[8],k[]={0,0,1,0,0,1,0,1,1,1},arregloP10 [10],k1 [8],l[4],r[4],ep[8],xor[8],s0_box[4][4],s1_box[4][4],aux1[2],aux2[2],arrp4[4],p4[4],xor2[4],f1[8],f2[8],sw[8],k2[8],c[8],i,gl[5],gr[5],aux3[10];

int main(void){
setSboxes();
printf("plaintext:\n");
for(i=0;i<8;i++)
printf("%d ",p[i]);
printf("\n");
permutacion10(arregloP10,k);
leftRotate(arregloP10, 1, 10);
permutacion8(arregloP10,k1);
IP(p1,p);
setNibbles(p1);
EP(ep,r);
XOR(ep,k1);
passBits(xor);



P4(arrp4,p4);

F1(xor2,f1);
SW(sw,f1);

permutacion10(arregloP10,k);

leftRotate(arregloP10, 1, 10);

separarllave(gl,gr);

permutacion8(aux3,k2);
setNibbles(sw);
EP(ep,r);

XOR(ep,k2);

passBits(xor);

P4(arrp4,p4);
F1(xor2,f2);
PI(c,f2);
printf("cipher text: ");
printf("\n");
for(i=0;i<8;i++)
printf("%d ",c[i]);

}

void permutacion10(int arrp10[], int key1 []){
arrp10[0]=key1[2];
arrp10[1]=key1[4];
arrp10[2]=key1[1];
arrp10[3]=key1[6];
arrp10[4]=key1[3];
arrp10[5]=key1[9];
arrp10[6]=key1[0];
arrp10[7]=key1[8];
arrp10[8]=key1[7];
arrp10[9]=key1[5];
}

void permutacion8(int arrp10[],int key1 [] ){
key1 [0]=arrp10[5];
key1 [1]=arrp10[2];
key1 [2]=arrp10[6];
key1 [3]=arrp10[3];
key1 [4]=arrp10[7];
key1 [5]=arrp10[4];
key1 [6]=arrp10[9];
key1 [7]=arrp10[8];

}

void leftRotate(int arr[], int d, int n)
{
  int i;
  for (i = 0; i < d; i++)
    leftRotatebyOne(arr, n);
}
 
void leftRotatebyOne(int arr[], int n)
{
  int i, temp;
  temp = arr[0];
  for (i = 0; i < n-1; i++)
     arr[i] = arr[i+1];
  arr[i] = temp;
}

void IP(int arrp1[],int p[]){
arrp1[0]=p[1];
arrp1[1]=p[5];
arrp1[2]=p[2];
arrp1[3]=p[0];
arrp1[4]=p[3];
arrp1[5]=p[7];
arrp1[6]=p[4];
arrp1[7]=p[6];
}

void setNibbles(int arrp1[]){
int i;

for(i=0;i<4;i++)
l[i]=arrp1[i];
for(i=0;i<4;i++)
r[i]=arrp1[i+4];
}

void EP(int arrep[],int nibble[]){
arrep[0]=nibble[3];
arrep[1]=nibble[0];
arrep[2]=nibble[1];
arrep[3]=nibble[2];
arrep[4]=nibble[1];
arrep[5]=nibble[2];
arrep[6]=nibble[3];
arrep[7]=nibble[0];

}

void XOR(int arrep[],int arrkey1[]){
int i;
for(i=0; i<8; ++i)
xor[i] = (int)(arrep[i] ^ arrkey1[i]);

}

void setSboxes(){
s0_box[0][0]=1;
s0_box[0][1]=0;
s0_box[0][2]=3;
s0_box[0][3]=2;

s0_box[1][0]=3;
s0_box[1][1]=2;
s0_box[1][2]=1;
s0_box[1][3]=0;

s0_box[2][0]=0;
s0_box[2][1]=2;
s0_box[2][2]=1;
s0_box[2][3]=3;

s0_box[3][0]=3;
s0_box[3][1]=1;
s0_box[3][2]=3;
s0_box[3][3]=2;

s1_box[0][0]=0;
s1_box[0][1]=1;
s1_box[0][2]=2;
s1_box[0][3]=3;

s1_box[1][0]=2;
s1_box[1][1]=0;
s1_box[1][2]=1;
s1_box[1][3]=3;

s1_box[2][0]=3;
s1_box[2][1]=0;
s1_box[2][2]=1;
s1_box[2][3]=0;

s1_box[3][0]=2;
s1_box[3][1]=1;
s1_box[3][2]=0;
s1_box[3][3]=3;

}

void passBits(int arrxor[]){
int auxi_s0[2], auxj_s0[2],auxi_s1[2],auxj_s1[2],i,j,coor_s0,coor_s1;
long vali,valj;
auxi_s0[0]=arrxor[0];
auxi_s0[1]=arrxor[3];
auxj_s0[0]=arrxor[1];
auxj_s0[1]=arrxor[2];

auxi_s1[0]=arrxor[4];
auxi_s1[1]=arrxor[7];
auxj_s1[0]=arrxor[5];
auxj_s1[1]=arrxor[6];

vali=concat(auxi_s0[0],auxi_s0[1]);

valj=concat(auxj_s0[0],auxj_s0[1]);

i=convertirBinarioDecimal(vali);

j=convertirBinarioDecimal(valj);

coor_s0=s0_box[i][j];

setaux1(coor_s0);

vali=concat(auxi_s1[0],auxi_s1[1]);

valj=concat(auxj_s1[0],auxj_s1[1]);

i=convertirBinarioDecimal(vali);

j=convertirBinarioDecimal(valj);

coor_s1=s1_box[i][j];

setaux2(coor_s1);

}

int convertirBinarioDecimal(long b){
int d;
long p,c;



c=1;
d=0;
	while(b>0)
	{
		p=0;
		p=c*(b%10);
		d+=p;
		c*=2;
		b/=10;
	}


return d;
}

int concat(int x, int y) {
    int temp = y;
    while (y != 0) {
        x *= 10;
        y /= 10;
    }
    return x + temp;
}

void binario(int num)
{
   int aux,i=1;
   
   if(num==0)
      return;

   aux=num%2;
   num=num/2;
   binario(num);
   aux1[i]=aux;
i--;

}
void setaux1(int n){

if(n==0){
aux1[0]=0;
aux1[1]=0;
}

else if(n==1){
aux1[0]=0;
aux1[1]=1;
}

else if(n==2){
aux1[0]=1;
aux1[1]=0;

}
else if(n==3){
aux1[0]=1;
aux1[1]=1;

}

}


void setaux2(int n){

if(n==0){
aux2[0]=0;
aux2[1]=0;
}

else if(n==1){
aux2[0]=0;
aux2[1]=1;
}

else if(n==2){
aux2[0]=1;
aux2[1]=0;

}
else if(n==3){
aux2[0]=1;
aux2[1]=1;

}

}


void P4(int arrp4[],int p4[]){
arrp4[0]=aux1[0];
arrp4[1]=aux1[1];
arrp4[2]=aux2[0];
arrp4[3]=aux2[1];

p4[0]=arrp4[1];
p4[1]=arrp4[3];
p4[2]=arrp4[2];
p4[3]=arrp4[0];
}
void XOR2(int arrl[],int arrp4[]){
int i;
for(i=0; i<4; ++i)
xor2[i] = (int)(arrl[i] ^ arrp4[i]);

}

void F1(int arrxor[],int arrf1[]){
XOR2(l,p4);
arrf1[0]=xor2[0];
arrf1[1]=xor2[1];
arrf1[2]=xor2[2];
arrf1[3]=xor2[3];
arrf1[4]=r[0];
arrf1[5]=r[1];
arrf1[6]=r[2];
arrf1[7]=r[3];

}

SW(int arrsw[],int arrf1[]){

arrsw[0]=arrf1[4];
arrsw[1]=arrf1[5];
arrsw[2]=arrf1[6];
arrsw[3]=arrf1[7];
arrsw[4]=arrf1[0];
arrsw[5]=arrf1[1];
arrsw[6]=arrf1[2];
arrsw[7]=arrf1[3];


}

void PI(int arrc[],int arrf2[]){
arrc[0]=arrf2[3];
arrc[1]=arrf2[0];
arrc[2]=arrf2[2];
arrc[3]=arrf2[4];
arrc[4]=arrf2[6];
arrc[5]=arrf2[1];
arrc[6]=arrf2[7];
arrc[7]=arrf2[5];

}

void separarllave(int gl[],int gr[]){

gl[0]=arregloP10[0];
gl[1]=arregloP10[1];
gl[2]=arregloP10[2];
gl[3]=arregloP10[3];
gl[4]=arregloP10[4];

gr[0]=arregloP10[5];
gr[1]=arregloP10[6];
gr[2]=arregloP10[7];
gr[3]=arregloP10[8];
gr[4]=arregloP10[9];

leftRotate(gl, 2, 5);
leftRotate(gr, 2, 5);
aux3[0]=gl[0];
aux3[1]=gl[1];
aux3[2]=gl[2];
aux3[3]=gl[3];
aux3[4]=gl[4];
aux3[5]=gr[0];
aux3[6]=gr[1];
aux3[7]=gr[2];
aux3[8]=gr[3];
aux3[9]=gr[4];

}


