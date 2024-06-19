/* the functions are as follow:
1. Check balance
2. Cash withdraw
3. User details
4. Update mobile number
5. Exit
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define ll long long int

class atm{

private:
    ll acc_no;
    int pin;
    float balance;
    string mob_no;
    string name;

public: 
    void setData(ll acc_no,string name,int pin,float balance,string mob_no){
        this->acc_no=acc_no;
        this->name=name;
        this->pin=pin;
        this->balance=balance;
        this->mob_no=mob_no;
    }
    ll getAcc(){
        return acc_no;
    }
    string getName(){
        return name;
    }
    string getMob(){
        return mob_no;
    }
    float getBalance(){
        return balance;
    }
    int getPin(){
        return pin;
    }

    // update mobile number
    void setMob(string prev,string updated){
        if(prev==mob_no)  //if matches previous number then we go ahead
        {
            mob_no=updated;
            cout<<"Mobile No. updated Successfully!!!";
            _getch();
        }
        else {cout<<"Mobile No. Not Correct!!!"<<endl; getch();}
    }
    //cash withdraw
    void cashWithdraw(float amount){
        if(amount<=balance && amount>0){
            balance=balance-amount;
            cout<<"Please Collect Your Cash"<<endl<<"Available Balance : "<<balance;
            _getch();
        }
        else if(amount<=0) {cout<<"Invalid Credentials!!!"<<endl; _getch();}
        else {cout<<"Insuffiecient Balance!!!"; _getch();}
    }
};

int main(){
    int input;
    int enterPin;
    ll enterAccNo;
    system("cls"); //clear screen

    atm user1;
    user1.setData(22010206914,"Palab",1404,51030.42,"8899123456");

    //we need our atm to run for infinite time
    do{
        system("cls");
        cout<<"~~~Welcome To SBI~~~"<<endl<<endl<<endl;
        cout<<"Enter Account No.:"<<endl;
        cin>>enterAccNo;
        cout<<"Enter PIN:"<<endl;
        cin>>enterPin;

        if(enterAccNo==user1.getAcc() && enterPin==user1.getPin()){
            do{
                float amount;
                string prev_mob,update_mob;
                system("cls");
                cout<<"Selected A Task"<<endl;
                cout<<"1. Check Balance"<<endl;
                cout<<"2. Cash Withdrawl"<<endl;
                cout<<"3. Show User Details"<<endl;
                cout<<"4. Update Mobile No."<<endl;
                cout<<"5. Exit"<<endl;
                cin>>input;

                switch(input){
                    case 1:
                        cout<<"Your Acoount Balance is :"<<user1.getBalance()<<endl;
                        _getch();
                        break;
                    case 2:
                        cout<<"Enter Amount:"<<endl;
                        cin>>amount;
                        user1.cashWithdraw(amount);
                        break;
                    case 3:
                        cout<<"Here are the User Details:-"<<endl;
                        cout<<"Account No. : "<<user1.getAcc()<<endl;
                        cout<<"Name : "<<user1.getName()<<endl;
                        cout<<"Balance : "<<user1.getBalance()<<endl;
                        cout<<"Mobile No. : "<<user1.getMob()<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"Enter Current Mobile No.:"<<endl;
                        cin>>prev_mob;
                        cout<<"Enter New Mobile No.:"<<endl;
                        cin>>update_mob;
                        user1.setMob(prev_mob,update_mob);
                        break;
                    case 5:
                        exit(0);
                    
                    default:
                        cout<<"Invalid Credentials!!!"<<endl;
                }
            } while(1); //atm machine never stops
        }
        else {
            cout<<"Invalid Details!!!"<<endl;
            _getch();
        }
    }while(1);
}
