#pragma once   // ��� ����������� ����� h-����� ���� ��� �� ���� ����� ����������� ���� ��� � ����� �����!

typedef enum { false, true } bool;

/*
* ������������ ���������� ������ ���� � �����.
* @param t_ - �����, � ������� ����� ���������� �����.
* @return - ���������� ������ ���� � �����.
*/
int EvenCount(int t_);

/*
* ������������ ���������� ������� ����� <= x
* @param x_ - �������� �����.
* @return ���������� ���������� ������� �����.
*/
int PI( int x_);

/*
* ������� �������� �� ����� �������.
*/
bool IsPrime( int number_);

/*
* ������� ������.
* @param x_ - ������� ����� �����.
* @result ������������ ���������� ����� ������� ������� � x_.
*/
int FI(int x_);

/*
* ������� ��� �� ������.
* @param a - ������ �����.
* @param b - ������ �����.
* @return ���������� ����� �������� a � b.
*/
int Gcd(int a, int b);

/*
* ������� ��������� �����.
* @param x_ - ����� �����.
* @return ��������� �����.
*/
unsigned long long Fact(int x_);

/*
* ������� ������������ ����� �� ������ �������:
* ���� ����� - ������, �� ������������ ������ ����� �� ����.
* ����� - �������� ������������.
* @param x_ - ����� �����.
* @return ������������ ������, ���� �������� ����� ������������������.
*/
unsigned long long DFact(int x_);

/*
* ������ �� ������� ������ �2: ����� ����� ���� ������ ��������� ���� ���������,
* ������� �� ��������� x_.
* @param x_ - ����� �����.
* @return ����� ������ ��������� ���� ���������.
*/
unsigned long long Euler_2(int x_);

/*
* ���������� n-� ���� ���� ���������.
*/
unsigned long long Fib(int n_);