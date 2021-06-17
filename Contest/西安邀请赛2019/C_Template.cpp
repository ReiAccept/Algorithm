#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
const double eps = 1e-6;
const double PI = acos(-1.0); // PI = 180°= 3.14 
using namespace std;
//判断符号
int sign(double x)
{
	if (fabs(x) < eps)
		return 0;
	return x > 0 ? 1 : -1;
}
 
struct point
{
	double x;
	double y;
	point operator + (const point& other) { return point{ x + other.x, y + other.y }; }
	point operator - (const point& other) { return point{ x - other.x, y - other.y }; }
	point operator * (double k) { return point{ x * k, y * k }; }
	point operator / (double k) { return point{ x / k, y / k }; }
	bool operator == (const point& other)
	{
		return sign(x - other.x) == 0 && sign(y - other.y) == 0;
	}
	bool operator < (const point & other)
	{
		if (fabs(x - other.x) < eps)
			return y < other.y;
		return x < other.x;
	}
};
//点积
double dot(point a, point b)
{
	return a.x* b.x + a.y * b.y;
}
//叉积
double cross(point a, point b)
{
	return a.x* b.y - b.x * a.y;
}
//向量的长度 (可以计算两点距离
double getlen(point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
//两向量夹角
double getangle(point a, point b)
{
	return acos(dot(a, b) / getlen(a) / getlen(b));
}
//点P 绕 点O 逆时针旋转angle角度(弧度制)
point rotate(point p, point o, double angle)
{
	point t = point{ p.x - o.x,p.y - o.y };
	double c = cos(angle), s = sin(angle);
	return point{ o.x + t.x * c - t.y * s,o.y + t.x * s + t.y * c };
}
 
struct circle
{
	point o;
	double r;
};
//经过点p，作圆o的切线，sol是切点数组，返回值为切点数
int gettangents(point p, circle oo, vector<point> & sol)
{
	double dis = getlen(p - oo.o);
	if (dis < oo.r)
		return 0;
	else if (sign(dis - oo.r) == 0)
	{
		sol.push_back(rotate(oo.o, p, PI / 2));
		return 1;
	}
	else
	{
		double angle = asin(oo.r / dis);
		sol.push_back(rotate(oo.o, p, angle));
		sol.push_back(rotate(oo.o, p, -angle));
		return 2;
	}
}
 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		point a; circle o;
		scanf("%lf%lf%lf%lf%lf", &o.o.x, &o.o.y, &o.r, &a.x, &a.y);
		point l = point{ o.o.x - o.r,o.o.y }, r = point{ o.o.x + o.r,o.o.y };
		point b = point{ o.o.x,o.o.y - o.r };
		vector<point>sol;
		int cnt = gettangents(a, o, sol);
		double ans = 99999999;
		for (int i = 0; i < cnt; i++)
		{
			double dis = getlen(a - sol[i]);
			sol[i] = (sol[i] - a) * (sqrt(dis * dis - o.r * o.r)) / dis + a;
			if (sign(sol[i].y - o.o.y) < 0)
			{
				if (sign(sol[i].x - o.o.x) < 0)
					sol[i] = l;
				else
					sol[i] = r;
			}
			double res = getlen(a - sol[i]) + getangle(sol[i] - o.o, b - o.o) * o.r;
			ans = min(ans, res);
		}
		printf("%.4lf\n", ans);
	}
}
