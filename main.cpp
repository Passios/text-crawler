#include <string> 
#include <cstring>
#include <string.h>
#include <iostream> 
#include <fstream> 
#include <vector>
#include <locale.h> 
#include <map>
#include <clocale>
#include <io.h>
#include <fcntl.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
//#include "excelword.h"

using namespace std; 
fstream inputtext;

char *locale = setlocale(LC_ALL, "Greek"); //� LOCAL �������� ���������� ��� ��� ��� ������������ ��� ��� ������������ ��������� ����������
 class ExcelS //� ExcelS �������� ����� ��� ��� ������� ��� �������� ���� ����� CSV ������� ��� ��� ��������� ������ ��� �������
{
	protected:
		string exS;  //������ ���������� ����� STRING
	public:
		void readExcelSData(ExcelS &exS); //� ������� ���� �� �������� �������� ��� �� �� ����� �� ������ ����� STRING
		void printExcelSData(void);	//� ������� ���� �� ��������� �������� �� ����� ��� ����� ��P
	//	bool operator== (const ExcelS &);
	
};

void ExcelS::readExcelSData(ExcelS &exS)
{
	char *locale4;

    locale4 = setlocale(LC_ALL, "Greek");
	inputtext.open("WORDS.txt");	//� inputtext ����� ����������� ����� FSTREAM ��� ��������� �� ������ ��������� ��� ������������� ��� ��� ����� Word
	
	if (!inputtext) perror("File not found "); //�� ��� ������� ������ ������
	else
		cout << "������� ������� �������!" << endl;

	for (int r = 0; r < 100; r++) //���������� �� �������� ��� � ������
	
	{
		inputtext >> ExcelS::exS[r];
		
	}
	inputtext.close();

}
void ExcelS::printExcelSData(void) //�� ���� ��� ������ �� ��������� ��� ������ ��� �� ����������� ��� ���� �����
{
	char *locale6;

    		locale6 = setlocale(LC_ALL, "Greek");
	//cout << word[r] << endl;
			FILE *fp;
 			char *file= "excelWords.csv"; //��� ����� ���� �� �������� ��� ��������� ��� ������

 

 			ofstream fl(file);
 			if (!fl) {
 			cerr << "Cannot open file" << endl;
 //return;
 			}
            static const char filename[] = "WORDS.txt"; //��� ���� �� ����� ��� ������������� ��� ��� ����� Word �� ���������� ��������
  			ifstream input(filename);
  			if (!input) //��� ��� ������� ������ ������
  			{
    			cout << "Error opening data file " << filename << "\n";
    			//return 1;
  			}
  			map<string, unsigned int> word_data; //���� ��P ������� ��� ������ ��� ���� �� �� ������ ��� ��� ������ ��������� (���������)
  			string word; 
  			while (input >> word) //������� ��� ���� ��� �� ������ �� ��������� ����� STRING
  			{
     			if (word_data.find(word) != word_data.end()) //������� ��� ���� ������ ��� ����� ��� �������
     			{
       				word_data[word]++; 
    			 }
     			else
     			{
      				 word_data[word] = 1;
     			}
  			}
  			cout<<"-������� ���������� ������ ��������-"<<endl;
  			fl<<"-������� ���������� ������ ��������-"<<endl;
  			fl << "���������" << " " << "���� " << "\n";
  			cout<< "���������" << " " << "���� " << "\n";
  			map<string, unsigned int>::iterator iter; //� ITERATOR �� ����� ��������� ���� ����
  			for (iter = word_data.begin(); iter != word_data.end(); ++iter) //��� ��� ���� ��� ����� ��� �� ����� �������� ��� ������� �� ������ ��� ������������
  			{
  				fl << iter->second << "\t" << "\t" << "  " << iter->first << "\n"; //�������� ��� ������
  			
  				
				cout<<"===================================="<<endl;
   				cout << iter->second << "\t" << "\t" <<  iter->first << "\n"; //����������� ���� �����
				cout<<"===================================="<<endl;
  			}

  			input.close(); //�������� ������ 
			fl.close();  //�������� ������ 
		
	
}


 class Excel  //� Excel �������� ����� ��� ��� ������� ��� �������� ���� ����� CSV ������� ��� ��� ��������� �������� ��� �������
{
	protected:
		string ex; 
	public:
		void readExcelData(Excel &ex); //������� ��� ��������
		void printExcelData(void); //������� ��� �������� ��� �������
		//bool operator== (const Excel &);
	
};
//bool Excel::operator== (const Excel &x) 
//{
//    if (x.ex!='\0' ) 
//        return false;
//       
//    else
//        return true;
    
