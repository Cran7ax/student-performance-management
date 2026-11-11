#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student{
    private:
	int Phy, Chem, Math;
        int Sum_Marks;
        double Percentage;
        char Grade;
        string First_Name, Last_Name;
        long long Roll_No;
    public:

        void Input_Details(){
            int Validated_Token;
            cout << "\n";
            cout << "Enter First Name: ";
            cin >> First_Name;
            cout << "Enter Last Name: ";
            cin >> Last_Name;
            cout << "Enter Enrollment Number: ";
            cin >> Roll_No;
            cout << "Enter Marks Of Physics: ";
            cin >> Phy;
            cout << "Enter Marks Of Chemistry: ";
            cin >> Chem;
            cout << "Enter Marks Of Math: ";
            cin >> Math;
            Validated_Token = Validate_Marks(Phy, Chem, Math);
            if(Validated_Token == 1234){
                cout << "\nTry Again!\n";
                Input_Details();
            }
            cout << "\n";
        }

        int Validate_Marks(int Sub1, int Sub2, int Sub3){
            if(Sub1 > 100 || Sub2 > 100 || Sub3 > 100){
                cout << "ERROR: Marks Cannot Be Greater Then 100!\n";
                return 1234;
            }else if(Sub1 < 0 || Sub2 < 0 || Sub3 < 0){
                cout << "ERROR: Marks Cannot Be Negetive!\n";
                return 1234;
            }
            return 0;
        }

        void Calculate_Total(){
            Calculate_Everything();
            cout << "Total Marks: " << Sum_Marks;
            cout << "\n";
        }

        void Calculate_Percentage(){
            Calculate_Everything();
            cout << "Percentage: " << Percentage << "%";
            cout << "\n";
        }
        
        void Calculate_Everything(){
            Sum_Marks = Phy + Chem + Math;
            Percentage = Sum_Marks / 3.00;

            if(Percentage <0.00 || Percentage > 100.00){
                Grade = '?';
                cout << "\nInvalid Marks!\n";
                return;
            }else if(Percentage >= 90.00){
                Grade = 'S';
            }else if(Percentage >= 80.00){
                Grade = 'A';
            }else if(Percentage >= 70.00){
                Grade = 'B';
            }else if(Percentage >= 60.00){
                Grade = 'C';
            }else if(Percentage >= 50.00){
                Grade = 'D';
            }else if(Percentage < 50.00){
                Grade = 'F';
            }else{
                cout << "\nInvalid Marks!\n";
            }
        }

        void Get_Grade(){
            Calculate_Everything();
            cout << "Grade: " << Grade;
            cout << "\n";
        }

        void Update_Details(){
            int choice, Token;
            int TempP, TempC, TempM;
            cout << "1. Update Name.\n2. Update Marks.\nEnter Choice: ";
            cin >> choice;
                switch(choice){
                    case 1:
                    cout << "Enter New First Name: ";
                    cin >> First_Name;
                    cout << "Enter New Last Name: ";
                    cin >> Last_Name;
                    cout << "\nDetails Updated Successfully!\n";
                    break;

                    case 2:
                    cout << "New Marks For Physics: ";
                    cin >> TempP;
                    cout << "New Marks For Chemistry: ";
                    cin >> TempC;
                    cout << "New Marks For Mathematics: ";
                    cin >> TempM;
                    Token = Validate_Marks(TempP, TempC, TempM);
                    if(Token == 1234){
                        cout << "\nERROR: INVALID MARKS: Try Again!\n";
                        Update_Details();
                    }else{
                        Phy = TempP;
                        Chem = TempC;
                        Math = TempM;
                        cout << "\nDetails Updated Successfully!\n";
                    }
                    Calculate_Everything();
                    break;

                    default:
                    cout << "\nERROR: INVALID INPUT\n";
                    break;
                }
        }

        void Report();

        long long Get_Roll(){
            return Roll_No;
        }

        int Get_TMarks(){
            Calculate_Everything();
            return Sum_Marks;
        }

        string RFN(){
            return First_Name;
        }

        string RLN(){
            return Last_Name;
        }

        int Get_Percentage(){
            return Percentage;
        }
};

