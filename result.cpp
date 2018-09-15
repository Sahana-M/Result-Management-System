#include<fstream>
#include<iomanip>
#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
#include <cstdlib>
#include <cmath>
#include<math.h>

using namespace std;
static int columncnt = 2;
static int u;

//**********************************************STUDENT CLASS **********************************

class Student{
public:
    string rollno;
    string name;
    int sem;
    int track=0;
    float cgpa, spi;
    void gets_data();
    void shows_data();
    void s_header(char *filename){
            std :: ifstream fr;
            std :: ofstream fw;
            fr.open(filename, ios_base::in);
            if(fr.is_open()){
            fr.close();
            }
           else{
            fw.open(filename, ios_base::app);
             fw<<"ROLLNO"<<','<<"NAME"<<',';
             fw.close();
           }
    }
    void s_addheader(string n, char *filename){
            std :: ifstream fr;
            std :: ofstream fw;
            if(fr.is_open()){
            fr.close();
            }
            else{
            fw.open(filename, ios_base::app);
            fw<<n<<',';
            fw.close();
            }
    }
    void s_endheader(char *filename){
        ofstream ft;
        ft.open(filename, ios_base::app);
        ft<<"CP1"<<'\n';
        ft.close();
    }
};

//****************************************** COURSE CLASS ***********************************

class Course : public Student{
public :
    string code;
    string c_name;
    string course[50];
    float credit;
    void getc_data();
    void showc_data();
    void c_header(char *filename){
            std :: ifstream fr;
            std :: ofstream fw;
            fr.open(filename, ios_base::in);
            if(fr.is_open()){
            fr.close();
            }
           else{
            fw.open(filename, ios_base::app);
             fw<<"ROLLNO"<<','<<"NAME"<<',';
             fw.close();
           }
    }
    void c_additionalHeader(string n, char *filename){
            std :: ifstream fr;
            std :: ofstream fw;
            if(fr.is_open()){
            fr.close();
            }
            else{
            fw.open(filename, ios_base::app);
            fw<<n<<',';
            fw.close();
            }
    }
    void end_header(char *filename){
            ofstream ft;
            ft.open(filename, ios_base::app);
            ft<<"ATTENDANCE"<<','<<"TOTAL"<<','<<"GRADE"<<'\n';
            ft.close();
    }
};

//*********************************************** FACULTY CLASS *********************************


class Faculty : public Course{
public:
    string f_name;
    string dept;
    string email;
    string id;
    string password;
    char p[50];
    void getf_data();
    void showf_data();
    void verify();
    void header(){
        std :: string title = "NAME,DEPT,EMAIL,COURSES_NAME,ID,PASSWORD\n";
        std :: ifstream fr;
        std :: ofstream fw;
        fr.open("faculty.csv", ios_base::in);
        if(fr.is_open()){
            fr.close();
        }
        else{
            fw.open("faculty.csv", ios_base::app);
            fw<<title;
            fw.close();
        }
    }
    void eval();
};


//*************************************************************
void intro_main();
void intro();
void instruction();
void intro_stud();
void intro_crs();
void intro_fac();
void intro_result();
void adds_data();
void addc_data();
void addf_data();
void shows_data();
void showf_data();
void showr_data();
void showb_data();
void cal_cgpa();
void cal();

//------------------------------------------------  GET VECTOR ----------------------------------------

vector<vector<string> > getvector(const char *file_name) {

    ifstream fileName;vector<vector<string> > data;
    fileName.open(file_name);
    string d;
    int i = 0;
    while (!fileName.eof()) {
       fileName >> d;
       stringstream ss(d);
       vector <string> myVec;
       string token;
       while (getline(ss, token, ',')) {
            myVec.push_back(token);

       }
       data.push_back(myVec);
       i += 1;
    }
    data.erase(data.end() - 1);
    return data;
}


//-------------------------------------------- CSV CREATORS  --------------------------------------

void csv_create(const char *file_name, vector<vector<string> > data) {

    string str = "", temp = "";
    for (int i = 1; i < data.size()-1; ++i) {
        for (int j = 0; j < data[0].size(); ++j) {
            temp = data[i][j] + ",";
            str += temp;
            cout<<"\n\n\t\there in for";
        }
        str.erase(str.size() - 1, 1);
        str = str + '\n';
    }
    ifstream fin;
    ofstream fs;
    fs.open (file_name);
    fs << str;
    fs.close();
}


