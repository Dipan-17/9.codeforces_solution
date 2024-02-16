#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Student structure to store student information
struct Student {
    string name;
    string age;
    string phoneNumber;
    string courseApplyingFor;
    double previousGrades;
    double yearlyIncome;
    bool needFinancialAid;
};

// FinancialAid structure to store financial aid information
struct FinancialAid {
    bool isGranted;
};

// Map to store student information
map<string, Student> students;

// Map to store financial aid applications and their status
map<string, FinancialAid> financialAidApplications;

// Function to register a new student
// Function to register a new student
void registerStudent() {
    string email, password;
    cout<<endl;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    Student newStudent;
    cout<<endl;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, newStudent.name);

    cout << "Enter Age: ";
    cin >> newStudent.age;

    cout << "Enter Phone Number: ";
    cin >> newStudent.phoneNumber;

    cout << "Enter Course Applying For: ";
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, newStudent.courseApplyingFor);

    cout << "Enter Previous Grades: ";
    cin >> newStudent.previousGrades;

    cout << "Enter Yearly Income in Lakhs: ";
    cin >> newStudent.yearlyIncome;

    cout << "Need Financial Aid? (1 for Yes, 0 for No): ";
    cin >> newStudent.needFinancialAid;

    // Store student information in the map
    students[email] = newStudent;

    // If the student applied for financial aid, store the application
    if (newStudent.needFinancialAid) {
        FinancialAid aid;
        aid.isGranted = false;
        financialAidApplications[email] = aid;
    }

    cout << "Registration successful!" << endl<<endl;
}

// Function to login for students
void studentLogin() {
    cout<<endl;
    string email, password;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    cout<<endl;
    // Check if the email exists in the map
    if (students.find(email) != students.end()) {
        cout << "Login successful!" << endl;
        cout << "Student Information:" << endl;
        cout << "Name: " << students[email].name << endl;
        cout << "Age: " << students[email].age << endl;
        cout << "Phone Number: " << students[email].phoneNumber << endl;
        cout << "Course Applying For: " << students[email].courseApplyingFor << endl;
        cout << "Previous Grades: " << students[email].previousGrades << endl;

        // Check if the student applied for financial aid
        if (students[email].needFinancialAid) {
            cout << "Financial Aid Status: ";
            if (financialAidApplications[email].isGranted) {
                cout << "Granted" << endl;
            } else {
                cout << "Pending Review" << endl;
            }
        }
    } else {
        cout << "Login failed. Email not found." << endl;
    }
    cout<<endl;
}

// Function to login for financial aid officer
// Function to login for financial aid officer
void officerLogin() {
    string email, password;
    cout<<endl;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    // Check if the email is for the financial aid officer (dummy account)
    if (email == "officer@aid.com" && password == "pass") {
        cout << "Login successful!" << endl;

        // Display all financial aid applications and their status
        for (const auto& entry : financialAidApplications) {
            cout<<endl;
            cout << "Email: " << entry.first << ", Status: ";
            if (entry.second.isGranted) {
                cout << "Granted" << endl;
            } else {
                cout << "Pending Review" << endl<<endl;
                // Display student information for pending applications
                cout << "Student Information:" << endl;
                cout << "Name: " << students[entry.first].name << endl;
                cout << "Age: " << students[entry.first].age << endl;
                cout << "Phone Number: " << students[entry.first].phoneNumber << endl;
                cout << "Course Applying For: " << students[entry.first].courseApplyingFor << endl;
                cout << "Previous Grades: " << students[entry.first].previousGrades << endl;
                cout << "Yearly Income in Lakhs: " << students[entry.first].yearlyIncome << endl;

                // Ask for financial aid decision
                cout<<endl;
                cout << "Financial Aid Decision: " << endl;
                cout << "1. Grant\n2. Reject\n";
                int decision;
                cin >> decision;

                // Update financial aid status based on the decision
                switch (decision) {
                    case 1:
                        financialAidApplications[entry.first].isGranted = true;
                        cout << "Financial aid granted!" << endl;
                        break;
                    case 2:
                        financialAidApplications[entry.first].isGranted = false;
                        cout << "Financial aid rejected." << endl<<endl;
                        break;
                    default:
                        cout << "Invalid decision. Please try again." << endl;
                        break;
                }
            }
            cout<<endl;
        }
    } else {
        cout << "Login failed. Email or password incorrect." << endl<<endl;
    }
}

