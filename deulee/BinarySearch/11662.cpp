#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
	double x, y;
};

// 주어진 t 값에서의 두 점 사이 거리 계산
double getDistance(Point A1, Point A2, Point B1, Point B2, double t) {
	double Ax = A1.x + (A2.x - A1.x) * t;
	double Ay = A1.y + (A2.y - A1.y) * t;
	double Bx = B1.x + (B2.x - B1.x) * t;
	double By = B1.y + (B2.y - B1.y) * t;

	return sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
}

int main() {
	// 입력값을 받을 네 개의 점
	Point A1, A2, B1, B2;
	cin >> A1.x >> A1.y >> A2.x >> A2.y;
	cin >> B1.x >> B1.y >> B2.x >> B2.y;

	// 삼분 탐색을 위한 초기 범위
	// 0~1 사이로 정규화 (마치 Lerp의 Alpha를 보는 듯한 이느낌)
	double left = 0.0, right = 1.0;

	// 오차 범위 설정
	const double EPS = 1e-9;

	while (right - left > EPS) {
		double t1 = left + (right - left) / 3;
		double t2 = right - (right - left) / 3;

		double d1 = getDistance(A1, A2, B1, B2, t1);
		double d2 = getDistance(A1, A2, B1, B2, t2);

		// 최소 거리를 찾는 방향으로 범위를 좁힘
		if (d1 < d2) {
			right = t2;
		} else {
			left = t1;
		}
	}

	// 최소 거리 출력 (소수점 10자리까지)
	cout << fixed << setprecision(10) << getDistance(A1, A2, B1, B2, (left + right) / 2) << endl;

	return 0;
}