void csvgrd_create(const char *file_name, vector<vector<string> > data) {
    string str = "", temp = "";
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[0].size(); ++j) {
            temp = data[i][j] + ",";
            str += temp;
        }
        str.erase(str.size(), 1);
        str = str + '\n';
    }
    ifstream fin;
    ofstream fs;
    fs.open (file_name);
    fs << str;
    fs.close();
}

//******************************************************CALCULATION PART******************************************

int g(int x){
	if(x>10)
		return 10;
	else if(x<0)
		return 0;
	else
		return x;

}

string f2s(float marks){
    int x;
x=ceil(marks);
if(x<10){
    string s="a";
    s[0]=char(x)+'0';
    return s;
}
else{
    string s="ab";int y;
    y=x%10;x=x/10;
    s[0]=char(x)+'0';
    s[1]=char(y)+'0';
    return s;
}


}
float s2f(string s){
   float marks;char c,d,e,f;
int l= s.size();
if (l==1){
    c=s[0];
    marks = int(c)-'0';
    return marks;
}
else if(l==2){
    c=s[0];d=s[1];
    marks = int (c) -'0';
    marks = (marks*10)+ int (d) -'0';
    return marks;


}
else if(l==3){
    c=s[0];d=s[2];
    marks = int (c) -'0';
    float q=float((int (d) -'0'))/10;
    marks = marks+ q;
    return marks;

}
else if(l==4){
    c=s[0];d=s[1];e=s[3];
    int a,b;
    marks = int (c) -'0';
    a = (marks*10)+ int (d) -'0';
    marks = int (e) -'0';

    float q=float(marks)/10;
    marks = a+q;
    return marks;

}

else if(l==5){
    c=s[0];d=s[1];e=s[3];f=s[4];
    int a,b;
    marks = int (c) -'0';
    a = (marks*10)+ int (d) -'0';
    marks = int (e) -'0';
    b = (marks*10)+ int (f) -'0';

    float q=float(b)/100;
    marks = a+q;
    return  marks;

}
}

//*****************************************INTRO ***************************************************



void intro(){

char c;
cout<<"\n\n\t\t***************WELCOME TO  MENU*****************";
cout<<"\n\n\t\t\t1.COURSE\n\n\t\t\t2.STUDENT\n\n\t\t\t3.FACULTY\n\n\t\t\t4.RESULT\n\n\t\t\t5.INSTRUCTIONS";
cout<<"\n\n\t\t\tENTER YOUR CHOICE:";
cin>>c;
    do{
        switch(c){
                case '1' :intro_crs();
                           break;
                case '2' : intro_stud();
                           break;
                case '3' : intro_fac();
                           break;
                case '4' : intro_result();
                           break;
                case '5' : instruction();
                           break;
                default  : break;
                }
     }while(c!='5');

}


//**************************************STUDENT *****************************************************

void intro_stud(){

char c;
cout<<"\n\n\t\t***************WELCOME TO STUDENT MENU*****************";
cout<<"\n\n\t\t\t1.ADD STUDENT DETAILS\n\n\t\t\t2.DISPLAY STUDENT DETAILS\n\n\t\t\t3.EXIT";
cout<<"\n\n\t\t\tENTER YOUR CHOICE:";
cin>>c;
    do{
        switch(c){
                case '1' : adds_data();
                       break;
                case '2' : shows_data();
                       break;
                case '3' : intro();
                default  : intro_stud();
                }
     }while(c!='3');

}

//--------------------------------------GET STUDENT


void Student:: gets_data(){
char batch[20];
Student s;
int no,i=0;
ofstream outfile;
cout<<"\n\n\t\t\t****WELCOME TO STUDENTS DATA ENTRY****\n";
cout<<"\n\n\t\tPlease enter the BATCH and DEPARTMENT of the students\n\n\t\te.g: 16_CSE (BATCH 2016, DEPT CSE):\t";

cin>>batch;
strcat(batch , "students");
strcat(batch, ".csv");
s.s_header(batch);
outfile.open(batch, ios_base ::app);

cout<<"\n\n\t\tEnter the no. of students in this batch:\n\n\t\t";
cin>>no;
cout<<"\n\nROLLNO NAME";
while(i<no){
    cout<<"\n----------------------\n";
    cin>>rollno;
    cin>>name;
    outfile<<rollno<<','<<name<<'\n';
    i++;
}
outfile.close();
}