// Function to generate dummy data
void dummyData() {
    

    // Dummy student 1 (Applying for financial aid with income below 5 lakhs)
    Student student1;
    student1.name = "Rahul Sharma";
    student1.age = "21";
    student1.phoneNumber = "9876543210";
    student1.courseApplyingFor = "Computer Science";
    student1.previousGrades = 78.5;
    student1.yearlyIncome = 2.1; // Random income below 5 lakhs
    student1.needFinancialAid = true;

    students["rahul@example.com"] = student1;
    if (student1.needFinancialAid) {
        FinancialAid aid;
        aid.isGranted = false;
        financialAidApplications["rahul@example.com"] = aid;
    }

    // Dummy student 2 (Applying for financial aid with income below 5 lakhs)
    Student student2;
    student2.name = "Priya Gupta";
    student2.age = "20";
    student2.phoneNumber = "8765432109";
    student2.courseApplyingFor = "Electrical Engineering";
    student2.previousGrades = 85.2;
    student2.yearlyIncome = 0.2; // Random income below 5 lakhs
    student2.needFinancialAid = true;

    students["priya@example.com"] = student2;
    if (student2.needFinancialAid) {
        FinancialAid aid;
        aid.isGranted = false;
        financialAidApplications["priya@example.com"] = aid;
    }

    // Dummy student 3 (Applying for financial aid with income above 20 lakhs)
    Student student3;
    student3.name = "Amit Singh";
    student3.age = "22";
    student3.phoneNumber = "7654321098";
    student3.courseApplyingFor = "Mechanical Engineering";
    student3.previousGrades = 76.8;
    student3.yearlyIncome = 23.2; // Random income above 20 lakhs
    student3.needFinancialAid = true;

    students["amit@example.com"] = student3;
    if (student3.needFinancialAid) {
        FinancialAid aid;
        aid.isGranted = false;
        financialAidApplications["amit@example.com"] = aid;
    }

    // Dummy student 4 (Not applying for financial aid with income above 50 lakhs)
    Student student4;
    student4.name = "Neha Patel";
    student4.age = "23";
    student4.phoneNumber = "6543210987";
    student4.courseApplyingFor = "Civil Engineering";
    student4.previousGrades = 92.3;
    student4.yearlyIncome = 93; // Random income above 50 lakhs
    student4.needFinancialAid = false;

    students["neha@example.com"] = student4;

    // Dummy student 5 (Not applying for financial aid with income above 50 lakhs)
    Student student5;
    student5.name = "Raj Kapoor";
    student5.age = "24";
    student5.phoneNumber = "5432109876";
    student5.courseApplyingFor = "Business Administration";
    student5.previousGrades = 88.6;
    student5.yearlyIncome = 22; // Random income above 50 lakhs
    student5.needFinancialAid = false;

    students["raj@example.com"] = student5;

    // students["rahul@example.com"].password = "rahul";
    // students["priya@example.com"].password = "priya";
    // students["amit@example.com"].password = "amit";
    // students["neha@example.com"].password = "neha";
    // students["raj@example.com"].password = "raj";
}


int main() {
    int choice;
    cout<<"-----------------------------WELCOME TO ADMISSION PORTAL-------------------------------------";
    dummyData();

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Register\n2. Student Login\n3. Financial Aid Officer Login\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerStudent();cout<<endl;
                
                break;
            case 2:
                studentLogin();cout<<endl;
                break;
            case 3:
                officerLogin();cout<<endl;
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;cout<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;cout<<endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
