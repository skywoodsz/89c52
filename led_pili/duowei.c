#include"reg52.h"
#define uchar unsigned char
#define uint unsigned int	
sbit led1_1=P0^0;//输出pwm
sbit led1_2=P0^1;//输出pwm
sbit led1_3=P0^2;//输出pwm
sbit led1_4=P0^3;//输出pwm
sbit led1_5=P0^4;//输出pwm
sbit led1_6=P0^5;//输出pwm
sbit led1_7=P0^6;//输出pwm
sbit led1_8=P0^7;//输出pwm

sbit led2_1=P2^7;//输出pwm
sbit led2_2=P2^6;//输出pwm
sbit led2_3=P2^5;//输出pwm
sbit led2_4=P2^4;//输出pwm
sbit led2_5=P2^3;//输出pwm
sbit led2_6=P2^2;//输出pwm
sbit led2_7=P2^1;//输出pwm
sbit led2_8=P2^0;//输出pwm

#define PWM_TIME 10//pwm周期，一个周期1ms
#define PWM_VALUE_MAX 10//pwm占空比上限：100%
#define PWM_VALUE_MIN 3//pwm占空比下限：30%
uint pwm_value[8]=0;//占空比1:从100->30->100
uint pwm2_value[8]=0;//占空比2:从100->30->100
uint pwm_count=0;//pwm输出份数；一个周期10份。即一份100us
uint pwm_flag=0;//占空比方向：0：占空比减小，1：占空比增加。
uint pwm2_flag=0;//占空比方向：0：占空比减小，1：占空比增加。
uint huxi_count=0;//占空比更新时间

void timer0_init()
{
  TMOD = 0x01;//选择工作方式1，16位定时器

  TH0 = 0x0FF;
  TL0 = 0x9C;//定时100us
/*
	TH0=-100/256;
	TL0=-100%256;
*/
  ET0=1;//允许定时器T0
	EA=1;//开总中断
	TR0=1;//打开16位定时器
}
void pwm_init()
{
	//led1
	pwm_value[0]=10;//占空比初始化为100%
	pwm_value[1]=9;
	pwm_value[2]=8;
	pwm_value[3]=7;
	pwm_value[4]=6;
	pwm_value[5]=5;
	pwm_value[6]=4;
	pwm_value[7]=3;
	//led2
	pwm2_value[0]=3;//占空比初始化为100%
	pwm2_value[1]=4;
	pwm2_value[2]=5;
	pwm2_value[3]=6;
	pwm2_value[4]=7;
	pwm2_value[5]=8;
	pwm2_value[6]=9;
	pwm2_value[7]=10;

}

