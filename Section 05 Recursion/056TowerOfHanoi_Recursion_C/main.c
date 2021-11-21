#include <stdio.h>

// transfer disks from sourcePole to destPole using auxiliaryPole.
//numberOfDisks gives the number of disks to be transferred "at a time"... but in real, they are transfered one by one.
void TowerofHanoi(int numberOfDisks,char sourcePole, char auxiliaryPole, char destPole)
{
    if(numberOfDisks>0)
    {
//        We first transfer the top disks to the aux pole, and then transfer the bottom most to
//        destination pole.
//        TowerofHanoi(n-1,A,C,B)
        TowerofHanoi(numberOfDisks-1,sourcePole,destPole,auxiliaryPole);
        printf("\n->%c to %c",sourcePole,destPole);
//        Finally, transfer all the disks kept temporarily at aux pole to
//        TowerofHanoi(n-1,B,A,C)
        TowerofHanoi(numberOfDisks-1,auxiliaryPole,sourcePole,destPole);
    }
}


int main()
{
    printf("Transfer %d disks as: \n",3);
    TowerofHanoi(3,'A','B','C');
    printf("\n");
    return 0;
}
