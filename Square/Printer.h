#pragma once
#include <iostream>
class Printer
{
private:
	std::string* Square;
	int* Prioritet;
	int SizeSquare;
	int MaxSizeSquare;
	int* h;
	int* m;
	int* s;
public:
	Printer(int z)
	{
		MaxSizeSquare = z;
		Square = new std::string[MaxSizeSquare];
		Prioritet = new int[MaxSizeSquare];
		SizeSquare = 0;
		h=new int[MaxSizeSquare];
		m=new int[MaxSizeSquare];
		s=new int[MaxSizeSquare];
	}
	bool IsFull()
	{
		return SizeSquare == MaxSizeSquare;
	}
	void add(std::string a, int b,int c,int d,int e)
	{
		if (!IsFull()) {
			Square[SizeSquare] = a;
			Prioritet[SizeSquare] = b;
			h[SizeSquare] = c;
			m[SizeSquare] = d;
			s[SizeSquare] = e;
			SizeSquare++;
		}
	}

	std::string Extract()
	{
		if (!IsEmpty()) {
			
			int max_pri = Prioritet[0];
			
			int pos_max_pri = 0;
			
			for (int i = 1; i < SizeSquare; i++)
				
				
				if (max_pri > Prioritet[i]) {
					max_pri = Prioritet[i];
					pos_max_pri = i;
				}
			
			std::string temp1 = Square[pos_max_pri];
			int temp2 = Prioritet[pos_max_pri];
			
			for (int i = pos_max_pri; i < SizeSquare - 1; i++) {
				Square[i] = Square[i + 1];
				Prioritet[i] = Prioritet[i + 1];
			}
			
			SizeSquare--;
			
			return temp1;
		}

	}

	void Clear()
	{
		SizeSquare = 0;
	}

	bool IsEmpty()
	{
		return SizeSquare == 0;
	}

	int GetCount()
	{
		return SizeSquare;
	}

	void Show() 
	{
		for (int i = 0; i < SizeSquare; i++) 
		{
			std::cout << Square[i] << "-" << Prioritet[i] << "  " << "Time: " << h[i] <<" : " <<m[i]<<" : " << s[i] << std::endl;
		}
	}

	~Printer() 
	{
		delete[]Square;
		delete[]Prioritet;
		delete[]h;
		delete[]m;
		delete[]s;
	}

};

