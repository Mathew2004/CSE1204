#include <bits/stdc++.h>
using namespace std;

class Member {
    int mid[1000];
    string name[1000];
    float height[1000];
    float weight[1000];
    float bmi[1000];
    int total = 0;

public:
    int check(int y) {
        for (int i = 0; i < total; i++) {
            if (mid[i] == y) {
                return i;
            }
        }
        return -1;
    }

    void addMember() {
        int x, i;
        cout << "Enter new Member ID: ";
        cin >> x;
        i = check(x);
        cout << "===========================" << endl;
        cout << "===== ADD MEMBER ========" << endl;
        cout << "===========================" << endl;

        if (i == -1) {
            // Not a Duplicate
            mid[total] = x;
            cout << "Enter Member Name: ";
            cin.ignore();
            getline(cin, name[total]);
            cout << "Enter Height: ";
            cin >> height[total];
            cout << "Enter Weight: ";
            cin >> weight[total];
            bmi[total] = weight[total] / (height[total] * height[total]);
            total++;
            cout << "Member Added Successfully" << endl;
        } else {
            // Duplicate
            cout << "Sorry, Duplicate Member ID" << endl;
        }
    }

    void searchMember() {
        int x;
        cout << "Enter Member ID: ";
        cin >> x;
        int index = check(x);
        cout << "================================" << endl;
        cout << "===========SEARCH MEMBER ========" << endl;
        cout << "=================================" << endl;
        if (index != -1) {
            // Member Found
            cout << "Member ID: " << mid[index] << endl;
            cout << "Member Name: " << name[index] << endl;
            cout << "Member Height: " << height[index] << endl;
            cout << "Member Weight: " << weight[index] << endl;
            cout << "Member BMI: " << bmi[index] << endl;
        } else {
            // Member Not Found
            cout << "Member Not Found" << endl;
        }
    }

    void updateMember() {
        int x;
        cout << "Enter Member ID: ";
        cin >> x;
        int index = check(x);
        if (index != -1) {
            // Member Found
            cout << "Enter Member Name: ";
            cin.ignore();
            getline(cin, name[index]);
            cout << "Enter Height: ";
            cin >> height[index];
            cout << "Enter Weight: ";
            cin >> weight[index];
            bmi[index] = weight[index] / (height[index] * height[index]);
            cout << "Member ID " << mid[index] << " Successfully Updated\n";
        } else {
            // Member Not Found
            cout << "Member Not Found" << endl;
        }
    }

    void maxHeight() {
        float maxH = height[0];
        float maxW = weight[0];
        for (int i = 1; i < total; i++) {
            if (height[i] > maxH) {
                maxH = height[i];
            }
            if (weight[i] > maxW) {
                maxW = weight[i];
            }
        }
        cout << "=================================" << endl;
        cout << "=== MAXIMUM HEIGHT & WEIGHT ====" << endl;
        cout << "=================================" << endl;
        cout << "Maximum Height = " << maxH << endl;
        cout << "Maximum Weight = " << maxW << endl;
    }

    void minHeight() {
        float minH = height[0];
        float minW = weight[0];
        for (int i = 1; i < total; i++) {
            if (height[i] < minH) {
                minH = height[i];
            }
            if (weight[i] < minW) {
                minW = weight[i];
            }
        }
        cout << "====================================" << endl;
        cout << "====== MINIMUM HEIGHT & WEIGHT======" << endl;
        cout << "====================================" << endl;
        cout << "Minimum Height = " << minH << endl;
        cout << "Minimum Weight = " << minW << endl;
    }

    void avgHeight() {
        cout << "==============================" << endl;
        cout << "========== AVERAGE HEIGHT ======" << endl;
        cout << "==============================" << endl;
        float sum = 0;
        for (int i = 0; i < total; i++)
            sum += height[i];
        cout << "Average Height = " << sum / total << endl;
    }

    void avgWeight() {
        cout << "============================" << endl;
        cout << "======== AVERAGE WEIGHT =======" << endl;
        cout << "============================" << endl;
        float sum = 0;
        for (int i = 0; i < total; i++) {
            sum += weight[i];
        }
        cout << "AVERAGE WEIGHT = " << sum / total << endl;
    }

    void bmi_classi() {
        int x;
        cout << "Enter Member ID: ";
        cin >> x;
        int index = check(x);
        cout << "==================================" << endl;
        cout << "===== BMI CLASSIFICATION ======" << endl;
        cout << "==================================" << endl;
        if (index != -1) {
            cout << "Member Name: " << name[index] << endl;
            cout << "Member Height: " << height[index] << endl;
            cout << "Member Weight: " << weight[index] << endl;
            cout << "Member BMI: " << bmi[index] << endl;
            if (bmi[index] < 16) {
                cout << "Severe Thinness" << endl;
            } else if (bmi[index] >= 16 && bmi[index] <= 17) {
                cout << "Moderate Thinness" << endl;
            } else if (bmi[index] >= 17 && bmi[index] <= 18.5) {
                cout << "Mild Thinness" << endl;
            } else if (bmi[index] >= 18.5 && bmi[index] <= 25) {
                cout << "Normal" << endl;
            } else if (bmi[index] >= 25 && bmi[index] <= 30) {
                cout << "Overweight" << endl;
            } else if (bmi[index] >= 30 && bmi[index] <= 35) {
                cout << "Obese Class I" << endl;
            } else if (bmi[index] >= 35 && bmi[index] <= 40) {
                cout << "Obese Class II" << endl;
            } else if (bmi[index] >= 40) {
                cout << "Obese Class III" << endl;
            }
        } else {
            cout << "Member Not Found" << endl;
        }
    }

    void summary() {
        cout << "===============================" << endl;
        cout << "======= SUMMARY ========" << endl;
        cout << "===============================" << endl;
        cout << "Total Members = " << total << endl;
        maxHeight();
        minHeight();
        avgHeight();
        avgWeight();
        cout << endl;
    }

    void rmvMember() {
        int id;
        cout << "Enter Member ID: ";
        cin >> id;
        int index = check(id);
        if (index != -1) {
            for (int i = index; i < total - 1; i++) {
                mid[i] = mid[i + 1];
                name[i] = name[i + 1];
                height[i] = height[i + 1];
                weight[i] = weight[i + 1];
                bmi[i] = bmi[i + 1];
            }
            total--;
            cout << "Member Has been Removed!" << endl;
        } else {
            cout << "Member Not Found!" << endl;
        }
    }
};

int main() {
    int option;
    Member m;
    while (1) {
        cout << "======================" << endl;
        cout << "========= MENU ======" << endl;
        cout << "=====================" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Update Member" << endl;
        cout << "3. Remove Member" << endl;
        cout << "4. Max Height & Weight" << endl;
        cout << "5. Min Height & Weight" << endl;
        cout << "6. Summary Report" << endl;
        cout << "7. BMI Classifications" << endl;
        cout << "8. Search Member" << endl;
        cout << "9. Average Height" << endl;
        cout << "10. Average Weight" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        if (option == 0)
            break;
        switch (option) {
            case 1:
                m.addMember();
                break;
            case 2:
                m.updateMember();
                break;
            case 3:
                m.rmvMember();
                break;
            case 4:
                m.maxHeight();
                break;
            case 5:
                m.minHeight();
                break;
            case 6:
                m.summary();
                break;
            case 7:
                m.bmi_classi();
                break;
            case 8:
                m.searchMember();
                break;
            case 9:
                m.avgHeight();
                break;
            case 10:
                m.avgWeight();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }
    return 0;
}
