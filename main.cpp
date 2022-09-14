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

char *locale = setlocale(LC_ALL, "Greek"); //г LOCAL апотекеи бибкиохгйг йаи еды тгм вягсилоиоуле циа тгм йыдийопоигсг еккгмийым ваяайтгяым
 class ExcelS //г ExcelS апотекеи йкасг циа тгм енацыцг йаи елжамисг стгм охомг CSV аявеиоу циа тгм сувмотгта кенеым сто йеилемо
{
	protected:
		string exS;  //дгкысг летабкгтгс тупоу STRING
	public:
		void readExcelSData(ExcelS &exS); //г леходос аутг ха диабафеи дедолема йаи ха та бафеи се пимайа тупоу STRING
		void printExcelSData(void);	//г леходос аутг ха елжамифеи дедолема ле вягсг тгс долгс лаP
	//	bool operator== (const ExcelS &);
	
};

void ExcelS::readExcelSData(ExcelS &exS)
{
	char *locale4;

    locale4 = setlocale(LC_ALL, "Greek");
	inputtext.open("WORDS.txt");	//г inputtext еимаи амтийеилемо тупоу FSTREAM йаи амоицоуле то аявеио пяотасеым поу дглиоуяцеитаи апо тгм йкасг Word
	
	if (!inputtext) perror("File not found "); //ам дем амоинеи лгмула кахоус
	else
		cout << "епитувг амоицла аявеиоу!" << endl;

	for (int r = 0; r < 100; r++) //диабафоуле та дедолема апо т аявеио
	
	{
		inputtext >> ExcelS::exS[r];
		
	}
	inputtext.close();

}
void ExcelS::printExcelSData(void) //се аутг тгм леходо ха паяацоуле йаи аявеио йаи ха елжамисоуле йаи стгм охомг
{
	char *locale6;

    		locale6 = setlocale(LC_ALL, "Greek");
	//cout << word[r] << endl;
			FILE *fp;
 			char *file= "excelWords.csv"; //сто аявеи ауто ха цяаьоуле тгм сувмотгта тым кенеым

 

 			ofstream fl(file);
 			if (!fl) {
 			cerr << "Cannot open file" << endl;
 //return;
 			}
            static const char filename[] = "WORDS.txt"; //апо ауто то аявеи поу дглиоуяцгхгйе апо тгм йкасг Word ха амткгсоуле дедолема
  			ifstream input(filename);
  			if (!input) //еам дем амоинеи лгмула кахоус
  			{
    			cout << "Error opening data file " << filename << "\n";
    			//return 1;
  			}
  			map<string, unsigned int> word_data; //долг лаP бафоуле сам ояисла тгм кенг ап то аявеио йаи том аяихло елжамисгс (сувмотгта)
  			string word; 
  			while (input >> word) //бафоуле тгм кенг апо то аявеио се летабкгтг тупоу STRING
  			{
     			if (word_data.find(word) != word_data.end()) //екецвос еам евеи жтасеи сто текос тоу аявеиоу
     			{
       				word_data[word]++; 
    			 }
     			else
     			{
      				 word_data[word] = 1;
     			}
  			}
  			cout<<"-пимайас сувмотгтас кенеым йеилемоу-"<<endl;
  			fl<<"-пимайас сувмотгтас кенеым йеилемоу-"<<endl;
  			fl << "епамакгьг" << " " << "кенг " << "\n";
  			cout<< "епамакгьг" << " " << "кенг " << "\n";
  			map<string, unsigned int>::iterator iter; //о ITERATOR ха йамеи пяосекасг стгм долг
  			for (iter = word_data.begin(); iter != word_data.end(); ++iter) //апо тгм аявг тгс долгс еыс то текос елцамисг йаи цяаьило се аявеио тоу пеяиеволемоу
  			{
  				fl << iter->second << "\t" << "\t" << "  " << iter->first << "\n"; //цяажоуле сто аявеио
  			
  				
				cout<<"===================================="<<endl;
   				cout << iter->second << "\t" << "\t" <<  iter->first << "\n"; //елжамифоуле стгм охомг
				cout<<"===================================="<<endl;
  			}

  			input.close(); //йкеисило аявеио 
			fl.close();  //йкеисило аявеио 
		
	
}


 class Excel  //г Excel апотекеи йкасг циа тгм енацыцг йаи елжамисг стгм охомг CSV аявеиоу циа тгм сувмотгта суккабым сто йеилемо
{
	protected:
		string ex; 
	public:
		void readExcelData(Excel &ex); //леходос циа диабасла
		void printExcelData(void); //леходос гиа ейтупысг йаи цяаьило
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

    locale4 = setlocale(LC_ALL, "Greek"); //емтокг циа еккгмийоус ваяайтгяес
	inputtext.open("syllabus.txt"); //inputtext амтийеилемо тупоу FSTREAM, амоицла syllabus.txt опоу ха амткгсоуле дедолема
	
	if (!inputtext) perror("File not found "); //лгмула кахоус еам дем амоинеи
	else
		cout << "епитувг дглиоуяциа аявеиоу!" << endl;

	for (int r = 0; r < 100; r++)
	