//}
void Excel::readExcelData(Excel &ex)
{
	char *locale4;

    locale4 = setlocale(LC_ALL, "Greek"); //������ ��� ���������� ����������
	inputtext.open("syllabus.txt"); //inputtext ����������� ����� FSTREAM, ������� syllabus.txt ���� �� ���������� ��������
	
	if (!inputtext) perror("File not found "); //������ ������ ��� ��� �������
	else
		cout << "������� ���������� �������!" << endl;

	for (int r = 0; r < 100; r++)
	
	{
		inputtext >> Excel::ex[r]; //�������� STRING ��� �� ������,�������� �� ������ STRING
		
	}
	inputtext.close(); //�������� �������

}
void Excel::printExcelData(void) //�� ���� ��� ������ �� ��������� ��� ������ ��� �� ����������� ��� ���� �����
{
	char *locale6;

    		locale6 = setlocale(LC_ALL, "Greek"); //��� ���������� ����������

			FILE *fp;
 			char *file= "excelSyllabus.csv"; //�� ���� �� ������ �� �������� ��� ��������� ��������

 

 			ofstream fl(file);
 			if (!fl) {
 			cerr << "Cannot open file" << endl;
 
 			}
            static const char filename[] = "syllabus.txt"; //��� ���� �� ������ ��� �������� ��� ��� ����� Syllabus �� ���������� ��������
  			ifstream input(filename);  
  			if (!input) //������ ������ ��� ��� �������
  			{
    			cout << "Error opening data file " << filename << "\n";
    			
  			}
  			map<string, unsigned int> word_data; //����������� �� ���� ����� �� ��� ����� ExcelS ME THN DOMH MAP
  			string word;
  			while (input >> word)
  			{
     			if (word_data.find(word) != word_data.end())
     			{
       				word_data[word]++;
    			 }
     			else
     			{
      				 word_data[word] = 1;
     			}
  			}
  			cout<<"-������� ���������� �������� ��������-"<<endl;
  			fl<<"-������� ���������� �������� ��������-"<<endl;
  			fl << "���������" << " " << "������� " << "\n";
  			cout<< "���������" << " " << "������� " << "\n";
  			map<string, unsigned int>::iterator iter;
  			for (iter = word_data.begin(); iter != word_data.end(); ++iter)
  			{
  				fl << iter->second << "\t" << "\t" << "\t" << iter->first << "\n";
  			
  				
				cout<<"===================================="<<endl;
   				cout << iter->second << "\t" << "\t" << iter->first << "\n";
				cout<<"===================================="<<endl;
  			}

  			input.close();
			fl.close();
		
	
}

class Task //���������� ����� ������������� ��� ��� ����������� ��� ������ �������� 
{ 
	protected:
    	string text; 
    
 
	public: 
	
   		char* locale4 = setlocale(LC_ALL, "Greek");  //��������� ���������� 
   		Task() 
   		{ 
        	text = " ";  //������������ ���� ������������
        
    	} 
 
    	Task(string _text) //������������� ������
    	{ 
       		 text = _text; 
        
   		} 
 	
    
 	//Task(string _text,const char *txt_)//, string _datetime) 
    //{ 
    //	int l=strlen(txt_);
	//	txt = new char[l+1];
	//	strcpy(txt,txt_);
    //    text = _text; 
        //datetime = _datetime; 
    //}
    
    	string getText() 
    	{ 
        	return text;  //GETTER ��� ������ �������
    	} 
 
}; 
///////////////////////////////////




///////////////////////////////////
 class Word //� ����� ���� �� ������������ �� ����� ������� ��� �� ������� ��� ������ �� ����� ������
{
	private:
		string word;
	public:
	//	void readWordData(Word &word);
		void printWordData(void);  		//������� ��� �������� ������ �� ������
	//	bool operator== (const Word &);
		void printWordDataChoose(void); //������� ��� �������� ���� �����
		Word operator+= (const Word &);
	
};

void Word::printWordData(void) //������� ��� �������� ������ �� ������
{
	

	
	
			//ifstream f_in;
			fstream f_in; 	//������ ������������ ����� fstream
   		    ofstream f_out;	//������ ������������ ����� �stream ���� ��� �������
   		    char yourfile[30];
   		    cout<<"�������� �� TXT ������ ��� "<<endl; //� ������� �������� ��� ���� ������ �� �������� �� ������ ������
   		    cin>>yourfile;	//����� � ������� �� ������ 
   		    f_in.open(yourfile,ios::in);  //������� �������  ������
			//f_in.open("plaintext.txt",ios::in);
  			f_out.open("WORDS.txt",ios::out); //�� ������ WORDS.txt ����� �� ������ ������ �� �� ������ � ������� ��� �� ������� ��� ����� ��� ������
    		if(!f_in||!f_out){
       		    cout<<"ERROR\n";  //������ ������ ��� ��� �������
       			 //return -1;
   			 }
 
   			char ch;  //������ ���������� ���������
    		while(f_in.get(ch)) //��� �������� ��������� ����������� �� �� ���� ���� ��� ������� �� ������� ������ ������ �� ������ ���� ����
   			{
   				if(ch=='.' || ch==',') //��� �� �������� ���� ����� ������ ������ 
   					continue;
   				if(ch==' ')
   				{
				   //f_out.put(ch);
					f_out<<endl;
				} else{
				   
        		f_out.put(ch);}
    		}
 
    		f_in.close(); //�������� �������
    		f_out.close();	 //�������� �������

}
Word Word::operator+= (const Word &x)
{
    
    int i;
    this->	word=word+x.word;
    //for(i = 0; i < dhl; i++)
   // {
    //    dhl_math[i] += x.dhl_math[i];
//	}
	return *this;
}

