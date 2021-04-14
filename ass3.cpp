/************************************************************************************************************************
Author:				Soojin Han
Student No:			040 698 591
Assignment name:	Assignment 3. Transient-Response Analysis of 1st Order Systems
Course Name/Number: Numerical Computing CST8233
Lab Sect:			301
Professor:			Abdullah Kadri
Due Date:			August 7 2020
Submission Date:	August 7 2020
Filename:			ass3.cpp
Version:			1.0
Purpose:			The purpose of the assignment to find the solution of 1st order Ordinary Differential Equations 
					(ODE) using well known methods; namely, Euler’s and Runge-Kutta 4th Order Methods
 ************************************************************************************************************************/

#include<iostream>
#include<vector>
#include <stdio.h>      
#include <math.h>      
#include <iomanip>

using namespace std;

void Euler(int, float, float, float);
void RK(int, float, float, float);

/*************************************************************************************************************
Function name:				main()
Purpose:					The purpose of the method is to run program to calculate Euler's method or 
							Runge-Kutta 4th Order Method
Function In parameters:		None
Function Out parameters:	int, returns zero on success
Version:					1.0
Author/Student Name:		Soojin Han
 **************************************************************************************************************/
int main()
{
	short option = 0;		/*user option*/
	int count;				/*iteration count*/
	const short xFinal = 2; /*final x value*/
	float yVal;				/*y value*/
	float xVal;				/*x value*/
	float h;				/*h value*/

	while (1)
	{
		xVal = 0;
		yVal = 3;

		cout << ">> Choose the method for solving the ODE:" << endl;
		cout << "\n1. Euler's Method" << endl;
		cout << "\n2. Runge-Kutta 4th Order Method\n\n>> ";

		if (cin >> option)
		{
			cout << "\n>> Choose step size \"h\" (0.8, 0.2, 0.05)\n\n>> ";
			cin >> h;
			count = (int)((xFinal - xVal) / h);
			cout << "\nTime(second)   Exact Temp(C)   Estimated Temp(C)   Percentage Error(%)" << endl;
			
			if (option == 1)
			{
				/*user chooses Euler's method*/
				Euler(count, xVal, yVal, h);
			}
			else if (option == 2)
			{
				/*user chooses Runge-Kutta 4th Order Method*/
				RK(count, xVal, yVal, h);
			}
			else
			{
				/*user entered a wrong option*/
				cout << "Please enter again" << endl;
			}

		}

		cout << "\n";
	}

	return 0;
}

/*************************************************************************************************************
Function name:				main()
Purpose:					The purpose of the method is to run to calculate Euler's method 
Function In parameters:		int count, float xVal, float yVal, float h
Function Out parameters:	void
Version:					1.0
Author/Student Name:		Soojin Han
 **************************************************************************************************************/
void Euler(int count, float xVal, float yVal, float h)
{
	float exactTemp;/*exact temperature*/
	float percError;/*percentage error*/
	float inc=h;	/*h value assign to inc*/

	for (int i = 0; i < count; i++)
	{
		/*exact, estimated temperature, tim, and percentage errors are calculated*/
		yVal = yVal + (cos(4 * xVal) - (2 * yVal)) * h;
		exactTemp = 0.1f * cos(4 * inc) + 0.2f * sin(4 * inc) + 2.9f * exp(-2 * inc);
		percError = abs(yVal - exactTemp) / exactTemp * 100;

		cout << fixed << setprecision(1) << inc << "            " << setprecision(3) << exactTemp << setw(16)
			<< yVal << setprecision(2) << "               " << percError << endl;

		xVal = xVal + h;/*x value is incremented by h*/
		inc += h;
	}

}

/*************************************************************************************************************
Function name:				main()
Purpose:					The purpose of the method is to run to calculate Runge-Kutta 4th Order Method
Function In parameters:		int count, float xVal, float yVal, float h
Function Out parameters:	void
Version:					1.0
Author/Student Name:		Soojin Han
 **************************************************************************************************************/
void RK(int count, float xVal, float yVal, float h)
{
	float exactTemp;/*exact temperature*/
	float percError;/*percentage error*/
	float inc = h;	/*h value assign to inc*/
	float k1;		/*k1 value*/
	float k2;		/*k2 value*/
	float k3;		/*k3 value*/
	float k4;		/*k4 value*/

	for (int i = 0; i < count; i++)
	{
		/*k1,k2,k3,k4,y value, exact, and estimated temperature, and percentage errors are calculated*/
		k1 = cos(4 * xVal) - 2 * yVal;
		k2 = cos(4 * (xVal + 0.5f * h)) - 2 * (yVal + 0.5f * k1 * h);
		k3 = cos(4 * (xVal + 0.5f * h)) - 2 * (yVal + 0.5f * k2 * h);
		k4 = cos(4 * (xVal + h)) - 2 * (yVal + k3 * h);
		yVal = yVal + (1.0f / 6.0f) * (k1 + 2 * k2 + 2 * k3 + k4) * h;
		exactTemp = 0.1f * cos(4 * inc) + 0.2f * sin(4 * inc) + 2.9f * exp(-2 * inc);
		percError = abs(yVal - exactTemp) / exactTemp * 100;

		cout << fixed << setprecision(1) << inc << "            " << setprecision(3) << exactTemp << setw(16)
			<< yVal << setprecision(2) << "               " << percError << endl;

		xVal += h;
		inc += h;
	}

}