//------------------------------------------SHOW STUDENT


void shows_data(){

    int i,j,c;
    char k[20];
    vector<vector<string> > s = getvector("total.csv");
    cout<<"\n\n\t\tENTER THE BATCH TO DISPLAY RECORDS";
    for(i=0; i<s.size(); ++i){
        cout<<"\n\n\t\t"<<i+1<<"."<<s[i][0];
    }
    cin>>k;
    strcat(k,"students.csv");
    cout<<"\n\n";
    vector<vector<string> > f = getvector(k);
    for(i=0; i<f[0].size(); ++i){
        cout<<f[0][i]<<"     ";
    }
    cout<<"\n----------------------------------------------------------------------\n";
    for(i=1;i<f.size(); ++i){
        for(j=0;j<f[0].size(); ++j){
            cout<<f[i][j]<<"\t  ";
        }
        cout<<"\n\n";
    }
    cout<<"\n\n\t\tDO YOU WANT TO SEE MORE DATA?     0/1";
    cin>>u;
    if(u==0){
        intro_stud();
    }
    else{
        shows_data();
    }
}


//**************************************** COURSE *****************************************************************

void intro_crs(){
char c;
cout<<"\n\n\t\t***************WELCOME TO COURSE MENU*****************";
cout<<"\n\n\t\t\t1.ADD COURSE DETAILS\n\n\t\t\t2.EXIT";
cout<<"\n\n\t\t\tENTER YOUR CHOICE:";
cin>>c;
    do{
        switch(c){
                case '1' : addc_data();
                       break;
                case '2' : intro();
                default  : intro_crs();
                }
     }while(c!='3');

}


// ------------------------------------ GET COURSE
void Course :: getc_data(){
        int i,n;
Course crs;
Student s;
char batch_nmextra[10], sub[10];
ofstream outfile, outfile1,outfile2;
cout<<"\n\n\t\tEnter the Batch for which you want to create the course\t:";
cin>>batch_nmextra;
outfile.open("total.csv", ios_base::app);
outfile<<batch_nmextra<<',';
strcpy(sub,batch_nmextra);
strcat(sub,"students");
strcat(sub,".csv");
s.s_header(sub);


cout<<"\n\n\t\tHow many courses do you want to add?\t:";
cin>>n;
for(i=0;i<n;i++){
    char crs_file[10];
    cout<<"\n\n\t\tEnter the "<<i+1<<" course code\t:";
    cin>>crs_file;
    s.s_addheader(crs_file,sub);
    outfile<<crs_file<<',';
    strcat(crs_file, ".csv");
    outfile1.open(crs_file, ios_base::in);
    crs.c_header(crs_file);
    outfile1.close();
    }
    s.s_endheader(sub);
    outfile<<'\n';
outfile.close();
cout << "\nDo u want to add more courses ? 0/1";

           	 cin >> u;
        if(u==0){
            intro_crs();
        }
        else{
            getc_data();
        }

}

//***************************************** FACULTY ***************************************************************


void intro_fac(){

Faculty f;
f.header();
char c;
cout<<"\n\n\t\t***************WELCOME TO FACULTY MENU*****************";
cout<<"\n\n\t\t\t1.DISPLAY FACULTY DETAILS\n\n\t\t\t2.SET EVAUATION PATTERN\n\n\t\t\t3.EXIT";
cout<<"\n\n\t\t\tENTER YOUR CHOICE\t:";
cin>>c;

        switch(c){
                case '1' : showf_data();
                            break;
                case '2' :  f.eval();
                            break;
                case '3' : intro();
                default  : intro_fac();
                }

}


// -------------------------------------- GET FACULTY

void Faculty:: getf_data(){

    int  c,i;
    header();
    ofstream outfile;
	outfile.open("faculty.csv", ios_base ::app);
	vector <vector<string> > m = getvector("faculty.csv");
    cout<<"\n\n\tFaculty Name\t:";
	cin>>f_name;
	cin.ignore();
	cout<<"\n\n\tDepartment  \t:";
	cin>>dept;
	cin.ignore();
	cout<<"\n\n\tMail ID     \t: ";
	cin>>email;
    cin.ignore();
    cout<<"\n\n\tCourse codes handled with comma between more than one course\n\n\t\t\t:";
    cin.getline(p,50);
    cout<<"\n\n\tEnter your choice of ID";
    cin>>id;
    cin.ignore();
    /* for(i=1; i<m.size(); ++i){
        if(m[i][4]==id){
            cout<<"\n\n\t\tID already exits, enter another ID\n\n";
            intro_main();
            break;
        }
    }*/
    cout<<"\n\n\tEnter password";
    cin>>password;
    cin.ignore();
	outfile<<f_name<<','<<dept<<','<<email<<','<<p<<','<<id<<','<<password<<'\n';
	outfile.close();
	cout<<"DATA ADDED SUCCESSFULLY\n\n";
    intro_main();
}