	{
		inputtext >> Excel::ex[r]; //диабасла STRING апо то аявеио,еисацыцг се пимайа STRING
		
	}
	inputtext.close(); //йкеидило аявеиоу

}
void Excel::printExcelData(void) //се аутг тгм леходо ха паяацоуле йаи аявеио йаи ха елжамисоуле йаи стгм охомг
{
	char *locale6;

    		locale6 = setlocale(LC_ALL, "Greek"); //циа еккгмийоус ваяайтгяес

			FILE *fp;
 			char *file= "excelSyllabus.csv"; //се ауто то аявеио ха енацоуле тгм сувмотгта суккабым

 

 			ofstream fl(file);
 			if (!fl) {
 			cerr << "Cannot open file" << endl;
 
 			}
            static const char filename[] = "syllabus.txt"; //апо ауто то аявеио поу аяавхгйе апо тгм йкасг Syllabus ха амткгсоуле дедолема
  			ifstream input(filename);  
  			if (!input) //лгмула кахоус еам дем амоинеи
  			{
    			cout << "Error opening data file " << filename << "\n";
    			
  			}
  			map<string, unsigned int> word_data; //айокоухоуле то идио лотиб ле тгм йкасг ExcelS ME THN DOMH MAP
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
  			cout<<"-пимайас сувмотгтас суккабым йеилемоу-"<<endl;
  			fl<<"-пимайас сувмотгтас суккабым йеилемоу-"<<endl;
  			fl << "епамакгьг" << " " << "суккабг " << "\n";
  			cout<< "епамакгьг" << " " << "суккабг " << "\n";
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

class Task //дкгкымоуле йкасг дягстгяиотгта циа тгм епенеяцасиа тоу пкгяес йеилемоу 
{ 
	protected:
    	string text; 
    
 
	public: 
	
   		char* locale4 = setlocale(LC_ALL, "Greek");  //еккгмийои ваяайтгяес 
   		Task() 
   		{ 
        	text = " ";  //аявийопоигсг йемг сулбокосеияа
        
    	} 
 
    	Task(string _text) //йатасйебастгс йкасгс
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
        	return text;  //GETTER циа пкгяес йеилемо
    	} 
 
}; 
///////////////////////////////////




///////////////////////////////////
 class Word //г йкасг ахтг ха еенеяцафетаи то кгяес йеилемо йаи ха паяацеи ема аявеио ыс киста кенеым
{
	private:
		string word;
	public:
	//	void readWordData(Word &word);
		void printWordData(void);  		//леходос циа енацыцеи кенеым се аявеио
	//	bool operator== (const Word &);
		void printWordDataChoose(void); //леходос циа еисацыцг меас кенгс
		Word operator+= (const Word &);
	
};

