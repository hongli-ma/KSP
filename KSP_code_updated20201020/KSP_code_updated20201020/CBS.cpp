/* 
    Author:  Hongli Ma<hongli.ma@mail.sdu.edu.cn> 2019

    Usage: This file is CBS source code. Use, redistribution, modify without limitations
  
 */
 
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<deque>
#include<ctime>
#include<iomanip>
#include<limits.h>


using namespace std;


int cmp(const pair<string,double> &x,const pair<string,double> &y)
{
	return x.second>y.second;
}


void sortMapbyVaule(map<string,double> &t_map,vector< pair<string,double> > &t_vec)
{
	for(map<string,double>::iterator iter=t_map.begin();iter!=t_map.end();iter++)
	{
		t_vec.push_back(make_pair(iter->first,iter->second));
	}
	sort(t_vec.begin(),t_vec.end(),cmp);
}



template <class T>
int partition(T a[], int start, int stop, int id[])
{
    	int temp_id, up=start, down=stop-1;
    	T temp_value, part=a[stop];
    	if(stop<=start) return start;
	while(true)
    	{
        	while(a[up]<part) up++;
        	while(part<a[down] && (up<down)) down--;

        	if(up>=down) break;

        	temp_value=a[up];  a[up]=a[down]; a[down]=temp_value;
        	temp_id=id[up]; id[up]=id[down]; id[down]=temp_id;

        	up++; down--;
    	}

    	temp_value=a[up]; a[up]=a[stop]; a[stop]=temp_value;
    	temp_id=id[up]; id[up]=id[stop]; id[stop]=temp_id;
    	return up;
}


template <class T>
void quickSort(T a[], int start, int stop, int id[])
{
    	int i;
    	if(stop<=start) return;

    	i=partition(a,start,stop,id);
    	quickSort(a,start,i-1,id);
    	quickSort(a,i+1,stop,id);
}

/* define BLOSUM62 matrix */

