#include <iostream>

using namespace std;

int main() {

    long long X, Y;
    std::cin >> X >> Y;

    long long z = (100 * Y) / X;

    if (z >= 99) {
        printf("-1");
        return 0;
    }

    // 오른쪽과 왼쪽을 기준으로 각각 최대, 최소 값 설정
    // 최대 1억번 까지 했을 때는 무조건 승률이 오를 수 밖에 없음.
    // 이미 100%가 아닌 이상은 2배의 게임을 이미 하는 것이기 때문
    long long right = 1000000000;
    long long left = 0;


    while(left <= right){
        long long mid = (left + right) / 2;
        // 중간 정도 플레이 했을 때 기준으로 승률을 계산함
        long long temp = (100 * (Y + mid)) / (X + mid);

        // 새로 계산한 승률이 이전 승률보다 큰 경우는 적어도 중간이나 중간 밑 까지
        // 게임해도 승리할 수 있다는 의미임.
        if (temp > z){
            right = mid - 1;
        }

        // 반면에 절반 게임했을 때도 승률이 변동되지 않은 (이전보다 높지 않은) 경우는
        // 게임을 더 해야하기 때문에 왼쪽의 값을 변경해준다.
        else if (temp <= z){
            left = mid + 1;
        }
    }

    printf("%lld", left);

    return 0;
}