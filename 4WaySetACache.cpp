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
    string filename;
    cout<<"Enter name of the file:";
    cin>>filename;    
    long int hit = 0;
    long int miss = 0;
    ifstream fin;
    string line,word;
    vector<string> hexa;
    vector<string> bin;
    vector<string> way1 = vector<string>(16384,"");
    vector<string> way2 = vector<string>(16384,"");
    vector<string> way3 = vector<string>(16384,"");
    vector<string> way4 = vector<string>(16384,"");
    vector<int> vb_way1 = vector<int>(16384,0);
    vector<int> vb_way2 = vector<int>(16384,0);
    vector<int> vb_way3 = vector<int>(16384,0);
    vector<int> vb_way4 = vector<int>(16384,0);
    vector<vector<int>> VectorOfStacks;
    vector<int> stack(0);
    // cout<<"a"<<endl;
    for(int i = 0;i<16384;i++)
    {

        VectorOfStacks.push_back(stack);
    }
    // for(int i =0;i<90;i++)
    // {
    //     for(int j=0;j<VectorOfStacks[i].size();j++)
    //     {
    //             cout<<VectorOfStacks[i][j]<<" ";
    //     }
    //     cout<<i<<endl;
    // }






    // cout<<"a"<<endl;
    fin.open(filename);
    // cout<<"b"<<endl;
     while(getline(fin,line))
     {
                if( fin.eof() ) 
                {
                          break;
                }
                                
        // cout<<line<<endl;
        // cout<<line.substr(4,8)<<endl;
         hexa.push_back(line.substr(4,8));     
     }
     // cout<<"b"<<endl;
     // cout<<"c"<<endl;
     for(int i =0;i<hexa.size();i++)
     {
        // cout<<i<<" "<<hexa[i]<<" "<<HexaToBinary(hexa[i])<<" ";
        string  temp = HexaToBinary(hexa[i]);
        bin.push_back(temp);
        // cout<<bin[i]<<endl;
        

     }
     // cout<<"c"<<endl;

     // cout<<"d"<<endl;

     // cout<<bin.size();
     for(int i =0;i<bin.size();i++)
     {
        // cout<<i<<endl;
        int index = stoi((bin[i].substr(16,14)),0,2);
        // cout<<i<<" "<<index<<endl; 
        if(vb_way1[index]==0)
        {
                // cout<<"x"<<endl;

                miss++;
                vb_way1[index] = 1;
                way1[index] = bin[i].substr(0,16);
                VectorOfStacks[index].push_back(1);
                // cout<<"x"<<endl;
        }
        // else if(vb_way1[index]==1)
        else
        {
                
                if(way1[index]==bin[i].substr(0,16))
                {
                        hit++;
                        int j;
                        for(j=0;j<VectorOfStacks[index].size();j++)
                        {
                                if(VectorOfStacks[index][j]==1)
                                {
                                        break;
                                }
                        }
                        VectorOfStacks[index].erase(VectorOfStacks[index].begin()+j);
                        VectorOfStacks[index].push_back(1);



                }
                else
                {
                        if(vb_way2[index]==0)
                        {
                                miss++;
                                vb_way2[index] = 1;
                                way2[index] = bin[i].substr(0,16);   
                                VectorOfStacks[index].push_back(2);                      
                        }
                        // else if(vb_way2[index]==1)
                        else
                        {
                                if(way2[index]==bin[i].substr(0,16))
                                {
                                        hit++;
                                        int j;
                                        for(j=0;j<VectorOfStacks[index].size();j++)
                                        {
                                                if(VectorOfStacks[index][j]==2)
                                                {
                                                        break;
                                                }
                                        }
                                        VectorOfStacks[index].erase(VectorOfStacks[index].begin()+j);
                                        VectorOfStacks[index].push_back(2);
                                }  
                                else
                                {
                                        if(vb_way3[index]==0)
                                        {
                                                miss++;
                                                vb_way3[index] = 1;
                                                way3[index] = bin[i].substr(0,16); 
                                                VectorOfStacks[index].push_back(3);                        
                                        }
                                        // else if(vb_way3[index]==1)
                                        else
                                        {
                                                if(way3[index]==bin[i].substr(0,16))
                                                {
                                                        hit++;
                                                        int j;
                                                        for(j=0;j<VectorOfStacks[index].size();j++)
                                                        {
                                                                if(VectorOfStacks[index][j]==3)
                                                                {
                                                                        break;
                                                                }
                                                        }
                                                        VectorOfStacks[index].erase(VectorOfStacks[index].begin()+j);
                                                        VectorOfStacks[index].push_back(3);                                                       


                                                }
                                                else
                                                {
                                                        if(vb_way4[index]==0)
                                                        {
                                                            miss++   ;
                                                            vb_way4[index] = 1;
                                                            way4[index] = bin[i].substr(0,16);
                                                            VectorOfStacks[index].push_back(4);

                                                        }
                                                        // else if(vb_way4[index]==1)
                                                        else
                                                        {
                                                             if(way4[index]==bin[i].substr(0,16))
                                                             {
                                                                hit++;
                                                                int j;
                                                                for(j=0;j<VectorOfStacks[index].size();j++)
                                                                {
                                                                        if(VectorOfStacks[index][j]==4)
                                                                        {
                                                                                break;
                                                                        }
                                                                }
                                                                VectorOfStacks[index].erase(VectorOfStacks[index].begin()+j);
                                                                VectorOfStacks[index].push_back(4);




                                                             }
                                                             else
                                                             {
                                                                miss++;
                                                                int lru_way = VectorOfStacks[index][0];
                                                                VectorOfStacks[index].erase(VectorOfStacks[index].begin());
                                                                VectorOfStacks[index].push_back(lru_way);

                                                                if(lru_way ==1)
                                                                {
                                                                        way1[index] = bin[i].substr(0,16);

                                                                }
                                                                else if(lru_way ==2)
                                                                {
                                                                        way2[index] = bin[i].substr(0,16);

                                                                }
                                                                else if(lru_way ==3)
                                                                {
                                                                        way3[index] = bin[i].substr(0,16);

                                                                }
                                                                else if(lru_way ==4)
                                                                {
                                                                        way4[index] = bin[i].substr(0,16);

                                                                }



                                                             }
                                                        }
                                                }
                                        }

                                }
                        }

                }

        }
        // else if(vb_way2[index]==0)
        // {
        //         // cout<<"p"<<endl;
        //         miss++;
        //         vb_way2[index] = 1;
        //         way2[index] = bin[i].substr(0,16);  
        //         // cout<<"p"<<endl;   
        // }
        // else if(vb_way3[index]==0)
        // {
        //         // cout<<"q"<<endl;
        //         miss++;
        //         vb_way3[index] = 1;
        //         way3[index] = bin[i].substr(0,16);   
        //         // cout<<"q"<<endl;  
        // }
        // else if(vb_way4[index]==0)
        // {
        //         // cout<<"r"<<endl;
        //         miss++;
        //         vb_way4[index] = 1;
        //         way4[index] = bin[i].substr(0,16);   
        //         // cout<<"r"<<endl;  
        // }
        // else
        // {
        //         // int lru_way = VectorOfStacks[index][0];
        //         // VectorOfStacks[index].erase(0);
        //         // VectorOfStacks[index].push_back(lru_way);
        //         // cout<<"ayush"<<endl;
                
                
        //         if(way1[index]==bin[i].substr(0,16))
        //         {
        //                                 hit++;
        //         }
        //         else if(way2[index]==bin[i].substr(0,16))
        //         {
        //                                 hit++;
        //         }
        //         else if(way3[index]==bin[i].substr(0,16))
        //         {
        //                                 hit++;
        //         }
        //         else if(way4[index]==bin[i].substr(0,16))
        //         {
        //                                 hit++;
        //         }
        //         else
        //         {
        //                 // cout<<"hey"<<endl;
        //                 miss++;
        //                 int lru_way = VectorOfStacks[index][0];
        //                 // cout<<"as"<<endl;
        //                 VectorOfStacks[index].erase(VectorOfStacks[index].begin());
        //                 // cout<<"ak"<<endl;
        //                 VectorOfStacks[index].push_back(lru_way);
        //                 // cout<<"ad"<<endl;
        //                 if(lru_way ==1)
        //                 {
        //                         way1[index] == bin[i].substr(0,16);

        //                 }
        //                 else if(lru_way ==2)
        //                 {
        //                         way2[index] == bin[i].substr(0,16);

        //                 }
        //                 else if(lru_way ==3)
        //                 {
        //                         way3[index] == bin[i].substr(0,16);

        //                 }
        //                 else if(lru_way ==4)
        //                 {
        //                         way4[index] == bin[i].substr(0,16);

        //                 }
        //                 // cout<<"hey"<<endl;
        //         }
        //         // cout<<"ayush"<<endl;

                
        // }
     }
     // cout<<"d"<<endl;
     
     cout<<"Hits: "<<hit<<endl;
     cout<<"Misses: "<<miss<<endl;
     cout<<"Percentage of Hits: "<<((float)hit/(float)(hit+miss))*100;
}
