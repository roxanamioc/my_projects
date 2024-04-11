#include<iostream>

#include<vector>


using namespace std;

class Policy {
  protected:
    bool isChecked;
  public:
    virtual void check(const string & str) = 0;
  bool getCheck() const {
    return this -> isChecked;
  }
};

class LengthPolicy: public Policy {
  private: uint16_t minLength, maxLength;
  public:
  LengthPolicy(uint16_t min) {
    this -> minLength = min;
    this -> maxLength = 255;
  }
  LengthPolicy(uint16_t min, uint16_t max) {
    this -> minLength = min;
    this -> maxLength = max;
  }
  void check(const string & str) {
    if ((str.length() >= this -> minLength) && (str.length() <= this -> maxLength)) {
      isChecked = true;
    } else {
      isChecked = false;
    }
  }
};

class ClassPolicy: public Policy {
  private: uint16_t minClassCount;
  public: 
  ClassPolicy(uint16_t value) {
    minClassCount = value;
  }
  void check(const string & str) {
    int i = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    for (i = 0; i < str.length(); i++) {
      if ((str[i] >= 97) && (str[i] <= 122)) {
        flag1 = 1;
      } else if ((str[i] >= 65) && (str[i] <= 90)) {
        flag2 = 1;
      } else if ((str[i] >= 48) && (str[i] <= 57)) {
        flag3 = 1;
      } else if (((str[i] >= 32) && (str[i] <= 47)) || ((str[i] >= 58) && (str[i] <= 64)) || ((str[i] >= 91) && (str[i] <= 96)) || ((str[i] >= 123) && (str[i] <= 127))) {
        flag4 = 1;
      }
    }
    if (flag1 + flag2 + flag3 + flag4 < minClassCount) {
      isChecked = false;
    } else {
      isChecked = true;
    }
  }
};

class IncludePolicy: public Policy {
  private: char characterType;
  public: 
  IncludePolicy(char character) {
    characterType = character;
  }
  void check(const string & str) {
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    if ((this -> characterType >= 48) && (this -> characterType <= 57)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 48) && (str[i] <= 57)) {
          flag3 = 1;
          break;
        }
      }
      if (flag3 == 1) {
        this -> isChecked = true;
      }
    }
    if ((this -> characterType >= 97) && (this -> characterType <= 122)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 97) && (str[i] <= 122)) {
          flag1 = 1;
          break;
        }
      }
      if (flag1 == 1) {
        this -> isChecked = true;
      }
    }
    if (((this -> characterType >= 32) && (this -> characterType <= 47)) || ((this -> characterType >= 58) && (this -> characterType <= 64)) || ((this -> characterType >= 91) && (this -> characterType <= 96)) || ((this -> characterType >= 123) && (this -> characterType <= 127))) {
      for (int i = 0; i < str.length(); i++) {
        if (((str[i] >= 32) && (str[i] <= 47)) || ((str[i] >= 58) && (str[i] <= 64)) || ((str[i] >= 91) && (str[i] <= 96)) || ((str[i] >= 123) && (str[i] <= 127))) {
          flag4 = 1;
          break;
        }
      }
      if (flag4 == 1) {
        this -> isChecked = true;
      }
    }
    if ((this -> characterType >= 65) && (this -> characterType <= 90)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 65) && (str[i] <= 90)) {
          flag2 = 1;
          break;
        }
      }
      if (flag2 == 1) {
        this -> isChecked = true;
      }
    }
    if (((this -> characterType >= 65) && (this -> characterType <= 90)) && (flag2 == 0)) {
      this -> isChecked = false;
    }
    if (((this -> characterType >= 48) && (this -> characterType <= 57)) && (flag3 == 0)) {
      this -> isChecked = false;
    }
    if (((this -> characterType >= 97) && (this -> characterType <= 122)) && (flag1 == 0)) {
      this -> isChecked = false;
    }
    if ((((this -> characterType >= 32) && (this -> characterType <= 47)) || ((this -> characterType >= 58) && (this -> characterType <= 64)) || ((this -> characterType >= 91) && (this -> characterType <= 96)) || ((this -> characterType >= 123) && (this -> characterType <= 127))) && (flag4 == 0)) {
      this -> isChecked = false;
    }
  }
};

