# include "iGraphics.h"
#include<math.h>
#include<windows.h>
#include<string.h>

//VALAR MORGHULIS || VALAR DOHAERIS

int x = 1200, y = 600,text=0,gravity_drop=0,c=1,mode=1;
int phase[5]= {0,0,100,0,0}, am[5]= {100,100,100,100,100};
int t=1,ti=25, g=255,green=20,red=20,phase2=50,turn_amp_up=1,turn_amp_down=1,blue=20,middle_line=300;
int ball_trace[6][2]= {0},curve_trace[6][2]= {0};
double i,m,a=100,z=.1,ball_speed=1,j=1,f=1,y_cor=0;
int index=0,ball_mode=0,ball_state=0,screen_mode=0,curve_mode=0,curve_state=0,screen_active=0;
char str1[100]="",str2[100]="",len,l,view[10]="";


void drawTextBox()
{
    iSetColor(47,79,79);
    iFilledRectangle(400, 450, 300, 30);
}

void Introduction()
{
    iSetColor(0,0,0);
    iFilledRectangle(400,0,400,310);
    iSetColor(255,255,255);
    iText(402,290,"Hello everyone. My name is Soumya Swagata Biswas.",GLUT_BITMAP_8_BY_13);
    iText(402,275,"This is my Waves assignment using igrapics.",GLUT_BITMAP_8_BY_13);
    iText(402,260,"I tried to keep the option of changing all the",GLUT_BITMAP_8_BY_13);
    iText(402,245,"curves at once as well as seperately.",GLUT_BITMAP_8_BY_13);
    iText(402,210,"There are also some interactions I hope you all",GLUT_BITMAP_8_BY_13);
    iText(402,195,"will find interesting :) ",GLUT_BITMAP_8_BY_13);
    //iText(1005,355,view,GLUT_BITMAP_8_BY_13);
    iText(402,150,"So without further delay,",GLUT_BITMAP_8_BY_13);
    iText(402,135,"Let's begin our journey to the Black hole Waves!!",GLUT_BITMAP_8_BY_13);
}

void sin_curve1()
{
    green=rand()%255;
    red=rand()%255;
    blue=rand()%255;
    for(i=0; i<1000; i+=.5)
    {

        if(curve_state==0 && curve_mode==1)
            iSetColor(255,139,255);
        if(curve_state==1 && curve_mode==1)
            iSetColor(red,green,blue);
        if(curve_state==2 && curve_mode==1)
            iSetColor(0,0,0);
        if(curve_mode==5)
            iSetColor(0,0,0);



        y_cor=(am[1]*sin(((i*f*3.1416)+phase[1])/180));
        if(y_cor>=200)
            turn_amp_up=0;



        iPoint(i,y_cor+middle_line,.5);
        red=(red+1)%255;
        green=(green+1)%255;
        blue=(blue+1)%255;
    }

}


void sin_curve2()
{
    green=rand()%255;
    red=rand()%255;
    blue=rand()%255;
    for(i=0; i<1000; i+=.5)
    {

        if(curve_state==0 && curve_mode==2)
            iSetColor(0,0,128);
        if(curve_state==1 && curve_mode==2)
            iSetColor(red,green,blue);
        if(curve_state==2 && curve_mode==2)
            iSetColor(0,0,0);
        if(curve_mode==5)
            iSetColor(0,0,0);

        y_cor=(am[2]*sin(((i*f*3.1416)+phase[2])/180));

        if(y_cor>=200)
            turn_amp_up=0;

        iPoint(i,y_cor+middle_line,.5);
        red=(red+1)%255;
        green=(green+1)%255;
        blue=(blue+1)%255;
    }
}

void cos_curve()
{
    green=rand()%255;
    red=rand()%255;
    blue=rand()%255;
    for(i=0; i<1000; i+=.5)
    {


        if(curve_state==0 && curve_mode==3)
            iSetColor(101,255,244);
        if(curve_state==1 && curve_mode==3)
            iSetColor(red,green,blue);
        if(curve_state==2 && curve_mode==3)
            iSetColor(0,0,0);
        if(curve_mode==5)
            iSetColor(0,0,0);

        y_cor=(am[3]*cos(((i*f*3.1416)+phase[3])/180));

        if(y_cor>=200)
            turn_amp_up=0;

        iPoint(i,y_cor+middle_line,.5);
        red=(red+1)%255;
        green=(green+1)%255;
        blue=(blue+1)%255;
    }
}

