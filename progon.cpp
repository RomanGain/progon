#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
/*
void greekletters()
{
	cout << "Enter the alpha, beta and gamma:" << endl;
};

float *f_equtation(float *x, int n)
{
	float *f = new float[n + 1];
	for (int i = 0; i <= n; i++)
	{
		f[i] = 6 * pow(x[i], 2) - x[i] + 2 - pow(x[i], 3);
		cout << f[i] << endl;

	}
	return f;
	delete[] f;
};
*/

void line()
{
	cout << "+" << setw(3) << setfill('-');
	cout << "+" << setw(5) << setfill('-');
	cout << "+" << setw(11) << setfill('-');
	cout << "+" << setw(11) << setfill('-');
	cout << "+" << setw(12) << setfill('-') << "+" << endl;
};

void titles()
{
	cout << "|" << setw(2) << setfill(' ') << "#";
	cout << "|" << setw(4) << setfill(' ') << "x";
	cout << "|" << setw(10) << setfill(' ') << "y";
	cout << "|" << setw(10) << setfill(' ') << "U";
	cout << "|" << setw(11) << setfill(' ') << "Accuracy" << "|" << endl;
};

void out_out(int n, float *x, float *y, float *U,float *acc)
{
	for (int i = 0; i <= n; i++)
	{
		cout << "|" << setw(2) << setfill(' ') << i << "|";
		cout << setw(4) << setfill(' ') << x[i] << "|";
		cout << setw(10) << setfill(' ') << y[i] << "|";
		cout << setw(10) << setfill(' ') << U[i] << "|";
		cout << setw(11) << setfill(' ') << acc[i] << "|"<< endl;
	}
};

void branch()
{
	cout << "Choose which one for a[i] " << endl;
	cout << "1) for a[i] = p(ih) or" << endl;
	cout << "2) for a[i] = p(ih + h/2)" << endl;
};

void main()
{
	int n, number;
	
	cout << "Enter n" << endl;
	cin >> n;
	system("cls");
	float h = 1.0 / n;
	float* x = new float[n + 1];
	float *f = new float[n + 1];
	float *U = new float[n + 1];
	x[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		x[i] = x[i - 1] + h;

	}

			for (int i = 0; i <= n; i++)
			{
				f[i] = 6 * pow(x[i], 2) - x[i] + 2 - pow(x[i], 3);
			}

					float* fi = new float[n+1];
					float* b = new float[n+1];
					float* a = new float[n+1];
					float* acc = new float[n + 1];

					for (int i = 0; i<=n; i++)
					{
						fi[i] = 6 * pow(i*h, 2) - (i*h) + 2 - pow(i*h, 3);
						b[i] = 1 + i*h;
					}

					branch();
					cin >> number;
					system("cls");


					if (number == 1)
						for (int i = 0; i <= n; i++)
						{
							a[i] = 1 + pow(i*h, 2);
						}
					else if (number == 2)
						for (int i = 0; i <= n; i++)
						{
							a[i] = 1 + pow(i*h+h/2, 2);
						}
					

					
					float* C = new float[n+1];
					float* B = new float[n+1];
					float* A = new float[n+1];
					for (int i = 0; i<n ; i++) 
					{
						C[i] = a[i+1]/pow(h,2);
						B[i] = (a[i] + a[i + 1]) / pow(h, 2) + b[i];
					}
					C[0] = 0;
					C[n] = 0;
					B[n] = (a[n] / pow(h, 2) + b[n]);
							

							for (int i = n; i > 0; i--)
							{
								A[i] = a[i - 1] / pow(h, 2);
							}
							A[0] = 0;

							/*for (int i = 0; i <= n; i++)
							{
								cout << i << " " << f[i] << " " << fi[i] << " ";
								cout << b[i] << " " << a[i] << " " << C[i] << " " << B[i] << " " << A[i] << endl;

							}*/

					

											float* P = new float[n+1];
											float* Q = new float[n+1];
											float* y = new float[n+1];


											
											for (int i = 0; i<n; i++)
											{
												P[i+1] = C[i]/(B[i]-A[i]*P[i]);

												Q[i+1] = (A[i]*Q[i]+fi[i])/(B[i]-A[i]*P[i]);

											}
											P[0] = 0;
											Q[0] = 0;

												y[n] = 0;
												for (int i=n-1 ; i>0 ; i--)
												{
													y[i] = P[i+1]*y[i+1] + Q[i+1];
												}
												y[0] = 0;


														for (int i = 0; i <= n; i++)
														{
															acc[i] = fabs(y[i]-i*h*(1 - i*h));
														}
														

																for (int i = 0; i <= n; i++)
																	{
																		U[i] = x[i] * (1 - x[i]);
																	}
																U[n] = 0;

	line();
	titles();
	line();
	out_out(n, x, y, U, acc);
	line();


					delete[] f;
					delete[] x;
					delete[] fi;
					delete[] b;
					delete[] a;
					delete[] C;
					delete[] B;
					delete[] A;
					delete[] P;
					delete[] Q;
					delete[] y;
					delete[] U;
					delete[] acc;


	system("pause");
}
