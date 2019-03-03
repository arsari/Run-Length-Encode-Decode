#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string run_length_encode(const string &str)
{
    string encodedLetters;

    for (int i = 0; i < str.length(); i++)
    {
        int count = 1;
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        (count > 1) ? encodedLetters += str[i] + to_string(count) : encodedLetters += str[i];
    }
    return encodedLetters;
}

string run_length_decode(const string &str)
{
    string decodedLetters = "";
    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {
        string counter = "";
        int letterCoefficient = 0;

        // evaluate if first element of str is number
        if (!isalpha(str[0]))
        {
            if (!isalpha(str[i]))
                continue;
            else
            {
                counter = str.substr(j, i - j);
                j = i + 1;

                istringstream(counter) >> letterCoefficient;

                for (int k = 0; k < letterCoefficient; k++)
                    decodedLetters += str[i];

                // evaluate if next element of str is letter
                if (isalpha(str[i + 1]))
                    decodedLetters += str[i + 1];
            }
        }
        else
        {
            if (isalpha(str[i]))
            {
                decodedLetters += str[i];
            }
            else
            {
                counter = str.substr(i, i - j);
                j = i - 1;

                istringstream(counter) >> letterCoefficient;

                for (int k = 1; k < letterCoefficient; k++)
                    decodedLetters += str[j];
            }
        }
    }
    return decodedLetters;
}

int main()
{
    // string examples
    string str1 = "WWWWBBWWWWWA";
    string str2 = "W4B2W5AS";
    string str3 = "6W2B6AXT";

    // variables
    int x = 0;
    char rlType;
    string userStr;
    string result = "";

    cout << "\nRun Length Encoder Example:" << endl;
    cout << "Input <- " << str1 << endl;
    cout << "Output -> " << run_length_encode(str1) << endl;

    cout << "\nRun Length Decoder Example:" << endl;
    cout << "Input <- " << str2 << endl;
    cout << "Output -> " << run_length_decode(str2) << endl;

    cout << "\nInput <- " << str3 << endl;
    cout << "Output -> " << run_length_decode(str3) << endl;

    cout << "\n----------" << endl;

    while (x != 1)
    {
        cout << "\nRun Length (E)ncoder or (D)ecoder: ";
        cin >> rlType;

        if (rlType == 'E' || rlType == 'e' || rlType == 'D' || rlType == 'd')
        {
            x = 1;
        }
        else
        {
            cout << "Sorry, wrong selection" << endl;
        }
    }

    cout << "Enter string: ";
    cin >> userStr;

    result = (rlType == 'E' || rlType == 'e') ? run_length_encode(userStr) : run_length_decode(userStr);

    cout << "\nUser Input <- " << userStr << endl;
    cout << "Output -> " << result << endl;
    cout << endl;

    return 0;
}