void tan_curve()
{
    for(i=0; i<1000; i+=.5)
    {

        if(curve_state==1 && curve_mode==4)
        {
            int green4=rand()%255;
            int red4=rand()%255;
            int blue4=rand()%255;
            iSetColor(red4,green4,blue4);

        }
        if(curve_state==0 && curve_mode==4)
            iSetColor(255,20,147);
        if(curve_state==2 && curve_mode==4)
            iSetColor(0,0,0);
        if(curve_mode==5)
            iSetColor(0,0,0);

        y_cor=am[4]*tan(((i*f*3.1416)+phase[4])/180);
        iPoint(i,y_cor+middle_line,.5);
    }

}

void sum_curve()
{
    for(i=0; i<1000; i++)
    {
        curve_trace[0][1]= am[1]*sin(((i*f*3.1416)+phase[1])/180);
        curve_trace[1][1]= am[2]*sin(((i*f*3.1416)+phase[2])/180);
        curve_trace[2][1]= am[3]*cos(((i*f*3.1416)+phase[3])/180);
        curve_trace[3][1]=am[4]*tan(((i*f*3.1416)+phase[4])/180);

        iSetColor(255,255,255);
        curve_trace[2][1]=curve_trace[0][1]+curve_trace[1][1]+curve_trace[2][1]+middle_line;
        iPoint(i,curve_trace[2][1],1);

    }
}

void instruction_box()
{
    iSetColor(2,2,5);
    iFilledRectangle(1000,0,200,600);
    iSetColor(21,21,25);

    iFilledRectangle(1000,570,200,30);

    iSetColor(255,255,255);
    iLine(1000,570,1200,570);

    iText(1000,580,"Welcome ",GLUT_BITMAP_8_BY_13);
    iText(1065,580,str2,GLUT_BITMAP_8_BY_13);
}