class NotIncludePolicy: public Policy {
  private: char characterType;
  public: 
  NotIncludePolicy(char character) {
    this -> characterType = character;
  }
  void check(const string & str) {
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    if (((this -> characterType >= 32) && (this -> characterType <= 47)) || ((this -> characterType >= 58) && (this -> characterType <= 64)) || ((this -> characterType >= 91) && (this -> characterType <= 96)) || ((this -> characterType >= 123) && (this -> characterType <= 127))) {
      for (int i = 0; i < str.length(); i++) {
        if (((str[i] >= 32) && (str[i] <= 47)) || ((str[i] >= 58) && (str[i] <= 64)) || ((str[i] >= 91) && (str[i] <= 96)) || ((str[i] >= 123) && (str[i] <= 127))) {
          flag4 = 1;
          break;
        }
      }
      if (flag4 == 1) {
        this -> isChecked = false;
      }
    }
    if ((this -> characterType >= 48) && (this -> characterType <= 57)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 48) && (str[i] <= 57)) {
          flag3 = 1;
          break;
        }
      }
      if (flag3 == 1) {
        this -> isChecked = false;
      }
    }
    if ((this -> characterType >= 97) && (this -> characterType <= 122)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 97) && (str[i] <= 122)) {
          flag1 = 1;
          break;
        }
      }
      if (flag1 == 1) {
        this -> isChecked = false;
      }
    }
    if ((this -> characterType >= 65) && (this -> characterType <= 90)) {
      for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 65) && (str[i] <= 90)) {
          flag2 = 1;
          break;
        }
      }
      if (flag2 == 1) {
        this -> isChecked = false;
      }
    }
    if (((this -> characterType >= 97) && (this -> characterType <= 122)) && (flag1 == 0)) {
      this -> isChecked = true;
    } else if (((this -> characterType >= 48) && (this -> characterType <= 57)) && (flag3 == 0)) {
      this -> isChecked = true;
    } else if ((((this -> characterType >= 32) && (this -> characterType <= 47)) || ((this -> characterType >= 58) && (this -> characterType <= 64)) || ((this -> characterType >= 91) && (this -> characterType <= 96)) || ((this -> characterType >= 123) && (this -> characterType <= 127))) && (flag4 == 0)) {
      this -> isChecked = true;
    } else if (((this -> characterType >= 65) && (this -> characterType <= 90)) && (flag2 == 0)) {
      this -> isChecked = true;
    }
  }
};

class RepetitionPolicy: public Policy {
  private: uint16_t maxCount;
  public: 
  RepetitionPolicy(uint16_t value) {
    this -> maxCount = value;
  }
  void check(const string & str) {
    uint16_t counter = 0;
    bool flag = true;
    for (int i = 0; i < str.size() - 1; i++) {
      if (i != 0) {
        if (str[i - 1] == str[i]) {
          counter++;
          if (maxCount < counter) {
            flag = false;
            break;
          }
        } else {
          counter = 1;
        }
      } else {
        counter = 1;
      }
    }
    if (flag) {
      isChecked = true;
    } else {
      isChecked = false;
    }
  }

};


class ConsecutivePolicy: public Policy {
  private: uint16_t maxCount;
  public: 
  ConsecutivePolicy(uint16_t value) {
    this -> maxCount = value;
  }
  void check(const string & str) {
    uint16_t counter = 0;
    bool flag = true;
    for (int i = 0; i < str.size() - 1; i++) {
      if (i != 0) {
        if (str[i] == str[i - 1] + 1) {
          counter++;
          if (counter > maxCount) {
            flag = false;
            break;
          }
        } else counter = 1;
      } else counter = 1;
    }
    if (flag) {
      isChecked = true;
    } else {
      isChecked = false;
    }
  }

};

string checkPassword(string pass, vector < Policy * > policies) {
  bool flag = true;
  for (auto i: policies) {
    i -> check(pass);
    if (i -> getCheck()==false) {
      flag = false;
    }
  }
  if (flag==true) {
    return "OK";
  }
  return "NOK";

}

int main() {
       vector < Policy * > policies;
       vector < string > passwords;
       string policy;
      string pass;
      string min_max_values;
      char password[999];
      int min = 0, max = 0;
      uint16_t num, num1, num2;
      char char_value, char_value1;
      int counter = 0;
      int n, i;
      cin >> n;
      for (i = 0; i < n; i++) {
        cin >> policy;
        if (policy == "class") {
          cin >> num;
          policies.push_back(new ClassPolicy(num));
        }
        if (policy == "repetition") {
          cin >> num;
          policies.push_back(new RepetitionPolicy(num));
        }
        if (policy == "include") {
          cin >> char_value;
          policies.push_back(new IncludePolicy(char_value));
        }
        if (policy == "consecutive") {
          cin >> num;
          policies.push_back(new ConsecutivePolicy(num));
        }
        if (policy == "ninclude") {
          cin >> char_value;
          policies.push_back(new NotIncludePolicy(char_value));
        }
        if (policy == "length") {
          getline(cin, min_max_values);
          int position;
          counter = 0;
          min = max = 0;
          for (auto i: min_max_values) {
            if (i == ' ') {
              counter++;
            }
          }
          if (counter == 1) {
            for (i = 1; i < min_max_values.size(); i++) {
              min = min * 10 + (int(min_max_values[i]) - 48);
            }
            policies.push_back(new LengthPolicy(min));
          } else {
            for (i = 1; i < min_max_values.size(); i++) {
              if (min_max_values[i] == ' ') {
                position = i;
                break;
              }
              if (min_max_values[i] != ' ')
                min = min * 10 + (int(min_max_values[i]) - 48);
            }
            for (i = position + 1; i < min_max_values.size(); i++) {
              max = max * 10 + (int(min_max_values[i]) - 48);
            }
            policies.push_back(new LengthPolicy(min, max));
          }

        }

      }
      while (cin >> pass) {
        passwords.push_back(pass);
      }

      for (i = 0; i < passwords.size(); i++)
        cout << checkPassword(passwords[i], policies) << endl;
  return 0;
}