void Word::printWordDataChoose(void)	//������� ��� �������� ���� �����
{
		char selectionw;
			cout<<"������ �� ���������� ��� ����; [���:1/���:2]"<<endl; 
			//cin.getline(selectionw, 2);
			cin>>selectionw;	//� ������� �� ������������� �� 1 �� ��������� ���� �� �� 2 ��� �� �������

      		if (selectionw=='1')        	
        	{
        	//	char *locale8;

   			//	locale8 = setlocale(LC_ALL, "Greek");
        		//Word word;
        		string w; //������ ���������� ���� STRING (STL)
        		cout<<"�������������� ��� ���� ���: "<<endl;
        		cin>>w; //� ������� ������������ ��� ����
        		fstream fileout;
        		fileout.open("WORDS.txt"); //��������� � ������ �� ���������� � ����� Word
        		fileout.seekg(0,ios::end); //���������� �� ������ ��� ����� ��� �������
        		fileout<< w; //��������� ��� ���� ��� ������
        		//wrd.operator+=(&w);
			}
			else if (selectionw=='2') //���  ������� ������������� �� 2 �������� ���� ��������
       		{
       			cout<<"E�����!" <<endl; 
			}
			else //if(strcmp(selectionw,'1')!=0||strcmp(selectionw,'2')!=0)
			{
				cout<<"� ������� ��� ��� �������,�������� ����! "<<endl; //��� ��� ������������� ���� �� 1 ���� �� 2 ������
			}  
}

/*

ostream& operator<<(ostream &ch,const Word &a)
{
	//ch<<"STOIXEIA ->  AM :" << a.getAM()<<"ONMATEPONYMO :"<<a.getOnomepon()<<endl;


	return ch;
} */
/////////////////////////////////////////////////////////////////////////////////

class Sentence //� ����� ��� ��������� �� ���� ������� ���������� �� ���� ��� ������
{
	private:
		char *sent[100]; //������ ������ ����� ������ ����������
		
	public:
		void readSentenceData(Sentence &sent); //������� ������ ��� �������� 
		void printSentenceData(void); //������� ��� ���������� ������ sentence.txt ��� �������� ��� ����� ��� ��������� ���� ��� �������� ���� ���� ��� ����� ����������� ���� �� �����
		void printSentenceDataChoice(void); //������� �� ��������� � ������� �������
		 
