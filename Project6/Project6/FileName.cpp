#include<math.h>
#include<iostream>
#include<limits>
using namespace std;
struct Sothuc
{
	float a, b, c, delta,t1,t2,t3,t4;
	float x1 = 0, x2 = 0;
};
void tinh(Sothuc ps)
{
	if (ps.a ==0&& ps.b ==0&& ps.c == 0)cout << "phuong trinh co vo so nghiem";
	else {

		if (ps.delta < 0) { cout << "phuong trinh vo nghiem"; }
		if (ps.delta == 0) {
			ps.x1 = -ps.b / 2 * ps.a; if (ps.x1 > 0) {
				ps.t1 = sqrt(ps.x1); ps.t2 = -sqrt(ps.x1); 
				if (ps.t1 > ps.t2)
				{
					int t = ps.t2;
					ps.t2 = ps.t1;
					ps.t1 = t;
				};
				cout << "phuong trinh co 2 nghiem" << ps.t1 << "   " << ps.t2;
			}
			else
				cout << "phuong trinh vo nghiem" << endl;
		} }
		if (ps.delta > 0)
		{
			ps.x1 = (-ps.b + sqrt(ps.delta)) / 2 * ps.a; ps.x2 = (-ps.b - sqrt(ps.delta)) / 2 * ps.a;
			if (ps.x1 < 0 && ps.x2 < 0)cout << "phuong trinh vo nghiem "; else
			{
				ps.t1 =- sqrt(ps.x1); ps.t2 = -sqrt(ps.x2); ps.t3 = sqrt(ps.x1); ps.t4 = sqrt(ps.x2);
				cout << "phuong trinh co 4 nghiem" << ps.t1 << ps.t2 << ps.t3 << ps.t4;
			}
			if (ps.x1 > 0 && ps.x2 < 0) {
				ps.t1 = -sqrt(ps.x1); ps.t2 = sqrt(ps.x1);
					if (ps.t1 > ps.t2)
				{
					int t = ps.t2;
					ps.t2 = ps.t1;
					ps.t1 = t;
				}; cout << "phuong trinh co 2 nghiem" << ps.t1 << "   " << ps.t2;
			}else{
				ps.t1 =- sqrt(ps.x2); ps.t2 = sqrt(ps.x2); 
				if (ps.t1 > ps.t2)
				{
					int t = ps.t2;
					ps.t2 = ps.t1;
					ps.t1 = t;
				} cout << "phuong trinh co 2 nghiem" << ps.t1 << "   " << ps.t2;

			}
		}
	}

int main()
{
	Sothuc ps;
	 cin >> ps.a; cout << endl;
	 cin >> ps.b; cout << endl;
	 cin >> ps.c; cout << endl;
	ps.delta = ps.b * ps.b - 4 * ps.a * ps.c;
	tinh( ps ); return 0;
	
}