// Aritra Bandyopadhyay 2021CSB107
// Assignent_1 Recursive Functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct nodetype {
    int data;
    struct nodetype *next;
}
node;



int factorial(int n) {
	if (n == 1) return 1;
	else return n*factorial(n-1);
}

int sum(int *arr, int n) {
	if (n == 1) return arr[0];
	else return arr[0] + sum((arr+1), n-1);
}

int strcomp(char *s1, char *s2) {
	if (s1[0] == '\0' && s2[0] == '\0')
		return 0; // both strings are empty
	if (s1[0] == '\0')
		return -1;
	if (s2[0] == '\0')
		return 1;
	if (s1[0] < s2[0])
		return -1;
	if (s1[0] > s2[0])
		return 1;
	else return strcomp(s1 + 1, s2 + 1);
}

int largest(int *arr, int n) {
	if (n == 1) 
		return arr[0];
	int largest_remaining = largest(arr, n - 1);
	// returning larger of the last number and largest remaining number
	return (arr[n - 1] > largest_remaining ? arr[n - 1] : largest_remaining);
}	

int hcf(int n1, int n2) {
	if (n2 == 0)
		return n1;
	else return hcf(n2, n1 % n2);
}

bool search(int *arr, int n, int num) {
	if (n == 0) return false;
	if (arr[0] == num) return true;
	else return search((arr+1), n-1, num);
}

void listrev(int *arr, int n) {
	if (n == 0) return;

	printf("%d\n", arr[n-1]);
	listrev(arr, n - 1);
	
}

bool check_palindrome(char *s, int n) {
	if (n == 0 || n == 1) 
		return true;
	if (s[0] != s[n - 2])
		return false;
	return check_palindrome(s + 1, n - 2); // n - 2 because decrementing length by 2 as removing both first and last characters
	
}

void replace_char(char *s, char c1, char c2) {
	if (s[0] == '\0') 
		return;
	if (s[0] == c1)
		s[0] = c2;
	return replace_char(s + 1, c1, c2);
}

void sort_asc(int *arr, int n) {
	if (n == 1)
		return;
	int i_max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[i_max]) {
			i_max = i;
		}
	}
	int temp = arr[n - 1];
	arr[n - 1]  = arr[i_max];
	arr[i_max] = temp;
	sort_asc(arr, n - 1);
}

// allocate a new node
void new(node **f, int data) {
    *f = (node*)malloc(sizeof(node));
    (*f)->data = data;
    (*f)->next = NULL;
}

// insert a new node at head
void insert(node **start, int data) {

    // LL is empty
    if (*start == NULL ) {
        new(start, data);
    }
    // if LL isnt empty
    else {
        node *tempNode;
        new(&tempNode, data);
        tempNode->next = *start;
        (*start) = tempNode;
    }
}


void sortLL(node **start, int length) {
	if (length == 1 || length == 0) // base case
		return;

	// traverse the LL to find the minimum
	node *ptr = *start;
	node *min = *start;
	while(ptr->next != NULL) {
		if (ptr->next->data < min->data) {
			min = ptr->next;
		}
		ptr = ptr->next;
	}
	// now swap min and start nodes
	node *temp;
	new(&temp, (*start)->data);
	temp->next = (*start)->next;
	(*start)->data = min->data;
	min->data = temp->data;
	sortLL(&((*start)->next), length - 1);	
}


void printLL(node *start) {
    for (node *tmp = start; tmp != NULL; tmp = tmp->next) {
        printf("%d ", tmp->data);
    }
    printf("\n");
}

void printLargest_lvl(int tree[], int height, int size){
    if( height == 0 && size > 0){ 
        printf("%d ", tree[0]);
        printLargest_lvl(tree, height + 1, size);
        return;
    }

    if ((1 << height) - 1 < size) {
        int i = (1 << height) - 1;
        int max = 0;
        while (i < size && i <= 2*((1 << height) - 1)) {
            max = __max(max, tree[i]);
            i++;
        }

        printf("%d ", max);
        printLargest_lvl(tree, height + 1, size);
    }

}


