import random
import json

# Initialize empty lists and dictionaries to store data
users = []
complaints = {"MessFood": [], "HostelCondition": []}
student_info = []
mess_menu = {}
attendance_records = []
mess_amounts = []
contacts = {"Warden": {}, "Dean": {}, "Supervisor": {}}
authenticated_users = set()

# Load data from text files (if available)
def load_data():
    try:
        with open("users.txt", "r") as user_file:
            users.extend(json.load(user_file))
        with open("complaints.txt", "r") as complaints_file:
            complaints.update(json.load(complaints_file))
        with open("mess_menu.txt", "r") as menu_file:
            mess_menu.update(json.load(menu_file))
        with open("attendance_records.txt", "r") as attendance_file:
            attendance_records.extend(json.load(attendance_file))
        with open("mess_amounts.txt", "r") as amounts_file:
            mess_amounts.extend(json.load(amounts_file))
        with open("contacts.txt", "r") as contacts_file:
            contacts.update(json.load(contacts_file))
    except FileNotFoundError:
        pass

# Save data to text files
def save_data():
    with open("users.txt", "w") as user_file:
        json.dump(users, user_file)
    with open("complaints.txt", "w") as complaints_file:
        json.dump(complaints, complaints_file)
    with open("mess_menu.txt", "w") as menu_file:
        json.dump(mess_menu, menu_file)
    with open("attendance_records.txt", "w") as attendance_file:
        json.dump(attendance_records, attendance_file)
    with open("mess_amounts.txt", "w") as amounts_file:
        json.dump(mess_amounts, amounts_file)
    with open("contacts.txt", "w") as contacts_file:
        json.dump(contacts, contacts_file)

# Load data at the beginning of the program
load_data()

# Register a single Dean for all hostels
dean = {
    "Email": "dean@nits.ac.in",
    "Password": "dean_password",
    "Role": "Dean",
    "Hostel": "BH1"  # Assign the Dean to BH1
}

# Register Supervisor, MMC, and Mess Manager for each hostel
supervisor_bh1 = {
    "Email": "supervisor_bh1@nits.ac.in",
    "Password": "supervisor_password",
    "Role": "Supervisor",
    "Hostel": "BH1"
}

supervisor_bh2 = {
    "Email": "supervisor_bh2@nits.ac.in",
    "Password": "supervisor_password",
    "Role": "Supervisor",
    "Hostel": "BH2"
}

supervisor_gh1 = {
    "Email": "supervisor_gh1@nits.ac.in",
    "Password": "supervisor_password",
    "Role": "Supervisor",
    "Hostel": "GH1"
}

mmc_bh1 = {
    "Email": "mmc_bh1@nits.ac.in",
    "Password": "mmc_password",
    "Role": "MMC",
    "Hostel": "BH1"
}

mmc_bh2 = {
    "Email": "mmc_bh2@nits.ac.in",
    "Password": "mmc_password",
    "Role": "MMC",
    "Hostel": "BH2"
}

mmc_gh1 = {
    "Email": "mmc_gh1@nits.ac.in",
    "Password": "mmc_password",
    "Role": "MMC",
    "Hostel": "GH1"
}

mess_manager_bh1 = {
    "Email": "manager_bh1@nits.ac.in",
    "Password": "manager_password",
    "Role": "MessManager",
    "Hostel": "BH1"
}

mess_manager_bh2 = {
    "Email": "manager_bh2@nits.ac.in",
    "Password": "manager_password",
    "Role": "MessManager",
    "Hostel": "BH2"
}

mess_manager_gh1 = {
    "Email": "manager_gh1@nits.ac.in",
    "Password": "manager_password",
    "Role": "MessManager",
    "Hostel": "GH1"
}

# Register the roles
users.extend([
    dean,
    supervisor_bh1, supervisor_bh2, supervisor_gh1,
    mmc_bh1, mmc_bh2, mmc_gh1,
    mess_manager_bh1, mess_manager_bh2, mess_manager_gh1
])

# Constants for mess bill per day (per hostel)
mess_bill_bh1 = 100  # Example values, please replace with actual rates
mess_bill_bh2 = 90
mess_bill_gh1 = 95

# Hostel capacity limits
bh1_capacity = 5
bh2_capacity = 10
gh1_capacity = 5

# Function to calculate initial fee for each student
def calculate_initial_fee():
    # Assuming equal fee for all students
    initial_fee = 1000  # You can adjust the initial fee amount

    for student in users:
        student["InitialFee"] = initial_fee

# Function to calculate mess refund for each student
def calculate_mess_refund():
    for student in users:
        # Calculate the refund based on mess bill and attendance
        if student["Hostel"] == "BH1":
            mess_bill = mess_bill_bh1
        elif student["Hostel"] == "BH2":
            mess_bill = mess_bill_bh2
        else:
            mess_bill = mess_bill_gh1

        student["DaysPresent"] = random.randint(10, 30)  # Random days present for testing
        student["MessRefund"] = student["InitialFee"] - (mess_bill * student["DaysPresent"])

# Function to submit complaints
def submit_complaints():
    category = input("Enter complaint category (MessFood or HostelCondition): ")
    complaint_text = input("Enter your complaint: ")
    complaints[category].append(complaint_text)
    print("Complaint submitted successfully!")

