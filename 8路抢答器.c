#include<reg51.h>
#include<intrins.h>
//--------------------定义全局变量，进行引脚绑定----------------------------------------

sbit keyks=P3^5;	//开始键
sbit keytz=P3^7;	//停止键
sbit keyfw=P3^6;	//复位键

sbit key1=P1^1;		//1号选手		 
sbit key2=P1^2;		
sbit key3=P1^6;		
sbit key4=P3^1;		
sbit key5=P1^0;		
sbit key6=P1^3;		
sbit key7=P1^7;		
sbit key8=P3^2;		//8号选手

sbit smg_1=P2^4;		//数码管第1位
sbit smg_2=P2^5;		//数码管第2位
sbit smg_3=P2^6;		//数码管第3位
sbit smg_4=P2^7;   //数码管第4位

sbit spk=P1^0;// 蜂鸣器

int djs=60;
int count=0;		   
unsigned char flag=0;
int ret=-1;//函数返回值
int table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};// 0~9

//--------------------函数定义----------------------------------------

void delayms(int xms)	   //延时函数
{
    int x,y;
    for(x=xms;x>0;x--)
        for(y=110;y>0;y--);
}
void Timer0_init()			//定时器0初始化
{
    count=0;
    TMOD=0x01;	  			//T0为定时器方式1
    TH0=60;
    TL0=176;			
    //TR0=1;//IT1=1;
    ET0=1;//EX1=1;
    EA=1;	
}
void Timer0_interupt() interrupt 1 using 1	//定时器0中断服务函数
{
    TF0=0;
    TH0=60;
    TL0=176;					//赋初值
    count++;
    if(flag==1)
    {
        if(count<8)
            spk=0;
        else spk=1;
    }
    if(count==20) 
    { count=0;
        djs--;					//产生1s的倒计时
    }
}
void time_display()				   //显示倒计时函数
{
    int fisrst,second;
    fisrst=djs/10;
    second=djs%10;	
    //显示十位
    P0=table[fisrst];
    smg_3=0;
    delayms(3);
    smg_3=1;					
    //显示个位
    P0=table[second];
    smg_4=0;
    delayms(3);				
    smg_4=1;
}
void mid_display() //第二位数码管显示-
{
    P0=0x49;			//第二位数码管
    smg_4=0;
    delayms(3);
    smg_4=1;
}
void init_display()				 
{	
    //第一位数码管显示0
    P0=0x3f;
    smg_1=0;
    delayms(3);
    smg_1=1;
    //第二位数码管0		
    P0=0x3f;			
    smg_2=0;
    delayms(3);
    smg_2=1;
    //第三位数码管显示0
    P0=0x3f;
    smg_3=0;
    delayms(3);			   
    smg_3=1;
    //第四位数码管显示0
    P0=0x3f;
    smg_4=0;
    delayms(3);
    smg_4=1;				 
}
void display_num_player(int num)
{
    P0=table[num];
    smg_1=0;
    delayms(3);
    smg_1=1;		
}
int  player_action(int num)
{
    while(1)
    {
        TR0=0;		  //定时器停止
        display_num_player(num);//显示选手编号
        mid_display();	  //第二位数码管显示
        time_display();	  //显示剩余时间
        if(keyfw==0)
        {	
            delayms(5);		   //去除抖动
            if(keyfw==0)
            { 
                while(!keyfw)
                    ; 

                return 0;		  //goto语句，回到AGAIN
            }
        }			
    }
    return -1;
}
void main()
{
    Timer0_init();	 //初始化定时器中断
    spk=1;			  //蜂鸣器不响
    djs=60;		//倒计时赋值
    while(1)
    {

AGAIN:   djs=60;
         init_display();	//显示0000
/***************************开始，停止，复位*************************/
         if(keyks==0)
         {		   
             delayms(2);		 
             if(keyks==0)
             { 
                 while(keyks==0)
                     ;	   
                 TR0=1;	 //启动定时器
                 while(1)
                 {
                     time_display();
                     //倒计时过程中按下停止
                     if(keytz==0) 
                     {
                         delayms(5);				
                         if(keytz==0)
                         { 
                             while(!keytz);	   
                             {
                                 TR0=0; //定时器停止
                                 flag=0;
                                 spk=1;
                             }

                         }
                     }
                     //倒计时过程中按下停止，在按开始
                     if(keyks==0)
                     {
                         delayms(5);	
                         if(keyks==0)
                         { 
                             while(!keyks);	   //以上表示按下清楚按键后 
                             TR0=1;		   //定时器启动

                         }
                     }
/***************************抢答阶段***********************************/

                     if((key1==0)&&(TR0==1))		 //在定时器运行状态下，1号选手抢答
                     {		
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key1==0)
                         { 
                             while(!key1);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(1);  
                             if(ret==0)
                                 goto AGAIN;
                         }
                     }
                     if((key2==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key2==0)
                         { 
                             while(!key2);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(2);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key3==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key3==0)
                         { 
                             while(!key3);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(3);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key4==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key4==0)
                         { 
                             while(!key4);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(4);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key5==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key5==0)
                         { 
                             while(!key5);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(5);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key6==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key6==0)
                         { 
                             while(!key6);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(6);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key7==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key7==0)
                         { 
                             while(!key7);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(7);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }
                     if((key8==0)&&(TR0==1))
                     {	
                         spk=0;	 //蜂鸣器响
                         delayms(2);
                         if(key8==0)
                         { 
                             while(!key8);	  //重新在判断，是否按下
                             {
                                 spk=1;		  //蜂鸣器不响
                                 flag=0;//清0最后五秒响蜂鸣器
                             }
                             ret=player_action(8);  
                             if(ret==0)
                                 goto AGAIN;
                         }						   
                     }

                     if(djs<=5)  
                         flag=1; //spk=0; 到倒计时小于5，蜂鸣器响
                     if(djs==0)	
                     {
                         flag=0;
                         spk=1;
                         while(1)
                         {
                             if(keyfw==0)
                             {	
                                 delayms(2);
                                 if(keyfw==0)
                                 { 
                                     while(!keyfw);
                                     spk=1;		  
                                     goto AGAIN;	
                                 }
                             }
                         }
                     } 

                 }

             }
         }
    }
}