int main(void) {
	int switcher;
	while (true) {
		printf("Press 0 to display all operations\n");
		printf("\nEnter an operation: ");
		scanf("%d", &switcher);
		switch(switcher)
		{
			case 0:
				printf("\nPress 1 to compute factorial of n\n");
				printf("Press 2 to compute sum of n integers\n");
				printf("Press 3 to compare two strings\n");
				printf("Press 4 to find the largest among n integer\n");
				printf("Press 5 to find the HCF of two integers\n");
				printf("Press 6 to search for a given integer in a given list of numbers");
				printf("Press 7 to print a given list of items in reverse order\n");
				printf("Press 8 to find whether string is palindrome or not\n");
				printf("Press 9 to replace all occurences of a certain character with other character\n");
				printf("Press 10 to sort an array of integers in ascending order\n");
				printf("Press 11 to sort singly Linked List\n");
				printf("Press 12 to find largest node from Tree given as array representation\n");
				break;
			case 1:
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				int fact_n = factorial(n);
				printf("Factorial of %d is %d\n", n, fact_n);
				break;
			case 2:
			{
				// braces added here to solve 'transfer of control bypasses initialization of VLA error'
				int len;
				printf("Enter length of array: ");
				scanf("%d", &len);
				int arr[len];
				for (int i = 0; i < len; i++) {
					printf("Enter a[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				int final_sum = sum(arr, len);
				printf("Sum is: %d\n", final_sum);
				break;
			}
			case 3:
			{
				char s1[100], s2[100];
				fflush(stdin);
				printf("Enter string1: ");
				fgets(s1, 100, stdin);
				fflush(stdin);
				printf("Enter string2: ");
				fgets(s2, 100, stdin);
				int result = strcomp(s1, s2);
				printf("Result: %d\n", result);
				break;
			}
			case 4:
			{
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				int arr[n];
				for (int i = 0; i < n; i++) {
					printf("Enter arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				int max = largest(arr, n);
				printf("Largest is: %d\n", max);
				break;
			}
			case 5:
				int a, b;
				printf("Enter a: ");
				scanf("%d", &a);
				printf("Enter b: ");
				scanf("%d", &b);
				int gcd = hcf(a, b);
				printf("HCF is: %d\n", gcd);
				break;
			case 6:
			{
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				int arr[n];
				for (int i = 0; i < n; i++) {
					printf("Enter arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				int key;
				printf("Enter number to be searched: ");
				scanf("%d", &key);
				if (search(arr, n, key)) printf("\nFound!\n");
				else printf("\nNot Found\n");
				break;
			}
			case 7:
			{
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				int arr[n];
				for (int i = 0; i < n; i++) {
					printf("Enter arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				listrev(arr, n);
				break;
			}
			case 8:
			{
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				char s[n+1];
				printf("Enter string: ");
				fflush(stdin);
				fgets(s, n+1, stdin);
				
				s[strcspn(s, "\n")] = 0;
				if(check_palindrome(s, n+1)) printf("\nPalindrome\n");
				else printf("\nNot Palindrome!\n");
				break;
			}
			case 9:
				char str[100];
				printf("Enter string: ");
				fflush(stdin);
				fgets(str, 100, stdin);
				char c1, c2;
				printf("Enter c1: ");
				
				scanf(" %c", &c1);
				printf("Enter c2: ");
				scanf(" %c", &c2);
				replace_char(str, c1, c2);
				printf("%s", str);
				break;
			case 10:
			{
				int n;
				printf("Enter n: ");
				scanf("%d", &n);
				int arr[n];
				for (int i = 0; i < n; i++) {
					printf("Enter arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				sort_asc(arr, n);
				for (int i = 0; i < n; i++) {
					printf("%d ", arr[i]);
				}
				break;
			}	
			case 11:
				node *start = NULL;
				int length;
				printf("Enter length: ");
				scanf("%d", &length);
				for (int i = 0; i < length; i++) {
					int new_key;
					scanf("%d", &new_key);
					insert(&start, new_key);
				}
				// printLL(start);
				sortLL(&start, length);
				printf("\nSorted Linked List is: \n");
				printLL(start);
				
				break;
			case 12:
			{
				int tree[100];
				printf("Enter array representation for tree. Enter 0 if node is empty and -1 to terminate\n");

				int i = 0;
				while (1) {
					int x;
					printf("Enter value: ");
					scanf("%d", &x);
					if(x == -1) break;
					else {
						tree[i] = x;
						i++;
					}
				}
				printLargest_lvl(tree, 0, i);
			}
		}
	}
}
