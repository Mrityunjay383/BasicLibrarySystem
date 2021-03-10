#include<iostream>
using namespace std;

int main(){

    int n = 50;

    int avalBooksC[n];
    int totalAval = 0;

    int issuedBooksC[n];
    int totalIssued = 0;

    int CurrentBookcode;

    while(true){

        char command;
        cout << "Please enter command ('a' for adding, 'i' for issuing, 'r' for returning, 's' for summary, and 'x' for terminating)" << endl;
        cin >> command;

        if(command == 'a'){
            cout << "Please privide book Code to be added:" << endl;
            cin >> CurrentBookcode;
            avalBooksC[totalAval] = CurrentBookcode;
            totalAval++;
            cout << "Book with Code " << CurrentBookcode << " is added succesfully" << endl;

        }else if(command == 'i'){
            if(totalAval == 0){
                cout << "Sorry no books are avalaibl, please add some!!" << endl;
            }else{
                cout << "Please provide the book Code to be issued:" << endl;
                cin >> CurrentBookcode;

                bool aval = false;
                for(int i = 0; i < totalAval; i++){
                    if(avalBooksC[i] == CurrentBookcode && !aval){
                        aval = true;
                    }else if(aval){
                        avalBooksC[i - 1] = avalBooksC[i];
                    }
                }
                if(aval){
                    issuedBooksC[totalIssued] = CurrentBookcode;
                    totalIssued++;
                    totalAval--;
                    cout << "Book with code " << CurrentBookcode << " is issued succesfully" << endl;
                }else{
                    cout << "Sorry!! Book with code " << CurrentBookcode << " didn't avaliable in the library" << endl;
                }
            }

        }else if(command == 'r'){
            if(totalIssued == 0){
                cout << "No Book is Issued" << endl;
            }else{
                cout << "Please provide the book Code to be returned:" << endl;
                cin >> CurrentBookcode;

                bool issued = false;
                for(int i = 0; i < totalIssued; i++){
                    if(issuedBooksC[i] == CurrentBookcode && !issued){
                        issued = true;
                    }else if(issued){
                        issuedBooksC[i - 1] = issuedBooksC[i];
                    }
                }
                if(issued){
                    avalBooksC[totalAval] = CurrentBookcode;
                    totalAval++;
                    totalIssued--;
                    cout << "Book with code " << CurrentBookcode << " is returned succesfully" << endl;
                }else{
                    cout << "Book with code " << CurrentBookcode << " is not issued by the library" << endl;
                }
            }
        }
        else if(command == 's'){
            cout << "Number of Avalaible Books are: " << totalAval << endl;
            for(int i = 0; i < totalAval; i++){
                cout << avalBooksC[i] << endl;
            }
            cout << "Number of Issued Books are: " << totalIssued << endl;
            for(int i = 0; i < totalIssued; i++){
                cout << issuedBooksC[i] << endl;
            }
        }
        else if(command == 'x'){
            cout << "Thanks for using the Software";
            break;
        }
        else{
            cout << "Wrong Command!!" << endl;
        }
    }
}
