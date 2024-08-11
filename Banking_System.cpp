#include <bits/stdc++.h> // INCLUDE ALL STANDARD C++ LIBRARIES
using namespace std; // USE THE STANDARD NAMESPACE


// FUNCTION TO DISPLAY INSTRUCTIONS
void display_instructions() {
  cout<<"                                      "<<" ********** " << "WELCOME TO THE ATM SYSTEM "<<" ********** "<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"                           " << " {->} PLEASE SELECT ONE OF THE FOLLOWING OPTIONS:"<<endl;
  cout<<endl;

  cout<<"                    " << "1. DEPOSIT AMOUNT: DEPOSIT MONEY INTO YOUR ACCOUNT:"<<endl;
  cout<<endl;
  cout<<"                    " <<"2. CHECK BALANCE: CHECK YOUR CURRENT ACCOUNT BALANCE:"<<endl;
  cout<<endl;
  cout<<"                    " << "3. DISPLAY BANKING FACILITIES: VIEW AVAILABLE BANKING SERVICES:"<<endl;
  cout<<endl;
  cout<<"                    " <<"4. INTEREST CALCULATION: CALCULATE INTEREST BASED ON YOUR DEPOSIT:"<<endl;
  cout<<endl;
  cout<<"                    " <<"5. WITHDRAW AMOUNT: WITHDRAW MONEY FROM YOUR ACCOUNT:"<<endl;
  cout<<endl;
  cout<<"                    " <<"6. HISTORY TRACKER: VIEW YOUR TRANSACTION HISTORY:"<<endl;
}


// FUNCTION TO CHECK THE BALANCE OF A BANK ACCOUNT
void check_balance(stack<int> &balance, int PIN) {
    int password;  // VARIABLE TO STORE THE ENTERED PASSWORD
    for(int i = 0; i < 3; i++) {  // ALLOW UP TO 3 ATTEMPTS TO ENTER THE CORRECT PIN
        cout << "Please enter the PIN for your bank account: " << endl;  // PROMPT USER TO ENTER PIN
        cin >> password;  // READ THE ENTERED PIN
        if(PIN == password) {  // CHECK IF THE ENTERED PIN MATCHES THE ACTUAL PIN
            cout << "Your account balance is: " << balance.top() << endl;  // DISPLAY THE ACCOUNT BALANCE
            exit(0); // EXIT THE PROGRAM AFTER SHOWING THE BALANCE
        }
    }
    // IF THE USER FAILS TO ENTER THE CORRECT PIN IN 3 ATTEMPTS
    cout << "You have reached the limit. Please take your time and enter the correct PIN." << endl;
}

// FUNCTION TO HANDLE DEPOSIT TRANSACTIONS
void deposit_amount(stack<int>& balance, int PIN , vector<time_t>& Time_Tracker) {
    int account_Number; // VARIABLE TO STORE THE ENTERED ACCOUNT NUMBER
    int TOP = 0;        // VARIABLE TO STORE THE TOP VALUE OF THE STACK
    int amount = 0;     // VARIABLE TO STORE THE DEPOSIT AMOUNT

    cout << endl;
    // INFORM THE USER TO ENTER THE ACCOUNT NUMBER CAREFULLY
    cout << "              " << "NOTE : " << "PLEASE ENTER THE ACCOUNT NUMBER CAREFULLY " << endl;

    // ALLOW THE USER 3 ATTEMPTS TO ENTER THE CORRECT ACCOUNT NUMBER
    for (int i = 0; i < 3; i++) {
        cout << "Enter the Account Number : " << endl;
        cin >> account_Number;

        // CHECK IF THE ENTERED ACCOUNT NUMBER MATCHES THE PROVIDED PIN
        if (account_Number == PIN) {
            cout << "Enter the Amount You have to Deposit : " << endl;
            cin >> amount;

            // CHECK IF THE DEPOSIT AMOUNT EXCEEDS THE LIMIT
            if (amount > 50000) {
                cout << "The Amount cannot be accepted Because of Limit Exceeded " << endl;
                return; // EXIT THE FUNCTION IF THE AMOUNT EXCEEDS THE LIMIT
            } else {
                // IF THE STACK IS NOT EMPTY, UPDATE THE BALANCE WITH THE DEPOSIT AMOUNT
                if (!balance.empty()) {
                    auto Current_TIMING = chrono::system_clock::now(); // GET CURRENT TIME
                    time_t CONVERT_TIME = chrono::system_clock::to_time_t(Current_TIMING); // CONVERT TO time_t
                    Time_Tracker.push_back(CONVERT_TIME); // ADD TIMESTAMP TO TRACKER
                    TOP = balance.top(); // GET THE CURRENT TOP VALUE OF THE STACK
                    balance.pop();       // REMOVE THE TOP VALUE FROM THE STACK
                    balance.push(TOP + amount); // PUSH THE UPDATED BALANCE ONTO THE STACK
                    cout << "New Balance: " << balance.top() << endl; // DISPLAY THE NEW BALANCE
                } else {
                    // IF THE STACK IS EMPTY, JUST PUSH THE DEPOSIT AMOUNT ONTO THE STACK
                    balance.push(amount);
                    cout << "New Balance: " << balance.top() << endl; // DISPLAY THE NEW BALANCE
                }
                return; // EXIT THE FUNCTION AFTER A SUCCESSFUL DEPOSIT
            }
        }
    }
    // INFORM THE USER IF THE ACCOUNT NUMBER WAS INCORRECT AFTER 3 ATTEMPTS
    cout << "Account number is incorrect after 3 attempts." << endl;
}