void Student :: Report(){ //Had to take help for this cause i genuinely dont know how setw and precision worked... Well now i know why small values didnt work 😑 (also idk why is suggested to write this function outside the function but issok i guess im not using too much brain on this cause im already using too much 🤧)
            Calculate_Everything();
            cout << "\n\n--- Student Report ---\n";
            cout << left << setw(22) << "Name: " << First_Name << " " << Last_Name << endl;
            cout << left << setw(22) << "Enrollment Number: " << Roll_No << endl;
            cout << left << setw(22) << "Physics: " << Phy << endl;
            cout << left << setw(22) << "Chemistry: " << Chem << endl;
            cout << left << setw(22) << "Mathematics: " << Math << endl;
            cout << left << setw(22) << "Total Marks: " << Sum_Marks << endl;
            cout << left << setw(22) << "Percentage: "
            << fixed << setprecision(2) << Percentage << "%" << endl;
            cout << left << setw(22) << "Grade: " << Grade << endl;
            cout << "\n";
        }

struct Node{
    Student S;
    Node* Next = nullptr;
};

class StudentList{
    private:
        Node* Head;

    public:
        StudentList(){
            Head = NULL;
       }

        void Add_Student(){ //Barely Alive
            Node* NewStudent = new Node;
            if(NewStudent == NULL){
                cout << "Memory Allocation Failed!\n";
                return;
            }

            NewStudent -> S.Input_Details();
            Node* Temp = Head;
            while(Temp != NULL){
                if(Temp -> S.Get_Roll() == NewStudent -> S.Get_Roll()){
                    cout << "\nDuplicate Enrollment Number!\n";
                    delete NewStudent;
                    return;
                }
                Temp = Temp -> Next;
            }

            if(Head == NULL){
                Head = NewStudent;
            }else{
                Node* Temp = Head;
                while(Temp -> Next != NULL){
                    Temp = Temp -> Next;
                }
                Temp -> Next = NewStudent;
            }
        }

