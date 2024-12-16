// operator (연산자)
// 값을 가져다가 요리조리 요리를 하는 거를

// 기초 연산자

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
int main() {
    // 산술 연산자
    3 + 4; // 7
    6 - 2; // 4
    2 * 4; // 8
    5 / 2; // 2 정수가 나와야 함
    (5 - (5 / 2) * 2); // 나머지?
    (5 % 2); // 나머지!

    // Logicwise
    // 피연산자들이 무조건 비트 하나만 쓴다고 가정할 거에요
    // 0이면 거짓이다. 나머지는 참이다.

    // AND
    // 둘 중에 하나 false? false
    true && false; // 0(false) 논리곱, AND
    true && true; // true

    // OR
    // 둘 중에 하나 true? true
    true || false; // 1(true), 논리합, OR

    // NOT
    !true; // 0(false) 반전, NOT

    // XOR
    !!true != !!false; // 둘 중에 하나 다르면 true

    // Bitwise
    // 피연산자의 비트를 하나하나 세어서 생각한다.

        0b1011001
    &   0b0010010;
    //  0b0010000, bit AND

        0b1011001
    |   0b0010010;
    //  0b1011011, bit OR

    ~   0b1011001;
    //  0b0100110, bit NOT

        0b1011001
    ^   0b0010010;
    //  0b1001011 bit XOR

    // 앞의 다섯 비트: x방향의 힘
    // 뒤의 다섯 비트: y방향의 힘
    // 0bxxxxxyyyyy
    typedef uint16_t vec2D_t; // 0b1111111111111111
    typedef uint8_t sclr_t; // 0b11111111
    const vec2D_t a = 0b1011101000;

    // vec2D라는 자료형을 가진 a에서
    // x 방향으로의 힘을 구하고 싶어요
    // 그니까 벡터에서 x를 추출하고 싶은 거임
    sclr_t a_sclr_x = a & 0b1111100000;

    //      0bxxxxxyyyyy
    // &    0b1111100000
    //      0bxxxxx00000 추출 완료

    // ? -> 0bxxxxx

    // bit-shift
    // 0bxxxx0ccc >> 3 오른쪽으로 세 칸 가세요
    // 0b000xxxx0
    
    // 왼쪽에서 채워지는 건 부호 비트를 따른다
    // 만약 unsigned잖아요? 양수 부호 비트는 무조건 0이에요. 그러니까 0으로 채워질 거에요
    // 근데 signed잖아요? 양수면? 0이 채워져요. 음수면? 1로 채워져요

    // 0bxxxx0ccc << 2 왼쪽으로 두 칸 가세요
    // 0bxx0ccc00 오른쪽에서는 무조건 0으로 채워 줄 거에요!

    // a_sclr_xd에서 x방향으로의 힘을 추출하고 싶으면 어떻게 해야 할까요?
    a_sclr_x >> 5; // 0bxxxxx

    4 > 3; // 4는 3보다 크니?
    4 < 3; // 4는 3보다 작니?

    3 > 3; // 3은 3보다 크지 않기 때문에 거짓임
    3 == 3; // 3은 3이니?
    1 + 2 == 3; // 1 + 2는 3이기 때문임

    // 소수는 상종하는 거 아니에요. 알겠죠?
    1.1 + 0.1 == 1.2; // 아님. 실제로는 왼쪽이 더 크다.
    1.1f + 0.1f == 1.2f; // 더 부정확하게 계산함. 역치가 더 크기 때문에 대강 맞다! 라고 봐 주는 거에요

    // 더 큰 자료형인 double로 타입캐스팅됨. 오른쪽도 같이 double이 됨.
    // 1.1 + 0.1 != 1.2랑 같아짐
    1.1 + 0.1f != 1.2f;

    // 제어문과 비교 연산자를 섞었다.
    // 그리고 세 개의 피연산자를 사용하는 "유일한" 연산자이기 때문에
    // 편의상 삼항연산자

    true ? 10/*참일 경우 결정되는 값*/ : -5/*거짓일 경우 결정되는 값*/; 
    true ? (false ? 5 : -4) : (true ? 5 : 2); // -4
    // 쓰레기 같은 방식 (이거 중복되면 보기 힘듦)
    // (truevalue if condition else elsevalue)

    // reference
    // 변수의 위치를 참조하는 것
    const int peanut = 5;

    // &는 땅콩을 가리키기 위하여 사용됨
    // 땅콩이라는 변수의 위치를 정수로 받아옵니다
    int* anyaa = &peanut; 

    // dereference
    // 위치로 값을 참조하는 것
    (*anyaa)--;
    printf("%d\n", peanut);

    // 배열로 만들 경우 그 이름은 포인터 역할을 해요
    int peanuts[7] = {0, };
    int* anyaashadow = peanuts;
    *(anyaashadow + 2) == *(2 + anyaashadow);
    anyaashadow[2] == 2[anyaashadow]; // 문제 없음

    // 포인터는 ㅈ도 모른다
    // 그냥 정수다
    // 어떻게 사용할지는? 프로그래머가 전부 정한다
    anyaashadow[-1]; // "이론상" 문제 없음

    typedef struct ___A {
        int a, b, c, d;
    } A_t;

    A_t aaa = {15, 16, 32, 32767};
    A_t* p_aaa = &aaa;

    (*p_aaa).a;
    p_aaa[0].a;
    p_aaa->a;
    ((int*)p_aaa)[1] = 4;
    printf("%d\n", aaa.b);
    printf("%d\n", sizeof(A_t));
    printf("%d\n", sizeof(int));

    return 0;
}