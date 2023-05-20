#include <iostream>
using namespace std;

void combine(const char *str1, const char *str2, char *str) {
  int i = 0;
  int j = 0;
  int n = 0;
  while (str1[i] != '\0') {
    cout << "str1[i]: " << str1[i] << "\n";
    // 65-90
    // 97-122
    if ((65 <= str1[i] && str1[i] <= 90) || 97 <= str1[i] && str1[i] <= 122) {
      str[n] = str1[i];
      n++;
      // find char in str2
      while (str2[j] != '\0') {
        cout << "str2[j]: " << str2[j] << "\n";
        if ((65 <= str2[j] && str2[j] <= 90) ||
            97 <= str2[j] && str2[j] <= 122) {
          str[n] = str2[j];
          n++;
          j++;
          break;
        }
        j++;
      }
    }
    i++;
  }
  // add rest of str2
  while (str2[j] != '\0') {
    cout << "str2[j]+: " << str2[j] << "\n";
    if ((65 <= str2[j] && str2[j] <= 90) || 97 <= str2[j] && str2[j] <= 122) {
      str[n] = str2[j];
      n++;
    }
    j++;
  }
}

void combine2(const char *str1, const char *str2, char *str) {
  int i = 0;
  int j = 0;
  int n = 0;
  while (str1[i] != '\0' && str2[j] != '\0') {
    cout << "str1[i]: " << str1[i] << "\n";
    cout << "str2[j]: " << str2[j] << "\n";

    // 65-90
    // 97-122
    bool merge = true;
    if (!((65 <= str1[i] && str1[i] <= 90) ||
          97 <= str1[i] && str1[i] <= 122)) {
      i++;
      merge = false;
    }
    if (!((65 <= str2[j] && str2[j] <= 90) ||
          97 <= str2[j] && str2[j] <= 122)) {
      j++;
      merge = false;
    }
    if (merge) {
      str[n] = str1[i];
      n++;
      str[n] = str2[j];
      n++;
      i++;
      j++;

    }
  }
  // add rest of str1
  while (str1[i] != '\0') {
    //cout << "str1[i]+: " << str2[j] << "\n";
    if ((65 <= str1[i] && str1[i] <= 90) || 97 <= str1[i] && str1[i] <= 122) {
      str[n] = str1[i];
      n++;
    }
    i++;
  }
  // add rest of str2
  while (str2[j] != '\0') {
    //cout << "str2[j]+: " << str2[j] << "\n";
    if ((65 <= str2[j] && str2[j] <= 90) || 97 <= str2[j] && str2[j] <= 122) {
      str[n] = str2[j];
      n++;
    }
    j++;
  }
}

int main() {
  char *str1 = (char *)"1a2b3 cdd";
  char *str2 = (char *)"A 2 B3  17";
  char *str = new char[100];
  combine2(str1, str2, str);
  cout << str;
}
