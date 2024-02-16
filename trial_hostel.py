# Define data structures to store information
students = []
mess_menu = {"BH1": [], "BH2": [], "GH1": []}
attendance_record = {"BH1": {}, "BH2": {}, "GH1": {}}
hostel_requirements = {"BH1": {}, "BH2": {}, "GH1": {}}
mess_amount = {"BH1": 0, "BH2": 0, "GH1": 0}

# Define roles and their permissions
roles = {
    "Student": ["register", "file_complaint", "view_mess_refund"],
    "Dean": ["allot_hostel", "complaints_management", "mess_refund_calculation"],
    "MMC": ["change_mess_menu"],
    "MessManager": ["change_menu_rate"],
    "Warden": ["complaints_management"],
    "Supervisor": ["complaints_management", "requirements_management"]
}

# Functions to implement use cases
def register_student(email, password, role, name, scholar_id, gender, semester, score):
    if role == "Student" and email.endswith("@nits.ac.in"):
        students.append({"email": email, "password": password, "name": name, "scholar_id": scholar_id, "gender": gender, "semester": semester, "score": score})
        return "Registration successful."
    else:
        return "Invalid registration. Please check your email format and role."

def login(email, password):
    for student in students:
        if student["email"] == email and student["password"] == password:
            return "Student"

    if email == "dean@example.com" and password == "dean_password":
        return "Dean"
    elif email == "mmc@example.com" and password == "mmc_password":
        return "MMC"
    elif email == "manager@example.com" and password == "manager_password":
        return "MessManager"
    elif email == "warden@example.com" and password == "warden_password":
        return "Warden"
    elif email == "supervisor@example.com" and password == "supervisor_password":
        return "Supervisor"

    return None  # Authentication failed

def allot_hostel(student_id):
    student = students[student_id]
    if student["gender"] == "girl":
        if len(attendance_record["GH1"]) < 10:
            attendance_record["GH1"][student["email"]] = 0
            return f"Allotted GH1 to {student['email']}"
        else:
            return "No capacity for girls."
    elif student["gender"] == "boy":
        if len(attendance_record["BH1"]) < 5:
            attendance_record["BH1"][student["email"]] = 0
            return f"Allotted BH1 to {student['email']}"
        elif len(attendance_record["BH2"]) < 10:
            attendance_record["BH2"][student["email"]] = 0
            return f"Allotted BH2 to {student['email']}"
        else:
            return "No capacity for boys."

def change_mess_menu(role, hostel, new_menu_item):
    if role == "MMC":
        mess_menu[hostel].append(new_menu_item)
        return "Menu updated successfully."
    else:
        return "Permission denied."

def change_menu_rate(role, hostel, new_rate):
    if role == "MessManager":
        mess_amount[hostel] = new_rate
        return "Menu rate updated successfully."
    else:
        return "Permission denied."

def complaints_management(role, complaint_type, complaint_text):
    if role in ["Warden", "Supervisor"]:
        complaint = {"type": complaint_type, "text": complaint_text}
        # You can add logic here to handle complaints based on the role
        return f"Complaint '{complaint_type}' filed successfully."
    else:
        return "Permission denied."

def requirements_management(role, hostel, rooms, students, beds, chairs):
    if role == "Supervisor":
        # Implement hostel requirements management
        # You can add logic here to update the hostel requirements based on the role
        hostel_requirements[hostel] = {
            "rooms": rooms,
            "students": students,
            "beds": beds,
            "chairs": chairs
        }
        return f"Hostel requirements for {hostel} updated successfully."
    else:
        return "Permission denied."

def mess_refund_calculation(role):
    if role in ["Dean", "MMC"]:
        for student in students:
            email = student["email"]
            attendance = sum(attendance_record[hostel][email] for hostel in attendance_record if email in attendance_record[hostel])
            daily_cost = sum(mess_amount[hostel] for hostel in mess_amount if hostel in attendance_record)
            amount_paid = calculate_total_amount_paid(email)
            
            mess_refund = amount_paid - (attendance * daily_cost)
            print(f"Student: {email}, Mess Refund: {mess_refund}")
        return "Mess refund calculated for all students."
    else:
        return "Permission denied."