# Function to record attendance
# Function to record attendance
def record_attendance():
    hostel = input("Enter hostel number: ")
    supervisor_password = input("Enter supervisor's password: ")

    if supervisor_password == "supervisor_password":  # Replace with the actual password
        for student in users:
            if 'Name' in student:
                presence = input(f"Is {student['Name']} present (1 for present, 0 for absent): ")
                student["DaysPresent"] = int(student.get("DaysPresent", 0)) + int(presence)
        print("Attendance recorded successfully!")
    else:
        print("Supervisor password incorrect. Attendance recording failed.")

# Function to manage hostels based on scores
def allot_hostels():
    sorted_students = sorted(users, key=lambda student: random.randint(0, 100), reverse=True)
    bh1_count = bh2_count = gh1_count = 0

    for student in sorted_students:
        if gh1_count < gh1_capacity and student["Gender"] == "Girl":
            student["Hostel"] = "GH1"
            gh1_count += 1
        elif bh1_count < bh1_capacity:
            student["Hostel"] = "BH1"
            bh1_count += 1
        elif bh2_count < bh2_capacity:
            student["Hostel"] = "BH2"
            bh2_count += 1
        else:
            print("No more capacity. Allocation complete.")
            break

# Function to change the mess menu (for MMC)
def change_mess_menu():
    day = input("Enter the day of the week (e.g., Monday): ")
    new_item = input(f"Enter the new menu item for {day}: ")
    mess_menu[day] = new_item
    print(f"Menu for {day} updated to: {new_item}")

# Function for user signup
def signup():
    email = input("Enter email (ending with @nits.ac.in): ")
    password = input("Enter password: ")

    if email.endswith("@nits.ac.in"):
        gender = "Boy" if len(users) < 10 else "Girl"
        student = {
            "Email": email,
            "Password": password,
            "Gender": gender,
            "Name": input("Enter your name: "),
            "ScholarID": input("Enter your scholar ID: "),
            "Semester": input("Enter your semester: "),
            "Hostel": "",
            "Role": "Student",
        }
        users.append(student)
        print(f"Registration successful for {student['Name']}")
    else:
        print("Invalid email address. Please use an @nits.ac.in email.")

# Function to view student information
def view_student_information():
    print("Student Information:")
    for student in users:
        print(f"Name: {student['Name']}, Email: {student['Email']}, ScholarID: {student['ScholarID']}")

# Function for user sign-in
def sign_in():
    email = input("Enter your email: ")
    password = input("Enter your password: ")

    # Check if the user is already authenticated
    if email in authenticated_users:
        print("You are already authenticated.")
        return

    user = next((user for user in users if user["Email"] == email), None)
    if user is not None and user["Password"] == password:
        role = user["Role"]
        if role not in {"Dean", "Supervisor", "MMC", "MessManager"}:
            print(f"Welcome, {user['Name']}! You are authenticated as a {role}.")
        else:
            print(f"Welcome! You are authenticated as a {role}.")
        authenticated_users.add(email)
        return role
    else:
        print("Authentication failed. Invalid email or password.")
        return None

def print_hostel_boarders():
    role = input("Enter your role (Dean, Supervisor, or Warden): ")
    hostel = input("Enter the hostel (BH1, BH2, or GH1): ")

    if role in {"Dean", "Supervisor", "Warden"} and hostel in {"BH1", "BH2", "GH1"}:
        print(f"Boarders in {hostel}:")
        for student in users:
            if student["Hostel"] == hostel:
                print(f"Name: {student['Name']}, ScholarID: {student['ScholarID']}")
    else:
        print("Invalid role or hostel. Not allowed.")

# Main program
while True:
    print("Hostel Management System Menu:")
    print("1. Sign In")
    print("2. Sign Up")
    print("3. Print Hostel Boarders")
    print("99. Exit")

    choice = input("Enter your choice (1-9, 0, 99): ")

    if choice == "1":  # Sign In
        role = sign_in()
        if role:
            if role == "Student":
                print("1. File Complaints")
                print("2. View Mess Refund")
                sub_choice = input("Enter your choice (1-2): ")
                if sub_choice == "1":
                    submit_complaints()
                elif sub_choice == "2":
                    calculate_mess_refund()
                else:
                    print("Not allowed.")
            elif role == "MMC":
                print("1. Change Mess Menu")
                sub_choice = input("Enter your choice (1): ")
                if sub_choice == "1":
                    change_mess_menu()
                else:
                    print("Not allowed.")
            elif role in {"Dean", "Warden", "Supervisor"}:
                print("1. File Complaints")
                print("2. View Mess Refund")
                print("3. Allot Hostels")
                print("4. Record Attendance")
                print("5. Print Hostel Boarders")  # New option
                sub_choice = input("Enter your choice (1-5): ")
                if sub_choice == "1":
                    submit_complaints()
                elif sub_choice == "2":
                    calculate_mess_refund()
                elif sub_choice == "3":
                    allot_hostels()
                elif sub_choice == "4":
                    record_attendance()
                elif sub_choice == "5":
                    print_hostel_boarders()  # New function
                else:
                    print("Not allowed.")
            elif role == "MessManager":
                print("1. Change Menu Rate")
                sub_choice = input("Enter your choice (1): ")
                if sub_choice == "1":
                    change_mess_menu()
                else:
                    print("Not allowed.")
    elif choice == "2":
        signup()

    elif choice == "3":
        print_hostel_boarders()  # New option
    
    elif choice == "99":
        save_data()
        break
