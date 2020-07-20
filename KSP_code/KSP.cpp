/* 
    Author:  Hongli Ma<hongli.ma@mail.sdu.edu.cn> 2019

    Usage: This file is KSP source code. Use, redistribution, modify without limitations
  
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


/* define quicksort function */

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



int main(int argc,const char* argv[])
{
	clock_t start;clock_t end;
	start=clock();
	
/* read combined phosphorylation network data */

	ifstream fin(argv[1]);
	vector<string> v1;
	vector<string> v2;
	string s01;
	string s02;
	for(int i=0;i<88282;++i)
	{
		fin>>s01>>s02;
		v1.push_back(s01);
		v2.push_back(s02);
	}	

/* read KSP_EXAMPLE data */

	ifstream fin2(argv[2]);
	char s1;char s2;char s3;char s4;char s5;char s6;char s7;char s8;char s9;char s10;
	char s11;char s12;char s13;char s14;char s15;
	string s03;
	vector<string> TestG;vector<char> sub;
	vector<vector<char> > TestSub;
	string truekinase;vector<string> TK;


       for(int i=0;i<20;++i)
	{
        fin2>>truekinase>>s03>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10>>s11>>s12>>s13>>s14>>s15;
		TestG.push_back(s03);
		TK.push_back(truekinase);
		sub.push_back(s1);sub.push_back(s2);sub.push_back(s3);sub.push_back(s4);
		sub.push_back(s5);sub.push_back(s6);sub.push_back(s7);sub.push_back(s8);
		sub.push_back(s9);sub.push_back(s10);sub.push_back(s11);sub.push_back(s12);
		sub.push_back(s13);sub.push_back(s14);sub.push_back(s15);
		TestSub.push_back(sub);
		sub.clear();
	}
        ofstream fout("ksp_example_output.txt");	
		
/* kinase count */

	map<string,int> Kinase_ID;
	map<int,string> Kinase_ID_Reverse;
	int a0=0;
	for(int j=1;j<10198;++j)
	{
		if(Kinase_ID.count(v1[j])==0)
		{
			Kinase_ID[v1[j]]=a0;
		        Kinase_ID_Reverse[a0]=v1[j];
		        a0=a0+1;
		}		
	}
	
/* substrate gene count */	

	map<string,int> Gene_ID;
	int b0=0;
	
	for(int j=1;j<88282;++j)
	{
		if(Gene_ID.count(v2[j])==0)
		{
			Gene_ID[v2[j]]=b0;
			b0=b0+1;
		}	
	}



    vector<int> temp_vec;
	map<int,vector<int> > Kinase_Trans;
	for(int j=1;j<10198;++j)
	{
           map<string,int>::iterator iter;
	       iter=Kinase_ID.find(v1[j]);
	       int c=iter->second;
	       map<string,int>::iterator iter2;
	       iter2=Gene_ID.find(v2[j]);
	       int d=iter2->second;
	       if(Kinase_Trans.count(c)==0)
	       {
		       Kinase_Trans[c]=temp_vec;
	       }
	       Kinase_Trans[c].push_back(d);
	}        


  	map<int,vector<int> > Gene_Trans;
	for(int j=10198;j<88282;++j)
	{
		map<string,int>::iterator iter;
		iter=Gene_ID.find(v1[j]);
		int e=iter->second;
		map<string,int>::iterator iter2;
		iter2=Gene_ID.find(v2[j]);
		int f=iter2->second;
		if(Gene_Trans.count(e)==0)
		{
			Gene_Trans[e]=temp_vec;
		}
		Gene_Trans[e].push_back(f);
	}

	vector<int> vec_g;
	vector<vector<int> > vec_KT;
	vector<int> vec_h;
	int g;int h;
	int m;int n;
	vector<int> vec_g_size;
        for(int i=0;i<370;++i)
	{
		vec_g=Kinase_Trans[i];
		vec_KT.push_back(vec_g);
		m=vec_g.size();
		vec_g_size.push_back(m);
	}
       

	vector<int> vec_h1;vector<int> vec_h2;
	int n1;int n2;int i;int j;int l;int l1;int l2;
	int M=vec_KT.size();
	vector<int> C;
	double temp0=0;int temp1=0;int temp2=0;int temp3=0;
	vector<vector<double> > CT;
	vector<double> CT0;
	vector<vector<int> > CT1;
	vector<vector<int> > CT2;
	vector<vector<int> > CT3;
	vector<double> temp_CT;
	int truepositive=0;

/* KSP algorithm */

	for(int num=0;num<20;++num)
	{
	map<string,int>::iterator iter;
	iter=Gene_ID.find(TestG[num]);
	int G=iter->second;
        vec_h=Gene_Trans[G];
	n=vec_h.size();
	for(i=0;i<M;++i)
	{
		vec_g=vec_KT[i];
		m=vec_g_size[i];
		for(j=0;j<m;++j)
		{
			if(vec_g[j]==G)temp0=temp0+1;
		}
		CT0.push_back(temp0);
		temp0=0;
	}

        for(i=0;i<M;++i)
	{
		vec_g=vec_KT[i];
		m=vec_g_size[i];
		for(j=0;j<m;++j)
		{
			for(l=0;l<n;++l)
			{
			        if(vec_g[j]==vec_h[l])temp1=temp1+1;
				C.push_back(temp1);
				temp1=0;
			}
		}
		CT1.push_back(C);
		C.clear();
	}

        
       for(i=0;i<M;++i)
	{
		vec_g=vec_KT[i];
		m=vec_g_size[i];
		for(j=0;j<m;++j)
		{
			for(l=0;l<n;++l)
			{
				vec_h1=Gene_Trans[vec_h[l]];
				n1=vec_h1.size();
				for(l1=0;l1<n1;++l1)
				{
					if(vec_g[j]==vec_h1[l1])
						temp2=temp2+1;
				}
				C.push_back(temp2);
				temp2=0;
			}
		}
		CT2.push_back(C);
		C.clear();
	}

       	for(i=0;i<M;++i)
	{
		vec_g=vec_KT[i];
		m=vec_g_size[i];
		for(j=0;j<m;++j)
		{
			for(l=0;l<n;++l)
			{
				vec_h1=Gene_Trans[vec_h[l]];
				n1=vec_h1.size();
				for(l1=0;l1<n1;++l1)
				{
					vec_h2=Gene_Trans[vec_h[l1]];
					n2=vec_h2.size();
					for(l2=0;l2<n2;++l2)
					{
					if(vec_g[j]==vec_h1[l1])
						temp3=temp3+1;
				        }
				}
				C.push_back(temp3);
				temp3=0;
			}
		}
		CT3.push_back(C);
		C.clear();
	}


	for(i=0;i<M;++i)
	{
	        int N=CT1[i].size();
		for(l1=0;l1<N;++l1)
		{
		temp_CT.push_back(0.3*CT1[i][l1]+0.25*CT2[i][l1]+0.25*CT3[i][l1]);
		}
		CT.push_back(temp_CT);
		temp_CT.clear();
	}
			

        double X=0.0;
	vector<double> temp_C;
	vector<double> K_S;
	for(int x=0;x<M;++x)
	{
          	temp_C=CT[x];
		int c_size=temp_C.size();
		for(int y=0;y<c_size;++y)
		{
			X=X+temp_C[y];
		}
		X=X/c_size;
		K_S.push_back(X);
        }

	for(int z=0;z<M;++z)
	{
		K_S[z]=K_S[z]*0.75+CT0[z]*0.25;
	}
			        	        	
        if(n==0)
	{
		for(int i=0;i<M;++i)
		{
			K_S[i]=CT0[i]*0.25;
		}
	}

/*	string tof;
	if(TK[num]=="_ATR")
	{
		tof="Y";
	}
	else
	{
		tof="N";
	}
*/
	double p [370];
        for(int i=0;i<370;++i)
	{
		p[i]=K_S[i];
	}
        int q[370];
	for(int i=0;i<370;i++) 
	{
		q[i]=i;
	}

	quickSort(p, 0, 369, q);
	for(int i=0;i<370;++i)
	{
		K_S[i]=(K_S[i]-p[0])/(p[369]-p[0]);
	}
    for(int i=0;i<370;++i)
	{
		p[i]=K_S[i];
	}

	quickSort(p, 0, 369, q);


	string r01;string r02;string r03;string r04;string r05;string r06;string r07;string r08;string r09;string r10;
	map<int,string>::iterator iterks;
        for(j=0;j<370;++j)
	{
		if(K_S[j]==p[369])
		{
	            iterks=Kinase_ID_Reverse.find(j);
		    r01=iterks->second;
		}
		if(K_S[j]==p[368])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r02=iterks->second;
		}
		if(K_S[j]==p[367])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r03=iterks->second;
		}
		if(K_S[j]==p[366])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r04=iterks->second;
		}
		if(K_S[j]==p[365])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r05=iterks->second;
		}
		if(K_S[j]==p[364])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r06=iterks->second;
		}
		if(K_S[j]==p[363])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r07=iterks->second;
		}
		if(K_S[j]==p[362])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r08=iterks->second;
		}
		if(K_S[j]==p[361])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r09=iterks->second;
		}
		if(K_S[j]==p[360])
		{
		    iterks=Kinase_ID_Reverse.find(j);
		    r10=iterks->second;
		}
	}
	
    fout<<num+1<<' '<<"In terms of KSP, the top kinases are as follows:"<<"\n";
	fout<<r01<<' '<<r02<<' '<<r03<<' '<<r04<<' '<<r05<<' '<<r06<<' '<<r07<<' '<<r08<<' '<<r09<<' '<<r10<<"\n";
	CT0.clear();CT1.clear();CT2.clear();
	CT3.clear();CT.clear();K_S.clear();
}


	    
	end=clock();
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(10)<<"Running time:"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
	return 0;
}




