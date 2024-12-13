#include <stdio.h>

// Logger
// 받아가지고 그걸 그대로 출력해 주고 싶어요
typedef void func_Log_t(const char* string);

void func_std_line(const char* string) {
    printf("LOG: %s\n", string);
}

void func_err_line(const char* string) {
    printf("ERROR: %s\n", string);
}

int main() {
    func_Log_t* logger = 0; // 이거 0이야
    #if 0
    logger("Hello World!"); // 난 0이라는 주소를 쓰라고 준 기억이 없어
    // 너 뭐야 씨발아 (Segfault)
    #else
    logger = &func_std_line; // 나는 함수의 포인터 func_a를 가리킬 거야
    logger("Hello World!"); // 함수 func_a를 실행한다
    #endif
    
    return 0;
}