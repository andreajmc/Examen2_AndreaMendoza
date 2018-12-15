//
// Created by andrea on 12/14/18.
//

#include "User.h"

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

User::User(const string &name, const string &username, const string &pw, int age, const string &gender) : name(name),
                                                                                                          username(
                                                                                                                  username),
                                                                                                          pw(pw),
                                                                                                          age(age),
                                                                                                          gender(gender) {
    vector<User*> amiguis;
    contacts = amiguis;
    vector<string> ints;
    interests = ints;
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