// -------------------------------------  SETTING EVALIATION

void Faculty:: eval(){
    columncnt=2;
    char filename[20];
    Course crs;
    string s;
    int n,i;
    cout<<"\n\n\t\t*************WELCOME TO EVALUATION PATTERN SETTING******************";
    cout<<"\n\n\t\tEnter the course code to set evaluation pattern";
    cin>>filename;
    ofstream outfile3;
    strcat(filename,".csv");
    cout<<"\n\n\t\tHow many headings are there?";
    cin>>n;
    columncnt=columncnt+n;
    cout<<"\n\n\t\tStart entering the headings";
    for(i=0;i<n;i++){
            cin>>s;
           crs.c_additionalHeader(s, filename);
    }
    crs.end_header(filename);
    columncnt=columncnt+3;
    cout<<"\n\ncoulumn"<<columncnt;
    cout<<"\n\nFINISHED ENTERING HEADINGS";
    cout<< "\nDo u want to add more courses ? 0/1";
    cin >> u;
        if(u==0){
            intro_fac();
        }
        else{
            eval();
        }
}

// ----------------------------------------- LOGIN VERIFICATION

void Faculty :: verify(){

    int i=0,j=0,flag=0;
    string fac_id;
    string pd;
    vector<vector<string> > displayall = getvector("faculty.csv");
    cout<<"\n\n   FACULTY ID:\t"<<endl;
    cin>>fac_id;
    cout<<"\n\n   PASSWORD:\t"<<endl;
    cin>>pd;
    for(i=1;i<displayall.size();++i){
        if(displayall[i][4]==fac_id){
           if(displayall[i][5]==pd){
                cout<<"\n\n\t\tLogin successful";
                flag=1;
                break;
            }
        break;
        }
    }
    if(flag==0){
        cout<<"\n\n\t\tWRONG ID/PASSWORD TRY AGAIN!!";
        intro_main();
    }
    else{
        intro();
    }
}


//------------------------------------------- SHOW FACULTY

void showf_data(){

    int i,j;
    vector<vector<string> > f = getvector("faculty.csv");
    cout<<"\n\n";
    for(i=0; i < f[0].size()-2; ++i){
        cout<<f[0][i]<<"        ";
    }
    cout<<"\n--------------------------------------------------------------\n";
    for(i=1;i<f.size(); ++i){
        for(j=0;j<f[0].size()-2; ++j){
            cout<<f[i][j]<<"\t     ";
        }
        cout<<"\n\n";
    }
    cout<<"\n\n\t\tCONTINUE ? 0/1";
    cin>>u;
    if(u==0){
        intro_fac();
    }
    else{
        showf_data();
    }
}


//******************************************** RESULT *************************************************************


void intro_result(){

    char c;
    cout<<"\n\n\t\t****************WELCOME TO RESULT MENU*****************";
    cout<<"\n\n\t\t1.CALCULATE COURSE RESULT\n\n\t\t2.CALCULATE BATCH RESULT\n\n\t\t3.VIEW COURSE RESULT\n\n\t\t4.VIEW BATCH RESULT\n\n\t\t5.EXIT";
    cout<<"\n\n\t\tENTER YOUR CHOICE\t:";
    cin>>c;
    do{
        switch(c){
            case '1'  : cal();
                        break;
            case '2'  : cal_cgpa();
                        break;
            case '3'  : showr_data();
                        break;
            case '4'  : showb_data();
                        break;
            case '5'  : intro();
            default   : intro_result();
        }
    }while(c!='3');
}


// ---------------------------------------------- SHOW RESULT

