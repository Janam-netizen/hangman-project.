	#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
void draw(int tries)
{if(tries==6 || tries==7)
    {
	cout << " ___________"<<endl;
	cout << " |        }"<<endl;
	cout << " |         " <<endl;
	cout << "_|______________"<<endl;
    }
    else if(tries==5)
    {
	cout << " ___________"<<endl;
	cout << " |        }"<<endl;
	cout << " |       \\  " <<endl;
	cout << "_|______________"<<endl;
    }
    else if(tries==4)
    {
	cout << " ___________"<<endl;
	cout << " |         }"<<endl;
	cout << " |       \\ 0 " <<endl;
	cout << "_|______________"<<endl;
    }
    else if(tries==3)
    {
	cout << " ___________"<<endl;
	cout << " |         }"<<endl;
	cout << " |       \\ 0 /" <<endl;
	cout << "_|______________"<<endl;
    }
    else if(tries==2)
    {
	cout << " ___________"<<endl;
	cout << " |        }"<<endl;
	cout << " |      \\ 0 /" <<endl;
	cout << " |        |"<<endl;
	cout << "_|______________"<<endl;
    }
    else if(tries==1)
    {
	cout << " ___________"<<endl;
	cout << " |         }"<<endl;
	cout << " |       \\ 0 /"<<endl;
	cout << " |         | "<<endl;
	cout << " |        /  "<<endl;
	cout << "_|______________"<<endl;
    }
    else

    {
	cout << " ___________"<<endl;
	cout << " |         }"<<endl;
	cout << " |       \\ 0 /"<<endl;
	cout << " |         | "<<endl;
	cout << " |        / \\ "<<endl;
	cout << "_|______________"<<endl;
    }
}

int play(char str[10])
{

char inp;
int ctr=6;
char fill[10];
int flag=0;
for(int i=0;str[i]!='\0';i++)
    {fill[i]='_ ' ;

    }
fill[i]='\0';

while(1)
     { clrscr();
      draw(ctr);
     puts(fill);
     cout<<endl;
     cout<<"enter letter"<<endl;
     cin>>inp;





     flag=0;
      for(int j=0;str[j]!='\0';j++)
	  {if (str[j]==inp)
	       {fill[j]=inp;
	       flag=1;
	       }
	  }


       if(flag==0&&ctr!=0)
	 {
	  ctr--;
	 }

	if(strcmpi(fill,str)==0)
	   {
	   cout<<"you have guessed the right word:"<<endl;
	    puts(fill);
	   cout<<endl;
	   cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
	   getch();

	   break;
	   }

	if(ctr==0)
	   {cout<<"you have lost the game"<<endl;
	   cout<<"the word was: "<<str<<endl;
	   cout<<"press any key to continue"<<endl;
	   getch();


	   break;
	   }




     }
if(ctr==0)
   {
    return 0;


   }


}


int cforb(char x[7])//check for spaces
{int flag=0;
for(int i=0;x[i]!='\0';i++)
     {
	 if(x[i]=='_')
	    {
	     flag=1;
	    }

     }

return flag;
}






