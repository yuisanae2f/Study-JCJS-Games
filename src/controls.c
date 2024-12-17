#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int condition_ctrl_if() {
    // 제어문
    // 프로세스의 흐름을 제어함

    // 프로세스?
    // 그냥 니들이 돌리고 있는 프로그램
    // 디스코드, Visual studio code, Linux Task Mgr, Glockenspiel (프로세스)
    // 죽은 프로그램이 아닙니다. 살아 있어야 해요. 작동하고 있어야 해

    // 조건문, 반복문
    // 여러분의 코드를 조금 더 "작게" 만들어 줄 거에요
    // 코드의 재사용성
    //  ex: goto

    /// if else: 질?문
    if(false) {
        printf("It is true, of course\n");
        printf("This is second command\n");
    } else if(false) {
        printf("Next Command when false\n");
        printf("Second command, of course\n");
    } else {
        printf("Wtf ");
    }
    printf("Finally\n");
    
    return 0;
}

int condition_ctrl_switch() {
    int number = 15;
    switch(number) {
        case false: {
            printf("False! 0\n");
        } break;
        default: {
            printf("True: %d\n", number);
        } break;
        case 234: printf("Unexpected\n"); break;
    } // if(number) {} else {}
}

int condition_ctrl_goto_basic() {

    if(true) {
        int b = 4;
        printf("If start\n");
        if(true) {
            goto ___else_case;    
        }
        printf("If\n");
    } else {
        int a = 3;
        printf("Else Start\n");
        ___else_case:
        printf("Else\n");
    }

    goto __lbl_skldfjlsdjflksdfklskdlfjklsdfjklklsdfkl;
    printf("This is nothing\n");

    int b;
    __lbl_skldfjlsdjflksdfklskdlfjklsdfjklklsdfkl:
    printf("Hello\n");

    while(1) {
        while(1) {
            // 무한반복
            printf("무량공처\n");
            if(true) {
                goto LoopEnd;
            }
        }
    } LoopEnd:
}

int condition_ctrl_goto_loop_example() {
    int a = 3;
    LOOP_START:

    a++;
    printf("%d\n", a);
    if(a == 45) goto LOOP_END;

    goto LOOP_START; // 무한반복
    LOOP_END: // 탈출
}

int condition_ctrl_for_while() {
    // 추상화, for, while
    while(false) {
        printf("무량공처\n");
    }

    do {
        printf("처음에 무조건 실행\n");
    } while(false);


    // for문 이해하기
    for(int index = printf("처음실행\n");index--;printf("각루프끝 %d\n", index))
    printf("루프 연산\n");

    // 
    for(uint64_t index = 1; index < 50; index <<= 1) {
        printf("%d\n", index);
    }
}

int main() {
    /// 알아서 넣으십시오 휴-먼
    return 0;
}