# Additional function to calculate total amount paid
def calculate_total_amount_paid(email):
    # Each student paid 1500
    return 1500

def view_mess_refund(student_id):
    student = students[student_id]
    email = student["email"]

    if email in attendance_record["BH1"]:
        hostel = "BH1"
    elif email in attendance_record["BH2"]:
        hostel = "BH2"
    elif email in attendance_record["GH1"]:
        hostel = "GH1"
    else:
        return "Student not allotted a hostel."

    attendance = attendance_record[hostel][email]
    amount_per_day = mess_amount[hostel]
    amount_paid = calculate_total_amount_paid(email)
    
    mess_refund = amount_paid - (attendance * amount_per_day)
    return f"Student: {email}, Mess Refund: {mess_refund}"


# Main menu-driven program
while True:
    print("Main Menu")
    print("1. Register")
    print("2. File Complaint")
    print("3. View Mess Refund")
    print("4. Allot Hostel")
    print("5. Change Mess Menu")
    print("6. Change Menu Rate")
    print("7. Complaints Management")
    print("8. Requirements Management")
    print("9. Mess Refund Calculation")
    print("10. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        role = input("Enter your role (Student, Dean, MMC, MessManager, Warden, Supervisor): ")
        email = input("Enter your email: ")
        password = input("Enter your password: ")
        name = input("Enter your name: ")
        scholar_id = input("Enter your scholar ID: ")
        gender = input("Enter your gender: ")
        semester = input("Enter your semester: ")
        score = input("Enter your score: ")

        registration_result = register_student(email, password, role, name, scholar_id, gender, semester, score)
        print(registration_result)
    elif choice == "2":
        role = input("Enter your role (Student, Dean, MMC, MessManager, Warden, Supervisor): ")
        student_id = input("Enter your student ID: ")
        complaint_type = input("Enter the complaint type: ")
        complaint_text = input("Enter the complaint text: ")

        result = complaints_management(role, complaint_type, complaint_text)
        print(result)
    elif choice == "3":
        student_id = input("Enter your student ID: ")
        result = view_mess_refund(student_id)
        print(result)
    elif choice == "4":
        student_id = input("Enter your student ID: ")
        allotment_result = allot_hostel(student_id)
        print(allotment_result)
    elif choice == "5":
        role = input("Enter your role (MMC): ")
        hostel = input("Enter the hostel: ")
        new_menu_item = input("Enter the new menu item: ")

        result = change_mess_menu(role, hostel, new_menu_item)
        print(result)
    elif choice == "6":
        role = input("Enter your role (MessManager): ")
        hostel = input("Enter the hostel: ")
        new_rate = input("Enter the new rate: ")

        result = change_menu_rate(role, hostel, new_rate)
        print(result)
    elif choice == "7":
        role = input("Enter your role (Warden, Supervisor): ")
        complaint_type = input("Enter the complaint type: ")
        complaint_text = input("Enter the complaint text: ")

        result = complaints_management(role, complaint_type, complaint_text)
        print(result)
    elif choice == "8":
        role = input("Enter your role (Supervisor): ")
        hostel = input("Enter the hostel: ")
        rooms = input("Enter the number of rooms: ")
        students = input("Enter the number of students: ")
        beds = input("Enter the number of beds: ")
        chairs = input("Enter the number of chairs: ")

        result = requirements_management(role, hostel, rooms, students, beds, chairs)
        print(result)
    elif choice == "9":
        role = input("Enter your role (Dean, MMC): ")
        mess_refund_result = mess_refund_calculation(role)
        print(mess_refund_result)
    elif choice == "10":
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please select a valid option.")
