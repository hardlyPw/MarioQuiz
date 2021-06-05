#include <bangtal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

SceneID start, game, story[10], background_black, real_start, normal, floor_15, hidden;
ObjectID start_button, end_button, enter_castle, Kinopico, Kinopico_chance, answer[4], duck, use_chance, CheckBox, X, O, whitebox, close, next,
Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10,Q11,Q12,Q13,Q14,Q18,Q19,
one_A1, one_A2, one_A3, one_A4, two_A1, two_A2, two_A3, two_A4, two_A5, three_flower, three_box, three_write, four_A1, five_write, six_box1, six_box2, six_fakebox, six_startbutton,
seven_A1, seven_A2, seven_A3, seven_A4, seven_fail, seven_failbox, eight_write, nine_stage1, nine_stage2, nine_mario, nine_plag, arrow_left, arrow_right, arrow_left2, arrow_right2, nine_box, nine_turtle, nine_minimario,
ten_keyboard1, ten_keyboard2, ten_l, ten_i, ten_n, ten_k, ten_reset, eleven_wrtie, twelve_wrtie, thirteen_keyboard1, thirteen_keyboard2, key_h,key_e,key_r,key_o, thirteen_reset,
fourteen_box1, fourteen_box2, fourteen_box3, eighteen_write, nineteen_write,
castle, koopa, pitch,mario_luigi, memo, write,restart,//20층 
dark_mario, box, tape, paper, //15층
explain1, explain2, explain3, explain4, explain5, explain6, explain7, explain8, explain9, explain10, explain11, explain12, explain13, explain18,explain19;

TimerID timer1,timer_X, timer_whitebox, sixfloor_timer, timer_orangebox, timer_turtle, timer_koopa, timer_koopa2, timer_15F;
int conversation = 0, conversation2 = 0, conversation3=0, conversation4=1, conversation5=0, stage = 1, chance = 0, flower, incorrect=0, num_5, check_box1=0, check_box2=0, check_box3=0; //chance는 찬스 사용한 개수 판단
int mario_X=900, keyboard_check=0, keyboard_right=0, thirteen=1, random, quest;
bool cat = true, turtle = false, open_door=false, control_arrow = false, check1 = true, check2 = false, check3 = false, check4=false, check5 =  false, start2 = true, Xbox = true, box_check1, box_check2, fake;
//check1 = true로 해놓고 시작

void right() { //정답일 때 기본 설정
    showObject(explain2);
    showObject(close);
    hideObject(Kinopico_chance);
    hideObject(use_chance);
    Xbox = false;
}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {

    ObjectID object = createObject(image);

    locateObject(object, scene, x, y);

    if (shown) {
        showObject(object);
    }
    return object;
}
void show_X() {
    if (Xbox == true) {
        showObject(X);
        setTimer(timer_X, 2.0f);
        startTimer(timer_X);
    }

}
void show_whitebox() {
    showObject(whitebox);
    setTimer(timer_whitebox,2.0f);
    startTimer(timer_whitebox);
}
void make_scene() {
    for (int a = 0; a < 10; a++) {
        char path[50];
        sprintf_s(path, "%d.png", a + 1);
        story[a] = createScene("", path);
    }
}

void stair_1() {
    showObject(Q1);
    showObject(duck);
    showObject(one_A1);
    showObject(one_A2);
    showObject(one_A3);
    showObject(one_A4);
    showMessage("1층입니다");
    show_whitebox();
}

void stair_2() {
    showMessage("2층입니다");
    showObject(Q2);
    showObject(two_A1);
    showObject(two_A2);
    showObject(two_A3);
    showObject(two_A4);

}

void stair_3() {
    showMessage("3층입니다");
    showObject(Q3);
    showObject(three_flower);
    showObject(three_box);
    showObject(three_write);
}

void stair_3_2() {
    showObject(explain3);
    showObject(close);
    hideObject(Kinopico_chance);
    hideObject(use_chance);
    showObject(next);
}

void stair_4() {
    showMessage("4층입니다");
    showObject(Q4);
    showObject(four_A1);

}
void stair_5() {
    showMessage("5층입니다");
    showObject(Q5);
    showObject(five_write);
}
void stair_5_2() {
    showObject(explain5);
    showObject(close);
    hideObject(Kinopico_chance);
    hideObject(use_chance);
    showObject(next);

}
void stair_6() {
    showMessage("6층입니다");
    showObject(six_box1);
    showObject(six_box2);
    showObject(six_startbutton);
    showObject(Q6);
}
void stair_7() {
    showMessage("7층입니다");
    showObject(Q7);
    showObject(seven_A1);
    showObject(seven_A2);
    showObject(seven_A3);
    showObject(seven_A4);
}
void stair_8() {
    showMessage("8층입니다");
    showObject(Q8);
    showObject(eight_write);
}
void stair_9() {
    showMessage("9층입니다");
    showObject(nine_stage1);
    showObject(nine_stage2);
    showObject(nine_plag);
    showObject(arrow_left);
    showObject(arrow_right);
    showObject(nine_box);
    showObject(nine_mario);
}
void stair_10() {
    showMessage("10층입니다");
    showObject(ten_keyboard1);
    showObject(ten_keyboard2);
    showObject(Q10);
    showObject(ten_i);
    showObject(ten_k);
    showObject(ten_n);
    showObject(ten_l);
    showObject(ten_reset);
}
void stair_11() {
    showObject(eleven_wrtie);
    showObject(Q11);
}
void stair_12() {
    showMessage("12층입니다");
    showObject(twelve_wrtie);
    showObject(Q12);
}
void stair_13() {
    showMessage("13층입니다");
    showObject(Q13);
    showObject(thirteen_keyboard1);
    showObject(thirteen_keyboard2);
    showObject(key_h);
    showObject(key_e);
    showObject(key_r);
    showObject(key_o);
    showObject(thirteen_reset);
}
void stair_14() {
    showMessage("14층입니다");
    showObject(Q14);
    random = rand() % 3;
    if (random == 0) {
        locateObject(fourteen_box1, game, 800, 300);
        locateObject(fourteen_box2, game, 400, 300);
    }
    else if (random == 1) {
        locateObject(fourteen_box1, game, 1230, 300);
        locateObject(fourteen_box3, game, 400, 300);
    }
    else if (random == 2) {
        locateObject(fourteen_box2, game, 1230, 300);
        locateObject(fourteen_box3, game, 800, 300);
    }
    showObject(fourteen_box1);
    showObject(fourteen_box2);
    showObject(fourteen_box3);
}
void stair_18() {
    showMessage("18층입니다");
    showObject(Q18);
    showObject(eighteen_write);
}
void stair_19() {
    showMessage("19층입니다");
    showObject(Q19);
    showObject(nineteen_write);
}

