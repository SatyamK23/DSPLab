//C-Program for Tower of Hanoi (iterative)

//Preprocess directive standards for taking input/output
#include <stdio.h>

//Assume 1-based array indexing
//Odd no of movements of disks, we pick the disk with smallest number
//Movement of disk takes place between rod1 and rod3
int moveSmallestDisk (int rod[], int flag, int *src, int *dest)
{
    *src = rod[1];  //1st rod is considered as src
    //Adding diskno to src will give the destno
    *dest = *src + flag; //Last rod is considered as dest
    
    //Since there are only 3 rods,if dest >3,we assume 1st rod as the dest 
    //If dest is less than 1, then the last rod is selected as the destination
    if ( *dest > 3 )
        *dest = 1;
    if ( *dest < 1 )
        *dest = 3;
        
    //
    return 1;
}

//For even no of disk, use this function
//
int moveAlternateDisk (int rod[], int numberOfDisks, int *src, int *dest)
{
    // determine which disk is at the top of each rod
    int topDisk[10];
    //
    for ( int i = 1; i <= 3; ++i )
        topDisk[i] = numberOfDisks + 1;
        
    //Move the top disk to the index of rod
    for ( int i = numberOfDisks; i >= 1; --i )
        topDisk[rod[i]] = i;
        
   //Select the 1st rod
    switch (rod[1])
    {
    //If the source rod is 2, dest rod =3
    //Rod 1 is not empty
    //Move the smaller disk to rod 3 in 1st gp
        case 1:
            *src = 2;
            *dest = 3;
            break;
            
     //If the source rod is 1, dest rod =3
    //Rod 2 is not empty
    //Move the smaller disk to rod 3
        case 2:
            *src = 1;
            *dest = 3;
            break;
            
     //If the source rod is 1, dest rod =2
    //Rod 3 is not empty
    //Move the smaller disk to rod 2
        case 3:
            *src = 1;
            *dest = 2;
            break;
            
        default:
            printf ("error");
            break;
    }
    
    //If the topdisk of src has higher value than dest,swap these position
    if ( topDisk[*src] > topDisk[*dest] ) {
        int temp;
        //Swap src and dest
        temp = *src;
        *src = *dest;
        *dest = temp;
    }

//Value of function of Topdisk present in the source rod
    return topDisk[*src];
}


//Whenever the disk moves to destination rod 3,increment the count 
int destinationCount (int rod[], int numberOfDisks)
{
    int count = 0;

    for ( int i = 1; i <= numberOfDisks; ++i ) {
        if ( rod[i] == 3 )
            ++count;
    }

    return count;
}

int main ()
{
	//Ask the user to enter no of disk
    printf ("Enter the number of disks present in a rod ");
    int Disks;
    //Store value entered by disk in a variable disks
    scanf ("%d", &Disks);
    
  
    int flag;
    //If the no of disk is even, smaller disk is transferred to next rod wrt sourc
    //If the no of disk is odd, smaller disk is transferred to prev rod wrt source
    if ( (Disks % 2) == 0 )
        flag = 1;
    else
        flag = -1;
        
        
    int rod[Disks + 1];
    //before the 1st iteration starts. all disks start on the first rod
    for ( int i = 1; i <= Disks; ++i )
        rod[i] = 1;

    int moveCount = 0, disk, rodFrom, rodTo;

//Continue until all the disk is moved from rod1 to rod3
   while ( destinationCount (rod, Disks) != Disks ) 
   {
   		 //Increment by 1 whenever a disk is moved from source to destination
        ++moveCount; 
		//If the noofmovement of disk is odd, use smallestdisk function
        if ( (moveCount % 2) == 1 )
            disk = moveSmallestDisk (rod, flag, &rodFrom, &rodTo);
        else
            disk = moveAlternateDisk (rod, Disks, &rodFrom, &rodTo);
		//Print the movement of disk from source and rod
		//To convert int into char,we add 64.since ASCII values of 'A' is 65
        printf ("%i: disk %i rod %c to rod %c\n", moveCount, disk,
               rodFrom + 64, rodTo + 64); 

        rod[disk] = rodTo;
    }
    return 0;
}
