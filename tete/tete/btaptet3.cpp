#include<iostream>
#include<math.h>
using namespace std;

void ptbac2(float a, float b, float c, int* songhiem, float* x1, float* x2)
{
	if (a == 0)
	{
		if (b == 0)


		{
			*songhiem = (c == 0) ? -1 : 0; 




		}
		else {
			*songhiem = 1;
			 *x1 = -c / b;
			
		}
	}
	else {
		float delta = (b * b) -( 4 * a * c);
		if (delta == 0) {
			*songhiem = 1;
			*x1 = -b / 2 * a;
		}
			

			if (delta > 0)
			{
				*songhiem = 2;
				*x1 = ( - b - sqrt(delta)) /( 2 * a); *x2 =( - b + sqrt(delta)) /( 2 * a);
				

			}if (delta < 0) {
				*songhiem = 0;

			}

		}
	}


int main() {
	float a,  b,  c;
		float x1, x2;
		int songhiem;
		cout << "nhap vao cac phan tu a   "; cin >> a;
		cout << "nhap vao cac phan tu b   "; cin >> b;
		cout << "nhap vao cac phan tu c   "; cin >> c;
		ptbac2(a, b, c, &songhiem, &x1, &x2);

		
		if (songhiem == -1) {
			cout << "Kết quả: Phương trình có vô số nghiệm.";
		}
		else if (songhiem == 0) {
			cout << "Kết quả: Phương trình vô nghiệm.";
		}
		else if (songhiem == 1) {
			cout << "Kết quả: Phương trình có 1 nghiệm: x = " << x1 ;
		}
		else {
			cout << "Kết quả: Phương trình có 2 nghiệm: x1 = " << x1 << ", x2 = " << x2 ;
		}

	return 0;
}