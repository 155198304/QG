#include <iostream>
#include <stdio.h>
using namespace std;
int lu = 0;
struct fuhao
{
	char f;
	int x;
}s[7] = { {'+',1},{'-',1},{'*',2},{'/',2},{'(',3},{')',3},{'=',-1} };
void PUSH(double nu, double a[])
{
	int i = 0;
	for (; i < 20; i++)
	{
		if (a[i] == 9999)
			break;
	}
	a[i] = nu;//������ջ
}
void PUSH1(double nu, int b[])
{
	int i = 0;
	for (; i <= 20; i++)
		if (b[i] == 9999)
			break;
	b[i] = nu;
}//����������ջ
double READ(char* p)//�������Ҷ�ȡ
{
	double rate = 10.0, item = 0;
	int x = 0;//��ʾ��ȡ�������ֻ��Ƿ���
	p = p + lu;
	while (*p != '/n')
	{
		if (x == 0)
		{
			if (*p == '+') { lu++; return-7; }//��ʾ��ȡ���ķ���
			else if (*p == '-') { lu++; return -6; }
			else if (*p == '*') { lu++; return -5; }
			else if (*p == '/') { lu++; return -4; }
			else if (*p == '(') { lu++; return -3; }
			else if (*p == ')') { lu++; return -2; }
			else if (*p == '=') { lu++; return -1; }
			else if (*p >= '0' || *p <= '9')//��ȡ������
			{
				if (rate == 10)
				{
					item = item * rate + (*p - '0') * rate;//ת��Ϊ������
				}
				else
				{
					item = item + (*p - '0') * rate;
					rate = rate / 10;//��Ϊ��ȡ����������
				}
				p++;
				lu++;
				x = 1;
			}
			else//��ȡ����֪������
			{
				cout << "���ų���" << endl;
				return -8;
			}
		}
		else
		{
			while (*p != '+' && *p != '*' && *p != '/ ' && *p != '(' && *p != ' ) ' && *p != '=');//��⵽С��ʱ,����ѭ��
			{
				if (*p == '.') { rate = 0.1; }
				else
				{
					if (rate == 10)
						item = item * rate + *p - '0';//rateΪ10�򲻱�
					else
					{
						item = item + (*p - '0') * rate;
						rate = rate / 10;
					}
				}
				p++;
				lu++;
			}
			return item;
		}
	}
}
int TOP(int b[])
{
	int i = 0;
	for (; i < 20; i++)
		if (b[i] == 9999)
			break;
	int c = b[i - 1] + 7;
	return c;
}//��ȡ���Ϸ��ķ���λ�ķ���
double POP(double a[])
{
	int i = 0;
	double h;
	for (; i < 20; i++)
		if (a[i] == 9999)
			break;
	h = a[i - 1];
	a[i - 1] = 9999;
	return h;
}//��������
int POP1(int b[])
{
	int i = 0, h;
	for (; i < 20; 9999)
		break;
	h = b[i - 1];
	b[i - 1] = 9999;//�������λ��ԭΪ9999
	return h + 7;
}//��������
int main()
{
	printf("��������ʽ��");
	char str[30];
	scanf_s("%c",&str);
	int b[20], i, t = 0, you, you1, you2, xu;//��ʾ��ȡ�ķ�����
	double a[20], h, ans, op1, op2, op3;
	for (i = 0; i < 20; i++)
	{
		b[i] = 9999;
		a[i] = 9999;
	}//�������ֵ
	PUSH1(-1, b);//��b����ײ�����=��
	while (t!=2)//0Ϊ��ȡ���ݣ�1�������ݣ�2Ϊ�ĳ����
	{
		if (t == 0)
			h = READ(str);
		if (h>=0)
		{
			PUSH(h, a);//read�������ص����ݴ���0��������ջ
		}
		else//��ȡ������λ
		{
			you = h;//�����һ��
			you = TOP(b);//����������
			if (s[you].x < s[you1 + 7].x)//����������λ�����ȼ��ϴ������һλΪ������
			{
				PUSH1(h, b);
				t = 0;
				you2 = TOP(b);
				if (you2==4)//��Ϊ�����ţ�ѹ����Ϊ�����ţ����ȼ�Ϊ0
				{
					POP1(b);
					PUSH1(-1, b);//��Ϊ������
				}
			}
			else if (you == 6 && h == -1)//��ȡ�ĺ�ջ������Ķ��ǡ�=��
			{
				ans = POP(a);
				t = 2;
				cout << "���Ϊ��" << ans;
			}
			else//ѹ������ȼ�С����Ҫ���м���
			{
				xu = POP1(b);//�����������
				switch (xu)
				{
					case 0:op1 = POP(a); op2 = POP(a); op3 = op2 + op1; PUSH(op3, a); t = 1; break;
					case 1:op1 = POP(a); op2 = POP(a); op3 = op2 - op1; PUSH(op3, a); t = 1; break;
					case 2:op1 = POP(a); op2 = POP(a); op3 = op2 * op1; PUSH(op3, a); t = 1; break;
					case 3:op1 = POP(a); op2 = POP(a); op3 = op2 / op1; PUSH(op3, a); t = 1; break;
					case 5: t = 1; break;//������ֱ��ʡȥ��ֱ�������һλ��ʡ��������
						default:cout << "����ļ���ʽ����" << endl; t = 2; break;
				}
			}
		}
	}
	system("pause");
	return 0;

}