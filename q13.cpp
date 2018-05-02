#include<iostream>
using namespace std;

int main()
{

char x,y;

cout<<"ENTER THE TRUTH VALUE FOR X :"<<endl;
cin>>x;

cout<<"ENTER THE TRUTH VALUE FOR Y :"<<endl;
cin>>y;

char conj,disj,exOR,cond,biCond,exNOR,negX,negY,NAND,NOR;

if(x=='F' && y=='F')
{
conj = 'F';
disj ='F';
exOR = 'F';
cond = 'T';
biCond = 'T';
exNOR = 'T';
negX = 'T';
negY = 'T';
NAND = 'T';
NOR = 'T';

}

else if(x=='F' && y=='T')
{
conj = 'F';
disj ='T';
exOR = 'T';
cond = 'T';
biCond = 'F';
exNOR = 'F';
negX = 'T';
negY = 'F';
NAND = 'T';
NOR = 'F';
}

else if(x=='T' && y=='F')
{
conj = 'F';
disj ='T';
exOR = 'T';
cond = 'F';
biCond = 'F';
exNOR = 'F';
negX = 'F';
negY = 'T';
NAND = 'T';
NOR = 'F';
}

else if(x=='T' && y=='T')
{
conj = 'T';
disj ='T';
exOR = 'F';
cond = 'T';
biCond = 'T';
exNOR = 'T';
negX = 'F';
negY = 'F';
NAND = 'F';
NOR = 'F';
}

cout<<"================================================TRUTH TABLE==========================================================="<<endl<<endl;
cout<<"| TRUTH VALUE | CONJUCTION | DISJUNCTION | EXCLUSIVE-OR | EXCLUSIVE-NOR | CONDITIONAL | BICONDITIONAL | NEGATION |  NAND  |  NOR  |"<<endl;
cout<<"|"<<"  X =  "<<"  "<<x<<"   | "<<"     "<<" "<<"     "<<"|"<<"       "<<" "<<"     "<<"|"<<"      "<<" "<<"       "<<"|"<<"       "<<" "<<"       "<<"|"<<"      "<<" "<<"      "<<"|"<<"       "<<" "<<"       "<<"|"<<"    "<<negX<<"     "<<"|"<<"    "<<" "<<"   "<<"|"<<"   "<<" "<<"   "<<"|"<<endl;


cout<<"|"<<"  OPERATIONS"<<" | "<<"     "<<conj<<"     "<<"|"<<"       "<<disj<<"     "<<"|"<<"      "<<exOR<<"       "<<"|"<<"       "<<exNOR<<"       "<<"|"<<"      "<<cond<<"      "<<"|"<<"       "<<biCond<<"       "<<"|"<<"    "<<" "<<"     "<<"|"<<"    "<<NAND<<"   "<<"|"<<"   "<<NOR<<"   "<<"|"<<endl;


cout<<"|"<<"  Y =  "<<"  "<<y<<"   | "<<"     "<<" "<<"     "<<"|"<<"       "<<" "<<"     "<<"|"<<"      "<<" "<<"       "<<"|"<<"       "<<" "<<"       "<<"|"<<"      "<<" "<<"      "<<"|"<<"       "<<" "<<"       "<<"|"<<"    "<<negY<<"     "<<"|"<<"    "<<" "<<"   "<<"|"<<"   "<<" "<<"   "<<"|"<<endl<<endl;

return 0;

}