void Word::printWordData(void) //леходос циа енацыцеи кенеым се аявеио
{
	

	
	
			//ifstream f_in;
			fstream f_in; 	//дгкысг амтийеилемоу тупоу fstream
   		    ofstream f_out;	//дгкысг амтийеилемоу тупоу Оstream ломо циа цяаьило
   		    char yourfile[30];
   		    cout<<"диакенте то TXT аявеио сас "<<endl; //о вягстгс диакецеи циа поио аявеио ха паяавхеи ме аявеио кенеым
   		    cin>>yourfile;	//бафеи о вягстгс то аявеио 
   		    f_in.open(yourfile,ios::in);  //амоицла аявеиоу  вягстг
			//f_in.open("plaintext.txt",ios::in);
  			f_out.open("WORDS.txt",ios::out); //то аявеио WORDS.txt еимаи то аявеио кенеым оу ха аяацеи г леходос поу ха еяиевеи тгм киста тым кенеым
    		if(!f_in||!f_out){
       		    cout<<"ERROR\n";  //лгмула кахоус еам дем амоинеи
       			 //return -1;
   			 }
 
   			char ch;  //дгкысг летабкгтгс ваяайтгяа
    		while(f_in.get(ch)) //осо диабафеи ваяайтгяа акцояихлийа ха се йахе йемо поу сумамта ха аккафеи цяаллг дгкадг ха цяажеи аккг кенг
   			{
   				if(ch=='.' || ch==',') //дем ха цяаьоуле стгм киста сглеиа стингс 
   					continue;
   				if(ch==' ')
   				{
				   //f_out.put(ch);
					f_out<<endl;
				} else{
				   
        		f_out.put(ch);}
    		}
 
    		f_in.close(); //йкеисило аявеиоу
    		f_out.close();	 //йкеисило аявеиоу

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

void Word::printWordDataChoose(void)	//леходос циа еисацыцг меас кенгс
{
		char selectionw;
			cout<<"хекете ма пяосхесете лиа кенг; [маи:1/ови:2]"<<endl; 
			//cin.getline(selectionw, 2);
			cin>>selectionw;	//о вягстгс ам пкгйтяокоцгсг то 1 ха пяосхесеи кенг ам то 2 дем ха еисацеи

      		if (selectionw=='1')        	
        	{
        	//	char *locale8;

   			//	locale8 = setlocale(LC_ALL, "Greek");
        		//Word word;
        		string w; //дгкысг летабкгтгс туоу STRING (STL)
        		cout<<"пкгйтяокоцгсте тгм кенг сас: "<<endl;
        		cin>>w; //о ыягстгс пкгйтяокоцеи тгм кенг
        		fstream fileout;
        		fileout.open("WORDS.txt"); //амоиноуле т аявеио оу сглиуяцгсе г йкасг Word
        		fileout.seekg(0,ios::end); //тоохетоуле тм деийтг сто текос тоу аявеиоу
        		fileout<< w; //еисацоуле тгм кенг тоу вягстг
        		//wrd.operator+=(&w);
			}
			else if (selectionw=='2') //еам  вягстгс пкгйтяокоцгсг то 2 елжамисг апка лгмулатс
       		{
       			cout<<"Eнодос!" <<endl; 
			}
			else //if(strcmp(selectionw,'1')!=0||strcmp(selectionw,'2')!=0)
			{
				cout<<"г епикоцг сас дем бяехгйе,еисацете нама! "<<endl; //еам дем пкгтяокоцгсеи оуте то 1 оуте то 2 енодос
			}  
}

/*

ostream& operator<<(ostream &ch,const Word &a)
{
	//ch<<"STOIXEIA ->  AM :" << a.getAM()<<"ONMATEPONYMO :"<<a.getOnomepon()<<endl;


	return ch;
} */
/////////////////////////////////////////////////////////////////////////////////

class Sentence //г йкасг тым пяотасеым ха евеи амакоцг кеитоуяциа ле аутг тым кенеым
{
	private:
		char *sent[100]; //дгкысг пимайа тупоу деийтг ваяайтгяым
		
	public:
		void readSentenceData(Sentence &sent); //леходос йкасгс циа диабасла 
		void printSentenceData(void); //леходос поу дглиоуяцеи аявеио sentence.txt поу апотекеи тгм киста тым пяотасеым окоу тоу йеилемоу акка евеи йаи аккес кеитоуяциес опыс ха доуле
		void printSentenceDataChoice(void); //леходос оу пяосхетеи о вягстгс пяотасг
		 
		Sentence operator+= (const Sentence &); //дем лас вяеиастгйе о текестгс аутос 
	
};
void Sentence::readSentenceData(Sentence &sent) //леходос циа диабасла дедолемым
{
	char *locale4;
	char yourfile[30]; //о вягстгс циакенеи то аявеио циа тм диалекисло тоу йеилемоу се пяотасеис
	cout<<"диакенте то TXT аявеио сас "<<endl; 
 	cin>>yourfile; //пкгйтяокоцеи омола аявеиоу
    locale4 = setlocale(LC_ALL, "Greek"); 
	inputtext.open(yourfile); //амтийеилемо йкасгс FSTREAM то аявеи тоу вягстг
	
	if (!inputtext) perror("File not found "); //еам дем амоинеи лгмула кахоус
	else
		cout << "епитувг амоицла аявеиоу!" << endl;
	for (int r = 0; r < 100; r++)
	
	{	
		char *locale;
		locale = setlocale(LC_ALL, "Greek");
		inputtext >> Sentence::sent[r];		 //та топохетоуле се пимайа тгс йкасгс пяотасеым
	}

}
void Sentence::printSentenceData(void) //г леходос аутг ха дглиоуяцеи то аявеи пяотасеым апо то аявеио тоу вягстг
{
	
	
	char *locale;
 	locale = setlocale(LC_ALL, "Greek");
 	
 		ifstream fin; 
 		fin.exceptions ( ifstream::badbit ); //оусиастийа г BADBIT EINAI ца тIс йатастасеис тым жкац (ам еимаи сгйылемг г BAD)
   		ofstream fout;
   	    char yourfile[30];
   	    cout<<"диакенте то TXT аявеио сас "<<endl; 
   	try {
		cin>>yourfile; //пкгйтяокоцеи то аявеио поу хекеи  вягстгс ма то "спасеи" се пяотасеис 
		fin.open(yourfile,ios::in); //амоицла аявеиоу циа амацмысг
  		fout.open("sentence.txt",ios::out); //амоицла аявеиоу циа цяаьило
  		char ch;
  		int count=0;  //летягтгс циа сумоко пяотасем аявеиоу
		while(fin.get(ch)) 
   		{
   				
   			
      			
        	if (ch == '.' || ch == ',') //хеыяоуле оти г текеиа йаи то йолла диавыяифоум пяотасеис
   			{
			    fout.put(ch); //ам бяехеи текеиа г йолла том цяажеи ст аявеио 
				fout<<endl;  //акканеи цяаллг ,текос пяотасгс
				count++; /**sent[count];*/ //аунамеи том летягтг пяотасеым
			} else{
				   
        		fout.put(ch); //аккиыс цяажеи ваяайтгяа
			}
        		
    		}
    		
    		cout<<"====================="<<endl;	
    		cout<< " сумоко пяотасеым: " <<count<<endl; //елжамисг пкгхоус пяотасеым йеилемоу
			cout<<"====================="<<endl;
	 }
  	catch (const ifstream::failure& e) {
   		 cout << "сжакла сто аявеио";
 	}
    		fin.close(); //йкеисило аявеиоу 
    		fout.close(); //йкеисило аявеиоу
    	
    		
    		//еды о вягстгс ха апожасисеи ам хекеи ма амафгтгсеи йапоиа пяотасг емы евеи гдг дглиоуяцгхеи то аявеи кистас пяотасеым ысте ма бкепеи тис пяотасеис тоу йеилемоу 
    		
			char selectionsetence; 
			cout<<"хекете ма амафгтгсете MIA пяотасг [маи:1/ови:2]"<<endl; 
			cin>>selectionsetence; //пкгйтяокоцеи 1 еам хекеи ма амафгтгсеи аккиыс 2 
			

      		if (selectionsetence=='1') 
        	{ 



        		cout<<"дысте аяихло цяаллгс,г аяихлгсг нейима апо то 0!"<<endl; //амакоца ле тгм цяаллг ао то аявеио пяотасеым кгйтяокоцг аяихло цяаллгс (г аяихлгсг нейима ао то 0)
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line; //пкгйтяокоцеи тгм цяаллг
   		     	
   		     	ifstream f("sentence.txt"); //апо то аявеио ятасеым оу дглиоуяцгсе г йкасг пяотасеым ха амткгсуле дедолема
   		     	
				
				if(!f){

					cout<< "Cannot open input file!" << endl; //еам дем амоинеи лгмула кахоус 
					//return 1;
				}

				int current_line = 0;          // пяытг цяаллг еимаи г 0
				while( std::getline(f,s) )     // диабафоуле цяаллес ап то аявеио пяытасеым
				{
  					if(current_line == line){ //еам г цяаллг поу диакене о вягстгс еимаи исг ле том деийтеи яосекасгс цяаллым
  
    
   						cout<<"г пяотасг поу епикенате еимаи: " << s<<endl;    //елжамифоуле стгм пяотасг стгм охомг         // Display the target line
   						fstream fo;
						fo.open("listwords.txt",ios::in |ios::out | ios::binary); 
						fo<< s; //цяажуле тгм пяотасг се ема мео аявеио дуадийо туоу FSTREAM
						char ch;
						cout<<"==============================" <<endl;
						cout<<" киста кенеым пяотасгс: " <<endl; //ха елжамисоуле тгм киста кенеым тгс яотасгс поу амафгтгсе о вягстгс
    					cout<<"==============================" <<endl;							
						fo.seekg(0); //бафоуле том деийтг ма деивмеи стгм аявг ту аявеиу оу пеяиевеи тгм пяотасг поу амафгтгсе о вягстгс
							
						int cnt=0; //летягтгс циа сумоко кенеым пяотасгс
    					while(fo.get(ch)) 
   						{
   							//	if(ch=='.')
   							//		continue;
   								//fo.get(ch);
   							if(ch==' ')		//еам бяоуле стгм пяотасг йем аккацг цяаллгс дгкадг текос кенгс йеи цяажоуле еолемг кенг айокухомтас ауто то лотибо
   							{
				 				  	//fo<<endl;
								cout<<endl;
								cnt++;
							}else if(ch=='.'){
								//cnt++;
   									continue; //сто текос тгс пяотасгс ха сумамтгсоуле сглеи стингс,отам то сгмамтгсоуле дем то цяажоуле
   									
							}
							else{
				   
        						cout.put(ch);} //се аккг пеяиптысг (ваяайтгяас) цяажоуле том ваяайтгяа
    					}
    					cout<<endl<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" сумоко кенеым пяотасгс: " << cnt <<endl; //елжамисг пкгхоус кенеым
    					cout<<"==============================" <<endl;
    					cout<<" TEкос кистас кенеым пяотасгс " <<endl;
     					cout<<"==============================" <<endl;   						
						fo.close(); //йкеисило аявеиоу
						break;                     
  					}
  					current_line++;              //аунгсг цяаллым еыс ма еимаи исг ле аутг оу пкгйтяокоцгсе  вягстгс
				
				}
			
	  	  		f.close(); //йкеисило аявеиоу
        	
       		//	continue;	
      		}
      	
       		else if (selectionsetence=='2')
       		{
       			cout<<"Eнодос апо тгм амафгтгсг пяотасеым!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"г епикоцг сас дем бяехгйе! "<<endl;  //еам дем кгйтяокоцгсеи оуте то 1 оуте то 2 лгмула кахоус 
			}
}
void Sentence::printSentenceDataChoice(void) //се аутг тгм леходо димоуле стом вягстг тгм диматотгта ма еисацеи меа пяотасг сто аявеио пяотасеым тгс йкасгс Sentence
{
	char selections;
	cout<<"хекете ма пяосхесете лиа пяотасг; [маи:1/ови:2]"<<endl; 
	
	cin>>selections; //о вягстгс еяытате еам хекеи ма еисацеи пяотасг

   	if (selections=='1')         //еам еицацеи то 1 бафеи пяотасг	
    {
        		//Word word;
       	char s[30];
        cout<<"пкгйтяокоцгсте тгм пяотасг сас: "<<endl;
       	cin>>s[30]; //кгйтяокоцеи тгм пяотасг тоу
       	//cin.getline(s,30);
       	fstream filesent; 
       	filesent.open("sentence.txt"); //амоицоуле т аявеио пятасеым поу паяавхгйе апо тгм йкасг пяотасеым
       	filesent.seekg(0,ios::end); //бафоуле тм деийтг сто текос тоу аявеиоу
       	while((strlen(s) != 0) )  
   		{ 

    		filesent << s;	//топхетоуле тгм пяотасг сто текос тоу аявеиоу
    		cin.getline(s,30);

  		} 
  		filesent.close(); //йкеимоуле то аявеио
  			 	 //delete[] s;
	}
	else if (selections=='2') 
   	{
       	cout<<"Eнодос!" <<endl;
	}
	else //if(strcmp(selections,'1')!=0||strcmp(selections,'2')!=0)
	{
		cout<<"г епикоцг сас дем бяехгйе! "<<endl; //еам дем пкгйтяокоцгсеи оуте то 1 оуте то 2 лгмула кахоус
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
class TaskManager //аутг г йкасг еимаи упеухумг циа тгм еенеяцасиа тоу кгяес йеилемоу
{ 
    vector<Task> tasks; //дгкысг VECTOR ле амтийеилема тупоу TASK (йкасг поу дглиоуяцгсале пяоуцоулемос)
 
public: 
    TaskManager() 
    { 
     
    	char yourfile[30]; 
   		cout<<"диакенте то TXT аявеио сас "<<endl; //о вягстгс диакецеи то аявеио оу хекеи ма тяопоигсеи
   		cin>>yourfile;
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        fstream f;
        f.exceptions ( fstream::badbit );

        //cout << f.eof(); 
    try{
        char tempText[200]; 
    	fstream f(yourfile, ios::in );
        while (f.getline(tempText, 200) ) //ха лпояоусале ма диалояжысоуле ма аиямеи ио оккоус ваяайтгяес акка циа ема лийяо аявеио доукеуеи
        { 
            Task tempTask(tempText); 
            tasks.push_back(tempTask); //пяосхгйг стом VEKTOR пеяиеволемо аявеиоу
        } 
        f.clear(); //йахаяифеи та 3 FLAGS 
        f.close(); //йкеисило аявеиоу 
	}catch(std::exception const& e){
     cout << "сжакла аявеиоу: " << e.what() << endl;//H сумаятгсг e.what() бяисйеи тупо сжаклатос
   }
	
    	f.clear(); //йахаяифеи та 3 FLAGS 
        f.close(); //йкеисило аявеиоу  
    } 
 
    void addTask(Task t)  //леходос поу девете сам ояисла амтийеилема тупоу таSK йаи та пяосхетеи сто йеилемо
    { 
    	char *locale4;
   		locale4 = setlocale(LC_ALL, "Greek");
        tasks.push_back(t); //пяосхесг стгм долг VECTOR
        this->saveToDisk();  //лас стекмеи стгм леходо saveToDisk() поу оусиастийа сыфеи тис аккацес


    } 
 
    void deleteTask(int index)  //леходос циа диацяажг амтийеилемым пяосхесале стгм VECTOR
    { 
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        if(index < tasks.size()) 
            tasks.erase(tasks.begin() +index);  //сбгмеи то амтийеилемо оу деивмеи о деийтгс поу  вягстгс тоу едысе тилг
        else 
            cout << "аямгсг диацяажгс,епикенате лг аподейто моулеяо!" << endl;  //ам о вягстгс дысеи тилг деийтг оу еимаи ейтос тоу лецехоус ,лгмула кахоус
 
        this->saveToDisk(); //сысило аккацым ап тгм леходо saveToDisk() 
    } 
 
    void listTasks() // леходос циа елжамисг кистас 
    { 
    	char *locale4;

   		locale4 = setlocale(LC_ALL, "Greek");
        for(int i=0; i < tasks.size(); i++)  //ао аявг еыс текос долгс
        { 
            cout << "аяихлос тяопопоигсгс: " << i << endl;  //елцамгсг "деийтг"
            cout << tasks[i].getText() << endl;   //елжамисг пеяиеволемоу
           
        } 
 
    } 
 
    void saveToDisk() //леходос циа апохгйеусг
    { 
    	char *locale4;
		char yourfile[30];
   		locale4 = setlocale(LC_ALL, "Greek");
        fstream f(yourfile, ios::out ); //апохгйеусг аккацым сто аявеио поу диакене о вягстгс пяоуцоулемос
 
        for(int i=0; i < tasks.size(); i++) 
        { 
            f << tasks[i].getText() << endl; //апо аявг еыс лецехос долгс цяаьило ваяайтгяым
          
        } 
 
        f.clear(); //йахаяислос FLAGS
        f.close();  //йкеисило аявеиоу
    } 
 
}; 


void readit() //г сумаятгсг аутг еимаи еисацыцийг йаи апка пеяиевеи одгциес циа тгм кеитуяциа тгс ежаялоцгс йаи елжамифетаи лиа жояа стгм аявг тгс летацкытисгс
{ 
	char *locale;

    locale = setlocale(LC_ALL, "Greek");
    cout<<endl<<"=============================="<<endl;
    cout << " одгциес вягсгс ежаялоцгс " << endl; 
    cout<<"=============================="<<endl;
    cout << " г ежаялоцг еимаи циа тгм епенеяцасиа   " << endl; 
    cout << "йеилемым ле еккгмийоус  ваяантгяес, сул-" << endl; 
    cout << "пеяикалбамомтаи йаи ои томислои  йаи та " << endl; 
    cout << "сглеиа стингс. то йеилемо сас пяепеи ма " << endl;
	cout << "нейимаеи памта ле йемо.йата тгм  епенея-" << endl; 
    cout << "цасиа тоу йеилемоу то пяоцяалла паяацеи " << endl;
	cout << "аявеиа та опоиа епенеяцафомтаи то йеиле-" << endl; 
	cout << "мо сас! " << endl;  
    cout << "йакг сас апокаусг! " << endl << endl; 
    cout<<"=============================="<<endl;

    
}



 
void printMenu() //г сумастгсг аутг аотекеи то лемоу кеитоуяциым  
{ 
	char *locale;

    locale = setlocale(LC_ALL, "Greek");
    cout<<endl<<"=============================="<<endl;
    cout<<endl<<"---------------------"<<endl;
	cout<<"   лемоу епикоцым:   "<<endl;
	cout<<"---------------------"<<endl;
    cout << "1: пяосхгйг сто йеилемо" << endl; 
    cout << "2: диацяажг пяосхгйгс" << endl; 
    cout << "3: елжамисг йеилемоу" << endl; 
    cout << "4: кенеис" << endl;
	cout << "5: жоятысг EXCEL кенеым" << endl; 
    cout << "6: пяотасеис" << endl;
	cout << "7: суккабес" << endl; 
	cout << "8: жоятысг EXCEL суккабым" << endl;  
    cout << "0: Aпохгйеусг йаи енодос" << endl << endl; 
    cout<<"=============================="<<endl;
    cout<<endl<<"--EIсацете тгм епикоцг сас--"<<endl;
    cout<<"->";
    
}



class Syllabus //йкасг суккабым
{
	private:
		char syl[100][4]; //дем лас вяеиастгйе йапоу аутг г летабкгтг
	public:
	//	void readSyllabusData(Syllabus &syl);
		void printSyllabusData(void); // г леходос аутг паяацеи то аявеио суккабым апо то аявеио йеилемоу поу "димеи" о вягстгс
		void printSyllabusDataSent(void); // г леходос аутг елцамифеи стгм охомг тгм киста суккабым тгс пяотасгс
		void printSyllabusDataWord(void); //г леходос аутг елжамифеи стгм охомг тгм киста суккабым тгс кенгс
		bool operator== (const Syllabus &); //г упеяжятысг тоу == 
	
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
		cout << "епитувг амоицла аявеиоу!" << endl;

	for (int r = 0; r < 100; r++)
	
	{		
		for (int c = 0; c < 4; c++)
	
		{
			char *locale;
			locale = setlocale(LC_ALL, "Greek");
			if(Syllabus::syl[r][c]=='А' || Syllabus::syl[r][c] == 'Е' || Syllabus::syl[r][c] == 'у' )
			{
				r++;
			}
			inputtext >> Syllabus::syl[r][c];
		
		}
	
		
	}

} */
void Syllabus::printSyllabusData(void) // г леходос аутг паяацеи то аявеио суккабым апо то аявеио йеилемоу поу "димеи" о вягстгс
{
	
	char yourfile[30];
   	cout<<"диакенте то TXT аявеио сас "<<endl;
   	cin>>yourfile; //о вягстгс кгйтяокоцеи то омла тоу аявеиоу поу хекеи ма то "суккабисеи" 
	char *locale;
 	locale = setlocale(LC_ALL, "Greek");
    
	ifstream f_in; 
   	ofstream f_out;	
	f_in.open(yourfile,ios::in); //амоицла аявеиоу поу кгйтяокоцеи  вягстгс
  	f_out.open("syllabus.txt",ios::out); //дглиоуявеиа амтийеилемоу йкассгс ofstream ,аявеио циа цяаьило йаи амицла тоу аявеиоу
    if(!f_in||!f_out){
    	cout<<"ERROR\n"; //еам дем амоиноум та аявеиа лгмула кахоус
      //return -1;
   		}
 
   			char ch; //дгкысг летабкгтгс тупоу ваяайтгяа
    		while(f_in.get(ch))
   			{
   				if(ch=='.' || ch==',') //еам еимаи сглеио стингс дем то цяажоуле
   						continue;
        		if (ch == 'А' || ch == 'е' ||ch == 'щ' || ch == 'ъ' || ch == 'Э' ||ch == 'о' || ch == 'А' || ch == 'Щ' || ch == '╬' ||ch == 'Е' || ch == 'И' || ch == 'О' ||ch == 'а'  || ch == 'H' || ch == 'ч' || ch == 'Г' || ch == '╧' ) //еды айоукоухоуле басийоус йамомес суккабислоу
   				{
   				//;
				   f_out.put(ch); //еам еимаи йаоиос апо аутоус тоус ваяайтгяес том цяажоуле йаи аккафоуле цяаллг сам емдеинг текос суккабгс 
					f_out<<endl;
				} else{
				   
        		f_out.put(ch);} //аккиыс цяажоуле йамомийа том ваяайтгяа
    		}
 
    		f_in.close(); //йкеисило аявеиоу
    		f_out.close(); //йкеисило аявеиоу
			
}
//////////////////////////////////////////////////////////////////////////////////////////
void Syllabus::printSyllabusDataSent(void) //леходос циа суккабисло пяотасгс
{
			char selectionsetence;
			cout<<"хекете ма амафгтгсете MIA пяотасг циа суккабисло[маи:1/ови:2]"<<endl; //яытале том вягстг еам хекеи ма амафгтгсеи пяотасг циа суккабисло
			cin>>selectionsetence; //бафеи тгм епикоцг тоу
			

      		if (selectionsetence=='1') //еам пкгйтяокоцгсеи 1
        	{ 
       			cout<<"дысте аяихло цяаллгс,г аяихлгсг нейима апо то 0!"<<endl; //айокоухоуле то идио лотибо ле тгм амафгтгсг тгс пяотасгс тгс йкасгс тым пяотасеым
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line;
   		     	
   		     	ifstream f("sentence.txt"); //амоицоуле то аявеио поу дглиоуяцгсе г йкасг Sentence
   		     
				if(!f){ 

					cout<< "Cannot open input file!" << endl; //лгмула кахоус еам дем амоинеи
				
				}

				int current_line = 0;          // г аяихлгсг цяаллым нейима ао то 0
				while( std::getline(f,s) )     
				{
  					if(current_line == line){
  

   						cout<<"г пяотасг поу епикенате еимаи: " << s<<endl;            // елжамисг пяотасгс поу ха суккабистеи
   						
						cout<<"==============================" <<endl;
						cout<<" киста суккабым пяотасгс: " <<endl; //еды ха айокухгсг г киста суккабым тгс пяотасгс
    					cout<<"==============================" <<endl;
						int l; 
        				l=s.length(); //летяале лгйос сулбоксеияас
        				char buf[l]; //дглиуяциа пимайа лецехус исоу ле то лгйос тгс сулбокосеияас
        				s.c_str(); //г леходос аутг летастяепеи то STRING се CHAR*
        				for(int i=0;i<l;i++) 
        				{
        					buf[i]=s[i]; //ейвыягсг сулбокосеияас стом пимайа поу дглиоуяцгсале
						}							
						
						int cnt=0; //о летягтгс аутос ха летяа суккабес пяотасгс
    						
    					int k=0; //ха вяеиастеи циа тгм пяоспекасг том стоивеиым тоу пимайа
    					while(k<l)  //осо то й еимаи лийяотекос апо то лгйос тгс сулбокосеияас 				
   						{
   							
   							if(buf[k]=='.' || buf[k]==',') //еам сумамтгсеи сглеио стингс сглаимеи текос пяотасгс
   								break;
        					if (buf[k] == 'А' || buf[k] == 'е' ||buf[k] == 'щ' || buf[k] == 'ъ' || buf[k] == 'Э' ||buf[k] == 'о' || buf[k] == 'А' || buf[k] == 'Щ' || buf[k] == '╬' ||buf[k] == 'Е' || buf[k] == 'И' || buf[k] == 'О' ||buf[k] == 'а'  || buf[k] == 'H' || buf[k] == 'ч' || buf[k] == 'Г' || buf[k] == '╧' ) //басийои йамомес суккабислоу
   							{
   				
				  				 cout<<buf[k]; //елжамифеи том ваяайтгяа
								 cout<<endl; //аккафеи цяаллг дгкадг текос суккабгс
								 cnt++; //аунамеи летягтг суккабым
								 
							} else{
				   
        						cout<<buf[k];} //се аккг пеяиптысг апка елжамифеи ваяайтгяа
        					k++;
    					}
    					cout<<endl;//<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" сумоко суккабым пяотасгс: " << cnt <<endl; //елжамисг пкгхоус суккабым
    					cout<<"==============================" <<endl;
    					cout<<" TEкос кистас суккабым пяотасгс " <<endl;
     					cout<<"==============================" <<endl;   						
						//fnew.close();
						break;                     
  					}
  					current_line++;              // аунгсг летабкгтгс цяаллым еыс аяихло цяаллгс вягстг
				
				}
			
	  	  		f.close(); //йкеисило аявеиоу
        	
       		//	continue;	
      		}
      	
       		else if (selectionsetence=='2')
       		{
       			cout<<"Eнодос апо тгм амафгтгсг пяотасеым!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"г епикоцг сас дем бяехгйе! "<<endl; //еам о вягстгс дем кгйтяокоцисеи оуте то 1 уте то 2 елцамисг лгмулатос
			}
	///////////////////////////////////////////////////////	

			
}

void Syllabus::printSyllabusDataWord(void) //г лехдос аутг суккабифеи кенг оу амафгтеи о вягстгс
{
	char selectionword;
			cout<<"хекете ма амафгтгсете MIA кенг циа суккабисло[маи:1/ови:2]"<<endl; //еяытатаи о вягстгс еам хекеи ма суккабисеи кенг
			cin>>selectionword; //пкгйтяокоцеи 1 г 2 амакца ле тгм апожасг тоу
			

      		if (selectionword=='1') //еам маи
        	{ 
        		cout<<"дысте аяихло цяаллгс,г аяихлгсг нейима апо то 0!"<<endl;
        		int cnt=1;
        		char ch1,buffer[256];
        		int line;
        		string s;
   		     	cin>>line; //пкгйтяокоцеи аяихло цяаллгс тоу аявеиоу WORDS.txt поу дглиоуяцгхгйе стгм йкассг Word
   		     	
   		     	ifstream f("WORDS.txt"); //то аявеио еимаи циа амацмысг
   		     //	fstream fnew;
        	//	fnew.open("SylSent.txt");
				if(!f){

					cout<< "Cannot open input file!" << endl;
					//return 1;
				}

				int current_line = 0;          // г аяихлгсг нейима апо 0
				while( std::getline(f,s) )     // айкоухеитаи т идио лотибо ле тгм амафгтгсг цяаллым се аявеио
				{
  					if(current_line == line){
  
    
   						cout<<"г кенг поу епикенате еимаи: " << s<<endl;            // елцамисг кенгс
   						fstream fnew("SylWord.txt" , fstream::binary | ios::in | ios::out);
        				//fnew.open("SylSent.txt");
        				int l;
        				l=s.length(); //летягсг лгйоус кенгс
        				char buf[l]; //дглиоуяциа пимайа лецехоус исоу ле то лецекос тгс кенгс
        				s.c_str(); //г леходос аутг летатяепеи то STRING се  CHAR*
        				for(int i=0;i<l;i++)
        				{
        					buf[i]=s[i]; //ейвыягсг ваяайтгяым кенгс стом пимайа
						}
					//	fnew << s;
						char ch;
						cout<<"==============================" <<endl;
						cout<<" киста суккабым кенгс: " <<endl;
    					cout<<"==============================" <<endl;
													
						fnew.seekg(0);
						
						int cnt=0; //дгкысг летягтг 
    					int k=0; //дгкысг летабкгтгс циа пяосекасг окым тым стоивеиым тоу пимайа
    					while(k<l)	//осо г летабкгтг еимаи лийяотеяг тоу лгйоус тгс кенгс	
   						{
   							
   							if(buf[k]=='.' || buf[k]==',') //еам сумамтгсеи сглеио стингс дем хекоуле ма то цяаьоуле
   								continue;
        					if (buf[k] == 'А' || buf[k] == 'е' ||buf[k] == 'щ' || buf[k] == 'ъ' || buf[k] == 'Э' ||buf[k] == 'о' || buf[k] == 'А' || buf[k] == 'У' ||buf[k] == 'Е' || buf[k] == 'И' || buf[k] == 'О' ||buf[k] == 'а' || buf[k] == 'H' || buf[k] == 'ч' || buf[k] == 'Г' || buf[k] == '╧' ) //басийои йамомес суккабислоу
   							{
   				//;
				  				 cout<<buf[k]; //еам сумамтгсеи емам апо тоус паяапамы ваяайтгяес том елцамифеи
								 cout<<endl; //аккацеи цяаллгс оу сглаимеи текос суккабгс 
								 cnt++; //аунгсг летягтг суккабым
								 
							} else{
				   
        						cout<<buf[k];} //аккиыс елцамифеи ваяайтгяа
        					k++;
    					}
    					//cout<<endl<<endl;
    					cout<<"==============================" <<endl;
    					cout<<" сумоко суккабым кенгс: " << cnt <<endl; //елжамисг кгхоус суккабым кенгс
    					cout<<"==============================" <<endl;
    					cout<<" TEкос кистас суккабым кенгс " <<endl;
     					cout<<"==============================" <<endl;   						
						fnew.close();
						break;                     // отам current_line == line
  					}
  					current_line++;              // аунгсг цяаллым еыс цяаллг оу амафгтгсе о вягстгс
				
				}
			
	  	  		f.close(); //йкеисило аявеиоу
        	
       		//	continue;	
      		}
      	
       		else if (selectionword=='2')
       		{
       			cout<<"Eнодос апо тгм амафгтгсг пяотасеым!" <<endl;
			}
			else //if(strcmp(selectionsetence,"1")!=0||strcmp(selectionsetence,"2")!=0)
			{
				cout<<"г епикоцг сас дем бяехгйе! "<<endl; //еам дем пкгйтяокоцисеи оуте 1 оуте 2
			}
	///////////////////////////////////////////////////////	

			
}
 
int main() 
{ 
	system ("chcp 1253"); //емтокг циа еккгмийг йыдийооигсг
	readit(); //йкгсг циа елжамгсг одгциым вягсгс ежаялоцгс, ха елжамистоум 1 жояа
    TaskManager tm;  //дгкысг амтийеилемоу тупоу TaskManager
    int index;  //дгкысг деийтг ,ха вяеиастеи циа тгм диажяажеи стоивеиоу апо тгм долг 
    char selection[7];    //дгкысг пимайа циа еисацысеи епикоцгс вягстг 
    char taskName[200]; //дгкысг пимайа циа еисацысг йеилемоу сто аявийо йеилемо
    printMenu();  //елжамисг лемоу
    cin.getline(selection, 7);  //еисацыцг епикоцгс вягстг
 

    while(strcmp(selection ,"0")!=0)  //еам кгйтяокоцгсеи 0 о вягстгс енодос йаи апохгйеусг
    { 
    	
        if (strcmp(selection,"1")==0)  //еам еисацеи то 1 йакеите г addTask() циа пяосхгйг сто йеилемо
        { 
        	char *locale9;
			locale9 = setlocale(LC_ALL, "Greek");
            cout << "паяайакы еисацете йеилемо: " <<endl; 
            cin.getline(taskName, 200);  //еисацеи акжаяихлгтийо о вягстгс
            
 
            Task tempTask(taskName);
            tm.addTask(tempTask);  //йкгсг леходоу йкассгс


        } 
        else if(strcmp(selection, "2") == 0)  //еам еисацеи то 2 йакеитаи г deleteTask() ле ояисла том деийтг тгс долгс оу хекеи ма диацяаьеи
        { 
            cout << "паяайакы дысте аяихло тяопопоигсгс: " ; 
            cin >> index; //пкгйтяокоцеи том деийтг
 			char *locale8;
			locale8 = setlocale(LC_ALL, "Greek");
            tm.deleteTask(index);  //йакеите г леходос диацяажгс
        } 
        else if (strcmp(selection , "3")==0)  //еам еисацеи то 3 елжамисг кистас долгс 
        { 
        	cout<<"жыятысг... "	<<endl;
            tm.listTasks(); 
        } 
        else if (strcmp(selection , "4")==0)  //еам еисацеи то 4 йеикеитаи г йкассг Word 
        { 
        	char *locale8;

   			locale8 = setlocale(LC_ALL, "Greek");
			Word wrd; //дилиоуяциа амтийеилемоу тупоу Word
			wrd.printWordData(); //йкеисг леходоу тгс йкассгс 
            cout<<"жыятысг... "	<<endl;
            cout<<"ANOIнте то аявеио WORDS"<<endl;
            wrd.printWordDataChoose(); //йкеисг леходоу тгс йкассгс 
            //system("pause");				  
        } 
        else if (strcmp(selection , "5")==0) //еам пкгйтяокоцгсеи то 5
        { 
        		cout<<"жыятысг... "	<<endl;
				ExcelS excS; //дглиоуяциа  амтийеилемоу тупоу ExcelS
				excS.printExcelSData(); //йкгсг леходоу йкасгс циа елцамисг сувмотгтас кенеым
				//system("pause");
		
        }
        else if (strcmp(selection , "6")==0) //еам пкгйтяокоцгсеи то 6
        { 
			cout<<"жыятысг... "	<<endl;
			Sentence sntc; //дглиоуяциа  амтийеилемоу тупоу Sentence
			sntc.printSentenceData(); //йкгсг леходоу циа выяисло йеилемоу се пяотасеис
			cout<<"ANOIнте то аявеио sentence"<<endl;
			sntc.printSentenceDataChoice(); //йкгсг леходоу циа еисацыцг пяотасгс
		}
     	else if (strcmp(selection , "7")==0)  //еам пкгйтяокоцгсеи то 7
        { 
        

			cout<<"жыятысг... "	<<endl;
			Syllabus syll; //дглеиуяциа амтийеилему тупоу Syllabus
			syll.printSyllabusData(); //йкгсг леходоу йкассгс циа диастасг йеилемоу се суккабес 
			cout<<"ANOIнте то аявеио syllabus"<<endl;
			syll.printSyllabusDataSent(); //йкгсг леходоу циа суккабисло пяотасгс
			syll.printSyllabusDataWord(); //йкгсг леходоу циа суккабисл кенгс
			//system("pause");
      }
      else if (strcmp(selection , "8")==0)  //еам пкгйтяокоцгсеи то 8
        { 
        		cout<<"жыятысг... "	<<endl;
				Excel exc; //дглиоуяциа амтийеилемоу тупоу Excel
				exc.printExcelData(); //йкгсг леходоу йкасгс циа елжамисг суымотгтас суккабым
				//system("pause");		
		
        }

		else if (strcmp(selection, "0")==0) //еам пкгйтяокоцгсеи то 0
        { 
            exit(0);  //енодос йаи апохгйеусг
        } 
        else 
        { 
        	cout<<endl;
        	cout << " емглеяысг... " << endl;
           // cout << "кахос епикоцг. паяайакы дойиласте нама ";// << endl; 
        } 
 		system("pause"); //емтокг циа "пацыла летацкыттисгс" циа диеуйокумсг тоу вягстг 
 		//delete[] selection;
        printMenu(); //елжамисг лемоу
        cin.getline(selection, 7); 
        //printMenu(); 
        
    } 
    cout<<"===================================="<<endl;	
	cout<<"Eкпифоуле ма леимате ийамопоиглемои!"<<endl;
	cout<<"===================================="<<endl;
// return 0; 
}
