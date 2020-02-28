#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
 void remove_duplicate(T *array,int &row)
     {
	 for(int i=0; i<row; i++)
    {
        for(int j=i+1; j<row; j++)
        {
            if(array[i] == array[j])
            {
                for(int k=j; k<row; k++)
                 array[k] = array[k + 1];
                row--;
                j--;
            }
        }
    }
}
template <typename T>
class Myset
{
    private:
    	int row;
     T *array;
     public:
     Myset()
     	{
     		row=0;
     		array=new T[0];
		 }
     Myset(int num)
     {
     	row=num;
         array=new T[num];
     }
     Myset(const Myset& m)
     {
     	row=m.row;
     	array=m.array;
	 }
    Myset operator+(const Myset  s)
    {
    	int i=0,j=0;
    	Myset temp(s.row+row);
    
    	for(;i<row;i++)
    	temp.array[i]=array[i];
    	for(;j<s.row;j++,i++)                                                                                                                                                                                                                                                                                                                  
    	temp.array[i]=s.array[j];
   	remove_duplicate(temp.array,temp.row);
    	return temp;
	}
	Myset operator*(const Myset  s)
    {
    	int i=0,j=0,k=0;
    	Myset temp;
    	if(s.row>=row)
    temp=row;
    	else
    	 temp=s.row;
    	for(int i=0; i<s.row; i++)
    {
        for(int j=0; j<row; j++)
        {
            if(s.array[i] == array[j])
            {
                 temp.array[k++] = array[j];
            }
        }
    }
    temp.row=k;
   	remove_duplicate(temp.array,temp.row);
    	return temp;
    }
    Myset operator^(const Myset  s)
    {
    	int i=0,j=0,k=0;
    	Myset temp;
    	for(int i=0; i<row; i++)
    {
        for(int j=0; j<s.row; j++)
        {
            if(array[i] != s.array[j])
            {
            	if(j==s.row-1)
                 temp.array[k++] = array[i];
            }
            else
            break;
        } 
    }
		  for(int i=0; i<s.row; i++)
    {
        for(int j=0; j<row; j++)
        {
            if(s.array[i] != array[j])
            {
            	if(j==row-1)
                 temp.array[k++] = s.array[i];
            }
            else
            break;
        }                     
    }                    
    temp.row=k;
    remove_duplicate(temp.array,temp.row);
    return temp;
	}
	Myset operator-(const Myset  s)
	{
		int l=0,k=0;
    	Myset temp;
    	for(int i=0; i<row; i++)
    {
        for(int j=0; j<s.row; j++)
        {
            if(array[i] != s.array[j])
            {
            	if(j==s.row-1)
                 temp.array[k++] = array[i];
            }
            else
            break;
        }                     
    }	
	temp.row=k;
  	remove_duplicate(temp.array,temp.row);
	return temp;	
	}
	bool operator== (const Myset s)
        {
            if(row != s.row)
                return false;
            else
            {
                int flag = 0;
                for(int i = 0; i < row; i++)
                    for(int j = 0; j <s.row;j++)
                        if(array[i] ==s.array[j])
                            flag++;
                if(flag == row)
                    return true;
                else
                    return false;
            }
        }
       void cardinality()
       {
    cout<<row;
	   }
     void input ()
     {
     	for(int i=0;i<row;i++)
     	cin>>array[i];
 		remove_duplicate(array,row);
	 }
	 void display()
	 {
	 	int i=0;
	 	if(row==0)
	 	cout<<"{0}";
	 	else
	 	{
		 
	 	cout<<"{";
	 	for(;i<row;i++)
	 	if(i==row-1)
     	cout<<array[i]<<"}";
     	else
     	cout<<array[i]<<",";
	 }
}
  
};
template <typename T>
void printSets(Myset <T> set1, Myset <T> set2,Myset <T> set7, Myset <T> set3, Myset <T> set4, Myset <T> set5, Myset <T> set6,bool result)

