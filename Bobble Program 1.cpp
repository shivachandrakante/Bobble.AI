#include<iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector<vector<string> > row;

void read_record() 
{ 
	fstream fin; 
	fin.open("Book1.csv", ios::in); 
	string word, temp,line; 

	while (!fin.eof()) { 
		getline(fin,line);
		stringstream s(line);
    	string   cell;
		vector<string> v;
		while (getline(s,cell, ',')) 
		{ 
			v.push_back(cell); 
		} 
		row.push_back(v);
	}
}
void print(string c,int pos,int l)
{
	int i;
	string s="";
	for(int i=0;i<row[pos].size();i++)
	{
		s=c+row[pos][i];
		if(s.length()==l)
		{
			cout<<s<<",";
		}
		else
		{
			print(s,pos+1,l);
		}
	}
}
int main()
{
	read_record();
	string k="";
	print(k,0,row.size()-1);
	return 0;
}

