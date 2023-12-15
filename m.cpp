#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

static int back;
static int r[5], rent1[5], total[5] = {10, 10, 10, 10, 10};

class Rent {
public:
    char name[20];
    long int CNIC;
    char adr[50];
    int phone;
    char mail[50];
    char today[10];
    char return_date[10];
    char car_name[10];
    char car_no[8];
    int numbers_cars;
    char city_from[10];
    char city_to[10];
    int payment;
    char res_py;
    int rent_day;
    int pay;

void car_info(){
	printf("<--BACK(0)\n");
	printf("NAME\t\tPAYMENT\tINRENT\tTOTAL\n");
	printf("KIA\t\t5600\t%d\t%d\n",r[0],10);
	printf("ALTO\t\t3200\t%d\t%d\n",r[1],10);
	printf("BMW \t\t7600\t%d\t%d\n",r[2],10);
	printf("Toyota\t\t5500\t%d\t%d\n",r[3],10);
	printf("Suzuki\t\t4400\t%d\t%d\n",r[4],10);
	printf("\t\t\tENTER COMMAND: ");
	scanf("%d",&back);
	if(back==0){
		system("cls");
		Menu();
	}
	
}
    void AddRecord() {
        fstream fp;
        char another = 'y';
        while (another == 'y' || another == 'Y') {
            system("cls");
            cout << "\t\t\t\t=======Add USER Info=======\n\n\n";
            cout << "\t\t\t\t======Don't Use Spaces=======\n\n\n";
            fp.open("information.txt", ios::out | ios::app);
            cout << "\n\t\t\tEnter Your Name: ";
            cin >> name;
            cout << "\n\t\t\tCNIC (USE 4 Value Only ) :";
            cin >> CNIC;
            cout << "\n\t\t\tAddress:";
            cin >> adr;
            cout << "\n\t\t\tEnter Your Personal Number:";
            cin >> phone;
            cout << "\n\t\t\tEnter Your E-Mail:";
            cin >> mail;
            cout << "\n\t\t\tEnter Today Date: ";
            cin >> today;
            cout << "\n\t\t\tEnter Return Date:";
            cin >> return_date;
            cout << "\n\t\t\tCity From :";
            cin >> city_from;
            cout << "\n\t\t\tCity To:";
            cin >> city_to;
            cout << "\n\t\t\tCar Name:";
            cin >> car_name;
            cout << "\n\t\t\tEnter Numbers Of Cars:";
            cin >> numbers_cars;
            cout << "\n\t\t\tReturn days:";
            cin >> rent_day;

            // Calculating payment based on car type
            if (strcmp(car_name, "kia") == 0) {
                if (numbers_cars > total[0]) {
                    cout << "Sorry, try again.\n";
                    getch();
                    system("cls");
                    continue;
                } else {
                    pay = 5600 * numbers_cars * rent_day;
                    r[0] = rent1[0] + numbers_cars;
                    total[0] = 10 - numbers_cars;
                }
            } else if (strcmp(car_name, "bmw") == 0) {
                // Similarly calculate payments for other car types
                // ...
            }

            cout << "\n\t\t\tYour Total payment IS:" << pay;
            cout << "\n\t\t\t______________________________\n";

            if (!fp) {
                cerr << "Can't open file";
            } else {
                cout << "\t\t\tRecord stored successfully\n";
            }

            fp.write(reinterpret_cast<char *>(this), sizeof(*this));
            fp.close();

            cout << "\t\t\tDo you want to add another record? (y/n) : ";
            cin >> another;
        }
        system("cls");
        Menu();
    }

