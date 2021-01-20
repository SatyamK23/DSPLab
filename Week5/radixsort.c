#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define r 10

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}DLL;

typedef struct deque
{
    int cnt;
    DLL *head;
}Deque;

Deque *createDeque(void)
{
    DLL *np;
    Deque *bins;
    bins = malloc (sizeof (Deque));
	np = malloc (sizeof (DLL));
	bins -> head = np;
	np -> next = np;
	np -> prev = np;
	bins -> cnt = 0;
	return (bins);
}

void destroyDeque (Deque *bins) {
	DLL *np;
	np = bins -> head -> next -> next;
	while (np != bins -> head) {
		free (np -> prev);
		np = np -> next;
	}
	if (np -> prev != np) {
		free (np -> prev);
    }
	free (np);
	return;
}

// Returns the number of items in the deque
int numItems (Deque *bins) {
	return (bins -> cnt);
}

// Adds an integer to the front of the deque
void addFirst (Deque *bins, int x) {
	DLL *np;
	np = malloc (sizeof (DLL));
	np -> data = x;
	np -> next = bins -> head -> next;
	np -> prev = np -> next -> prev;
	np -> next -> prev = np;
	bins -> head -> next = np;
	bins -> cnt++;
}

// Adds an integer to the end of the deque
void addLast (Deque *bins, int x) {
	DLL *np;
	np = malloc (sizeof (DLL));
	np -> data = x;
	np -> next = bins -> head;
	np -> prev = bins -> head -> prev;
	np -> prev -> next = np;
	bins -> head -> prev = np;
	bins -> cnt++;
}

// Removes & frees an integer from the front of the deque
int removeFirst (Deque *bins) {
	int x;
	bins -> head -> next = bins -> head -> next -> next;
	x = bins -> head -> next -> prev -> data;
	free (bins -> head -> next -> prev);
	bins -> head -> next -> prev = bins -> head;
	bins -> cnt--;
	return (x);
}

// Removes & frees an integer from the end of the deque
int removeLast (Deque *bins) {
	int x;
	bins -> head -> prev = bins -> head -> prev -> prev;
	x = bins -> head -> prev -> next -> data;
	free (bins -> head -> prev -> next);
	bins -> head -> prev -> next = bins -> head;
	bins -> cnt--;
	return (x);
}

// Returns integer of the first item in the deque
int getFirst (Deque *bins) {
	return (bins -> head -> next -> data);
}

// Returns integer of the last item in the deque
int getLast (Deque *bins) {
	return (bins -> head -> prev -> data);
}


int main()
{
    int k,x,y,z,j;
    int n;
    scanf("%d",&n);
    int A[n];
    int max=0;
    Deque *toBeSorted;
	toBeSorted = createDeque();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<0)
        {
            printf("INVALID INPUT\n");
            return 0;
        }
        addLast(toBeSorted,A[i]);
    }
    if(n<=0)
    {
        printf("INVALID INPUT\n");
        return 0;
    }


    	// Create 'r' amount of bins. 'r' represents the base of the numbers
	Deque *bins[10];
	for (int i = 0; i < r; i++) {
		bins[i] = createDeque();
	}

	// Loop through all significant digits until finished
	int atTheEnd = 0;
	int i = 0;


	// Continue looping for all significant digits
	while (!atTheEnd) {
		atTheEnd = 1; // Only remains true if we are calculating for the highest significant digit.

        	// Remove from main deque and place into respective bins
		while(numItems(toBeSorted) != 0) {
			z = removeFirst(toBeSorted);
			y = (z / ((int)pow(10,i))) % 10;
			addLast(bins[y], z);

			if ((z / ((int)pow(10,i))) > 0) {
				atTheEnd = 0;
			}
		}

        	// Removes from bins in order then places back into main deque
		for (j = 0; j < r; j++) {
			while (numItems(bins[j]) != 0) {
				z = removeFirst(bins[j]);
				addLast(toBeSorted,z);
			}
		}

		i++;
	}

    	// Print sorted numbers
	for (i = 0; i < numItems(toBeSorted); i++) {
		k = removeFirst(toBeSorted);
		printf ("%d ", k);
		addLast(toBeSorted,k);
	}
    

    	// Free all memory used
	for (i = 0; i < r; i++) {
		destroyDeque(bins[i]);
	}
	destroyDeque(toBeSorted);
    return 0;
}

