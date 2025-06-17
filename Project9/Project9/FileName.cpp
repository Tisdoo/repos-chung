#include<iostream>
#include<math.h>
using namespace std;
struct Sothuc
{
	float a, b, c, x1, x2, denta;

};
int ktra(Sothuc ps)
{
	ps.denta = ps.b * ps.b - 4 * ps.a * ps.c;

	if (ps.denta == 0)return 2;
	if (ps.denta > 0)return 1;
	if (ps.denta < 0)return -1;

}int giainghiem(Sothuc ps)
{

}