		Sentence operator+= (const Sentence &); //��� ��� ���������� � �������� ����� 
	
};
void Sentence::readSentenceData(Sentence &sent) //������� ��� �������� ���������
{
	char *locale4;
	char yourfile[30]; //� ������� �������� �� ������ ��� �� ���������� ��� �������� �� ���������
	cout<<"�������� �� TXT ������ ��� "<<endl; 
 	cin>>yourfile; //������������ ����� �������
    locale4 = setlocale(LC_ALL, "Greek"); 
	inputtext.open(yourfile); //����������� ������ FSTREAM �� ����� ��� ������
	
	if (!inputtext) perror("File not found "); //��� ��� ������� ������ ������
	else
		cout << "������� ������� �������!" << endl;
	for (int r = 0; r < 100; r++)
	
	{	
		char *locale;
		locale = setlocale(LC_ALL, "Greek");
		inputtext >> Sentence::sent[r];		 //�� ����������� �� ������ ��� ������ ���������
	}

}
void Sentence::printSentenceData(void) //� ������� ���� �� ���������� �� ����� ��������� ��� �� ������ ��� ������
{
	
	
	char *locale;
 	locale = setlocale(LC_ALL, "Greek");
 	
 		ifstream fin; 
 		fin.exceptions ( ifstream::badbit ); //���������� � BADBIT EINAI �� �I� ����������� ��� ���� (�� ����� �������� � BAD)
   		ofstream fout;
   	    char yourfile[30];
   	    cout<<"�������� �� TXT ������ ��� "<<endl; 
   	try {
		cin>>yourfile; //������������ �� ������ ��� �����  ������� �� �� "������" �� ��������� 
		fin.open(yourfile,ios::in); //������� ������� ��� ��������
  		fout.open("sentence.txt",ios::out); //������� ������� ��� �������
  		char ch;
  		int count=0;  //�������� ��� ������ �������� �������
		while(fin.get(ch)) 
   		{
   				
   			
      			
        	if (ch == '.' || ch == ',') //�������� ��� � ������ ��� �� ����� ����������� ���������
   			{
			    fout.put(ch); //�� ������ ������ � ����� ��� ������ �� ������ 
				fout<<endl;  //������� ������ ,����� ��������
				count++; /**sent[count];*/ //������� ��� ������� ���������
			} else{
				   
        		fout.put(ch); //������ ������ ���������
			}
        		
    		}
    		
    		cout<<"====================="<<endl;	
    		cout<< " ������ ���������: " <<count<<endl; //�������� ������� ��������� ��������
			cout<<"====================="<<endl;
	 }
  	catch (const ifstream::failure& e) {
   		 cout << "������ ��� ������";
 	}
    		fin.close(); //�������� ������� 
    		fout.close(); //�������� �������
    	
    		
    		//��� � ������� �� ���������� �� ����� �� ���������� ������ ������� ��� ���� ��� ������������ �� ����� ������ ��������� ���� �� ������ ��� ��������� ��� �������� 
    		
			char selectionsetence; 
			cout<<"������ �� ����������� MIA ������� [���:1/���:2]"<<endl; 
			cin>>selectionsetence; //������������ 1 ��� ����� �� ���������� ������ 2 
			

      		if (selectionsetence=='1') 
        	{ 



        		cout<<"����� ������ �������,� �������� ������ ��� �� 0!"<<endl; //������� �� ��� ������ �� �� ������ ��������� ���������� ������ ������� (� �������� ������ �� �� 0)
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line; //������������ ��� ������
   		     	
   		     	ifstream f("sentence.txt"); //��� �� ������ ������� �� ����������� � ����� ��������� �� ��������� ��������
   		     	
				
				if(!f){

					cout<< "Cannot open input file!" << endl; //��� ��� ������� ������ ������ 
					//return 1;
				}

				int current_line = 0;          // ����� ������ ����� � 0
				while( std::getline(f,s) )     // ���������� ������� �� �� ������ ���������
				{
  					if(current_line == line){ //��� � ������ ��� ������� � ������� ����� ��� �� ��� ������� ��������� �������
  
    
   						cout<<"� ������� ��� ��������� �����: " << s<<endl;    //����������� ���� ������� ���� �����         // Display the target line
   						fstream fo;
						fo.open("listwords.txt",ios::in |ios::out | ios::binary); 
						fo<< s; //������� ��� ������� �� ��� ��� ������ ������� ���� FSTREAM
						char ch;
						cout<<"==============================" <<endl;
						cout<<" ����� ������ ��������: " <<endl; //�� ����������� ��� ����� ������ ��� ������� ��� ��������� � �������
    					cout<<"==============================" <<endl;							
						fo.seekg(0); //������� ��� ������ �� ������� ���� ���� �� ������ �� �������� ��� ������� ��� ��������� � �������
							
						int cnt=0; //�������� ��� ������ ������ ��������
    					while(fo.get(ch)) 
   						{
   							//	if(ch=='.')
   							//		continue;
   								//fo.get(ch);
   							if(ch==' ')		//��� ������ ���� ������� ��� ������ ������� ������ ����� ����� ��� �������� ������ ���� ����������� ���� �� ������
   							{
				 				  	//fo<<endl;
								cout<<endl;
								cnt++;
							}else if(ch=='.'){
								//cnt++;
   									continue; //��� ����� ��� �������� �� ������������ ����� ������,���� �� ������������ ��� �� ��������
   									
							}
							else{
				   
        						cout.put(ch);} //�� ���� ��������� (����������) �������� ��� ���������
    					}
    					cout<<endl<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" ������ ������ ��������: " << cnt <<endl; //�������� ������� ������
    					cout<<"==============================" <<endl;
    					cout<<" TE��� ������ ������ �������� " <<endl;
     					cout<<"==============================" <<endl;   						
						fo.close(); //�������� �������
						break;                     
  					}
  					current_line++;              //������ ������� ��� �� ����� ��� �� ���� �� �������������  �������
				
				}
			
	  	  		f.close(); //�������� �������
        	
       		//	continue;	
      		}
      	
       		else if (selectionsetence=='2')
       		{
       			cout<<"E����� ��� ��� ��������� ���������!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"� ������� ��� ��� �������! "<<endl;  //��� ��� ������������� ���� �� 1 ���� �� 2 ������ ������ 
			}
}
void Sentence::printSentenceDataChoice(void) //�� ���� ��� ������ ������� ���� ������ ��� ���������� �� ������� ��� ������� ��� ������ ��������� ��� ������ Sentence
{
	char selections;
	cout<<"������ �� ���������� ��� �������; [���:1/���:2]"<<endl; 
	
	cin>>selections; //� ������� ������� ��� ����� �� ������� �������

   	if (selections=='1')         //��� ������� �� 1 ����� �������	
    {
        		//Word word;
       	char s[30];
        cout<<"�������������� ��� ������� ���: "<<endl;
       	cin>>s[30]; //����������� ��� ������� ���
       	//cin.getline(s,30);
       	fstream filesent; 
       	filesent.open("sentence.txt"); //��������� � ������ �������� ��� ��������� ��� ��� ����� ���������
       	filesent.seekg(0,ios::end); //������� �� ������ ��� ����� ��� �������
       	while((strlen(s) != 0) )  
   		{ 

    		filesent << s;	//���������� ��� ������� ��� ����� ��� �������
    		cin.getline(s,30);

  		} 
  		filesent.close(); //��������� �� ������
  			 	 //delete[] s;
	}
	else if (selections=='2') 
   	{
       	cout<<"E�����!" <<endl;
	}
	else //if(strcmp(selections,'1')!=0||strcmp(selections,'2')!=0)
	{
		cout<<"� ������� ��� ��� �������! "<<endl; //��� ��� �������������� ���� �� 1 ���� �� 2 ������ ������
	}  
}

/*
fstream& operator>>(istream &ch,const Setence &a)
{
	//ch<<"STOIXEIA ->  AM :" << a.getAM()<<"ONMATEPONYMO :"<<a.getOnomepon()<<endl;


	return ch;
} */
 /*Sentence Sentence::operator+= (const Sentence &x)
{
    
    int i;
   // this->	sent=sent+x.sent;
    for(i = 0; i < 100; i++)
    {
      this->  sent[i] = sent[i] + x.sent[i];
	}
	return *this;
}	*/



