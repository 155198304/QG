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
	a[i] = nu;//常数入栈
}
void PUSH1(double nu, int b[])
{
	int i = 0;
	for (; i <= 20; i++)
		if (b[i] == 9999)
			break;
	b[i] = nu;
}//符号优先入栈
double READ(char* p)//从左往右读取
{
	double rate = 10.0, item = 0;
	int x = 0;//表示读取的是数字还是符号
	p = p + lu;
	while (*p != '/n')
	{
		if (x == 0)
		{
			if (*p == '+') { lu++; return-7; }//表示读取到的符号
			else if (*p == '-') { lu++; return -6; }
			else if (*p == '*') { lu++; return -5; }
			else if (*p == '/') { lu++; return -4; }
			else if (*p == '(') { lu++; return -3; }
			else if (*p == ')') { lu++; return -2; }
			else if (*p == '=') { lu++; return -1; }
			else if (*p >= '0' || *p <= '9')//读取到数字
			{
				if (rate == 10)
				{
					item = item * rate + (*p - '0') * rate;//转换为数字量
				}
				else
				{
					item = item + (*p - '0') * rate;
					rate = rate / 10;//若为读取两个连续数
				}
				p++;
				lu++;
				x = 1;
			}
			else//读取到不知名数字
			{
				cout << "符号出错" << endl;
				return -8;
			}
		}
		else
		{
			while (*p != '+' && *p != '*' && *p != '/ ' && *p != '(' && *p != ' ) ' && *p != '=');//检测到小数时,二重循环
			{
				if (*p == '.') { rate = 0.1; }
				else
				{
					if (rate == 10)
						item = item * rate + *p - '0';//rate为10则不变
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
}//提取最上方的符号位的符号
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
}//弹出数据
int POP1(int b[])
{
	int i = 0, h;
	for (; i < 20; 9999)
		break;
	h = b[i - 1];
	b[i - 1] = 9999;//弹出后该位还原为9999
	return h + 7;
}//弹出符号
int main()
{
	printf("请输入表达式：");
	char str[30];
	scanf_s("%c",&str);
	int b[20], i, t = 0, you, you1, you2, xu;//表示读取的符号数
	double a[20], h, ans, op1, op2, op3;
	for (i = 0; i < 20; i++)
	{
		b[i] = 9999;
		a[i] = 9999;
	}//赋予最大值
	PUSH1(-1, b);//在b数组底部放入=号
	while (t!=2)//0为读取数据，1计算数据，2为的出结果
	{
		if (t == 0)
			h = READ(str);
		if (h>=0)
		{
			PUSH(h, a);//read函数返回的数据大于0，数字入栈
		}
		else//读取到符号位
		{
			you = h;//检测下一个
			you = TOP(b);//最上面的序号
			if (s[you].x < s[you1 + 7].x)//索引到符号位的优先级较大或者上一位为左括号
			{
				PUSH1(h, b);
				t = 0;
				you2 = TOP(b);
				if (you2==4)//若为左括号，压入后变为右括号，优先级为0
				{
					POP1(b);
					PUSH1(-1, b);//变为右括号
				}
			}
			else if (you == 6 && h == -1)//读取的和栈最上面的都是”=“
			{
				ans = POP(a);
				t = 2;
				cout << "结果为：" << ans;
			}
			else//压入的优先级小，需要进行计算
			{
				xu = POP1(b);//弹出顶层符号
				switch (xu)
				{
					case 0:op1 = POP(a); op2 = POP(a); op3 = op2 + op1; PUSH(op3, a); t = 1; break;
					case 1:op1 = POP(a); op2 = POP(a); op3 = op2 - op1; PUSH(op3, a); t = 1; break;
					case 2:op1 = POP(a); op2 = POP(a); op3 = op2 * op1; PUSH(op3, a); t = 1; break;
					case 3:op1 = POP(a); op2 = POP(a); op3 = op2 / op1; PUSH(op3, a); t = 1; break;
					case 5: t = 1; break;//左括号直接省去，直接往后读一位，省略右括号
						default:cout << "输入的计算式错误" << endl; t = 2; break;
				}
			}
		}
	}
	system("pause");
	return 0;

}