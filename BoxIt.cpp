#include<iostream>
using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    int l,b,h;
    public:
        Box(){
            l=0;
            b=0;
            h=0;
        }
        Box(int l, int b, int h ){
            this->l=l;
            this->b=b;
            this->h=h;
        }
        Box(Box &b1){
            l=b1.l;
            b=b1.b;
            h=b1.h;
        }
        int getLength() {return l;}
        int getBreadth() {return b;}
        int getHeight() {return h;}
        long long CalculateVolume(){
            return 1LL*l*b*h;
        }
        bool operator<(const Box& B) 
        {
            if (l < B.l)
                return true;
            
            if (b < B.b && l == B.l)
                return true;
            
            if (h < B.h && l == B.l && b == B.b)
                return true;
            
            return false;
        }

};

ostream& operator<<(ostream& out, Box& B)
{
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight(); 
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}

/*
INPUT//OTPUT
9
1 //! 0 0 0
2 3 4 5 //! 3 4 5
3 5 6 7 //! Greater
5 //! 3 4 5
4 //! 60
2 5 6 7 //! 5 6 7
4 //! 210
5 //! 5 6 7
4 //! 210
*/