{
    cout << "SET A: ";
    set1.display();
    cout << "\nSET B: ";
    set2.display();
    cout << "\nUNION: ";
    set3.display();
    cout << "\nINTERSECTION: ";
    set4.display();
    cout << "\nDIFFERENCE: ";
    set5.display();
    cout << "\nSYMMETRIC DIFFERENCE: ";
    set6.display();
    cout<<"\nCOPY CONSTRUCTOR:";
    set7.display();
   if(result==true)
   cout<<"\nSETS A AND B ARE EQUAL";
   else
   cout<<"\nSETS A AND B ARE NOT EQUAL";
}
int main()
{
	char choice;
	int option;
	do
	{
	int num1,num2;
	cout<<" ENTER NUMBERS OF ELEMENTS YOU WANT TO ENTER IN FIRST SET \n";
	cin>>num1;
	cout<<" ENTER NUMBERS OF ELEMENTS YOU WANT TO ENTER IN SECOND SET\n";
	cin>>num2;
	
	
	cout<<"\n            MENU              ";
	cout<<"\n     1) INTEGER ";
	cout<<"\n     2) CHARACTER ";
	cout<<"\n     3) FLOATING-POINT ";
	cout<<"\n ENTER YOUR CHOICE ";
	cin>>option;
	switch(option)
	{
		case 1:{
						 Myset <int> set1(num1);
                        cout << "ENTER ELEMENTS IN SET1\n";
                        set1.input();
                        Myset <int> set2(num2);
                        cout << "ENTER ELEMENTS IN SET2\n";
                        set2.input();
                        Myset <int> set3 = set1 + set2;                                   
                        Myset <int> set4 = set1 * set2;       
                        Myset <int> set5 = set1 - set2;;       
                        Myset <int> set6 = set1^set2;
                        bool result = set1 == set2;
                        Myset<int> set7=set1;
						printSets(set1, set2, set3, set4, set5, set6,set7,result);
						cout<<"\n CARDINALITY OF SET 1 :";
						set1.cardinality();
						cout<<"\n CARDINALITY OF SET 2 :";
						set2.cardinality();	
						
				break;
			}
		case 2: {
						Myset <char> set1(num1);
                        cout << "ENTER ELEMENTS IN SET1\n";
                        set1.input();
                        Myset <char> set2(num2);
                        cout << "ENTER ELEMENTS IN SET2\n";
                        set2.input();
                        Myset <char> set3 = set1 + set2;                                   
                        Myset <char> set4 = set1 * set2;       
                        Myset <char> set5 = set1 - set2;;       
                        Myset <char> set6 = set1^set2;
                        bool result = set1 == set2;
                        Myset<char> set7=set1;
						printSets(set1, set2, set3, set4, set5, set6,set7,result);	
						cout<<"\n CARDINALITY OF SET 1 :";
						set1.cardinality();
						cout<<"\n CARDINALITY OF SET 2 :";
						set2.cardinality();
				break;
			    }
	   case 3: {
						Myset <float> set1(num1);
                        cout << "ENTER ELEMENTS IN SET1\n";
                        set1.input();
                        Myset <float> set2(num2);
                        cout << "ENTER ELEMENTS IN SET2\n";
                        set2.input();
                        Myset <float> set3 = set1 + set2;                                   
                        Myset <float> set4 = set1 * set2;       
                        Myset <float> set5 = set1 - set2;;       
                        Myset <float> set6 = set1^set2;
                        bool result = set1 == set2;
                        Myset<float> set7=set1;
						printSets(set1, set2, set3, set4, set5, set6,set7,result);	
						cout<<"\n CARDINALITY OF SET 1 :";
						set1.cardinality();
						cout<<"\n CARDINALITY OF SET 2 :";
						set2.cardinality();
				break;
			}
	}
	cout<<"\nDO YOU WANT TO CONTINUE (Y/N)";
	cin>>choice;
}while(choice=='y'||choice=='Y');
	return 0;
}
