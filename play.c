#include <stdio.h>



int main(){

  char num_a[100] = "19283746564738291828374658492190203821743674268423148347343187";

  char num_b[100] = "6459673984658736478136478126129038124728952734589374823641782481";

  char num_a_[100];

  char num_b_[100];

  char result[101] = ""; // �̰� �ʱ�ȭ �����ָ� ��� �ڿ� �̻��Ѱ� �ٴ´�

  int carry = 0;

  int sum = 0;

  int i = 0;



// sprintf_s: (������, ������, ���� ������, �ҽ�����)

// sprintf���� ������: ������ ���� (���� sprintf�� ������ ������ ���� �߸��ϸ� ���� �����÷ο�)

// %099s�� �ǹ�: %s (���ڿ�) �� ����ϵ� 99�ڰ� �ɶ����� 0�� �տ� ä��ٴ� ��

// %0100s�� �ϸ� ȭ�鿡 �ƹ��͵� �ȶ�. sprintf�� ����� ���� NULL�� ä��� ������ ���� �ʰ�

  sprintf_s(num_a_, sizeof(num_a_), "%099s", num_a);

  sprintf_s(num_b_, sizeof(num_b_), "%099s", num_b);

  printf("%s\n", num_a);

  printf("%s\n", num_b);

  printf("%s\n", num_a_);

  printf("%s\n", num_b_);



  for (i=sizeof(num_a_)-2; i>=0; i--){

    // �� �ڸ��� �ƽ�Ű �ڵ�ǥ�� ���ڷ� ó��, '0' �� ���� ���ڷμ��� ���� �ȴ�

    // �ٽ� ����迭�� �������� �ݴ�� '0' �� ������� ���ڰ� ��

    sum = (num_a_[i]-'0') + (num_b_[i]-'0') + carry;

    carry = sum / 10;

    sum = sum % 10;

    result[i+1] = sum + '0';

  }

  result[0] = carry + '0';



  for (i=0; result[i] == '0'; i++);

  printf("%s\n", result + i); // �迭 �����ּ� + iĭ. ���⼭ i�� ��Ա� ���ؼ��� i�� ������ ����



  return 0;

}