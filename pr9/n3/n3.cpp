#include <iostream>
#include <algorithm>

using namespace std;

template<typename Atype>
class Set {
private:
    Atype* a;
    int len;
public:
    Set() {
        len = 0;
        a = nullptr;
    };
    Set(Atype* arr, int size) {
        a = new Atype[size];
        for (int i = 0; i < size; i++) a[i] = arr[i];
        len = size;
    }
    ~Set() {
        delete[] a;
    }
    bool Is_Empty() {
        return len == 0;
    }
    bool Add(Atype T) {
        if (In_Set(T)) return false;
        else {
            Atype* new_a = new Atype[len + 1];
            for (int i = 0; i < len; i++) new_a[i] = a[i];
            new_a[len] = T;
            if (a != nullptr) delete[] a;
            a = new_a;
            len++;
            return true;
        }
    }
    bool In_Set(Atype T) {
        for (int i = 0; i < len; i++) {
            if (a[i] == T) return true;
        }
        return false;
    }
    Atype Get(Atype T) {
        for (int i = 0; i < len; i++) {
            if (a[i] == T) return a[i];
        }
        return 0;
    }
    void Remove(Atype val) {
        if (!In_Set(val)) return;
        Atype* new_a = new Atype[len - 1];
        int j = 0;
        for (int i = 0; i < len; i++, j++) {
            if (a[i] != val) {
                new_a[j] = a[i];
            }
            else {
                j--;
            }
        }
        delete[] a;
        a = new_a;
        len--;
    }

    void Print() {
        cout << "Set: ";
        for (int i = 0; i < len; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    Set Union(Set& other) {
        Set res;
        for (int i = 0; i < len; i++)
            res.Add(a[i]);
        for (int i = 0; i < other.len; i++)
            res.Add(other.a[i]);
        return res;
    }

    Set Intersection(Set& other) {
        Set res;
        for (int i = 0; i < len; i++)
            if (other.In_Set(a[i]))
                res.Add(a[i]);
        return res;
    }

    bool Is_Subset(Set& other) {
        for (int i = 0; i < len; i++)
            if (!other.In_Set(a[i]))
                return false;
        return true;
    }
};

int main() {
    cout << "Sets of integer numbers" << endl;
    int a[3] = { 1, 2, 3 };
    Set<int> s(a, 3);
    s.Add(3);
    s.Add(4);
    s.Print();
    s.Is_Empty() ? cout << "Is empty!\n" : cout << "Is not empty\n";
    s.In_Set(1) ? cout << "1 in set\n" : cout << "1 not in set\n";
    s.In_Set(5) ? cout << "5 in set\n" : cout << "5 not in set\n";
    cout << "Get 3: " << s.Get(3) << endl;

    int a2[1] = { 4 };
    Set<int> s2(a2, 1);
    s2.Add(4);
    s2.Add(5);
    s2.Add(6);
    cout << endl;
    s2.Print();
    cout << endl;
    cout << "Union of two sets" << endl;
    Set<int> s3 = s.Union(s2);
    s3.Print();
    cout << "Intersection of two sets" << endl;
    Set<int> s4 = s.Intersection(s2);
    s4.Print();

    if (s.Is_Subset(s2)) { cout << "It's subset\n"; }
    else { cout << "It isn't subset\n"; }

    cout << "\nSet of chars\n";
    Set<char> b;
    b.Add('a');
    b.Add('b');
    b.Add('c');

    b.Print();
    b.Remove('a');
    b.Print();
    b.Is_Empty() ? cout << "Is empty!\n" : cout << "Is not empty\n";
    b.In_Set('c') ? cout << "'c' in set\n" : cout << "'c' not in set\n";

    return 0;
}
