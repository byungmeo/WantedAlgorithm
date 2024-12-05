#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
  int N;
  int A,B;
  
  std::cin >> N >> A >> B;
  
  int result = 1;
  
  // A가 홀수고 B가 해당 값 보다 1이 큰 짝수면 반드시 붙어 경기를 치뤄야 한다.
  if ((A + 1) / 2 == (B + 1) / 2) {
    std::cout << result;
    return 0;
  }
  
  // 매번 16강, 8강, 4강을 비교하기 위해 i가 2씩 곱하면서 상위권으로 진입한다.
  // N이 만약 딱 떨어지지 않고 남는 경우에 대비해 2를 곱해 그 이상까지 점검한다.
  // 만약 그 전에 딱 떨어지는 경우는 이전에 종료된다.
  for (int i = 4; i <= N * 2; i *= 2) {
    // 이미 이 반복문은 최소한의 예선전 이상이기 때문에 1을 더하고 시작한다.
    result++;
    // 위에서는 N강을 나타냈다면 여기는 N강의 멤버들을 확인해 내부에 값이 있는지 체크
    // 반올림을 이용해서 만약 남는 숫자가 있는 경우는 부전승 처리로 한다.
    // 1이 남는 경우는 어차피 존재하지 않는 번호와 비교되기 떄문에 당장 문제는 없다
    // 
    // N이 16일 때 1 ~ 4, 5 ~ 8, 9 ~ 12, 13 ~ 16
    // j가 1 ~ 4까지 순회
    // 1 + (j * i) ~ j * i + i
    
    
    double TotalGroup = ceil((double) N / i);
    for (int j = 0; j < TotalGroup; j++) {
      int GroupStart = 1 + j * i;
      int GroupEnd = i + j * i;
        
      if (GroupEnd > N) {
        GroupEnd = N;
      }
      if ((GroupStart <= A && GroupEnd >= A) && (GroupStart <= B && GroupEnd >= B)) {
        std::cout << result;
        return 0;
      }
    }
  }
  std::cout << -1;
  return 0;
}