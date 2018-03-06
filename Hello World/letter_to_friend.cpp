#include "../std_lib_facilities.h"

int main() {
    cout << "This program will write a letter with information you provided to your friend.\n";
    string letter = "";
    
    cout << "Enter friend first name\n";
    string friend_name = "";
    cin >> friend_name;

    letter += "Dear " + friend_name + ",\n\n" + "How are you? I am fine. I miss you.";

    letter += "\n\n";

    cout << "Enter another friend name\n";
    cin >> friend_name;

    letter += "Have you seen " + friend_name +" lately? ";

    char friend_sex = 0;
    cout << "Enter another friend sex\n";
    cin >> friend_sex;

    if (friend_sex == 'f') {
        letter += "If you see " + friend_name + " please ask her to call me.";
    } else {
        letter += "If you see " + friend_name + " please ask him to call me.";
    }
    
    letter += "\n\n";

    int age = 0;
    cout << "Enter friend age\n";
    cin >> age;

    if (age <= 0 || age > 110) {
        simple_error("you're kidding!");
    } else {
        letter += "I hear you just had a birthday and you are " + to_string(age) + " years old. ";
    }

    if (age < 12) {
        letter += "Next year you will be " + to_string(age + 1) + ".";
    } else if (age == 17) {
        letter += "Next year you will be able to vote.";
    } else if (age >= 70) {
        letter += "I hope you are enjoying retirement.";
    }

    letter += "\n\n";
    letter += "Your sincerely,";

    letter += "\n\n";
    letter += "XiaoHong";

    letter += "\n\n";

    cout << letter;

    return 0;
}