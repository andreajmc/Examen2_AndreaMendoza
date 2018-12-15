//
// Created by andrea on 12/14/18.
//

#ifndef EXAMEN2_ANDREAMENDOZA_USER_H
#define EXAMEN2_ANDREAMENDOZA_USER_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;
using std::ofstream;

class User {
private:
    string name;
    string username;
    string pw;
    int age;
    string gender;
    vector <string> interests;
    vector<User*> contacts;

public:

    User(const string &name, const string &username, const string &pw, int age, const string &gender,
         const vector<string> &interests);

    User(const string &name, const string &username, const string &pw, int age, const string &gender);

    User();

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);

    const string &getGender() const;

    void setGender(const string &gender);

    void addInterests(string);

    void addFriend(User*);

    void unFriended(User*);

    bool operator== (const User &amiguis) {
        return amiguis.getName() == name && amiguis.getAge() == age && amiguis.getGender() == gender && username == amiguis.getUsername() && pw == amiguis.getPw();
    }

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPw() const;

    void setPw(const string &pw);

    string toString();

    const vector<User*> &getContacts() const;

    const vector<string> &getInterests() const;

    void setInterests(const vector<string> &interests);

    void write(ofstream&);
    void read(ifstream&);
};


#endif //EXAMEN2_ANDREAMENDOZA_USER_H
