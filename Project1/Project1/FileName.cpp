#include<iostream>
#include<math.h>
using namespace std;
struct Sothuc
{
	float a, b, c, delta, t1, t2, t3, t4;
	float x1 = 0, x2 = 0;
};
int ktra(Sothuc ps)
{
	if (ps.a == 0 && ps.b == 0 && ps.c == 0)return -1; else
	{
		if (ps.delta < 0) return 0;
		if (ps.delta == 0)return 1;
		if (ps.delta > 0)return 2;
	}
}

float tinhpt2(Sothuc ps)
{
	
	

		
		if (ktra(ps) == 1) { ps.x1 = -ps.b / 2 * ps.a; return ps.x1; }
		if (ktra(ps) == 2)
		{
			ps.x1 = (-ps.b + sqrt(ps.delta)) / 2 * ps.a; ps.x2 = (-ps.b - sqrt(ps.delta)) / 2 * ps.a;

			if (ps.x1 > ps.x2) {
				float t = ps.x2;
				ps.x2 = ps.x1;
				ps.x1 = t; return ps.x1;
					return ps.x2;



			}


		}
	
}void chuyen(Sothuc ps)
{
	tinhpt2(ps);
	if (ktra(ps) == 0); cout << "phuong trinh vo nghiem";

	
	if (ktra(ps) == 1) {
		if (ps.x1 < 0)
			cout << "phuong trinh vo nghiem  "; else {

			ps.t1 = sqrt(ps.x1); ps.t2 = -sqrt(ps.x1);
			cout << "phuong trinh co 2 nghiem" << ps.t1 << "    " << ps.t2;
		}
	}if (ktra(ps) == 2)
	{
		if (ps.x1 < 0 && ps.x2 < 0)
			cout << "phuong trinh vo nghiem  "; else {

			ps.t1 = sqrt(ps.x1); ps.t2 = -sqrt(ps.x1);
			ps.t3 = sqrt(ps.x2); ps.t4 = -sqrt(ps.x2);
			cout << "phuong trinh 4 nghiem" << ps.t1 << "  " << ps.t2 << "  " << ps.t3 << "  " << ps.t4;
		}
	}
};









	int main()
	{
		Sothuc ps;
		cin >> ps.a; cout << endl;
		cin >> ps.b; cout << endl;
		cin >> ps.c; cout << endl;
		ps.delta = ps.b * ps.b - 4 * ps.a * ps.c;
		chuyen(ps);
		return 0;
	}
