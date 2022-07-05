#include <iostream>
#include <iomanip> //setw
#include <string>  // getline
#include <vector>  // dynamic ARRAY
using namespace std;

// To keep track of the customer price
/*
number means index
-> 0 - price of items (sum)
-> 1  -quantity of item(total)
->2 - tax
->3 -discount
->4 -total amount(tax,discount included)
->5 -money returned after cash payment(access)
->6 -money paid in cash
*/
void Calling_Function(int n);

int customer[7] = {0, 0, 0, 0, 0, 0, 0};

// KEEPS DATA OF THE ITEMS OF THE CUSTOMER(BASICALLY THE LIST IN SHORT FORM)
vector<vector<int>> customer_BillDetails;

// Structure Of Customer Data
struct customer_Data
{
    string name;
    string phone_Number = "";
    string modeofPayment;
    string address = "";
    string email_id = "";
    string NameOfBank = "";
} c1;

// The Time showing Function
void show_Time()
{
    // return the date and time as an integer
    time_t curr_Time = time(0);

    // converts to a string and returns as a pointer
    char *print_Time = ctime(&curr_Time);
    cout << print_Time;

    return;
}

// The Details Of The Customer And Balance Paying
void customer_Details()
{
    // Customer Bill MOnetary prt
    customer[2] = 0.02 * customer[0];                      // discount
    customer[3] = 0.05 * customer[0];                      // tax
    customer[4] = customer[0] + customer[2] - customer[3]; // total price

    cin.ignore(); // newline character ya whitespace ignore

    int money_recived;
    int price;
    char in;
    bool flag; // true(1) ya false(0)

    cout << "\n\n";
    cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
    cout << setw(45);
    show_Time();
    cout << "\t\t\t\t\t===========================================\n\n";
    cout << "\n\n\n";

    cout << "\t\t\t\t\tPLEASE ENTER YOUR NAME: ";
    getline(cin, c1.name);
    cout << "\n";

    cout << "\t\t\t\t\tDO YOU WISH TO GIVE OUR MOBILE PHONE NUMBER(Y/N): ";
    cin >> in;
    if (in == 121 || in == 89)
    {
        cout << "\n\t\t\t\t\tPLEASE ENTER YOUR PHONE NUMBER: ";
        cin >> c1.phone_Number;
    }
    cout << "\n\n";

    cout << "\t\t\t\t\tDO YOU WISH TO SHARE YOUR EMAIL ID(Y/N): ";
    cin >> in;

    if (in == 121 || in == 89)
    {
        cout << "\n\t\t\t\t\tPLEASE ENTER YOUR EMAIL ID: ";
        cin >> c1.email_id;
    }
    cout << "\n\n";

    cout << "\t\t\t\t\tDO YOU WISH TO SHARE YOUR ADDRESS(Y/N): ";
    cin >> in;

    if (in == 121 || in == 89)
    {
        cout << "\n\t\t\t\t\tPLEASE ENTER YOUR CURRENT LIVING ADDRESS: ";
        getline(cin, c1.address);
    }

    cout << "\n\n";
    cin.ignore();
    cout << "\t\t\t\t\tPLEASE ENTER YOUR MODE OF PAYMENT: ";
    getline(cin, c1.modeofPayment);
    if (c1.modeofPayment == "Credit Card")
    {
        cout << "\n\n\t\t\t\t\tCREDIT CARD PAYMENT ";
        cout << "\n\t\t\t\t\tENTER YOUR BANK NAME: ";
        cin >> c1.NameOfBank;
        cout << "\n\t\t\t\t\tTHE PAYMENT IS SUCCESSFULL.PLEASE CHECK YOUR BANK STATEMENT FOR CONFIRMATION\n";

        // 1 sec pause
        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }

        customer[5] = 0;                  // No return money
        customer[4] = 0.95 * customer[0]; // 5% extra discount
        customer[6] = customer[4];        // Money Recieved
        cout << "\n";
    }
    else // CAsh Payment
    {
        bool flag; // Ya toh true ya false
        // loop does not stop till the person pays the full amount of the items

        do
        {
            flag == false;
            cout << "\n\n\t\t\t\t\tCASH PAYMENT";
            cout << "\n\t\t\t\t\tYOU HAVE TO GIVE A TOTAL OF: " << customer[4];
            cout << "\n\t\t\t\t\tPLEASE ENTER THE AMOUNT YOU GAVE:";
            cin >> money_recived;
            customer[5] = money_recived - customer[4];
            if (customer[5] < 0)
            {
                cout << "\n\t\t\t\t\tYOU HAVEN'T FULLY FOR THE ITEMS!!!!!!";
                flag = true; // Full money nhi diya
                cout << "\n\n";
            }
        } while (flag);

        customer[6] = money_recived;
    }

    // used to clear the screen
    system("cls");

    // Customer Data SHow
    cout << "\n\n";
    cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
    cout << setw(45);
    show_Time();
    cout << "\t\t\t\t\t===========================================\n\n";
    cout << "\n\n\n";

    // printing user data
    cout << "\n";
    cout << "\t\t\tNAME : \t\t" << c1.name;

    if (c1.phone_Number != "")
    {
        cout << "\t\t\tPhoneNumber: " << c1.phone_Number;
    }

    if (c1.address != "")
    {
        cout << "\t\t\tADDRESS: " << c1.address << "\n";
    }

    if (c1.email_id != "")
    {
        cout << "\t\t\tEMAIL ID: " << c1.email_id;
    }
    cout << "\n\t\t\tMODEOFPAYMENT : " << c1.modeofPayment;

    if (c1.modeofPayment == "Credit Card")
    {
        cout << c1.modeofPayment << "\t\t";
        cout << "\t\tBANK NAME :" << c1.NameOfBank;
    }
    else
    {
        cout << c1.modeofPayment;
    }

    cout << "\n\t\t\tCASHIER : " << setw(5) << "RAMESH";
    cout << "\n\n";
    return;
}