void instructions()
{
    iSetColor(20,0,10);
    iFilledRectangle(1000,330,200,240);

    iSetColor(255,255,255);

    iText(1005,550, "BASIC COMMANDS:",GLUT_BITMAP_8_BY_13);
    iText(1005,535, "Increase Amplitude: UP",GLUT_BITMAP_8_BY_13);
    iText(1005,520, "Increase Amplitude: Down",GLUT_BITMAP_8_BY_13);
    iText(1005,505, "Increase Frequency: RIGHT",GLUT_BITMAP_8_BY_13);
    iText(1005,490, "Decrease Frequency: LEFT",GLUT_BITMAP_8_BY_13);
    iText(1005,475, "Increase tracer speed: a",GLUT_BITMAP_8_BY_13);
    iText(1005,460, "Decrease tracer speed: A",GLUT_BITMAP_8_BY_13);
    iText(1005,445, "Elevate middle line: m",GLUT_BITMAP_8_BY_13);
    iText(1005,430, "Lower middle line: M",GLUT_BITMAP_8_BY_13);
    iText(1005,415, "Zoom in: Page Down",GLUT_BITMAP_8_BY_13);
    iText(1005,400, "Zoom out: Page Up",GLUT_BITMAP_8_BY_13);
    iText(1005,385, "Phase shift to left: P",GLUT_BITMAP_8_BY_13);
    iText(1005,370,"Phase shift to right: p",GLUT_BITMAP_8_BY_13);
    iText(1005,355,"Increase Tracer speed: a",GLUT_BITMAP_8_BY_13);
    iText(1005,340,"Decrease Tracer speed: A",GLUT_BITMAP_8_BY_13);

    iSetColor(20,30,10);
    iFilledRectangle(1000,115,200,220);
    iSetColor(255,255,255);
    iLine(1000,335,1200,335);


    iText(1005,315,"Special Interactions:",GLUT_BITMAP_8_BY_13);
    iText(1005,300,"Depending on the current ",GLUT_BITMAP_8_BY_13);
    iText(1005,285,"state(shown at bottom)",GLUT_BITMAP_8_BY_13);
    iText(1005,270,"You can manipulate that",GLUT_BITMAP_8_BY_13);
    iText(1005,255,"curve in different ways",GLUT_BITMAP_8_BY_13);
    iText(1005,230,"Change state: w",GLUT_BITMAP_8_BY_13);
    iText(1005,215,"Change curve color: q",GLUT_BITMAP_8_BY_13);
    iText(1005,200,"Mouse Left drag change amp.",GLUT_BITMAP_8_BY_13);
    iText(1005,185,"Stop tracer: g",GLUT_BITMAP_8_BY_13);
    iText(1005,170,"Hide/show tracer: r",GLUT_BITMAP_8_BY_13);
    iText(1005,155,"GRAVTTY DROP: G",GLUT_BITMAP_8_BY_13);
    iText(1005,140,"SUPERNOVA:Right mouse click",GLUT_BITMAP_8_BY_13);
    iText(1005,125,"Exit: x",GLUT_BITMAP_8_BY_13);

    iSetColor(10,20,30);
    iFilledRectangle(1000,70,200,50);

    iSetColor(255,255,255);
    iLine(1000,120,1200,120);

    if(curve_mode==0)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Controlling all curves",GLUT_BITMAP_8_BY_13);
    }

    if(curve_mode==2)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Controlling sine2 curve",GLUT_BITMAP_8_BY_13);

    }

    if(curve_mode==1)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Controlling sine1 curve",GLUT_BITMAP_8_BY_13);

    }

    if(curve_mode==3)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Controlling cos curve",GLUT_BITMAP_8_BY_13);

    }

    if(curve_mode==4)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Controlling tan curve",GLUT_BITMAP_8_BY_13);

    }

    if(curve_mode==5)
    {
        iSetColor(255,255,255);
        iText(1005,100,"Vanishing mode!!",GLUT_BITMAP_8_BY_13);
    }

    if(ball_state==1)
    {
        iText(1005,85,"Tracer off",GLUT_BITMAP_8_BY_13);
    }

    if(ball_state==0)
    {
        iText(1005,85,"Tracer on",GLUT_BITMAP_8_BY_13);
    }

    iText(1005,40,"Thank you all.",GLUT_BITMAP_HELVETICA_18);
    iLine(1000,0,1000,600);

}

void balls()
{
    //FOR SIN CURVE 1
    if(ball_mode==1 && ball_state==1)
    {

    }

    else if(ball_mode==5 && ball_state==1)
    {

    }

    else
    {
        iSetColor(255,0,0);
        iFilledCircle(ball_trace[0][0],ball_trace[0][1],6);
    }


//FOR SINE CURVE 2
    if(ball_mode==2 && ball_state==1)
    {


    }

    else if(ball_mode==5 && ball_state==1)
    {

    }
    else
    {
        iSetColor(0,255,0);
        iFilledCircle(ball_trace[1][0],ball_trace[1][1],6);
    }


//FOR COSINE CURVE
    if(ball_mode==3 && ball_state==1)
    {

    }

    else if(ball_mode==5 && ball_state==1)
    {

    }

    else
    {
        iSetColor(255,255,0);
        iFilledCircle(ball_trace[2][0],ball_trace[2][1],6);


    }

//TAN CURVE
    if(ball_mode==4 && ball_state==1)
    {

    }

    else if(ball_mode==5 && ball_state==1)
    {

    }
    else
    {
        iSetColor(210,105,30);
        iFilledCircle(ball_trace[3][0],ball_trace[3][1],6);

    }


//FOR SUM CURVE
    iSetColor(88,255,144);
    iFilledCircle(ball_trace[6][0],ball_trace[6][1],6);

    iSetColor(0,144,55);
    iLine(-200,middle_line,1000,middle_line);
}

