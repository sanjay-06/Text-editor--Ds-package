#include <iostream>
#include <conio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <queue>
#include "gapbuffer.h"
#include "ternarysearchtree.h"
#include "trie.h"
#include "linkedlist.h"
#include "stack.h" 

using namespace std;

inline void welcome()
{
        	char topic_text[2000] = "\n\n\n\n\n\
                                            0        000000  00000  00   00  000000  				    \n\r\
                                           0 0         00    00      00 00     00      				    \n\r\
                                          00000        00    00000    000      00     					\n\r\
                                         00   00       00    00      00 00     00    					\n\r\
                                        00     00      00    00000  00   00    00    					\n\r\
	                                                                                       				\n\n\r\
                                        000000    000000    000000  000000   0000   00000               \n\r\
                                        00        00   00     00      00    00  00  00  00              \n\r\
                                        000000    00    00    00      00    00  00  00000               \n\r\
                                        00        00   00     00      00    00  00  00  00              \n\r\
                                        000000    000000    000000    00     0000   00   00             \
										\n\n\n\n\n\n\r                                                  BY SANJAY AND SARAVANAN \n";
	        cout<<topic_text;
		    sleep(3);
}

inline void header()
{
	const char a='\xCD';
	const char b='\xBA';
	const char c='\xC9';
	const char d='\xBB';
	const char e='\xC8';
	const char f='\xBC';
	string str0=" >new <filename>    - to create new file ";
	string str1=" >open <filename>   - to open an existing file";
	string str2=" >delete <filename> - to delete";
	string str3=" >Type list         - to view the list of files";
	string str4=" >Type #save        - to save the file ";
	string str5=" >Press escape      - to close the file";
	string str6=" >Type close        - to exit the editor";
	string margin=" ";
	string line(str3.length()+2*margin.length(),a);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t"<<c<<line<<d<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str0<<"\t "<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str1<<" "<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str2<<"\t\t "<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str3<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str4<<"\t "<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str5<<"\t "<<margin<<b<<endl;
    cout<<"\t\t\t\t\t\t"<<b<<margin<<str6<<"\t "<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<e<<line<<f<<endl;
}

inline void editing()
{
	const char a='\xCD';
	const char b='\xBA';
	const char c='\xC9';
	const char d='\xBB';
	const char e='\xC8';
	const char f='\xBC';
	 string str=" >To exit                  - type 00";
	string str0=" >To edit a line           - type 11";
	string str1=" >To edit the word         - type 22";
	string str2=" >For help with words list - type 33";
	string str3=" >Undo                     - type 44";
	string str4=" >Redo                     - type 55";
	string margin=" ";
	string line(str2.length()+2*margin.length(),a);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t"<<c<<line<<d<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str0<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str1<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str2<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str3<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str4<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<e<<line<<f<<endl;
}
inline void save()
{
	const char a='\xCD';
	const char b='\xBA';
	const char c='\xC9';
	const char d='\xBB';
	const char e='\xC8';
	const char f='\xBC';
	 string str="Are you sure want to save the file?";
	 string str1="\t    (yes or no)\t\t     ";
	 string str2="\t(type 'no' to edit)\t     ";
	string margin=" ";
	string line(str.length()+2*margin.length(),a);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t"<<c<<line<<d<<endl;
	cout<<"\t\t\t\t\t"<<b<<margin<<str<<margin<<b<<endl;
	cout<<"\t\t\t\t\t"<<b<<margin<<str1<<margin<<b<<endl;
	cout<<"\t\t\t\t\t"<<b<<margin<<str2<<margin<<b<<endl;
	cout<<"\t\t\t\t\t"<<e<<line<<f<<endl;
}