// FUNCTION TO DISPLAY BANKING FACILITIES
void displayBankingFacilities() {
    // PROVIDENT FUND (PF)
    double pfInterestRate = 8.5; // RANDOM INTEREST RATE
    cout << "---- Provident Fund (PF) ----\n";
    cout << "Interest Rate: " << pfInterestRate << "%\n\n";

    // PUBLIC PROVIDENT FUND (PPF)
    double ppfInterestRate = 7.1; // RANDOM INTEREST RATE
    cout << "---- Public Provident Fund (PPF) ----\n";
    cout << "Interest Rate: " << ppfInterestRate << "%\n\n";

    // JAN DHAN YOJANA
    double janDhanInterestRate = 4.0; // RANDOM INTEREST RATE
    cout << "---- Jan Dhan Yojana ----\n";
    cout << "Interest Rate: " << janDhanInterestRate << "%\n\n";

    // FIXED DEPOSIT
    double fdInterestRate = 6.5; // RANDOM INTEREST RATE
    cout << "---- Fixed Deposit ----\n";
    cout << "Interest Rate: " << fdInterestRate << "%\n\n";

    // RECURRING DEPOSIT
    double rdInterestRate = 5.8; // RANDOM INTEREST RATE
    cout << "---- Recurring Deposit ----\n";
    cout << "Interest Rate: " << rdInterestRate << "%\n\n";

    // SAVINGS ACCOUNT
    double savingsInterestRate = 3.5; // RANDOM INTEREST RATE
    cout << "---- Savings Account ----\n";
    cout << "Interest Rate: " << savingsInterestRate << "%\n\n";

    // SENIOR CITIZEN SAVINGS SCHEME
    double scssInterestRate = 8.0; // RANDOM INTEREST RATE
    cout << "---- Senior Citizen Savings Scheme ----\n";
    cout << "Interest Rate: " << scssInterestRate << "%\n\n";

    // SUKANYA SAMRIDDHI YOJANA
    double ssyInterestRate = 7.6; // RANDOM INTEREST RATE
    cout << "---- Sukanya Samriddhi Yojana ----\n";
    cout << "Interest Rate: " << ssyInterestRate << "%\n\n";
}

