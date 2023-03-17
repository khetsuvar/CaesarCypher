#include <iostream>
#include <string>

using namespace std;

string decrypt(string message, int shift) {
    string result = "";

    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result += char(int(message[i] - shift - 65 + 26) % 26 + 65);
            }
            else {
                result += char(int(message[i] - shift - 97 + 26) % 26 + 97);
            }
        }
        else {
            result += message[i];
        }
    }

    return result;
}

int main() {
    string message;
    int shift;

    cout << "Enter an encrypted message: ";
    getline(cin, message);

    for (shift = 1; shift <= 25; shift++) {
        string decrypted_message = decrypt(message, shift);
        cout << "Shift " << shift << ": " << decrypted_message << endl;
    }

    return 0;
}

