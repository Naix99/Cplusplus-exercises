#include<bits/stdc++.h>

using namespace std;
//Code that implement sthe class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box(); (construct a box without information)
// Box(int,int,int); (construct a box with given l,b,h)
// Box(Box); (construct a box with the same data as another box)


class Box {
    private:
        long l; long b; long h; 
    public:
        Box() {
            l = 0; b=0; h=0;
        }
        Box(int le, int br, int he) {
            l = le; b=br; h=he;
        }
        Box(Box &copy){
            l = copy.getLength();
            b = copy.getBreadth();
            h = copy.getHeight();
        }
        int getLength(){
            return l;
        }
        int getBreadth(){
            return b;
        }
        int getHeight(){
            return h;
        }
		// A basic function to give the volume of a box.
        long long int CalculateVolume(){
            return l*b*h;
        }
		// This is defining how to compare two boxes using <.
        bool operator<(Box& ot){
            if (l<ot.getLength()){
                return true;
            }
            else if ( (l == ot.getLength()) && (b < ot.getBreadth())){
                return true;
            }
            else if ( (l ==ot.getLength()) && (b ==ot.getBreadth()) && (h<ot.getHeight()) ){
                return true;
            }
            else{
                return false;
            } 
        }        
};
// This is defining how to print a box to the console.
ostream& operator<<(ostream& out, Box& B){
            out << B.getLength()<< " "<<B.getBreadth()<<" "<<B.getHeight();
            return out; 
}


/* This code just usses different inputs to perform different actions between elements of the Box class. It is just an application of the
code above */
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