int BLOSUM62(char psub, char qsub)
{
	int output=1000;
	if(psub=='A'||psub=='a')
	{
                switch(qsub)
                {
		        case'a':
				output=4;
				break;
			case'A':	
				output=4;
				break;
			case'c':
				output=0;
				break;
			case'C':
				output=0;
				break;
                        case'd':
				output=-2;
				break;
			case'D':
				output=-2;
				break;
			case'e':
				output=-1;
				break;
			case'E':
				output=-1;
				break;
			case'f':
				output=-2;
				break;
			case'F':
				output=-2;
				break;
			case'g':
				output=0;
				break;
			case'G':
				output=0;
				break;
			case'h':
				output=-2;
				break;
			case'H':
				output=-2;
				break;
			case'i':
				output=-1;
				break;
			case'I':
				output=-1;
				break;
			case'k':
				output=-1;
				break;
			case'K':
				output=-1;
				break;
			case'l':
				output=-1;
				break;
			case'L':
				output=-1;
				break;
			case'm':
				output=-1;
				break;
			case'M':
				output=-1;
				break;
			case'n':
				output=-2;
				break;
			case'N':
				output=-2;
				break;
			case'p':
				output=-1;
				break;
			case'P':
				output=-1;
				break;
			case'q':
				output=-1;
				break;
			case'Q':
				output=-1;
				break;
			case'r':
				output=-1;
				break;
			case'R':
				output=-1;
				break;
			case's':
				output=1;
				break;
			case'S':
				output=1;
				break;
			case't':
				output=0;
				break;
			case'T':
				output=0;
				break;
			case'v':
				output=0;
				break;
			case'V':
				output=0;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='C'||psub=='c')
	{
                switch(qsub)
                {
			case'c':
				output=9;
				break;
			case'C':
				output=9;
				break;
                        case'd':
				output=-3;
				break;
			case'D':
				output=-3;
				break;
			case'e':
				output=-4;
				break;
			case'E':
				output=-4;
				break;
			case'f':
				output=-2;
				break;
			case'F':
				output=-2;
				break;
			case'g':
				output=-3;
				break;
			case'G':
				output=-3;
				break;
			case'h':
				output=-3;
				break;
			case'H':
				output=-3;
				break;
			case'i':
				output=-1;
				break;
			case'I':
				output=-1;
				break;
			case'k':
				output=-3;
				break;
			case'K':
				output=-3;
				break;
			case'l':
				output=-1;
				break;
			case'L':
				output=-1;
				break;
			case'm':
				output=-1;
				break;
			case'M':
				output=-1;
				break;
			case'n':
				output=-3;
				break;
			case'N':
				output=-3;
				break;
			case'p':
				output=-3;
				break;
			case'P':
				output=-3;
				break;
			case'q':
				output=-3;
				break;
			case'Q':
				output=-3;
				break;
			case'r':
				output=-3;
				break;
			case'R':
				output=-3;
				break;
			case's':
				output=-1;
				break;
			case'S':
				output=-1;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-1;
				break;
			case'V':
				output=-1;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='D'||psub=='d')
	{
                switch(qsub)
                {
		        case'd':
				output=6;
				break;
			case'D':
				output=6;
				break;
			case'e':
				output=2;
				break;
			case'E':
				output=2;
				break;
			case'f':
				output=-3;
				break;
			case'F':
				output=-3;
				break;
			case'g':
				output=-1;
				break;
			case'G':
				output=-1;
				break;
			case'h':
				output=-1;
				break;
			case'H':
				output=-1;
				break;
			case'i':
				output=-3;
				break;
			case'I':
				output=-3;
				break;
			case'k':
				output=-1;
				break;
			case'K':
				output=-1;
				break;
			case'l':
				output=-4;
				break;
			case'L':
				output=-4;
				break;
			case'm':
				output=-3;
				break;
			case'M':
				output=-3;
				break;
			case'n':
				output=1;
				break;
			case'N':
				output=1;
				break;
			case'p':
				output=-1;
				break;
			case'P':
				output=-1;
				break;
			case'q':
				output=0;
				break;
			case'Q':
				output=0;
				break;
			case'r':
				output=-2;
				break;
			case'R':
				output=-2;
				break;
			case's':
				output=0;
				break;
			case'S':
				output=0;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-3;
				break;
			case'V':
				output=-3;
				break;
			case'w':
				output=-4;
				break;
			case'W':
				output=-4;
				break;
			case'y':
				output=-3;
				break;
			case'Y':
				output=-3;
				break;
			default:
				break;
		}
	}

	if(psub=='E'||psub=='e')
	{
                switch(qsub)
                {
			case'e':
				output=5;
				break;
			case'E':
				output=5;
				break;
			case'f':
				output=-3;
				break;
			case'F':
				output=-3;
				break;
			case'g':
				output=-2;
				break;
			case'G':
				output=-2;
				break;
			case'h':
				output=0;
				break;
			case'H':
				output=0;
				break;
			case'i':
				output=-3;
				break;
			case'I':
				output=-3;
				break;
			case'k':
				output=1;
				break;
			case'K':
				output=1;
				break;
			case'l':
				output=-3;
				break;
			case'L':
				output=-3;
				break;
			case'm':
				output=-2;
				break;
			case'M':
				output=-2;
				break;
			case'n':
				output=0;
				break;
			case'N':
				output=0;
				break;
			case'p':
				output=-1;
				break;
			case'P':
				output=-1;
				break;
			case'q':
				output=2;
				break;
			case'Q':
				output=2;
				break;
			case'r':
				output=0;
				break;
			case'R':
				output=0;
				break;
			case's':
				output=0;
				break;
			case'S':
				output=0;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-2;
				break;
			case'V':
				output=-2;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='F'||psub=='f')
	{
                switch(qsub)
                {
			case'f':
				output=6;
				break;
			case'F':
				output=6;
				break;
			case'g':
				output=-3;
				break;
			case'G':
				output=-3;
				break;
			case'h':
				output=-1;
				break;
			case'H':
				output=-1;
				break;
			case'i':
				output=0;
				break;
			case'I':
				output=0;
				break;
			case'k':
				output=-3;
				break;
			case'K':
				output=-3;
				break;
			case'l':
				output=0;
				break;
			case'L':
				output=0;
				break;
			case'm':
				output=0;
				break;
			case'M':
				output=0;
				break;
			case'n':
				output=-3;
				break;
			case'N':
				output=-3;
				break;
			case'p':
				output=-4;
				break;
			case'P':
				output=-4;
				break;
			case'q':
				output=-3;
				break;
			case'Q':
				output=-3;
				break;
			case'r':
				output=-3;
				break;
			case'R':
				output=-3;
				break;
			case's':
				output=-2;
				break;
			case'S':
				output=-2;
				break;
			case't':
				output=-2;
				break;
			case'T':
				output=-2;
				break;
			case'v':
				output=-1;
				break;
			case'V':
				output=-1;
				break;
			case'w':
				output=1;
				break;
			case'W':
				output=1;
				break;
			case'y':
				output=3;
				break;
			case'Y':
				output=3;
				break;
			default:
				break;
		}
	}

	if(psub=='G'||psub=='g')
	{
                switch(qsub)
                {
			case'g':
				output=6;
				break;
			case'G':
				output=6;
				break;
			case'h':
				output=-2;
				break;
			case'H':
				output=-2;
				break;
			case'i':
				output=-4;
				break;
			case'I':
				output=-4;
				break;
			case'k':
				output=-2;
				break;
			case'K':
				output=-2;
				break;
			case'l':
				output=-4;
				break;
			case'L':
				output=-4;
				break;
			case'm':
				output=-3;
				break;
			case'M':
				output=-3;
				break;
			case'n':
				output=0;
				break;
			case'N':
				output=0;
				break;
			case'p':
				output=-2;
				break;
			case'P':
				output=-2;
				break;
			case'q':
				output=-2;
				break;
			case'Q':
				output=-2;
				break;
			case'r':
				output=-2;
				break;
			case'R':
				output=-2;
				break;
			case's':
				output=0;
				break;
			case'S':
				output=0;
				break;
			case't':
				output=-2;
				break;
			case'T':
				output=-2;
				break;
			case'v':
				output=-3;
				break;
			case'V':
				output=-3;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=-3;
				break;
			case'Y':
				output=-3;
				break;
			default:
				break;
		}
	}

	if(psub=='H'||psub=='h')
	{
                switch(qsub)
                {
			case'h':
				output=8;
				break;
			case'H':
				output=8;
				break;
			case'i':
				output=-3;
				break;
			case'I':
				output=-3;
				break;
			case'k':
				output=-1;
				break;
			case'K':
				output=-1;
				break;
			case'l':
				output=-3;
				break;
			case'L':
				output=-3;
				break;
			case'm':
				output=-2;
				break;
			case'M':
				output=-2;
				break;
			case'n':
				output=1;
				break;
			case'N':
				output=1;
				break;
			case'p':
				output=-2;
				break;
			case'P':
				output=-2;
				break;
			case'q':
				output=0;
				break;
			case'Q':
				output=0;
				break;
			case'r':
				output=0;
				break;
			case'R':
				output=0;
				break;
			case's':
				output=-1;
				break;
			case'S':
				output=-1;
				break;
			case't':
				output=-2;
				break;
			case'T':
				output=-2;
				break;
			case'v':
				output=-3;
				break;
			case'V':
				output=-3;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=2;
				break;
			case'Y':
				output=2;
				break;
			default:
				break;
		}
	}

	if(psub=='I'||psub=='i')
	{
                switch(qsub)
                {
			case'i':
				output=4;
				break;
			case'I':
				output=4;
				break;
			case'k':
				output=-3;
				break;
			case'K':
				output=-3;
				break;
			case'l':
				output=2;
				break;
			case'L':
				output=2;
				break;
			case'm':
				output=1;
				break;
			case'M':
				output=1;
				break;
			case'n':
				output=-3;
				break;
			case'N':
				output=-3;
				break;
			case'p':
				output=-3;
				break;
			case'P':
				output=-3;
				break;
			case'q':
				output=-3;
				break;
			case'Q':
				output=-3;
				break;
			case'r':
				output=-3;
				break;
			case'R':
				output=-3;
				break;
			case's':
				output=-2;
				break;
			case'S':
				output=-2;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=3;
				break;
			case'V':
				output=3;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-1;
				break;
			case'Y':
				output=-1;
				break;
			default:
				break;
		}
	}

	if(psub=='K'||psub=='k')
	{
                switch(qsub)
                {
			case'k':
				output=5;
				break;
			case'K':
				output=5;
				break;
			case'l':
				output=-2;
				break;
			case'L':
				output=-2;
				break;
			case'm':
				output=-1;
				break;
			case'M':
				output=-1;
				break;
			case'n':
				output=0;
				break;
			case'N':
				output=0;
				break;
			case'p':
				output=-1;
				break;
			case'P':
				output=-1;
				break;
			case'q':
				output=1;
				break;
			case'Q':
				output=1;
				break;
			case'r':
				output=2;
				break;
			case'R':
				output=2;
				break;
			case's':
				output=0;
				break;
			case'S':
				output=0;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-2;
				break;
			case'V':
				output=-2;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='L'||psub=='l')
	{
                switch(qsub)
                {
			case'l':
				output=4;
				break;
			case'L':
				output=4;
				break;
			case'm':
				output=2;
				break;
			case'M':
				output=2;
				break;
			case'n':
				output=-3;
				break;
			case'N':
				output=-3;
				break;
			case'p':
				output=-3;
				break;
			case'P':
				output=-3;
				break;
			case'q':
				output=-2;
				break;
			case'Q':
				output=-2;
				break;
			case'r':
				output=-2;
				break;
			case'R':
				output=-2;
				break;
			case's':
				output=-2;
				break;
			case'S':
				output=-2;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=1;
				break;
			case'V':
				output=1;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=-1;
				break;
			case'Y':
				output=-1;
				break;
			default:
				break;
		}
	}

	if(psub=='M'||psub=='m')
	{
                switch(qsub)
                {
			case'm':
				output=5;
				break;
			case'M':
				output=5;
				break;
			case'n':
				output=-2;
				break;
			case'N':
				output=-2;
				break;
			case'p':
				output=-2;
				break;
			case'P':
				output=-2;
				break;
			case'q':
				output=0;
				break;
			case'Q':
				output=0;
				break;
			case'r':
				output=-1;
				break;
			case'R':
				output=-1;
				break;
			case's':
				output=-1;
				break;
			case'S':
				output=-1;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=1;
				break;
			case'V':
				output=1;
				break;
			case'w':
				output=-1;
				break;
			case'W':
				output=-1;
				break;
			case'y':
				output=-1;
				break;
			case'Y':
				output=-1;
				break;
			default:
				break;
		}
	}

	if(psub=='N'||psub=='n')
	{
                switch(qsub)
                {
			case'n':
				output=6;
				break;
			case'N':
				output=6;
				break;
			case'p':
				output=-2;
				break;
			case'P':
				output=-2;
				break;
			case'q':
				output=0;
				break;
			case'Q':
				output=0;
				break;
			case'r':
				output=0;
				break;
			case'R':
				output=0;
				break;
			case's':
				output=1;
				break;
			case'S':
				output=1;
				break;
			case't':
				output=0;
				break;
			case'T':
				output=0;
				break;
			case'v':
				output=-3;
				break;
			case'V':
				output=-3;
				break;
			case'w':
				output=-4;
				break;
			case'W':
				output=-4;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='P'||psub=='p')
	{
                switch(qsub)
                {
			case'p':
				output=7;
				break;
			case'P':
				output=7;
				break;
			case'q':
				output=-1;
				break;
			case'Q':
				output=-1;
				break;
			case'r':
				output=-2;
				break;
			case'R':
				output=-2;
				break;
			case's':
				output=-1;
				break;
			case'S':
				output=-1;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-2;
				break;
			case'V':
				output=-2;
				break;
			case'w':
				output=-4;
				break;
			case'W':
				output=-4;
				break;
			case'y':
				output=-3;
				break;
			case'Y':
				output=-3;
				break;
			default:
				break;
		}
	}

	if(psub=='Q'||psub=='q')
	{
                switch(qsub)
                {
			case'q':
				output=5;
				break;
			case'Q':
				output=5;
				break;
			case'r':
				output=1;
				break;
			case'R':
				output=1;
				break;
			case's':
				output=0;
				break;
			case'S':
				output=0;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-2;
				break;
			case'V':
				output=-2;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=-1;
				break;
			case'Y':
				output=-1;
				break;
			default:
				break;
		}
	}

	if(psub=='R'||psub=='r')
	{
                switch(qsub)
                {
			case'r':
				output=5;
				break;
			case'R':
				output=5;
				break;
			case's':
				output=-1;
				break;
			case'S':
				output=-1;
				break;
			case't':
				output=-1;
				break;
			case'T':
				output=-1;
				break;
			case'v':
				output=-3;
				break;
			case'V':
				output=-3;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='S'||psub=='s')
	{
                switch(qsub)
                {
			case's':
				output=4;
				break;
			case'S':
				output=4;
				break;
			case't':
				output=1;
				break;
			case'T':
				output=1;
				break;
			case'v':
				output=-2;
				break;
			case'V':
				output=-2;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='T'||psub=='t')
	{
                switch(qsub)
                {
			case't':
				output=5;
				break;
			case'T':
				output=5;
				break;
			case'v':
				output=0;
				break;
			case'V':
				output=0;
				break;
			case'w':
				output=-2;
				break;
			case'W':
				output=-2;
				break;
			case'y':
				output=-2;
				break;
			case'Y':
				output=-2;
				break;
			default:
				break;
		}
	}

	if(psub=='V'||psub=='v')
	{
                switch(qsub)
                {
			case'v':
				output=4;
				break;
			case'V':
				output=4;
				break;
			case'w':
				output=-3;
				break;
			case'W':
				output=-3;
				break;
			case'y':
				output=-1;
				break;
			case'Y':
				output=-1;
				break;
			default:
				break;
		}
	}

	if(psub=='W'||psub=='w')
	{
                switch(qsub)
                {
			case'w':
				output=11;
				break;
			case'W':
				output=11;
				break;
			case'y':
				output=2;
				break;
			case'Y':
				output=2;
				break;
			default:
				break;
		}
	}

	if(psub=='Y'||psub=='y')
	{
                switch(qsub)
                {
			case'y':
				output=7;
				break;
			case'Y':
				output=7;
				break;
			default:
				break;
		}
	}

	if(psub=='_'||qsub=='_')
	{
		output=-4;
	}

	if(output==1000)
	{
		output=BLOSUM62(qsub,psub);
	}
	return output;
}



int main(int argc,const char* argv[])
{
	clock_t start;clock_t end;
	start=clock();

/* read all peptides information */
		
	ifstream fin1(argv[1]);
	vector<vector<char> > Sub;
	vector<char> sub;
	vector<string> K;
	char s1;char s2;char s3;char s4;char s5;char s6;char s7;char s8;char s9;char s10;char s11;char s12;char s13;char s14;char s15;string k;
	
        while(!fin1.eof())
	{
		fin1>>k>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10>>s11>>s12>>s13>>s14>>s15;
                if(fin1.eof()) break;
		sub.push_back(s1);sub.push_back(s2);sub.push_back(s3);sub.push_back(s4);
		sub.push_back(s5);sub.push_back(s6);sub.push_back(s7);sub.push_back(s8);
		sub.push_back(s9);sub.push_back(s10);sub.push_back(s11);sub.push_back(s12);
		sub.push_back(s13);sub.push_back(s14);sub.push_back(s15);
		K.push_back(k);
		Sub.push_back(sub);
		sub.clear();
	}
	
/* read test data */

	ifstream fin2(argv[2]);
	vector<vector<char> > TestSub;
	string truekinase;vector<string> TK;
        while(!fin2.eof())
        {
		fin2>>truekinase>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10>>s11>>s12>>s13>>s14>>s15;
                if(fin2.eof()) break;
		TK.push_back(truekinase);
		sub.push_back(s1);sub.push_back(s2);sub.push_back(s3);sub.push_back(s4);
		sub.push_back(s5);sub.push_back(s6);sub.push_back(s7);sub.push_back(s8);
		sub.push_back(s9);sub.push_back(s10);sub.push_back(s11);sub.push_back(s12);
		sub.push_back(s13);sub.push_back(s14);sub.push_back(s15);
		TestSub.push_back(sub);
		sub.clear();
	}

        string outsuffix="_cbsoutput";
        string outfile_name=argv[2]+outsuffix;
        ofstream fout(outfile_name.c_str());	
	
/* count kinases which have more than 15 sites */	

	map<string,int> Kinase_ID2;
	map<int,string> Kinase_ID2_Reverse;
	int a1=0;
	for(int i=0;i<K.size();++i)
	{
		if(Kinase_ID2.count(K[i])==0)
		{
			Kinase_ID2[K[i]]=a1;
			Kinase_ID2_Reverse[a1]=K[i];
			a1=a1+1;
		}
	}

	map<int,vector<int> > Kinase_Count2;
	vector<int> temp_vec2;
	vector<int> ekcount;
       	for(int i=0;i<113;++i)
	{
		for(int j=0;j<K.size();++j)
		{
	                if(Kinase_ID2[K[j]]==i)
		        temp_vec2.push_back(j);
	        }
		Kinase_Count2[i]=temp_vec2;
		ekcount.push_back(temp_vec2.size());
		temp_vec2.clear();
	}

	map<int,vector<vector<char> > > Kinase_Sub;
	vector<vector<char> > Kinase_sub;
	int a2;int a3;
	int a4=0;
        for(int i=0;i<113;++i)
	{
		a2=ekcount[i];
		a3=a4;
		a4=a4+a2;
		for(int j=a3;j<a4;++j)
		{
			Kinase_sub.push_back(Sub[j]);
		}
		Kinase_Sub[i]=Kinase_sub;
		Kinase_sub.clear();
	}

/* clustering for BLOSUM62 similarity */

	vector<char> epsub;
	char psub0;char qsub0;int blotemp;int blo;
	vector<int> BLO;
	int truepositive3=0;
	for(int k=0;k<TK.size();++k)
	{
	for(int i=0;i<K.size();++i)
	{
		epsub=Sub[i];
		blo=0;
		for(int j=0;j<15;++j)
		{
			psub0=epsub[j];qsub0=TestSub[k][j];
			blotemp=BLOSUM62(psub0,qsub0);
			blo=blo+blotemp;
		}
		BLO.push_back(blo);
	}
	int p2[K.size()];
	for(int i=0;i<K.size();++i)
	{
		p2[i]=BLO[i];
	}
	int q2[K.size()];
	for(int i=0;i<K.size();++i)
	{
		q2[i]=i;
	}
	quickSort(p2,0,K.size(),q2);


       
	vector<string> topkinase;
	for(int j=K.size()-1;j>K.size()-1000;--j)
	{
		for(int i=0;i<K.size();++i)
		{
                        if(BLO[i]==p2[j]&&topkinase.size()<K.size()*0.075)
		        {	
			       topkinase.push_back(K[i]);
		        }
		}
	}

	map<string,int> topkinase30count0;
	int topkc=1;
	for(int i=0;i<K.size()*0.075;++i)
	{
		string a=topkinase[i];
		if(topkinase30count0.count(a)==0)
		{
			topkinase30count0[a]=topkc;
		}
		else
		{
			topkinase30count0[a]=topkinase30count0[a]+1;
		}
	}

	int out;
	map<string,int>::iterator iter;
	iter=topkinase30count0.find("_ERK2");
	if(iter==topkinase30count0.end())
	{
		out=0;
	}
	else
	{
                out=iter->second;
	}
	/*string tof;
	if(TK[k]=="_ATM")
	{
		tof="Y";
	}
	else
	{
		tof="N";
	}
	fout<<tof<<'	'<<out<<"\n";*/
        	

    vector<double> avertopkinase;
	for(int i=0;i<K.size()*0.075;++i)
	{
		string a=topkinase[i];
		map<string,int>::iterator iter;
		iter=Kinase_ID2.find(a);
		int temp_id=iter->second;
		int temp_ekc=ekcount[temp_id];
		int temp_tk30c=topkinase30count0[a];
		double temp=(double)temp_tk30c/temp_ekc;
		avertopkinase.push_back(temp);
	}


	map<string,double> topkinase30count;

	for(int i=0;i<K.size()*0.075;++i)
	{
		string a=topkinase[i];
		double b=avertopkinase[i];
		if(topkinase30count.count(a)==0)
		{
			topkinase30count[a]=b;
		}
	}

    vector< pair<string,double> >Vtopkinase30count;
	sortMapbyVaule(topkinase30count,Vtopkinase30count);


	fout<<k+1<<' '<<"In terms of CBS, the top kinases are as follows:"<<"\n";
	for(int i=0;i<10;++i)
	{
		fout<<Vtopkinase30count[i].first<<' '<<Vtopkinase30count[i].second<<"\n";
		if(Vtopkinase30count[i].first==TK[k])
		{
			truepositive3=truepositive3+1;
		}
	}	

        BLO.clear();

        }

    end=clock();
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(10)<<"Running time:"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
	return 0;
}




