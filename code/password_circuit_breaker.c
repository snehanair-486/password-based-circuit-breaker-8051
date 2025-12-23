#include <reg51.h>
#include <string.h>

sbit RS = P3^0;
sbit EN = P3^1;
sbit IN1 = P3^2;
sbit IN2 = P3^3;

void delay(int a)
{
    int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<255;j++);
}

void cmd(char cm)
{
    P2 = cm;
    RS = 0;
    EN = 1;
    delay(1);
    EN = 0;
}

void dat(char dt)
{
    P2 = dt;
    RS = 1;
    EN = 1;
    delay(1);
    EN = 0;
}

void display(char *lcd)
{
    while(*lcd)
    {
        dat(*lcd++);
    }
}

void lcdint()
{
    cmd(0x38);
    cmd(0x0E);
    cmd(0x01);
    cmd(0x80);
}

void main()
{
    char pass[5] = "1234";
    char pass2[5];
    int i = 0;
    char *ptr = pass2;

    lcdint();
    display("Password-");
    pass2[4] = '\0';

    while(1)
    {
        while(i < 4)
        {
            P1 = 0xFE;
            if(P1 == 0xEE){ ptr[i++]='1'; dat('*'); while(P1!=0xFE); delay(50); }
            else if(P1 == 0xDE){ ptr[i++]='2'; dat('*'); while(P1!=0xFE); delay(50); }
            else if(P1 == 0xBE){ ptr[i++]='3'; dat('*'); while(P1!=0xFE); delay(50); }
            else if(P1 == 0x7E){ ptr[i++]='A'; dat('*'); while(P1!=0xFE); delay(50); }

            P1 = 0xFD;
            if(P1 == 0xED){ ptr[i++]='4'; dat('*'); while(P1!=0xFD); delay(50); }
            else if(P1 == 0xDD){ ptr[i++]='5'; dat('*'); while(P1!=0xFD); delay(50); }
            else if(P1 == 0xBD){ ptr[i++]='6'; dat('*'); while(P1!=0xFD); delay(50); }
            else if(P1 == 0x7D){ ptr[i++]='B'; dat('*'); while(P1!=0xFD); delay(50); }

            P1 = 0xFB;
            if(P1 == 0xEB){ ptr[i++]='7'; dat('*'); while(P1!=0xFB); delay(50); }
            else if(P1 == 0xDB){ ptr[i++]='8'; dat('*'); while(P1!=0xFB); delay(50); }
            else if(P1 == 0xBB){ ptr[i++]='9'; dat('*'); while(P1!=0xFB); delay(50); }
            else if(P1 == 0x7B){ ptr[i++]='C'; dat('*'); while(P1!=0xFB); delay(50); }

            P1 = 0xF7;
            if(P1 == 0xE7){ ptr[i++]='*'; dat('*'); while(P1!=0xF7); delay(50); }
            else if(P1 == 0xD7){ ptr[i++]='0'; dat('*'); while(P1!=0xF7); delay(50); }
            else if(P1 == 0xB7){ ptr[i++]='#'; dat('*'); while(P1!=0xF7); delay(50); }
            else if(P1 == 0x77){ ptr[i++]='D'; dat('*'); while(P1!=0xF7); delay(50); }
        }

        if(i == 4)
        {
            cmd(0xC0);
            if(strcmp(pass, pass2) == 0)
            {
                display("Correct");
                IN1 = 1;
                IN2 = 0;
            }
            else
            {
                display("Incorrect");
                IN1 = 0;
                IN2 = 0;
            }

            delay(300);
            i = 0;
            cmd(0x01);
            cmd(0x80);
            display("Password-");
        }
    }
}
