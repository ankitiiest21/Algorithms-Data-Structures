#include <iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void generate_keypad(char inp[],char out[],int i,int j){
    //Base case
    if(inp[i]=='\0')
    {
     out[j]='\0';
     cout<<out<<endl;
     return;
    }
    //Rec case
    int digit=inp[i]-'0';
    if(digit<=1)
     generate_keypad(inp,out,i+1,j);
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
     out[j]=keypad[digit][k];
     //fill the remaining characters
     generate_keypad(inp,out,i+1,j+1);
    }
    return;
}

int main() {
    char inp[1000];
    cin>>inp;
    char out[1000];
    generate_keypad(inp,out,0,0);
    return 0;
}
