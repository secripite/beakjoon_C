#include <stdio.h>



int main(){

  char num_a[100] = "19283746564738291828374658492190203821743674268423148347343187";

  char num_b[100] = "6459673984658736478136478126129038124728952734589374823641782481";

  char num_a_[100];

  char num_b_[100];

  char result[101] = ""; // 이거 초기화 안해주면 결과 뒤에 이상한게 붙는다

  int carry = 0;

  int sum = 0;

  int i = 0;



// sprintf_s: (대상버퍼, 사이즈, 서식 지정자, 소스버퍼)

// sprintf와의 차이점: 사이즈 지정 (기존 sprintf는 사이즈 지정이 없어 잘못하면 버퍼 오버플로우)

// %099s의 의미: %s (문자열) 로 출력하되 99자가 될때까지 0을 앞에 채운다는 뜻

// %0100s로 하면 화면에 아무것도 안뜸. sprintf의 결과는 끝에 NULL을 채우기 때문에 길이 초과

  sprintf_s(num_a_, sizeof(num_a_), "%099s", num_a);

  sprintf_s(num_b_, sizeof(num_b_), "%099s", num_b);

  printf("%s\n", num_a);

  printf("%s\n", num_b);

  printf("%s\n", num_a_);

  printf("%s\n", num_b_);



  for (i=sizeof(num_a_)-2; i>=0; i--){

    // 각 자리는 아스키 코드표의 숫자로 처리, '0' 을 빼면 문자로서의 값이 된다

    // 다시 결과배열에 넣을때는 반대로 '0' 을 더해줘야 문자가 됨

    sum = (num_a_[i]-'0') + (num_b_[i]-'0') + carry;

    carry = sum / 10;

    sum = sum % 10;

    result[i+1] = sum + '0';

  }

  result[0] = carry + '0';



  for (i=0; result[i] == '0'; i++);

  printf("%s\n", result + i); // 배열 시작주소 + i칸. 여기서 i를 써먹기 위해서는 i를 위에서 선언



  return 0;

}