////////////////////////////////////////////////////////////////////////////////////
class TaskManager //���� � ����� ����� �������� ��� ��� ���������� ��� ����� ��������
{ 
    vector<Task> tasks; //������ VECTOR �� ����������� ����� TASK (����� ��� ������������� ������������)
 
public: 
    TaskManager() 
    { 
     
    	char yourfile[30]; 
   		cout<<"�������� �� TXT ������ ��� "<<endl; //� ������� �������� �� ������ �� ����� �� ����������
   		cin>>yourfile;
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        fstream f;
        f.exceptions ( fstream::badbit );

        //cout << f.eof(); 
    try{
        char tempText[200]; 
    	fstream f(yourfile, ios::in );
        while (f.getline(tempText, 200) ) //�� ���������� �� ������������� �� ������ �� ������ ���������� ���� ��� ��� ����� ������ ��������
        { 
            Task tempTask(tempText); 
            tasks.push_back(tempTask); //�������� ���� VEKTOR ����������� �������
        } 
        f.clear(); //��������� �� 3 FLAGS 
        f.close(); //�������� ������� 
	}catch(std::exception const& e){
     cout << "������ �������: " << e.what() << endl;//H ��������� e.what() ������� ���� ���������
   }
	
    	f.clear(); //��������� �� 3 FLAGS 
        f.close(); //�������� �������  
    } 
 
    void addTask(Task t)  //������� ��� ������ ��� ������ ����������� ����� ��SK ��� �� ��������� ��� �������
    { 
    	char *locale4;
   		locale4 = setlocale(LC_ALL, "Greek");
        tasks.push_back(t); //�������� ���� ���� VECTOR
        this->saveToDisk();  //��� ������� ���� ������ saveToDisk() ��� ���������� ����� ��� �������


    } 
 
    void deleteTask(int index)  //������� ��� �������� ������������ ���������� ���� VECTOR
    { 
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        if(index < tasks.size()) 
            tasks.erase(tasks.begin() +index);  //������ �� ����������� �� ������� � ������� ���  ������� ��� ����� ����
        else 
            cout << "������ ���������,��������� �� �������� �������!" << endl;  //�� � ������� ����� ���� ������ �� ����� ����� ��� �������� ,������ ������
 
        this->saveToDisk(); //������ ������� �� ��� ������ saveToDisk() 
    } 
 
    void listTasks() // ������� ��� �������� ������ 
    { 
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        for(int i=0; i < tasks.size(); i++)  //�� ���� ��� ����� �����
        { 
            cout << "������� ������������: " << i << endl;  //�������� "������"
            cout << tasks[i].getText() << endl;   //�������� ������������
           
        } 
 
    } 
 
    void saveToDisk() //������� ��� ����������
    { 
    	char *locale4;
		char yourfile[30];
   		locale4 = setlocale(LC_ALL, "Greek");
        fstream f(yourfile, ios::out ); //���������� ������� ��� ������ ��� ������� � ������� ������������
 
        for(int i=0; i < tasks.size(); i++) 
        { 
            f << tasks[i].getText() << endl; //��� ���� ��� ������� ����� ������� ����������
          
        } 
 
        f.clear(); //���������� FLAGS
        f.close();  //�������� �������
    } 
 
}; 


void readit() //� ��������� ���� ����� ���������� ��� ���� �������� ������� ��� ��� ��������� ��� ��������� ��� ����������� ��� ���� ���� ���� ��� ������������
{ 
	char *locale;

    locale = setlocale(LC_ALL, "Greek");
    cout<<endl<<"=============================="<<endl;
    cout << " ������� ������ ��������� " << endl; 
    cout<<"=============================="<<endl;
    cout << " � �������� ����� ��� ��� �����������   " << endl; 
    cout << "�������� �� ����������  ����������, ���-" << endl; 
    cout << "��������������� ��� �� ��������  ��� �� " << endl; 
    cout << "������ ������. �� ������� ��� ������ �� " << endl;
	cout << "�������� ����� �� ����.���� ���  ������-" << endl; 
    cout << "����� ��� �������� �� ��������� ������� " << endl;
	cout << "������ �� ����� �������������� �� �����-" << endl; 
	cout << "�� ���! " << endl;  
    cout << "���� ��� ��������! " << endl << endl; 
    cout<<"=============================="<<endl;

    
}



 
void printMenu() //� ��������� ���� ������� �� ����� �����������  
{ 
	char *locale;

    locale = setlocale(LC_ALL, "Greek");
    cout<<endl<<"=============================="<<endl;
    cout<<endl<<"---------------------"<<endl;
	cout<<"   ����� ��������:   "<<endl;
	cout<<"---------------------"<<endl;
    cout << "1: �������� ��� �������" << endl; 
    cout << "2: �������� ���������" << endl; 
    cout << "3: �������� ��������" << endl; 
    cout << "4: ������" << endl;
	cout << "5: ������� EXCEL ������" << endl; 
    cout << "6: ���������" << endl;
	cout << "7: ��������" << endl; 
	cout << "8: ������� EXCEL ��������" << endl;  
    cout << "0: A��������� ��� ������" << endl << endl; 
    cout<<"=============================="<<endl;
    cout<<endl<<"--EI������ ��� ������� ���--"<<endl;
    cout<<"->";
    
}