void showb_data(){

    int i,j,c,l;
    char k[20];
    vector<vector<string> > s = getvector("total.csv");
    for(i=0; i<s.size(); ++i){
        cout<<"\n\n\t\t"<<i+1<<"."<<s[i][0];
    }
    cout<<"\n\n\t\tENTER YOUR CHOICE\t:";
    cin>>l;
    strcpy(k,s[l-1][0].c_str());
    strcat(k,"students.csv");
    vector<vector<string> > f = getvector(k);
    cout<<"\n\n";
    for(i=0;i<f[0].size(); ++i){
       cout<<f[0][i]<<"    ";
    }
    for(i=1;i<f.size(); ++i){
            cout<<"\n\n";
        for(j=0;j<f[0].size(); ++j){
            cout<<f[i][j]<<"\t ";
        }

    }
    cout<<"\n\n\t\tDO YOU WANT TO SEE MORE DATA?     0/1";
    cin>>u;
    if(u==0){
        intro_result();
    }
    else{
        showb_data();
    }
}



void showr_data(){
    int l,i,j;
    char k[10];
    vector<vector<string> > s = getvector("total.csv");
    cout<<"\n\n\t\tAVAILABLE COURSES ";
    for(i=0; i<s.size(); ++i){
        for(j=1; j<s[0].size(); ++j){
            cout<<"\n\t\t"<<i+1<<".  "<<s[i][j];
        }
    }
    cout<<"\n\t\tENTER THE COURSE CODE : ";
    cin>>k;
    strcat(k, ".csv");
    cout<<"\n\n";
    vector<vector<string> > v = getvector(k);
    for(i=0; i< v[0].size(); ++i){
        cout<<v[0][i]<<"   ";
    }

    for(i=1; i<v.size(); ++i){
            cout<<"\n\n";
        for(j=0; j<v[0].size(); ++j){
            cout<<v[i][j]<<"\t ";
        }
    }

}
//*********************************************** FUCNTIONS TO GET DATA ********************************


void adds_data(){
Student stud;
stud.gets_data();
cout<<"\n\n\t\t\tDATA FILLED SUCCESSFULLY";
cin.ignore();
intro_stud();
}

void addc_data(){
Course crs;
crs.getc_data();
cout<<"\n\n\t\t\tDATA FILLED SUCCESSFULLY";
cin.ignore();
intro_crs();
}

void addf_data(){
Faculty f;
f.getf_data();
cout<<"\n\n\t\t\tDATA FILLED SUCCESSFULLY";
cin.ignore();
intro_fac();

}


// ----------------------------------------     CGPA    -------------------------------------------------


