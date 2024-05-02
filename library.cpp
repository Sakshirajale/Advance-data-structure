#include "iostream"
using namespace std;
const int max_node = 10;
struct node
{
    int book_no = -1;
    string title;
    string author;
    string isbn;
    int availability_stat;
    int next = 0;
};

node a[max_node];

int create()
{
    int head, i;
    cout << "Enter Index of First Book ::";
    cin >> i;
    head = i;
    while (i != 0)
    {
        cout << "\nEnter Book Number :: ";
        cin >> a[i].book_no;
        cout << "Enter Title of the Book :: ";
        cin >> a[i].title;
        cout << "Enter Author of the Book :: ";
        cin >> a[i].author;
        cout << "Enter ISBN of the Book :: ";
        cin >> a[i].isbn;
        cout << "Enter Number of Books Available :: ";
        cin >> a[i].availability_stat;
        cout << "Enter Index of Next Book(Enter 0 to stop) :: ";
        cin >> a[i].next;
        i = a[i].next;
    }
    return head;
}

void display_search(int head)
{
    cout << "\n\nBook No\t|\tTitle\t|\tAuthor\t|\tISBN\t| Availability\t|\t Next Index\t|\n";
    cout<<"----------------------------------------------------------------------------------------------------------------\n";
    int i = head;
    cout << a[i].book_no << "\t|\t" << a[i].title << "\t|\t" << a[i].author << "\t|\t" << a[i].isbn << "\t|\t" << a[i].availability_stat
     << "\t|\t"<<a[i].next<<"\t|\n";
}

void display(int head)
{
    int i = head;
    cout << "\n\nBook No\t|\tTitle\t|\tAuthor\t|\tISBN\t| Availability\t|\tNext Index\t|\n";
    cout<<"----------------------------------------------------------------------------------------------------------------\n";
    while (i != 0)
    {
        if (a[i].book_no != -1)
        {
            cout << a[i].book_no << "\t|\t" << a[i].title << "\t|\t" << a[i].author << "\t|\t" << a[i].isbn << "\t|\t" << a[i].availability_stat << "\t|\t"<<a[i].next<<"\t|\n";
        }
        i = a[i].next;
    }
  //  cout << "NULL" << endl;
}

void insert()
{
    int new_book_no, temp;
    string new_title, new_author, new_isbn;
    int new_availability_stat;

    cout << "Enter Book Number :: " << endl;
    cin >> new_book_no;
    cout << "\nEnter Title of the Book :: ";
    cin >> new_title;
    cout << "\nEnter Author of the Book :: ";
    cin >> new_author;
    cout << "\nEnter ISBN of the Book :: ";
    cin >> new_isbn;
    cout << "\nEnter Number of Books Available ::";
    cin >> new_availability_stat;
    cout << "\nEnter Book No After which you want to insert ::";
    cin >> temp;
    for (int i = 0; i < max_node; i++)
    {
        if (a[i].book_no == temp)
        {
            for (int j = i + 1; j < max_node; j++)
            {
                if (a[j].book_no == -1)
                {
                    a[j].book_no = new_book_no;
                    a[j].title = new_title;
                    a[j].author = new_author;
                    a[j].isbn = new_isbn;
                    a[j].availability_stat = new_availability_stat;
                    a[j].next = a[i].next;
                    a[i].next = j;
                    return;
                }
            }
        }
    }
    cout << "* No such Book Number present *" << endl;
}

int delete_data(int head)
{
    int temp;
    cout << "Enter Book Number you want to delete :: ";
    cin >> temp;
    int prev = 0;
    int current = head;
    if (a[current].book_no == temp)
    {
        a[current].book_no = -1;
        head = a[current].next;
    }
    while (current != 0)
    {
        prev = current;
        current = a[current].next;
        if (a[current].book_no == temp)
        {
            a[current].book_no = -1;
            a[prev].next = a[current].next;
            a[current].next = 0;
            return 0;
        }
    }
    //cout << "Element not found";
    return head;
}

void search(int head)
{
    string val;
    cout << "Enter Title of Book to search :: ";
    cin >> val;
    int i = head;
    bool flag = true;
    while (i != 0)
    {
        if (a[i].title == val)
        {
            cout << " ** BOOK FOUND **" << endl;
            display_search(i);
            flag = false;
        }
        i = a[i].next;
    }
    if (flag == true)
    {
        cout << " ** BOOK NOT FOUND ** ";
    }
}

int main()
{
    int head = create();
    //cout << " book_no created " << endl;
    int ch,c;
    do
    {
        cout << "MENU\n1.INSERT\n2.DISPLAY\n3.DELETE\n4.SEARCH\n5.exit";
        cout<<"\nEnter your choice ::";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display(head);
            break;
        case 3:
            delete_data(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            exit(0);
            break;

        default:
            cout<<"WRONG CHOICE ";
        }
        cout << "\nDo you want to continue(1/0) :: ";
        cin >> c;
    } while (c == 1);
    return 0;
}
