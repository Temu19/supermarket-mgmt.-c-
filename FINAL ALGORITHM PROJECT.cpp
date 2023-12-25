		#include <iostream>
		#include <conio.h>
		#include <fstream>
		#include <string>
		using namespace std;
		
		//build node inside a class
		
		class supramarket{
			private:
					struct node{           //singly linked list
					int ID;               //product id
					string proname;       //product name
					double preprice;      //product price
					int quantity;         //product quantity
					struct node* next;    //pointer variable(next)
			};
			public:
				struct node *head = NULL;
				void del();
				void edit();
				void sort();
				void search();
				void insert();
				void password();
				void interface();
				void display();
				void about();
				void showexisting();
		};
		
		      //password interface
		
		 void supramarket::password(){
		    	system("cls");
		        string passnumber;
		        string passcode = "123123a";
		
		    cout <<"Please Enter Your Password: ";
		
		    cin >> passnumber;
		
		   if(passcode == passnumber){
		    cout <<"!!!!!!!! ACCESS GRANTED !!!!!!!"<<endl;
		    cout <<"Now press the ENTER key to continue: ";
			getch();
		   }
		   else{
		   	cout <<"!! ACCESS DENIED TRY AGAIN LATER !! ";
		   	getch();
		    exit(0);
		   }
		
		 }
		 
		//insertion of first record or product
		void supramarket::insert()
		{
		    system("cls");
			fstream marketfile;
			marketfile.open("supermarketfile.txt",ios::app); //write in form of append
		
			cout <<"\n\n\t\t\t\t ====================================================";
		    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
		    cout <<"\n\n\t\t\t\t ====================================================";
			int id,quant;
			string name;
			double pre;
			struct node *t = new node;
			cout<<"\n\n\n\t\t:::::: Please Enter The Proper Data Type :::::: ";
			cout << "\n\n\t\t\tEnter product id:-";
			cin >> id;
			t->ID=id;
			marketfile << id<<endl;
			cout << "\t\t\tEnter product name:-";
			cin >>name;
			t->proname=name;
			marketfile << name<<endl;
			cout << "\t\t\tEnter product price:-";
			cin >> pre;
			t->preprice=pre;
			marketfile << pre<<endl;
			cout << "\t\t\tEnter product quantity:-";
			cin >> quant;
			t->quantity=quant;
			marketfile << quant<<endl<<endl<<endl;
			marketfile.close();
			t->next = NULL;
			if(head == NULL)
			{
				head = t;
			}
			else{
				node *ptr = head;
			    while(ptr -> next != NULL)
			      {
			 	    ptr = ptr -> next;
			      }
			      ptr->next = t;
			}
			cout <<"\n\n\t\tNew Product Record Inserted Successfully...........";
			getch();
			interface();
		}
		
		void supramarket::search(){
			system("cls");
			int p_id, found = 0;
			cout <<"\n\n\t\t\t\t ====================================================";
		    cout <<"\n\n\t\t\t=============== supermarket management system ====================";
		    cout <<"\n\n\t\t\t\t ====================================================";
			if(head == NULL){
				cout <<"\n\n linked list is empty....";
						getch();
						interface();
			}
			else
			{
				cout <<"\n\nproduct id :";
				cin >>p_id;
				node *ptr = head;
				while(ptr != NULL)
				{
					if(p_id == ptr -> ID)
					{
							system("cls");
						cout <<"\n\n\t\t\t\t ====================================================";
					    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
					    cout <<"\n\n\t\t\t\t ====================================================";
						cout <<"\n\n product id : "<<ptr -> ID;
						cout <<"\n\n product name : "<<ptr -> proname;
				        cout <<"\n\n product quantity : "<<ptr -> quantity;
						cout <<"\n\n product price : "<<ptr->preprice;
						found++;
						getch();
						interface();
					}
					ptr = ptr -> next;
				}
				if(found == 0)
				{
					cout<<"\n\n product id invalid.....";
					getch();
					interface();
				}
		
			}
		
		
		
		}
		void supramarket::edit(){
		
		     	system("cls");
			fstream marketfile;
			marketfile.open("supermarketfile.txt", ios::app);
			int p_id, found = 0;
			cout <<"\n\n\t\t\t\t ====================================================";
		    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
		    cout <<"\n\n\t\t\t\t ====================================================";
			if(head == NULL){
				cout <<"\n\n linked list is empty....";
				getch();
				interface();
			}
			else
			{
				cout <<"\n\nproduct id :";
				cin >>p_id;
				node *ptr = head;
				while(ptr != NULL)
				{
					if(p_id == ptr -> ID)
					{
							system("cls");
						cout <<"\n\n\t\t\t\t ====================================================";
					    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
					    cout <<"\n\n\t\t\t\t ====================================================";
						cout <<"\n\n product id : ";
						cin >>ptr -> ID;
						marketfile << ptr -> ID<<" ";
						cout <<"\n\n product name : ";
						cin >>ptr -> proname;
						marketfile << ptr -> proname<<" ";
				        cout <<"\n\n product quantity : ";
						cin >>ptr -> quantity;
						marketfile << ptr -> quantity<<" ";
						cout <<"\n\n product price : ";
						cin >>ptr -> preprice;
						marketfile << ptr -> preprice<<" ";
						marketfile.close();
						found++;
						cout <<"\n\t\t\t Updated Product Record Succesfully.........";
						getch();
						interface();				
					}
					ptr = ptr -> next;
				}
				if(found == 0)
				{
					cout<<"\n\n product id invalid.....";
					getch();
					interface();
				}
			}
		
		}
		void supramarket::del(){
				system("cls");
			int p_id, found = 0;
			cout <<"\n\n\t\t\t\t ====================================================";
		    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
		    cout <<"\n\n\t\t\t\t ====================================================";
			if(head == NULL){
				
				cout <<"\n\n linked list is empty....";
				getch();
				interface();
			}
			else
			{
				cout <<"\n\n product id :";
				cin >>p_id;
				if(p_id == head->ID)
			     {
			     	node *ptr = head;
			     	head = head->next;
			     	delete ptr;
			     	cout <<" Product Record Deleted Successfully......";
			     	getch();
			     	interface();
			     	found++;
				 }
				 else
				 {
				 	node *pre = head;
				 	node *ptr = head;
				 	while(ptr != NULL)
				 	{
				 		if(p_id == ptr->ID)
				 		{
				 			pre->next = ptr->next;
				 			delete ptr;
				 			cout<<"!! Product Record Deleted Successfully !!";
				 			getch();
				 			interface();
				 			found++;
				 			break;
						 }
						 pre = ptr;
						 ptr = ptr->next; 
					 }
				 }
			if(found == 0)
			{
				cout <<"product id is invalid";
				getch();
				interface();
			}
		    }
		}
		
		void supramarket::sort(){
				   
				if(head == NULL){
					 system("cls");
				   	cout <<"\n\nlinked list is empty ";
		             getch();
		             interface();
		
				}
			    	int count=0;
					int p_id;
					int p_price;
					int p_quant;
					string p_name;
				node *ptr = head;
				while(ptr != NULL)
				{
					 count++; 
					 ptr = ptr -> next;
				}
				for(int i=1;i<=count;i++)
				{
					node *ptr = head;
					for(int j =1;j<count;j++)
					{
						if(ptr->ID > ptr->next->ID)
						{
							//save data into temporary variables
							p_id = ptr->ID;
							p_name = ptr->proname;
							p_price =ptr->preprice;
							p_quant =ptr->quantity;
							//save data into current node
							ptr -> ID = ptr->next->ID;
							ptr -> proname = ptr->next->proname;
							ptr -> preprice = ptr->next->preprice;
							ptr -> quantity = ptr->next->quantity;
							//save data into next node variables
							ptr->next->ID = p_id;
							ptr->next->proname = p_name;
							ptr->next->preprice = p_price;
							ptr->next->quantity = p_quant;
						}
						ptr = ptr->next;
					}
				}
		
			}
		
		void supramarket::display()
				     {
							system("cls");
							int p_id, found = 0;
							cout <<"\n\n\t\t\t\t ====================================================";
						    cout <<"\n\n\t\t\t=============== supermarket management system ========================";
						    cout <<"\n\n\t\t\t\t ====================================================";
						
							
								
								node *ptr = head;
								while(ptr != NULL)
								{
									
									
										cout <<"\n\n product id : "<<ptr -> ID;
										cout <<"\n\n product name : "<<ptr -> proname;
								        cout <<"\n\n product quantity : "<<ptr -> quantity;
										cout <<"\n\n product price : "<<ptr -> preprice;
										cout <<"\n\n\n ===========================================";
									    ptr = ptr -> next;
								}
								
							}
							
		void supramarket::interface(){
				system("color 03");
		    system("cls");
			long int choice;
			cout <<"\n\n\t\t\t\t   ====================================================";
		    cout <<"\n\n\t\t\t====================== supermarket management system ========================";
		    cout <<"\n\n\t\t\t\t   ====================================================";
		    
		    cout <<"\n\n 1. INSERT NEW RECORD";
		    cout <<"\n\n 2. SEARCH SPECIFIC RECORD";
		    cout <<"\n\n 3. EDIT RECORD";
		    cout <<"\n\n 4. DELETE RECORD";
		    cout <<"\n\n 5. SORT AND DISPLAY ALL RECORD";
		    cout <<"\n\n 6. SHOW EXISTING PRODUCTS FROM FILE";
		    cout <<"\n\n 7. EXIT";
		     cout <<"\n\n 8. ABOUT";
		    
		    cout <<"\n\n PLEASE ENTER YOUR CHOICE : ";
		
		    cin >> choice;
		
		    switch(choice){
		    	case 1:
		    		insert();
		    		break;
		    	case 2:
		
		    		search();
		    		break;
				case 3:
		
		    		edit();
		    		break;
				case 4:
		 
		    		del();
		    		break;
		    		
				case 5:
		
		    		sort();
		    		display();
		    		break;
		    		
		    	case 6:	 
		    	    
		    	    showexisting();
		    	    break;
		    	
				case 7:
					
		    		exit(0);
		    		
		    	case 8:
		    		
		    		about();
		    		break;
		    		
			    default:
				cout <<"\n\n invalid choice";
				 getch();
			
			}
		 getch();
		}
		
		void supramarket :: about(){
		
			system("cls");
			system("color 02");
			cout <<	"\n\n\t\t\t\t   ====================================================";
		    cout <<"\n\n\t\t\t====================== supermarket management system ========================";
		    cout <<"\n\n\t\t\t\t   ===================================================="<<endl;
		    
		    cout <<"\n         This has been a great opportunity made for us by our Teacher and we would really like to Thank him!!!!!!"<<endl;
		    cout <<"\n\n\n\n                :::::::::::Students Involved In This Great Journey:::::::::::\n\n\n\n";
		    cout <<"\t\tStudent Name                                                                Student ID"<<endl;
		    cout << "\n\t\t\tTemesgen Tesfaye -------------------------------------------15/21"<<endl;
	
		  
		    
		    getch();
		    
		    
		}
		
		void supramarket::showexisting(){
		    system("cls");
			fstream marketfile;
			marketfile.open("supermarketfile.txt",ios::in); //read  from file
			if(marketfile.is_open()) {
				string line;
				while (getline(marketfile, line)){
					cout<< line <<endl;
					
				}
				
				marketfile.close();
			}
			
			
			
			
		}
		
		
		
		//main function
		
		int main(){
			 
			 supramarket obj;
			 obj.password();
			 obj.interface();
		
		}
