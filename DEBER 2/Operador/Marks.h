#include <iostream>

class Marks{
	int notas[3];
	public:
		Marks(int sub1, int sub2, int sub3){
			notas[0]= sub1;
			notas[1]= sub2;
			notas[2]= sub3;	
		}
		int operator[](int position);
		
	
};