void stair_20() {
    showObject(koopa);
    showObject(whitebox);
    showObject(castle);
    setTimer(timer_koopa, 0.1f);
    startTimer(timer_koopa);
    check3 = true;
}


void hide_1() {
    hideObject(Q1);
    hideObject(duck);
    hideObject(one_A1);
    hideObject(one_A2);
    hideObject(one_A3);
    hideObject(one_A4);
}

void hide_2() {
    hideObject(Q2);
    hideObject(two_A1);
    hideObject(two_A2);
    hideObject(two_A3);
    hideObject(two_A4);
    hideObject(two_A5);
}

void hide_3() {
    hideObject(Q3);
    hideObject(three_flower);
    hideObject(three_box);
    hideObject(three_write);
}

void hide_4() {
    hideObject(Q4);
    hideObject(four_A1);
}
void hide_5() {
    hideObject(Q5);
    hideObject(five_write);
}
void hide_6() {
    hideObject(six_box1);
    hideObject(six_box2);
    hideObject(six_startbutton);
    hideObject(Q6);
}
void hide_7() {
    hideObject(Q7);
    hideObject(seven_A1);
    hideObject(seven_A2);
    hideObject(seven_A3);
    hideObject(seven_A4);
}
void hide_8() {
    hideObject(Q8);
    hideObject(eight_write);
}
void hide_9() {
    hideObject(nine_stage1);
    hideObject(nine_stage2);
    hideObject(nine_minimario);
    hideObject(nine_plag);
}
void hide_10() {
    hideObject(Q10);
    hideObject(ten_reset);
}   
void hide_11() {
    hideObject(Q11);
    hideObject(eleven_wrtie);
}
void hide_12() {
    hideObject(Q12);
}
void hide_13() {
    hideObject(Q13);
    hideObject(thirteen_reset);
}
void hide_14() {
    hideObject(Q14);
    hideObject(fourteen_box1);
    hideObject(fourteen_box2);
    hideObject(fourteen_box3);
}
void hide_18() {
    hideObject(Q18);
    hideObject(eighteen_write);
}
void hide_19() {
    hideObject(Q19);
    hideObject(nineteen_write);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == start_button) {
        setTimer(timer1, 0.1f);
        startTimer(timer1);
    }
    else if (object == end_button) endGame();
    else if (object == enter_castle) {
        if (start2 == true) {
            showObject(Kinopico);
            setTimer(timer1, 0.1f);
            startTimer(timer1);
            check2 = true;
            hideObject(enter_castle);
        }
        else {
            enterScene(game);
            stair_1();
        }

    }
    else if (object == close) {
        hideObject(close);
        hideObject(explain1);
        hideObject(explain2);
        hideObject(explain3);
        hideObject(explain4);
        hideObject(explain5);
        hideObject(explain6);
        hideObject(explain7);
        hideObject(explain8);
        hideObject(explain9);
        hideObject(explain10);
        hideObject(explain11);
        hideObject(explain12);
        hideObject(explain13);
        hideObject(explain18);
        hideObject(explain19);
        showObject(next);
        control_arrow = true;
    }
    else if (object == Kinopico_chance) {
        if (cat == true) {
            show_whitebox();
            if (stage == 1) showMessage("어라..다른 동물이 있는 것 같은데요..?!");
            if (stage == 2) showMessage("\"문제 위의\" 마리오. .라는데요?  ");
            if (stage == 3) showMessage("꽃이 없어야 꽃 뒤의 숫자를 볼 수 있지 않을까요?");
            if (stage == 4) showMessage("제 눈에는 검정색이 가장 어둡게 보이는데.. 저만그런가요?");
            if (stage == 5) showMessage("죄송해요.. 이건 저도 잘 모르겠네요..");
            if (stage == 6) showMessage("클릭하는 중간에 초록색이 아닌 무언가가 있지 않았나요 . .?");
            if (stage == 7) showMessage("아. . . 아까전에 봤던것 같은데.. 기억이 잘...");
            if (stage == 8) showMessage("1이 10이면. . 10은. .?");
            if (stage == 10) showMessage("저 상자들 안에 무슨 알파벳을 넣어야할까요. . 그리고 왜 색깔이 있을까요?");
            if (stage == 11) showMessage("앗. . 저도 이전 문제에 정신이 팔려서 몇층인지 까먹었네요. . ");
            if (stage == 12) showMessage("헤이호는 하나, 부끄부끄는 0");
            if (stage == 13) {
                switch (thirteen) {
                case 1:
                    showMessage("누가");
                    thirteen++;
                    chance++;
                    break;
                case 2:
                    showMessage("언제");
                    thirteen++;
                    chance++;
                    break;
                case 3:
                    showMessage("어디서");
                    thirteen++;
                    chance++;
                    break;
                case 4:
                    showMessage("무엇을");
                    thirteen++;
                    chance++;
                    break;
                case 5:
                    showMessage("어떻게");
                    thirteen++;
                    chance++;
                    break;
                case 6:
                    showMessage("왜");
                    thirteen++;
                    chance++;
                    break;
                default:
                    showMessage("힌트 끝");
                }
            }
            if (stage == 14) {
                if(open_door==true) enterScene(floor_15);               
            }
            if (stage == 18) showMessage("무지개 색 순서대로 선을 그어보세요!");
            if (stage == 19) showMessage("시계");
            chance++;
        }
    }
    else if (object == answer[0]) {
        conversation2 = 6;
        setTimer(timer1, 0.1f);
        startTimer(timer1);
    }
    else if (object == answer[1]) {
        conversation2 = 7;
        setTimer(timer1, 0.1f);
        startTimer(timer1);
    }
    else if (object == answer[2]) {
        conversation2 = 8;
        setTimer(timer1, 0.1f);
        startTimer(timer1);
    }
    else if (object == answer[3]) {
        conversation2 = 9;
        setTimer(timer1, 0.1f);
        startTimer(timer1);
    }
    else if (object == one_A1) {
        show_X();
    }
    else if (object == one_A2) {
        show_X();
    }
    else if (object == one_A3) {
        if (Xbox == true) {
            showObject(explain1);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            Xbox = false;
        }
    }
    else if (object == one_A4) {
        show_X();
    }
    else if (object == two_A1) {

        if (action == MouseAction::MOUSE_DRAG_UP) {
            hideObject(two_A1);
            showObject(two_A5);
        }
        else {
            show_X();
        }
    }
    else if (object == two_A2) {
        show_X();
    }
    else if (object == two_A3) {
        show_X();
    }
    else if (object == two_A4) {
        show_X();
    }
    else if (object == two_A5) {
        if (Xbox == true) {
            showObject(explain2);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            Xbox = false;
        }
    }
    else if (object == three_flower) {
        if (action == MouseAction::MOUSE_DRAG_UP) {
            locateObject(three_flower, game, 830, 700);
        }
    }
    else if (object == three_write) {
        scanf_s("%d", &flower);
        if (flower == 3254) {
            stair_3_2();
            hide_3();
        }
        else {
            showMessage("틀렸습니다!");
            show_X();
        }
    }
    else if (object == four_A1) {
        show_X();
        incorrect++;
    }
    else if (object == Q4) {
        showObject(explain4);
        showObject(close);
        hideObject(Kinopico_chance);
        hideObject(use_chance);
        Xbox = false;
    }
    else if (object == five_write) {
        scanf_s("%d", &num_5);
        if (num_5 == incorrect) {
            stair_5_2();
            hide_5();
        }
        else {
            showMessage("틀렸습니다!");
            show_X();
        }
    }
    else if (object == six_box1) {
        if (box_check1 == true) {
            check_box1++;
            if (check_box1 == 10) {
                box_check2 = true;
            }
            else if (check_box1 > 10) box_check2 = false;
        }

    }
    else if (object == six_box2) {
        if (box_check2 == true) {
            check_box2++;
        }
        if (check_box2 == 5) {
            showObject(six_fakebox);
            setTimer(timer_orangebox, 1.0f);
            startTimer(timer_orangebox);
        }
        if (check_box2 == 9) {
            if (fake == 1) {
                show_X();
                stopTimer(sixfloor_timer);
                check_box1 = 0;
                check_box2 = 0;
                box_check1 = false;
                box_check2 = false;
                fake = 0;
            }
        }
        if (check_box2 == 10) {
                showObject(explain6);
                showObject(close);
                hideObject(Kinopico_chance);
                hideObject(use_chance);
                Xbox = false;
                hideObject(six_startbutton);
                hideTimer();
        }
    }
    else if (object == six_startbutton) {
        box_check1 = true;
        setTimer(sixfloor_timer, 10.0f);
        startTimer(sixfloor_timer);
        showTimer(sixfloor_timer);
        check_box1 = 0;
        check_box2 = 0;
        box_check2 = false;
        fake = 0;
    }
    else if (object == six_fakebox) {
        fake = 1;
        hideObject(six_fakebox);
    }
    else if (object == seven_A1) {
        show_X();
        showObject(seven_fail);
        showObject(seven_failbox);
        cat = false;
        check_box3 = 0;
    }
    else if (object == seven_A2) {
        show_X();
        showObject(seven_fail);
        showObject(seven_failbox);
        cat = false;
        check_box3 = 0;

    }
    else if (object == seven_A3) {
        showObject(explain7);
        showObject(close);
        hideObject(Kinopico_chance);
        hideObject(use_chance);
        Xbox = false;

    }
    else if (object == seven_A4) {
        show_X();
        showObject(seven_fail);
        showObject(seven_failbox);
        cat = false;
        check_box3 = 0;
    }
    else if (object == seven_failbox) {
        if (check_box3 == 29) {
            hideObject(seven_failbox);
            hideObject(seven_fail);
            check_box3 == 0;
        }
        check_box3++;
    }
    else if (object == eight_write) {
        int a, b = 1;
        scanf("%d", &a);
        if (a == b) {
            showObject(explain8);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            Xbox = false;
        }
        else {
            showMessage("틀렸습니다!");
            show_X();
        }
    }
    else if (object == arrow_left) {
        if (mario_X > 300) {
            mario_X = mario_X - 100;
            locateObject(nine_mario, game, mario_X, 230);
        }
        if (mario_X == 700) {
            if (turtle == true) {
                hideObject(nine_mario);
                hideObject(nine_turtle);
                hideObject(arrow_left);
                hideObject(arrow_right);
                showObject(arrow_left2);
                showObject(arrow_right2);
                showObject(nine_minimario);
            }
        }
    }
    else if (object == arrow_right) {
        if (mario_X < 1200) {
            mario_X = mario_X + 100;
            locateObject(nine_mario, game, mario_X, 230);
        }
        if (mario_X == 700) {
            if (turtle == true) {
                hideObject(nine_mario);
                hideObject(nine_turtle);
                hideObject(arrow_left);
                hideObject(arrow_right);
                showObject(arrow_left2);
                showObject(arrow_right2);
                showObject(nine_minimario);
            }
        }

    }
    else if (object == arrow_left2) {
        if (mario_X > 300) {
            mario_X = mario_X - 100;
            locateObject(nine_minimario, game, mario_X, 230);

        }
    }
    else if (object == arrow_right2) {
        mario_X = mario_X + 100;
        locateObject(nine_minimario, game, mario_X, 230);
        if (mario_X == 1400) {
            hideObject(arrow_left2);
            hideObject(arrow_right2);
            showObject(explain9);
            showObject(close);
        }
    }
    else if (object == nine_box) {
        if (mario_X != 700) {
            showObject(nine_turtle);
            setTimer(timer_turtle, 0.5f);
            startTimer(timer_turtle);
            hideObject(nine_box);
            turtle = true;
        }
    }
    else if (object == ten_keyboard1 or object == ten_keyboard2) {
        keyboard_right = 0;
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            show_X();
        }
    }
    else if (object == ten_l) {
        keyboard_right = 1;
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
    }
    else if (object == ten_i) {
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
        if (keyboard_right == 1) {
            keyboard_right = 2;
        }

    }
    else if (object == ten_n) {
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
        if (keyboard_right == 2) {
            keyboard_right = 3;
        }
    }
    else if (object == ten_k) {
        keyboard_check++;
        if (keyboard_right == 3) {
            keyboard_right = 0;
            keyboard_check = 0;
            showObject(explain10);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            hideObject(ten_keyboard1);
            hideObject(ten_keyboard2);
            hideObject(ten_i);
            hideObject(ten_l);
            hideObject(ten_n);
            hideObject(ten_k);
            Xbox = false;
        }
        else if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }

    }
    else if (object == ten_reset) {
        keyboard_check = 0;
        keyboard_right = 0;
        show_X();
    }
    else if (object == eleven_wrtie) {
        int a = 11, b;
        scanf("%d", &b);
        if (a == b) {
            showObject(explain11);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            Xbox = false;
        }
        else if (b == 15) {
            open_door = true;
            showMessage("열렸습니다");
        }
        else {
            show_X();
            showMessage("틀렸습니다!");
        }
    }
    else if (object == twelve_wrtie) {
        int a = 13, b;
        scanf("%d", &b);
        if (a == b) {
            showObject(explain12);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            hideObject(twelve_wrtie);
            Xbox = false;
        }
        else {
            show_X();
            showMessage("틀렸습니다!");
        }
    }
    else if (object == thirteen_keyboard1 or object == thirteen_keyboard2) {
        keyboard_right = 0;
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            show_X();
        }
    }
    else if (object == key_h) {
        keyboard_right = 1;
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
    }
    else if (object == key_e) {
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
        if (keyboard_right == 1) {
            keyboard_right = 2;
        }
    }
    else if (object == key_r) {
        keyboard_check++;
        if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
        if (keyboard_right == 2) {
            keyboard_right = 3;
        }
    }
    else if (object == key_o) {
        keyboard_check++;
        if (keyboard_right == 3) {
            keyboard_right = 0;
            keyboard_check = 0;
            showObject(explain13);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            hideObject(thirteen_keyboard1);
            hideObject(thirteen_keyboard2);
            hideObject(key_h);
            hideObject(key_e);
            hideObject(key_r);
            hideObject(key_o);
            Xbox = false;
        }
        else if (keyboard_check == 4) {
            keyboard_check = 0;
            keyboard_right = 0;
            show_X();
        }
    }
    else if (object == thirteen_reset) {
        keyboard_check = 0;
        keyboard_right = 0;
        show_X();
    }

    else if (object == fourteen_box1) {
        hide_14();
        stair_18();
        stage = 18;
    }
    else if (object == fourteen_box2) {
        hide_14();
        stair_18();
        stage = 18;
    }
    else if (object == fourteen_box3) {
        hide_14();
        stair_19();
        stage = 19;
    }
    if (object == eighteen_write) {
        int aa = 3659, bb;
        scanf_s("%d", &bb);
        if (aa == bb) {
            showObject(explain18);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            hideObject(eighteen_write);
            Xbox = false;
        }
        else {
            show_X();
            showMessage("틀렸습니다!");
        }
    }
    if (object == nineteen_write) {
        int aa = 9, bb;
        scanf_s("%d", &bb);
        if (aa == bb) {
            showObject(explain19);
            showObject(close);
            hideObject(Kinopico_chance);
            hideObject(use_chance);
            hideObject(nineteen_write);
            Xbox = false;
        }
        else {
            show_X();
            showMessage("틀렸습니다!");
        }
    }
    else if (object == write) {
        int a;
        check4 = true;
        scanf("%d", &a);
        if (a == chance) {
            setTimer(timer_koopa2, 0.5f);
            startTimer(timer_koopa2);
            hideObject(write);
        }
        else {
            conversation4 = 100;
            setTimer(timer_koopa2, 0.5f);
            startTimer(timer_koopa2);
            hideObject(write); 
        }
    }

    else if (object == next) {
        cat = true;
        if (control_arrow == true)
        {
            if (stage == 1) hide_1();
            else if (stage == 2) hide_2();
            else if (stage == 3) hide_3();
            else if (stage == 4) hide_4();
            else if (stage == 5) hide_5();
            else if (stage == 6) hide_6();
            else if (stage == 7) hide_7();
            else if (stage == 8) hide_8();
            else if (stage == 9) hide_9();
            else if (stage == 10) hide_10();
            else if (stage == 11) hide_11();
            else if (stage == 12) hide_12();
            else if (stage == 13) hide_13();
            else if (stage == 14) hide_14();
            else if (stage == 18) hide_18();
            else if (stage == 19) hide_19();
            stage++;
            Xbox = true;
            showObject(Kinopico_chance);
            if (stage == 1) stair_1();
            else if (stage == 2) stair_2();
            else if (stage == 3) stair_3();
            else if (stage == 4) stair_4();
            else if (stage == 5) stair_5();
            else if (stage == 6) stair_6();
            else if (stage == 7) stair_7();
            else if (stage == 8) stair_8();
            else if (stage == 9) stair_9();
            else if (stage == 10) stair_10();
            else if (stage == 11) stair_11();
            else if (stage == 12) stair_12();
            else if (stage == 13) stair_13();
            else if (stage == 14) stair_14();
            else if (stage == 18) stair_18();
            else if (stage == 19) stair_19();
            else if (stage == 20) stair_20();
            hideObject(next);
            control_arrow = false;
        }
    }
    else if (object == box) {
        check5 = true;
        setTimer(timer_15F, 0.5f);
        startTimer(timer_15F);
    }
}


