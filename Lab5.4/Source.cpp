#include<iostream>
#include<cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0;
	for (int i = 1; i <= N; i++)
		s += (1 / i) + sqrt(1 + sin(i) * sin(i));
	return s;
}
double S1(const int K, const int N, const int i = 1)
{
	if (i > N)
		return 0;
	else
		return (1 / i) + sqrt(1 + sin(i) * sin(i)) + S1(K,N, i + 1);
}
double S2(const int K, const int N, const int i = 1)
{
	if (i < 1)
		return 0;
	else
		return (1 / i) + sqrt(1 + sin(i) * sin(i)) + S2(K, N, i - 1);
}
double S3(const int K, const int N, const int i, double t)
{
	t = t + (1 / i) + sqrt(1 + sin(i) * sin(i));
	if (i >= N)
		return t;
	else
		return S3(K, N, i + 1, t);
}
double S4(const int K, const int N, const int i, double t)
{
	t = t + (1 / i) + sqrt(1 + sin(i) * sin(i));
	if (i <= 1)
		return t;
	else
		return S4(K, N, i - 1, t);
}
int main()
{
	int K, N;
	K = 1;

	cout << "N = "; cin >> N;
	cout << "(iter)        S0 = " << S0(K, N) << endl;
	cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;
	return 0;
}