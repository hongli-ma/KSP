/* 
    Author:  Hongli Ma<hongli.ma@mail.sdu.edu.cn> 2019

    Usage: This file is KSP source code. Use, redistribution, modify without limitations
  
 */

#include<iostream>
#include<fstream>
#include <sstream>
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
	vector<string> TestG;
	vector<string> TestSub;
        vector<string> TK;

        while(!fin2.eof())
	{
           vector<string> strings;
           string line; string s; 
           while(getline(fin2, line))
           {
              istringstream iss(line);
	      while(getline(iss,s,'\t'))
	      {
		  strings.push_back(s);
	      }
              if(strings.size()==3)
              {
	         TK.push_back(strings[0]);
	         TestG.push_back(strings[1]);
	         TestSub.push_back(strings[2]);
              }
              else if(strings.size()==2)
              {
	         TestG.push_back(strings[0]);
	         TestSub.push_back(strings[1]);
              }
              else
              {
                cout<<"Error: Wrong KSP test data format. Please refer to Data Format Requirements at https://sourceforge.net/projects/kspscore/files/"<<"\n";
                return 0;
              }
	      strings.clear();
	   }
	}
        string outsuffix="_kspoutput";
        string outfile_name=argv[2]+outsuffix;
        ofstream fout(outfile_name.c_str());	

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

	for(int num=0;num<TestG.size();++num)
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
		K_S[z]=K_S[z]*0.5+CT0[z]*0.5;
	}
			        	        	
        if(n==0)
	{
		for(int i=0;i<M;++i)
		{
			K_S[i]=CT0[i]*0.5;
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


	string r01;
	double score1;
	map<int,string>::iterator iterks;
	vector<int> index(K_S.size(), 0);
	vector<string> Top10kinase;
	vector<double> Top10score;
	for (int i = 0 ; i != index.size() ; i++) {
	    index[i] = i;
	}
	sort(index.begin(), index.end(),
	    [&](const int& a, const int& b) {
		return (K_S[a] < K_S[b]);
	    }
	);
	for (int i = index.size()-1; i>=index.size()-10; i--) 
	{

	    iterks=Kinase_ID_Reverse.find(index[i]);
	    r01=iterks->second;
	    Top10kinase.push_back(r01);
	    score1=K_S[index[i]];
	    Top10score.push_back(score1);
	}




	
     fout<<num+1<<' '<<"In terms of KSP, the top kinases with KSPScores are as follows:"<<"\n";
     for(int i=0;i<Top10kinase.size();i++)
     {
	fout<<Top10kinase[i]<<' '<<Top10score[i]<<"\n";
     }
        
	CT0.clear();CT1.clear();CT2.clear();
	CT3.clear();CT.clear();K_S.clear();
}


	    
	end=clock();
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(10)<<"Running time:"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
	return 0;
}




