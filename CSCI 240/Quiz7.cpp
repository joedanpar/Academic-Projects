#include <iostream>
using namespace std;

int main()
{
int i, j, k;
int ans;
string s; 

i = 4; // 1
j = 7; // 2
ans = 4 * j/i + 9; // 3
i = 0; // 4

while (ans > 0) // 5
{
i++; // 6
ans--; // 7
}

if (j % 2 / 2) // 8
  ans = 1; // 9
else
  ans = 2; // 10
ans += k; // 11

return 1;
}

