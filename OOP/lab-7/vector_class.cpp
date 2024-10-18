#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertFirst(vector<int>& ax) {
    int value;
    cout<<"Enter the element to insert at the beginning: ";
    cin>>value;
    ax.insert(ax.begin(), value);
    cout<<"Element inserted at the beginning."<<endl;
}
void insertLast(vector<int>& ax) {
    int value;
    cout<<"Enter the element to insert at the end: ";
    cin>>value;
    ax.push_back(value);
    cout<<"Element inserted at the end."<<endl;
}
void insertBefore(vector<int>& ax) {
    int value, target;
    cout<<"Enter the element to insert: ";
    cin>>value;
    cout<<"Enter the element before which to insert: ";
    cin>>target;
    for (auto it=ax.begin(); it != ax.end(); ++it) {
        if (*it==target) {
            ax.insert(it, value);
            cout<<"Element inserted before "<<target<<"."<<endl;
            return;
        }
    }

    cout<<"Target element not found in the list."<<endl;
}
void insertAfter(vector<int>& ax) {
    int value, target;
    cout<<"Enter the element to insert: ";
    cin>>value;
    cout<<"Enter the element after which to insert: ";
    cin>>target;
    for (auto it=ax.begin(); it != ax.end(); ++it) {
        if (*it==target) {
            ax.insert(it + 1, value);
            cout<<"Element inserted after "<<target<<"."<<endl;
            return;
        }
    }

    cout<<"Target element not found in the list."<<endl;
}
void deleteElement(vector<int>& ax) {
    int target;
    cout<<"Enter the element to delete: ";
    cin>>target;
    auto it=find(ax.begin(), ax.end(), target);
    if (it != ax.end()) {
        ax.erase(it);
        cout<<"Element "<<target<<" deleted."<<endl;
    } else {
        cout<<"Element not found in the list."<<endl;
    }
}
void searchElement(const vector<int>& ax) {
    int target;
    cout<<"Enter the element to search: ";
    cin>>target;
    auto it=find(ax.begin(), ax.end(), target);
    if (it != ax.end()) {
        cout<<"Element "<<target<<" found in the list."<<endl;
    } else {
        cout<<"Element not found in the list."<<endl;
    }
}
void displayList(const vector<int>& ax) {
    cout<<"List elements: ";
    for (int element : ax) {
        cout<<element<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> ax;
    int choice;

    while (true) {
        cout<<"**** Main Menu ****"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Display list"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>choice;

        switch (choice) {
            case 1:
                int insertChoice;
                cout<<"**** Insert Sub Menu ****"<<endl;
                cout<<"1. Insert at First"<<endl;
                cout<<"2. Insert at Last"<<endl;
                cout<<"3. Insert Before"<<endl;
                cout<<"4. Insert After"<<endl;
                cout<<"5. Exit"<<endl;
                cout<<"Enter your option: ";
                cin>>insertChoice;
                switch (insertChoice) {
                    case 1:
                        insertFirst(ax);
                        break;
                    case 2:
                        insertLast(ax);
                        break;
                    case 3:
                        insertBefore(ax);
                        break;
                    case 4:
                        insertAfter(ax);
                        break;
                    case 5:
                        break;
                    default:
                        cout<<"Invalid option."<<endl;
                        break;
                }
                break;
            case 2:
                deleteElement(ax);
                break;
            case 3:
                searchElement(ax);
                break;
            case 4:
                displayList(ax);
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid option."<<endl;
                break;
        }
    }

    return 0;
}
