#include <cstdio>
#include <cstring>
#include <climits>
#include <map>

using namespace std;

int main(){
    //char a[2], b[2];
    //scanf("%s %s", a, b);
    //printf("%d\n%d", INT_MAX, INT_MIN);
    map<string, double> a;
    a["2"] = 3;
    a["2"] += 4.5;
    a.insert(map<string, double>::value_type("2", 10));
    printf("%d %lf", 2, a["2"]);
}