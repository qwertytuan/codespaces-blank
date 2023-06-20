#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// A struct to store flight details
struct Flight {
    string flight_number;
    string origin;
    string destination;
    string departure_time;
    string arrival_time;
};

// A struct to store user details
struct User {
    string name;
    string email;
    string phone;
};

// A function to display the menu
void display_menu() {
    cout << "Welcome to the flight reservation and booking system.\n";
    cout << "Please choose an option:\n";
    cout << "1. Reserve a flight\n";
    cout << "2. Book a flight\n";
    cout << "3. Cancel a reservation\n";
    cout << "4. Show all bookings\n";
    cout << "5. Exit\n";
}

// A function to reserve a flight and save the user details to a txt file
void reserve_flight() {
    // Create an object of Flight struct
    Flight f;

    // Create an object of User struct
    User u;

    // Prompt the user to enter the user details
    cout << "Enter your name: ";
    cin >> u.name;
    cout << "Enter your email: ";
    cin >> u.email;
    cout << "Enter your phone: ";
    cin >> u.phone;

    // Prompt the user to enter the flight details
    cout << "Enter the flight number: ";
    cin >> f.flight_number;
    cout << "Enter the origin: ";
    cin >> f.origin;
    cout << "Enter the destination: ";
    cin >> f.destination;
    cout << "Enter the departure time: ";
    cin >> f.departure_time;
    cout << "Enter the arrival time: ";
    cin >> f.arrival_time;

    // Open the txt file in append mode
    ofstream file("reservation.txt", ios::app);

     // Check if the file is opened successfully
     if (file.is_open()) {
         // Write the user and flight details to the file
         file << u.name << " "
              << u.email << " "
              << u.phone << " "
              << f.flight_number << " "
              << f.origin << " "
              << f.destination << " "
              << f.departure_time << " "
              << f.arrival_time << "\n";

         // Close the file
         file.close();

         // Display a success message
         cout << "Flight reserved successfully.\n";
     }
     else {
         // Display an error message
         cout << "Error: Unable to open the file.\n";
     }
}