void playwithcomp()
{
 clrscr();

 ofstream fout;
 fout.open("text.txt");
 fout<<"a"<<"b"<<"c"<<"d"<<"e"<<"f"<<"g"<<"h"<<"i"<<"j"<<"k"<<"l"<<"m"<<"n"<<"o"<<"p"<<"q"<<"r"<<"s"<<"t"<<"u"<<"v"<<"w"<<"x"<<"y"<<"z";
 fout.close();
 int index;
 int n; char fill[7];
 char string[26];
 char ch,y;
 cout<<"\n pls specify length";
 cin>>n;
 for(int i=0;i<n;i++)
     {fill[i]='_' ;



     }
 fill[i]='\0';
 fstream f;
 char alp,letter;
 double ctr=0;
 int times=0;
 int tries=6;
 f.open("text.txt",ios::in|ios::out|ios::app);
 while(!f.eof()&&ctr<=26)
  {
    f>>letter;
    string[ctr]=letter;
    ctr++;
  }
//int x=0;
while(1)
{ clrscr();
  randomize();
  alp=string[random(27)];
  draw(tries);

  cout<<alp;
  cout<<"\n please enter y if the letter is present in the word";
  cin>>ch;
 if(ch=='y'||ch=='Y')
 {
  cout<<"\n how many times does it occur";
  cin>>times;

  for(int j=0;j<times;j++)
  {
   cout<<"\n enter the place where the letter is present"<<endl;
   cin>>index;
   fill[index-1]=alp;
  }
cout<<fill<<endl;}
else
    {tries--;
    draw(tries);
    cout<<fill<<endl;
    cout<<"YOU HAVE "<<tries<<"TRIES REMIANING"<<endl;
    cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
    getch();


    }
char ch;
if(cforb(fill)==0)
    {cout<<fill<<endl;
    cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
    getch();

    break;

    }
if(tries==0)
   {cout<<"you won!!!"<<endl;
   cout<<"PRESS ANY KEY TO CONTINUE"<<endl;
   getch();
    break;
   }

}
cout<<endl;
//cout<<fill;
}


void hangman()
{
char words[100][20];
double ctr=0;
fstream f;
char x[20];
f.open("janam.txt",ios::in|ios::out|ios::app);
while(!f.eof()&&ctr<=100)
  {f>>x;
  strcpy(words[ctr],x);
  ctr++;}
f.close();



char c[20];
randomize();
play(words[random(100)]);


}





















































class player
{
public:char password[10];
char username[10];
void getpass(char password[10]);
void getdata()
{cout<<"enter usenrame"<<endl;
gets(username);
cout<<"enter password" <<endl;
getpass(password);
}
//void writeto()
void dispdata()
{cout<<"username:"<<username<<endl;
cout<<"password:"<<password<<endl;

}
};
void player::getpass(char password[10])
{char ch;
int i=0;
while((ch=getch())!='\r')
{  password[i]=ch;

	++i;

	if(password[i-1]==8)  //backspace preocessing
	   {i-=2;
	clrscr();
	for(int m=0;m<i;m++)
	       {cout<<"*";
	       }
	    }
	else{cout<<"*";
       }

     }
password[i]='\0';
}

int check(player p)
{int flag =0;

player op;
fstream fin;
fin.open("book.dat",ios::in);

while(fin.read((char*)&op,sizeof(op)))
      { if(strcmpi(p.username,op.username)==0)
	     {flag=1;
	     if(strcmpi(p.password,op.password)==0)
		 {return 2; //for login
		 }
	     else
		 {return 1;//used to avoid duplicate usrnames
		 }
	    }

      }

   if (flag==0)
       {return 0 ;//for signup

       }
fin.seekg(0,ios::beg);
fin.close();
}