int main()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
	welcome();
	string command,fileName,x;
	fstream commands,file,fileList;
	int count=0;
	while(true)
	{
		system("cls");
		header();
		commands.open("commandlist.txt",ios::in);
		commands.seekg(0,ios::beg);
		while(getline(commands,command))
		{
			cout<<"\n   "<<command;
		}
		commands.close();
		cout<<"\n  $:";
		commands.open("commandlist.txt",ios::out | ios::app);
		cin.sync();
		getline(cin,command);
		commands<<command+"\n";
		commands.close();

			if (command.substr(0,4)=="new ")
			{
				fileName=command.substr(4,command.length())+".txt";
				system("cls");
				header();
				file.open(fileName.c_str(),ios::in);
				if (file)
				{
					cout<<"\n\n\n\n   The file already exists";
					file.close();
					sleep(2);
					continue;
				}
				file.close();
				cout<<"\n\n\n\n\n   Creating a new file -- "<<fileName<<endl;
				file.open(fileName.c_str(),ios::out);
				sleep(2);
				system("cls");
				header();
				cout<<"\n\n\t\t\t\t"<<fileName<<"\n\n";
				cin>>x;
				queue<string> input;
				while(x!="#save")
				{
					input.push(x);							//inserting every word you type into a queue
					if (cin.peek()=='\n')
					{
						file<<x+"\n";
					}
					else if (cin.peek()==' ')
					{
						file<<x+' ';
					}
					cin>>x;
				}
				file.close();
				bool mist=false;
				TST tree;
				string sq;
				string *ptr;
				cout<<endl;
				while(!input.empty())
				{
					sq=input.front();
					tree.insert1(sq.c_str());
					input.pop();
					if(tree.queueval())
						mist=true;
				}
				if (mist)
					cout<<"\n\n THESE ARE THE INCORRECT WORDS!!!\n\n";
l:				save();
				string yn;
				cin>>yn;
				transform(yn.begin(), yn.end(), yn.begin(), ::toupper);
				if(yn.compare("YES")==0)
				{
					system("cls");
					header();
					cout<<"\n\n   "<<fileName<<" is saved";
					sleep(2);
				}
				else if(yn.compare("NO")==0)
				{
					system("cls");
					header();
					cout<<"\n\n\t\t\t\t"<<fileName<<endl;
					file.open(fileName.c_str(),ios::in);
					int i,nline=1;
					char ch;
					string w,y="",z="";
					while(file.get(ch))
					{
						cout<<ch;
					}
					file.close();
					cout<<"\n\nEnter which line you want to edit: ";
					cin>>i;
					cout<<"\nType in the whole line(you can insert or delete)(use arrow keys , home button)\n\n";
					file.open(fileName.c_str(),ios::in);
					if (i==1)
					{
						bool f=true;
						while(file.get(ch))
						{
							if (ch=='\n')
							{
								f=false;
							}
							if (f)
							{
								cout<<ch;
							}
							else
							{
								z+=ch;
							}
						}
						cout<<"\r";
						cin.sync();
						getline(cin,w);
					}
					else
					{
						int f=-1;
						while(file.get(ch))
						{
							if (f==0 && ch=='\n')
							{
								++nline;
								if (nline==i)
								{
									f=0;
								}
								else if (nline>i)
								{
									f=1;
								}
							}
							switch (f)
							{
								case -1:
										y+=ch;
										break;
								case 1:
										z+=ch;
										break;
								case 0:
										cout<<ch;
										break;
							}
							if (ch=='\n')
							{
								++nline;
								if (nline==i)
								{
									f=0;
								}
								else if (nline>i)
								{
									f=1;
								}
							}
						}
						cout<<"\r";
						cin.sync();
						getline(cin,w);
					}
					file.close();
					file.open(fileName.c_str(),ios::out);
					file<<y;
					file<<w;
					file<<z;
					file.close();
					goto l; 		
				}
			}
			else if (command.substr(0,5)=="open ")
			{
				fileName=command.substr(5,command.length())+".txt";
				system("cls");
				header();
				char ch;
				string X,Y;
				Stack undoBuffer(50);
				Stack redoBuffer(50);
				file.open(fileName.c_str(),ios::in);
				if (!file)
				{
					cout<<"\n\n   The file "<<fileName<<" doesn't exist";
					sleep(2);
					continue;
				}
				cout<<"\n\n\n\n\n\tOpening the file --"<<fileName<<"\n\n";
				sleep(2);
				file.close();
l3:				file.open(fileName.c_str(),ios::in);
   				X="";
				while(file.get(ch))
				{
					X+=ch;
				} 
				file.close();
				undoBuffer.push(X);
l4:				file.open(fileName.c_str(),ios::in);
				system("cls");
				header();
				cout<<"\n\n\t\t\t\t"<<fileName<<endl;
				linkedlist list;
				string word;
				while (file>>word) 
    			{ 
    				list.insert(word); 
    			}
    			file.close();
    			file.open(fileName.c_str(),ios::in);
				while(file.get(ch))
				{
					cout<<ch;
				} 
				file.close();
				cout<<"\n\n\n\n(Press any key to edit and escape key to exit)\n\n";
				ch=getch();
				if (ch==27)
				{
					continue;
				}
				else
				{
					string str;
					editing();
					int num=0,i,nline=1;
l1:					cout<<"\nEnter your editing mode: ";
					cin>>num;
					bool x;
					string e,w,y="",z="";
					switch(num)
					{
						case 00:
								break;
						case 11:
								cout<<"\n\nEnter which line you want to edit: ";
								cin>>i;
								cout<<"\n(Type in the whole line)(you can insert or delete)(use arrow keys , home button)\n\n";
								file.open(fileName.c_str(),ios::in);
								if (i==1)
								{
									bool f=true;
									while(file.get(ch))
									{
										if (ch=='\n')
										{
											f=false;
										}
										if (f)
										{
											cout<<ch;
										}
										else
										{
											z+=ch;
										}
									}
									cout<<"\r";
									cin.sync();
									getline(cin,w);
								}
								else
								{
									int f=-1;
									while(file.get(ch))
									{
										if (f==0 && ch=='\n')
										{
											++nline;
											if (nline==i)
											{
												f=0;
											}
											else if (nline>i)
											{
												f=1;
											}
										}
										switch (f)
										{
											case -1:
													y+=ch;
													break;
											case 1:
													z+=ch;
													break;
											case 0:
													cout<<ch;
													break;
										}
										if (ch=='\n')
										{
											++nline;
											if (nline==i)
											{
												f=0;
											}
											else if (nline>i)
											{
												f=1;
											}
										}
									}
									cout<<"\r";
									cin.sync();
									getline(cin,w);
								}
								file.close();
								file.open(fileName.c_str(),ios::out);
								file<<y;
								file<<w;
								file<<z;
								file.close();
								goto l3;
l2:								case 22:cout<<"\n\nEnter the string in file in which you need to insert: ";
								cin>>str;
								x=list.search(str);
								if(x==true)
								{
									Gapbuffer s;
									string s1=s.input(str);
									list.replace(str,s1);
									list.recreate(fileName);
								}
								else
								{
									cout<<"\nword not found!!!";
									goto l2;
								}
								goto l3;
						case 33:
									Trie aut;
									cout<<"\n\nEnter any three letter or two letter for the words you need to find"<<endl;
									cout<<"\nIf you enter 'al', all the 'al'-prefix frequently used words will be printed\n"<<endl;
									cin>>str;
									aut.create(str);
									cout<<"\n\n\t\t\t\t\thave a look at the words"<<endl;
									cout<<"----------press any key to continue---------"<<endl;
									getch();
									system("cls");
									goto l3;
						case 44:
								if (undoBuffer.topp()!="NULL")
								{
									Y=undoBuffer.pop();
									redoBuffer.push(Y);
									Y=undoBuffer.topp();
									if (Y!="NULL")
									{
										file.open(fileName.c_str(),ios::out);
										file<<Y;
										file.close();
									}
								}
								goto l4;
						case 55:
								if (redoBuffer.topp()!="NULL")
								{
									Y=redoBuffer.pop();
									undoBuffer.push(Y);
									file.open(fileName.c_str(),ios::out);
									file<<Y;
									file.close();
								}
								goto l4;
						default:
								cout<<"\n\n\tINVALID COMMAND\n";
								sleep(2);
								goto l1;
					}
				}
			}
			else if (command.substr(0,7)=="delete ")
			{
				fileName=command.substr(7,command.length())+".txt";
				system("cls");
				header();
				remove(fileName.c_str());
				cout<<"\n\n\n\n\n\tThe file --"<<fileName<<"-- is deleted"<<endl;
				sleep(2);
			}
			else if (command=="list")
			{
				commands.open("commandlist.txt",ios::in);
				commands.seekg(0,ios::beg);
				system("cls");
				header();
				int i=0;
				cout<<"List of files:(press any key to exit)\n\n\n\n";
				while(getline(commands,command))
				{
					if (command.substr(0,4)=="new ")
					{
						if (i==4)
						{
							cout<<"\n\n";
							i=0;
						}
						cout<<"\t"<<command.substr(4,command.length())<<"\t\t";
						++i;
					}
				}
				commands.close();
				getch();
			}
			else if (command=="close")
			{
				exit(0);
			}
			else
			{
				system("cls");
				header();
				cout<<"\n\n\n\n\n\tINVALID COMMAND\n";
				sleep(2);
			}
	}
	return 0;
}

