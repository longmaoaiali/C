

#include <stdio.h>


int main() {

    int num,sum=0;
    int numpow;//������ƽ��
    int sumnumpow=0;
    int count=0;//�������������
    int badnum = 0;
    double EX=0;//��ѧ��������
    double EXnumpow = 0;
    double EXpow = 0;
    double DX=0;

    while(scanf("%d",&num) != EOF){
        count++;
        sum += num;
        numpow = num*num;
        sumnumpow += numpow;//����ƽ���ĺ�

        printf("input is %d\n",num);

        EX = (double) sum/count;
        EXpow = EX*EX;
        EXnumpow = (double) sumnumpow/count;
        DX = EXnumpow-EXpow;
        printf("EX=%f\n",EX);
        printf("DX=%f\n",DX);

        if((num < (EX-(3*DX))) || (num > (EX+(3*DX)))){
            printf("input num %d is not ok\n",num);
            badnum++;
        }
    }

    double result = (double)(count-badnum)/count;
    printf("��Ʒ��=%f\n",result);

    return 0;
}
