//C-prorgam to find the range of index of searched element
#include<stdio.h>
#include<stdlib.h>

//Compare the element and swap them
int cmp(const void *a, const void *b) 
{
   return ( *(int*)a - *(int*)b );
}

//Find the first and last occurence of element
int occ(int A[],int x,int n, int flag)
{
	//To know if element is present in list or not
    int res=-1;
    //Setting the index of low and high 
    int low=0,high=n-1;
    
    //Continue finding the element till the entire array element is marked
    while(low<=high)
    {
        int mid = (low+high)>>1;

       //Check if search element is present and 1st occ is found in mid
       //Res is updated to mid
       //If not found in mid,look for flag value
       //Flag is 1, look in the lower half else look in the right half for last occurence
       if(A[mid]==x)
       {
           res = mid;
           if(flag==1)
               high = mid-1;
           else
               low = mid + 1;
       }

       //If the search element is less than mid look into left half for 1st occurence
       
       else if(A[mid]<x)
           low = mid +1;
       else
           high = mid -1;
    }
//Return the function value as index of the search element
return res;
}


int main()
{
    printf("Enter the size of array");
    int n;
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

	//Inbuilt library for quicksort
	qsort(A,n,sizeof(int),cmp);
	
    int x,flag;
    //Finding occurence of sorted array
    printf("Enter the element to find the occ of elem");
    scanf("%d",&x); 
    int first = occ(A,x,n,1);
    int  last = occ(A,x,n,0);

    if(first==-1 && last==-1)
        printf("Element not present in array");
    else
    {
        printf("Starting Occurence: [%d\n", first);
        printf("Ending Occurence: %d]\n",last);
    }
    return 0;
}
