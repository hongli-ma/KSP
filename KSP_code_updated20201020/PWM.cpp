/* 
    Author:  Hongli Ma<hongli.ma@mail.sdu.edu.cn> 2019

    Usage: This file is PWM source code. Use, redistribution, modify without limitations
  
 */
 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#include<algorithm>
#include<ctime>

using namespace std;

int main(int argc,const char* argv[])
{
	clock_t start;clock_t end;
	start=clock();
	ifstream fin(argv[1]);
	vector<vector<char> > Sub;vector<char> sub;
	vector<string> K;vector<string> G;char s1;char s2;char s3;char s4;char s5;char s6;char s7;char s8;char s9;char s10;char s11;char s12;char s13;char s14;char s15;string k;string g;

/* read train data */

	
        while(!fin.eof()) 
	{
		fin>>k>>g>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10>>s11>>s12>>s13>>s14>>s15;
                if(fin.eof()) break;
		sub.push_back(s1);sub.push_back(s2);sub.push_back(s3);
		sub.push_back(s4);sub.push_back(s5);sub.push_back(s6);
		sub.push_back(s7);sub.push_back(s8);sub.push_back(s9);
		sub.push_back(s10);sub.push_back(s11);sub.push_back(s12);
		sub.push_back(s13);sub.push_back(s14);sub.push_back(s15);
		K.push_back(k);G.push_back(g);
		Sub.push_back(sub);
		sub.clear();
	}

	ifstream fin2(argv[2]);
	vector<char> test;vector<vector<char> > Test;vector<string> TK;vector<string>G2;

/* read test data */

        while(!fin2.eof())
    	{
	        fin2>>k>>g>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10>>s11>>s12>>s13>>s14>>s15;
                if(fin2.eof()) break;
	        test.push_back(s1);test.push_back(s2);test.push_back(s3);test.push_back(s4);
	        test.push_back(s5);test.push_back(s6);test.push_back(s7);test.push_back(s8);
	        test.push_back(s9);test.push_back(s10);test.push_back(s11);test.push_back(s12);
	        test.push_back(s13);test.push_back(s14);test.push_back(s15);
	        TK.push_back(k);G2.push_back(g);
		Test.push_back(test);
		test.clear();
	}
        
	for(int i=0;i<G2.size();++i)
        {
           cout<<G2[i]<<endl;
        }

        string outsuffix="_pwmoutput";
        string outfile_name=argv[2]+outsuffix;
        ofstream fout(outfile_name.c_str());	
	
/* construct position weight matrix */

    //  double aa_bp[]={0.070,0.023,0.048,0.071,0.037,0.066,0.026,0.044,0.058,0.100,0.021,0.036,0.063,0.047,0.056,0.083,0.053,0.060,0.012,0.027};
    double acount=0;double ccount=0;double dcount=0;double ecount=0;
	double fcount=0;double gcount=0;double hcount=0;double icount=0;
	double kcount=0;double lcount=0;double mcount=0;double ncount=0;
	double pcount=0;double qcount=0;double rcount=0;double scount=0;
	double tcount=0;double vcount=0;double wcount=0;double ycount=0;
	vector<vector<char> > V;
	vector<double> tempKS;
	vector<vector<double> > KS;
	for(int j=0;j<15;++j)
	{
		for(int k=0;k<G.size();++k)
		{
                        char temp=Sub[k][j];
			switch(temp)
			{
			case'a':
				acount=acount+1;
				break;
			case'A':
				acount=acount+1;
				break;
			case'c':
				ccount=ccount+1;
				break;
			case'C':
				ccount=ccount+1;
				break;
                        case'd':
				dcount=dcount+1;
				break;
			case'D':
				dcount=dcount+1;
				break;
			case'e':
				ecount=ecount+1;
				break;
			case'E':
				ecount=ecount+1;
				break;
			case'f':
				fcount=fcount+1;
				break;
			case'F':
				fcount=fcount+1;
				break;
			case'g':
				gcount=gcount+1;
				break;
			case'G':
				gcount=gcount+1;
				break;
			case'h':
				hcount=hcount+1;
				break;
			case'H':
				hcount=hcount+1;
				break;
			case'i':
				icount=icount+1;
				break;
			case'I':
				icount=icount+1;
				break;
			case'k':
				kcount=kcount+1;
				break;
			case'K':
				kcount=kcount+1;
				break;
			case'l':
				lcount=lcount+1;
				break;
			case'L':
				lcount=lcount+1;
				break;
			case'm':
				mcount=mcount+1;
				break;
			case'M':
				mcount=mcount+1;
				break;
			case'n':
				ncount=ncount+1;
				break;
			case'N':
				ncount=ncount+1;
				break;
			case'p':
				pcount=pcount+1;
				break;
			case'P':
				pcount=pcount+1;
				break;
			case'q':
				qcount=qcount+1;
				break;
			case'Q':
				qcount=qcount+1;
				break;
			case'r':
				rcount=rcount+1;
				break;
			case'R':
				rcount=rcount+1;
				break;
			case's':
				scount=scount+1;
				break;
			case'S':
				scount=scount+1;
				break;
			case't':
				tcount=tcount+1;
				break;
			case'T':
				tcount=tcount+1;
				break;
			case'v':
				vcount=vcount+1;
				break;
			case'V':
				vcount=vcount+1;
				break;
			case'w':
				wcount=wcount+1;
				break;
			case'W':
				wcount=wcount+1;
				break;
			case'y':
				ycount=ycount+1;
				break;
			case'Y':
				ycount=ycount+1;
				break;
			default:
				break;
			}
			
		}
                double aaver=acount/G.size();//+aa_bp[0]*0.01;
	        double caver=ccount/G.size();//+aa_bp[1]*0.01;
	        double daver=dcount/G.size();//+aa_bp[2]*0.01;
	        double eaver=ecount/G.size();//+aa_bp[3]*0.01;
	        double faver=fcount/G.size();//+aa_bp[4]*0.01;
	        double gaver=gcount/G.size();//+aa_bp[5]*0.01;
	        double haver=hcount/G.size();//+aa_bp[6]*0.01;
	        double iaver=icount/G.size();//+aa_bp[7]*0.01;
	        double kaver=icount/G.size();//+aa_bp[8]*0.01;
	        double laver=lcount/G.size();//+aa_bp[9]*0.01;
	        double maver=mcount/G.size();//+aa_bp[10]*0.01;
	        double naver=ncount/G.size();//+aa_bp[11]*0.01;
	        double paver=pcount/G.size();//+aa_bp[12]*0.01;
	        double qaver=qcount/G.size();//+aa_bp[13]*0.01;
		double raver=rcount/G.size();//+aa_bp[14]*0.01;
		double saver=scount/G.size();//+aa_bp[15]*0.01;
		double taver=tcount/G.size();//+aa_bp[16]*0.01;
		double vaver=vcount/G.size();//+aa_bp[17]*0.01;
		double waver=wcount/G.size();//+aa_bp[18]*0.01;
		double yaver=ycount/G.size();//+aa_bp[19]*0.01;
		       tempKS.push_back(aaver);
		       tempKS.push_back(caver);
		       tempKS.push_back(daver);
		       tempKS.push_back(eaver);
		       tempKS.push_back(faver);
		       tempKS.push_back(gaver);
		       tempKS.push_back(haver);
		       tempKS.push_back(iaver);
		       tempKS.push_back(kaver);
		       tempKS.push_back(laver);
		       tempKS.push_back(maver);
		       tempKS.push_back(naver);
		       tempKS.push_back(paver);
		       tempKS.push_back(qaver);
		       tempKS.push_back(raver);
		       tempKS.push_back(saver);
		       tempKS.push_back(taver);
		       tempKS.push_back(vaver);
		       tempKS.push_back(waver);
		       tempKS.push_back(yaver);
		       KS.push_back(tempKS);
		       tempKS.clear();
       	               acount=0; ccount=0; dcount=0; ecount=0;
	               fcount=0; gcount=0; hcount=0; icount=0;
	               kcount=0; lcount=0; mcount=0; ncount=0;
	               pcount=0; qcount=0; rcount=0; scount=0;
	               tcount=0; vcount=0; wcount=0; ycount=0;
		}
              		

        fout<<"label"<<'	'<<"score"<<"\n";
	double test1;vector<double> T;
	vector<double> T1;
	for(int i=0;i<G2.size();++i)
	{
	for(int j=0;j<15;++j)
	{
		char test0=Test[i][j];
                switch(test0)
                {
	        case'a':
			test1=KS[j][0];
			break;
		case'A':
			test1=KS[j][0];
			break;
		case'c':
			test1=KS[j][1];
			break;
		case'C':
			test1=KS[j][1];
			break;
                case'd':
			test1=KS[j][2];
			break;
		case'D':
			test1=KS[j][2];
			break;
		case'e':
			test1=KS[j][3];
			break;
		case'E':
			test1=KS[j][3];
			break;
		case'f':
			test1=KS[j][4];
			break;
		case'F':
			test1=KS[j][4];
			break;
		case'g':
			test1=KS[j][5];
			break;
		case'G':
			test1=KS[j][5];
			break;
		case'h':
			test1=KS[j][6];
			break;
		case'H':
			test1=KS[j][6];
			break;
		case'i':
			test1=KS[j][7];
			break;
		case'I':
			test1=KS[j][7];
			break;
		case'k':
			test1=KS[j][8];
			break;
		case'K':
			test1=KS[j][8];
			break;
		case'l':
			test1=KS[j][9];
			break;
		case'L':
			test1=KS[j][9];
			break;
		case'm':
			test1=KS[j][10];
			break;
		case'M':
			test1=KS[j][10];
			break;
		case'n':
			test1=KS[j][11];
			break;
		case'N':
			test1=KS[j][11];
			break;
		case'p':
			test1=KS[j][12];
			break;
		case'P':
			test1=KS[j][12];
			break;
		case'q':
			test1=KS[j][13];
			break;
		case'Q':
			test1=KS[j][13];
			break;
		case'r':
			test1=KS[j][14];
			break;
		case'R':
			test1=KS[j][14];
			break;
		case's':
			test1=KS[j][15];
			break;
		case'S':
			test1=KS[j][15];
			break;
		case't':
			test1=KS[j][16];
			break;
		case'T':
			test1=KS[j][16];
			break;
		case'v':
			test1=KS[j][17];
			break;
		case'V':
			test1=KS[j][17];
			break;
		case'w':
			test1=KS[j][18];
			break;
		case'W':
			test1=KS[j][18];
			break;
		case'y':
			test1=KS[j][19];
			break;
		case'Y':
			test1=KS[j][19];
			break;
		case'_':
			test1=0;
			break;
		default:
			break;
		}
		T1.push_back(test1);
	}
	double t=(T1[0]+T1[1]+T1[2]+T1[3]+T1[4]+T1[5]+T1[6]+T1[7]+T1[8]+T1[9]+T1[10]+T1[11]+T1[12]+T1[13]+T1[14])/15;
	T.push_back(t);
	T1.clear();
	string tof;
	if(TK[i]=="_CDK1")
	{
		tof="Y";
	}
	else
	{
		tof="N";
	}
	fout<<tof<<'	'<<T[i]<<"\n";
	}	
	

	end=clock();
	cout<<"Running time:"<<(double)(end-start)/CLOCKS_PER_SEC<<"\n";
	return 0;
}





