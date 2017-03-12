#include <iostream>
#include <fstream>
#include <string>
	

using namespace std;

class tmatrix{
private:
	int count_1,count_2;
	int **array;
public:
	tmatrix();
	tmatrix(int,int);
	tmatrix(tmatrix&);
	void print();
	void fill(string);
	tmatrix operator+(tmatrix);
	tmatrix operator*(tmatrix);
	tmatrix operator == (tmatrix&)const;
	tmatrix operator = (const tmatrix&);
	~tmatrix();
};

tmatrix::tmatrix(){
	count_1=0;
	count_2=0;
}

tmatrix tmatrix::operator = ( const tmatrix &tmat)
{
	for(int i=0;i<count_1;i++)
	{
		delete[] array[i];
	}
	delete[] array;
	array = new int*[tmat.count_1];
	for(int i=0;i<tmat.count_1;i++){
		array[i]=new int[count_2];
		for(int j=0;j<count_2;j++){
			array[i][j]=tmat.array[i][j];
		}
	}
	count_1 = tmat.count_1;
	count_2 = tmat.count_2;
	return *this;
	
}


tmatrix tmatrix::operator == (tmatrix &MatrixCopy)const{
	tmatrix re(count_1, count_2);
	for (int i = 0; i < count_1; i++){
		for (int j = 0; j < count_2; j++){
			if (array[i][j] != MatrixCopy.array[i][j]){
				cout << "Matrix_1 != Matrix_2";
			}
		break;
		} 
	break;
	}
	cout << "Matrix_1 == Matrix_2" << "\n";
	return re;
}

tmatrix::tmatrix(int xSize, int ySize)
{
	array = new int *[ySize];
	for (int count = 0; count < ySize; count++)
		array[count] = new int[xSize];
	count_1 = xSize;
	count_2 = ySize;
	for (int i = 0; i < count_1; i++){
		for (int j = 0; j < count_2; j++){
		array[i][j] = 0;
		}
	}
}

tmatrix::tmatrix(tmatrix&count){
	count_1=count.count_1;
	count_2=count.count_2;
	array=new int * [count_1];
	for(int i=0;i<count_1;i++){
		array[i]=new int[count_2];
		for(int j=0;j<count_2;j++){
			array[i][j]=count.array[i][j];
		}
	}
}

void tmatrix::fill(string name_1){
	ifstream file_1(name_1);
	for(int i=0;i<count_1;i++){
		for(int j=0;j<count_2;j++){
			file_1>>array[i][j];
		}
	}
}

void tmatrix::print(){
	for(int i=0;i<count_1;i++){
		for(int j=0;j<count_2;j++){
			cout<<array[i][j]<<"   ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

tmatrix tmatrix::operator+(tmatrix count){
	tmatrix overload(count_1,count_2);
	for(int i=0;i<count_1;i++){
		for(int j=0;j<count_2;j++){
			overload.array[i][j]=array[i][j] + count.array[i][j];
		}
	}
	return overload;
}

tmatrix tmatrix::operator*(tmatrix count){
	tmatrix overload(count_1,count_2);
	for(int i=0;i<count_1;i++){
		for(int j=0;j<count_2;j++){
			overload.array[i][j] = 0;
			for(int k=0;k<count_2;k++){
				overload.array[i][j] +=array[i][k] * count.array[k][j];
			}

		}

	}
	return overload;
}
	
tmatrix::~tmatrix()
{
		for (int i = 0; i < count_1; i++){
		delete[] array[i];
	}
	delete[] array;
}

int main (){
	string name_1;
	int ySize,xSize;
	cout<<"Print file name:";
	getline(cin,name_1);
	cout<<"Number of lines: ";
	cin>>ySize;
	cout<<"Number of columns: ";
	cin>>xSize;
	tmatrix tmatrix_1(xSize,ySize);
	tmatrix_1.fill(name_1);
	tmatrix_1.print();
	tmatrix tmatrix_2(xSize,ySize);
	tmatrix_2.fill(name_1);
	tmatrix_2.print();
	tmatrix Sum = tmatrix_1+tmatrix_2;
	Sum.print();	
	tmatrix Comp = tmatrix_1*tmatrix_2;
	Comp.print();
	tmatrix  Mult = (tmatrix_1 == tmatrix_2);
	tmatrix  Equel = (tmatrix_1 = tmatrix_2);
	system("pause");
}
