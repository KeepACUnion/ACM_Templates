#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6+10;
char s[maxn];
int n;

int smallestRepresentation()
{
    n = strlen(s);
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        if(s[(i+k)%n] == s[(j+k)%n])k++;
        else{
            if(s[(i+k)%n] > s[(j+k)%n])i += k+1;
            else j += k+1;
            if(i == j)j++;
            k = 0;
        }
    }
    return min(i, j);
}