void timerCallback(TimerID timer) {
    if (check1 == true) {
        if (timer == timer1) {
            switch (conversation) {
            case 0:
                showMessage("오늘도 평화로운 피치 왕국.");
                enterScene(story[0]);
                break;
            case 1:
                showMessage("하지만 오늘도 어김없이 . . .");
                enterScene(story[1]);
                break;
            case 2:
                showMessage("피치성을 쳐들어오는 쿠파.");
                enterScene(story[2]);
                break;
            case 3:
                showMessage("마리오&루이지: 이 손은 뭐지..???");
                enterScene(story[3]);
                break;
            case 4:
                showMessage("키노피오&키노피코: 어어..??");
                enterScene(story[4]);
                break;
            case 5:
                showMessage("마리오&루이지: 으악!");
                enterScene(story[5]);
                break;
            case 6:
                showMessage("피치: 내 친구들이..!");
                enterScene(story[6]);
                break;
            case 7:
                showMessage("쿠파: 하하하! 잘가라!");
                enterScene(story[7]);
                break;
            case 8:
                showMessage("그렇게 날아가버린 마리오와 친구들 . . .");
                enterScene(story[8]);
                break;
            case 9:
                showMessage("과연 그들은 피치공주를 구할 수 있을까?!");
                enterScene(story[9]);
                break;
            }


        }
        if (conversation < 10) {
            conversation++;
            setTimer(timer1, 3.5f);
            startTimer(timer1);
        }
        else {
            enterScene(real_start);
            check1 = false;
        }
    }
    else if (check2 == true) {
        switch (conversation2) {
        case 0:
            showMessage("???: 안녕하세요!");
            break;
        case 1:
            showMessage("???: 저는 키노피코라고 해요!");
            break;
        case 2:
            showMessage("키노피코: 피치 공주님을 구출하러 가는데 도움이 되고 싶어서. . .!");
            break;
        case 3:
            showMessage("키노피코: 만약 퀴즈를 풀다가 모르겠으면 오른쪽 상단에 있는 저를 눌러주세요!");
            break;
        case 4:
            showMessage("키노피코: 제가 최대한 아는 선에서 답변해드릴게요!");
            break;
        case 5:
            showMessage("키노피코: 혹시 더 궁금한거 있으세요??");
            for (int a = 0; a <= 3; a++) {
                showObject(answer[a]);
            }
            break;
        case 6:
            showMessage("키노피코: 제 생각으로는 쿠파가 공주님을 20층 꼭대기에 가둬두었을 것 같아요...");
            break;
        case 7:
            showMessage("키노피코: 각 층에 있는 문제를 풀면 다음 층으로 올라갈 수 있어요!");
            break;
        case 8:
            showMessage("키노피코: 나 역시 네녀석 따위는 필요없다.");
            break;
        case 9:
            showMessage("키노피코: 그럼 출발해 보도록 할까요!");
            showObject(enter_castle);
            for (int i = 0; i < 4; i++) {
                hideObject(answer[i]);
            }
            check2 = false;
            start2 = false;
        }
        if (conversation2 <= 4) {
            conversation2++;
            setTimer(timer1, 3.5f);
            startTimer(timer1);
        }
        
    }
    if (check3 == true) {
        if (timer == timer_koopa) {
            switch (conversation3) {
            case 0:
                showMessage("쿠파: 너. . 결국 여기까지 왔구나.");
                break;
            case 1:
                showMessage("나: 피치공주는 어딨지!?");
                break;
            case 2:
                showMessage("쿠파: 이 곳 꼭대기에 가두어두었지.");
                break;
            case 3:
                showMessage("쿠파: 만약 내가 내는 마지막 문제를 맞춘다면 공주를 풀어주마.");
                break;
            case 4:
                showMessage("쿠파: 하지만 맞추지 못할경우. . 넌 이곳에서 튕겨져 나간다.");
                break;
            case 5:
                showMessage("쿠파: 문제에 대한 답은 콘솔창에 입력하면 된다.");
                break;
            case 6:
                showMessage("나: 문제를 맞추기만 하면 공주를 풀어주는 거지?!");
                break;
            case 7:
                showMessage("쿠파: 물론이다. 그럼 문제를 내지.");
                break;
            case 8:
                showMessage("쿠파: 탑을 오르면서 힌트를 확인한 횟수는?");
                break;
            case 9:
                showObject(write);
                check3 = false;
                break;            
            }
            if (conversation3<=9) {
                conversation3++;
                setTimer(timer_koopa, 4.0f);
                startTimer(timer_koopa);
            }      
        }
    }
    if (check4 == true) {
        if (timer == timer_koopa2) {
            switch (conversation4) {
            case 1:
                showMessage("쿠파: . . .");
                break;
            case 2:
                showMessage("쿠파: 이럴수가! 이 문제를 맞추다니. . !");
                break;
            case 3:
                showMessage("나: 자, 이제 피치를 풀어주시지!");
                break;
            case 4:
                showMessage("쿠파: 아니, 그럴 수 없다. 차라리 이 성을 부수겠어!");
                break;
            case 5:
                showMessage("마리오&루이지: 멈춰!");
                showObject(mario_luigi);
                break;
            case 6:
                showMessage("쿠파: 아니, 너희들은 분명 내가 날려버렸을 텐데. . !");
                break;
            case 7:
                showMessage("마리오&루이지: 이미 너의 성은 포위 됬다! 항복해!");
                break;
            case 8:
                showMessage("쿠파: 이런. . 어쩔 수 없나. . !");
                break;
            case 9:
                showMessage("마리오&루이지: 공주님! 괜찮으세요??");
                showObject(pitch);
                break;
            case 10:
                showMessage("피치: 응. . 난 괜찮아! ");
                break;
            case 11:
                showMessage("쿠파: 자, 피치를 풀어줬으니 됬지?");
                break;
            case 12:
                showMessage("마리오: 아니? 쿠파 너는 감옥으로 가야지.");
                break;
            case 13:
                showMessage("쿠파: 마리오 네녀석이. .");
                break;
            case 14:
                showMessage("쿠파: 좋다, 순순히 따라가도록 하지. 하지만 내 부하들은 보내줘.");
                break;
            case 15:
                showMessage("마리오: 어림도 없지. 너와 네 부하들은 평생 감옥에서 살아야 할거야.");
                break;
            case 16:
                showMessage("쿠파: 마리오. . !");
                break;
            case 17:
                hideObject(koopa);
                hideObject(mario_luigi);
                showMessage("피치: 휴, 드디어 끝났군요. 구해주셔서 정말 고마워요!");
                break;
            case 18:
                showMessage("피치: 저를 몇 번이나 납치했었는데, 쿠파를 이제서야 잡는군요.");
                break;
            case 19:
                showMessage("피치: 성에 돌아가면 성대한 파티를 열도록 할게요.");
                break;
            case 20:
                showMessage("나: 그래, 너도 갇혀있느라 힘들었겠다.");
                break;
            case 21:
                showMessage("피치: 그럼 성으로 돌아가도록하죠!");
                break;
            case 22:
                hideObject(pitch);
                showMessage("휴. . 드디어 끝난건가. . ");
                break;
            case 23:
                showMessage("어.. 이 쪽지는뭐지?");
                break;
            case 24:
                showObject(memo);
                showMessage("아까 쿠파가 흘리고 간 것 같은데. . ?");
                break;
            case 25:
                showMessage("15F. .  무슨 뜻이지?");
                break;
            case 26:
                showMessage("피치: 왜 안오시고 계세요~");
                showObject(pitch);
                break;
            case 27:
                showMessage("나: 이제 갈게!");
                break;
            case 28:
                hideObject(memo);
                hideObject(pitch);
                showMessage("나: 이 쪽지는 가지고 가볼까. . ");
                break;
            case 29:
                enterScene(normal);
                check3 = false;
                break;
            case 100:
                showMessage("쿠파: 하하! 틀렸다, 잘가라!");
                break;
            case 101:
                endGame();
            }
            conversation4++;
            setTimer(timer_koopa2, 4.0f);
            startTimer(timer_koopa2);
        }
    }
    if (check5 == true) {
        if (timer == timer_15F) {
            switch (conversation5) {
            case 0:
                showMessage("이 상자는 뭐지..?");
                break;
            case 1:
                showMessage("상자 옆에 쪽지가 놓여져 있다.");
                showObject(paper);
                break;
            case 2:
                showMessage("\"이 모든 사건의 시작\" ");
                break;
            case 3:
                showMessage("이게 무슨소리지. . ? 상자를 열어볼까.");
                break;
            case 4:
                showMessage("이 안엔 테이프가 있구나.");
                hideObject(box);
                showObject(tape);
                break;
            case 5:
                showMessage("한 번 틀어보도록 하자.");
                break;
            case 6:
                showMessage("(테이프가 실행되며 쿠파의 목소리가 나온다.)");
                break;
            case 7:
                showMessage("쿠파: 이번이 정말 마지막이겠지?");
                break;
            case 8:
                showMessage("???: 그래, 피치를 납치하는 일도 이번이 마지막이야.");
                break;
            case 9:
                showMessage("???: 만약 이번일이 잘 풀린다면 가두어놨던 쿠파 주니어도 풀어주지.");
                break;
            case 10:
                showMessage("쿠파: 그게 정말이겠지?");
                break;
            case 11:
                showMessage("쿠파: 그 말, 꼭 지켜야 할거다. 마리오.");
                break;
            case 12:
                showMessage("(뭐야.. 마리오라고!?)");
                break;
            case 13:
                showMessage("이 일을 어서 모두에게 알려야해. . !");
                break;
            case 14:
                showMessage("마리오: 이런 이런..");
                break;
            case 15:
                showMessage("마리오: 전부 다. . 들으셨나 보군요.");
            case 16:
                hideObject(paper);
                hideObject(tape);
                showObject(dark_mario);
                showMessage("마리오: 쿠파가 녹음을 남겨뒀을 줄은. . ");
                break;
            case 17:
                showMessage("마리오: 하지만, 뭐 상관없습니다. 이미 피치 공주는 제가 납치했으니까요.");
                break;
            case 18:
                showMessage("뭐라고!?");
                break;
            case 19:
                showMessage("마리오: 당신이 쿠파를 물리치고 성으로 돌아가면 다시 납치할 계획이었으나. . ");
                break;
            case 20:
                showMessage("마리오: 일이 이렇게 됬으니 어쩔 수 없죠. 바로 데려가는 수밖에.");
                break;
            case 21:
                showMessage("마리오: 피치를 되찾고 싶다면 마리오 성까지 쫓아와 보시죠!");
                break;
            case 22:
                hideObject(dark_mario);
                showMessage("마리오. . . 네 뜻대로는 안될거다!");
                break;
            case 23:
                showMessage("반드시 피치를 되찾겠어!");
                break;
            case 24:
                enterScene(hidden);
            }
            conversation5++;
            setTimer(timer_15F, 4.0f);
            startTimer(timer_15F);
        }
    }


    if (timer == timer_X) {
        hideObject(X);
    }
    if (timer == timer_whitebox) {
        hideObject(whitebox);
    }
    if (timer == sixfloor_timer) {
        show_X();
        check_box1 = 0;
        check_box2 = 0;
        box_check1 = false;
        box_check2 = false;
        fake = 0;
    }
    if (timer == timer_orangebox) {
        hideObject(six_fakebox);
    }
    if (timer == timer_turtle) {
        locateObject(nine_turtle, game, 700, 240);
    }
}



