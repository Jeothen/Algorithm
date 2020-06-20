#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int range = 1'000'000;

bool chk[range+1];

int main() {
	freopen("1016.txt", "r", stdin);
	ll a, b; scanf("%lld %lld", &a, &b);
	ll root = static_cast<ll>(sqrt(b));
	ll answer = b-a+1;
	for (ll i = 2; i <= root; i++) {
		ll square = i * i;
		ll start = (a / square) * square;
		for (ll j = start; j <= b; j += square) {
			if (j >= a && !chk[j-a]) {
				answer--;
				chk[j - a] = true;
			}
		}
	}
	printf("%lld", answer);
}