#include"reg52.h"
#define uchar unsigned char
#define uint unsigned int	
sbit led1_1=P0^0;//���pwm
sbit led1_2=P0^1;//���pwm
sbit led1_3=P0^2;//���pwm
sbit led1_4=P0^3;//���pwm
sbit led1_5=P0^4;//���pwm
sbit led1_6=P0^5;//���pwm
sbit led1_7=P0^6;//���pwm
sbit led1_8=P0^7;//���pwm

sbit led2_1=P2^7;//���pwm
sbit led2_2=P2^6;//���pwm
sbit led2_3=P2^5;//���pwm
sbit led2_4=P2^4;//���pwm
sbit led2_5=P2^3;//���pwm
sbit led2_6=P2^2;//���pwm
sbit led2_7=P2^1;//���pwm
sbit led2_8=P2^0;//���pwm

#define PWM_TIME 10//pwm���ڣ�һ������1ms
#define PWM_VALUE_MAX 10//pwmռ�ձ����ޣ�100%
#define PWM_VALUE_MIN 3//pwmռ�ձ����ޣ�30%
uint pwm_value[8]=0;//ռ�ձ�1:��100->30->100
uint pwm2_value[8]=0;//ռ�ձ�2:��100->30->100
uint pwm_count=0;//pwm���������һ������10�ݡ���һ��100us
uint pwm_flag=0;//ռ�ձȷ���0��ռ�ձȼ�С��1��ռ�ձ����ӡ�
uint pwm2_flag=0;//ռ�ձȷ���0��ռ�ձȼ�С��1��ռ�ձ����ӡ�
uint huxi_count=0;//ռ�ձȸ���ʱ��

