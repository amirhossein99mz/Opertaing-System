init(s1,1);
init(s2,0);
init(s3,0);
init(s4,0);
init(s5,0);
init(s6,0);
init(s7,0);

void P1(){

    while(1){

        wait(s1);
        printf("S1\n");
        signal(s2);
        signal(s3);
    }



}

void P2(){

    while(1){

        wait(s2);
        printf("S2\n");
        signal(s4);
        signal(s5);
    }



}



void P3(){

    while(1){

        wait(s3);
        printf("S3\n");
        signal(s5);
        signal(s6);
    }



}



void P4(){

    while(1){

        wait(s4);
        printf("S4\n");
        signal(s7);

    }



}



void P5(){

    while(1){

        wait(s5);
        wait(s5);
        printf("S5\n");
        signal(s7);
    }



}



void P6(){

    while(1){

        wait(s6);
        printf("S6\n");
        signal(s7);
    }



}


void P7(){

    while(1){

        wait(s7);
        wait(s7);
        wait(s7);
        printf("S7\n");
        signal(s1);
    }



}




destroy(s1);
destroy(s2);
destroy(s3);
destroy(s4);
destroy(s5);
destroy(s6);
destroy(s7);
