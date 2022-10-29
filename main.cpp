#include <iostream>
#include <math.h>

int main() {
	std::cout << std::fixed;
	std::cout.precision(14);

    std::cout << "Enter a positive integer number, and you will get the best common fraction approximation with numerator and denominator equal or less than the entered number" << std::endl;
	int n;
	std::cin >> n;

	long double ans = 100;
	int up = -1;
	int down = -1;
	for (int i = 3; i <= n; i++) {
		int l = 1, r = i;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (((long double) i / m) < M_PI)
				r = m;
			else
				l = m;
		}
		if (abs(M_PI - (long double) i / l) < ans) {
			ans = abs(M_PI - (long double) i / l);
			up = i;
			down = l;
		}
		if (abs(M_PI - (long double) i / (l - 1)) < ans) {
			ans = abs(M_PI - (long double) i / (l - 1));
			up = i;
			down = l + 1;
		}
	}
	std::cout << "Decimal interpretation (15 digits): " << (long double) up / down << std::endl;
	std::cout << "Common fraction: " << up << '/' << down << std::endl;
	std::cout << "Difference between fraction and Pi constant number: " << ans << std::endl;
	return 0;
}
