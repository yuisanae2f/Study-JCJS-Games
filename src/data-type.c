#include <stdio.h>
#include <stdint.h>

int var; // 변수
int func(int a, int b); // 함수

int (*pointerVar); // Var에 대한 포인터
int* (pointerInt); // int에 대한 포인터 (자료형에 대한 포인터)

int* func_pointerInt(int a, int b); // int에 대한 pointer를 반환하는 함수
int (*func_pointerVar)(int a, int b); // int를 반환하는 함수의 포인터를 저장할 수 있는 변수

typedef int var_t; // 변수의 타입
typedef int func_t(int a, int b); // 함수의 타입
typedef int (*pointerVar_t); // Var에 대한 포인터의 타입
typedef int* (pointerInt_t); // int에 대한 포인터의 타입
typedef int* func_pointerInt_t(int a, int b); // int에 대한 pointer를 반환하는 함수 자체가 타입이 됨
typedef int (*func_pointerVar_t)(int a, int b); // int를 반환하는 함수의 포인터를 저장할 수 있는 변수

int func_region_ex_const_qualifiers();

int main() {
    // 정수 타입들을 재정의 해놓은 곳이에요
    // 컴파일러마다, 아키텍쳐마다 정수 크기들이 달라지는 경우가 있음
    // 혼란 - 파괴 - 망가
    // 해결하기 위해서 미리 정의된 정수 형태들을 쓰는 거에요
    // 그러면 우리는 char, unsigned char, 외울 필요 없음
    // 우리는 뻐킹 int, uint만 기억하면 돼요
    // char, unsigned, short

    // 정수
    int8_t a; // 8비트 char
    int16_t aa; // 16비트 short
    int32_t aaa; // 32비트 int(ㅆㅂ Dynamic 씹새끼)
    int64_t aaaa; // 64비트 long

    // 아래는 부호가 없는 정수들임
    uint8_t au; // 8비트 char
    uint16_t aau; // 16비트 short
    uint32_t aaau; // 32비트 int(ㅆㅂ Dynamic 씹새끼)
    uint64_t aaaau; // 64비트 long

    // 실수
    float f; // 4바이트
    double lf; // 8바이트
    long double llf; // 10 ~ 16바이트

    // 구조체
    struct Structure {
        int a;
        int b; // 멤버
    };

    struct Structure structure;
    structure.a = 3;
    printf("%d\n", structure.b); // Undefined behaviour
    

    // 공룡 구조체 (크아아앙)
    // 공용 구조체 (같이 쓴다고)
    union UnionStructure {
        int a;
        int b;
    };
    union UnionStructure _union;
    _union.a = 3;
    printf("%d\n", _union.b);
    printf("ptr: unionStructure: %p %p\n", &_union.a, &_union.b);

    func_t* func_ptr; // 함수 포인터

    func_region_ex_const_qualifiers();

    return 0;
}

int func_region_ex_const_qualifiers() {
    int a = 5; // 변경이 가능해요!
    a = 4;

    // 방은 할당이 되어 있기 때문에
    // 그리고 포인터는 원본이 어떻게 생겼든 뻑-유를 시전하기 때문에
    const int b = 4; // readonly, 안 바뀌어요
    // b = 7; // 응아니야 
    
    int* ptr_a = &a;
    *ptr_a; // a의 값 확인 가능
    *ptr_a = 3; // a의 값 수정 가능

    // 이후 a는 3이 될 것임 ㅅㄱ
    
    const int* ptr_a_const = &a;
    *ptr_a_const; // 확인 가능
    // *ptr_a_const = 3; // 응아니야

    // initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]GCC
    int* ptr_b_fucking_dangerous = &b; // ?
    *ptr_b_fucking_dangerous; // 확인 가능
    *ptr_b_fucking_dangerous = 5; // 변경 가능

    // 이후로 b는 5가 되어 있음 (이러지 마십시오)

    // 포인터는 그냥 정수에요 ㅈ도 몰라요 그냥
    // 포인터는 원본을 신경쓰지 않아요
    // 포인터가 무슨 짓을 할지는 순전히 프로그래머가 정해야 해요

    const char ItisjustaSingleChar = 0;

    // 이게 가능하다 이1말이야
    // 보통 이래서 문제 생겨요ㅋㅋㅋㅋ
    int* fuckit = (int*)&ItisjustaSingleChar; // ?
    fuckit[0] = 7; // 위에 있는 어딘가의 스택 프레임을 참조하겠지 ㄹㅇㅋㅋ

    printf("%d\n", fuckit[0]);

    // qualifier 타락
    printf("%d\n", ItisjustaSingleChar);
    // ItisjustaSingleChar = 3; // 정절은 지켜짐
    
    int dir_a, dir_b;
    const int* only_one_direction_willing = &dir_a; // 포인트하는 메모리의 위치를 바꾸지 않고 싶을 수 있음
    only_one_direction_willing = &dir_b; // 환승연애 쌉가능

    int* const romantist = &dir_a;
    // romantist = &dir_b; // 해바라기다
    
    return 0;
}


int func_region_ex_complex_grammers() {
    // 앞에 기본 자료형이 있으면 여러 변수를 만들 수 있습니다.
    // 보통 기본 타입 이외에는 그냥 다 악세사리 취급이니까요.
    // 악세사리 취급 받지 않는 기본 자료형을 공유받을 경우 다음과 같습니다.
    int 
        /// @brief
        /// int Int;
        Int, 
        /// @brief
        /// int *Int_ptr
        *Int_ptr, 
        /// @brief
        /// int Int_Func();
        Int_Func(), 
        /// @brief
        /// int (*Int_Func_Ptr)();
        (*Int_Func_Ptr)(), 
        /// @brief
        /// int *(*IntPtr_Func_Ptr)();
        (*(*IntPtr_Func_Ptr)());

    // 아 물론 앞에 typedef 붙이면 새로운 타입이 될 거에요.
    typedef int int_t, *int_ptr_t, int_func_t(), (*int_func_ptr_t)();

    // 구조체
    typedef const struct StructureName {
        int Member;
        int Member2;
        // ...
    } // 이 시점에서 새로운 자료형이 생김
        /// @brief
        /// const struct StructureName
        StructureName_const_t, 

        /// @brief
        /// const struct StructureName* (*const func_StructureNameInstance_ptr_t)(int a, int b) \n
        /// :함수 포1인터 타입
        * (*const func_StructureNameInstance_ptr_t)(int a, int b);

    

    // 이걸 이해하잖아요?
    // 오늘 학습은 제대로 하신 겁니다

    return 0;
}