// The Bill Function
void bill_View(int customer[])
{
    system("cls");

    if (!customer_BillDetails.size())
    {
        int option;
        cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
        cout << setw(45);
        show_Time();
        cout << "\t\t\t\t\t===========================================\n\n";

        cout << "\t\t\t\tLOOKS LIKE U HAVENT PURCHASED SOMETHING... LETS GO AND BUY TOGETHER...";
        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }

        cout << "\n\n\t\t\tDOU YOU WANT TO BUY OR LEAVE(1 TO BUY REST TO LEAVE): ";
        cin >> option;
        if (option == 1)
        {
            Calling_Function(5);
        }
        else
        {
            Calling_Function(1);
        }
    }

    Calling_Function(6);

    cout << "\n\n\n\t\t\t\t*********************************************";
    cout << "\n\t\t\t\t                 BILL PAYMENT                  ";
    cout << "\n\t\t\t\t*********************************************";
    cout << "\n\n\t\t\t\tTOTAL PRICE :          " << setw(10) << customer[0];
    cout << "\n\t\t\t\tTOTAL QUANTITY :       " << setw(10) << customer[1];
    cout << "\n\t\t\t\tTAX  :       " << setw(20) << customer[2];
    cout << "\n\t\t\t\tDISCOUNT  :    " << setw(18) << customer[3];
    cout << "\n\n\n\t\t\t\tNET AMOUNT   :" << setw(18) << "Rs. " << customer[4];
    cout << "\n\t\t\t\tMONEY RECIEVED  :" << setw(15) << "Rs. " << customer[6];
    cout << "\n\t\t\t\tMONEY RETURNED  :" << setw(15) << "Rs. " << customer[5];
    cout << "\n\t\t\t\t*********************************************";
    cout << "\n\n";
    cout << "\t\t\t\t******THANKS FOR SHOPPING WITH US.HOPE TO SEE U AGAIN********";

    int x;
    cout << "\n\n\n\t\t\t\tPRESS ANY OTHER KEY TO LEAVE.................\n";
    cin >> x;
    exit(0);
    return;
}