void cal(){

    string batchnme, coursenme;
    int i,j,k;
    ofstream outfile;
    vector< vector<string> > ter = getvector("total.csv");
    cout<<"\n\n\t\tSelect the batch to calculate the result\t:";
    for(i=0; i<ter.size(); ++i){
        cout<<"\n\t"<<i+1<<"."<<ter[i][0];
    }

    cout<<"\n\n\t\tENTER YOUR CHOICE\t:";
    cin>>j;
    batchnme = ter[j-1][0];
    batchnme = batchnme + "students.csv";
    int n=batchnme.size();
    char b_array[n+1];
    strcpy(b_array, batchnme.c_str());
    cout<<"\n\n\tSelect the course to calculate result\t:";
    for(i=1; i<ter[0].size(); ++i){
        cout<<"\n\t"<<i<<"."<<ter[j-1][i];
    }


    cout<<"\n\n\t\tENTER YOUR CHOICE\t:";
    cin>>k;
    coursenme = ter[j-1][k];
    string sub=coursenme;
    coursenme = coursenme + ".csv";
    char c_array[n+1];
    strcpy(c_array,coursenme.c_str());
    vector < vector<string> > data = getvector(b_array);
    string str = "", temp = "";
    for (int i = 1; i < data.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            temp = data[i][j] + ",";
            str += temp;
        }
        str = str + '\n';
    }


    ifstream fin;
    ofstream fs;
    fs.open (c_array, ios_base::app);
    fs << str;
    fs.close();
    int h;
    cout<<"\n\n\t\tPLEASE NETER THE MARKS IN THE CORRESPONDING CSV FILE";
    cout<<"\n\n\t\tHAVE YOU ENTERED?0/1";
    cin>>h;
    int num,nor=0;
    int totalclm = columncnt-2;
    int gradeclm = columncnt-1;
    cout.setf(ios::fixed|ios::showpoint);
    cout<<setprecision(4);
    float total=0;float mean=0,sd=0;float grade[13]={0};
    vector<vector<string> > dat =  getvector(c_array);
    num=dat.size()-1;
    float marks[num];
    marks[num]={0};
    cout<<"\n\n\t\tSTUDENT MARKS     :";
            for(int i=1; i<dat.size() ; i++){

                    for(int j=2; j<dat[0].size()-3 ;j++){

                        marks[i-1] = marks[i-1] + s2f(dat[i][j]);

                    }

                    dat[i][totalclm] = f2s(marks[i-1]);

                    total=total+ceil(marks[i-1]);

                    cout<<"\n  "<<marks[i-1];

            }

    mean = total/num;
    grade[6]=mean;
    cout<<"\n\n\t\tMEAN\t:"<<mean<<endl;

        for(int i=0;i<num;i++){
                sd = sd + pow(marks[i]-mean,2);
        }

    sd=float(sqrt(sd/num-1));
    grade[0]=mean+ 3*sd;
    grade[1]=mean+ 2.5*sd;
    grade[2]=mean+ 2*sd;
    grade[3]=mean+ 1.5*sd;
    grade[4]=mean+ 1*sd;
    grade[5]=mean+ 0.5*sd;
    grade[12]=mean- 3*sd;
    grade[11]=mean- 2.5*sd;
    grade[10]=mean- 2*sd;
    grade[9]=mean- 1.5*sd;
    grade[8]=mean- 1*sd;
    grade[7]=mean- 0.5*sd;

            for(int i=0;i<13;i++){
                cout<<"\n\n\t\t\t"<<grade[i]<<setw(4);
            }

    int cgpa;
    cout<<"\n\t\tEnter the Grade for Mean : (10,9,8,7,6,5,4,0) "<<endl;
    cin>> cgpa;

            for(int i=0;i<num;i++){
                if(marks[i]<=grade[0] && marks[i] >=grade[1]){
                    dat[i+1][gradeclm]=f2s(g(cgpa+5));
                }
               else if(marks[i]<grade[1] && marks[i] >=grade[2]){
                    dat[i+1][gradeclm]=f2s(g(cgpa+4));
                }
               else if(marks[i]<grade[2] && marks[i] >=grade[3]){
                    dat[i+1][gradeclm]=f2s(g(cgpa+3));
                }
               else if(marks[i]<grade[3] && marks[i] >=grade[4]){
                    dat[i+1][gradeclm]=f2s(cgpa+2);
                }
               else if(marks[i]<grade[4] && marks[i] >=grade[5]){
                    dat[i+1][gradeclm]=f2s(g(cgpa+1));
                }
              else  if(marks[i]<grade[5] && marks[i] >=grade[6]){
                    dat[i+1][gradeclm]=f2s(g(cgpa));
                }
               else if(marks[i]<grade[6] && marks[i] >=grade[7]){
                   dat[i+1][gradeclm]=f2s(g(cgpa-1));
                }
                else if(marks[i]<grade[7] && marks[i] >=grade[8]){
                   dat[i+1][gradeclm]=f2s(g(cgpa-2));
                }
                else if(marks[i]<grade[8] && marks[i] >=grade[9]){
                   dat[i+1][gradeclm]=f2s(g(cgpa-3));
                }
                else if(marks[i]<grade[9] ){
                   data[i+1][gradeclm]=f2s(g(0));
                }
            }

    cout<<"\n\n";
    for(i=0;i<dat[0].size(); ++i){
        cout<<dat[0][i]<<"  ";
    }
    cout<<"\n\n";
            for(int i=1;i<dat.size();i++){
                for(j=0;j<dat[0].size();j++)
                    cout << dat[i][j]<<"\t";
                cout<<endl;
            }

    csvgrd_create(c_array,  dat);
    cout<<"\nAdded successfully \n";
    vector<vector<string> > d =  getvector(b_array);
    int index;

            for(int j=2 ; j< d[0].size() ;j++){
                if(sub == d[0][j]){
                    index=j;
                    break;
                }
            }

            for(int i = 1;i<dat.size();i++){
                for(int j=1 ; j< d.size() ;j++){
                    if(dat[i][0]==d[j][0]){
                        d[j][index]=dat[i][gradeclm];
                    }
                }
            }

    csvgrd_create(b_array,  d);
    int c;
    cout<<"\n\n\t\tEXIT   1/0  ??";
    cin>>c;
    if(c==1){
        intro_result();
    }
    else{
        cout<<"\n\n\t\t*********************************************";
    }
}