        void Display_All_Students(){
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }else{
                Node* Temp = Head;
                while(Temp != NULL){
                    Temp -> S.Report();
                    cout << "\n";
                    Temp = Temp -> Next;
                }
            }
        }

        void Search_Student(){
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }
            long long Enroll;
            cout << "Enter Enrollment Number To Search: ";
            cin >> Enroll;
            Node* Temp = Head;
            while(Temp != NULL){
                if(Temp -> S.Get_Roll() == Enroll){
                    Temp -> S.Report();
                    return;
                }
                else{
                    Temp = Temp -> Next;
                }
            }
            cout << "\nStudent Not Found!\n";
            return;
        }

        void Search_Student(const string& FN, const string& LN){
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }
            Node* Temp = Head;
            bool Found = false;
            while(Temp != NULL){
                if(Temp -> S.RFN() == FN && Temp -> S.RLN() == LN){
                    Temp -> S.Report();
                    Found = true;
                }
                Temp = Temp -> Next;
            }
            if(Found == false){
                cout << "\nStudent Not Found!\n";
                return;
            }
        }

        void Delete_Student(){ // Don't Know How But It Works So Just Dont Touch It Again 🙏
            long long Del_Enroll;
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }
            Node* Temp = Head;
            Node *Prev = NULL;
            cout << "Enter Enrollment Number: ";
            cin >> Del_Enroll;
            while(Temp != NULL){
                if(Temp -> S.Get_Roll() == Del_Enroll){
                    if(Temp == Head){
                        Head = Head -> Next;
                        delete Temp;
                        cout << "\nStudent Deleted!\n";
                        return;
                    }else{
                        Prev -> Next = Temp -> Next;
                        delete Temp;
                        cout << "\nStudent Deleted!\n\n";
                        return;
                    }
                }
                else{
                    Prev = Temp;
                    Temp = Temp -> Next;
                }
            }
            cout << "\nStudent Not Found!\n";
            return;
        }

        void Update_Student(){
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }
            long long Enroll;
            cout << "Enter Student Enrollment Number: ";
            cin >> Enroll;
            Node* Temp = Head;
            while(Temp != NULL){
                if(Enroll == Temp -> S.Get_Roll()){
                    Temp -> S.Update_Details();
                    return;
                }
                Temp = Temp -> Next;
            }
            cout << "\nStudent Not Found!\n";
            return;
        }

        void Find_Topper(){
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return;
            }
            Node * Topper = Head;
            Node* Temp = Head;
            while(Temp != NULL){
                if(Temp -> S.Get_TMarks() > Topper -> S.Get_TMarks()){
                    Topper = Temp;
                }
                Temp = Temp -> Next;
            }
            Temp = Head;
            cout << "Topper(s) Are/Is: ";
            while(Temp != NULL){
                if(Temp -> S.Get_TMarks() == Topper -> S.Get_TMarks()){
                    Temp -> S.Report();
                }
                cout << "\n";
                Temp = Temp -> Next;
            }
        }

        void Statistics(){
            int Count =  Count_Students();
            if(Count == 0){
                return;
            }
            Node* Temp = Head;
            int Total_Marks = 0, Pass = 0, Fail = 0;
            float Percent, AVG_Percentage;
            int Highest = Temp -> S.Get_TMarks(), Lowest = Temp -> S.Get_TMarks();
            while(Temp != NULL){
                Total_Marks += Temp -> S.Get_TMarks();
                Percent = Temp -> S.Get_TMarks() / 3.0;
                if(Percent >= 50){
                    Pass++;
                }else{
                    Fail++;
                }

                if(Temp -> S.Get_TMarks() > Highest){
                    Highest = Temp -> S.Get_TMarks();
                }else if(Temp -> S.Get_TMarks() < Lowest){
                    Lowest = Temp -> S.Get_TMarks();
                }
                Temp = Temp -> Next;
            }
            //ALMOST WENT CRAZY 😭
            AVG_Percentage = Total_Marks / (3.0 * Count);
            cout << left << setw(30) << "Total Students: " << Count << endl;
            cout << left << setw(30) << "Class Average Percentage: "
            << fixed << setprecision(2) << AVG_Percentage << "%" << endl;
            cout << left << setw(30) << "Highest Total Marks: " << Highest << endl;
            cout << left << setw(30) << "Lowest Total Marks: " << Lowest << endl;
            cout << left << setw(30) << "Passed: " << Pass << endl;
            cout << left << setw(30) << "Failed: " << Fail << endl;
            return;
        }

        int Count_Students(){
            int Count = 0;
            if(Head == NULL){
                cout << "\nNo Records!\n";
                return 0;
            }
            Node* Temp = Head;
            while(Temp != NULL){
                Count++;
                Temp = Temp -> Next;
            }
            return Count;
        }

        ~ StudentList(){// Had to look into the prac files for this 😭
            Node* Temp = Head;
            while(Temp != NULL){
                Node* NextNode = Temp -> Next;
                delete Temp;
                Temp = NextNode;
            }
        }

};
int main(){
    StudentList List;
    int choice;
    int search_choice;
    string FName;
    string LName;
    do{
        cout << "1. Add Student.\n2. Display All Students.\n3. Search Student.\n4. Find Topper.\n5. Delete Student.\n6. Class Statistics.\n7. Update Student.\n8. Exit.\nEnter Your Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            List.Add_Student();
            break;

            case 2:
            List.Display_All_Students();
            break;

            case 3:
            cout << "1. Search By Enrollment Number.\n2. Search By Name.\nEnter Your Choice: ";
            cin >> search_choice;
            if(search_choice == 1){
                List.Search_Student();
                break;
            }else if(search_choice == 2){
                cout << "Enter First Name: ";
                cin >> FName;
                cout << "Enter Last Name: ";
                cin >> LName;
                List.Search_Student(FName, LName);
                break;
            }else{
                cout << "\nERROR: INVALID INPUT!\n";
                break;
            }
            break;

            case 4:
            List.Find_Topper();
            break;

            case 5:
            List.Delete_Student();
            break;

            case 6:
            List.Statistics();
            break;

            case 7:
            List.Update_Student();
            break;

            case 8:
            cout << "\n\nExiting Student Performance Manager...";
            break;
            
            default:
            cout << "\nERROR: INVALID INPUT!\n";
        }
    }while(choice != 8);//DONT FORGET TO UPDATE THIS AFTER ADDING ANOTHER STUPID FEATURE ❗❗❗❗
    return 0;
}
