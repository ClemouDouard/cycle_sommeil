#include <stdio.h>
#include <stdlib.h>

struct time {
    int h;
    int min;
};
typedef struct time time;

double time_to_double(time t){
    return t.h + (double)t.min/60;
}

time double_to_time(double t){
    int ent = (int) t;
    double dec = (t - ent);

    time heure;
    heure.h = ent; heure.min = 60*dec;
    return heure;
}

time end_hour(time start, time last) {
    double s = time_to_double(start); double l = time_to_double(last);
    s+=0.25;

    double temps = 0;
    if (s<l) {
        temps = s;
        while (temps <= l) {
            temps += 1.5;
        }
        temps -= 1.5;

        return double_to_time(temps);
    }
    else {
        temps = s - 24;
        while (temps <= l) {
            temps += 1.5;
        }
        temps -= 1.5;

        return double_to_time(temps);
    }
}

time sleep_later(time start, time last, time end) {
    double s = time_to_double(start); double l = time_to_double(last); double e = time_to_double(end);
    double diff = l - e;
    double coucher = (s + diff);
    if (coucher >= 24) coucher -=24;

    time c = double_to_time(coucher);
    return c;
}


int main() {

    time s;
    printf("Donnez l'heure à laquelle vous voulez vous coucher (juste l'heure !) : "); scanf("%d", &s.h);
    printf("%d h combien de minutes ?",s.h); scanf("%d", &s.min);

    time l;
    printf("Donnez la dernière heure à laquelle vous pouvez vous lever demain (juste l'heure !) : "); scanf("%d", &l.h);
    printf("%d h combien de minutes ?", l.h); scanf("%d", &l.min);

    time he = end_hour(s, l);
    printf("Mettez un réveil pour demain à : %dh%d\n", he.h, he.min);

    time c = sleep_later(s, l, he);
    printf("Ou alors couchez vous à : %dh%d pour vous réveiller à : %dh%d\n", c.h, c.min, l.h, l.min);

    return 0;
}