class Syllabus //����� ��������
{
	private:
		char syl[100][4]; //��� ��� ���������� ����� ���� � ���������
	public:
	//	void readSyllabusData(Syllabus &syl);
		void printSyllabusData(void); // � ������� ���� ������� �� ������ �������� ��� �� ������ �������� ��� "�����" � �������
		void printSyllabusDataSent(void); // � ������� ���� ��������� ���� ����� ��� ����� �������� ��� ��������
		void printSyllabusDataWord(void); //� ������� ���� ��������� ���� ����� ��� ����� �������� ��� �����
		bool operator== (const Syllabus &); //� ���������� ��� == 
	
};
bool Syllabus::operator== (const Syllabus &x) 
{
    if (x.syl!='\0' ) 
        return false;
       // x.delete_start(&x);
    else
        return true;
    
}
/*
void Syllabus::readSyllabusData(Syllabus &syl)
{
	char *locale4;

    locale4 = setlocale(LC_ALL, "Greek");
	inputtext.open("plaintext.txt");
	
	if (!inputtext) perror("File not found ");
	else
		cout << "������� ������� �������!" << endl;

	for (int r = 0; r < 100; r++)
	
	{		
		for (int c = 0; c < 4; c++)
	
		{
			char *locale;
			locale = setlocale(LC_ALL, "Greek");
			if(Syllabus::syl[r][c]=='�' || Syllabus::syl[r][c] == '�' || Syllabus::syl[r][c] == '�' )
			{
				r++;
			}
			inputtext >> Syllabus::syl[r][c];
		
		}
	
		
	}

} */
void Syllabus::printSyllabusData(void) // � ������� ���� ������� �� ������ �������� ��� �� ������ �������� ��� "�����" � �������
{
	
	char yourfile[30];
   	cout<<"�������� �� TXT ������ ��� "<<endl;
   	cin>>yourfile; //� ������� ����������� �� ���� ��� ������� ��� ����� �� �� "����������" 
	char *locale;
 	locale = setlocale(LC_ALL, "Greek");
    
	ifstream f_in; 
   	ofstream f_out;	
	f_in.open(yourfile,ios::in); //������� ������� ��� �����������  �������
  	f_out.open("syllabus.txt",ios::out); //����������� ������������ ������� ofstream ,������ ��� ������� ��� ������ ��� �������
    if(!f_in||!f_out){
    	cout<<"ERROR\n"; //��� ��� �������� �� ������ ������ ������
      //return -1;
   		}
 
   			char ch; //������ ���������� ����� ���������
    		while(f_in.get(ch))
   			{
   				if(ch=='.' || ch==',') //��� ����� ������ ������ ��� �� ��������
   						continue;
        		if (ch == '�' || ch == '�' ||ch == '�' || ch == '�' || ch == '�' ||ch == '�' || ch == '�' || ch == '�' || ch == '�' ||ch == '�' || ch == '�' || ch == '�' ||ch == '�'  || ch == 'H' || ch == '�' || ch == '�' || ch == '�' ) //��� ������������ �������� ������� �����������
   				{
   				//;
				   f_out.put(ch); //��� ����� ������ ��� ������ ���� ���������� ��� �������� ��� ��������� ������ ��� ������� ����� �������� 
					f_out<<endl;
				} else{
				   
        		f_out.put(ch);} //������ �������� �������� ��� ���������
    		}
 
    		f_in.close(); //�������� �������
    		f_out.close(); //�������� �������
			
}
//////////////////////////////////////////////////////////////////////////////////////////
void Syllabus::printSyllabusDataSent(void) //������� ��� ���������� ��������
{
			char selectionsetence;
			cout<<"������ �� ����������� MIA ������� ��� ����������[���:1/���:2]"<<endl; //������ ��� ������ ��� ����� �� ���������� ������� ��� ����������
			cin>>selectionsetence; //����� ��� ������� ���
			

      		if (selectionsetence=='1') //��� �������������� 1
        	{ 
       			cout<<"����� ������ �������,� �������� ������ ��� �� 0!"<<endl; //����������� �� ���� ������ �� ��� ��������� ��� �������� ��� ������ ��� ���������
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line;
   		     	
   		     	ifstream f("sentence.txt"); //��������� �� ������ ��� ����������� � ����� Sentence
   		     
				if(!f){ 

					cout<< "Cannot open input file!" << endl; //������ ������ ��� ��� �������
				
				}

				int current_line = 0;          // � �������� ������� ������ �� �� 0
				while( std::getline(f,s) )     
				{
  					if(current_line == line){
  

   						cout<<"� ������� ��� ��������� �����: " << s<<endl;            // �������� �������� ��� �� �����������
   						
						cout<<"==============================" <<endl;
						cout<<" ����� �������� ��������: " <<endl; //��� �� ��������� � ����� �������� ��� ��������
    					cout<<"==============================" <<endl;
						int l; 
        				l=s.length(); //������� ����� ������������
        				char buf[l]; //��������� ������ ������� ���� �� �� ����� ��� �������������
        				s.c_str(); //� ������� ���� ����������� �� STRING �� CHAR*
        				for(int i=0;i<l;i++) 
        				{
        					buf[i]=s[i]; //�������� ������������� ���� ������ ��� �������������
						}							
						
						int cnt=0; //� �������� ����� �� ����� �������� ��������
    						
    					int k=0; //�� ��������� ��� ��� ���������� ��� ��������� ��� ������
    					while(k<l)  //��� �� � ����� ���������� ��� �� ����� ��� ������������� 				
   						{
   							
   							if(buf[k]=='.' || buf[k]==',') //��� ���������� ������ ������ �������� ����� ��������
   								break;
        					if (buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�'  || buf[k] == 'H' || buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ) //������� ������� �����������
   							{
   				
				  				 cout<<buf[k]; //��������� ��� ���������
								 cout<<endl; //������� ������ ������ ����� ��������
								 cnt++; //������� ������� ��������
								 
							} else{
				   
        						cout<<buf[k];} //�� ���� ��������� ���� ��������� ���������
        					k++;
    					}
    					cout<<endl;//<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" ������ �������� ��������: " << cnt <<endl; //�������� ������� ��������
    					cout<<"==============================" <<endl;
    					cout<<" TE��� ������ �������� �������� " <<endl;
     					cout<<"==============================" <<endl;   						
						//fnew.close();
						break;                     
  					}
  					current_line++;              // ������ ���������� ������� ��� ������ ������� ������
				
				}
			
	  	  		f.close(); //�������� �������
        	
       		//	continue;	
      		}
      	
       		else if (selectionsetence=='2')
       		{
       			cout<<"E����� ��� ��� ��������� ���������!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"� ������� ��� ��� �������! "<<endl; //��� � ������� ��� ������������� ���� �� 1 ��� �� 2 �������� ���������
			}
	///////////////////////////////////////////////////////	

			
}

void Syllabus::printSyllabusDataWord(void) //� ������ ���� ���������� ���� �� �������� � �������
{
	char selectionword;
			cout<<"������ �� ����������� MIA ���� ��� ����������[���:1/���:2]"<<endl; //�������� � ������� ��� ����� �� ���������� ����
			cin>>selectionword; //������������ 1 � 2 ������ �� ��� ������� ���
			

      		if (selectionword=='1') //��� ���
        	{ 
        		cout<<"����� ������ �������,� �������� ������ ��� �� 0!"<<endl;
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line; //������������ ������ ������� ��� ������� WORDS.txt ��� ������������� ���� ������ Word
   		     	
   		     	ifstream f("WORDS.txt"); //�� ������ ����� ��� ��������
   		     //	fstream fnew;
        	//	fnew.open("SylSent.txt");
				if(!f){

					cout<< "Cannot open input file!" << endl;
					//return 1;
				}

				int current_line = 0;          // � �������� ������ ��� 0
				while( std::getline(f,s) )     // ����������� � ���� ������ �� ��� ��������� ������� �� ������
				{
  					if(current_line == line){
  
    
   						cout<<"� ���� ��� ��������� �����: " << s<<endl;            // �������� �����
   						fstream fnew("SylWord.txt" , fstream::binary | ios::in | ios::out);
        				//fnew.open("SylSent.txt");
        				int l;
        				l=s.length(); //������� ������ �����
        				char buf[l]; //���������� ������ �������� ���� �� �� ������� ��� �����
        				s.c_str(); //� ������� ���� ���������� �� STRING ��  CHAR*
        				for(int i=0;i<l;i++)
        				{
        					buf[i]=s[i]; //�������� ���������� ����� ���� ������
						}
					//	fnew << s;
						char ch;
						cout<<"==============================" <<endl;
						cout<<" ����� �������� �����: " <<endl;
    					cout<<"==============================" <<endl;
													
						fnew.seekg(0);
						
						int cnt=0; //������ ������� 
    					int k=0; //������ ���������� ��� ��������� ���� ��� ��������� ��� ������
    					while(k<l)	//��� � ��������� ����� ��������� ��� ������ ��� �����	
   						{
   							
   							if(buf[k]=='.' || buf[k]==',') //��� ���������� ������ ������ ��� ������� �� �� ��������
   								continue;
        					if (buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ||buf[k] == '�' || buf[k] == 'H' || buf[k] == '�' || buf[k] == '�' || buf[k] == '�' ) //������� ������� �����������
   							{
   				//;
				  				 cout<<buf[k]; //��� ���������� ���� ��� ���� �������� ���������� ��� ���������
								 cout<<endl; //������� ������� �� �������� ����� �������� 
								 cnt++; //������ ������� ��������
								 
							} else{
				   
        						cout<<buf[k];} //������ ��������� ���������
        					k++;
    					}
    					//cout<<endl<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" ������ �������� �����: " << cnt <<endl; //�������� ������ �������� �����
    					cout<<"==============================" <<endl;
    					cout<<" TE��� ������ �������� ����� " <<endl;
     					cout<<"==============================" <<endl;   						
						fnew.close();
						break;                     // ���� current_line == line
  					}
  					current_line++;              // ������ ������� ��� ������ �� ��������� � �������
				
				}
			
	  	  		f.close(); //�������� �������
        	
       		//	continue;	
      		}
      	
       		else if (selectionword=='2')
       		{
       			cout<<"E����� ��� ��� ��������� ���������!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"� ������� ��� ��� �������! "<<endl; //��� ��� �������������� ���� 1 ���� 2
			}
	///////////////////////////////////////////////////////	

			
}
 
int main() 
{ 
	system ("chcp 1253"); //������ ��� �������� �����������
	readit(); //����� ��� �������� ������� ������ ���������, �� ����������� 1 ����
    TaskManager tm;  //������ ������������ ����� TaskManager
    int index;  //������ ������ ,�� ��������� ��� ��� ��������� ��������� ��� ��� ���� 
    char selection[7];    //������ ������ ��� ��������� �������� ������ 
    char taskName[200]; //������ ������ ��� �������� �������� ��� ������ �������
    printMenu();  //�������� �����
    cin.getline(selection, 7);  //�������� �������� ������
 

    while(strcmp(selection ,"0")!=0)  //��� ������������� 0 � ������� ������ ��� ����������
    { 
    	
        if (strcmp(selection,"1")==0)  //��� ������� �� 1 ������� � addTask() ��� �������� ��� �������
        { 
        	char *locale9;
			locale9 = setlocale(LC_ALL, "Greek");
            cout << "�������� �������� �������: " <<endl; 
            cin.getline(taskName, 200);  //������� ������������� � �������
            
 
            Task tempTask(taskName);
            tm.addTask(tempTask);  //����� ������� �������


        } 
        else if(strcmp(selection, "2") == 0)  //��� ������� �� 2 �������� � deleteTask() �� ������ ��� ������ ��� ����� �� ����� �� ���������
        { 
            cout << "�������� ����� ������ ������������: " ; 
            cin >> index; //������������ ��� ������
 			char *locale8;
			locale8 = setlocale(LC_ALL, "Greek");
            tm.deleteTask(index);  //������� � ������� ���������
        } 
        else if (strcmp(selection , "3")==0)  //��� ������� �� 3 �������� ������ ����� 
        { 
        	cout<<"�������... "	<<endl;
            tm.listTasks(); 
        } 
        else if (strcmp(selection , "4")==0)  //��� ������� �� 4 ��������� � ������ Word 
        { 
        	char *locale8;

   			locale8 = setlocale(LC_ALL, "Greek");
			Word wrd; //���������� ������������ ����� Word
			wrd.printWordData(); //������ ������� ��� ������� 
            cout<<"�������... "	<<endl;
            cout<<"ANOI��� �� ������ WORDS"<<endl;
            wrd.printWordDataChoose(); //������ ������� ��� ������� 
            //system("pause");				  
        } 
        else if (strcmp(selection , "5")==0) //��� �������������� �� 5
        { 
        		cout<<"�������... "	<<endl;
				ExcelS excS; //����������  ������������ ����� ExcelS
				excS.printExcelSData(); //����� ������� ������ ��� �������� ���������� ������
				//system("pause");
		
        }
        else if (strcmp(selection , "6")==0) //��� �������������� �� 6
        { 
			cout<<"�������... "	<<endl;
			Sentence sntc; //����������  ������������ ����� Sentence
			sntc.printSentenceData(); //����� ������� ��� ������� �������� �� ���������
			cout<<"ANOI��� �� ������ sentence"<<endl;
			sntc.printSentenceDataChoice(); //����� ������� ��� �������� ��������
		}
     	else if (strcmp(selection , "7")==0)  //��� �������������� �� 7
        { 
        

			cout<<"�������... "	<<endl;
			Syllabus syll; //���������� ����������� ����� Syllabus
			syll.printSyllabusData(); //����� ������� ������� ��� �������� �������� �� �������� 
			cout<<"ANOI��� �� ������ syllabus"<<endl;
			syll.printSyllabusDataSent(); //����� ������� ��� ���������� ��������
			syll.printSyllabusDataWord(); //����� ������� ��� ��������� �����
			//system("pause");
      }
      else if (strcmp(selection , "8")==0)  //��� �������������� �� 8
        { 
        		cout<<"�������... "	<<endl;
				Excel exc; //���������� ������������ ����� Excel
				exc.printExcelData(); //����� ������� ������ ��� �������� ���������� ��������
				//system("pause");		
		
        }

		else if (strcmp(selection, "0")==0) //��� �������������� �� 0
        { 
            exit(0);  //������ ��� ����������
        } 
        else 
        { 
        	cout<<endl;
        	cout << " ���������... " << endl;
           // cout << "����� �������. �������� ��������� ���� ";// << endl; 
        } 
 		system("pause"); //������ ��� "������ �������������" ��� ����������� ��� ������ 
 		//delete[] selection;
        printMenu(); //�������� �����
        cin.getline(selection, 7); 
        //printMenu(); 
        
    } 
    cout<<"===================================="<<endl;	
	cout<<"E�������� �� ������� ��������������!"<<endl;
	cout<<"===================================="<<endl;
// return 0; 
}
