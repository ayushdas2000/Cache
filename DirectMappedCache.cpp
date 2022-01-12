#include<bits/stdc++.h>

#include<string.h>
#include <sstream>
#include <fstream>
#include<vector>
using namespace std;

string HexaToBinary(string hexa)
{
		long int j=0;

        
        

        string s="";
        while(hexa[j])
        {
                switch(hexa[j])
                {
                        case '0' : s=s+"0000";
                                break;
                        case '1' : s=s+"0001";
                                break;
                        case '2' : s=s+"0010";
                                break;
                        case '3' : s=s+"0011";
                                break;
                        case '4' : s=s+"0100";
                                break;
                        case '5' : s=s+"0101";
                                break;
                        case '6' : s=s+"0110";
                                break;
                        case '7' : s=s+"0111";
                                break;
                        case '8' : s=s+"1000";
                                break;
                        case '9' : s=s+"1001";
                                break;
                        case 'A' : s=s+"1010";
                                break;
                        case 'B' : s=s+"1011";
                                break;
                        case 'C' : s=s+"1100";
                                break;
                        case 'D' : s=s+"1101";
                                break;
                        case 'E' : s=s+"1110";
                                break;
                        case 'F' : s=s+"1111";
                                break;
                        case 'a' : s=s+"1010";
                                break;
                        case 'b' : s=s+"1011";
                                break;
                        case 'c' : s=s+"1100";
                                break;
                        case 'd' : s=s+"1101";
                                break;
                        case 'e' : s=s+"1110";
                                break;
                        case 'f' : s=s+"1111";
                                break;
                        default : cout<<"\n Invalid Hexadecimal Digit... "<<hexa[j];

                }
                j++;
        }

        return s;

}

int main()
{
	// string hex = HexaToBinary("1ffff668");
	// int i = stoi(hex,0,2);
	// vector<string> v(100);
	// v[i] = "ayush";
	// cout<<v[i];
	// cout<<HexaToBinary("1ffff640")<<endl;
	string filename;
	cout<<"Enter name of the file:";
	cin>>filename;
	ifstream fin;
    string line,word;
	long int hit = 0;
	long int miss = 0;
    vector<string> hexa;
    vector<string> bin;
    vector<string> cache = vector<string>(65536,"");

    int rows = 0;
    fin.open(filename);
     while(getline(fin,line))

     {
   		// vector<string> tokens;

     // 	tokens.clear();
     //    stringstream s(line);
     //    string temp;

     	       	if( fin.eof() ) 
       			 	{
       			 		break;
       			 	}
       			 	
       	// cout<<line<<endl;
       	// cout<<line.substr(4,8)<<endl;
       	 hexa.push_back(line.substr(4,8));
     		// 	row.clear();
       //          fin>>line;
       			 	// while(getline(s,temp,' '))
       			 	// {
       			 	// 	tokens.push_back(temp);
       			 	// }
       			 	// hexa.push_back(tokens[1]);




       // 			 if( fin.eof() ) 
       // 			 	{
       // 			 		break;
       // 			 	}
			    // while (getline(s, word, ' ')) 
			    // { 
			  
			    //         // add all the column data 
			    //         // of a row to a vector 
			    //         // cout<<word;
			    //         row.push_back(word); 
		     //    }
		     //   for(int i=0;i<row.size();i++)

		     //   {
		     //   	cout<<row[i]<<" ";
		     //   }
		     //   cout<<endl;
       // 			 // hexa.push_back(row[1].substr(2,10));
       // 			 rows++;


        	    	


     }

     // for(int i=0;i<10;i++)
     // {
     // 	cout<<hexa[i]<<endl;
     // // }

     for(int i =0;i<hexa.size();i++)
     {
     	// cout<<i<<" "<<hexa[i]<<" "<<HexaToBinary(hexa[i])<<" ";
     	string  temp = HexaToBinary(hexa[i]);
     	bin.push_back(temp);
     	// cout<<bin[i]<<endl;
     	
     }
     // for(int i = 0;i<hexa.size();i++)
     // {
     // 	cout<<hexa[i]<<" "<<bin[i]<<" "<<i<<endl;
     // }




     vector<int> validbit;
     for(int i = 0;i<65536;i++)
     {
     	validbit.push_back(0);

     	// cout<<i<<" "<<validbit[i]<<endl;
     }
     // for(int i =0;i<bin.size();i++)
     // {
     // 	cout<<i<<" "<<bin[i]<<endl;
     // }
     // cout<<"came out"<<endl;




     // cout<<bin[0]<<endl;

     for(int i =0;i<bin.size();i++)
     {
     	

     	int index = stoi((bin[i].substr(14,16)),0,2);
     	// cout<<bin[i].substr(14,16)<<endl;
     	// cout<<i<<" "<<"index "<<index<<endl;
     	// cout<<validbit[index];

     	if(validbit[index]==0)
     	{

     		miss++;
     		cache[index] = bin[i].substr(0,14);
     		validbit[index] = 1;
     	}
     	else if(validbit[index]==1)
     	{
     		if(cache[index]==bin[i].substr(0,14))
     		{
     			hit++;
     		}
     		else
     		{
     			miss++;
     			cache[index] = bin[i].substr(0,14);

     		}
     	}
     }
     cout<<"Hits: "<<hit<<endl;
     cout<<"Misses: "<<miss<<endl;
     cout<<"Percentage of Hits: "<<((float)hit/(float)(hit+miss))*100;

    
}


