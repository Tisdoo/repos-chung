#include<iostream>
using namespace std;
struct Sothuc
{
	float a, b, c, x1, x2, denta;
};


int ktra(Sothuc ps)
{
	if (ps.denta == 0) return 2;
	if (ps.denta < 0)return 0;
	if (ps.denta > 0)return 1;

}
void tinh(Sothuc ps)
{
	ps.denta = ps.b*ps.b - 4*ps.a*ps.c;


}






int main()
{
	cout >> "n";

	return 0;
}