// FUNCTION TO CALCULATE INTEREST
void Intrest_Calculation() {
    int year; // DECLARE VARIABLE TO STORE NUMBER OF YEARS
    int AMOUNT; // DECLARE VARIABLE TO STORE THE AMOUNT
 cout<< "                         "<<"NOTE -:"<<"THIS WILL CALCULATE THE INTEREST RATE OF YOURE ENTERED AMOUNT"<<endl;
    cout << "Enter the Amount : " << " "; // PROMPT USER TO ENTER THE AMOUNT
    cin >> AMOUNT; // READ THE AMOUNT ENTERED BY THE USER
    cout << "Enter The Number Of Year You Have To get : " << " "; // PROMPT USER TO ENTER NUMBER OF YEARS
    cin >> year; // READ THE NUMBER OF YEARS ENTERED BY THE USER

    // CALCULATE INTEREST BASED ON NUMBER OF YEARS
    if (year <= 2) {
        cout << "Your Interest Rate Per Year Will Be " << "5% " << "The Amount Will Be " << (AMOUNT / 100) * 5 << endl; // DISPLAY INTEREST RATE AND AMOUNT FOR <= 2 YEARS
    } else if (year > 2 && year <= 5) {
        cout << "Your Interest Rate Per Year Will Be " << "8% " << "The Amount Will Be " << (AMOUNT / 100) * 8 << endl; // DISPLAY INTEREST RATE AND AMOUNT FOR > 2 AND <= 5 YEARS
    } else if (year > 5 && year <= 8) {
        cout << "Your Interest Rate Per Year Will Be " << "10% " << "The Amount Will Be " << (AMOUNT / 100) * 10 << endl; // DISPLAY INTEREST RATE AND AMOUNT FOR > 5 AND <= 8 YEARS
    } else {
        cout << "THE INTEREST WILL BE INCREASED AS PER THE YEAR INCREASE " << endl; // DISPLAY MESSAGE FOR YEARS > 8
        cout << "FOR MORE DETAILS YOU CAN CONTACT US IN OUR BANK WILL BE OPENED FROM 10:00 AM TO 4:30 PM " << endl; // DISPLAY BANK CONTACT INFORMATION
    }

    // ADDITIONAL FEATURES
    cout << "Would you like to calculate the total interest earned? (yes/no): "; // PROMPT USER TO CALCULATE TOTAL INTEREST EARNED
    string response;
    cin >> response; // READ USER'S RESPONSE

    if (response == "yes") {
        double total_interest = 0; // DECLARE VARIABLE TO STORE TOTAL INTEREST

        // CALCULATE TOTAL INTEREST BASED ON YEAR RANGE
        if (year <= 2) {
            total_interest = (AMOUNT * 5 / 100) * year; // CALCULATE TOTAL INTEREST FOR <= 2 YEARS
        } else if (year > 2 && year <= 5) {
            total_interest = (AMOUNT * 8 / 100) * year; // CALCULATE TOTAL INTEREST FOR > 2 AND <= 5 YEARS
        } else if (year > 5 && year <= 8) {
            total_interest = (AMOUNT * 10 / 100) * year; // CALCULATE TOTAL INTEREST FOR > 5 AND <= 8 YEARS
        }

        cout << "Total interest earned over " << year << " years is: " << total_interest << endl; // DISPLAY TOTAL INTEREST EARNED
    }

    cout << "Would you like to see a yearly breakdown of interest? (yes/no): "; // PROMPT USER TO SEE YEARLY BREAKDOWN OF INTEREST
    cin >> response; // READ USER'S RESPONSE

    if (response == "yes") {
        // DISPLAY YEARLY BREAKDOWN OF INTEREST
        for (int i = 1; i <= year; ++i) {
            double yearly_interest = 0; // DECLARE VARIABLE TO STORE YEARLY INTEREST

            // CALCULATE YEARLY INTEREST BASED ON YEAR RANGE
            if (i <= 2) {
                yearly_interest = (AMOUNT * 5 / 100); // CALCULATE YEARLY INTEREST FOR <= 2 YEARS
            } else if (i > 2 && i <= 5) {
                yearly_interest = (AMOUNT * 8 / 100); // CALCULATE YEARLY INTEREST FOR > 2 AND <= 5 YEARS
            } else if (i > 5 && i <= 8) {
                yearly_interest = (AMOUNT * 10 / 100); // CALCULATE YEARLY INTEREST FOR > 5 AND <= 8 YEARS
            }

            cout << "Year " << i << ": " << yearly_interest << " interest" << endl; // DISPLAY INTEREST FOR EACH YEAR
        }
    }
}