void iDraw()
{
    //place your drawing codes here
    iClear();

    if(screen_mode == 0 || screen_mode==1)
    {
        iShowBMP(0,0,"rsz_lightning.bmp");
        iSetColor(23,34,85);
        if(screen_mode==0)
            iText(410, 435, "Kindly click on the box above",GLUT_BITMAP_HELVETICA_18);

        drawTextBox();
        Introduction();
    }

    if(screen_mode==1)
    {
        iSetColor(255,255,255);
        iText(402,458,str1,GLUT_BITMAP_8_BY_13);
        iShowBMP2(400,480,"waves.bmp",0);
        iSetColor(0,255,255);
        iText(410, 435, "NOW PLEASE ENTER YOUR NAME",GLUT_BITMAP_HELVETICA_18);

    }


    if(screen_mode==2)
    {
        iShowBMP(0, 0, "rsz_11black_hole.bmp");

        iSetColor(65,104,255);
        sin_curve1();

        iSetColor(255,255,0);
        sin_curve2();

        iSetColor(87,255,104);
        tan_curve();

        iSetColor(255,69,0);
        cos_curve();

        sum_curve();

        balls();

        instruction_box();
        instructions();
    }

}


void change_sin1()
{

    if(gravity_drop==0)
    {
        ball_trace[0][0]=j;
        ball_trace[0][1] =(am[1]*sin(((j*f*3.1416)+phase[1])/180))+middle_line;
        if(ball_trace[0][0]>1000)
        {
            j=0;
        }

        j=j+ball_speed;

    }

    if(gravity_drop==1)
    {
        ball_trace[0][1]--;
    }

}

void change_sin2()
{
    if(gravity_drop==0)
    {
        ball_trace[1][0]=j;
        ball_trace[1][1] = (am[2]*sin(((j*f*3.1416)+phase[2])/180))+middle_line;
        if(ball_trace[1][0]>1000)
        {
            j=0;
        }

        j=j+ball_speed;
    }

    if(gravity_drop==1)
    {
        ball_trace[1][1]--;
    }
}

void change_cos()
{

    if(gravity_drop==0)
    {
        ball_trace[2][0]=j;
        ball_trace[2][1] =(am[3]*cos(((j*f*3.1416)+phase[3])/180))+middle_line;
        if(ball_trace[2][0]>1000)
        {
            j=0;
        }

        j=j+ball_speed;

    }

    if(gravity_drop==1)
    {
        ball_trace[2][1]--;
    }

}

void change_tan()
{
    if(gravity_drop==0)
    {
        ball_trace[3][0]=j;
        ball_trace[3][1] =(am[4]*tan(((j*f*3.1416)+phase[4])/180))+middle_line;
        if(ball_trace[3][0]>1000)
        {
            j=0;
        }

        j=j+ball_speed;

    }

    if(gravity_drop==1)
    {
        ball_trace[3][1]--;
    }
}

void change_sum()
{
    ball_trace[6][0]=j;
    ball_trace[6][1]=ball_trace[0][1]+ball_trace[1][1]+ball_trace[2][1]-middle_line-middle_line;

    if(ball_trace[6][0]>1000)
    {
        j=0;
    }
    if(ball_trace[6][0]<0)
    {
        j=1000;
    }

    j=j+ball_speed;

    if(gravity_drop==1)
    {
        ball_trace[6][1]--;
    }
}

void iMouseMove(int mx, int my)
{

    if(curve_mode==0)
    {
        am[1]=my;
        am[2]=my;
        am[3]=my;
        am[4]=my;

    }

    if(curve_mode==1)
    {
        am[1]=my;
    }

    if(curve_mode==2)
    {
        am[2]=my;
    }

    if(curve_mode==3)
    {
        am[3]=my;
    }

    if(curve_mode==4)
    {
        am[4]=my;
    }

}

void iMouse(int button, int curve_state, int mx, int my)
{
    if(button == GLUT_RIGHT_BUTTON && curve_state == GLUT_DOWN)
    {
        f=mx;
        a=my;

    }
    if(button == GLUT_LEFT_BUTTON && curve_state == GLUT_DOWN)
    {
        //place your codes here
        if(mx >= 400 && mx <= 700 && my >= 450 && my <= 480 && screen_mode == 0)
        {
            screen_mode=1;
            printf("%d",screen_active);
        }
    }
}