int main()
{
    srand((unsigned int)time(NULL));
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setMouseCallback(mouseCallback);
    setTimerCallback(timerCallback);


    hidden = createScene("히든엔딩", "hidden.jpg");
    floor_15 = createScene("15층", "15층.png");
    start=createScene("시작 화면", "마리오퀴즈.png");
    game = createScene("", "게임배경1.png");
    background_black = createScene("", "검은배경.png");
    real_start = createScene("마리오퀴즈", "성.jpg");
    normal = createScene("노말엔딩","노말엔딩.jpg");

    start_button = createObject("start.png", start, 300, 150, true);
    end_button = createObject("end.png", start, 700, 150, true);
    enter_castle = createObject("성입장.png", real_start, 500, 50, true);
    Kinopico = createObject("키노피코.png", real_start, 475, 200, false);
    Kinopico_chance = createObject("키노피코찬스.png", game, 1400, 700, true);
    use_chance = createObject("use_chance.png", game, 1350, 600, true);
    CheckBox = createObject("CheckBox.png", game, 300, 800, true);
    X = createObject("X.png", game, 310, 670, false);
    O = createObject("O.png", game, 270, 660, false);
    answer[0] = createObject("대답1.png", real_start, 100, 100, false);
    answer[1] = createObject("대답2.png", real_start, 100, 500, false);
    answer[2] = createObject("대답3.png", real_start, 700, 500, false);
    answer[3] = createObject("대답4.png", real_start, 700, 100, false);
    

    //1층
    Q1 = createObject("Q1.png", game, 700, 780, false);
    one_A1 = createObject("one_A1.png", game, 300, 200, false);
    one_A2 = createObject("one_A2.png", game, 620, 200, false);
    one_A3 = createObject("one_A3.png", game, 940, 200, false);
    one_A4 = createObject("one_A4.png", game, 1260, 200, false);

    duck = createObject("duck.png", game, 600, 350, false);

    //2층
    Q2 = createObject("Q2.png", game, 650, 780, false);
    two_A1 = createObject("마리오.png", game, 600, 450, false);
    two_A2 = createObject("루이지.png", game, 980, 430, false);
    two_A3 = createObject("요시.png", game, 1000, 200, false);
    two_A4 = createObject("피노키오.png", game, 600, 200, false);
    two_A5 = createObject("마리오.png", game, 600, 650, false);

    //3층
    Q3 = createObject("Q3.png", game, 350, 450, false);
    three_box = createObject("three_box.png", game, 330, 200, false);
    three_flower = createObject("꽃.jpg", game, 830, 220, false);
    three_write = createObject("입력.png", game, 830, 600, false);
    scaleObject(three_flower, 0.9f);

    //4층
    Q4 = createObject("Q4.png", game, 700, 750, false);
    four_A1 = createObject("four_A1.png", game, 700, 300, false);

    //5층
    Q5= createObject("Q5.png", game, 500, 450, false);
    five_write = createObject("입력.png", game, 830, 200, false);
    
    //6층
    Q6 = createObject("Q6.png", game, 600, 650, false);
    six_box1 = createObject("주황상자.png", game, 500, 400, false);
    six_box2 = createObject("초록상자.png", game, 1000, 400, false);
    six_fakebox = createObject("주황상자.png", game, 1000, 400, false);
    six_startbutton = createObject("시작.png", game, 860, 250, false);

    //7층
    Q7 = createObject("Q7.png", game, 600, 700, false);
    seven_A1 = createObject("seven_A1.png", game, 500, 200, false);
    seven_A2 = createObject("seven_A2.png", game, 1000, 280, false);
    seven_A3 = createObject("seven_A3.png", game, 1000, 470, false);
    seven_A4 = createObject("seven_A4.png", game, 1000, 235, false);
    seven_fail = createObject("벌칙.png", game, 500, 200, false);
    seven_failbox = createObject("초록상자.png", game, 770, 350, false);

    //8층
    Q8 = createObject("Q8.png", game, 650, 500, false);
    eight_write = createObject("입력.png", game, 800, 300, false);
    
    //9층
    nine_stage1 = createObject("9단계배경.png", game, 0, 0, false);
    Q9 = createObject("Q9.png", game, 650, 500, false);   
    nine_stage2 = createObject("nine_stage.png", game, 310, 170, false);
    nine_plag = createObject("plag.png", game, 1400, 250, false);
    arrow_left = createObject("arrow_left.png", game, 300, 175, false);
    arrow_right = createObject("arrow_right.png", game, 500, 175, false);
    arrow_left2 = createObject("arrow_left.png", game, 300, 175, false);
    arrow_right2 = createObject("arrow_right.png", game, 500, 175, false);
    nine_box = createObject("랜덤박스.png", game, 720, 400, false);
    nine_turtle = createObject("거북이.png", game, 700, 315, false);
    nine_mario = createObject("게임마리오.png", game, mario_X, 230, false);
    nine_minimario = createObject("미니마리오.png", game, 700, 230, false);

    //10층
    Q10 = createObject("Q10.png", game, 650, 370, false);
    ten_keyboard1 = createObject("keyboard1.png", game, 350, 200, false);
    ten_keyboard2 = createObject("keyboard2.png", game, 1250, 280, false);
    ten_i = createObject("i.png", game, 355, 360, false);
    ten_k = createObject("k.png", game, 493, 360, false);
    ten_l = createObject("l.png", game, 563, 360, false);
    ten_n = createObject("n.png", game, 1253, 365, false);
    ten_reset= createObject("리셋.png", game, 850, 205, false);

    //11층
    Q11 = createObject("Q11.png", game, 600, 500, false);
    eleven_wrtie= createObject("입력.png", game, 800, 200, false);

    //12층
    Q12 = createObject("Q12.png", game, 400, 200, false);
    twelve_wrtie = createObject("입력.png", game, 1200, 400, false);

    //13층
    Q13 = createObject("Q13.png", game, 670, 200, false);
    thirteen_keyboard1 = createObject("keyboard3.png", game, 400, 200, false);
    thirteen_keyboard2 = createObject("keyboard4.png", game, 1200, 250, false);
    key_h = createObject("key_h.png", game, 1390, 400, false);
    key_e = createObject("e.png", game, 1207, 400, false);
    key_r = createObject("r.png", game, 460, 268, false);
    key_o = createObject("key_o.png", game, 1329, 330, false);
    thirteen_reset = createObject("리셋.png", game, 800, 700, false);

    //14층
    Q14 = createObject("Q14.png", game, 750, 700, false);
    fourteen_box1 = createObject("randombox.png", game, 400, 300, false);
    fourteen_box2 = createObject("randombox.png", game, 800, 300, false);
    fourteen_box3 = createObject("randombox.png", game, 1230, 300, false);

    //18층
    Q18 = createObject("Q18.png", game, 550, 400, false);
    eighteen_write = createObject("입력.png", game, 800, 200, false);

    //19층
    Q19 = createObject("Q19.png", game, 550, 200, false);
    nineteen_write = createObject("입력.png", game, 1000, 400, false);

    //20층
    castle = createObject("쿠파성.jpg", game, 270, 150, false);
    koopa = createObject("쿠파.png", game, 700, 400, false);
    pitch = createObject("피치.png", game, 1200, 350, false);
    mario_luigi = createObject("마리오루이지.png", game, 350, 390,false);
    memo = createObject("memo.png", game, 800, 400, false);
    write = createObject("입력.png", game, 800, 400, false);


    //15층
    dark_mario = createObject("납치마리오.png", floor_15, 750, 400, false);
    box = createObject("상자.png", floor_15, 750, 400, true);
    tape = createObject("테이프.png", floor_15, 600, 400, false);
    paper = createObject("쪽지.png", floor_15, 700, 400, false);

    scaleObject(dark_mario, 0.6f);
    scaleObject(box, 0.7f);
    scaleObject(paper, 0.7f);
    timer_15F = createTimer(3.0f);
    scaleObject(duck, 1.2f);
    scaleObject(Kinopico_chance, 0.4f);
    scaleObject(O, 0.8f);
    scaleObject(X, 0.5f);
    scaleObject(arrow_left, 0.7f);
    scaleObject(arrow_right, 0.7f);
    scaleObject(arrow_left2, 0.7f);
    scaleObject(arrow_right2, 0.7f);
    scaleObject(Q10, 0.7f);
    scaleObject(fourteen_box1, 0.3f);
    scaleObject(fourteen_box2, 0.3f);
    scaleObject(fourteen_box3, 0.3f);
    scaleObject(castle, 2.2f);
    scaleObject(mario_luigi, 0.7f);
    scaleObject(koopa,  0.5f);
    scaleObject(pitch, 0.3f);


    timer1=createTimer(10.0f);
    timer_X = createTimer(3.0f);
    timer_whitebox = createTimer(3.0f);
    sixfloor_timer = createTimer(10.0f);
    timer_orangebox = createTimer(1.0f);
    timer_turtle = createTimer(0.5f);
    timer_koopa = createTimer(3.0f);
    timer_koopa2 = createTimer(3.0f);

    make_scene();
    whitebox = createObject("whitebox.png", game, 300, 100, false);
    explain1 = createObject("1번답.png", game, 500, 250, false);
    explain2 = createObject("2번답.png", game, 500, 250, false);
    explain3 = createObject("3번답.png", game, 500, 250, false);
    explain4 = createObject("4번답.png", game, 500, 250, false);
    explain5 = createObject("5번답.png", game, 500, 250, false);
    explain6 = createObject("6번답.png", game, 500, 250, false);
    explain7 = createObject("7번답.png", game, 500, 250, false);
    explain8 = createObject("8번답.png", game, 500, 250, false);
    explain9 = createObject("9번답.png", game, 500, 250, false);
    explain10 = createObject("10번답.png", game, 500, 250, false);
    explain11 = createObject("11번답.png", game, 500, 250, false);
    explain12 = createObject("12번답.png", game, 500, 250, false);
    explain13 = createObject("13번답.png", game, 500, 250, false);
    explain18 = createObject("18번답.png", game, 500, 250, false);
    explain19 = createObject("19번답.png", game, 500, 250, false);
    close = createObject("close.png", game, 445, 630, false);
    next = createObject("next.png", game, 1350, 400, false);
    startGame(start);        
}