//
void print_List(vector<vector<int>> &a)
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****THE ANYTHING STORE*****";
    cout << setw(45);
    show_Time();
    cout << "\t\t\t\t\t\t\t\t===========================================\n\n";
    cout << "\n\n";
    if (!a.size())
    {
        int option;
        cout << "\t\t\t\t\t\t\tLOOKS LIKE U HAVENT PURCHASED SOMETHING... LETS GO AND BUY TOGETHER...";

        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }

        cout << "\n\n\t\t\tDO YOU WANT TO BUY OR LEAVE(1 TO BUY REST TO LEAVE): ";
        cin >> option;
        if (option == 1)
        {
            Calling_Function(5);
        }
        else
        {
            Calling_Function(1);
        }
    }
    else
    {
        cout << "\t\t\tCODE\t     QUANTITY\t       PRICE\t\tTOTAL\n\n\n";
        for (int i = 0; i < a.size(); i++)
        {
            cout << "\t\t\t";
            for (int j = 0; j < 4; j++)
            {
                cout << a[i][j] << "\t\t";
            }
            cout << "\n\n";
        }
    }

    cout << "\t\t\tDO YOU WANT TO GO FOR THE BILL PAYMENT(1) , EDIT THE LIST(2) , ADD MORE ITEMS(3) OR GO THE TO THE MAIN MENU(4): ";
    int option;
    cin >> option;
    if (option == 1)
    {
        Calling_Function(2);
    }
    else if (option == 2)
    {
        Calling_Function(4);
    }
    else if (option == 3)
    {
        Calling_Function(4);
    }
    else
    {
        Calling_Function(1);
    }

    return;
}

