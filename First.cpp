#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i ++)

int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    
    string s;
    getline(cin, s);
    int n = s.length();
    int cnt = 0;
    bool flag = 0, f = 0, f1 = 0;
    int tab = 4;

    for(int i = 0; i < n;) {
        if(s[i] == '{') {
            flag = 0;
            if(f1) {
                cout << "\n";
                f1 = 0;
            }
            rep(j, 0, cnt) {
                cout << " ";
            }
            f = 1;
            cout << s[i] << "\n";
            cnt += tab;
            i ++;
        }
        else if(s[i] == '}') {
            if(f1 == 1) {
                cout << "\n";
                f1 = 0;
            }
            cnt -= tab;
            rep(i, 0, cnt) cout << " ";
            if(s[i + 1] == ',') {
                cout << s[i] << s[i + 1] << "\n";
                f = 1;
                i += 2;
            }
            else {
                cout << s[i] << "\n";
                i ++;
            }
        }
        else if(s[i] == '[') {
            if(s[i + 1] == '{') {
                f = 1;
                cout << s[i] << "\n";
                cnt += tab;
                rep(j, 0, cnt) cout << " ";
                cnt += tab;
                cout << s[i + 1] << "\n";
                i += 2;
            }
            else {
                flag = 1;
                cout << s[i];
                i ++;
            }
        }
        else if(s[i] == ']') {
            if(s[i + 1] == ',') {
                if(f1 == 0) {
                    rep(j, 0, cnt - 4) cout << " ";
                    cnt -= tab;
                }
                cout << s[i] << s[i + 1] << "\n";
                f = 1;
                flag = 0;
                i += 2;
            }
            else {
                if(f1 == 1) {
                    f1 = 0;
                }
                else {
                    cnt -= tab;
                    rep(j, 0, cnt) cout << " ";
                }
                cout << s[i] << "\n";
                i ++;
            }
        }
        else if(s[i] == ',') {
            if(flag or ((s[i + 1] >='a' and s[i + 1] <= 'z') or s[i + 1] == ' ')) {
                cout << s[i];
                i ++;
            }
            else {
                cout << s[i] << "\n";
                f = 1;
                i ++;
            }
        }
        else {
            if(f == 1) {
                rep(j, 0, cnt) cout << " ";
            }
            f = 0;
            cout << s[i];
            f1 = 1;
            i ++;
        }
    }
    return 0;
}