//*******************************************  CALCULATE  CGPA ***********************************


void cal_cgpa(){

    int i,j;
    string batchnme;
    vector< vector<string> > ter = getvector("total.csv");
    cout<<"\n\n\t\tSelect the batch to calculate the result\t:";
    for(i=0; i<ter.size(); ++i){
        cout<<"\n\t"<<i+1<<"."<<ter[i][0];
    }
    cout<<"\n\n\t\tENTER YOUR CHOICE\t:";
    cin>>j;
    batchnme = ter[j-1][0];
    int n= ter[j-1].size();
    float sum=0;
    string track[n]; float credits[n];
    for(i=1; i<n; ++i){
        track[i-1] = ter[j-1][i];
        cout<<"\n\n\t\tEnter Credits for "<<track[i-1]<<"\t:";
        cin>>credits[i-1];
        sum=sum+credits[i-1];
    }
    cout<<"\n\n\t\t\t\tTOTAL CREDITS :"<<sum;
    batchnme = batchnme + "students.csv";
    int f=batchnme.size(), num,k;
    char b_array[f];
    strcpy(b_array, batchnme.c_str());
    vector< vector<string> > cg =getvector(b_array);
    num=cg.size()-1;
    k = cg[0].size()-1;
    float marks[num], total=0;


    marks[num]={0};

            for(i=1; i<=cg.size(); ++i){

                for(j=2; j<cg[0].size()-1; ++j){

                    total= s2f(cg[i][j]) * credits[j-2];
                    marks[i-1]= marks[i-1] + total;

                }

                    marks[i-1] = marks[i-1]/sum;
                  //  cout<<"  "<<marks[i-1]<<'\n';
                    cg[i][k] = f2s(marks[i-1]);
                   // cout<<"  "<<cg[i][k];
            }
     csvgrd_create(b_array,  cg);
     cout<<"\n\n\t\t************RESULTFOR BATCH 20"<<batchnme<<" ***************\n";
     for(i=0; i<cg[0].size() ; ++i){
        cout<<cg[0][i]<<"\t";
     }
    cout<<"\n\n";
     for(i=1; i<cg.size(); ++i){

        for(j=0; j<cg[0].size();++j){
            cout<<cg[i][j]<<" \t";
        }
         cout<<"\n\n-----------------------------------------------------------------------------------------------------\n";
     }
     int c;
    cout<<"\n\n\t\tEXIT   1/0  ??";
    cin>>c;
    if(c==1){
        intro_result();
    }
    else{
        cout<<"\n\n\t\t*********************************************";
    }
}
//**********************************INSTRUCTIONS*******************************************

void instruction(){
       cout<<"\n\n\t***************WELCOME TO INSTRUCTIONS PAGE****************** ";
       cout<<"\n\n\t\t1. New faculty has to register first and remember their faculty ID and Password";
       cout<<"\n\t\t2. Login if you have already registered ";
       cout<<"\n\t\t3. First add the courses in the course menu fr a particular batch";
       cout<<"\n\t\t4. Add the enrolled students for that course ";
       cout<<"\n\t\t5. In the faculty menu, you can set the evaluation pattern for a particular course";
       cout<<"\n\t\t6. After entering the marks in the particular csv file do not forget the make all the columns in the batch file to 0";
       cout<<"\n\t\t7. Make sure to make all the empty columns to 0 in all the csv files you are dealing with";
       cout<<"\n\t\t8. Result can be viewed for a particular course as well as for a whole batch ";


}

//************************************ LOGIN PAGE ********************************************


void intro_main(){
int c;
    Faculty fac;
    cout<<"\n\n\t\t   INDIAN INSTITUTE  OF INFORMATION TECHNOLOGY    \n\n";
    cout<<"\t\t\t\t    GRADE SHEET    \n\n";
    cout<<"\t\t1.LOGIN\n\n\t\t2.REGISTER\n\n\t\tPLEASE ENTER YOUR CHOICE\t:";
    cin>>c;
    switch(c){
        case 1: fac.verify();
                break;
        case 2: fac.getf_data();
                break;
        default: cout<<"\n\n\t\tPLEASE ENTER A VALID CHOICE";
                intro_main();
    }

}


//********************************************************************************************

int main(){

    intro_main();
    return 0;

}


