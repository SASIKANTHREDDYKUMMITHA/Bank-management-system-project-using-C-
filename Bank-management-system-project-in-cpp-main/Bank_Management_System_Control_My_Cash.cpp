#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <string.h>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class BankMF
{
public:
    int n, customer_id, total = 0;
    int a,opp;
    vector<string>transaction;
    string name,address,branch,password,NID,Phone,age ;
    long long balance=100000000;
    char ex;
    BankMF()
    {
        ifstream f("users.txt");
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t============= Greetings =============="<<endl<<"\t\t\t\t\t===== Welcome to Control My Cash =====";
        cout<<endl<<endl<<"\t\t\t\t\t\tAre you?"<<endl<<"\t\t\t\t\t\t1. Employee?"<<endl<<"\t\t\t\t\t\t2. Customer?";
        cout<<endl<<"\t\t\t\t\t\tChoose the option : ";
        cin>>a;

        if(a==1)
        {
            loading();
            employee_login();

        }
        else
            which_user();
        return;
    }
    void which_user(){
         system("cls");
            cout<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\tYou are?\n\t\t\t\t\t1. Already have an account \n\t\t\t\t\t2. New User"<<endl;
            cout<<"\t\t\t\t\tEnter Your Choice : ";
            cin>>opp;
            if(opp==1)
            {
                loading();
                login_page();
            }
            else
            {
                loading();
                new_user();
            }
        return;
    }
    void loading()
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        std::cout << "\t\t\t\t\tLoading.....Please Wait For a While!" << std::flush;
        for (int i=0; i<4; i++)
        {
            sleep(1);
            std::cout << "." << std::flush;
        }
        system("cls");
    }

    int main()
    {
        loading();
        return 0;
    }

    void new_user()
    {
        system("cls");
        ofstream newuse;
        newuse.open("users.txt",ios::app);
        cin.ignore();
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tEnter Your Following Information"<<endl;
        cout<<"\t\t\t\t\tPhone Number                            :";
        cin>>Phone;
        cin.ignore();
        int src_phno=access(Phone);
        if(src_phno == 0)
        {
            cout << "\t\t\t\t\tThis number is already registered." << endl;
            continue_button();
            which_user();
            return;
        }
        cout<<"\t\t\t\t\tPassword (Password can't include space!):";
        getline(cin,password);
        cout<<"\t\t\t\t\tName                                    :";
        getline(cin,name);
        cout<<"\t\t\t\t\tAge                                     :";
        cin>>age;
        cin.ignore();
        cout<<"\t\t\t\t\tNID                                     :";
        cin>>NID;
        cin.ignore();
        newuse <<endl<< Phone <<' '<<password <<' '<< age <<' '<<NID <<' '<<"25"<<' '<< name;
        for(int i=0; i<10; i++)
            newuse<<endl<<"--------------------";
            newuse<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXX";
        newuse.close();
        cout<<"\t\t\t\t\tAccount Successfully Created !"<<endl;
        cout << endl;
        continue_button();
        loading();
        login_page();
    }
    void employee_login()
    {
        //system("cls");
        cout<<"\t\t\t\t\t\tLOGIN PAGE"<<endl;
        string id, pass;
        cout<<endl<<endl<<endl<<endl<<endl;
there:
        cout << "\t\t\t\t\tEnter your ID       : ";
        cin >> id;
        if(id=="C233477" || id=="C233479" || id=="C233510" ){
        cout << "\t\t\t\t\tEnter your password :";
        cin>> pass;
        if((id=="C233477" && pass == "yasup")||(id=="C233479" && pass == "xyz")||(id=="C233510" && pass == "EEEmate"))
        {
            loading();
            employee_menu();
            return;
        }
        else
        {
            cout<<endl<<endl;
            cout << "\t\t\t\t\tYour password is incorrect" << endl;
            goto there;
        }}
        else {
            cout<<"\n\n\t\t\t\t\tThis ID is not registered as our Employee!\n\n"<<endl;
            goto there;
        }
    }
    void employee_menu()
    {
        while(1)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl;
            cout << "\t\t\t\t\tMenu" << endl;
            cout << "\t\t\t\t\t1.Cash In" << endl << "\t\t\t\t\t2.Update information" << endl << "\t\t\t\t\t3.Delete Account" ;
            cout<< endl << "\t\t\t\t\t4.Search and check" << endl << "\t\t\t\t\t5.Salary" << endl << "\t\t\t\t\t6.Need Help ?" ;
            cout<< endl << "\t\t\t\t\t7.Exit" << endl;
            cout<< "\t\t\t\t\tEnter Your Choice : ";
            int x;
            cin >> x;
            system("cls");
                loading();
            switch(x)
            {
            case 1:
                cash_in();
                break;
            case 2:
                update_info();
                break;
            case 3:
                delete_account();
                break;
            case 4:
                search_n_check();
                break;
            case 5:
                cout << "\t\t\t\t\tYour current salary is : " << "50000 taka" << endl;
                cout << "\t\t\t\t\tBonus : " << "10 taka" << endl;
                continue_button();
                break;
            case 6:
                cout<<endl<<endl<<endl<<endl<<endl;
                cout << "\t\t\t\t\tCall : +432948328434" << endl << "\t\t\t\t\tE-mail : jaijaidin@gmail.com" << endl;
                continue_button();
                break;

            default:
                cout << "\t\t\t\t\tInvalid Input" << endl;
                break;
            }
            if(x == 7)
            {
                system("cls");
                cout<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\tThank you for using our App."<<endl<<endl<<endl<<endl;
                exit(0);
            }
        }
    }
    int access(string no)
    {
        ifstream gui;
        int c=1;
        string sxf,gay;
        gui.open("users.txt");
        while(gui>>sxf)
        {
            if(strcmp(no.c_str(), sxf.c_str())== 0)
            {
                gui>>password>>age>>NID>>balance ;
                getline(gui,name);
                for(int i=0; i<10; i++)
                {
                    getline(gui,gay);
                    transaction.push_back(gay);
                }
                c=0;
                gui.close();
            }
        }
        return c;
    }
    void cash_in()
    {
        int acc_no;
        long long cash;
        cout<<endl<<endl<<endl<<endl<<endl;
        cout << "\t\t\t\t\tEnter customer account no                : ";
        cin >> Phone;
        acc_no=access(Phone);
        if(acc_no==1)cout<<"\t\t\t\t\tThe account doesn't exist."<<endl;
        else
        {
            cout << "\t\t\t\t\tEnter the amount you want to cash in : ";
            cin >> cash;
            cout << "\t\t\t\t\tCash In successful !" << endl;
            cout << "\t\t\t\t\tPrevious balance : " << balance << endl;
            balance+=cash;
            cout << "\t\t\t\t\tCurrent balance  : " << balance << endl;
        }
        update_tran(1,cash,"ryf");
        update();
        continue_button();
        return;
    }
    void update_info()
    {
        string   src_pass;
        int src_phno;
        int f = 1;
        cout<<endl<<endl<<endl<<endl<<endl;
        cout << "\t\t\t\t\tEnter customer phone no : ";
        cin >> Phone;
        src_phno=access(Phone);
        if(src_phno == 1)
        {
            cout << "\t\t\t\t\tSorry No Registration History" << endl;
            continue_button();
            return;
        }
        cout << "\t\t\t\t\t1. Name : "<<name<<endl;
        cout << "\t\t\t\t\t2. Age  : "<<age<<endl;
        cout << "\t\t\t\t\t3. NID  : "<<NID<<endl;
        cout<<  "\t\t\t\t\t4. Exit"<<endl;
        while(f>0 &&f<4)
        {
            cout<<"\t\t\t\t\tChoose the option you want to edit : ";
            cin>>f;
            switch(f)
            {
            case 1:
            {
                cin.ignore();
                string naam;
                cout<<"\t\t\t\t\tEnter the new data : ";
                getline(cin,naam);
                int s=name.size()-naam.size();
                while(s-- && s>0)
                {
                    naam=naam+' ';
                }
                name=' '+naam;
            }
            break;
            case 2:
                cout<<"\t\t\t\t\tEnter the new data : ";
                cin>>age;
                break;
            case 3:
                cout<<"\t\t\t\t\tEnter the new data : ";
                cin>>NID;
                break;
            }
        }
        update();
        continue_button();
        return;
    }
    void delete_account()
    {
        string reason;
        int del_no;
        cout << "\t\t\t\t\tEnter customer account no : ";
        cin >> Phone;
        del_no=access(Phone);
        if(del_no == 1)
        {
            cout << "\t\t\t\t\tSorry no registration history :(" << endl;
            continue_button();
            return;
        }
        name="";
        update();
        cout << "\t\t\t\t\tAccount deletion successful !" << endl;
        continue_button();
        return;
    }
    void search_n_check()
    {
        string  src_pass;
        int f = 1,src_phno;
        cout<<endl<<endl<<endl<<endl<<endl;
        cout << "\t\t\t\t\tEnter customer phone no : ";
        cin >> Phone;
        src_phno=access(Phone);
        if(src_phno == 1)
        {
            cout << "\t\t\t\t\tSorry no registration history :(" << endl;
            continue_button();
            return;
        }
        cout << "\t\t\t\t\tName : "<<name<<endl;
        cout << "\t\t\t\t\tAge : "<<age<<endl;
        cout << "\t\t\t\t\tNID : "<<NID<<endl;
        cout << "\t\t\t\t\tPhone No : "<< Phone << endl;
        cout << "\t\t\t\t\tTotal Balance : "<< balance << endl;
        continue_button();
        return;
    }
    void login_page()
    {
        string passw,src_phno;
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tLOGIN PAGE:"<<endl;

there:
        cout<<endl<<"\t\t\t\t\tPhone Number:";
        cin>>src_phno;
        ifstream khula;
        khula.open("users.txt",ios::app);
        int c=1;
        while(khula >> Phone)
        {
            string p;
            if(strcmp(Phone.c_str(), src_phno.c_str())== 0)
            {
                khula>>password;
                c=0;
                khula.close();
            }
        }
        if(c==1)
        {
            cout<<"\t\t\t\t\tThe account doesn't exists"<<endl;
            goto there;
        }
        cin.ignore();
        cout<<"\t\t\t\t\tPassword:";
        getline(cin,passw);
        if(password==passw)
        {
            menu();
            return;
        }
        else
        {
            cout<<"\t\t\t\t\tYour password is incorrect."<<endl<<endl;
            goto there;
        }
    }
    void menu()
    {
        while(1)
        {   system("cls");
            cout<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t===== Menu ====="<<endl<<"\t\t\t\t\t1. Cash Out"<<endl<<"\t\t\t\t\t2. Send Money"<<endl;
            cout<<"\t\t\t\t\t3. Check Balance"<<endl<<"\t\t\t\t\t4. Apply for Loan"<<endl<<"\t\t\t\t\t5. Transaction History";
            cout<<endl<<"\t\t\t\t\t6. Donate for Palestine"<<endl;
            cout<<"\t\t\t\t\t7. Need Help? Contact Us"<<endl<<"\t\t\t\t\t8. Exit"<<endl;
            cout<<"\t\t\t\t\tEnter Your Choice : ";
            int m;
            cin>>m;
            access(Phone);
            system("cls");
            loading();
            switch(m)
            {
            case 1:
                Cash_out();
                break;
            case 2:
                Send_money();
                break;
            case 3:
                Check_balance();
                continue_button();
                break;
            case 4:
                Loan();
                break;
            case 5:
                Transac();
                break;
            case 6:
                donate();
                break;
            case 7:
                contact();
                break;
            case 8:
                break;
            default:
                cout<<endl<<endl<<endl<<endl;
                cout<<"\t\t\t\t\tInvalid Input. Try Again!"<<endl<<endl<<endl;
                break;
            }
            if(m==8)
            {
                system("cls");
                cout<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\tThank you for using our App."<<endl<<endl<<endl<<endl;
                exit(0);
            }
        }
    }
    void contact()
    {
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tPhone: +880 XXXX-XXXXXX"<<endl;
        cout<<"\t\t\t\t\tEmail: controlmycash@gmail.com"<<endl;
        cout<<"\t\t\t\t\tFax: XXX XXX XXX"<<endl;
        continue_button();
        return;
    }
    void donate()
    {
        long long amount;
        Check_balance();
        cout<<"\t\t\t\t\tAmount of cash you want to donate: ";
        cin>>amount;
        final_balance(amount);
        update_tran(2,amount,"kgk");
        update();
        return;
    }
    void Transac()
    {
        access(Phone);
        cout<<endl<<"\t\t\t\t\t\tTRANSACTION HISTORY"<<endl<<endl;
        for(int i=0; i<10; i++)
        {
            cout<<"\t\t\t\t"<<transaction[i]<<endl;
        }
        continue_button();
        return;
    }
    int submission()
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t1. Submit"<<endl<<"\t\t\t\t\t2. Cancel"<<endl;
        int opp;
        cout<< "\t\t\t\t\tEnter Your Choice : ";
        cin>>opp;
        return opp;
    }
    void Loan()
    {
        long long loan;
        string reason;
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tHow much loan do you want?  ";
        cin>>loan;
        cin.ignore();
        cout<<"\t\t\t\t\tReason behind applying for loan?"<<endl<<"\t\t\t\t\t";
        getline(cin,reason);
        opp=submission();
        if(opp==2)return;
        else
        {
            cout<<"\t\t\t\t\tApplication has being submited."<<endl;
            continue_button();
            return;
        }
    }
    void continue_button()
    {
        string df;
        cout<<endl<<endl<<endl<<endl<<"\t\t\t\t\tEnter any character to return : ";
        cin>>df;
    }
    void Check_balance ()
    {
        cout<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tYour Total Balance: " <<balance<<endl;
        return;
    }
    void Cash_out ()
    {
        long long amount;
        string phomy;
        cout<<endl<<endl<<endl<<endl<<endl;
        Check_balance();
        cout<<endl;
        cout<<"\t\t\t\t\tEnter Your Amount: ";
        cin>>amount;
        cout<<endl;
        cout<<"\t\t\t\t\tEnter Agent Number: ";
        cin>>phomy;
        cout<<endl;
        opp=submission();
        if(opp==2) {}
        else
        {
            final_balance(amount);
        }
        update_tran(3,amount,phomy);
        update();
        return;
    }
    void final_balance(long long amounty)
    {
        if(balance-20<amounty || balance<=20)
        {
            cout<<"\t\t\t\t\tInsufficient Balance"<<endl<<"\t\t\t\t\tTransaction failed"<<endl;
        }
        else
        {
            balance-=amounty;
            cout<<"\t\t\t\t\tTransaction Successful"<<endl<<"\t\t\t\t\tYour Current balance: "<<balance<<endl;
        }
        continue_button();
        return;
    }
    void Send_money()
    {
        cout<<endl<<endl<<endl<<endl<<endl;
        long long amount;
        string phone;
        Check_balance();
        cout<<"\t\t\t\t\tEnter Your Amount: ";
        cin>>amount;
        cout<<"\t\t\t\t\tEnter Receiver's Number: ";
        cin>>phone;
        opp=submission();
        if(opp==2) {}
        else
        {
            final_balance(amount);
        }
        update_tran(4,amount,phone);
        update();
        return;
    }
    void update()
    {
        long long ct=1,i=5,k=100;
        fstream newuse,agains,abar,newd;
        string exf,extra,mad="546654654",yo;
        newuse.open("users.txt", std::ios::in | std::ios::out);
        newd.open("users.txt", std::ios::in | std::ios::out);
        while(newuse>>exf)
        {
            if(strcmp(Phone.c_str(), exf.c_str())== 0)
            {
                i=ct-1;
                abar.open("users.txt", std::ios::in | std::ios::out);
                agains.open("users.txt", std::ios::in | std::ios::out);
                while(i--)
                {
                    agains>>extra;
                    abar>>extra;
                }
                getline(abar,extra);
                getline(abar,yo);
                for(int i=0; i<11; i++)
                {
                    getline(abar,extra);
                }
                getline(abar,extra);
                int j=0;
                if(extra!="XXXXXXXXXXXXXXXXXXXXXXXX")
                while(mad!="XXXXXXXXXXXXXXXXXXXXXXXX" || extra!="XXXXXXXXXXXXXXXXXXXXXXXX")
                {
                    mad=extra;
                    if(mad=="--------------------" && j<11)
                    {
                        mad="yo";
                        j++;
                    }
                    else j=0;
                    agains<<endl<<extra;
                    getline(abar,extra);
                }
                if(name!="")
                {
                    agains<<endl<<Phone<<' '<<password << ' '<<age<< ' '<<NID <<' '<<balance<<name;
                    for(int i=0; i<10; i++)
                    {
                        agains<<endl<<transaction[i];
                    }
                    agains<<endl<<"XXXXXXXXXXXXXXXXXXXXXXXX";
                }
                else
                {
                    agains<<endl;
                    int y=yo.size();
                    while(y--)agains<<' ';
                    for(int i=0; i<10; i++)
                    {
                        agains<<endl;
                        y=transaction[i].size();
                        while(y--)agains<<' ';
                    }
                    agains<<endl;
                    int k=24;
                    while(k--)agains<<' ';
                }
                agains.close();
                abar.close();
                newuse.close();
                transaction.clear();
                return;
            }
            ct++;
        }
    }
    void update_tran (int x,long long y,string h)
    {
        string k=to_string(y);
        if(x==1)transaction[9]=     "CashIn..............CMC Agent................. + "+k;
        else if(x==2)transaction[9]="Donated.............to Palestine.............. - "+k;
        else if(x==3)transaction[9]="CashOut............."+h+"................ - "+k;
        else if(x==4)transaction[9]="SendMoney..........."+h+"................ - "+k;
        for(int i=8; i>=0; i--)swap(transaction[i],transaction[i+1]);
        return;
    }
};
using namespace std;
int main()
{
    BankMF a;
    return 0;
}