// FUNCTION TO WITHDRAW AMOUNT
void Withdraw_Amount(stack<int>& balance, int PIN) {
    int counter = 0 ; // COUNTER FOR PIN ATTEMPTS
    int ACCEPT_PIN_FROM_THE_USER; // VARIABLE TO ACCEPT PIN FROM USER
    cout << "Enter The Account PIN : " << endl;
    for(int i= 0 ; i<3; i++) {
        cin >> ACCEPT_PIN_FROM_THE_USER;
        counter += 1; // INCREMENT COUNTER FOR EACH ATTEMPT
        if(ACCEPT_PIN_FROM_THE_USER == PIN) { // CHECK IF ENTERED PIN IS CORRECT

            if (balance.empty()) {       // CHECK IF STACK 'balance' IS EMPTY
                cout << "There is No Amount in Your Account" << endl; // PRINT MESSAGE IF STACK IS EMPTY
            } else {                     // IF STACK IS NOT EMPTY
                int Amount_In_Account;   // DECLARE VARIABLE 'Amount_In_Account'
                Amount_In_Account = balance.top(); // ASSIGN TOP ELEMENT OF STACK TO 'Amount_In_Account'
                balance.pop();           // REMOVE TOP ELEMENT FROM STACK
                int Required_Amount;     // DECLARE VARIABLE 'Required_Amount'
                cout << "Enter the Required Amount You Need to Withdraw: " << endl; // PROMPT USER TO ENTER REQUIRED AMOUNT
                cin >> Required_Amount;  // READ REQUIRED AMOUNT FROM USER INPUT

                if (Required_Amount < Amount_In_Account) { // CHECK IF REQUIRED AMOUNT IS LESS THAN AMOUNT IN ACCOUNT
                    Amount_In_Account -= Required_Amount;  // DEDUCT REQUIRED AMOUNT FROM 'Amount_In_Account'
                    balance.push(Amount_In_Account);       // PUSH UPDATED 'Amount_In_Account' BACK TO STACK
                } else {
                    cout << "The Entered Amount Is Not In Your Account In Current Situation " << endl;
                }
            }
            cout << "Your Amount In The Account Is : " << balance.top(); // PRINT THE TOP ELEMENT OF STACK 'balance'
            exit(0); // EXIT THE FUNCTION
        } else {
            cout << "Enter The Correct PIN " << endl;
            if(counter == 3) {
                cout << "Please Go To Your Bank And Change Your PIN Until Then We Will Make No Transition In Your Account" << endl;
            }
        }
    }
}

// FUNCTION TO TRACK TRANSACTION HISTORY
void History_Tracker(const vector<time_t>& Time_Tracker) {
    cout<<"                        "<<"********TRANSITION HISTORY OF YOUR BANK ACCOUNT********"<<endl;
    if (Time_Tracker.empty()) {
    cout<<"           "<< "No Transition Had Made Until Now" << endl;
    } else {
        for (size_t i = 0; i < Time_Tracker.size(); i++) {
            cout << ctime(&Time_Tracker[i]) << " ";
        }
    }
}

// MAIN FUNCTION
int main() {
    cout<<"                        "<<" .......@$@$$@$@$@$@$@$@$@$@$ "<<" Welcome To Dark_Web  "<<" @$@$$@$@$@$@$@$@$@$@$......."<<endl;
    cout<<endl;
    cout<<endl;

   display_instructions(); // FUNCTION TO DISPLAY INSTRUCTIONS
        cout<<endl;
        cout<<endl;
    int option; // VARIABLE TO STORE USER OPTION
    vector<time_t> Time_Tracker; // VECTOR TO STORE TIME OF TRANSACTIONS
    stack<int> balance; // STACK TO STORE BALANCE
    balance.push(30000); // INITIAL BALANCE

    auto Present_Time = chrono::system_clock::now(); // GET CURRENT TIME
    time_t Convert_Time = chrono::system_clock::to_time_t(Present_Time); // CONVERT TO time_t
    Time_Tracker.push_back(Convert_Time); // ADD TO TIME TRACKER

    int PIN = 143; // SET ACCOUNT PIN

    cout << "Enter an option (1-6): "; // PROMPT USER TO ENTER OPTION
    cin >> option; // READ USER OPTION
    try {
        switch(option) {
            case 1:
                deposit_amount(balance, PIN, Time_Tracker); // CALL FUNCTION TO DEPOSIT AMOUNT
                break;
            case 2:
                check_balance(balance, PIN); // CALL FUNCTION TO CHECK BALANCE
                break;
            case 3:
                displayBankingFacilities(); // CALL FUNCTION TO DISPLAY BANKING FACILITIES
                break;
            case 4:
                Intrest_Calculation(); // CALL FUNCTION TO CALCULATE INTEREST
                break;
            case 5:
                Withdraw_Amount(balance, PIN); // CALL FUNCTION TO WITHDRAW AMOUNT
                break;
            case 6:
                History_Tracker(Time_Tracker); // CALL FUNCTION TO TRACK HISTORY
                break;
            default:
                throw invalid_argument("Invalid option. Please enter a number between 1 and 6."); // THROW EXCEPTION FOR INVALID OPTION
        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // CATCH EXCEPTION AND DISPLAY ERROR MESSAGE
    }
    cout<<endl;
    cout<<endl;

    cout<< "                 "<<"#########################"<<"  "<<" THANK FOR USING OUR BANK " <<" "<<"#########################"<<endl;
    cout<<endl;

    cout<< "                    "<<"*****************"<<"  "<<" VISITE AGAIN " <<" "<<"*****************"<<endl;

    return 0; // RETURN SUCCESS
}