// Customer Bill Editing
void edit_CustomerBillingList(vector<vector<int>> &a)
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\t\t*****THE ANYTHING STORE*****";
    cout << setw(45);
    show_Time();
    cout << "\t\t\t\t\t\t\t\t===========================================\n\n";
    cout << "\n\n";

    if (!a.size())
    {
        int option;
        cout << "\t\t\t\t\t\t\tLOOKS LIKE U HAVENT PURCHASED SOMETHING... LETS GO AND BUY TOGETHER...";
        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }

        cout << "\n\n\t\t\tDOU YOU WANT TO BUY OR LEAVE(1 TO BUY REST TO LEAVE): ";
        cin >> option;
        if (option == 1)
        {
            Calling_Function(5);
        }
        else
        {
            Calling_Function(1);
        }
    }

    cout << "\n\n\t\t\tPRESS 1. TO EDIT THE AMOUNT THE ITEMS \n\n";
    cout << "\t\t\tPRESS 2. TO REMOVE THE ITEM \n\n";
    cout << "\t\t\tPRESS 3. TO VIEW THE LIST \n\n";
    cout << "\t\t\tPRESS 4. TO ADD DATA IN THE LIST \n\n";
    cout << "\t\t\tPRESS ANY OTHER TO GO TO MAIN MENU \n\n";
    cout << "\t\t\tPLEASE ENTER YOUR OPTION: ";
    int option;
    cin >> option;

    cout << "\n\n";

    if (option == 1)
    {
        bool flag = false;
        do
        {
            system("cls");

            cout << "\t\t\t\t\t\t\t\t\t*****THE ANYTHING STORE*****";
            cout << setw(45);
            show_Time();
            cout << "\t\t\t\t\t\t\t\t===========================================\n\n";
            cout << "\n\n";

            int code, idx = a.size() + 1; // a.size()->size of the list.
            cout << "\t\t\tPLEASE ENTER THE CODE OF THE ITEM: ";
            cin >> code;

            for (int i = 0; i < a.size(); i++)
            {
                if (a[i][0] == code)
                {
                    idx = i;
                    break;
                }
            }

            if (idx == a.size() + 1)
            {
                cout << "\t\t\tTHERE IS NO SUCH ITEM .. PLEASE BUY ONE AND THEN COME BACK...";
                Calling_Function(1);
            }

            int x;
            cout << "\t\t\tPLEASE ENTER THE NEW QUANTITY: ";
            cin >> x;
            if (x > a[idx][1])
            {
                a[idx][3] = (x)*a[idx][2];
                customer[0] += (x - a[idx][1]) * a[idx][2];
                customer[1] += (x - a[idx][1]);
                customer[2] = 0.02 * customer[0];
                customer[3] = 0.05 * customer[0];
                customer[4] = customer[0] + customer[2] - customer[3];
                a[idx][1] = x;
            }
            else
            {
                a[idx][3] = (x)*a[idx][2];
                customer[0] -= (a[idx][1] - x) * a[idx][2];
                customer[1] -= (a[idx][1] - x);
                customer[2] = 0.02 * customer[0];
                customer[3] = 0.05 * customer[0];
                customer[4] = customer[0] + customer[2] - customer[3];
                a[idx][1] = x;
            }

            cout << "\t\t\tDO YOU WANT TO CHANGE MORE ITEMS(1 FOR YES AND 0 FOR NO): ";
            cout << "\n\n";
            cin >> flag;
        } while (flag);

        return;
    }
    else if (option == 2)
    {
        bool flag = false;
        do
        {
            system("cls");

            cout << "\t\t\t\t\t\t\t\t\t*****THE ANYTHING STORE*****";
            cout << setw(45);
            show_Time();
            cout << "\t\t\t\t\t\t\t\t===========================================\n\n";
            cout << "\n\n";

            int code, idx;
            cout << "\t\t\tPLEASE ENTER THE CODE OF THE ITEM: ";
            cin >> code;

            for (int i = 0; i < a.size(); i++)
            {
                if (a[i][0] == code)
                {
                    idx = i;
                    break;
                }
            }

            customer[0] -= (a[idx][0]) * a[idx][2];
            customer[1] -= (a[idx][0]);
            customer[2] = 0.02 * customer[0];
            customer[3] = 0.05 * customer[0];
            customer[4] = customer[0] + customer[2] - customer[3];
            a[idx].clear();
            a.erase(a.begin() + idx);

            cout << "\n\n\t\t\tDO YOU WANT TO DELETE MORE ITEMS(1 FOR YES AND 0 FOR NO): ";
            cin >> flag;

            cout << "\n\n";

        } while (flag);
    }
    else if (option == 3)
    {
        Calling_Function(3);
    }
    else if (option == 4)
    {
        Calling_Function(5);
    }
    Calling_Function(1);
    return;
}

// Calculation Of The Items And Thier Prices
void bill_Calculation(int customer[])
{
    system("cls");
    int option;
    do
    {
        system("cls");

        cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
        cout << setw(45);
        show_Time();
        cout << "\t\t\t\t\t===========================================\n\n";

        cout << "\t\t\tCUSTOMER LIST -----"
             << "\n\n";
        cout << "\n\n";
        cout << "\t\t\tPLEASE ADD THE FOLLOWING INFORMATION ABOUT THE ITEM FROM THE MENU GIVEN AT THE GATE--";
        int price;
        int code;
        int quantity;
        cout << "\n\n";
        cout << "\t\t\tENTER THE CODE OF THE ITEM: ";
        cin >> code;
        cout << "\n";
        cout << "\t\t\tENTER THE PRICE: ";
        cin >> price;
        cout << "\n";
        cout << "\t\t\tENTER THE QUANTITY: ";
        cin >> quantity;

        // INDIVIDUAL ITEM DETAIL OF THE CUSTOMER
        vector<int> input(4);
        input[0] = code;
        input[1] = quantity;
        input[2] = price;
        input[3] = price * quantity;

        customer_BillDetails.push_back(input);

        // Bill Calculation Of The Customer
        customer[0] += price * quantity;
        customer[1] += quantity;

        cout << "\n\n";
        cout << "\t\t\tWANT TO ADD MORE ITEM(1), PROCEED TO BILL PAYMENT(2) ,VIEW YOUR LIST(3) OR EDIT THE LIST(4) AND PRESS ANY OTHER TO GO TO THE HOME PAGE: ";
        cin >> option;
    } while (option == 1);

    if (option == 2)
    {
        Calling_Function(2);
    }
    else if (option == 3)
    {
        Calling_Function(3);
    }
    else if (option == 4)
    {
        Calling_Function(4);
    }
    else
    {
        cout << "\n\n\n\t\t\tYOU HAVE ENTERED A WRONG KEY.REDIRECTING YOU TO THE HOME PAGE ......";
        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }
        Calling_Function(1);
    }
    return;
}