// A function to book a flight and save the user and flight details to another txt file
void book_flight() {
     // Create an object of Flight struct
     Flight f;

     // Create an object of User struct
     User u;

     // Declare a variable to store the name of the user who wants to book a flight
     string book_name;

     // Prompt the user to enter the name of the user who wants to book a flight
     cout << "Enter the name of the user who wants to book a flight: ";
     cin >> book_name;
           bool found = false;
    // mo file2 LuuTruMayBay.txt de ghi
              ifstream file("LuuTruMayBay.txt", ios::in);
     // kiem tra xem file2 da mo thanh cong chua
     if (file.is_open()) {
         // doc den khi den dong cuoi cua file2 or the class Flight is found
         while (file>>f2.MaMayBay2>>f2.NoiDi2>>f2.NoiDen2>>f2.ThoiGianDi2>>f2.ThoiGianDen2&&!found) 
         {
             // kiem tra ma may bay co trung hay khong
             if (f2.MaMayBay2 == TimMaChuyenBay2) 
             {
                 // neu trung thi la true
                 found = true;
                 // hien thi la da tim thay
                 cout << "Da tim thay.\n";
                 cout << "Ma may bay: " << f2.MaMayBay2 << "\n";
                 cout << "Noi Di: " << f2.NoiDi2 << "\n";
                 cout << "Noi Den: " << f2.NoiDen2 << "\n";
                 cout << " thoi gian di: " << f2.ThoiGianDi2 << "\n";
                 cout << " thoi gian den: " << f2.ThoiGianDen2 << "\n";
                   
             }
         }
     // Declare a flag to indicate whether the reservation is found or not
     bool found = false;

     // Open the reservation txt file in input mode
     ifstream file_in("reservation.txt", ios::in);

      // Check if the file is opened successfully
      if (file_in.is_open()) {
          // Open a booking txt file in append mode
          ofstream file_out("booking.txt", ios::app);

          // Check if the file is opened successfully
          if (file_out.is_open()) {
              // Read the user and flight details from the input file until the end of file is reached or the reservation is found
              while (file_in >> u.name >> u.email >> u.phone >> f.flight_number >> f.origin >> f.destination >> f.departure_time >> f.arrival_time && !found) {
                  // Check if the name matches with the booking criteria
                  if (u.name == book_name) {
                      // Set the flag to true
                      found = true;

                      // Write the user and flight details to the output file
                      file_out << u.name << " "
                               << u.email << " "
                               << u.phone << " "
                               << f.flight_number << " "
                               << f.origin << " "
                               << f.destination << " "
                               << f.departure_time << " "
                               << f.arrival_time << "\n";

                      // Display a success message and the booking details
                      cout << "Flight booked successfully.\n";
                      cout << "Name: " << u.name << "\n";
                      cout << "Email: " << u.email << "\n";
                      cout << "Phone: " << u.phone << "\n";
                      cout << "Flight Number: " << f.flight_number << "\n";
                      cout << "Origin: " << f.origin << "\n";
                      cout << "Destination: " << f.destination << "\n";
                      cout << "Departure Time: " << f.departure_time << "\n";
                      cout << "Arrival Time: " << f.arrival_time << "\n";
                  }
              }

              // Close both files
              file_in.close();
              file_out.close();

              // Check if the flag is false
              if (!found) {
                  // Display a failure message
                  cout << "Reservation not found.\n";
              }
          }
          else {
              // Display an error message and close the input file
              cout << "Error: Unable to open the output file.\n";
              file_in.close();
          }
      }
      else {
          // Display an error message
          cout << "Error: Unable to open the input file.\n";
      }
}

// A function to cancel a reservation and delete the user and flight details from the txt file
void cancel_reservation() {
    // Create an object of Flight struct
    Flight f;

    // Create an object of User struct
    User u;

    // Declare a variable to store the name of the user who wants to cancel a reservation
    string cancel_name;

    // Prompt the user to enter the name of the user who wants to cancel a reservation
    cout << "Enter the name of the user who wants to cancel a reservation: ";
    cin >> cancel_name;

    // Declare a flag to indicate whether the reservation is found or not
    bool found = false;

    // Open the reservation txt file in input mode
    ifstream file_in("reservation.txt", ios::in);

     // Check if the file is opened successfully
     if (file_in.is_open()) {
         // Open a temporary txt file in output mode
         ofstream file_out("temp.txt", ios::out);

         // Check if the file is opened successfully
         if (file_out.is_open()) {
             // Read the user and flight details from the input file until the end of file is reached
             while (file_in >> u.name >> u.email >> u.phone >> f.flight_number >> f.origin >> f.destination >> f.departure_time >> f.arrival_time) {
                 // Check if the name matches with the cancel criteria
                 if (u.name == cancel_name) {
                     // Set the flag to true
                     found = true;
                 }
                 else {
                     // Write the user and flight details to the output file
                     file_out << u.name << " "
                              << u.email << " "
                              << u.phone << " "
                              << f.flight_number << " "
                              << f.origin << " "
                              << f.destination << " "
                              << f.departure_time << " "
                              << f.arrival_time << "\n";
                 }
             }

             // Close both files
             file_in.close();
             file_out.close();

             // Check if the flag is true
             if (found) {
                 // Remove the original txt file and rename the temporary txt file as reservation.txt
                 remove("reservation.txt");
                 rename("temp.txt", "reservation.txt");

                 // Display a success message
                 cout << "Reservation cancelled successfully.\n";
             }
             else {
                 // Display a failure message and remove the temporary txt file
                 cout << "Reservation not found.\n";
                 remove("temp.txt");
             }
         }
         else {
             // Display an error message and close the input file
             cout << "Error: Unable to open the output file.\n";
             file_in.close();
         }
     }
     else {
         // Display an error message
         cout << "Error: Unable to open the input file.\n";
     }
}

// A function to show all bookings from the booking txt file
void show_all_bookings() {
    // Create an object of Flight struct
    Flight f;

    // Create an object of User struct
    User u;

    // Open the booking txt file in input mode
    ifstream file("booking.txt", ios::in);

     // Check if the file is opened successfully
     if (file.is_open()) {
         // Display a header for the booking details
         cout << "Name\tEmail\tPhone\tFlight Number\tOrigin\tDestination\tDeparture Time\tArrival Time\n";

         // Read the user and flight details from the file until the end of file is reached
         while (file >> u.name >> u.email >> u.phone >> f.flight_number >> f.origin >> f.destination >> f.departure_time >> f.arrival_time)
{
    cout<<u.name<<u.email<<u.phone<<f.flight_number<<f.origin<<f.destination<< f.departure_time<<f.arrival_time;
}
     }
}
int main()
{
    int choice;

    // Display the menu and prompt the user to enter a choice until 4 is entered
    do {
        display_menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        // Perform different actions based on the user's choice using switch case statement
        switch (choice) {
            case 1:
                reserve_flight();
                break;
            case 2:
                book_flight();
                break;
            case 3:
                cancel_reservation();
                break;
            case 4:
            show_all_bookings();
            break;
            default:
                cout << "Loi.Vui long thu lai.\n";
        }
    } while (choice != 4);
    return 0;
}