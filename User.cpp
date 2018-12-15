//
// Created by andrea on 12/14/18.
//

#include "User.h"
#include <fstream>
using std::ifstream;
using std::ostream;



User::User(const string &name, const string &username, const string &pw, int age, const string &gender,
           const vector<string> &interests) : name(name), username(username), pw(pw), age(age), gender(gender),
                                              interests(interests) {
    vector<User*> amiwis;
    contacts = amiwis;
}

User::User(const string &name, const string &username, const string &pw, int age, const string &gender) : name(name),
                                                                                                          username(
                                                                                                                  username),
                                                                                                          pw(pw),
                                                                                                          age(age),
                                                                                                          gender(gender) {}

User::User() {}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

int User::getAge() const {
    return age;
}

void User::setAge(int age) {
    User::age = age;
}

const string &User::getGender() const {
    return gender;
}

void User::setGender(const string &gender) {
    User::gender = gender;
}

void User::addInterests(string ints) {
    interests.push_back(ints);
}

void User::addFriend(User* amiguis) {
    contacts.push_back(amiguis);
}

void User::unFriended(User* amiguis) {
    for (int i = 0; i < contacts.size(); ++i) {
        if (amiguis == contacts.at(i)) {
            contacts.erase(contacts.begin() + i);
        }
    }
}

const string &User::getUsername() const {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const string &User::getPw() const {
    return pw;
}

void User::setPw(const string &pw) {
    User::pw = pw;
}

const vector<User*> &User::getContacts() const {
    return contacts;
}

const vector<string> &User::getInterests() const {
    return interests;
}

void User::setInterests(const vector<string> &interests) {
    User::interests = interests;
}

string User::toString() {
    string tostring;
    tostring = getName() + " ("+std::to_string(getAge())+" / "+getGender()+" / "+getUsername() + ")";
    return tostring;
}

void User::write(ofstream & out) {
    int size = getName().size();
    out.write(reinterpret_cast<char*>(&size), sizeof(int));
    out.write(getName().data(), size);

    size = getGender().size();
    out.write(reinterpret_cast<char*>(&size), sizeof(int));
    out.write(getGender().data(), size);

    size = getUsername().size();
    out.write(reinterpret_cast<char*>(&size), sizeof(int));
    out.write(getUsername().data(), size);


    size = getPw().size();
    out.write(reinterpret_cast<char*>(&size), sizeof(int));
    out.write(getPw().data(), size);
    out.write(reinterpret_cast<char*>(&age), sizeof(int));
}



void User::read(ifstream& in) {
    int size;
    in.read(reinterpret_cast<char*>(&size), sizeof(int));
    char nameBuffer[size+1];
    in.read(nameBuffer, size);
    nameBuffer[size] = 0;

    name = nameBuffer;
    in.read(reinterpret_cast<char*>(&size), sizeof(int));
    char numBuffer[size+1];
    in.read(numBuffer, size);
    numBuffer[size] = 0;
    gender = numBuffer;
    in.read(reinterpret_cast<char*>(&size), sizeof(int));
    char carreraBuffer[size+1];
    in.read(carreraBuffer, size);
    carreraBuffer[size] = 0;
    username = carreraBuffer;
    in.read(reinterpret_cast<char*>(&age), sizeof(int));

}