    void DeleteRecord() {
        fstream fp, fp1;
        int cnic, found = 0;

        cout << "\t\t\t\t=======DELETE USER RECORD=======\n\n\n";
        fp.open("information.txt", ios::in);
        fp1.open("temp.txt", ios::out);
        cout << "\t\t\t\tEnter User CNIC : ";
        cin >> cnic;

        if (!fp) {
            cerr << "DATA NOT SAVE: \n";
            getch();
            system("cls");
            Menu();
        }

        while (fp.read(reinterpret_cast<char *>(this), sizeof(*this))) {
            if (CNIC == cnic) {
                found = 1;
            } else {
                fp1.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
        }
        fp.close();
        fp1.close();

        if (!found) {
            cout << "\n\t\t\t\tRecord not found\n";
            getch();
            system("cls");
            Menu();
        }
        if (found) {
            remove("information.txt");
            rename("temp.txt", "information.txt");

            cout << "\n\t\t\t\tRecord deleted successfully\n";
        }

        getch();
        system("cls");
        Menu();
    }

    void ShowRecords() {
        ifstream fp;
        cout << "\t\t\t\t=======USER RECORD=======\n\n\n";

        fp.open("information.txt", ios::in);

        if (!fp) {
            cerr << "USER DATA NOT FOUND\n";
            getch();
            system("cls");
            Menu();
        } else {
            cout << "\t\t\t\tRECORDS :\n";
            cout << "\t\t\t\t___________\n\n";
        }

        while (fp.read(reinterpret_cast<char *>(this), sizeof(*this))) {
            cout << "\n\t\t\t\t Person Name  : " << name;
            cout << "\n\t\t\t\t Person CNIC       : " << CNIC;
            cout << "\n\t\t\t\t Person Address         : " << adr;
            cout << "\n\t\t\t\t Phone  : " << phone;
            cout << "\n\t\t\t\t Payment    : " << pay;
            cout << "\n\t\t\t\t Mail    : " << mail;
            cout << "\n\t\t\t\t Date:    : " << today;
            cout << "\n\t\t\t\t Return Date    : " << return_date;
            cout << "\n\t\t\t\t CAR Name    : " << car_name;
            cout << "\n\t\t\t\t From    : " << city_from;
            cout << "\n\t\t\t\t To    : " << city_to;
            cout << "\n\t\t\t\t ________________________________\n";
        }
        fp.close();
        getch();
        system("cls");
        Menu();
    }

    void showRecordInfo(const Rent &info) {
    cout << "\n\t\t\t\t Person Adress         : " << info.adr;
    cout << "\n\t\t\t\t Phone  : " << info.phone;
    cout << "\n\t\t\t\t Payment    : " << info.pay;
    cout << "\n\t\t\t\t Mail    : " << info.mail;
    cout << "\n\t\t\t\t Date:    : " << info.today;
    cout << "\n\t\t\t\t Return Date    : " << info.return_date;
    cout << "\n\t\t\t\t CAR Name    : " << info.car_name;
    cout << "\n\t\t\t\t From    : " << info.city_from;
    cout << "\n\t\t\t\t To    : " << info.city_to;
    cout << "\n\t\t\t\t ________________________________\n";
}

// Function to search for user record
void searchRecord() {
    ifstream file("information.txt", ios::binary);
    int user_ser;
    bool found = false;
    cout << "\t\t\t\t=======SEARCH INRENT-USER RECORD=======\n\n\n";
    cout << "\t\t\tENTER THE USER CNIC NO ( without - ) : ";
    cin >> user_ser;

    Rent info;
    while (file.read(reinterpret_cast<char *>(&info), sizeof(Rent))) {
        if (info.CNIC == user_ser) {
            found = true;
            showRecordInfo(info);
        }
    }

    if (!found) {
        cout << "\n\t\t\tRecord not found\n";
        cin.ignore();
        cin.get();
    }
    file.close();
}
void userrec(){
	FILE *fp;
    struct Rent info;
    fp = fopen("information.txt", "r");

    printf("\t\t\t\t=======USER RECORD=======\n\n\n");

    if (fp == NULL) {
        fprintf(stderr, "USER DATA NOT FOUND\n");
        getch();
        system("cls");
        // Assuming `menu()` is a function already defined
        Menu();
    } else {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");

        while (fread(&info, sizeof(struct Rent), 1, fp)) {
            printf("\n\t\t\t\t Person Name  : %s", info.name);
            printf("\n\t\t\t\t Person CNIC       : %d", info.CNIC);
            printf("\n\t\t\t\t Person Address         : %s", info.adr);
            printf("\n\t\t\t\t Phone  : %d", info.phone);
            printf("\n\t\t\t\t Payment    : %d", info.pay);
            printf("\n\t\t\t\t Mail    : %s", info.mail);
            printf("\n\t\t\t\t Date:    : %s", info.today);
            printf("\n\t\t\t\t Return Date    : %s", info.return_date);
            printf("\n\t\t\t\t CAR Name    : %s", info.car_name);
            printf("\n\t\t\t\t From    : %s", info.city_from);
            printf("\n\t\t\t\t To    : %s", info.city_to);

            printf("\n\t\t\t\t ________________________________\n");
        }
        fclose(fp);
        getch();
        system("cls");
        // Assuming `menu()` is a function already defined
        Menu();
}
}
void add_user() {
    FILE *fp;
    char another;
    struct Rent info;

    do {
        system("cls");
        cout << "\t\t\t\t=======Add USER Info=======\n\n\n";

        fp = fopen("information.txt", "a");

        cout << "\n\t\t\tEnter Your Name: ";
        cin >> info.name;
        cout << "\n\t\t\tCNIC: ";
        cin >> info.CNIC;
        cout << "\n\t\t\tAddress: ";
        cin >> info.adr;
        cout << "\n\t\t\tEnter Your Personal Number: ";
        cin >> info.phone;
        cout << "\n\t\t\tEnter Your E-Mail: ";
        cin >> info.mail;
        cout << "\n\t\t\tEnter Today Date: ";
        cin >> info.today;
        cout << "\n\t\t\tEnter Return Date: ";
        cin >> info.return_date;
        cout << "\n\t\t\tCity From: ";
        cin >> info.city_from;
        cout << "\n\t\t\tCity To: ";
        cin >> info.city_to;
        cout << "\n\t\t\tCar Name: ";
        cin >> info.car_name;
        cout << "\n\t\t\tEnter Numbers Of Cars: ";
        cin >> info.numbers_cars;
        cout << "\n\t\t\tReturn days: ";
        cin >> info.rent_day;

        if (strcmp(info.car_name, "kia") == 0) {
            if (info.numbers_cars > total[0]) {
                cout << "sorry try again.";
                getch();
                system("cls");
                Menu();
            } else {
                info.pay = 5600 * info.numbers_cars * info.rent_day;
                r[0] = rent1[0] + info.numbers_cars;
                total[0] = 10 - info.numbers_cars;
            }
        } else if (strcmp(info.car_name, "bmw") == 0) {
            // Similar blocks for other car types...
        }

        cout << "\n\t\t\tYour Total payment IS: " << info.pay;
        cout << "\n\t\t\t______________________________\n";

        if (fp == NULL) {
            fprintf(stderr, "can't open file");
        } else {
            cout << "\t\t\tRecord stored successfully\n";
        }

        fwrite(&info, sizeof(struct Rent), 1, fp);
        fclose(fp);

        cout << "\t\t\tYou want to add another record?(y/n) : ";
        cin >> another;

    } while (another == 'y' || another == 'Y');

    system("cls");
    Menu();
}


void deleteRecord() 
{
    fstream fp, fp1;
    int cnic;
    bool found = false;

    cout << "\t\t\t\t=======DELETE USER RECORD=======\n\n\n";
    cout << "\t\t\t\tEnter User CNIC : ";
    cin >> cnic;

    fp.open("information.txt", ios::in);
    fp1.open("temp.txt", ios::out | ios::app);

    if (!fp || !fp1) {
        cerr << "Error opening files!\n";
        getch();
        system("cls");
        Menu();
    }

    while (fp.read(reinterpret_cast<char *>(this), sizeof(*this))) {
        if (CNIC == cnic) {
            found = true;
            continue;
        }
        fp1.write(reinterpret_cast<char *>(this), sizeof(*this));
    }

    fp.close();
    fp1.close();

    if (!found) {
        cout << "\n\t\t\t\tRecord not found\n";
        getch();
        system("cls");
        Menu();
    } else {
        remove("information.txt");
        rename("temp.txt", "information.txt");
        cout << "\n\t\t\t\tRecord deleted successfully\n";
    }

    getch();
    system("cls");
    Menu();
}
void serinfo() {
    ifstream file("information.txt", ios::binary);
    int userCNIC;
    bool found = false;

    cout << "\t\t\t\t=======SEARCH USER RECORD=======\n\n\n";
    cout << "\t\t\t\tENTER THE USER CNIC NO (without -): ";
    cin >> userCNIC;

    Rent info;
    while (file.read(reinterpret_cast<char *>(&info), sizeof(Rent))) {
        if (info.CNIC == userCNIC) {
            found = true;
            cout << "\n\t\t\t\tRecord Found:\n";
            cout << "\t\t\t\t-----------------\n";
            cout << "\t\t\t\t Person Name         : " << info.name << endl;
            cout << "\t\t\t\t Person CNIC         : " << info.CNIC << endl;
            cout << "\t\t\t\t Person Address      : " << info.adr << endl;
            cout << "\t\t\t\t Phone               : " << info.phone << endl;
            cout << "\t\t\t\t Payment             : " << info.pay << endl;
            cout << "\t\t\t\t Mail                : " << info.mail << endl;
            cout << "\t\t\t\t Date                : " << info.today << endl;
            cout << "\t\t\t\t Return Date         : " << info.return_date << endl;
            cout << "\t\t\t\t CAR Name            : " << info.car_name << endl;
            cout << "\t\t\t\t From                : " << info.city_from << endl;
            cout << "\t\t\t\t To                  : " << info.city_to << endl;
            cout << "\t\t\t\t ----------------------------\n";
        }
    }

    if (!found) {
        cout << "\n\t\t\t\tRecord not found\n";
    }

    file.close();
    cin.ignore();
    cin.get();
    system("cls");
    Menu(); 
}
void logout(){
	system("cls");
		cout<<"\t\t\tDO You Want To LogOut ? "<<endl;
		cout<<"\t\t\t   Yes         No       "<<endl;
		cout<<"\t\t\tCOMMAND: ";
		string cmdd;
		cin>>cmdd;
		if(cmdd=="yes" || cmdd=="Yes" || cmdd=="YES"){
			system("cls");
			exit(0);
			
			
		}
		else{
			system("cls");
			Menu();
		}
		
		
}
void about(){
	
}
void exit_program(){
	system("cls");
	cout<<"\t\tt\THANK U FOR USING MY SOFTWARE";
	{
		exit(0);
	}
}
void Menu() {
	Rent nb;
	int number;
	printf("\t\t WELLCOME TO RENT A CAR MANAGEMENT SYSTEM.\n");
	printf("\t\t\tNOTE:USE NUMBERS FOR SELECTING\n");
	printf("\n");
	printf("\t\t\t1)Cars Info\n ");
	printf("\t\t\t2)User Info\n ");
	printf("\t\t\t3)Add New Record \n ");
	printf("\t\t\t4)Del User Info\n ");
	printf("\t\t\t5)Search\n ");
	printf("\t\t\t6)Log-Out\n ");
	printf("\t\t\t7)About\n ");
	printf("\t\t\t8)Exit\n ");
	printf("\t\t\tENTER COMMAND: ");
	cin>>number;
	if(number==1){
		system("cls");
		car_info();
	}
	else if(number==2){
		system("cls");
		userrec();
	}
	else if(number==3){
		system("cls");
		add_user();
	
	}
	else if(number==4){
		system("cls");
		deleteRecord();
	}
	else if(number==5){
		system("cls");
		serinfo();
	}
	else if(number==6){
		system("cls");
		logout();
	}
	else if(number==7){
		system("cls");
		about();
	}
	else if(number==8){
		system("cls");
		exit_program();
	}
	else{
		system("cls");
		printf("\t\t\tPlz Use Numbers (1-8):\n");
		Menu();
	}
	
	


}
};

// Function to handle user login
int main() {
    Rent lg;
    string name,pass;
    cout << "\t\t\tENTER USER NAME: ";
    cin >> name;
    cout << "\t\t\tENTER Password: ";
    cin >> pass;
    
    if (name=="admin") {
        if (pass== "12a") {
            system("cls");
            cout << "\n\n\n";
            cout << "\n\n\n";
            cout << "\t\t\tLOGIN SUCCESSFULLY ...\n";
            cout << "\t\t\t WAIT 3 SEC\n";
            //this_thread::sleep_for(chrono::milliseconds(2100));
            Sleep(200);
            cout << "\t\t\tPress Enter:";
            cin.ignore();
            cin.get();
            system("cls");
            lg.Menu();
        } else {
            system("cls");
            cout << "\t\t\t\aYOUR PASSWORD IS INVALID\n";
            main();
        }
    } else {
        system("cls");
        cout << "\t\t\t\aUserName Invalid \n";
        main();
    }
	return 0;
}