void signup(player&k)
{clrscr();
cout<<"\t\t------------------------------";
cout<<"\n\t\t\t     SIGNUP \n";
cout<<"\t\t------------------------------\n\n"<<endl;

k.getdata();
ofstream fout;
fout.open("book.dat",ios::out|ios::app);
if(check(k)==0)
    {

      fout.write((char*)&k,sizeof(k));


    }
else
{cout<<"username already exists"<<endl;
}

}
int login(player k)//to check if player exists..
{
if(check(k)==2)
{

return 1;
}

else
    {

     return 0;
    }


}
int setup(player&p)
{
int k=0;
while(k!=3)//while login not successfull
{cout<<endl;
     cout<<"\t\t------------------------------";
     cout<<"\n\t\t     MAIN MENU \n";
      cout<<"\t\t------------------------------\n\n";
cout<<"1:login" <<endl;
cout<<"2:signup"<<endl;
cout<<"3:QUIT"<<endl;


cin>>k;
if(k==1)
   {clrscr();
     cout<<"\t\t------------------------------";
     cout<<"\n\t\t     LOGIN \n";
      cout<<"\t\t------------------------------\n\n";



p.getdata();


      if(login(p)==1)
	 { cout<<"login successfull"<<endl;
	  break;

	 }
      else
	 {cout<<"login unsucessfull" <<endl;
	 cout<<"ENTER ANY KEY TO TRY AGAIN"<<endl;
	 getch();
	 }
   }
else if(k==2)
   {

    signup(p);


   }
if(k==3){
      return 0;
     }
}
}
void display()
{ifstream fin;
fin.open("book.dat");
player p;
while(fin.read((char*)&p,sizeof(p)))
     {p.dispdata();


     }
}
/*void game()

{player p2;
int x;
play:
cout<<"1: computer guesses"<<endl;
cout<<"2:you guess"<<endl;
cout<<"3:allow"<<endl;
cout<<"4:quit"<<endl;
cin>>x;
if(x==1){ clrscr();

	  playwithcomp();
	  goto play;
	     }
if(x==2){ clrscr();
	    hangman();
	     goto play;
	    }
ixf(x==3)
       {cout<<"player 2 pls " <<endl;
      if(setup(p2)==0)
	  {
	    goto play;
	  }
      else
	 {cout<<"P1:"<<endl;
	 p1.dispdata();
	 cout<<"P2:"<<endl;
	 p2.dispdata();}

	 goto play;


      }


}*/
/*char wordlist[3][10];
char wrongwords[3][10];
void play1(player q,player &a)
{ cout<<"TIME TO PLAY FOR "<<a.username<<endl;
int score=0;
for(int i=0;i<=2;i++)
      {
	if(play(wordlist[i])==0)
	    { strcpy(wrongwords[i],wordlist[i]);


	    }
	else
	    {

	      score++;

	    }
      }
cout<<endl;
cout<<"SCORE:"<<score<<endl;
cout<<"WRONG WORDS ARE:"<<endl;
for( i=0;i<2;i++)
    {
     cout<<wrongwords[i];}
cout<<"played against"<<q.username<<endl;
}

void setwords(player p1,player&p2)//to enter the words to be simulated in the resp. player's obj....
{ cout<<p1.username<<" set the words for "<<p2.username<<endl;

for(int i=0;i<3;i++)
    { cout<<"enter word"<<endl;
      gets(wordlist[i]);


    }
}*/
void multiplayer()
     {char word[10];
     player p2;
     setup(p2);
     cout<<"ENTER WORD"<<endl;
     gets(word);
     play(word);

     }
void main()
{clrscr();
player p1;
player p2;
char word[10];
if(setup(p1)!=0)//while login succesfull
      {







      //display();

	//cout<<"p1:"<<p1.username<<endl;
	cout<<"WELCOME " <<" "<<p1.username<<endl;
	getch();
	cout<<"GAME 1:"<<endl; //user guesses words for comp
	hangman();
	getch();
	cout<<"GAME 2:"<<endl;
	getch();
	playwithcomp();//comp guess the words
	getch();
	cout<<"GAME 3:"<<endl;//old project but only one word
	cout<<"Player 2 please enter your details "<<endl;
	p2.getdata();
	cout<<"welcome "<<" "<<p2.username<<endl;
	cout<<"set word for"<<" "<<p1.username<<endl;
	gets(word);
	cout<<"time for"<<" "<<p1.username<<" "<<"to play"<<endl;
	cout<<"Press any key to continue"<<endl;
	getch();
	play(word) ;
	cout<<p1.username<<" "<<"set word for "<<" "<<p2.username<<endl;
	gets(word);
	cout<<"Time for "<<" "<<p1.username<<" "<<"to play"<<endl;
	play(word);
	}


//char word[10];

//cout<<"p1:"<<p1.username<<endl;
//cout<<"p2:"<<p2.username<<endl;
//p1.dispdata();
/*cout<<"setup player 2"<<endl;
multiplayer();*/
remove("book.dat");


getch();
}







