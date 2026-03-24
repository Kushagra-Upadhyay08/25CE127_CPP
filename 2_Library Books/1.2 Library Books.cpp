#include <iostream>
#include <string>
using namespace std;

class Library {
    int book_id;
    string author_name;
    string title;
    int copies;

public:
    void set_data();
    void add_book();
    void issue_book();
    void return_book();
    void display_book();
    bool search_book(const string& name);
};

bool Library::search_book(const string& name) {
    return title == name;
}

void Library::set_data() {
    cout << "Enter Book ID: ";
    cin >> book_id;
    cin.ignore();

    cout << "Enter Author Name: ";
    getline(cin, author_name);

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Number of Copies: ";
    cin >> copies;
}

void Library::add_book() {
    int no;
    cout << "Enter number of copies to add: ";
    cin >> no;
    copies += no;
}

void Library::issue_book() {
    if (copies > 0) {
        copies--;
        cout << "Book issued successfully\n";
    } else {
        cout << "No copies available\n";
    }
}

void Library::return_book() {
    copies++;
    cout << "Book returned successfully\n";
}

void Library::display_book() {
    cout << "\nBook ID: " << book_id;
    cout << "\nAuthor: " << author_name;
    cout << "\nTitle: " << title;
    cout << "\nCopies: " << copies << endl;
}

int main() {
    Library b[10];
    string match_book;
    int t = 0, choice;


    while (true) {
        cout << "\n\n1. Set Book Data"
             << "\n2. Add Book Copies"
             << "\n3. Issue Book"
             << "\n4. Return Book"
             << "\n5. Display All Books"
             << "\n0. Exit"
             << "\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            cout << "Thanks for coming!\n";
            break;
        }

        switch (choice) {
        case 1:
            b[t].set_data();
            t++;
            break;

        case 2:
            cout << "Enter Book Title: ";
            getline(cin, match_book);
            for (int i = 0; i < t; i++) {
                if (b[i].search_book(match_book)) {
                    b[i].add_book();
                    goto found;
                }
            }
            cout << "Book not found\n";
        found:
            break;

        case 3:
            cout << "Enter Book Title: ";
            getline(cin, match_book);
            for (int i = 0; i < t; i++) {
                if (b[i].search_book(match_book)) {
                    b[i].issue_book();
                    goto found2;
                }
            }
            cout << "Book not found\n";
        found2:
            break;

        case 4:
            cout << "Enter Book Title: ";
            getline(cin, match_book);
            for (int i = 0; i < t; i++) {
                if (b[i].search_book(match_book)) {
                    b[i].return_book();
                    goto found3;
                }
            }
            cout << "Book not found\n";
        found3:
            break;

        case 5:
            for (int i = 0; i < t; i++) {
                b[i].display_book();
            }
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}

