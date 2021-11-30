#include<iostream>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;

static int p = 0;

class a
{
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}

bus[10];

void vline(char ch)
{
	for(int i=80;i>0;i--)
	{
		cout<<ch;
	}
}

void a::install()
{
	cout<<"Enter bus no. : ";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name : ";
	cin>>bus[p].driver;
	cout<<"\nArrival Time : ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture Time : ";
	cin>>bus[p].depart;
	cout<<"\nFrom : \t\t ";
	cin>>bus[p].from;
	cout<<"\nTo : \t\t ";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}

void a::allotment()
{
	int seat, n;
	char num[5];
	top:
		cout<<"Bus No. : ";
		cin>>num;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn, num) == 0)
				break;
		}
		while(n<=p)
		{
			cout<<"\nSeat No. : ";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in this bus ..!";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty") == 0)
				{
					cout<<"\nEnter Passanger's name : ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
				else
					cout<<"The seat no. is already reserved.\n";
			}
		}
		if(n>p)
		{
			cout<<"Enter correct bus no. : ";
			goto top;
		}
}

void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");
		}
	}
}

void a::show()
{
	int n;
	char num[5];
	cout<<"Enter bus no. : ";
	cin>>num;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn, num) == 0)
			break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"Bus no, : "<<bus[n].busn<<"\nDriver Name : "<<bus[n].driver<<"\nArrival Time : "<<bus[n].arrival
		<<"\nDeparture Time : "<<bus[n].depart<<"\nFrom : "<<bus[n].from<<"\nTo : "<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a = 1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j], "Empty") != 0)
					cout<<"\nThe seat no. "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<" .";
			}
		}
		break;
	}
	if(n>p)
		cout<<"Enter correct bus no.";
}

void a::position(int l)
{
	int s=0, p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty") == 0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\nThere are "<<p<<" seats empty in the Bus No. : "<<bus[l].busn;
}

void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus no, : "<<bus[n].busn<<"\nDriver Name : "<<bus[n].driver<<"\nArrival Time : "<<bus[n].arrival
		<<"\nDeparture Time : "<<bus[n].depart<<"\nFrom : "<<bus[n].from<<"\nTo : "<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}

int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<"\n\n\n";
		cout<<"\t\t1. Install \n\t\t"<<"2. Reservation \n\t\t"<<"3. Show \n\t\t"<<"4. Buses Available \n\t\t"<<"5. Exit";
		cout<<"\nEnter your choice : ";
		cin>>w;
		switch(w)
		{
			case 1: bus[p].install();
					break;
			case 2: bus[p].allotment();
					break;
			case 3: bus[p].show();
					break;
			case 4: bus[p].avail();
					break;
			case 5: exit(0);
		}
	}
	return 0;
}