void iKeyboard(unsigned char key)
{

//Input from screen
    if(screen_mode==1)
    {
        if(key == '\r')
        {
            screen_mode = 2;
            strcpy(str2, str1);
            for(l = 0; l < len; l++)
                str1[l] = 0;
            len = 0;

            iSetColor(34,42,134);
        }


        if(key=='\b')
        {
            len--;
            str1[len]='\0';
            if(len<=0)
                len=0;
        }

        else
        {
            str1[len] = key;
            len++;
        }
    }


    if(screen_mode==2)
    {


        if(curve_state==0 && key == 'q')
        {
            curve_state=1;
        }

        else if(curve_state==1 && key == 'q')
        {
            curve_state=2;
        }

        else if(curve_state==2 && key == 'q')
        {
            curve_state=0;
        }


//Ball speed
        if(key == 'g')
        {
            ball_speed=0;
        }

        if(key == 'a')
        {
            ball_speed+=1;
        }

        if(key == 'A')
        {
            ball_speed-=1;
        }


//Shifting middle axis
        if(key == 'm')
        {

            middle_line+=5;
        }

        if(key == 'M')
        {

            middle_line-=5;
        }

//GRAVITY DROP
        if(key == 'G')
        {
            gravity_drop=1;
            ball_speed=0;
        }


//Curve state change
        if(key == 'w')
        {
            curve_mode+=1;
            ball_mode+=1;
            curve_state=0;

            if(curve_mode>5)
            {
                curve_mode=0;
                ball_mode=0;
            }

            printf("%d",curve_mode);


        }

        if(key=='r')
        {
            ball_state+=1;
            if(ball_state>1)
                ball_state=0;
        }


//PHASE SHIFTING
        if(curve_mode==0 && key=='p')
        {
            int p1;
            for(p1=1; p1<=4; p1++)
                phase[p1]-=5;
        }
        if(curve_mode==1 && key=='p')
        {
            phase[1]-=5;
        }

        if(curve_mode==2 && key=='p')
        {
            phase[2]-=5;
        }

        if(curve_mode==3 && key=='p')
        {
            phase[3]-=5;
        }

        if(curve_mode==4 && key=='p')
        {
            phase[4]-=5;
        }


        if(curve_mode==0 && key=='P')
        {
            int p1;
            for(p1=1; p1<=4; p1++)
                phase[p1]+=5;
        }
        if(curve_mode==1 && key=='P')
        {
            phase[1]+=5;
        }

        if(curve_mode==2 && key=='P')
        {
            phase[2]+=5;
        }

        if(curve_mode==3 && key=='P')
        {
            phase[3]+=5;
        }

        if(curve_mode==4 && key=='P')
        {
            phase[4]+=5;
        }
    }

    if(key=='\r')
    {
        screen_mode=2;
    }

//Exit
    if(key=='x')
    {
        exit(0);
    }
}


void iSpecialKeyboard(unsigned char key)
{

//AMPLITUDE AND FREQUENCY CHANGE
    if(turn_amp_up==1 && key == GLUT_KEY_UP)
    {
        am[1] +=3;
        am[2] +=3;
        am[3] +=3;
        am[4] +=3;
        turn_amp_down==1;
    }

    if(turn_amp_down==1 && key == GLUT_KEY_DOWN)
    {
        am[1] -=3;
        am[2] -=3;
        am[3] -=3;
        am[4] -=3;
        turn_amp_up=1;
    }

    if(key == GLUT_KEY_RIGHT)
    {
        f+=.05;

    }

    if(key == GLUT_KEY_LEFT)
    {
        f-=.05;
    }

    //Zoom in
    if(key == GLUT_KEY_PAGE_UP)
    {
        f+=.1;
        am[1] -=3;
        am[2] -=3;
        am[3] -=3;
        am[4] -=3;
    }

    //Zoom out
    if(key == GLUT_KEY_PAGE_DOWN)
    {
        f-=.1;
        am[1] +=3;
        am[2] +=3;
        am[3] +=3;
        am[4] +=3;
    }

}


int main()
{

    iSetTimer(25,change_sin1);
    iSetTimer(25,change_sin2);
    iSetTimer(25,change_cos);
    iSetTimer(25,change_sum);
    iSetTimer(25,change_tan);

    iInitialize(x, y, "Demo!");
    return 0;
}
