#include <iostream>
#include <algorithm>
#include <cstring>
#include <random>
#include <set>
#include <vector>
#include <string>

using namespace std;

void f1() {
    vector<string> fruits = {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto it= find_if(fruits.begin(), fruits.end(),
        [](const string &fruit){return fruit.find("berry")<fruit.size();});

    if (it != fruits.end()) cout << "Found." <<endl;
    else cout << "Not found." <<endl;
}

void f2() {
    vector<int> integers={2,2,4};
    auto it2= all_of(integers.begin(), integers.end(),
        [](int e){return e%2==0;});

    if (it2) cout << "Found." <<endl;
    else cout << "Not found." <<endl;
}

void f3() {
    vector<int> integers={2,2,4};
    for_each(integers.begin(), integers.end(),
        [](int &e){return e=e*2;});

    for (int i=0;i<integers.size();i++) {
        cout << integers[i] << endl;
    }
}

void f4() {
    vector<string> months { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int count=count_if(months.begin(), months.end(),
        [](string &e) {
            if(e.size()<5) return false;

            set<char> letters;
            for(int i=0;i<e.size();i++) letters.insert(e[i]);
            if(letters.size()<5) return false;
            return true;
        });

    cout << count << endl;
}

void f5() {
    vector<int> integers={2,1,4,3};
    sort(integers.begin(), integers.end(),greater<int>());

    for (int i=0;i<integers.size();i++) {
        cout << integers[i] << endl;
    }
}

void f6() {
    vector<pair<string,double>> months=
        {{"January",12.2}, {"February",10.2}, {"March",18.7}, {"April",18.6}, {"May",15.1},
        {"June",15.3}, {"July",12.7}, {"August",13.3}, {"September",14.6}, {"October",9.6},
        {"November",8.3}, {"December",8.2}};

    sort(months.begin(), months.end(),
        [](pair<string,double> &a,pair<string,double> &b){return a.second<b.second;});

    for (int i=0;i<months.size();i++) {
        cout << months[i].first<<" "<< months[i].second << endl;
    }
}

void f7() {
    vector<double> integers={-2.1,1.5,4.8,-3.2};
    sort(integers.begin(), integers.end(),
        [](double &a,double &b){return abs(a)<abs(b);});

    for (int i=0;i<integers.size();i++) {
        cout << integers[i] << endl;
    }
}

void f89() {
    vector<string> months { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    for_each(months.begin(), months.end(),
        [](string &e){e[0]=e[0]+32;});

    //for (int i=0;i<months.size();i++) cout << months[i] << endl;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<char> weirdA(alphabet.begin(), alphabet.end());
    std::mt19937 rng(0); // fixed seed, deterministic result
    shuffle(weirdA.begin(), weirdA.end(), rng);

    auto indexOf = [&](char c) {
        return std::find(weirdA.begin(), weirdA.end(), c) - weirdA.begin();
    };
    sort(months.begin(), months.end(),
         [&](string &a, string &b){ return indexOf(a[0]) < indexOf(b[0]); });

    for (int i=0;i<months.size();i++) cout << months[i] << endl;
}

int main() {
    f89();

    return 0;
}