// The Starting page
void starting_Page()
{
    system("cls");
    cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
    cout << setw(45);
    show_Time();
    cout << "\t\t\t\t\t===========================================\n\n";
    cout << "\n\t\t1.Billing  Report\n\n";
    cout << "\t\t2.Add/Remove/Edit Item\n\n";
    cout << "\t\t3.Show Item Details\n\n";
    cout << "\t\t4.Exit\n\n";
    cout << "\t\tPlease Enter Required Option: ";

    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        bill_View(customer);
        break;

    case 2:
        system("cls");

        cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
        cout << setw(45);
        show_Time();
        cout << "\t\t\t\t\t===========================================\n\n";
        int option;
        cout << "\t\t\tADD/EDIT/REMOVE ITEMS FROM YOUR LIST\n\n";
        cout << "\n\n";
        cout << "\t\t\t1. ADD ITEM TO THE LIST"
             << "\n";
        cout << "\t\t\t2. EDIT THE ITEMS IN YOUR LIST"
             << "\n";
        cout << "\t\t\t3. PRINT THE BILL "
             << "\n";
        cout << "\t\t\tYOUR OPTION(PRESS ANY OTHER KEY TO LEAVE APART FROM THE ABOVE ONES): ";

        cin >> option;

        if (option == 1)
        {
            Calling_Function(5);
        }
        else if (option == 2)
        {
            Calling_Function(4);
        }
        else if (option == 3)
        {
            Calling_Function(2);
        }
        else
        {
            starting_Page();
        }
        break;

    case 3:
        system("cls");
        print_List(customer_BillDetails);
        break;

    case 4:
        system("cls");
        cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
        cout << setw(45);
        show_Time();
        cout << "\t\t\t\t\t===========================================\n\n";
        cout << "\n\n";
        cout << "\t\t\t\t******THANKS FOR SHOPPING WITH US.HOPE TO SEE U AGAIN********";
        for (int i = 0; i < 10e8; i++)
        {
            continue;
        }
        exit(0);

    default:
        system("cls");
        cout << "\t\t\t\t\t\t*****THE ANYTHING STORE*****";
        cout << setw(45);
        show_Time();
        cout << "\t\t\t\t\t===========================================\n\n";
        cout << "\n\n";
        cout << "\t\t\tYOU HAVE PRESSED THE WRONG KEY."
             << "\n";
        starting_Page();
        break;
    }
}

// The Function Calling All The Rest Of The Codes..
void Calling_Function(int n)
{
    if (n == 1)
    {
        starting_Page();
    }
    else if (n == 2)
    {
        bill_View(customer);
    }
    else if (n == 3)
    {
        print_List(customer_BillDetails);
    }
    else if (n == 4)
    {
        edit_CustomerBillingList(customer_BillDetails);
    }
    else if (n == 5)
    {
        bill_Calculation(customer);
    }
    else if (n == 6)
    {
        customer_Details();
    }

    return;
}

// Main Function
int main()
{
    starting_Page();
    return 0;
}
