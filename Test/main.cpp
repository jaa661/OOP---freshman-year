/*
  The STL. Standard Template Library
  Sec 
*/

#include <vector>
#include <iostream> 
#include <list>
#include <algorithm>
using namespace std;

// char* myFind(char* start, char* stop, char target) {
//     for (char* p = start; p != stop; ++p) {
//         if (*p == target) return p;
//     }
//     return stop;
// }

// list<char>::iterator myFind(list<char>::iterator start,
//                             list<char>::iterator stop, char target) {
//     for (list<char>::iterator p = start; p != stop; ++p) {
//         if (*p == target) return p;
//     }
//     return stop;
// }

// template <typename fred>
// fred myFind(fred start, fred stop, char target) {
template <typename fred, typename george>
fred myFind(fred start, fred stop, george target) {
    for (fred p = start; p != stop; ++p) {
        if (*p == target) return p;
    }
    return stop;
}

bool isEven(int n) {
    return n%2 == 0;
}

int main() {

    char array[] = "Bjarne Stroustrup";
    int len = 17;

    vector<char> vc(array, array+len);

    cout << array << endl;
    sort(array, array+len);
    cout << array << endl;

    list<char> lc(array, array+len);

    for (size_t i = 0; i < vc.size(); ++i) {
        cout << vc[i] << ' ';
    }
    cout << endl;

    for (size_t i = 0; i < lc.size(); ++i) {
        //        cout << lc[i] << ' ';
    }
    cout << endl;

    for(vector<char>::iterator iter = vc.begin(); iter != vc.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    for(list<char>::iterator iter = lc.begin(); iter != lc.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    list<char> lc2(vc.begin(), vc.end());

    typedef list<char>::iterator LCI;
    for(LCI iter = lc.begin(); iter != lc.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    auto x = 17;
    auto pi = 3.14159;

    for(auto iter = lc.begin(); iter != lc.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    for (char c : vc) cout << c << ' ';
    cout << endl;

    for (char c : lc) cout << c << ' ';
    cout << endl;

    for (auto c : lc) cout << c << ' ';
    cout << endl;
    
    for (auto& c : lc) cout << c << ' ';
    cout << endl;
    
    for (const auto& c : lc) cout << c << ' ';
    cout << endl;
    
    if (find(lc.begin(), lc.end(), 'q') == lc.end()) {
        cout << "'q' is not in Bjarne Stroustrup\n";
    }

    //    char* where = find(array, array+len, 'q');
    char* where = myFind(array, array+len, 'q');
    if (where == array+len) {
        cout << "'q' is not in Bjarne Stroustrup\n";
    }

    list<int> li {1, 17, 2, 4, 20 31};
    auto result = find_if(li.begin(), li.end(), isEven);
    result = find_if(li.begin(), li.end(),
                     //[] (int n) { return n%2 == 0; } );
                     [] (int n) -> bool { return n%2 == 0; } );

    

}


