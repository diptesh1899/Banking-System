#include<iostream>
#include<unistd.h>
using namespace std;

class Bank{
	private: 
	    int total;
	    string id;
	    struct person{
	    	string name,ID,address;
	    	int contact,balance;
		}person[100];
	public:
		Bank(){
			total=0;
		}
		void choice()
		{
			int ch;
    		while(1){
			cout<<"\n\nPRESS..!!"<<endl;
			cout<<"1. Create new account"<<endl;
			cout<<"2. View customers list"<<endl;
			cout<<"3. Update information of existing account"<<endl;
			cout<<"4. Check the details of an existing account"<<endl;
			cout<<"5. For transactions"<<endl;
			cout<<"6. Remove existing account"<<endl;
			cout<<"7. Exit"<<endl;
			cin>>ch;
			system("clear");
			switch(ch){
			case 1:
				perData();
				break;
			case 2:
				if(total==0) cout<<"No data is entered"<<endl;
				else show();
				break;
			case 3:
				if(total==0) cout<<"No data is entered"<<endl;
				else update();
				break;
			case 4:
				if(total==0) cout<<"No data is entered"<<endl;
				else search();
				break;
			case 5:
				if(total==0) cout<<"No data is entered"<<endl;
				else transactions();
				break;
			case 6:
				if(total==0) cout<<"No data is entered"<<endl;
				else del();
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<<"Invalid input"<<endl;
				break;
	        }
        }
	 }
		void perData(){
			cout<<"Enter data of person "<<total+1<<endl;
			cout<<"Enter name: ";
			cin>>person[total].name;
			cout<<"ID: ";
			cin>>person[total].ID;
			cout<<"Address: ";
			cin>>person[total].address;
			cout<<"Contact: ";
			cin>>person[total].contact;
			cout<<"Total balance: ";
			cin>>person[total].balance;
			total++;
		}
		void show(){
			for(int i=0;i<total;i++){
				cout<<"Data of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Address: "<<person[i].address<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Balance: "<<person[i].balance<<endl;
	        }
		}
		void update(){
			cout<<"Enter id of student those data you want to update"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
					cout<<"Previous data"<<endl;
					cout<<"Data of person "<<i+1<<endl;
					cout<<"Name: "<<person[i].name<<endl;
					cout<<"ID: "<<person[i].ID<<endl;
					cout<<"Address: "<<person[i].address<<endl;
					cout<<"Contact: "<<person[i].contact<<endl;
					cout<<"Balance: "<<person[i].balance<<endl;
					cout<<"\nEnter new data"<<endl;
					cout<<"Enter name: ";
					cin>>person[i].name;
					cout<<"ID: ";
					cin>>person[i].ID;
					cout<<"Address: ";
					cin>>person[i].address;
					cout<<"Contact: ";
					cin>>person[i].contact;
					cout<<"Total balance: ";
					cin>>person[i].balance;
					break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void search(){
			cout<<"Enter id of student those data you want to search"<<endl;
            cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
					cout<<"Name: "<<person[i].name<<endl;
					cout<<"ID: "<<person[i].ID<<endl;
					cout<<"Address: "<<person[i].address<<endl;
					cout<<"Contact: "<<person[i].contact<<endl;
					cout<<"Balance: "<<person[i].balance<<endl;
					break;
	            }
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void transactions(){
			int balance;
			int ch;
			cout<<"Enter id of those data you want to transaction"<<endl;
     		cin>>id;
     		for(int i=0;i<total;i++){
     		if(id==person[i].ID){
     			cout<<"Name: "<<person[i].name<<endl;
     	    	cout<<"Address: "<<person[i].address<<endl;
		     	cout<<"Contact: "<<person[i].contact<<endl;
		     	cout<<"\nExisting balance "<<person[i].balance<<endl;
		     	cout<<"Press 1 to Deposit"<<endl;
		     	cout<<"Press 2 to Withdraw"<<endl;
		     	cin>>ch;
		     	switch(ch){
		     		case 1:
						cout<<"How much amount you want to deposit??"<<endl;
						cin>>balance;
						person[i].balance+=balance;
						cout<<"Your new balance is "<<person[i].balance<<endl;
		     			break;
		     		case 2:
						back:
						cout<<"How much money you want to withdraw??"<<endl;
						cin>>balance;
						if(balance>person[i].balance){
							cout<<"Your existing balance is just "<<person[i].balance<<endl;
							sleep(2);
							goto back;
						}
						person[i].balance-=balance;
						cout<<"Your new balance is "<<person[i].balance<<endl;
						break;
					default:
						cout<<"Invalid input"<<endl;
						break;
			   }
			break;
		   }
		   if(i==total-1){
		  		cout<<"No such record found in the system"<<endl;
		   }
	      }
		}
		void del(){
			int ch;
			cout<<"Press 1 to remove specific record"<<endl;
			cout<<"Press 2 to remove full record"<<endl;
			cin>>ch;
			switch(ch){
				case 1:
					cout<<"Enter id of those data you want to remove"<<endl;
					cin>>id;
					for(int i=0;i<total;i++){
						if(id==person[i].ID){
							for(int j=i;j<total;j++){
								person[j].name=person[j+1].name;
								person[j].ID=person[j+1].ID;
								person[j].address=person[j+1].address;
								person[j].contact=person[j+1].contact;
								person[j].balance=person[j+1].balance;
								total--;
								cout<<"Your required data is deleted"<<endl;
								break;
							}
						}
				    	if(i==total-1){
							cout<<"No such record found in the system"<<endl;
						}
					}			
						break;
				case 2:
					total=0;
					cout<<"All record is deleted!"<<endl;
					break;
				default:
					cout<<"Invalid Input"<<endl;
					break;
			}
		}
};

int main(){
	Bank b;
	b.choice();
	return 0;
}
