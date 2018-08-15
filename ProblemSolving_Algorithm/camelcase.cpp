/* Subdomain: String
 * Problem: Camelcase
 */

#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int num_words = 1;
    for (int i = 1; i < s.size(); i++){
        cout << i << endl;
        if (s[i] >= 65 && s[i] <= 90){
            num_words += 1;
            cout << "num_words:" << num_words << endl;
        }
    }
    return num_words;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