int main()
{
	timer0_init();//定时器0初始化
	pwm_init();//pwm初始化
	led1_1=1;
	while(1);
	return 0;
}
void time0() interrupt 1//定时器0中断函数
{
	uint count=0;//指示led灯

  TH0 = 0x0FF;
  TL0 = 0x9C;//定时100us

		pwm_count++;
	
	//led2_1
		if(pwm_count<=pwm2_value[0])//输出高电平
		{
			led2_1 = 1;
		}
		if(pwm_count>pwm2_value[0])//输出低电平
		{
			led2_1 = 0;
		}
	//led2_2
		if(pwm_count<=pwm2_value[1])//输出高电平
		{
			led2_2 = 1;
		}
		if(pwm_count>pwm2_value[1])//输出低电平
		{
			led2_2 = 0;
		}
		//led2_3
		if(pwm_count<=pwm2_value[2])//输出高电平
		{
			led2_3 = 1;
		}
		if(pwm_count>pwm2_value[2])//输出低电平
		{
			led2_3 = 0;
		}
		//led2_4
		if(pwm_count<=pwm2_value[3])//输出高电平
		{
			led2_4 = 1;
		}
		if(pwm_count>pwm2_value[3])//输出低电平
		{
			led2_4 = 0;
		}
		//led2_5
		if(pwm_count<=pwm2_value[4])//输出高电平
		{
			led2_5 = 1;
		}
		if(pwm_count>pwm2_value[4])//输出低电平
		{
			led2_5 = 0;
		}
		//led2_6
		if(pwm_count<=pwm2_value[5])//输出高电平
		{
			led2_6 = 1;
		}
		if(pwm_count>pwm2_value[5])//输出低电平
		{
			led2_6 = 0;
		}
		//led2_7
		if(pwm_count<=pwm2_value[6])//输出高电平
		{
			led2_7 = 1;
		}
		if(pwm_count>pwm2_value[6])//输出低电平
		{
			led2_7 = 0;
		}
		//led2_8
		if(pwm_count<=pwm2_value[7])//输出高电平
		{
			led2_8 = 1;
		}
		if(pwm_count>pwm2_value[7])//输出低电平
		{
			led2_8 = 0;
		}
		//led1_1
		if(pwm_count<=pwm_value[0])//输出高电平
		{
			led1_1 = 1;
		}
		if(pwm_count>pwm_value[0])//输出低电平
		{
			led1_1 = 0;
		}
		
	  //led1_2
		if(pwm_count<=pwm_value[1])//输出高电平
		{
			led1_2 = 1;
		}
		if(pwm_count>pwm_value[1])//输出低电平
		{
			led1_2 = 0;
		}
		//led1_3
		if(pwm_count<=pwm_value[2])//输出高电平
		{
			led1_3 = 1;
		}
		if(pwm_count>pwm_value[2])//输出低电平
		{
			led1_3 = 0;
		}
		//led1_4
		if(pwm_count<=pwm_value[3])//输出高电平
		{
			led1_4 = 1;
		}
		if(pwm_count>pwm_value[3])//输出低电平
		{
			led1_4 = 0;
		}
		//led1_5
		if(pwm_count<=pwm_value[4])//输出高电平
		{
			led1_5 = 1;
		}
		if(pwm_count>pwm_value[4])//输出低电平
		{
			led1_5 = 0;
		}
		//led1_6
		if(pwm_count<=pwm_value[5])//输出高电平
		{
			led1_6 = 1;
		}
		if(pwm_count>pwm_value[5])//输出低电平
		{
			led1_6 = 0;
		}
		//led1_7
		if(pwm_count<=pwm_value[6])//输出高电平
		{
			led1_7 = 1;
		}
		if(pwm_count>pwm_value[6])//输出低电平
		{
			led1_7 = 0;
		}
		//led1_8
		if(pwm_count<=pwm_value[7])//输出高电平
		{
			led1_8 = 1;
		}
		if(pwm_count>pwm_value[7])//输出低电平
		{
			led1_8 = 0;
		}
		
		if(pwm_count==PWM_TIME)//到达一个周期
		{
			pwm_count=0;//置零
			huxi_count++;//周期数+1
		}
		
		if((huxi_count==10))//输出10个周期的方波
		{
				huxi_count=0;//置零
				//led1
				if(pwm_value[7]==PWM_VALUE_MAX)//占空比比值达到最小
					{
						pwm_flag=1;//1：上走，2：下走
					}
				if(pwm_value[0]==PWM_VALUE_MAX)//占空比比值达到最大
					{
						pwm_flag=0;//1：下走,2:上走
					}
					
				if(pwm_flag==0)
				{
					//led1下走
					for(count=7;count>0;count--)
					{
						pwm_value[count]=pwm_value[count-1];
					}
					pwm_value[0]--;
					//led2上走
					for(count=0;count<7;count++)
					{
						pwm2_value[count]=pwm2_value[count+1];
					}
					pwm2_value[7]--;
					
				}
					
				if(pwm_flag==1)
				{
					//led1上走
					for(count=0;count<7;count++)
					{
						pwm_value[count]=pwm_value[count+1];
					}
					pwm_value[7]--;
					//led2下走
					for(count=7;count>0;count--)
					{
						pwm2_value[count]=pwm2_value[count-1];
					}
					pwm2_value[0]--;
				}
				
		}
			
}