void timer0_init()
{
  TMOD = 0x01;//ѡ������ʽ1��16λ��ʱ��

  TH0 = 0x0FF;
  TL0 = 0x9C;//��ʱ100us
/*
	TH0=-100/256;
	TL0=-100%256;
*/
  ET0=1;//����ʱ��T0
	EA=1;//�����ж�
	TR0=1;//��16λ��ʱ��
}
void pwm_init()
{
	//led1
	pwm_value[0]=10;//ռ�ձȳ�ʼ��Ϊ100%
	pwm_value[1]=9;
	pwm_value[2]=8;
	pwm_value[3]=7;
	pwm_value[4]=6;
	pwm_value[5]=5;
	pwm_value[6]=4;
	pwm_value[7]=3;
	//led2
	pwm2_value[0]=3;//ռ�ձȳ�ʼ��Ϊ100%
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
	timer0_init();//��ʱ��0��ʼ��
	pwm_init();//pwm��ʼ��
	led1_1=1;
	while(1);
	return 0;
}
void time0() interrupt 1//��ʱ��0�жϺ���
{
	uint count=0;//ָʾled��

  TH0 = 0x0FF;
  TL0 = 0x9C;//��ʱ100us

		pwm_count++;
	
	//led2_1
		if(pwm_count<=pwm2_value[0])//����ߵ�ƽ
		{
			led2_1 = 1;
		}
		if(pwm_count>pwm2_value[0])//����͵�ƽ
		{
			led2_1 = 0;
		}
	//led2_2
		if(pwm_count<=pwm2_value[1])//����ߵ�ƽ
		{
			led2_2 = 1;
		}
		if(pwm_count>pwm2_value[1])//����͵�ƽ
		{
			led2_2 = 0;
		}
		//led2_3
		if(pwm_count<=pwm2_value[2])//����ߵ�ƽ
		{
			led2_3 = 1;
		}
		if(pwm_count>pwm2_value[2])//����͵�ƽ
		{
			led2_3 = 0;
		}
		//led2_4
		if(pwm_count<=pwm2_value[3])//����ߵ�ƽ
		{
			led2_4 = 1;
		}
		if(pwm_count>pwm2_value[3])//����͵�ƽ
		{
			led2_4 = 0;
		}
		//led2_5
		if(pwm_count<=pwm2_value[4])//����ߵ�ƽ
		{
			led2_5 = 1;
		}
		if(pwm_count>pwm2_value[4])//����͵�ƽ
		{
			led2_5 = 0;
		}
		//led2_6
		if(pwm_count<=pwm2_value[5])//����ߵ�ƽ
		{
			led2_6 = 1;
		}
		if(pwm_count>pwm2_value[5])//����͵�ƽ
		{
			led2_6 = 0;
		}
		//led2_7
		if(pwm_count<=pwm2_value[6])//����ߵ�ƽ
		{
			led2_7 = 1;
		}
		if(pwm_count>pwm2_value[6])//����͵�ƽ
		{
			led2_7 = 0;
		}
		//led2_8
		if(pwm_count<=pwm2_value[7])//����ߵ�ƽ
		{
			led2_8 = 1;
		}
		if(pwm_count>pwm2_value[7])//����͵�ƽ
		{
			led2_8 = 0;
		}
		//led1_1
		if(pwm_count<=pwm_value[0])//����ߵ�ƽ
		{
			led1_1 = 1;
		}
		if(pwm_count>pwm_value[0])//����͵�ƽ
		{
			led1_1 = 0;
		}
		
	  //led1_2
		if(pwm_count<=pwm_value[1])//����ߵ�ƽ
		{
			led1_2 = 1;
		}
		if(pwm_count>pwm_value[1])//����͵�ƽ
		{
			led1_2 = 0;
		}
		//led1_3
		if(pwm_count<=pwm_value[2])//����ߵ�ƽ
		{
			led1_3 = 1;
		}
		if(pwm_count>pwm_value[2])//����͵�ƽ
		{
			led1_3 = 0;
		}
		//led1_4
		if(pwm_count<=pwm_value[3])//����ߵ�ƽ
		{
			led1_4 = 1;
		}
		if(pwm_count>pwm_value[3])//����͵�ƽ
		{
			led1_4 = 0;
		}
		//led1_5
		if(pwm_count<=pwm_value[4])//����ߵ�ƽ
		{
			led1_5 = 1;
		}
		if(pwm_count>pwm_value[4])//����͵�ƽ
		{
			led1_5 = 0;
		}
		//led1_6
		if(pwm_count<=pwm_value[5])//����ߵ�ƽ
		{
			led1_6 = 1;
		}
		if(pwm_count>pwm_value[5])//����͵�ƽ
		{
			led1_6 = 0;
		}
		//led1_7
		if(pwm_count<=pwm_value[6])//����ߵ�ƽ
		{
			led1_7 = 1;
		}
		if(pwm_count>pwm_value[6])//����͵�ƽ
		{
			led1_7 = 0;
		}
		//led1_8
		if(pwm_count<=pwm_value[7])//����ߵ�ƽ
		{
			led1_8 = 1;
		}
		if(pwm_count>pwm_value[7])//����͵�ƽ
		{
			led1_8 = 0;
		}
		
		if(pwm_count==PWM_TIME)//����һ������
		{
			pwm_count=0;//����
			huxi_count++;//������+1
		}
		
		if((huxi_count==10))//���10�����ڵķ���
		{
				huxi_count=0;//����
				//led1
				if(pwm_value[7]==PWM_VALUE_MAX)//ռ�ձȱ�ֵ�ﵽ��С
					{
						pwm_flag=1;//1�����ߣ�2������
					}
				if(pwm_value[0]==PWM_VALUE_MAX)//ռ�ձȱ�ֵ�ﵽ���
					{
						pwm_flag=0;//1������,2:����
					}
					
				if(pwm_flag==0)
				{
					//led1����
					for(count=7;count>0;count--)
					{
						pwm_value[count]=pwm_value[count-1];
					}
					pwm_value[0]--;
					//led2����
					for(count=0;count<7;count++)
					{
						pwm2_value[count]=pwm2_value[count+1];
					}
					pwm2_value[7]--;
					
				}
					
				if(pwm_flag==1)
				{
					//led1����
					for(count=0;count<7;count++)
					{
						pwm_value[count]=pwm_value[count+1];
					}
					pwm_value[7]--;
					//led2����
					for(count=7;count>0;count--)
					{
						pwm2_value[count]=pwm2_value[count-1];
					}
					pwm2_value[0]--;
				}
				
		}
			
}
